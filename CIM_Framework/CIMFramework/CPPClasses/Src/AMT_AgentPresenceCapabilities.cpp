//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceCapabilities.cpp
//
//  Contents:   Represents the Agent Presence feature capabilities.
//
//              This file was automatically generated from AMT_AgentPresenceCapabilities.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AgentPresenceCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AgentPresenceCapabilities::_metadata[] = {
		{"MaxTotalAgents", false, false, false },
		{"MaxTotalActions", false, false, false },
		{"MinGuaranteedActionListSize", false, false, false },
		{"MaxEacAgents", false, false, false },
	};
	// class fields
	const unsigned int AMT_AgentPresenceCapabilities::MaxTotalAgents() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxTotalAgents"), ret);
		return ret;
	}
	void AMT_AgentPresenceCapabilities::MaxTotalAgents(const unsigned int value)
	{
		SetOrAddField("MaxTotalAgents", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceCapabilities::MaxTotalAgentsExists() const
	{
		return ContainsField("MaxTotalAgents");
	}
	void AMT_AgentPresenceCapabilities::RemoveMaxTotalAgents()
	{
		RemoveField("MaxTotalAgents");
	}

	const unsigned int AMT_AgentPresenceCapabilities::MaxTotalActions() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxTotalActions"), ret);
		return ret;
	}
	void AMT_AgentPresenceCapabilities::MaxTotalActions(const unsigned int value)
	{
		SetOrAddField("MaxTotalActions", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceCapabilities::MaxTotalActionsExists() const
	{
		return ContainsField("MaxTotalActions");
	}
	void AMT_AgentPresenceCapabilities::RemoveMaxTotalActions()
	{
		RemoveField("MaxTotalActions");
	}

	const unsigned int AMT_AgentPresenceCapabilities::MinGuaranteedActionListSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MinGuaranteedActionListSize"), ret);
		return ret;
	}
	void AMT_AgentPresenceCapabilities::MinGuaranteedActionListSize(const unsigned int value)
	{
		SetOrAddField("MinGuaranteedActionListSize", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceCapabilities::MinGuaranteedActionListSizeExists() const
	{
		return ContainsField("MinGuaranteedActionListSize");
	}
	void AMT_AgentPresenceCapabilities::RemoveMinGuaranteedActionListSize()
	{
		RemoveField("MinGuaranteedActionListSize");
	}

	const unsigned int AMT_AgentPresenceCapabilities::MaxEacAgents() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxEacAgents"), ret);
		return ret;
	}
	void AMT_AgentPresenceCapabilities::MaxEacAgents(const unsigned int value)
	{
		SetOrAddField("MaxEacAgents", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceCapabilities::MaxEacAgentsExists() const
	{
		return ContainsField("MaxEacAgents");
	}
	void AMT_AgentPresenceCapabilities::RemoveMaxEacAgents()
	{
		RemoveField("MaxEacAgents");
	}

	CimBase *AMT_AgentPresenceCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_AgentPresenceCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AgentPresenceCapabilities>(object);
		}
		else
		{
			ret = new AMT_AgentPresenceCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AgentPresenceCapabilities> > AMT_AgentPresenceCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AgentPresenceCapabilities>(client, keys);
	}

	void AMT_AgentPresenceCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AgentPresenceCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_AgentPresenceCapabilities::CLASS_NAME = "AMT_AgentPresenceCapabilities";
	const string AMT_AgentPresenceCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceCapabilities";
	const string AMT_AgentPresenceCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceCapabilities";
	const string AMT_AgentPresenceCapabilities::CLASS_NS_PREFIX = "AAg273";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AgentPresenceCapabilities::_classMetaData;
}
}
}
}
