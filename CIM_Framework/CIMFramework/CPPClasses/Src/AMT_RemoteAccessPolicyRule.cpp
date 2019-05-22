//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessPolicyRule.cpp
//
//  Contents:   Represents a Remote Access policy. The policy defines a condition that will trigger the establishment of a tunnel between the Intel(R) AMT subsystem and a remote MpServer. The policy also defines parameters for the connection such as TunnelLifeTime in seconds.
//
//              This file was automatically generated from AMT_RemoteAccessPolicyRule.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RemoteAccessPolicyRule.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_RemoteAccessPolicyRule::_metadata[] = {
		{"Trigger", false, true, false },
		{"TunnelLifeTime", false, true, false },
		{"ExtendedData", false, false, false },
	};
	// class fields
	const unsigned short AMT_RemoteAccessPolicyRule::Trigger() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Trigger"), ret);
		return ret;
	}
	void AMT_RemoteAccessPolicyRule::Trigger(const unsigned short value)
	{
		SetOrAddField("Trigger", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessPolicyRule::TriggerExists() const
	{
		return ContainsField("Trigger");
	}
	void AMT_RemoteAccessPolicyRule::RemoveTrigger()
	{
		RemoveField("Trigger");
	}

	const unsigned int AMT_RemoteAccessPolicyRule::TunnelLifeTime() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TunnelLifeTime"), ret);
		return ret;
	}
	void AMT_RemoteAccessPolicyRule::TunnelLifeTime(const unsigned int value)
	{
		SetOrAddField("TunnelLifeTime", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessPolicyRule::TunnelLifeTimeExists() const
	{
		return ContainsField("TunnelLifeTime");
	}
	void AMT_RemoteAccessPolicyRule::RemoveTunnelLifeTime()
	{
		RemoveField("TunnelLifeTime");
	}

	const Base64 AMT_RemoteAccessPolicyRule::ExtendedData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ExtendedData"), ret);
		return ret;
	}
	void AMT_RemoteAccessPolicyRule::ExtendedData(const Base64 &value)
	{
		SetOrAddField("ExtendedData", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessPolicyRule::ExtendedDataExists() const
	{
		return ContainsField("ExtendedData");
	}
	void AMT_RemoteAccessPolicyRule::RemoveExtendedData()
	{
		RemoveField("ExtendedData");
	}

	CimBase *AMT_RemoteAccessPolicyRule::CreateFromCimObject(const CimObject &object)
	{
		AMT_RemoteAccessPolicyRule *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RemoteAccessPolicyRule>(object);
		}
		else
		{
			ret = new AMT_RemoteAccessPolicyRule(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RemoteAccessPolicyRule> > AMT_RemoteAccessPolicyRule::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RemoteAccessPolicyRule>(client, keys);
	}

	void AMT_RemoteAccessPolicyRule::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RemoteAccessPolicyRule::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_RemoteAccessPolicyRule::CLASS_NAME = "AMT_RemoteAccessPolicyRule";
	const string AMT_RemoteAccessPolicyRule::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessPolicyRule";
	const string AMT_RemoteAccessPolicyRule::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessPolicyRule";
	const string AMT_RemoteAccessPolicyRule::CLASS_NS_PREFIX = "ARe489";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RemoteAccessPolicyRule::_classMetaData;
}
}
}
}
