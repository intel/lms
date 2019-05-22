//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkPortSystemDefensePolicy.cpp
//
//  Contents:   An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to to 'Enable' a policy for a given interface. Among all the associations that may exist there can be only one 'Active' policy per interface.An Active policy is chosen based on the precedence property in a policy.
//
//              This file was automatically generated from AMT_NetworkPortSystemDefensePolicy.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_NetworkPortSystemDefensePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_NetworkPortSystemDefensePolicy::_metadata[] = {
		{"Enabled", false, false, false },
	};
	// class fields
	const bool AMT_NetworkPortSystemDefensePolicy::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefensePolicy::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefensePolicy::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_NetworkPortSystemDefensePolicy::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *AMT_NetworkPortSystemDefensePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_NetworkPortSystemDefensePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_NetworkPortSystemDefensePolicy>(object);
		}
		else
		{
			ret = new AMT_NetworkPortSystemDefensePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_NetworkPortSystemDefensePolicy> > AMT_NetworkPortSystemDefensePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_NetworkPortSystemDefensePolicy>(client, keys);
	}

	void AMT_NetworkPortSystemDefensePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_NetworkPortSystemDefensePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_NetworkPortSystemDefensePolicy::CLASS_NAME = "AMT_NetworkPortSystemDefensePolicy";
	const string AMT_NetworkPortSystemDefensePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortSystemDefensePolicy";
	const string AMT_NetworkPortSystemDefensePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortSystemDefensePolicy";
	const string AMT_NetworkPortSystemDefensePolicy::CLASS_NS_PREFIX = "ANe893";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_NetworkPortSystemDefensePolicy::_classMetaData;
}
}
}
}
