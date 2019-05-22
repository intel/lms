//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PETFilterSetting.cpp
//
//  Contents:   This class represents a PET filter in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_PETFilterSetting.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PETFilterSetting.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PETFilterSetting::_metadata[] = {
		{"EnableFilter", false, true, false },
		{"OEMFilter", false, true, false },
		{"LogOnEvent", false, true, false },
		{"DeviceAddress", false, true, false },
		{"EventSensorType", false, true, false },
		{"EventType", false, true, false },
		{"EventOffset", false, true, false },
		{"EventSourceType", false, true, false },
		{"EventSeverity", false, true, false },
		{"SensorNumber", false, true, false },
		{"Entity", false, true, false },
		{"EntityInstance", false, true, false },
		{"PolicyID", false, true, false },
		{"SendAlert", false, true, false },
	};
	// class fields
	const bool AMT_PETFilterSetting::EnableFilter() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("EnableFilter"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EnableFilter(const bool value)
	{
		SetOrAddField("EnableFilter", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EnableFilterExists() const
	{
		return ContainsField("EnableFilter");
	}
	void AMT_PETFilterSetting::RemoveEnableFilter()
	{
		RemoveField("EnableFilter");
	}

	const bool AMT_PETFilterSetting::OEMFilter() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("OEMFilter"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::OEMFilter(const bool value)
	{
		SetOrAddField("OEMFilter", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::OEMFilterExists() const
	{
		return ContainsField("OEMFilter");
	}
	void AMT_PETFilterSetting::RemoveOEMFilter()
	{
		RemoveField("OEMFilter");
	}

	const bool AMT_PETFilterSetting::LogOnEvent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LogOnEvent"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::LogOnEvent(const bool value)
	{
		SetOrAddField("LogOnEvent", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::LogOnEventExists() const
	{
		return ContainsField("LogOnEvent");
	}
	void AMT_PETFilterSetting::RemoveLogOnEvent()
	{
		RemoveField("LogOnEvent");
	}

	const unsigned char AMT_PETFilterSetting::DeviceAddress() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DeviceAddress"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::DeviceAddress(const unsigned char &value)
	{
		SetOrAddField("DeviceAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::DeviceAddressExists() const
	{
		return ContainsField("DeviceAddress");
	}
	void AMT_PETFilterSetting::RemoveDeviceAddress()
	{
		RemoveField("DeviceAddress");
	}

	const unsigned char AMT_PETFilterSetting::EventSensorType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSensorType"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EventSensorType(const unsigned char &value)
	{
		SetOrAddField("EventSensorType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EventSensorTypeExists() const
	{
		return ContainsField("EventSensorType");
	}
	void AMT_PETFilterSetting::RemoveEventSensorType()
	{
		RemoveField("EventSensorType");
	}

	const unsigned char AMT_PETFilterSetting::EventType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventType"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EventType(const unsigned char &value)
	{
		SetOrAddField("EventType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EventTypeExists() const
	{
		return ContainsField("EventType");
	}
	void AMT_PETFilterSetting::RemoveEventType()
	{
		RemoveField("EventType");
	}

	const unsigned char AMT_PETFilterSetting::EventOffset() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventOffset"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EventOffset(const unsigned char &value)
	{
		SetOrAddField("EventOffset", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EventOffsetExists() const
	{
		return ContainsField("EventOffset");
	}
	void AMT_PETFilterSetting::RemoveEventOffset()
	{
		RemoveField("EventOffset");
	}

	const unsigned char AMT_PETFilterSetting::EventSourceType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSourceType"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EventSourceType(const unsigned char &value)
	{
		SetOrAddField("EventSourceType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EventSourceTypeExists() const
	{
		return ContainsField("EventSourceType");
	}
	void AMT_PETFilterSetting::RemoveEventSourceType()
	{
		RemoveField("EventSourceType");
	}

	const unsigned char AMT_PETFilterSetting::EventSeverity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSeverity"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EventSeverity(const unsigned char &value)
	{
		SetOrAddField("EventSeverity", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EventSeverityExists() const
	{
		return ContainsField("EventSeverity");
	}
	void AMT_PETFilterSetting::RemoveEventSeverity()
	{
		RemoveField("EventSeverity");
	}

	const unsigned char AMT_PETFilterSetting::SensorNumber() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SensorNumber"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::SensorNumber(const unsigned char &value)
	{
		SetOrAddField("SensorNumber", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::SensorNumberExists() const
	{
		return ContainsField("SensorNumber");
	}
	void AMT_PETFilterSetting::RemoveSensorNumber()
	{
		RemoveField("SensorNumber");
	}

	const unsigned char AMT_PETFilterSetting::Entity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Entity"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::Entity(const unsigned char &value)
	{
		SetOrAddField("Entity", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EntityExists() const
	{
		return ContainsField("Entity");
	}
	void AMT_PETFilterSetting::RemoveEntity()
	{
		RemoveField("Entity");
	}

	const unsigned char AMT_PETFilterSetting::EntityInstance() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EntityInstance"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::EntityInstance(const unsigned char &value)
	{
		SetOrAddField("EntityInstance", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::EntityInstanceExists() const
	{
		return ContainsField("EntityInstance");
	}
	void AMT_PETFilterSetting::RemoveEntityInstance()
	{
		RemoveField("EntityInstance");
	}

	const unsigned char AMT_PETFilterSetting::PolicyID() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("PolicyID"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::PolicyID(const unsigned char &value)
	{
		SetOrAddField("PolicyID", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::PolicyIDExists() const
	{
		return ContainsField("PolicyID");
	}
	void AMT_PETFilterSetting::RemovePolicyID()
	{
		RemoveField("PolicyID");
	}

	const bool AMT_PETFilterSetting::SendAlert() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SendAlert"), ret);
		return ret;
	}
	void AMT_PETFilterSetting::SendAlert(const bool value)
	{
		SetOrAddField("SendAlert", TypeConverter::TypeToString(value));
	}
	bool AMT_PETFilterSetting::SendAlertExists() const
	{
		return ContainsField("SendAlert");
	}
	void AMT_PETFilterSetting::RemoveSendAlert()
	{
		RemoveField("SendAlert");
	}

	CimBase *AMT_PETFilterSetting::CreateFromCimObject(const CimObject &object)
	{
		AMT_PETFilterSetting *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PETFilterSetting>(object);
		}
		else
		{
			ret = new AMT_PETFilterSetting(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PETFilterSetting> > AMT_PETFilterSetting::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PETFilterSetting>(client, keys);
	}

	void AMT_PETFilterSetting::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PETFilterSetting::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PETFilterSetting::CLASS_NAME = "AMT_PETFilterSetting";
	const string AMT_PETFilterSetting::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETFilterSetting";
	const string AMT_PETFilterSetting::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETFilterSetting";
	const string AMT_PETFilterSetting::CLASS_NS_PREFIX = "APE448";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PETFilterSetting::_classMetaData;
}
}
}
}
