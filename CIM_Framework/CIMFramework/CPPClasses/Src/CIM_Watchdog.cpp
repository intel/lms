//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Watchdog.cpp
//
//  Contents:   CIM_Watchdog is a timer that is implemented in the system hardware. It allows the hardware to monitor the state of the Operating System, BIOS, or a software component that is installed on the System. If the monitored component fails to re-arm the timer before its expiration, the hardware assumes that the System is in a critical state, and could reset the ComputerSystem. This feature can also be used as an application watchdog timer for a mission-critical application. In this case, the application would assume responsibility for re-arming the timer before expiration.
//
//              This file was automatically generated from CIM_Watchdog.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_Watchdog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Watchdog::_metadata[] = {
		{"MonitoredEntity", false, false, false },
		{"MonitoredEntityDescription", false, false, false },
		{"TimeoutInterval", false, false, false },
		{"TimerResolution", false, false, false },
		{"TimeOfLastExpiration", false, false, false },
		{"MonitoredEntityOnLastExpiration", false, false, false },
		{"ActionOnExpiration", false, false, false },
	};
	// class fields
	const unsigned short CIM_Watchdog::MonitoredEntity() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MonitoredEntity"), ret);
		return ret;
	}
	void CIM_Watchdog::MonitoredEntity(const unsigned short value)
	{
		SetOrAddField("MonitoredEntity", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::MonitoredEntityExists() const
	{
		return ContainsField("MonitoredEntity");
	}
	void CIM_Watchdog::RemoveMonitoredEntity()
	{
		RemoveField("MonitoredEntity");
	}

	const string CIM_Watchdog::MonitoredEntityDescription() const
	{
		return GetField("MonitoredEntityDescription")[0];
	}
	void CIM_Watchdog::MonitoredEntityDescription(const string &value)
	{
		SetOrAddField("MonitoredEntityDescription", value);
	}
	bool CIM_Watchdog::MonitoredEntityDescriptionExists() const
	{
		return ContainsField("MonitoredEntityDescription");
	}
	void CIM_Watchdog::RemoveMonitoredEntityDescription()
	{
		RemoveField("MonitoredEntityDescription");
	}

	const unsigned int CIM_Watchdog::TimeoutInterval() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TimeoutInterval"), ret);
		return ret;
	}
	void CIM_Watchdog::TimeoutInterval(const unsigned int value)
	{
		SetOrAddField("TimeoutInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::TimeoutIntervalExists() const
	{
		return ContainsField("TimeoutInterval");
	}
	void CIM_Watchdog::RemoveTimeoutInterval()
	{
		RemoveField("TimeoutInterval");
	}

	const unsigned int CIM_Watchdog::TimerResolution() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TimerResolution"), ret);
		return ret;
	}
	void CIM_Watchdog::TimerResolution(const unsigned int value)
	{
		SetOrAddField("TimerResolution", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::TimerResolutionExists() const
	{
		return ContainsField("TimerResolution");
	}
	void CIM_Watchdog::RemoveTimerResolution()
	{
		RemoveField("TimerResolution");
	}

	const CimDateTime CIM_Watchdog::TimeOfLastExpiration() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastExpiration"), ret);
		return ret;
	}
	void CIM_Watchdog::TimeOfLastExpiration(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastExpiration", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::TimeOfLastExpirationExists() const
	{
		return ContainsField("TimeOfLastExpiration");
	}
	void CIM_Watchdog::RemoveTimeOfLastExpiration()
	{
		RemoveField("TimeOfLastExpiration");
	}

	const unsigned short CIM_Watchdog::MonitoredEntityOnLastExpiration() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MonitoredEntityOnLastExpiration"), ret);
		return ret;
	}
	void CIM_Watchdog::MonitoredEntityOnLastExpiration(const unsigned short value)
	{
		SetOrAddField("MonitoredEntityOnLastExpiration", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::MonitoredEntityOnLastExpirationExists() const
	{
		return ContainsField("MonitoredEntityOnLastExpiration");
	}
	void CIM_Watchdog::RemoveMonitoredEntityOnLastExpiration()
	{
		RemoveField("MonitoredEntityOnLastExpiration");
	}

	const unsigned short CIM_Watchdog::ActionOnExpiration() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ActionOnExpiration"), ret);
		return ret;
	}
	void CIM_Watchdog::ActionOnExpiration(const unsigned short value)
	{
		SetOrAddField("ActionOnExpiration", TypeConverter::TypeToString(value));
	}
	bool CIM_Watchdog::ActionOnExpirationExists() const
	{
		return ContainsField("ActionOnExpiration");
	}
	void CIM_Watchdog::RemoveActionOnExpiration()
	{
		RemoveField("ActionOnExpiration");
	}

	CimBase *CIM_Watchdog::CreateFromCimObject(const CimObject &object)
	{
		CIM_Watchdog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Watchdog>(object);
		}
		else
		{
			ret = new CIM_Watchdog(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Watchdog> > CIM_Watchdog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Watchdog>(client, keys);
	}

	void CIM_Watchdog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Watchdog::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Watchdog::CLASS_NAME = "CIM_Watchdog";
	const string CIM_Watchdog::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Watchdog";
	const string CIM_Watchdog::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Watchdog";
	const string CIM_Watchdog::CLASS_NS_PREFIX = "AWa37";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Watchdog::_classMetaData;
}
}
}
}
