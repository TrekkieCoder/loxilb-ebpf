/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_ResetType_H_
#define	_NGAP_ResetType_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_ResetAll.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_ResetType_PR {
	NGAP_ResetType_PR_NOTHING,	/* No components present */
	NGAP_ResetType_PR_nG_Interface,
	NGAP_ResetType_PR_partOfNG_Interface,
	NGAP_ResetType_PR_choice_Extensions
} NGAP_ResetType_PR;

/* Forward declarations */
struct NGAP_UE_associatedLogicalNG_connectionList;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_ResetType */
typedef struct NGAP_ResetType {
	NGAP_ResetType_PR present;
	union NGAP_ResetType_u {
		NGAP_ResetAll_t	 nG_Interface;
		struct NGAP_UE_associatedLogicalNG_connectionList	*partOfNG_Interface;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_ResetType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ResetType;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_ResetType_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_ResetType_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_ResetType_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_ResetType_H_ */
#include <asn_internal.h>
