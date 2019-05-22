//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EventLogEntry.h
//
//  Contents:   The LogRecord object can describe the definitional format for entries in a MessageLog, or can be used to instantiate the actual records in the Log. The latter approach provides a great deal more semantic definition and management control over the individual entries in a MessageLog, than do the record manipulation methods of the Log class. It is recommended that the data in individual Log entries be modeled using subclasses of LogRecord, to avoid the creation of LogRecords with one property (such as RecordData) without semantics. Definitional formats for LogRecords could be specified by establishing a naming convention for the RecordID and Message Timestamp key properties.
//
//              This file was automatically generated from AMT_EventLogEntry.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_EVENTLOGENTRY_H
#define AMT_EVENTLOGENTRY_H 1
#include "CIM_LogEntry.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The LogRecord object can describe the definitional format for entries in a MessageLog, or can be used to instantiate the actual records in the Log. The latter approach provides a great deal more semantic definition and management control over the individual entries in a MessageLog, than do the record manipulation methods of the Log class. It is recommended that the data in individual Log entries be modeled using subclasses of LogRecord, to avoid the creation of LogRecords with one property (such as RecordData) without semantics. Definitional formats for LogRecords could be specified by establishing a naming convention for the RecordID and Message Timestamp key properties.
	class CIMFRAMEWORK_API AMT_EventLogEntry  : public CIM_LogEntry
	{
	public:

		//Default constructor
		AMT_EventLogEntry()
			: CIM_LogEntry(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		AMT_EventLogEntry(ICimWsmanClient *client)
			: CIM_LogEntry(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~AMT_EventLogEntry(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_EventLogEntry keys
		class CimKeys : public CIM_LogEntry::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The SMBus address of the physical sensor device that implements the logical sensor.
		const unsigned char DeviceAddress() const;

		// Optional, The SMBus address of the physical sensor device that implements the logical sensor.
		void DeviceAddress(const unsigned char &value); 

		// Is true if the field DeviceAddress exists in the current object, otherwise is false.
		bool DeviceAddressExists() const;

		// Remove DeviceAddress field.
		void RemoveDeviceAddress(); 

		// Optional, The value to be set into the alert's Event Sensor Type field (see [PET] for definitions.)
		const unsigned char EventSensorType() const;

		// Optional, The value to be set into the alert's Event Sensor Type field (see [PET] for definitions.)
		void EventSensorType(const unsigned char &value); 

		// Is true if the field EventSensorType exists in the current object, otherwise is false.
		bool EventSensorTypeExists() const;

		// Remove EventSensorType field.
		void RemoveEventSensorType(); 

		// Optional, The value to be set into the alert's Event Type field (see [PET] for definitions.)
		const unsigned char EventType() const;

		// Optional, The value to be set into the alert's Event Type field (see [PET] for definitions.)
		void EventType(const unsigned char &value); 

		// Is true if the field EventType exists in the current object, otherwise is false.
		bool EventTypeExists() const;

		// Remove EventType field.
		void RemoveEventType(); 

		// Optional, The value to be set into the alert's Event Offset field (see [PET] for definitions.)
		const unsigned char EventOffset() const;

		// Optional, The value to be set into the alert's Event Offset field (see [PET] for definitions.)
		void EventOffset(const unsigned char &value); 

		// Is true if the field EventOffset exists in the current object, otherwise is false.
		bool EventOffsetExists() const;

		// Remove EventOffset field.
		void RemoveEventOffset(); 

		// Optional, The value to be set into the alert's Event Source Type field (see [PET] for definitions.)
		const unsigned char EventSourceType() const;

		// Optional, The value to be set into the alert's Event Source Type field (see [PET] for definitions.)
		void EventSourceType(const unsigned char &value); 

		// Is true if the field EventSourceType exists in the current object, otherwise is false.
		bool EventSourceTypeExists() const;

		// Remove EventSourceType field.
		void RemoveEventSourceType(); 

		// Optional, This field can be used to fill in the Event Severity field in a PET alert. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		const unsigned char EventSeverity() const;

		// Optional, This field can be used to fill in the Event Severity field in a PET alert. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		void EventSeverity(const unsigned char &value); 

		// Is true if the field EventSeverity exists in the current object, otherwise is false.
		bool EventSeverityExists() const;

		// Remove EventSeverity field.
		void RemoveEventSeverity(); 

		// Optional, The value to be set into the alert's Sensor Number field (see [PET] for definitions.)
		const unsigned char SensorNumber() const;

		// Optional, The value to be set into the alert's Sensor Number field (see [PET] for definitions.)
		void SensorNumber(const unsigned char &value); 

		// Is true if the field SensorNumber exists in the current object, otherwise is false.
		bool SensorNumberExists() const;

		// Remove SensorNumber field.
		void RemoveSensorNumber(); 

		// Optional, The value to be set into the alert's Entity field (see [PET] for definitions.)
		const unsigned char Entity() const;

		// Optional, The value to be set into the alert's Entity field (see [PET] for definitions.)
		void Entity(const unsigned char &value); 

		// Is true if the field Entity exists in the current object, otherwise is false.
		bool EntityExists() const;

		// Remove Entity field.
		void RemoveEntity(); 

		// Optional, The value to be set into the alert's Entity Instance field (see [PET] for definitions.)
		const unsigned char EntityInstance() const;

		// Optional, The value to be set into the alert's Entity Instance field (see [PET] for definitions.)
		void EntityInstance(const unsigned char &value); 

		// Is true if the field EntityInstance exists in the current object, otherwise is false.
		bool EntityInstanceExists() const;

		// Remove EntityInstance field.
		void RemoveEntityInstance(); 

		// Optional, Describes optional event data sent in the PET packet. The values are defined in the ASF specification [ASF].
		const vector<unsigned char> EventData() const;

		// Optional, Describes optional event data sent in the PET packet. The values are defined in the ASF specification [ASF].
		void EventData(const vector<unsigned char> &value); 

		// Is true if the field EventData exists in the current object, otherwise is false.
		bool EventDataExists() const;

		// Remove EventData field.
		void RemoveEventData(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_EventLogEntry> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_EventLogEntry(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogEntry(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_EventLogEntry(const CimObject &object)
			: CIM_LogEntry(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogEntry::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
		static const CimFieldAttribute _metadata[];
		static const string CLASS_NAME;
		static const string CLASS_URI;
		static const string CLASS_NS;
		static const string CLASS_NS_PREFIX;
		static vector<CimFieldAttribute> _classMetaData;
	};

} // close namespace Typed
} // close namespace Cim
} // close namespace Manageability
} // close namespace Intel
#endif // AMT_EVENTLOGENTRY_H
