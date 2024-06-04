/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_AreaOfInterestCellItem_H_
#define	_NGAP_AreaOfInterestCellItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_NGRAN-CGI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_AreaOfInterestCellItem */
typedef struct NGAP_AreaOfInterestCellItem {
	NGAP_NGRAN_CGI_t	 nGRAN_CGI;
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_AreaOfInterestCellItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_AreaOfInterestCellItem;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_AreaOfInterestCellItem_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_AreaOfInterestCellItem_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_AreaOfInterestCellItem_H_ */
#include <asn_internal.h>
