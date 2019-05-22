//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPortConfigurationService.h
//
//  Contents:   CIM_NetworkPortConfigurationService provides management of the network interfaces associated with a network port.
//
//              This file was automatically generated from CIM_NetworkPortConfigurationService.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_NETWORKPORTCONFIGURATIONSERVICE_H
#define CIM_NETWORKPORTCONFIGURATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_NetworkPortConfigurationService provides management of the network interfaces associated with a network port.
	class CIMFRAMEWORK_API CIM_NetworkPortConfigurationService  : public CIM_Service
	{
	public:

		//Default constructor
		CIM_NetworkPortConfigurationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_NetworkPortConfigurationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_NetworkPortConfigurationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_NetworkPortConfigurationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		// The StopService method places the Service in the stopped state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StopService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully stopped, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "stop" semantics are convenient to use.
		virtual unsigned int StopService();

		// The StartService method places the Service in the started state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StartService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully started, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "start" semantics are convenient to use.
		virtual unsigned int StartService();

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

		//Input parameter for function AddLANEndpoint
		class CIMFRAMEWORK_API AddLANEndpoint_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddLANEndpoint_INPUT() : CimParam() {}

			// Class Destructor
			~AddLANEndpoint_INPUT(){}

			// Required, The NetworkPort to which the network interface will be added.
			void Port(const CimReference &value); 

			// Required, The MAC address requested.
			void Address(const string &value); 

			// Optional, The requested LAN ID.
			void LANID(const string &value); 

			// Required, The requested alias addresses.
			void AliasAddresses(const vector<string> &value); 

			// Required, The requested group addresses.
			void GroupAddresses(const vector<string> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddLANEndpoint
		class CIMFRAMEWORK_API AddLANEndpoint_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddLANEndpoint_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddLANEndpoint_OUTPUT(){}

			// class fields
			// The created LANEndpoint.
			const CimReference Endpoint() const;
			bool EndpointExists() const;
		private:
		};

		// Create a CIM_LANEndpoint instance and associate it with the specified NetworkPort instance via an instance of CIM_PortImplementsEndpoint. The newly created instance of CIM_LANEndpont contains the configuration properties specified or default values applicable for the specified NetworkPort instance. This method will also create an instance of CIM_HostedAccessPoint which associates the newly created CIM_LANEndpoint instance with the instance of CIM_ComputerSystem which scopes the specified CIM_NetworkPort. An extrinsic method is required in order to provide atomic creation of multiple, related instances. Prior to creating the instances, the implementation will verify that a CIM_LANEndpoint instance can be created and associated with the CIM_NetworkPort instance.
		virtual unsigned int AddLANEndpoint(const AddLANEndpoint_INPUT &input, AddLANEndpoint_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_NetworkPortConfigurationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_NetworkPortConfigurationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_NetworkPortConfigurationService(const CimObject &object)
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
#endif // CIM_NETWORKPORTCONFIGURATIONSERVICE_H
