//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AuthenticationService.h
//
//  Contents:   CIM_AuthenticationService verifies users' identities through some means. These services are decomposed into a subclass that provides credentials to users and a subclass that provides for the verification of the validity of a credential and, perhaps, the appropriateness of its use for access to target resources. The persistent state information used from one such verification to another is maintained in an instance of Identity class.
//
//              This file was automatically generated from CIM_AuthenticationService.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_AUTHENTICATIONSERVICE_H
#define CIM_AUTHENTICATIONSERVICE_H 1
#include "CIM_SecurityService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_AuthenticationService verifies users' identities through some means. These services are decomposed into a subclass that provides credentials to users and a subclass that provides for the verification of the validity of a credential and, perhaps, the appropriateness of its use for access to target resources. The persistent state information used from one such verification to another is maintained in an instance of Identity class.
	class CIMFRAMEWORK_API CIM_AuthenticationService  : public CIM_SecurityService
	{
	public:

		//Default constructor
		CIM_AuthenticationService()
			: CIM_SecurityService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_AuthenticationService(ICimWsmanClient *client)
			: CIM_SecurityService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_AuthenticationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AuthenticationService keys
		class CimKeys : public CIM_SecurityService::CimKeys
		{
		public:
		};
		//Input parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_INPUT(){}

			// Optional, The state requested for the element. This information will be placed into the RequestedState property of the instance if the return code of the RequestStateChange method is 0 ('Completed with No Error'), or 4096 (0x1000) ('Job Started'). Refer to the description of the EnabledState and RequestedState properties for the detailed explanations of the RequestedState values.
			// Legal values:
			// Enabled: 2
			// Disabled: 3
			// Shut Down: 4
			// Offline: 6
			// Test: 7
			// Defer: 8
			// Quiesce: 9
			// Reboot: 10
			// Reset: 11
			// DMTF Reserved: ..
			// Vendor Reserved: 32768..65535
			void RequestedState(const unsigned short value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' shall be returned.
			void TimeoutPeriod(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_OUTPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_OUTPUT(){}

			// class fields
			// May contain a reference to the ConcreteJob created to track the state transition initiated by the method invocation.
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// Requests that the state of the element be changed to the value specified in the RequestedState parameter. When the requested state change takes place, the EnabledState and RequestedState of the element will be the same. Invoking the RequestStateChange method multiple times could result in earlier requests being overwritten or lost. 
		// A return code of 0 shall indicate the state change was successfully initiated. 
		// A return code of 3 shall indicate that the state transition cannot complete within the interval specified by the TimeoutPeriod parameter. 
		// A return code of 4096 (0x1000) shall indicate the state change was successfully initiated, a ConcreteJob has been created, and its reference returned in the output parameter Job. Any other return code indicates an error condition.
		virtual unsigned int RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output);

		// The StartService method places the Service in the started state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StartService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully started, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "start" semantics are convenient to use.
		virtual unsigned int StartService();

		// The StopService method places the Service in the stopped state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StopService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully stopped, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "stop" semantics are convenient to use.
		virtual unsigned int StopService();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AuthenticationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AuthenticationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SecurityService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AuthenticationService(const CimObject &object)
			: CIM_SecurityService(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SecurityService::SetMetaData(childMetaData);
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
#endif // CIM_AUTHENTICATIONSERVICE_H
