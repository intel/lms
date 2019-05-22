//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AlarmClockService.cpp
//
//  Contents:   AMT Alarm Clock Service derived from Service and provides the ability to set an alarm time to turn the host computer system on. Setting an alarm time is done by calling "AddAlarm" method."NextAMTAlarmTime" and "AMTAlarmClockInterval" properties are deprecated and "AddAlarm" should be used instead.
//
//              This file was automatically generated from AMT_AlarmClockService.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AlarmClockService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AlarmClockService::_metadata[] = {
		{"NextAMTAlarmTime", false, false, false },
		{"AMTAlarmClockInterval", false, false, false },
	};
	// class fields
	const CimDateTime AMT_AlarmClockService::NextAMTAlarmTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("NextAMTAlarmTime"), ret);
		return ret;
	}
	void AMT_AlarmClockService::NextAMTAlarmTime(const CimDateTime &value)
	{
		SetOrAddField("NextAMTAlarmTime", TypeConverter::TypeToString(value));
	}
	bool AMT_AlarmClockService::NextAMTAlarmTimeExists() const
	{
		return ContainsField("NextAMTAlarmTime");
	}
	void AMT_AlarmClockService::RemoveNextAMTAlarmTime()
	{
		RemoveField("NextAMTAlarmTime");
	}

	const CimDateTime AMT_AlarmClockService::AMTAlarmClockInterval() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("AMTAlarmClockInterval"), ret);
		return ret;
	}
	void AMT_AlarmClockService::AMTAlarmClockInterval(const CimDateTime &value)
	{
		SetOrAddField("AMTAlarmClockInterval", TypeConverter::TypeToString(value));
	}
	bool AMT_AlarmClockService::AMTAlarmClockIntervalExists() const
	{
		return ContainsField("AMTAlarmClockInterval");
	}
	void AMT_AlarmClockService::RemoveAMTAlarmClockInterval()
	{
		RemoveField("AMTAlarmClockInterval");
	}

	CimBase *AMT_AlarmClockService::CreateFromCimObject(const CimObject &object)
	{
		AMT_AlarmClockService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AlarmClockService>(object);
		}
		else
		{
			ret = new AMT_AlarmClockService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AlarmClockService> > AMT_AlarmClockService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AlarmClockService>(client, keys);
	}

	void AMT_AlarmClockService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AlarmClockService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_AlarmClockService::AddAlarm_INPUT::_metadata[] = {
		{"AlarmTemplate", false, true },
	};
	void AMT_AlarmClockService::AddAlarm_INPUT::AlarmTemplate(const IPS_AlarmClockOccurrence &value)
	{
		SetOrAddField("AlarmTemplate", TypedTypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AlarmClockService::AddAlarm_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const CimReference AMT_AlarmClockService::AddAlarm_OUTPUT::AlarmClock() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("AlarmClock"), ret);
		return ret;
	}
	bool AMT_AlarmClockService::AddAlarm_OUTPUT::AlarmClockExists() const
	{
		return ContainsField("AlarmClock");
	}
	unsigned int AMT_AlarmClockService::AddAlarm(const AddAlarm_INPUT &input, AddAlarm_OUTPUT &output)
	{
		return Invoke("AddAlarm", input, output);
	}
	const string AMT_AlarmClockService::CLASS_NAME = "AMT_AlarmClockService";
	const string AMT_AlarmClockService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AlarmClockService";
	const string AMT_AlarmClockService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AlarmClockService";
	const string AMT_AlarmClockService::CLASS_NS_PREFIX = "AAl1";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AlarmClockService::_classMetaData;
}
}
}
}
