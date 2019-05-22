//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceWatchdogAction.cpp
//
//  Contents:   Represents an action which is triggered on an application watchdog state transition.
//
//              This file was automatically generated from AMT_AgentPresenceWatchdogAction.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AgentPresenceWatchdogAction.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AgentPresenceWatchdogAction::_metadata[] = {
		{"EventOnTransition", false, false, false },
		{"ActionSd", false, false, false },
	};
	// class fields
	const bool AMT_AgentPresenceWatchdogAction::EventOnTransition() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("EventOnTransition"), ret);
		return ret;
	}
	void AMT_AgentPresenceWatchdogAction::EventOnTransition(const bool value)
	{
		SetOrAddField("EventOnTransition", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceWatchdogAction::EventOnTransitionExists() const
	{
		return ContainsField("EventOnTransition");
	}
	void AMT_AgentPresenceWatchdogAction::RemoveEventOnTransition()
	{
		RemoveField("EventOnTransition");
	}

	const unsigned short AMT_AgentPresenceWatchdogAction::ActionSd() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ActionSd"), ret);
		return ret;
	}
	void AMT_AgentPresenceWatchdogAction::ActionSd(const unsigned short value)
	{
		SetOrAddField("ActionSd", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceWatchdogAction::ActionSdExists() const
	{
		return ContainsField("ActionSd");
	}
	void AMT_AgentPresenceWatchdogAction::RemoveActionSd()
	{
		RemoveField("ActionSd");
	}

	CimBase *AMT_AgentPresenceWatchdogAction::CreateFromCimObject(const CimObject &object)
	{
		AMT_AgentPresenceWatchdogAction *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AgentPresenceWatchdogAction>(object);
		}
		else
		{
			ret = new AMT_AgentPresenceWatchdogAction(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AgentPresenceWatchdogAction> > AMT_AgentPresenceWatchdogAction::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AgentPresenceWatchdogAction>(client, keys);
	}

	void AMT_AgentPresenceWatchdogAction::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AgentPresenceWatchdogAction::GetMetaData() const
	{
		return _classMetaData;
	}
	const bool AMT_AgentPresenceWatchdogAction::GetActionEac_OUTPUT::ActionEac() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActionEac"), ret);
		return ret;
	}
	bool AMT_AgentPresenceWatchdogAction::GetActionEac_OUTPUT::ActionEacExists() const
	{
		return ContainsField("ActionEac");
	}
	unsigned int AMT_AgentPresenceWatchdogAction::GetActionEac(GetActionEac_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetActionEac", input, output);
	}
	const string AMT_AgentPresenceWatchdogAction::CLASS_NAME = "AMT_AgentPresenceWatchdogAction";
	const string AMT_AgentPresenceWatchdogAction::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceWatchdogAction";
	const string AMT_AgentPresenceWatchdogAction::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceWatchdogAction";
	const string AMT_AgentPresenceWatchdogAction::CLASS_NS_PREFIX = "AAg892";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AgentPresenceWatchdogAction::_classMetaData;
}
}
}
}
