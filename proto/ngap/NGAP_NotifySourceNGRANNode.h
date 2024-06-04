/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_NotifySourceNGRANNode_H_
#define	_NGAP_NotifySourceNGRANNode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_NotifySourceNGRANNode {
	NGAP_NotifySourceNGRANNode_notifySource	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_NotifySourceNGRANNode;

/* NGAP_NotifySourceNGRANNode */
typedef long	 NGAP_NotifySourceNGRANNode_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_NotifySourceNGRANNode_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_NotifySourceNGRANNode;
extern const asn_INTEGER_specifics_t asn_SPC_NGAP_NotifySourceNGRANNode_specs_1;
asn_struct_free_f NGAP_NotifySourceNGRANNode_free;
asn_struct_print_f NGAP_NotifySourceNGRANNode_print;
asn_constr_check_f NGAP_NotifySourceNGRANNode_constraint;
per_type_decoder_f NGAP_NotifySourceNGRANNode_decode_aper;
per_type_encoder_f NGAP_NotifySourceNGRANNode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_NotifySourceNGRANNode_H_ */
#include <asn_internal.h>
