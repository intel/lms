//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAffectsElement.cpp
//
//  Contents:   ServiceAffectsElement represents an association between a Service and the ManagedElements that might be affected by its execution. Instantiating this association indicates that running the service may change, manage, provide functionality for,or pose some burden on the ManagedElement. This burden might affect performance, throughput, availability, and so on.
//
//              This file was automatically generated from CIM_ServiceAffectsElement.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceAffectsElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceAffectsElement::_metadata[] = {
		{"AffectedElement", true, false, true },
		{"AffectingElement", true, false, true },
		{"ElementEffects", false, false, false },
		{"OtherElementEffectsDescriptions", false, false, false },
	};
	// class fields
	const CimReference CIM_ServiceAffectsElement::AffectedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("AffectedElement"), ret);
		return ret;
	}
	void CIM_ServiceAffectsElement::AffectedElement(const CimReference &value)
	{
		SetOrAddField("AffectedElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ServiceAffectsElement::AffectingElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("AffectingElement"), ret);
		return ret;
	}
	void CIM_ServiceAffectsElement::AffectingElement(const CimReference &value)
	{
		SetOrAddField("AffectingElement", TypeConverter::TypeToString(value));
	}

	const vector<unsigned short> CIM_ServiceAffectsElement::ElementEffects() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ElementEffects"), ret);
		return ret;
	}
	void CIM_ServiceAffectsElement::ElementEffects(const vector<unsigned short> &value)
	{
		SetOrAddField("ElementEffects", TypeConverter::TypeToString(value));
	}
	bool CIM_ServiceAffectsElement::ElementEffectsExists() const
	{
		return ContainsField("ElementEffects");
	}
	void CIM_ServiceAffectsElement::RemoveElementEffects()
	{
		RemoveField("ElementEffects");
	}

	const vector<string> CIM_ServiceAffectsElement::OtherElementEffectsDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherElementEffectsDescriptions"), ret);
		return ret;
	}
	void CIM_ServiceAffectsElement::OtherElementEffectsDescriptions(const vector<string> &value)
	{
		SetOrAddField("OtherElementEffectsDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_ServiceAffectsElement::OtherElementEffectsDescriptionsExists() const
	{
		return ContainsField("OtherElementEffectsDescriptions");
	}
	void CIM_ServiceAffectsElement::RemoveOtherElementEffectsDescriptions()
	{
		RemoveField("OtherElementEffectsDescriptions");
	}

	CimBase *CIM_ServiceAffectsElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceAffectsElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceAffectsElement>(object);
		}
		else
		{
			ret = new CIM_ServiceAffectsElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceAffectsElement> > CIM_ServiceAffectsElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceAffectsElement>(client, keys);
	}

	void CIM_ServiceAffectsElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceAffectsElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ServiceAffectsElement::CLASS_NAME = "CIM_ServiceAffectsElement";
	const string CIM_ServiceAffectsElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAffectsElement";
	const string CIM_ServiceAffectsElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAffectsElement";
	const string CIM_ServiceAffectsElement::CLASS_NS_PREFIX = "ASe5";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceAffectsElement::_classMetaData;
}
}
}
}
