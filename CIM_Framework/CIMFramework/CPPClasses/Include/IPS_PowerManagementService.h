//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_PowerManagementService.h
//
//  Contents:   The IPS_PowerManagementService inherits CIM_PowerManagementService and adds capability to control OS power state
//
//              This file was automatically generated from IPS_PowerManagementService.mof,  version: 10.0
//
//----------------------------------------------------------------------------
#ifndef IPS_POWERMANAGEMENTSERVICE_H
#define IPS_POWERMANAGEMENTSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_PowerManagementService inherits CIM_PowerManagementService and adds capability to control OS power state
	class CIMFRAMEWORK_API IPS_PowerManagementService  : public CIM_Service
	{
	public:

		//Default constructor
		IPS_PowerManagementService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		IPS_PowerManagementService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~IPS_PowerManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_PowerManagementService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The current operating system power saving state of the associated Managed System Element.
		const unsigned short OSPowerSavingState() const;

		// Optional, The current operating system power saving state of the associated Managed System Element.
		void OSPowerSavingState(const unsigned short value); 

		// Is true if the field OSPowerSavingState exists in the current object, otherwise is false.
		bool OSPowerSavingStateExists() const;

		// Remove OSPowerSavingState field.
		void RemoveOSPowerSavingState(); 

		//Input parameter for function RequestOSPowerSavingStateChange
		class CIMFRAMEWORK_API RequestOSPowerSavingStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestOSPowerSavingStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestOSPowerSavingStateChange_INPUT(){}

			// Optional, The OS power saving state for ManagedElement.
			// Legal values:
			// Full Power: 2
			// OS power saving: 3
			// DMTF Reserved: ..
			// Vendor Specific: 0x7FFF..0xFFFF
			void OSPowerSavingState(const unsigned short value); 

			// Optional, ManagedElement indicates the element whose state is set.
			void ManagedElement(const CimReference &value); 

			// Optional, Time indicates when the OS power saving state should be set, either as a regular date-time value or as an interval value (where the interval begins when the method invocation is received.
			void Time(const CimDateTime &value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' must be returned.
			void TimeoutPeriod(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RequestOSPowerSavingStateChange
		class CIMFRAMEWORK_API RequestOSPowerSavingStateChange_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestOSPowerSavingStateChange_OUTPUT() : CimParam() {}

			// Class Destructor
			~RequestOSPowerSavingStateChange_OUTPUT(){}

			// class fields
			// Reference to the job (can be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// RequestOSPowerSavingStateChange defines the desired OS powersaving state of the managed element, and when the element should be put into that state. The RequestOSPowerSavingStateChange method has xxx input  parameters and a result code. 
		// - OSPowerSavingState indicates the desired OS power saving state. 
		// - ManagedElement indicates the element whose OS state is set. This element SHOULD be associated to the service using the AssociatedPowerManagementService relationship. 
		// - Time indicates when the OS power saving state should be set, either as a regular date-time value or as an  interval value (where the interval begins when the method invocation is received). 
		// - Job is a reference to the job if started. 
		// - TimeOutPeriod indicates the maximum amount of time a client expects the transition to take. 
		// 
		virtual unsigned int RequestOSPowerSavingStateChange(const RequestOSPowerSavingStateChange_INPUT &input, RequestOSPowerSavingStateChange_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_PowerManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_PowerManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_PowerManagementService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // IPS_POWERMANAGEMENTSERVICE_H
