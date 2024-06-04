/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_MBSSessionSetupOrModRequestTransfer_H_
#define	_NGAP_MBSSessionSetupOrModRequestTransfer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_MBSSessionSetupOrModRequestTransfer */
typedef struct NGAP_MBSSessionSetupOrModRequestTransfer {
	NGAP_ProtocolIE_Container_11854P119_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_MBSSessionSetupOrModRequestTransfer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_MBSSessionSetupOrModRequestTransfer;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_MBSSessionSetupOrModRequestTransfer_H_ */
#include <asn_internal.h>
