//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceInterfacePolicy.cpp
//
//  Contents:   An existing association implies that a System Defense Policy may be activated on the specified interface. A management console may create an instance of this class in order to set a global Agent Presence configuration that should enable a policy in case of a corresponding Agent Presence state change.
//
//              This file was automatically generated from AMT_AgentPresenceInterfacePolicy.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AgentPresenceInterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AgentPresenceInterfacePolicy::_metadata[] = {
		{"Enabled", false, false, false },
	};
	// class fields
	const bool AMT_AgentPresenceInterfacePolicy::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_AgentPresenceInterfacePolicy::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceInterfacePolicy::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_AgentPresenceInterfacePolicy::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *AMT_AgentPresenceInterfacePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_AgentPresenceInterfacePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AgentPresenceInterfacePolicy>(object);
		}
		else
		{
			ret = new AMT_AgentPresenceInterfacePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AgentPresenceInterfacePolicy> > AMT_AgentPresenceInterfacePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AgentPresenceInterfacePolicy>(client, keys);
	}

	void AMT_AgentPresenceInterfacePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AgentPresenceInterfacePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_AgentPresenceInterfacePolicy::CLASS_NAME = "AMT_AgentPresenceInterfacePolicy";
	const string AMT_AgentPresenceInterfacePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceInterfacePolicy";
	const string AMT_AgentPresenceInterfacePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceInterfacePolicy";
	const string AMT_AgentPresenceInterfacePolicy::CLASS_NS_PREFIX = "AAg242";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AgentPresenceInterfacePolicy::_classMetaData;
}
}
}
}
