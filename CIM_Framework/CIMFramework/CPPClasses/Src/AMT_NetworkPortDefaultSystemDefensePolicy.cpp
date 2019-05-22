//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkPortDefaultSystemDefensePolicy.cpp
//
//  Contents:   Associates a Network Interface with a System DefensePolicy. An existing association implies that the System Defense Policy is the default policy for the specified interface. It will be activated when no other policies are enabled for that interface.
//
//              This file was automatically generated from AMT_NetworkPortDefaultSystemDefensePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_NetworkPortDefaultSystemDefensePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_NetworkPortDefaultSystemDefensePolicy::_metadata[] = {
		{"Active", false, false, false },
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	const bool AMT_NetworkPortDefaultSystemDefensePolicy::Active() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Active"), ret);
		return ret;
	}
	void AMT_NetworkPortDefaultSystemDefensePolicy::Active(const bool value)
	{
		SetOrAddField("Active", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortDefaultSystemDefensePolicy::ActiveExists() const
	{
		return ContainsField("Active");
	}
	void AMT_NetworkPortDefaultSystemDefensePolicy::RemoveActive()
	{
		RemoveField("Active");
	}

	CimBase *AMT_NetworkPortDefaultSystemDefensePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_NetworkPortDefaultSystemDefensePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_NetworkPortDefaultSystemDefensePolicy>(object);
		}
		else
		{
			ret = new AMT_NetworkPortDefaultSystemDefensePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_NetworkPortDefaultSystemDefensePolicy> > AMT_NetworkPortDefaultSystemDefensePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_NetworkPortDefaultSystemDefensePolicy>(client, keys);
	}

	void AMT_NetworkPortDefaultSystemDefensePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_NetworkPortDefaultSystemDefensePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_NetworkPortDefaultSystemDefensePolicy::CLASS_NAME = "AMT_NetworkPortDefaultSystemDefensePolicy";
	const string AMT_NetworkPortDefaultSystemDefensePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortDefaultSystemDefensePolicy";
	const string AMT_NetworkPortDefaultSystemDefensePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortDefaultSystemDefensePolicy";
	const string AMT_NetworkPortDefaultSystemDefensePolicy::CLASS_NS_PREFIX = "ANe414";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_NetworkPortDefaultSystemDefensePolicy::_classMetaData;
}
}
}
}
