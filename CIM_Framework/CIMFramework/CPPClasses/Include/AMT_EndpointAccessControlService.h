//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EndpointAccessControlService.h
//
//  Contents:   A AMT_EndpointAccessControlService is a Logical Element that contains the information necessary to represent and manage the functionality provided by a the Endpoint Access Control manager of Intel(R) AMT.
//
//              This file was automatically generated from AMT_EndpointAccessControlService.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ENDPOINTACCESSCONTROLSERVICE_H
#define AMT_ENDPOINTACCESSCONTROLSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A AMT_EndpointAccessControlService is a Logical Element that contains the information necessary to represent and manage the functionality provided by a the Endpoint Access Control manager of Intel(R) AMT.
	class CIMFRAMEWORK_API AMT_EndpointAccessControlService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_EndpointAccessControlService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_EndpointAccessControlService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_EndpointAccessControlService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_EndpointAccessControlService keys
		class CimKeys : public CIM_Service::CimKeys
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

		//Input parameter for function GetPosture
		class CIMFRAMEWORK_API GetPosture_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPosture_INPUT() : CimParam() {}

			// Class Destructor
			~GetPosture_INPUT(){}

			// Required, The posture type to be generated.
			// Legal values:
			// Attribute-Value pair (AVP) type: 0
			void PostureType(const unsigned short value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetPosture
		class CIMFRAMEWORK_API GetPosture_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPosture_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetPosture_OUTPUT(){}

			// class fields
			// BLOB representation of a Signed NAC Posture data block.
			const Base64 SignedPosture() const;
			bool SignedPostureExists() const;
			// A computed hash value over the posture data (fields like current time is omitted). This hash can be used to check if the posture was changed, comparing to the last computed hash value.
			const Base64 PostureChangeHash() const;
			bool PostureChangeHashExists() const;
		private:
		};

		// This method returns (and optionally updates) the EAC posture for the Intel(R) AMT device.
		virtual unsigned int GetPosture(const GetPosture_INPUT &input, GetPosture_OUTPUT &output);

		//Input parameter for function GetPostureHash
		class CIMFRAMEWORK_API GetPostureHash_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPostureHash_INPUT() : CimParam() {}

			// Class Destructor
			~GetPostureHash_INPUT(){}

			// Required, The posture type to be generated.
			// Legal values:
			// Attribute-Value pair (AVP) type: 0
			void PostureType(const unsigned short value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetPostureHash
		class CIMFRAMEWORK_API GetPostureHash_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPostureHash_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetPostureHash_OUTPUT(){}

			// class fields
			// A computed hash value over the posture data (fields like current time is omitted). This hash can be used to check if the posture was changed, comparing to the last computed hash value.
			const Base64 PostureChangeHash() const;
			bool PostureChangeHashExists() const;
		private:
		};

		// This method returns an hash of the currently available posture for the Intel(R) AMT device, which can be compared to hash values from previous results to detect differences.
		virtual unsigned int GetPostureHash(const GetPostureHash_INPUT &input, GetPostureHash_OUTPUT &output);

		//Input parameter for function UpdatePostureState
		class CIMFRAMEWORK_API UpdatePostureState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdatePostureState_INPUT() : CimParam() {}

			// Class Destructor
			~UpdatePostureState_INPUT(){}

			// Required, The posture element to be updated.
			// Legal values:
			// PostureUpdateBootCounters: 0
			// PostureUpdateAgentPresenceState: 1
			void UpdateType(const unsigned short value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This command tells the Intel AMT device to reset its boot counters and Agent Presence state counters.
		virtual unsigned int UpdatePostureState(const UpdatePostureState_INPUT &input);

		//Output parameter for function GetEacOptions
		class CIMFRAMEWORK_API GetEacOptions_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetEacOptions_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetEacOptions_OUTPUT(){}

			// class fields
			// Enabled EAC Vendors
			// Legal values:
			// EAC NAC: 1
			// EAC NAP: 2
			// EAC NAC and NAP: 3
			// Reserved: 4..65535
			const unsigned int EacVendors() const;
			bool EacVendorsExists() const;
			// Posture Hash Type
			// Legal values:
			// SHA-1-160: 1
			// SHA-2-256: 2
			// SHA-2-384: 3
			// Reserved: 4..65535
			const unsigned int PostureHashAlgorithm() const;
			bool PostureHashAlgorithmExists() const;
		private:
		};

		// This method returns EAC options for the Intel(R) AMT device.
		virtual unsigned int GetEacOptions(GetEacOptions_OUTPUT &output);

		//Input parameter for function SetEacOptions
		class CIMFRAMEWORK_API SetEacOptions_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetEacOptions_INPUT() : CimParam() {}

			// Class Destructor
			~SetEacOptions_INPUT(){}

			// Required, Enabled EAC Vendors
			// Legal values:
			// EAC NAC: 1
			// EAC NAP: 2
			// EAC NAC and NAP: 3
			// Reserved: 4..65535
			void EacVendors(const unsigned int value); 

			// Required, Posture Hash Method
			// Legal values:
			// SHA-1-160: 1
			// SHA-2-256: 2
			// SHA-2-384: 3
			// Reserved: 4..65535
			void PostureHashAlgorithm(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method configures EAC options for the Intel(R) AMT device.
		virtual unsigned int SetEacOptions(const SetEacOptions_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_EndpointAccessControlService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_EndpointAccessControlService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_EndpointAccessControlService(const CimObject &object)
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
#endif // AMT_ENDPOINTACCESSCONTROLSERVICE_H
