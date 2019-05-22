//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_GeneralSystemDefenseCapabilities.cpp
//
//  Contents:   Describes the system capabilities of the System Defense feature. These capabilities are independent of all network interfaces.
//
//              This file was automatically generated from AMT_GeneralSystemDefenseCapabilities.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_GeneralSystemDefenseCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_GeneralSystemDefenseCapabilities::_metadata[] = {
		{"InstanceID", true, false, false },
		{"GlobalMaxSupportedPolicies", false, false, false },
		{"GlobalMaxSupportedFilters", false, false, false },
	};
	// class fields
	const unsigned int AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedPolicies() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("GlobalMaxSupportedPolicies"), ret);
		return ret;
	}
	void AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedPolicies(const unsigned int value)
	{
		SetOrAddField("GlobalMaxSupportedPolicies", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedPoliciesExists() const
	{
		return ContainsField("GlobalMaxSupportedPolicies");
	}
	void AMT_GeneralSystemDefenseCapabilities::RemoveGlobalMaxSupportedPolicies()
	{
		RemoveField("GlobalMaxSupportedPolicies");
	}

	const unsigned int AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedFilters() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("GlobalMaxSupportedFilters"), ret);
		return ret;
	}
	void AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedFilters(const unsigned int value)
	{
		SetOrAddField("GlobalMaxSupportedFilters", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSystemDefenseCapabilities::GlobalMaxSupportedFiltersExists() const
	{
		return ContainsField("GlobalMaxSupportedFilters");
	}
	void AMT_GeneralSystemDefenseCapabilities::RemoveGlobalMaxSupportedFilters()
	{
		RemoveField("GlobalMaxSupportedFilters");
	}

	CimBase *AMT_GeneralSystemDefenseCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_GeneralSystemDefenseCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_GeneralSystemDefenseCapabilities>(object);
		}
		else
		{
			ret = new AMT_GeneralSystemDefenseCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_GeneralSystemDefenseCapabilities> > AMT_GeneralSystemDefenseCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_GeneralSystemDefenseCapabilities>(client, keys);
	}

	void AMT_GeneralSystemDefenseCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_GeneralSystemDefenseCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_GeneralSystemDefenseCapabilities::CLASS_NAME = "AMT_GeneralSystemDefenseCapabilities";
	const string AMT_GeneralSystemDefenseCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_GeneralSystemDefenseCapabilities";
	const string AMT_GeneralSystemDefenseCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_GeneralSystemDefenseCapabilities";
	const string AMT_GeneralSystemDefenseCapabilities::CLASS_NS_PREFIX = "AGe962";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_GeneralSystemDefenseCapabilities::_classMetaData;
}
}
}
}
