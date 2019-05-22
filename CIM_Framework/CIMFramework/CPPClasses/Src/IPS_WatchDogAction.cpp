//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_WatchDogAction.cpp
//
//  Contents:   The IPS_WatchDogAction class configures the action of watch dog expiration.
//
//              This file was automatically generated from IPS_WatchDogAction.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#include "IPS_WatchDogAction.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_WatchDogAction::_metadata[] = {
		{"InstanceID", true, false, false },
		{"HeciWatchDogExpirationAction", false, true, false },
		{"AgentPresenceWatchDogExpirationAction", false, true, false },
		{"Timeout", false, false, false },
		{"ReArmReset", false, false, false },
	};
	// class fields
	const unsigned int IPS_WatchDogAction::HeciWatchDogExpirationAction() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("HeciWatchDogExpirationAction"), ret);
		return ret;
	}
	void IPS_WatchDogAction::HeciWatchDogExpirationAction(const unsigned int value)
	{
		SetOrAddField("HeciWatchDogExpirationAction", TypeConverter::TypeToString(value));
	}
	bool IPS_WatchDogAction::HeciWatchDogExpirationActionExists() const
	{
		return ContainsField("HeciWatchDogExpirationAction");
	}
	void IPS_WatchDogAction::RemoveHeciWatchDogExpirationAction()
	{
		RemoveField("HeciWatchDogExpirationAction");
	}

	const unsigned int IPS_WatchDogAction::AgentPresenceWatchDogExpirationAction() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AgentPresenceWatchDogExpirationAction"), ret);
		return ret;
	}
	void IPS_WatchDogAction::AgentPresenceWatchDogExpirationAction(const unsigned int value)
	{
		SetOrAddField("AgentPresenceWatchDogExpirationAction", TypeConverter::TypeToString(value));
	}
	bool IPS_WatchDogAction::AgentPresenceWatchDogExpirationActionExists() const
	{
		return ContainsField("AgentPresenceWatchDogExpirationAction");
	}
	void IPS_WatchDogAction::RemoveAgentPresenceWatchDogExpirationAction()
	{
		RemoveField("AgentPresenceWatchDogExpirationAction");
	}

	const unsigned int IPS_WatchDogAction::Timeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Timeout"), ret);
		return ret;
	}
	void IPS_WatchDogAction::Timeout(const unsigned int value)
	{
		SetOrAddField("Timeout", TypeConverter::TypeToString(value));
	}
	bool IPS_WatchDogAction::TimeoutExists() const
	{
		return ContainsField("Timeout");
	}
	void IPS_WatchDogAction::RemoveTimeout()
	{
		RemoveField("Timeout");
	}

	const bool IPS_WatchDogAction::ReArmReset() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ReArmReset"), ret);
		return ret;
	}
	void IPS_WatchDogAction::ReArmReset(const bool value)
	{
		SetOrAddField("ReArmReset", TypeConverter::TypeToString(value));
	}
	bool IPS_WatchDogAction::ReArmResetExists() const
	{
		return ContainsField("ReArmReset");
	}
	void IPS_WatchDogAction::RemoveReArmReset()
	{
		RemoveField("ReArmReset");
	}

	CimBase *IPS_WatchDogAction::CreateFromCimObject(const CimObject &object)
	{
		IPS_WatchDogAction *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_WatchDogAction>(object);
		}
		else
		{
			ret = new IPS_WatchDogAction(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_WatchDogAction> > IPS_WatchDogAction::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_WatchDogAction>(client, keys);
	}

	void IPS_WatchDogAction::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_WatchDogAction::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_WatchDogAction::ApplyActionOnWatchDog_INPUT::_metadata[] = {
		{"AgentPresenceWatchDog", false, true },
		{"ActionEnable", false, true },
	};
	void IPS_WatchDogAction::ApplyActionOnWatchDog_INPUT::AgentPresenceWatchDog(const CimReference &value)
	{
		SetOrAddField("AgentPresenceWatchDog", TypeConverter::TypeToString(value));
	}
	void IPS_WatchDogAction::ApplyActionOnWatchDog_INPUT::ActionEnable(const bool value)
	{
		SetOrAddField("ActionEnable", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_WatchDogAction::ApplyActionOnWatchDog_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int IPS_WatchDogAction::ApplyActionOnWatchDog(const ApplyActionOnWatchDog_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("ApplyActionOnWatchDog", input, output);
	}
	unsigned int IPS_WatchDogAction::CancelRebootAction()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("CancelRebootAction", input, output);
	}
	const string IPS_WatchDogAction::CLASS_NAME = "IPS_WatchDogAction";
	const string IPS_WatchDogAction::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_WatchDogAction";
	const string IPS_WatchDogAction::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_WatchDogAction";
	const string IPS_WatchDogAction::CLASS_NS_PREFIX = "AWa934";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_WatchDogAction::_classMetaData;
}
}
}
}
