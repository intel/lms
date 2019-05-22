//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PETFilterSetting.h
//
//  Contents:   This class represents a PET filter in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_PETFilterSetting.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PETFILTERSETTING_H
#define AMT_PETFILTERSETTING_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class represents a PET filter in the Intel(R) AMT system.
	class CIMFRAMEWORK_API AMT_PETFilterSetting  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_PETFilterSetting()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}

		//constructor which receives WSMan client
		AMT_PETFilterSetting(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}

		//Destructor
		virtual ~AMT_PETFilterSetting(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PETFilterSetting keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, Specifies whether this filter is currently being applied to platform events.
		const bool EnableFilter() const;

		// Required, Specifies whether this filter is currently being applied to platform events.
		void EnableFilter(const bool value); 

		// Is true if the field EnableFilter exists in the current object, otherwise is false.
		bool EnableFilterExists() const;

		// Remove EnableFilter field.
		void RemoveEnableFilter(); 

		// Required, Specifies whether this fitler is a manufacturer pre-configured filter (The filter entry has been configured by the system integrator and cannot be altered by software - updated, enabled, disabled or removed).
		const bool OEMFilter() const;

		// Required, Specifies whether this fitler is a manufacturer pre-configured filter (The filter entry has been configured by the system integrator and cannot be altered by software - updated, enabled, disabled or removed).
		void OEMFilter(const bool value); 

		// Is true if the field OEMFilter exists in the current object, otherwise is false.
		bool OEMFilterExists() const;

		// Remove OEMFilter field.
		void RemoveOEMFilter(); 

		// Required, Specifies whether the system should log events that match the criteria established via this filter
		const bool LogOnEvent() const;

		// Required, Specifies whether the system should log events that match the criteria established via this filter
		void LogOnEvent(const bool value); 

		// Is true if the field LogOnEvent exists in the current object, otherwise is false.
		bool LogOnEventExists() const;

		// Remove LogOnEvent field.
		void RemoveLogOnEvent(); 

		// Required, The SMBus address of the physical sensor device that implements the logical sensor.
		const unsigned char DeviceAddress() const;

		// Required, The SMBus address of the physical sensor device that implements the logical sensor.
		void DeviceAddress(const unsigned char &value); 

		// Is true if the field DeviceAddress exists in the current object, otherwise is false.
		bool DeviceAddressExists() const;

		// Remove DeviceAddress field.
		void RemoveDeviceAddress(); 

		// Required, The value of the alert's Event Sensor Type field (see PET specification for definitions.)
		const unsigned char EventSensorType() const;

		// Required, The value of the alert's Event Sensor Type field (see PET specification for definitions.)
		void EventSensorType(const unsigned char &value); 

		// Is true if the field EventSensorType exists in the current object, otherwise is false.
		bool EventSensorTypeExists() const;

		// Remove EventSensorType field.
		void RemoveEventSensorType(); 

		// Required, The value of the alert's Event Type field (see PET specification for definitions.)
		const unsigned char EventType() const;

		// Required, The value of the alert's Event Type field (see PET specification for definitions.)
		void EventType(const unsigned char &value); 

		// Is true if the field EventType exists in the current object, otherwise is false.
		bool EventTypeExists() const;

		// Remove EventType field.
		void RemoveEventType(); 

		// Required, The value of the alert's Event Offset field (see PET specification for definitions.)
		const unsigned char EventOffset() const;

		// Required, The value of the alert's Event Offset field (see PET specification for definitions.)
		void EventOffset(const unsigned char &value); 

		// Is true if the field EventOffset exists in the current object, otherwise is false.
		bool EventOffsetExists() const;

		// Remove EventOffset field.
		void RemoveEventOffset(); 

		// Required, The value of the alert's Event Source Type field (see PET specification for definitions.)
		const unsigned char EventSourceType() const;

		// Required, The value of the alert's Event Source Type field (see PET specification for definitions.)
		void EventSourceType(const unsigned char &value); 

		// Is true if the field EventSourceType exists in the current object, otherwise is false.
		bool EventSourceTypeExists() const;

		// Remove EventSourceType field.
		void RemoveEventSourceType(); 

		// Required, The value of the alert's Event Severity field. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		const unsigned char EventSeverity() const;

		// Required, The value of the alert's Event Severity field. The severity values are based on the 'DMI' severity values used for the generic sensor event/reading type code.
		void EventSeverity(const unsigned char &value); 

		// Is true if the field EventSeverity exists in the current object, otherwise is false.
		bool EventSeverityExists() const;

		// Remove EventSeverity field.
		void RemoveEventSeverity(); 

		// Required, The value of the alert's Sensor Number field (see PET specification for definitions.)
		const unsigned char SensorNumber() const;

		// Required, The value of the alert's Sensor Number field (see PET specification for definitions.)
		void SensorNumber(const unsigned char &value); 

		// Is true if the field SensorNumber exists in the current object, otherwise is false.
		bool SensorNumberExists() const;

		// Remove SensorNumber field.
		void RemoveSensorNumber(); 

		// Required, The value to be set into the alert's Entity field (see PET specification for definitions.)
		const unsigned char Entity() const;

		// Required, The value to be set into the alert's Entity field (see PET specification for definitions.)
		void Entity(const unsigned char &value); 

		// Is true if the field Entity exists in the current object, otherwise is false.
		bool EntityExists() const;

		// Remove Entity field.
		void RemoveEntity(); 

		// Required, The value to be set into the alert's Entity Instance field (see PET specification for definitions.)
		const unsigned char EntityInstance() const;

		// Required, The value to be set into the alert's Entity Instance field (see PET specification for definitions.)
		void EntityInstance(const unsigned char &value); 

		// Is true if the field EntityInstance exists in the current object, otherwise is false.
		bool EntityInstanceExists() const;

		// Remove EntityInstance field.
		void RemoveEntityInstance(); 

		// Required, Associates a filter to its Subscription.
		const unsigned char PolicyID() const;

		// Required, Associates a filter to its Subscription.
		void PolicyID(const unsigned char &value); 

		// Is true if the field PolicyID exists in the current object, otherwise is false.
		bool PolicyIDExists() const;

		// Remove PolicyID field.
		void RemovePolicyID(); 

		// Required, Indicates whether the service should send an event alert.
		const bool SendAlert() const;

		// Required, Indicates whether the service should send an event alert.
		void SendAlert(const bool value); 

		// Is true if the field SendAlert exists in the current object, otherwise is false.
		bool SendAlertExists() const;

		// Remove SendAlert field.
		void RemoveSendAlert(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PETFilterSetting> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PETFilterSetting(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PETFilterSetting(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 14);
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
#endif // AMT_PETFILTERSETTING_H
