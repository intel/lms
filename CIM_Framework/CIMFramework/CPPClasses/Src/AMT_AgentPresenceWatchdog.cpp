//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceWatchdog.cpp
//
//  Contents:   Represents the monitoring state associated with a single agent.
//
//              This file was automatically generated from AMT_AgentPresenceWatchdog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AgentPresenceWatchdog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AgentPresenceWatchdog::_metadata[] = {
		{"CurrentState", false, false, false },
		{"StartupInterval", false, true, false },
		{"MonitoredEntityDescription", false, false, false },
		{"DeviceID", true, false, false },
		{"TimeoutInterval", false, true, false },
	};
	// class fields
	const unsigned short AMT_AgentPresenceWatchdog::CurrentState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CurrentState"), ret);
		return ret;
	}
	void AMT_AgentPresenceWatchdog::CurrentState(const unsigned short value)
	{
		SetOrAddField("CurrentState", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceWatchdog::CurrentStateExists() const
	{
		return ContainsField("CurrentState");
	}
	void AMT_AgentPresenceWatchdog::RemoveCurrentState()
	{
		RemoveField("CurrentState");
	}

	const unsigned short AMT_AgentPresenceWatchdog::StartupInterval() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("StartupInterval"), ret);
		return ret;
	}
	void AMT_AgentPresenceWatchdog::StartupInterval(const unsigned short value)
	{
		SetOrAddField("StartupInterval", TypeConverter::TypeToString(value));
	}
	bool AMT_AgentPresenceWatchdog::StartupIntervalExists() const
	{
		return ContainsField("StartupInterval");
	}
	void AMT_AgentPresenceWatchdog::RemoveStartupInterval()
	{
		RemoveField("StartupInterval");
	}

	CimBase *AMT_AgentPresenceWatchdog::CreateFromCimObject(const CimObject &object)
	{
		AMT_AgentPresenceWatchdog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AgentPresenceWatchdog>(object);
		}
		else
		{
			ret = new AMT_AgentPresenceWatchdog(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AgentPresenceWatchdog> > AMT_AgentPresenceWatchdog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AgentPresenceWatchdog>(client, keys);
	}

	void AMT_AgentPresenceWatchdog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AgentPresenceWatchdog::GetMetaData() const
	{
		return _classMetaData;
	}
	const unsigned int AMT_AgentPresenceWatchdog::RegisterAgent_OUTPUT::SessionSequenceNumber() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("SessionSequenceNumber"), ret);
		return ret;
	}
	bool AMT_AgentPresenceWatchdog::RegisterAgent_OUTPUT::SessionSequenceNumberExists() const
	{
		return ContainsField("SessionSequenceNumber");
	}
	const unsigned short AMT_AgentPresenceWatchdog::RegisterAgent_OUTPUT::TimeoutInterval() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TimeoutInterval"), ret);
		return ret;
	}
	bool AMT_AgentPresenceWatchdog::RegisterAgent_OUTPUT::TimeoutIntervalExists() const
	{
		return ContainsField("TimeoutInterval");
	}
	unsigned int AMT_AgentPresenceWatchdog::RegisterAgent(RegisterAgent_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("RegisterAgent", input, output);
	}
	const CimFieldAttribute AMT_AgentPresenceWatchdog::AssertPresence_INPUT::_metadata[] = {
		{"SequenceNumber", false, true },
	};
	void AMT_AgentPresenceWatchdog::AssertPresence_INPUT::SequenceNumber(const unsigned int value)
	{
		SetOrAddField("SequenceNumber", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AgentPresenceWatchdog::AssertPresence_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_AgentPresenceWatchdog::AssertPresence(const AssertPresence_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AssertPresence", input, output);
	}
	const CimFieldAttribute AMT_AgentPresenceWatchdog::AssertShutdown_INPUT::_metadata[] = {
		{"SequenceNumber", false, true },
	};
	void AMT_AgentPresenceWatchdog::AssertShutdown_INPUT::SequenceNumber(const unsigned int value)
	{
		SetOrAddField("SequenceNumber", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AgentPresenceWatchdog::AssertShutdown_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_AgentPresenceWatchdog::AssertShutdown(const AssertShutdown_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AssertShutdown", input, output);
	}
	const CimFieldAttribute AMT_AgentPresenceWatchdog::AddAction_INPUT::_metadata[] = {
		{"OldState", false, true },
		{"NewState", false, true },
		{"EventOnTransition", false, true },
		{"ActionSd", false, false },
		{"ActionEac", false, false },
	};
	void AMT_AgentPresenceWatchdog::AddAction_INPUT::OldState(const unsigned short value)
	{
		SetOrAddField("OldState", TypeConverter::TypeToString(value));
	}
	void AMT_AgentPresenceWatchdog::AddAction_INPUT::NewState(const unsigned short value)
	{
		SetOrAddField("NewState", TypeConverter::TypeToString(value));
	}
	void AMT_AgentPresenceWatchdog::AddAction_INPUT::EventOnTransition(const bool value)
	{
		SetOrAddField("EventOnTransition", TypeConverter::TypeToString(value));
	}
	void AMT_AgentPresenceWatchdog::AddAction_INPUT::ActionSd(const unsigned short value)
	{
		SetOrAddField("ActionSd", TypeConverter::TypeToString(value));
	}
	void AMT_AgentPresenceWatchdog::AddAction_INPUT::ActionEac(const bool value)
	{
		SetOrAddField("ActionEac", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AgentPresenceWatchdog::AddAction_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	unsigned int AMT_AgentPresenceWatchdog::AddAction(const AddAction_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AddAction", input, output);
	}
	unsigned int AMT_AgentPresenceWatchdog::DeleteAllActions()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("DeleteAllActions", input, output);
	}
	const string AMT_AgentPresenceWatchdog::CLASS_NAME = "AMT_AgentPresenceWatchdog";
	const string AMT_AgentPresenceWatchdog::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceWatchdog";
	const string AMT_AgentPresenceWatchdog::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceWatchdog";
	const string AMT_AgentPresenceWatchdog::CLASS_NS_PREFIX = "AAg838";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AgentPresenceWatchdog::_classMetaData;
}
}
}
}
