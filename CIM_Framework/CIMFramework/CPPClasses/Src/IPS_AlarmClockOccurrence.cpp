//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_AlarmClockOccurrence.cpp
//
//  Contents:   IPS_AlarmClockOccurrence represents a single alarm clock setting. An instance of this class is created by calling AMT_AlarmClockService.AddAlarm method.
//
//              This file was automatically generated from IPS_AlarmClockOccurrence.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_AlarmClockOccurrence.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_AlarmClockOccurrence::_metadata[] = {
		{"InstanceID", true, false, false },
		{"StartTime", false, false, false },
		{"Interval", false, false, false },
		{"DeleteOnCompletion", false, false, false },
	};
	// class fields
	const string IPS_AlarmClockOccurrence::InstanceID() const
	{
		return GetField("InstanceID")[0];
	}
	void IPS_AlarmClockOccurrence::InstanceID(const string &value)
	{
		SetOrAddField("InstanceID", value);
	}

	const CimDateTime IPS_AlarmClockOccurrence::StartTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("StartTime"), ret);
		return ret;
	}
	void IPS_AlarmClockOccurrence::StartTime(const CimDateTime &value)
	{
		SetOrAddField("StartTime", TypeConverter::TypeToString(value));
	}
	bool IPS_AlarmClockOccurrence::StartTimeExists() const
	{
		return ContainsField("StartTime");
	}
	void IPS_AlarmClockOccurrence::RemoveStartTime()
	{
		RemoveField("StartTime");
	}

	const CimDateTime IPS_AlarmClockOccurrence::Interval() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("Interval"), ret);
		return ret;
	}
	void IPS_AlarmClockOccurrence::Interval(const CimDateTime &value)
	{
		SetOrAddField("Interval", TypeConverter::TypeToString(value));
	}
	bool IPS_AlarmClockOccurrence::IntervalExists() const
	{
		return ContainsField("Interval");
	}
	void IPS_AlarmClockOccurrence::RemoveInterval()
	{
		RemoveField("Interval");
	}

	const bool IPS_AlarmClockOccurrence::DeleteOnCompletion() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DeleteOnCompletion"), ret);
		return ret;
	}
	void IPS_AlarmClockOccurrence::DeleteOnCompletion(const bool value)
	{
		SetOrAddField("DeleteOnCompletion", TypeConverter::TypeToString(value));
	}
	bool IPS_AlarmClockOccurrence::DeleteOnCompletionExists() const
	{
		return ContainsField("DeleteOnCompletion");
	}
	void IPS_AlarmClockOccurrence::RemoveDeleteOnCompletion()
	{
		RemoveField("DeleteOnCompletion");
	}

	CimBase *IPS_AlarmClockOccurrence::CreateFromCimObject(const CimObject &object)
	{
		IPS_AlarmClockOccurrence *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_AlarmClockOccurrence>(object);
		}
		else
		{
			ret = new IPS_AlarmClockOccurrence(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_AlarmClockOccurrence> > IPS_AlarmClockOccurrence::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_AlarmClockOccurrence>(client, keys);
	}

	void IPS_AlarmClockOccurrence::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_AlarmClockOccurrence::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_AlarmClockOccurrence::CLASS_NAME = "IPS_AlarmClockOccurrence";
	const string IPS_AlarmClockOccurrence::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_AlarmClockOccurrence";
	const string IPS_AlarmClockOccurrence::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_AlarmClockOccurrence";
	const string IPS_AlarmClockOccurrence::CLASS_NS_PREFIX = "AAl159";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_AlarmClockOccurrence::_classMetaData;
}
}
}
}
