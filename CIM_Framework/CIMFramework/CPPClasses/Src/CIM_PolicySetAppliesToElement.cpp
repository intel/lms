//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySetAppliesToElement.cpp
//
//  Contents:   PolicySetAppliesToElement makes explicit which PolicySets (i.e., policy rules and groups of rules) ARE CURRENTLY applied to a particular Element. This association indicates that the PolicySets that are appropriate for a ManagedElement (specified using the PolicyRoleCollection aggregation) have actually been deployed in the policy management infrastructure. Note that if the named Element refers to a Collection, then the PolicySet is assumed to be applied to all the members of the Collection.
//
//              This file was automatically generated from CIM_PolicySetAppliesToElement.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicySetAppliesToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicySetAppliesToElement::_metadata[] = {
		{"PolicySet", true, false, true },
		{"ManagedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_PolicySetAppliesToElement::PolicySet() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("PolicySet"), ret);
		return ret;
	}
	void CIM_PolicySetAppliesToElement::PolicySet(const CimReference &value)
	{
		SetOrAddField("PolicySet", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_PolicySetAppliesToElement::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_PolicySetAppliesToElement::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_PolicySetAppliesToElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicySetAppliesToElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicySetAppliesToElement>(object);
		}
		else
		{
			ret = new CIM_PolicySetAppliesToElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicySetAppliesToElement> > CIM_PolicySetAppliesToElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicySetAppliesToElement>(client, keys);
	}

	void CIM_PolicySetAppliesToElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicySetAppliesToElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicySetAppliesToElement::CLASS_NAME = "CIM_PolicySetAppliesToElement";
	const string CIM_PolicySetAppliesToElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySetAppliesToElement";
	const string CIM_PolicySetAppliesToElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySetAppliesToElement";
	const string CIM_PolicySetAppliesToElement::CLASS_NS_PREFIX = "APo251";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicySetAppliesToElement::_classMetaData;
}
}
}
}
