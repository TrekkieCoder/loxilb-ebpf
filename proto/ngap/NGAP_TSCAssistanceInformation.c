/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_TSCAssistanceInformation.h"

#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_TSCAssistanceInformation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_TSCAssistanceInformation, periodicity),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_Periodicity,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"periodicity"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_TSCAssistanceInformation, burstArrivalTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_BurstArrivalTime,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"burstArrivalTime"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_TSCAssistanceInformation, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P339,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_NGAP_TSCAssistanceInformation_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_NGAP_TSCAssistanceInformation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_TSCAssistanceInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* periodicity */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* burstArrivalTime */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_TSCAssistanceInformation_specs_1 = {
	sizeof(struct NGAP_TSCAssistanceInformation),
	offsetof(struct NGAP_TSCAssistanceInformation, _asn_ctx),
	asn_MAP_NGAP_TSCAssistanceInformation_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NGAP_TSCAssistanceInformation_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_TSCAssistanceInformation = {
	"TSCAssistanceInformation",
	"TSCAssistanceInformation",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_TSCAssistanceInformation_tags_1,
	sizeof(asn_DEF_NGAP_TSCAssistanceInformation_tags_1)
		/sizeof(asn_DEF_NGAP_TSCAssistanceInformation_tags_1[0]), /* 1 */
	asn_DEF_NGAP_TSCAssistanceInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_TSCAssistanceInformation_tags_1)
		/sizeof(asn_DEF_NGAP_TSCAssistanceInformation_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_TSCAssistanceInformation_1,
	3,	/* Elements count */
	&asn_SPC_NGAP_TSCAssistanceInformation_specs_1	/* Additional specs */
};

