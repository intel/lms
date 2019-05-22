//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EventLogEntry.cpp
//
//  Contents:   The LogRecord object can describe the definitional format for entries in a MessageLog, or can be used to instantiate the actual records in the Log. The latter approach provides a great deal more semantic definition and management control over the individual entries in a MessageLog, than do the record manipulation methods of the Log class. It is recommended that the data in individual Log entries be modeled using subclasses of LogRecord, to avoid the creation of LogRecords with one property (such as RecordData) without semantics. Definitional formats for LogRecords could be specified by establishing a naming convention for the RecordID and Message Timestamp key properties.
//
//              This file was automatically generated from AMT_EventLogEntry.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EventLogEntry.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EventLogEntry::_metadata[] = {
		{"DeviceAddress", false, false, false },
		{"EventSensorType", false, false, false },
		{"EventType", false, false, false },
		{"EventOffset", false, false, false },
		{"EventSourceType", false, false, false },
		{"EventSeverity", false, false, false },
		{"SensorNumber", false, false, false },
		{"Entity", false, false, false },
		{"EntityInstance", false, false, false },
		{"EventData", false, false, false },
	};
	// class fields
	const unsigned char AMT_EventLogEntry::DeviceAddress() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DeviceAddress"), ret);
		return ret;
	}
	void AMT_EventLogEntry::DeviceAddress(const unsigned char &value)
	{
		SetOrAddField("DeviceAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::DeviceAddressExists() const
	{
		return ContainsField("DeviceAddress");
	}
	void AMT_EventLogEntry::RemoveDeviceAddress()
	{
		RemoveField("DeviceAddress");
	}

	const unsigned char AMT_EventLogEntry::EventSensorType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSensorType"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventSensorType(const unsigned char &value)
	{
		SetOrAddField("EventSensorType", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventSensorTypeExists() const
	{
		return ContainsField("EventSensorType");
	}
	void AMT_EventLogEntry::RemoveEventSensorType()
	{
		RemoveField("EventSensorType");
	}

	const unsigned char AMT_EventLogEntry::EventType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventType"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventType(const unsigned char &value)
	{
		SetOrAddField("EventType", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventTypeExists() const
	{
		return ContainsField("EventType");
	}
	void AMT_EventLogEntry::RemoveEventType()
	{
		RemoveField("EventType");
	}

	const unsigned char AMT_EventLogEntry::EventOffset() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventOffset"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventOffset(const unsigned char &value)
	{
		SetOrAddField("EventOffset", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventOffsetExists() const
	{
		return ContainsField("EventOffset");
	}
	void AMT_EventLogEntry::RemoveEventOffset()
	{
		RemoveField("EventOffset");
	}

	const unsigned char AMT_EventLogEntry::EventSourceType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSourceType"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventSourceType(const unsigned char &value)
	{
		SetOrAddField("EventSourceType", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventSourceTypeExists() const
	{
		return ContainsField("EventSourceType");
	}
	void AMT_EventLogEntry::RemoveEventSourceType()
	{
		RemoveField("EventSourceType");
	}

	const unsigned char AMT_EventLogEntry::EventSeverity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EventSeverity"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventSeverity(const unsigned char &value)
	{
		SetOrAddField("EventSeverity", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventSeverityExists() const
	{
		return ContainsField("EventSeverity");
	}
	void AMT_EventLogEntry::RemoveEventSeverity()
	{
		RemoveField("EventSeverity");
	}

	const unsigned char AMT_EventLogEntry::SensorNumber() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SensorNumber"), ret);
		return ret;
	}
	void AMT_EventLogEntry::SensorNumber(const unsigned char &value)
	{
		SetOrAddField("SensorNumber", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::SensorNumberExists() const
	{
		return ContainsField("SensorNumber");
	}
	void AMT_EventLogEntry::RemoveSensorNumber()
	{
		RemoveField("SensorNumber");
	}

	const unsigned char AMT_EventLogEntry::Entity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Entity"), ret);
		return ret;
	}
	void AMT_EventLogEntry::Entity(const unsigned char &value)
	{
		SetOrAddField("Entity", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EntityExists() const
	{
		return ContainsField("Entity");
	}
	void AMT_EventLogEntry::RemoveEntity()
	{
		RemoveField("Entity");
	}

	const unsigned char AMT_EventLogEntry::EntityInstance() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EntityInstance"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EntityInstance(const unsigned char &value)
	{
		SetOrAddField("EntityInstance", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EntityInstanceExists() const
	{
		return ContainsField("EntityInstance");
	}
	void AMT_EventLogEntry::RemoveEntityInstance()
	{
		RemoveField("EntityInstance");
	}

	const vector<unsigned char> AMT_EventLogEntry::EventData() const
	{
		vector<unsigned char> ret;
		TypeConverter::StringToType(GetField("EventData"), ret);
		return ret;
	}
	void AMT_EventLogEntry::EventData(const vector<unsigned char> &value)
	{
		SetOrAddField("EventData", TypeConverter::TypeToString(value));
	}
	bool AMT_EventLogEntry::EventDataExists() const
	{
		return ContainsField("EventData");
	}
	void AMT_EventLogEntry::RemoveEventData()
	{
		RemoveField("EventData");
	}

	CimBase *AMT_EventLogEntry::CreateFromCimObject(const CimObject &object)
	{
		AMT_EventLogEntry *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EventLogEntry>(object);
		}
		else
		{
			ret = new AMT_EventLogEntry(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EventLogEntry> > AMT_EventLogEntry::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EventLogEntry>(client, keys);
	}

	void AMT_EventLogEntry::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EventLogEntry::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_EventLogEntry::CLASS_NAME = "AMT_EventLogEntry";
	const string AMT_EventLogEntry::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventLogEntry";
	const string AMT_EventLogEntry::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventLogEntry";
	const string AMT_EventLogEntry::CLASS_NS_PREFIX = "AEv359";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EventLogEntry::_classMetaData;
}
}
}
}
