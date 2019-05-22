//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_InterfacePolicy.cpp
//
//  Contents:   Associates a System Defense Policy to a Network Interface. An existing association implies that a System Defense Policy may be activated on the specified interface. Among all the associations that may exist there can be only one active policy per interface. An Active policy is chosen based on the precedence property in a policy.
//
//              This file was automatically generated from AMT_InterfacePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_InterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_InterfacePolicy::_metadata[] = {
		{"Active", false, false, false },
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	const bool AMT_InterfacePolicy::Active() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Active"), ret);
		return ret;
	}
	void AMT_InterfacePolicy::Active(const bool value)
	{
		SetOrAddField("Active", TypeConverter::TypeToString(value));
	}
	bool AMT_InterfacePolicy::ActiveExists() const
	{
		return ContainsField("Active");
	}
	void AMT_InterfacePolicy::RemoveActive()
	{
		RemoveField("Active");
	}

	CimBase *AMT_InterfacePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_InterfacePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_InterfacePolicy>(object);
		}
		else
		{
			ret = new AMT_InterfacePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_InterfacePolicy> > AMT_InterfacePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_InterfacePolicy>(client, keys);
	}

	void AMT_InterfacePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_InterfacePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_InterfacePolicy::CLASS_NAME = "AMT_InterfacePolicy";
	const string AMT_InterfacePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_InterfacePolicy";
	const string AMT_InterfacePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_InterfacePolicy";
	const string AMT_InterfacePolicy::CLASS_NS_PREFIX = "AIn372";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_InterfacePolicy::_classMetaData;
}
}
}
}
