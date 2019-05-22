//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterInterfacePolicy.cpp
//
//  Contents:   An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to set a Heuristic Packet Filter configuration, that will cause the policy to move to the 'Enabled' System Defense policy state in case of a threshold breach.As per the rules for System Defense policies, an Enabled policy will become Active if it has the highest priority of all policies enabled for the particular network interface.
//
//              This file was automatically generated from AMT_HeuristicPacketFilterInterfacePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_HeuristicPacketFilterInterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_HeuristicPacketFilterInterfacePolicy::_metadata[] = {
		{"Enabled", false, false, false },
		{"Dependent", true, false, true },
		{"Antecedent", true, false, true },
	};
	// class fields
	const bool AMT_HeuristicPacketFilterInterfacePolicy::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterInterfacePolicy::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterInterfacePolicy::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_HeuristicPacketFilterInterfacePolicy::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *AMT_HeuristicPacketFilterInterfacePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_HeuristicPacketFilterInterfacePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_HeuristicPacketFilterInterfacePolicy>(object);
		}
		else
		{
			ret = new AMT_HeuristicPacketFilterInterfacePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_HeuristicPacketFilterInterfacePolicy> > AMT_HeuristicPacketFilterInterfacePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_HeuristicPacketFilterInterfacePolicy>(client, keys);
	}

	void AMT_HeuristicPacketFilterInterfacePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_HeuristicPacketFilterInterfacePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_HeuristicPacketFilterInterfacePolicy::CLASS_NAME = "AMT_HeuristicPacketFilterInterfacePolicy";
	const string AMT_HeuristicPacketFilterInterfacePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterInterfacePolicy";
	const string AMT_HeuristicPacketFilterInterfacePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterInterfacePolicy";
	const string AMT_HeuristicPacketFilterInterfacePolicy::CLASS_NS_PREFIX = "AHe496";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_HeuristicPacketFilterInterfacePolicy::_classMetaData;
}
}
}
}
