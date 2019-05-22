//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PETCapabilities.cpp
//
//  Contents:   describes the attributes associated with a single logical sensor which can cause to event alerting. The logical model classifies sensors according to type regardless of the physical devices that implement them. Thus, a single physical sensor device can implement logical sensors of different types, such as temperature and voltage sensors.
//
//              This file was automatically generated from AMT_PETCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PETCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PETCapabilities::_metadata[] = {
		{"IsLegacySensor", false, false, false },
		{"Index", false, false, false },
		{"DeviceAddress", false, false, false },
		{"AssertionEvent", false, false, false },
		{"DeassertionEvent", false, false, false },
		{"EventSensorType", false, false, false },
		{"EventType", false, false, false },
		{"EventOffset", false, false, false },
		{"EventSourceType", false, false, false },
		{"EventSeverity", false, false, false },
		{"SensorNumber", false, false, false },
		{"Entity", false, false, false },
		{"EntityInstance", false, false, false },
	};
	// class fields
	const bool AMT_PETCapabilities::IsLegacySensor() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsLegacySensor"), ret);
		return ret;
	}
	void AMT_PETCapabilities::IsLegacySensor(const bool value)
	{
		SetOrAddField("IsLegacySensor", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::IsLegacySensorExists() const
	{
		return ContainsField("IsLegacySensor");
	}
	void AMT_PETCapabilities::RemoveIsLegacySensor()
	{
		RemoveField("IsLegacySensor");
	}

	const unsigned char AMT_PETCapabilities::Index() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Index"), ret);
		return ret;
	}
	void AMT_PETCapabilities::Index(const unsigned char &value)
	{
		SetOrAddField("Index", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::IndexExists() const
	{
		return ContainsField("Index");
	}
	void AMT_PETCapabilities::RemoveIndex()
	{
		RemoveField("Index");
	}

	const unsigned char AMT_PETCapabilities::DeviceAddress() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DeviceAddress"), ret);
		return ret;
	}
	void AMT_PETCapabilities::DeviceAddress(const unsigned char &value)
	{
		SetOrAddField("DeviceAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::DeviceAddressExists() const
	{
		return ContainsField("DeviceAddress");
	}
	void AMT_PETCapabilities::RemoveDeviceAddress()
	{
		RemoveField("DeviceAddress");
	}

	const bool AMT_PETCapabilities::AssertionEvent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AssertionEvent"), ret);
		return ret;
	}
	void AMT_PETCapabilities::AssertionEvent(const bool value)
	{
		SetOrAddField("AssertionEvent", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::AssertionEventExists() const
	{
		return ContainsField("AssertionEvent");
	}
	void AMT_PETCapabilities::RemoveAssertionEvent()
	{
		RemoveField("AssertionEvent");
	}

	const bool AMT_PETCapabilities::DeassertionEvent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DeassertionEvent"), ret);
		return ret;
	}
	void AMT_PETCapabilities::DeassertionEvent(const bool value)
	{
		SetOrAddField("DeassertionEvent", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::DeassertionEventExists() const
	{
		return ContainsField("DeassertionEvent");
	}
	void AMT_PETCapabilities::RemoveDeassertionEvent()
	{
		RemoveField("DeassertionEvent");
	}

	const unsigned char AMT_PETCapabilities::EventSensorType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSensorType"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EventSensorType(const unsigned char &value)
	{
		SetOrAddField("EventSensorType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EventSensorTypeExists() const
	{
		return ContainsField("EventSensorType");
	}
	void AMT_PETCapabilities::RemoveEventSensorType()
	{
		RemoveField("EventSensorType");
	}

	const unsigned char AMT_PETCapabilities::EventType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventType"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EventType(const unsigned char &value)
	{
		SetOrAddField("EventType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EventTypeExists() const
	{
		return ContainsField("EventType");
	}
	void AMT_PETCapabilities::RemoveEventType()
	{
		RemoveField("EventType");
	}

	const unsigned char AMT_PETCapabilities::EventOffset() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventOffset"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EventOffset(const unsigned char &value)
	{
		SetOrAddField("EventOffset", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EventOffsetExists() const
	{
		return ContainsField("EventOffset");
	}
	void AMT_PETCapabilities::RemoveEventOffset()
	{
		RemoveField("EventOffset");
	}

	const unsigned char AMT_PETCapabilities::EventSourceType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSourceType"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EventSourceType(const unsigned char &value)
	{
		SetOrAddField("EventSourceType", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EventSourceTypeExists() const
	{
		return ContainsField("EventSourceType");
	}
	void AMT_PETCapabilities::RemoveEventSourceType()
	{
		RemoveField("EventSourceType");
	}

	const unsigned char AMT_PETCapabilities::EventSeverity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSeverity"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EventSeverity(const unsigned char &value)
	{
		SetOrAddField("EventSeverity", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EventSeverityExists() const
	{
		return ContainsField("EventSeverity");
	}
	void AMT_PETCapabilities::RemoveEventSeverity()
	{
		RemoveField("EventSeverity");
	}

	const unsigned char AMT_PETCapabilities::SensorNumber() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SensorNumber"), ret);
		return ret;
	}
	void AMT_PETCapabilities::SensorNumber(const unsigned char &value)
	{
		SetOrAddField("SensorNumber", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::SensorNumberExists() const
	{
		return ContainsField("SensorNumber");
	}
	void AMT_PETCapabilities::RemoveSensorNumber()
	{
		RemoveField("SensorNumber");
	}

	const unsigned char AMT_PETCapabilities::Entity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Entity"), ret);
		return ret;
	}
	void AMT_PETCapabilities::Entity(const unsigned char &value)
	{
		SetOrAddField("Entity", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EntityExists() const
	{
		return ContainsField("Entity");
	}
	void AMT_PETCapabilities::RemoveEntity()
	{
		RemoveField("Entity");
	}

	const unsigned char AMT_PETCapabilities::EntityInstance() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EntityInstance"), ret);
		return ret;
	}
	void AMT_PETCapabilities::EntityInstance(const unsigned char &value)
	{
		SetOrAddField("EntityInstance", TypeConverter::TypeToString(value));
	}
	bool AMT_PETCapabilities::EntityInstanceExists() const
	{
		return ContainsField("EntityInstance");
	}
	void AMT_PETCapabilities::RemoveEntityInstance()
	{
		RemoveField("EntityInstance");
	}

	CimBase *AMT_PETCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_PETCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PETCapabilities>(object);
		}
		else
		{
			ret = new AMT_PETCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PETCapabilities> > AMT_PETCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PETCapabilities>(client, keys);
	}

	void AMT_PETCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PETCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PETCapabilities::CLASS_NAME = "AMT_PETCapabilities";
	const string AMT_PETCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETCapabilities";
	const string AMT_PETCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETCapabilities";
	const string AMT_PETCapabilities::CLASS_NS_PREFIX = "APE182";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PETCapabilities::_classMetaData;
}
}
}
}
