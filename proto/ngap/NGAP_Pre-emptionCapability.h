/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_Pre_emptionCapability_H_
#define	_NGAP_Pre_emptionCapability_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_Pre_emptionCapability {
	NGAP_Pre_emptionCapability_shall_not_trigger_pre_emption	= 0,
	NGAP_Pre_emptionCapability_may_trigger_pre_emption	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_Pre_emptionCapability;

/* NGAP_Pre-emptionCapability */
typedef long	 NGAP_Pre_emptionCapability_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_Pre_emptionCapability_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_Pre_emptionCapability;
extern const asn_INTEGER_specifics_t asn_SPC_NGAP_Pre_emptionCapability_specs_1;
asn_struct_free_f NGAP_Pre_emptionCapability_free;
asn_struct_print_f NGAP_Pre_emptionCapability_print;
asn_constr_check_f NGAP_Pre_emptionCapability_constraint;
per_type_decoder_f NGAP_Pre_emptionCapability_decode_aper;
per_type_encoder_f NGAP_Pre_emptionCapability_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_Pre_emptionCapability_H_ */
#include <asn_internal.h>
