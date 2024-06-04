/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_NPN_AccessInformation_H_
#define	_NGAP_NPN_AccessInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_NPN_AccessInformation_PR {
	NGAP_NPN_AccessInformation_PR_NOTHING,	/* No components present */
	NGAP_NPN_AccessInformation_PR_pNI_NPN_Access_Information,
	NGAP_NPN_AccessInformation_PR_choice_Extensions
} NGAP_NPN_AccessInformation_PR;

/* Forward declarations */
struct NGAP_CellCAGList;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_NPN-AccessInformation */
typedef struct NGAP_NPN_AccessInformation {
	NGAP_NPN_AccessInformation_PR present;
	union NGAP_NPN_AccessInformation_u {
		struct NGAP_CellCAGList	*pNI_NPN_Access_Information;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_NPN_AccessInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_NPN_AccessInformation;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_NPN_AccessInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_NPN_AccessInformation_1[2];
extern asn_per_constraints_t asn_PER_type_NGAP_NPN_AccessInformation_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_NPN_AccessInformation_H_ */
#include <asn_internal.h>
