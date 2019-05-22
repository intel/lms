//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerManagementService.h
//
//  Contents:   A class derived from Service that describes power management functionality, hosted on a System. Whether this service might be used to affect the power state of a particular element is defined by the CIM_ServiceAvailable ToElement association.
//
//              This file was automatically generated from CIM_PowerManagementService.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#ifndef CIM_POWERMANAGEMENTSERVICE_H
#define CIM_POWERMANAGEMENTSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from Service that describes power management functionality, hosted on a System. Whether this service might be used to affect the power state of a particular element is defined by the CIM_ServiceAvailable ToElement association.
	class CIMFRAMEWORK_API CIM_PowerManagementService  : public CIM_Service
	{
	public:

		//Default constructor
		CIM_PowerManagementService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_PowerManagementService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_PowerManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PowerManagementService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Input parameter for function RequestPowerStateChange
		class CIMFRAMEWORK_API RequestPowerStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestPowerStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestPowerStateChange_INPUT(){}

			// Optional, The power state for ManagedElement.
			// Legal values:
			// Power On: 2
			// Sleep - Light: 3
			// Sleep - Deep: 4
			// Power Cycle (Off Soft): 5
			// Power Off - Hard: 6
			// Hibernate: 7
			// Power Off - Soft: 8
			// Power Cycle (Off Hard): 9
			// Master Bus Reset: 10
			// Diagnostic Interrupt (NMI): 11
			// Power Off - Soft Graceful: 12
			// Power Off - Hard Graceful: 13
			// Master Bus Reset Graceful: 14
			// Power Cycle (Off - Soft Graceful): 15
			// Power Cycle (Off - Hard Graceful): 16
			void PowerState(const unsigned short value); 

			// Optional, ManagedElement indicates the element whose state is set.
			void ManagedElement(const CimReference &value); 

			// Optional, Time indicates when the power state should be set, either as a regular date-time value or as an interval value (where the interval begins when the method invocation is received.
			void Time(const CimDateTime &value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' must be returned.
			void TimeoutPeriod(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RequestPowerStateChange
		class CIMFRAMEWORK_API RequestPowerStateChange_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestPowerStateChange_OUTPUT() : CimParam() {}

			// Class Destructor
			~RequestPowerStateChange_OUTPUT(){}

			// class fields
			// Reference to the job (can be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// RequestPowerStateChange defines the desired power state of the managed element, and when the element should be put into that state. The RequestPowerStateChange method has five input parameters and a result code. 
		// - PowerState indicates the desired power state. 
		// - ManagedElement indicates the element whose state is set. This element SHOULD be associated to the service using the AssociatedPowerManagementService relationship. 
		// - Time indicates when the power state should be set, either as a regular date-time value or as an interval value (where the interval begins when the method invocation is received). 
		// - Job is a reference to the job if started. 
		// - TimeOutPeriod indicates the maximum amount of time a client is expects the transition to take. 
		// See CIM_PowerStateCapabilities for descriptions of PowerState parameter enumerations.
		virtual unsigned int RequestPowerStateChange(const RequestPowerStateChange_INPUT &input, RequestPowerStateChange_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PowerManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PowerManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PowerManagementService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // CIM_POWERMANAGEMENTSERVICE_H
