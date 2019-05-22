//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AbstractIndicationSubscription.cpp
//
//  Contents:   CIM_IndicationSubscription describes a flow of Indications. The flow is specified by the referenced Filter, and directed to the referenced destination or process in the Handler. Property values of the referenced CIM_IndicationFilter instance and CIM_ListenerDestination instance MAY significantly effect the definition of the subscription. E.g., a subscription associated with a "Transient" destination MAY be deleted when the destination terminates or is no longer available.
//
//              This file was automatically generated from CIM_AbstractIndicationSubscription.mof,  version: 2.31.0
//
//----------------------------------------------------------------------------
#include "CIM_AbstractIndicationSubscription.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AbstractIndicationSubscription::_metadata[] = {
		{"Filter", true, false, true },
		{"Handler", true, false, true },
		{"OnFatalErrorPolicy", false, false, false },
		{"OtherOnFatalErrorPolicy", false, false, false },
		{"FailureTriggerTimeInterval", false, false, false },
		{"SubscriptionState", false, false, false },
		{"OtherSubscriptionState", false, false, false },
		{"TimeOfLastStateChange", false, false, false },
		{"SubscriptionDuration", false, false, false },
		{"SubscriptionStartTime", false, false, false },
		{"SubscriptionTimeRemaining", false, false, false },
		{"RepeatNotificationPolicy", false, false, false },
		{"OtherRepeatNotificationPolicy", false, false, false },
		{"RepeatNotificationInterval", false, false, false },
		{"RepeatNotificationGap", false, false, false },
		{"RepeatNotificationCount", false, false, false },
		{"SubscriptionInfo", false, false, false },
	};
	// class fields
	const CimReference CIM_AbstractIndicationSubscription::Filter() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Filter"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::Filter(const CimReference &value)
	{
		SetOrAddField("Filter", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_AbstractIndicationSubscription::Handler() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Handler"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::Handler(const CimReference &value)
	{
		SetOrAddField("Handler", TypeConverter::TypeToString(value));
	}

	const unsigned short CIM_AbstractIndicationSubscription::OnFatalErrorPolicy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OnFatalErrorPolicy"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::OnFatalErrorPolicy(const unsigned short value)
	{
		SetOrAddField("OnFatalErrorPolicy", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::OnFatalErrorPolicyExists() const
	{
		return ContainsField("OnFatalErrorPolicy");
	}
	void CIM_AbstractIndicationSubscription::RemoveOnFatalErrorPolicy()
	{
		RemoveField("OnFatalErrorPolicy");
	}

	const string CIM_AbstractIndicationSubscription::OtherOnFatalErrorPolicy() const
	{
		return GetField("OtherOnFatalErrorPolicy")[0];
	}
	void CIM_AbstractIndicationSubscription::OtherOnFatalErrorPolicy(const string &value)
	{
		SetOrAddField("OtherOnFatalErrorPolicy", value);
	}
	bool CIM_AbstractIndicationSubscription::OtherOnFatalErrorPolicyExists() const
	{
		return ContainsField("OtherOnFatalErrorPolicy");
	}
	void CIM_AbstractIndicationSubscription::RemoveOtherOnFatalErrorPolicy()
	{
		RemoveField("OtherOnFatalErrorPolicy");
	}

	const Uint64 CIM_AbstractIndicationSubscription::FailureTriggerTimeInterval() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("FailureTriggerTimeInterval"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::FailureTriggerTimeInterval(const Uint64 value)
	{
		SetOrAddField("FailureTriggerTimeInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::FailureTriggerTimeIntervalExists() const
	{
		return ContainsField("FailureTriggerTimeInterval");
	}
	void CIM_AbstractIndicationSubscription::RemoveFailureTriggerTimeInterval()
	{
		RemoveField("FailureTriggerTimeInterval");
	}

	const unsigned short CIM_AbstractIndicationSubscription::SubscriptionState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SubscriptionState"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::SubscriptionState(const unsigned short value)
	{
		SetOrAddField("SubscriptionState", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::SubscriptionStateExists() const
	{
		return ContainsField("SubscriptionState");
	}
	void CIM_AbstractIndicationSubscription::RemoveSubscriptionState()
	{
		RemoveField("SubscriptionState");
	}

	const string CIM_AbstractIndicationSubscription::OtherSubscriptionState() const
	{
		return GetField("OtherSubscriptionState")[0];
	}
	void CIM_AbstractIndicationSubscription::OtherSubscriptionState(const string &value)
	{
		SetOrAddField("OtherSubscriptionState", value);
	}
	bool CIM_AbstractIndicationSubscription::OtherSubscriptionStateExists() const
	{
		return ContainsField("OtherSubscriptionState");
	}
	void CIM_AbstractIndicationSubscription::RemoveOtherSubscriptionState()
	{
		RemoveField("OtherSubscriptionState");
	}

	const CimDateTime CIM_AbstractIndicationSubscription::TimeOfLastStateChange() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastStateChange"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::TimeOfLastStateChange(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastStateChange", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::TimeOfLastStateChangeExists() const
	{
		return ContainsField("TimeOfLastStateChange");
	}
	void CIM_AbstractIndicationSubscription::RemoveTimeOfLastStateChange()
	{
		RemoveField("TimeOfLastStateChange");
	}

	const Uint64 CIM_AbstractIndicationSubscription::SubscriptionDuration() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("SubscriptionDuration"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::SubscriptionDuration(const Uint64 value)
	{
		SetOrAddField("SubscriptionDuration", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::SubscriptionDurationExists() const
	{
		return ContainsField("SubscriptionDuration");
	}
	void CIM_AbstractIndicationSubscription::RemoveSubscriptionDuration()
	{
		RemoveField("SubscriptionDuration");
	}

	const CimDateTime CIM_AbstractIndicationSubscription::SubscriptionStartTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("SubscriptionStartTime"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::SubscriptionStartTime(const CimDateTime &value)
	{
		SetOrAddField("SubscriptionStartTime", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::SubscriptionStartTimeExists() const
	{
		return ContainsField("SubscriptionStartTime");
	}
	void CIM_AbstractIndicationSubscription::RemoveSubscriptionStartTime()
	{
		RemoveField("SubscriptionStartTime");
	}

	const Uint64 CIM_AbstractIndicationSubscription::SubscriptionTimeRemaining() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("SubscriptionTimeRemaining"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::SubscriptionTimeRemaining(const Uint64 value)
	{
		SetOrAddField("SubscriptionTimeRemaining", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::SubscriptionTimeRemainingExists() const
	{
		return ContainsField("SubscriptionTimeRemaining");
	}
	void CIM_AbstractIndicationSubscription::RemoveSubscriptionTimeRemaining()
	{
		RemoveField("SubscriptionTimeRemaining");
	}

	const unsigned short CIM_AbstractIndicationSubscription::RepeatNotificationPolicy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RepeatNotificationPolicy"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::RepeatNotificationPolicy(const unsigned short value)
	{
		SetOrAddField("RepeatNotificationPolicy", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::RepeatNotificationPolicyExists() const
	{
		return ContainsField("RepeatNotificationPolicy");
	}
	void CIM_AbstractIndicationSubscription::RemoveRepeatNotificationPolicy()
	{
		RemoveField("RepeatNotificationPolicy");
	}

	const string CIM_AbstractIndicationSubscription::OtherRepeatNotificationPolicy() const
	{
		return GetField("OtherRepeatNotificationPolicy")[0];
	}
	void CIM_AbstractIndicationSubscription::OtherRepeatNotificationPolicy(const string &value)
	{
		SetOrAddField("OtherRepeatNotificationPolicy", value);
	}
	bool CIM_AbstractIndicationSubscription::OtherRepeatNotificationPolicyExists() const
	{
		return ContainsField("OtherRepeatNotificationPolicy");
	}
	void CIM_AbstractIndicationSubscription::RemoveOtherRepeatNotificationPolicy()
	{
		RemoveField("OtherRepeatNotificationPolicy");
	}

	const Uint64 CIM_AbstractIndicationSubscription::RepeatNotificationInterval() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RepeatNotificationInterval"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::RepeatNotificationInterval(const Uint64 value)
	{
		SetOrAddField("RepeatNotificationInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::RepeatNotificationIntervalExists() const
	{
		return ContainsField("RepeatNotificationInterval");
	}
	void CIM_AbstractIndicationSubscription::RemoveRepeatNotificationInterval()
	{
		RemoveField("RepeatNotificationInterval");
	}

	const Uint64 CIM_AbstractIndicationSubscription::RepeatNotificationGap() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RepeatNotificationGap"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::RepeatNotificationGap(const Uint64 value)
	{
		SetOrAddField("RepeatNotificationGap", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::RepeatNotificationGapExists() const
	{
		return ContainsField("RepeatNotificationGap");
	}
	void CIM_AbstractIndicationSubscription::RemoveRepeatNotificationGap()
	{
		RemoveField("RepeatNotificationGap");
	}

	const unsigned short CIM_AbstractIndicationSubscription::RepeatNotificationCount() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RepeatNotificationCount"), ret);
		return ret;
	}
	void CIM_AbstractIndicationSubscription::RepeatNotificationCount(const unsigned short value)
	{
		SetOrAddField("RepeatNotificationCount", TypeConverter::TypeToString(value));
	}
	bool CIM_AbstractIndicationSubscription::RepeatNotificationCountExists() const
	{
		return ContainsField("RepeatNotificationCount");
	}
	void CIM_AbstractIndicationSubscription::RemoveRepeatNotificationCount()
	{
		RemoveField("RepeatNotificationCount");
	}

	const string CIM_AbstractIndicationSubscription::SubscriptionInfo() const
	{
		return GetField("SubscriptionInfo")[0];
	}
	void CIM_AbstractIndicationSubscription::SubscriptionInfo(const string &value)
	{
		SetOrAddField("SubscriptionInfo", value);
	}
	bool CIM_AbstractIndicationSubscription::SubscriptionInfoExists() const
	{
		return ContainsField("SubscriptionInfo");
	}
	void CIM_AbstractIndicationSubscription::RemoveSubscriptionInfo()
	{
		RemoveField("SubscriptionInfo");
	}

	CimBase *CIM_AbstractIndicationSubscription::CreateFromCimObject(const CimObject &object)
	{
		CIM_AbstractIndicationSubscription *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AbstractIndicationSubscription>(object);
		}
		else
		{
			ret = new CIM_AbstractIndicationSubscription(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AbstractIndicationSubscription> > CIM_AbstractIndicationSubscription::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AbstractIndicationSubscription>(client, keys);
	}

	void CIM_AbstractIndicationSubscription::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AbstractIndicationSubscription::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AbstractIndicationSubscription::CLASS_NAME = "CIM_AbstractIndicationSubscription";
	const string CIM_AbstractIndicationSubscription::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AbstractIndicationSubscription";
	const string CIM_AbstractIndicationSubscription::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AbstractIndicationSubscription";
	const string CIM_AbstractIndicationSubscription::CLASS_NS_PREFIX = "AAb29";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AbstractIndicationSubscription::_classMetaData;
}
}
}
}
