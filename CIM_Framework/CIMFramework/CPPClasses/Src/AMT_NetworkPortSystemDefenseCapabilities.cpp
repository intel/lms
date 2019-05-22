//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkPortSystemDefenseCapabilities.cpp
//
//  Contents:   Describes the System Defense capabilities of a single network port.
//
//              This file was automatically generated from AMT_NetworkPortSystemDefenseCapabilities.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_NetworkPortSystemDefenseCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_NetworkPortSystemDefenseCapabilities::_metadata[] = {
		{"InstanceID", true, false, false },
		{"IPv4_MaxTxFilters", false, false, false },
		{"IPv4_MaxTxCounters", false, false, false },
		{"IPv4_MaxRxFilters", false, false, false },
		{"IPv4_MaxRxCounters", false, false, false },
		{"IPv4_AntiSpoofingCapable", false, false, false },
		{"IPv6_MaxTxFilters", false, false, false },
		{"IPv6_MaxTxCounters", false, false, false },
		{"IPv6_MaxRxFilters", false, false, false },
		{"IPv6_MaxRxCounters", false, false, false },
		{"IPv6_AntiSpoofingCapable", false, false, false },
		{"IPv6_to_IPv4_Ratio", false, false, false },
	};
	// class fields
	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxFilters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv4_MaxTxFilters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxFilters(const unsigned short value)
	{
		SetOrAddField("IPv4_MaxTxFilters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxFiltersExists() const
	{
		return ContainsField("IPv4_MaxTxFilters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv4_MaxTxFilters()
	{
		RemoveField("IPv4_MaxTxFilters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxCounters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv4_MaxTxCounters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxCounters(const unsigned short value)
	{
		SetOrAddField("IPv4_MaxTxCounters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxTxCountersExists() const
	{
		return ContainsField("IPv4_MaxTxCounters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv4_MaxTxCounters()
	{
		RemoveField("IPv4_MaxTxCounters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxFilters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv4_MaxRxFilters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxFilters(const unsigned short value)
	{
		SetOrAddField("IPv4_MaxRxFilters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxFiltersExists() const
	{
		return ContainsField("IPv4_MaxRxFilters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv4_MaxRxFilters()
	{
		RemoveField("IPv4_MaxRxFilters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxCounters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv4_MaxRxCounters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxCounters(const unsigned short value)
	{
		SetOrAddField("IPv4_MaxRxCounters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_MaxRxCountersExists() const
	{
		return ContainsField("IPv4_MaxRxCounters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv4_MaxRxCounters()
	{
		RemoveField("IPv4_MaxRxCounters");
	}

	const bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_AntiSpoofingCapable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IPv4_AntiSpoofingCapable"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv4_AntiSpoofingCapable(const bool value)
	{
		SetOrAddField("IPv4_AntiSpoofingCapable", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv4_AntiSpoofingCapableExists() const
	{
		return ContainsField("IPv4_AntiSpoofingCapable");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv4_AntiSpoofingCapable()
	{
		RemoveField("IPv4_AntiSpoofingCapable");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxFilters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv6_MaxTxFilters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxFilters(const unsigned short value)
	{
		SetOrAddField("IPv6_MaxTxFilters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxFiltersExists() const
	{
		return ContainsField("IPv6_MaxTxFilters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_MaxTxFilters()
	{
		RemoveField("IPv6_MaxTxFilters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxCounters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv6_MaxTxCounters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxCounters(const unsigned short value)
	{
		SetOrAddField("IPv6_MaxTxCounters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxTxCountersExists() const
	{
		return ContainsField("IPv6_MaxTxCounters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_MaxTxCounters()
	{
		RemoveField("IPv6_MaxTxCounters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxFilters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv6_MaxRxFilters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxFilters(const unsigned short value)
	{
		SetOrAddField("IPv6_MaxRxFilters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxFiltersExists() const
	{
		return ContainsField("IPv6_MaxRxFilters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_MaxRxFilters()
	{
		RemoveField("IPv6_MaxRxFilters");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxCounters() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv6_MaxRxCounters"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxCounters(const unsigned short value)
	{
		SetOrAddField("IPv6_MaxRxCounters", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_MaxRxCountersExists() const
	{
		return ContainsField("IPv6_MaxRxCounters");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_MaxRxCounters()
	{
		RemoveField("IPv6_MaxRxCounters");
	}

	const bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_AntiSpoofingCapable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IPv6_AntiSpoofingCapable"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_AntiSpoofingCapable(const bool value)
	{
		SetOrAddField("IPv6_AntiSpoofingCapable", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_AntiSpoofingCapableExists() const
	{
		return ContainsField("IPv6_AntiSpoofingCapable");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_AntiSpoofingCapable()
	{
		RemoveField("IPv6_AntiSpoofingCapable");
	}

	const unsigned short AMT_NetworkPortSystemDefenseCapabilities::IPv6_to_IPv4_Ratio() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IPv6_to_IPv4_Ratio"), ret);
		return ret;
	}
	void AMT_NetworkPortSystemDefenseCapabilities::IPv6_to_IPv4_Ratio(const unsigned short value)
	{
		SetOrAddField("IPv6_to_IPv4_Ratio", TypeConverter::TypeToString(value));
	}
	bool AMT_NetworkPortSystemDefenseCapabilities::IPv6_to_IPv4_RatioExists() const
	{
		return ContainsField("IPv6_to_IPv4_Ratio");
	}
	void AMT_NetworkPortSystemDefenseCapabilities::RemoveIPv6_to_IPv4_Ratio()
	{
		RemoveField("IPv6_to_IPv4_Ratio");
	}

	CimBase *AMT_NetworkPortSystemDefenseCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_NetworkPortSystemDefenseCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_NetworkPortSystemDefenseCapabilities>(object);
		}
		else
		{
			ret = new AMT_NetworkPortSystemDefenseCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_NetworkPortSystemDefenseCapabilities> > AMT_NetworkPortSystemDefenseCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_NetworkPortSystemDefenseCapabilities>(client, keys);
	}

	void AMT_NetworkPortSystemDefenseCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_NetworkPortSystemDefenseCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_NetworkPortSystemDefenseCapabilities::CLASS_NAME = "AMT_NetworkPortSystemDefenseCapabilities";
	const string AMT_NetworkPortSystemDefenseCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortSystemDefenseCapabilities";
	const string AMT_NetworkPortSystemDefenseCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkPortSystemDefenseCapabilities";
	const string AMT_NetworkPortSystemDefenseCapabilities::CLASS_NS_PREFIX = "ANe511";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_NetworkPortSystemDefenseCapabilities::_classMetaData;
}
}
}
}
