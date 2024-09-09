/*
 * Copyright (c) 2024 NetLOX Inc
 *
 * SPDX short identifier: BSD-3-Clause
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <fcntl.h>

#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <pthread.h>
#include <netdb.h>
#include <poll.h>
#include <ifaddrs.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/types.h>
#include <linux/tls.h>
#include <linux/tcp.h>
#include "log.h"
#include "notify.h"

#define MAX_NOTIFY_FDS 65535
#define MAX_NOTIFY_POLL_FDS 8192
#define MAX_NOTIFY_THREADS (8)
#define MAX_NOTIFY_POLL_TIMEO (10)

typedef struct notify_ent {
  int fd;
  notify_type_t type;
  int poll_slot;
  int thr_id;
  void *priv;
} notify_ent_t; 

#define NOTI_LOCK(C) pthread_rwlock_wrlock(&(C)->lock)
#define NOTI_UNLOCK(C) pthread_rwlock_unlock(&(C)->lock)

typedef struct notify_thr {
  void *ctx;
  int thrid;
} notify_thr_t;

typedef struct notify_poll_ctx {
  int n_pfds;
  struct pollfd pfds[MAX_NOTIFY_POLL_FDS];
} notify_poll_ctx_t;

typedef struct notify_ctx {
  pthread_rwlock_t lock;
  notify_ent_t earr[MAX_NOTIFY_FDS];
  int n_fds;
  int thr_sel;
  int n_thrs;
  notify_cbs_t cbs;
  notify_poll_ctx_t poll_ctx[MAX_NOTIFY_THREADS];
} notify_ctx_t ;

static short
notify_conv2poll_events(notify_type_t type)
{
  short events = 0;
  if (type & NOTI_TYPE_IN) {
    events |= POLLIN;
  }
  if (type & NOTI_TYPE_OUT) {
    events |= POLLOUT;
  }
  if (type & NOTI_TYPE_HUP) {
    events |= (POLLRDHUP|POLLHUP);
  }
  if (type & NOTI_TYPE_ERROR) {
    events |= POLLERR;
  }
  return events;
}

static notify_type_t
notify_conv4mpoll_events(short events)
{
  notify_type_t type = 0;

  if (events & POLLIN) {
    type |= NOTI_TYPE_IN;
  }
  if (events & POLLOUT) {
    type |= NOTI_TYPE_OUT;
  }
  if (events & (POLLRDHUP|POLLHUP)) {
    type |= NOTI_TYPE_HUP;
  }
  if (events & (POLLERR|POLLNVAL)) {
    type |=  NOTI_TYPE_ERROR;
  }
  return type;
}

void *
notify_ctx_new(notify_cbs_t *cbs, int n_thrs)
{
  notify_ctx_t *nc = calloc(1, sizeof(notify_ctx_t));
  assert(nc);

  if (cbs) {
    nc->cbs.notify = cbs->notify;
    nc->cbs.pdestroy = cbs->pdestroy;
  }

  if (n_thrs > MAX_NOTIFY_THREADS) {
    free(nc);
    return NULL;
  }

  nc->n_thrs = n_thrs;

  return nc;
}

int
notify_check_slot(void *ctx, int fd)
{
  notify_ctx_t *nctx = ctx;
  notify_ent_t *ent;

  assert(ctx);

  if (fd <= 0 || fd >= MAX_NOTIFY_FDS) {
    return 0;
  }

  NOTI_LOCK(nctx);
  ent = &nctx->earr[fd];
  if (ent->fd > 0) {
    NOTI_UNLOCK(nctx);
    return 0;
  }

  NOTI_UNLOCK(nctx);
  return 1;
}

int
notify_add_ent(void *ctx, int fd, notify_type_t type, void *priv)
{
  notify_ctx_t *nctx = ctx;
  notify_ent_t *ent;
  notify_poll_ctx_t *pctx;
  short events;
  int tslot = 0;

  assert(ctx); 

  if (fd <= 0 || fd > MAX_NOTIFY_FDS) {
    return -EINVAL;
  }

  events = notify_conv2poll_events(type);
  if (!events) {
    return -EINVAL;
  }

  NOTI_LOCK(nctx); 
  ent = &nctx->earr[fd];
  if (ent->fd > 0) {
    pctx = &nctx->poll_ctx[ent->thr_id];
    assert(pctx);
    if (ent->priv == priv) {
      if (pctx->pfds[ent->poll_slot].events != events) {
        pctx->pfds[ent->poll_slot].events = events;
      }
      NOTI_UNLOCK(nctx);
      return 0;
    }
    NOTI_UNLOCK(nctx); 
    //log_debug("events exist %d", fd);
    return -EEXIST;
  }

  //nctx->thr_sel++;
  //tslot = ctx->thr_sel % nctx->n_thrs;
  tslot = fd % nctx->n_thrs;
  pctx = &nctx->poll_ctx[tslot];
  if (pctx->n_pfds >= MAX_NOTIFY_POLL_FDS) {
    NOTI_UNLOCK(nctx);
    log_error("notify no slots exist %d", fd);
    return -EINVAL;
  }

  ent->type = type;
  ent->fd = fd;
  ent->poll_slot = pctx->n_pfds;
  ent->priv = priv;
  ent->thr_id = tslot;
  
  pctx->pfds[pctx->n_pfds].fd = fd;
  pctx->pfds[pctx->n_pfds].events = events;

  nctx->n_fds++;
  pctx->n_pfds++;

  NOTI_UNLOCK(nctx); 

  //log_debug("notify - add fd  %d tslot %d", fd, tslot);
  return 0;
}

int
notify_delete_ent__(void *ctx, int fd)
{
  int i = 0;
  notify_ctx_t *nctx = ctx;
  notify_ent_t *ent;
  notify_ent_t *pent;
  notify_poll_ctx_t *pctx;

  assert(ctx); 

  if (fd <= 0 || fd >= MAX_NOTIFY_FDS) {
    return -EINVAL;
  }

  ent = &nctx->earr[fd];
  if (ent->fd <= 0) {
    return -ENOENT;
  }

  if (ent->poll_slot < 0) {
    assert(0);
  }

  pctx = &nctx->poll_ctx[ent->thr_id];

  for (i = ent->poll_slot; i < pctx->n_pfds - 1; i++) {

    pent = NULL;
    if (pctx->pfds[i+1].fd > 0 && pctx->pfds[i+1].fd < MAX_NOTIFY_FDS) {
      pent = &nctx->earr[pctx->pfds[i+1].fd];
    }

    pctx->pfds[i].fd = pctx->pfds[i+1].fd;
    pctx->pfds[i].events = pctx->pfds[i+1].events;

    if (pent) {
      pent->poll_slot = i;
    }
  }

  //log_debug("notify del fd  %d tslot %d", fd, ent->thr_id);

  ent->fd = -1;
  ent->type = 0; 
  ent->poll_slot = -1;
  if (ent->priv) {
    if (nctx->cbs.pdestroy) {
      nctx->cbs.pdestroy(ent->priv);
    }
    ent->priv = NULL;
  }

  nctx->n_fds--;
  pctx->n_pfds--;

  return 0;
}

int
notify_delete_ent(void *ctx, int fd)
{
  int rc;
  notify_ctx_t *nctx = ctx;

  NOTI_LOCK(nctx);
  rc = notify_delete_ent__(ctx, fd);
  NOTI_UNLOCK(nctx);

  return rc;
}

static void
notify_run(void *ctx, int thread)
{
  int rc = 0;
  int nproc = 0;
  int i = 0;
  int n_pfds = 0;
  void *priv = NULL;
  char estr[128];;
  struct pollfd pfds[MAX_NOTIFY_POLL_FDS];
  notify_ent_t *ent;
  notify_ctx_t *nctx = ctx;

  assert(nctx);

  if (thread >= MAX_NOTIFY_THREADS) {
    assert(0);
  }

  while(1) {

    /* This is seemingly expensive operation */
    NOTI_LOCK(nctx);
    memcpy(pfds, nctx->poll_ctx[thread].pfds, sizeof(pfds));
    n_pfds = nctx->poll_ctx[thread].n_pfds;
    NOTI_UNLOCK(nctx);

    nproc = 0;
    rc = poll(pfds, n_pfds, MAX_NOTIFY_POLL_TIMEO);
    if (rc < 0) {
      log_error("poll :error(%s)", strerror_r(errno, estr, sizeof(estr)));
      usleep(200*1000);
      continue;
    }

    if (rc == 0) {
      continue;
    }

    for (i = 0 ; i < n_pfds; i++) {
      int fd = pfds[i].fd;
      notify_type_t type = notify_conv4mpoll_events(pfds[i].revents);
      if (type == 0) {
        continue;
      }

      if (fd <= 0 || fd >= MAX_NOTIFY_FDS) {
        continue;
      }

      NOTI_LOCK(nctx);
      ent = &nctx->earr[fd];
      if (ent->fd <= 0) {
        NOTI_UNLOCK(nctx);
        continue;
      }
      priv = ent->priv;
      NOTI_UNLOCK(nctx);

      if (nctx->cbs.notify) {
        if (type & NOTI_TYPE_OUT) {
          type |= NOTI_TYPE_IN;
        }
        nctx->cbs.notify(fd, type, priv);
      }

      if (type & (NOTI_TYPE_HUP|NOTI_TYPE_ERROR)) {
        //log_debug("notify hup %d", fd);
        notify_delete_ent__(nctx, fd); 
      }
      nproc++;
    }
  }
}

static void *
notify_run_worker(void *arg)
{
  notify_thr_t *targ = arg;
  notify_run(targ->ctx, targ->thrid);
  return NULL;
}

int
notify_start(void *ctx)
{
  int i = 0;
  pthread_t *ptarr;
  notify_thr_t *nthr;
  notify_ctx_t *nctx = ctx;

  ptarr = calloc(1, nctx->n_thrs*sizeof(pthread_t));

  for (i = 0; i < nctx->n_thrs; i++) {
    nthr = calloc(1, sizeof(*nthr));
    assert(nthr);

    nthr->ctx = ctx;
    nthr->thrid = i;
    pthread_create(&ptarr[i], NULL, notify_run_worker, nthr);
  }

  while (1) {
    sleep(1);
  }
}
