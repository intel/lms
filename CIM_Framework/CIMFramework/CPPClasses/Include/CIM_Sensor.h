//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Sensor.h
//
//  Contents:   A Sensor is an entity capable of measuring or reporting the characteristics of some physical property - for example, the temperature or voltage characteristics of a Computer System.
//
//              This file was automatically generated from CIM_Sensor.mof,  version: 2.32.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SENSOR_H
#define CIM_SENSOR_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A Sensor is an entity capable of measuring or reporting the characteristics of some physical property - for example, the temperature or voltage characteristics of a Computer System.
	class CIMFRAMEWORK_API CIM_Sensor  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_Sensor()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		CIM_Sensor(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~CIM_Sensor(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Sensor keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The Type of the Sensor, e.g. Voltage or Temperature Sensor. If the type is set to "Other", then the OtherSensorType Description can be used to further identify the type, or if the Sensor has numeric readings, then the type of the Sensor can be implicitly determined by the Units. A description of the different Sensor types is as follows: A Temperature Sensor measures the environmental temperature. Voltage and Current Sensors measure electrical voltage and current readings. A Tachometer measures speed/revolutions of a Device. For example, a Fan Device can have an associated Tachometer which measures its speed. A Counter is a general purpose Sensor that measures some numerical property of a Device. A Counter value can be cleared, but it never decreases. A Switch Sensor has states like Open/Close, On/Off, or Up/Down. A Lock has states of Locked/Unlocked. Humidity, Smoke Detection and Air Flow Sensors measure the equivalent environmental characteristics. A Presence Sensor detects the presence of a PhysicalElement. A Power Consumption Sensor measures the instantaneous power consumed by a managed element. A Power Production Sensor measures the instantaneous power produced by a managed element such as a power supply or a voltage regulator. A pressure sensor is used to report pressure. Intrusion sensor reports an intrusion of an enclosure regardless whether it was authorized or not.
		const unsigned short SensorType() const;

		// Optional, The Type of the Sensor, e.g. Voltage or Temperature Sensor. If the type is set to "Other", then the OtherSensorType Description can be used to further identify the type, or if the Sensor has numeric readings, then the type of the Sensor can be implicitly determined by the Units. A description of the different Sensor types is as follows: A Temperature Sensor measures the environmental temperature. Voltage and Current Sensors measure electrical voltage and current readings. A Tachometer measures speed/revolutions of a Device. For example, a Fan Device can have an associated Tachometer which measures its speed. A Counter is a general purpose Sensor that measures some numerical property of a Device. A Counter value can be cleared, but it never decreases. A Switch Sensor has states like Open/Close, On/Off, or Up/Down. A Lock has states of Locked/Unlocked. Humidity, Smoke Detection and Air Flow Sensors measure the equivalent environmental characteristics. A Presence Sensor detects the presence of a PhysicalElement. A Power Consumption Sensor measures the instantaneous power consumed by a managed element. A Power Production Sensor measures the instantaneous power produced by a managed element such as a power supply or a voltage regulator. A pressure sensor is used to report pressure. Intrusion sensor reports an intrusion of an enclosure regardless whether it was authorized or not.
		void SensorType(const unsigned short value); 

		// Is true if the field SensorType exists in the current object, otherwise is false.
		bool SensorTypeExists() const;

		// Remove SensorType field.
		void RemoveSensorType(); 

		// Optional, A string describing the Sensor type - used when the SensorType property is set to "Other".
		const string OtherSensorTypeDescription() const;

		// Optional, A string describing the Sensor type - used when the SensorType property is set to "Other".
		void OtherSensorTypeDescription(const string &value); 

		// Is true if the field OtherSensorTypeDescription exists in the current object, otherwise is false.
		bool OtherSensorTypeDescriptionExists() const;

		// Remove OtherSensorTypeDescription field.
		void RemoveOtherSensorTypeDescription(); 

		// Optional, PossibleStates enumerates the string outputs of the Sensor. For example, a "Switch" Sensor may output the states "On", or "Off". Another implementation of the Switch may output the states "Open", and "Close". Another example is a NumericSensor supporting thresholds. This Sensor can report the states like "Normal", "Upper Fatal", "Lower Non-Critical", etc. A NumericSensor that does not publish readings and thresholds, but stores this data internally, can still report its states.
		const vector<string> PossibleStates() const;

		// Optional, PossibleStates enumerates the string outputs of the Sensor. For example, a "Switch" Sensor may output the states "On", or "Off". Another implementation of the Switch may output the states "Open", and "Close". Another example is a NumericSensor supporting thresholds. This Sensor can report the states like "Normal", "Upper Fatal", "Lower Non-Critical", etc. A NumericSensor that does not publish readings and thresholds, but stores this data internally, can still report its states.
		void PossibleStates(const vector<string> &value); 

		// Is true if the field PossibleStates exists in the current object, otherwise is false.
		bool PossibleStatesExists() const;

		// Remove PossibleStates field.
		void RemovePossibleStates(); 

		// Optional, The current state indicated by the Sensor. This is always one of the "PossibleStates".
		const string CurrentState() const;

		// Optional, The current state indicated by the Sensor. This is always one of the "PossibleStates".
		void CurrentState(const string &value); 

		// Is true if the field CurrentState exists in the current object, otherwise is false.
		bool CurrentStateExists() const;

		// Remove CurrentState field.
		void RemoveCurrentState(); 

		// Optional, The polling interval that the Sensor hardware or the instrumentation uses to determine the current state of the Sensor.
		const Uint64 PollingInterval() const;

		// Optional, The polling interval that the Sensor hardware or the instrumentation uses to determine the current state of the Sensor.
		void PollingInterval(const Uint64 value); 

		// Is true if the field PollingInterval exists in the current object, otherwise is false.
		bool PollingIntervalExists() const;

		// Remove PollingInterval field.
		void RemovePollingInterval(); 

		// Optional, SensorContext indicates the purpose and context of the sensor. For example, the property may indicate what entity is being monitored or where the sensor is installed. Contextual and location information should be provided using associations to existing model elements. This property may be used if additional differentiation is necessary beyond that which is possible to convey using associations or values of SensorType. The value shall be formatted using the following algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the SensorContext or that is a registered ID assigned to the business entity by a recognized global authority. In addition, to ensure uniqueness, <OrgID> shall not contain a colon (:). 
		// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements.
		const string SensorContext() const;

		// Optional, SensorContext indicates the purpose and context of the sensor. For example, the property may indicate what entity is being monitored or where the sensor is installed. Contextual and location information should be provided using associations to existing model elements. This property may be used if additional differentiation is necessary beyond that which is possible to convey using associations or values of SensorType. The value shall be formatted using the following algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the SensorContext or that is a registered ID assigned to the business entity by a recognized global authority. In addition, to ensure uniqueness, <OrgID> shall not contain a colon (:). 
		// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements.
		void SensorContext(const string &value); 

		// Is true if the field SensorContext exists in the current object, otherwise is false.
		bool SensorContextExists() const;

		// Remove SensorContext field.
		void RemoveSensorContext(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Sensor> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Sensor(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Sensor(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // CIM_SENSOR_H
