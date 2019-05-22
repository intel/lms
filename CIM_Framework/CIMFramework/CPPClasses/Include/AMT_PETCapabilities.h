//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PETCapabilities.h
//
//  Contents:   describes the attributes associated with a single logical sensor which can cause to event alerting. The logical model classifies sensors according to type regardless of the physical devices that implement them. Thus, a single physical sensor device can implement logical sensors of different types, such as temperature and voltage sensors.
//
//              This file was automatically generated from AMT_PETCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PETCAPABILITIES_H
#define AMT_PETCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// describes the attributes associated with a single logical sensor which can cause to event alerting. The logical model classifies sensors according to type regardless of the physical devices that implement them. Thus, a single physical sensor device can implement logical sensors of different types, such as temperature and voltage sensors.
	class CIMFRAMEWORK_API AMT_PETCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_PETCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}

		//constructor which receives WSMan client
		AMT_PETCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}

		//Destructor
		virtual ~AMT_PETCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PETCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The value in this field is TRUE if this is a legacy sensor described in the ACPI 'ASF!' table or FALSE if this is an ASF sensor. The value in this field is used in determining how to poll the status of the device on the SMBus.Supported for backwards compatibility.
		const bool IsLegacySensor() const;

		// Optional, The value in this field is TRUE if this is a legacy sensor described in the ACPI 'ASF!' table or FALSE if this is an ASF sensor. The value in this field is used in determining how to poll the status of the device on the SMBus.Supported for backwards compatibility.
		void IsLegacySensor(const bool value); 

		// Is true if the field IsLegacySensor exists in the current object, otherwise is false.
		bool IsLegacySensorExists() const;

		// Remove IsLegacySensor field.
		void RemoveIsLegacySensor(); 

		// Optional, If this is a legacy sensor, then this field contains the 0-based index of the ASF_ALERTDATA structure in the Device Array of the ASF_ALRT structure in the ACPI 'ASF!' structure. If this is an ASF sensor, then this field contains the value of the Event Status Index required for a Get Event Status cycle on the SMBus. The value in this field is used in determining how to poll the status of the device on the SMBus. Supported for backwards compatibility.
		const unsigned char Index() const;

		// Optional, If this is a legacy sensor, then this field contains the 0-based index of the ASF_ALERTDATA structure in the Device Array of the ASF_ALRT structure in the ACPI 'ASF!' structure. If this is an ASF sensor, then this field contains the value of the Event Status Index required for a Get Event Status cycle on the SMBus. The value in this field is used in determining how to poll the status of the device on the SMBus. Supported for backwards compatibility.
		void Index(const unsigned char &value); 

		// Is true if the field Index exists in the current object, otherwise is false.
		bool IndexExists() const;

		// Remove Index field.
		void RemoveIndex(); 

		// Optional, The SMBus address of the physical sensor device that implements the logical sensor.
		const unsigned char DeviceAddress() const;

		// Optional, The SMBus address of the physical sensor device that implements the logical sensor.
		void DeviceAddress(const unsigned char &value); 

		// Is true if the field DeviceAddress exists in the current object, otherwise is false.
		bool DeviceAddressExists() const;

		// Remove DeviceAddress field.
		void RemoveDeviceAddress(); 

		// Optional, True if the assertion event is sent internally to the event handler. The event handler manages policies regarding whether the resulting event is sent in a PET frame and/or logged in the NV event log.
		const bool AssertionEvent() const;

		// Optional, True if the assertion event is sent internally to the event handler. The event handler manages policies regarding whether the resulting event is sent in a PET frame and/or logged in the NV event log.
		void AssertionEvent(const bool value); 

		// Is true if the field AssertionEvent exists in the current object, otherwise is false.
		bool AssertionEventExists() const;

		// Remove AssertionEvent field.
		void RemoveAssertionEvent(); 

		// Optional, True if the de-assertion event is sent internally to the event handler. The event handler manages policies regarding whether the resulting event is sent in a PET frame and/or logged in the NV event log
		const bool DeassertionEvent() const;

		// Optional, True if the de-assertion event is sent internally to the event handler. The event handler manages policies regarding whether the resulting event is sent in a PET frame and/or logged in the NV event log
		void DeassertionEvent(const bool value); 

		// Is true if the field DeassertionEvent exists in the current object, otherwise is false.
		bool DeassertionEventExists() const;

		// Remove DeassertionEvent field.
		void RemoveDeassertionEvent(); 

		// Optional, The value of the alert's Event Sensor Type field (see PET specification for definitions.)
		const unsigned char EventSensorType() const;

		// Optional, The value of the alert's Event Sensor Type field (see PET specification for definitions.)
		void EventSensorType(const unsigned char &value); 

		// Is true if the field EventSensorType exists in the current object, otherwise is false.
		bool EventSensorTypeExists() const;

		// Remove EventSensorType field.
		void RemoveEventSensorType(); 

		// Optional, The value of the alert's Event Type field (see PET specification for definitions.)
		const unsigned char EventType() const;

		// Optional, The value of the alert's Event Type field (see PET specification for definitions.)
		void EventType(const unsigned char &value); 

		// Is true if the field EventType exists in the current object, otherwise is false.
		bool EventTypeExists() const;

		// Remove EventType field.
		void RemoveEventType(); 

		// Optional, The value of the alert's Event Offset field (see PET specification for definitions.)
		const unsigned char EventOffset() const;

		// Optional, The value of the alert's Event Offset field (see PET specification for definitions.)
		void EventOffset(const unsigned char &value); 

		// Is true if the field EventOffset exists in the current object, otherwise is false.
		bool EventOffsetExists() const;

		// Remove EventOffset field.
		void RemoveEventOffset(); 

		// Optional, The value of the alert's Event Source Type field (see PET specification for definitions.)
		const unsigned char EventSourceType() const;

		// Optional, The value of the alert's Event Source Type field (see PET specification for definitions.)
		void EventSourceType(const unsigned char &value); 

		// Is true if the field EventSourceType exists in the current object, otherwise is false.
		bool EventSourceTypeExists() const;

		// Remove EventSourceType field.
		void RemoveEventSourceType(); 

		// Optional, The value of the alert's Event Severity field. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		const unsigned char EventSeverity() const;

		// Optional, The value of the alert's Event Severity field. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		void EventSeverity(const unsigned char &value); 

		// Is true if the field EventSeverity exists in the current object, otherwise is false.
		bool EventSeverityExists() const;

		// Remove EventSeverity field.
		void RemoveEventSeverity(); 

		// Optional, The value of the alert's Sensor Number field (see PET specification for definitions.)
		const unsigned char SensorNumber() const;

		// Optional, The value of the alert's Sensor Number field (see PET specification for definitions.)
		void SensorNumber(const unsigned char &value); 

		// Is true if the field SensorNumber exists in the current object, otherwise is false.
		bool SensorNumberExists() const;

		// Remove SensorNumber field.
		void RemoveSensorNumber(); 

		// Optional, The value to be set into the alert's Entity field (see PET specification for definitions.)
		const unsigned char Entity() const;

		// Optional, The value to be set into the alert's Entity field (see PET specification for definitions.)
		void Entity(const unsigned char &value); 

		// Is true if the field Entity exists in the current object, otherwise is false.
		bool EntityExists() const;

		// Remove Entity field.
		void RemoveEntity(); 

		// Optional, The value to be set into the alert's Entity Instance field (see PET specification for definitions.)
		const unsigned char EntityInstance() const;

		// Optional, The value to be set into the alert's Entity Instance field (see PET specification for definitions.)
		void EntityInstance(const unsigned char &value); 

		// Is true if the field EntityInstance exists in the current object, otherwise is false.
		bool EntityInstanceExists() const;

		// Remove EntityInstance field.
		void RemoveEntityInstance(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PETCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PETCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PETCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 13);
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
#endif // AMT_PETCAPABILITIES_H
