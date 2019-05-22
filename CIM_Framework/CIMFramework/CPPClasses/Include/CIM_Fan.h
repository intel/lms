//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Fan.h
//
//  Contents:   Capabilities and management of a Fan CoolingDevice.
//
//              This file was automatically generated from CIM_Fan.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_FAN_H
#define CIM_FAN_H 1
#include "CIM_CoolingDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of a Fan CoolingDevice.
	class CIMFRAMEWORK_API CIM_Fan  : public CIM_CoolingDevice
	{
	public:

		//Default constructor
		CIM_Fan()
			: CIM_CoolingDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CoolingDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_Fan(ICimWsmanClient *client)
			: CIM_CoolingDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CoolingDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_Fan(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Fan keys
		class CimKeys : public CIM_CoolingDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indication of whether the fan supports variable speeds.
		const bool VariableSpeed() const;

		// Optional, Indication of whether the fan supports variable speeds.
		void VariableSpeed(const bool value); 

		// Is true if the field VariableSpeed exists in the current object, otherwise is false.
		bool VariableSpeedExists() const;

		// Remove VariableSpeed field.
		void RemoveVariableSpeed(); 

		// Optional, DesiredSpeed is the currently requested fan speed, defined in Revolutions per Minute, when a variable speed fan is supported (VariableSpeed boolean = TRUE). The current speed is determined via a sensor (CIM_Tachometer) that is associated with the Fan using the CIM_AssociatedSensor relationship.
		const Uint64 DesiredSpeed() const;

		// Optional, DesiredSpeed is the currently requested fan speed, defined in Revolutions per Minute, when a variable speed fan is supported (VariableSpeed boolean = TRUE). The current speed is determined via a sensor (CIM_Tachometer) that is associated with the Fan using the CIM_AssociatedSensor relationship.
		void DesiredSpeed(const Uint64 value); 

		// Is true if the field DesiredSpeed exists in the current object, otherwise is false.
		bool DesiredSpeedExists() const;

		// Remove DesiredSpeed field.
		void RemoveDesiredSpeed(); 

		//Input parameter for function SetSpeed
		class CIMFRAMEWORK_API SetSpeed_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetSpeed_INPUT() : CimParam() {}

			// Class Destructor
			~SetSpeed_INPUT(){}

			// Optional, The desired speed for the fan.
			void DesiredSpeed(const Uint64 value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Requests that the Fan speed be set to the value specified in the method's input parameter. The return value should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int SetSpeed(const SetSpeed_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Fan> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Fan(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_CoolingDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CoolingDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Fan(const CimObject &object)
			: CIM_CoolingDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CoolingDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_CoolingDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_FAN_H
