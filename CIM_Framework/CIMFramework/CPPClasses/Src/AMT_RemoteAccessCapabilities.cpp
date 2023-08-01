//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessCapabilities.cpp
//
//  Contents:   Represents the Remote Access feature capabilities.
//
//              This file was automatically generated from AMT_RemoteAccessCapabilities.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RemoteAccessCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_RemoteAccessCapabilities::_metadata[] = {
		{"MaxTotalMpServers", false, false, false },
		{"MaxTotalPolicies", false, false, false },
		{"MaxMpsPerPolicy", false, false, false },
		{"MaxTotalProxyEntryPoints", false, false, false },
	};
	// class fields
	const unsigned int AMT_RemoteAccessCapabilities::MaxTotalMpServers() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxTotalMpServers"), ret);
		return ret;
	}
	void AMT_RemoteAccessCapabilities::MaxTotalMpServers(const unsigned int value)
	{
		SetOrAddField("MaxTotalMpServers", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessCapabilities::MaxTotalMpServersExists() const
	{
		return ContainsField("MaxTotalMpServers");
	}
	void AMT_RemoteAccessCapabilities::RemoveMaxTotalMpServers()
	{
		RemoveField("MaxTotalMpServers");
	}

	const unsigned int AMT_RemoteAccessCapabilities::MaxTotalPolicies() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxTotalPolicies"), ret);
		return ret;
	}
	void AMT_RemoteAccessCapabilities::MaxTotalPolicies(const unsigned int value)
	{
		SetOrAddField("MaxTotalPolicies", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessCapabilities::MaxTotalPoliciesExists() const
	{
		return ContainsField("MaxTotalPolicies");
	}
	void AMT_RemoteAccessCapabilities::RemoveMaxTotalPolicies()
	{
		RemoveField("MaxTotalPolicies");
	}

	const unsigned int AMT_RemoteAccessCapabilities::MaxMpsPerPolicy() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxMpsPerPolicy"), ret);
		return ret;
	}
	void AMT_RemoteAccessCapabilities::MaxMpsPerPolicy(const unsigned int value)
	{
		SetOrAddField("MaxMpsPerPolicy", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessCapabilities::MaxMpsPerPolicyExists() const
	{
		return ContainsField("MaxMpsPerPolicy");
	}
	void AMT_RemoteAccessCapabilities::RemoveMaxMpsPerPolicy()
	{
		RemoveField("MaxMpsPerPolicy");
	}

	const unsigned int AMT_RemoteAccessCapabilities::MaxTotalProxyEntryPoints() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxTotalProxyEntryPoints"), ret);
		return ret;
	}
	void AMT_RemoteAccessCapabilities::MaxTotalProxyEntryPoints(const unsigned int value)
	{
		SetOrAddField("MaxTotalProxyEntryPoints", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessCapabilities::MaxTotalProxyEntryPointsExists() const
	{
		return ContainsField("MaxTotalProxyEntryPoints");
	}
	void AMT_RemoteAccessCapabilities::RemoveMaxTotalProxyEntryPoints()
	{
		RemoveField("MaxTotalProxyEntryPoints");
	}

	CimBase *AMT_RemoteAccessCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_RemoteAccessCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RemoteAccessCapabilities>(object);
		}
		else
		{
			ret = new AMT_RemoteAccessCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RemoteAccessCapabilities> > AMT_RemoteAccessCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RemoteAccessCapabilities>(client, keys);
	}

	void AMT_RemoteAccessCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RemoteAccessCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_RemoteAccessCapabilities::CLASS_NAME = "AMT_RemoteAccessCapabilities";
	const string AMT_RemoteAccessCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessCapabilities";
	const string AMT_RemoteAccessCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessCapabilities";
	const string AMT_RemoteAccessCapabilities::CLASS_NS_PREFIX = "ARe449";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RemoteAccessCapabilities::_classMetaData;
}
}
}
}
