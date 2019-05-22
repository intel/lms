//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Sensor.cpp
//
//  Contents:   A Sensor is an entity capable of measuring or reporting the characteristics of some physical property - for example, the temperature or voltage characteristics of a Computer System.
//
//              This file was automatically generated from CIM_Sensor.mof,  version: 2.32.0
//
//----------------------------------------------------------------------------
#include "CIM_Sensor.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Sensor::_metadata[] = {
		{"SensorType", false, false, false },
		{"OtherSensorTypeDescription", false, false, false },
		{"PossibleStates", false, false, false },
		{"CurrentState", false, false, false },
		{"PollingInterval", false, false, false },
		{"SensorContext", false, false, false },
	};
	// class fields
	const unsigned short CIM_Sensor::SensorType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SensorType"), ret);
		return ret;
	}
	void CIM_Sensor::SensorType(const unsigned short value)
	{
		SetOrAddField("SensorType", TypeConverter::TypeToString(value));
	}
	bool CIM_Sensor::SensorTypeExists() const
	{
		return ContainsField("SensorType");
	}
	void CIM_Sensor::RemoveSensorType()
	{
		RemoveField("SensorType");
	}

	const string CIM_Sensor::OtherSensorTypeDescription() const
	{
		return GetField("OtherSensorTypeDescription")[0];
	}
	void CIM_Sensor::OtherSensorTypeDescription(const string &value)
	{
		SetOrAddField("OtherSensorTypeDescription", value);
	}
	bool CIM_Sensor::OtherSensorTypeDescriptionExists() const
	{
		return ContainsField("OtherSensorTypeDescription");
	}
	void CIM_Sensor::RemoveOtherSensorTypeDescription()
	{
		RemoveField("OtherSensorTypeDescription");
	}

	const vector<string> CIM_Sensor::PossibleStates() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("PossibleStates"), ret);
		return ret;
	}
	void CIM_Sensor::PossibleStates(const vector<string> &value)
	{
		SetOrAddField("PossibleStates", TypeConverter::TypeToString(value));
	}
	bool CIM_Sensor::PossibleStatesExists() const
	{
		return ContainsField("PossibleStates");
	}
	void CIM_Sensor::RemovePossibleStates()
	{
		RemoveField("PossibleStates");
	}

	const string CIM_Sensor::CurrentState() const
	{
		return GetField("CurrentState")[0];
	}
	void CIM_Sensor::CurrentState(const string &value)
	{
		SetOrAddField("CurrentState", value);
	}
	bool CIM_Sensor::CurrentStateExists() const
	{
		return ContainsField("CurrentState");
	}
	void CIM_Sensor::RemoveCurrentState()
	{
		RemoveField("CurrentState");
	}

	const Uint64 CIM_Sensor::PollingInterval() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("PollingInterval"), ret);
		return ret;
	}
	void CIM_Sensor::PollingInterval(const Uint64 value)
	{
		SetOrAddField("PollingInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_Sensor::PollingIntervalExists() const
	{
		return ContainsField("PollingInterval");
	}
	void CIM_Sensor::RemovePollingInterval()
	{
		RemoveField("PollingInterval");
	}

	const string CIM_Sensor::SensorContext() const
	{
		return GetField("SensorContext")[0];
	}
	void CIM_Sensor::SensorContext(const string &value)
	{
		SetOrAddField("SensorContext", value);
	}
	bool CIM_Sensor::SensorContextExists() const
	{
		return ContainsField("SensorContext");
	}
	void CIM_Sensor::RemoveSensorContext()
	{
		RemoveField("SensorContext");
	}

	CimBase *CIM_Sensor::CreateFromCimObject(const CimObject &object)
	{
		CIM_Sensor *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Sensor>(object);
		}
		else
		{
			ret = new CIM_Sensor(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Sensor> > CIM_Sensor::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Sensor>(client, keys);
	}

	void CIM_Sensor::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Sensor::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Sensor::CLASS_NAME = "CIM_Sensor";
	const string CIM_Sensor::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Sensor";
	const string CIM_Sensor::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Sensor";
	const string CIM_Sensor::CLASS_NS_PREFIX = "ASe238";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Sensor::_classMetaData;
}
}
}
}
