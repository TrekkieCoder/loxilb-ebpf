/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./ngap.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_PDUSessionResourceInformationItem.h"

#include "NGAP_DRBsToQosFlowsMappingList.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_PDUSessionResourceInformationItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceInformationItem, pDUSessionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PDUSessionID,
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
		"pDUSessionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceInformationItem, qosFlowInformationList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_QosFlowInformationList,
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
		"qosFlowInformationList"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_PDUSessionResourceInformationItem, dRBsToQosFlowsMappingList),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_DRBsToQosFlowsMappingList,
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
		"dRBsToQosFlowsMappingList"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_PDUSessionResourceInformationItem, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P224,
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
static const int asn_MAP_NGAP_PDUSessionResourceInformationItem_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_PDUSessionResourceInformationItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pDUSessionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* qosFlowInformationList */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dRBsToQosFlowsMappingList */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_PDUSessionResourceInformationItem_specs_1 = {
	sizeof(struct NGAP_PDUSessionResourceInformationItem),
	offsetof(struct NGAP_PDUSessionResourceInformationItem, _asn_ctx),
	asn_MAP_NGAP_PDUSessionResourceInformationItem_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_NGAP_PDUSessionResourceInformationItem_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_PDUSessionResourceInformationItem = {
	"PDUSessionResourceInformationItem",
	"PDUSessionResourceInformationItem",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1,
	sizeof(asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1[0]), /* 1 */
	asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceInformationItem_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_PDUSessionResourceInformationItem_1,
	4,	/* Elements count */
	&asn_SPC_NGAP_PDUSessionResourceInformationItem_specs_1	/* Additional specs */
};

