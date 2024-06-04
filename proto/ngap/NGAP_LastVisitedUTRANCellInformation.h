/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_LastVisitedUTRANCellInformation_H_
#define	_NGAP_LastVisitedUTRANCellInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_LastVisitedUTRANCellInformation */
typedef OCTET_STRING_t	 NGAP_LastVisitedUTRANCellInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_LastVisitedUTRANCellInformation;
asn_struct_free_f NGAP_LastVisitedUTRANCellInformation_free;
asn_struct_print_f NGAP_LastVisitedUTRANCellInformation_print;
asn_constr_check_f NGAP_LastVisitedUTRANCellInformation_constraint;
per_type_decoder_f NGAP_LastVisitedUTRANCellInformation_decode_aper;
per_type_encoder_f NGAP_LastVisitedUTRANCellInformation_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_LastVisitedUTRANCellInformation_H_ */
#include <asn_internal.h>
