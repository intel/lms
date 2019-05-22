//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SAPAvailableForElement.cpp
//
//  Contents:   CIM_SAPAvailableForElement conveys the semantics of a Service Access Point that is available for a ManagedElement. When CIM_SAPAvailableForElement is not instantiated, then the SAP is assumed to be generally available. If instantiated, the SAP is available only for the associated ManagedElements. For example, a device might provide management access through a URL. This association allows the URL to be advertised for the device.
//
//              This file was automatically generated from CIM_SAPAvailableForElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_SAPAvailableForElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SAPAvailableForElement::_metadata[] = {
		{"AvailableSAP", true, false, true },
		{"ManagedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_SAPAvailableForElement::AvailableSAP() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("AvailableSAP"), ret);
		return ret;
	}
	void CIM_SAPAvailableForElement::AvailableSAP(const CimReference &value)
	{
		SetOrAddField("AvailableSAP", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_SAPAvailableForElement::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_SAPAvailableForElement::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_SAPAvailableForElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_SAPAvailableForElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SAPAvailableForElement>(object);
		}
		else
		{
			ret = new CIM_SAPAvailableForElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SAPAvailableForElement> > CIM_SAPAvailableForElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SAPAvailableForElement>(client, keys);
	}

	void CIM_SAPAvailableForElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SAPAvailableForElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SAPAvailableForElement::CLASS_NAME = "CIM_SAPAvailableForElement";
	const string CIM_SAPAvailableForElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SAPAvailableForElement";
	const string CIM_SAPAvailableForElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SAPAvailableForElement";
	const string CIM_SAPAvailableForElement::CLASS_NS_PREFIX = "ASA246";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SAPAvailableForElement::_classMetaData;
}
}
}
}
