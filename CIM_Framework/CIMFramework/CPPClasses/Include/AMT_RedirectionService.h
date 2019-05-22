//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RedirectionService.h
//
//  Contents:   Represents the redirection service, which encompasses the IDER and SOL redirection functionalities
//
//              This file was automatically generated from AMT_RedirectionService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_REDIRECTIONSERVICE_H
#define AMT_REDIRECTIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the redirection service, which encompasses the IDER and SOL redirection functionalities
	class CIMFRAMEWORK_API AMT_RedirectionService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_RedirectionService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_RedirectionService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_RedirectionService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_RedirectionService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Describes the listener state of this service. The service is operational only if its EnabledState is set to Enabled (by the Intel(R) AMT Administrator) and the ListenerEnabled is set to TRUE (by a RedirectionRealm user)
		const bool ListenerEnabled() const;

		// Optional, Describes the listener state of this service. The service is operational only if its EnabledState is set to Enabled (by the Intel(R) AMT Administrator) and the ListenerEnabled is set to TRUE (by a RedirectionRealm user)
		void ListenerEnabled(const bool value); 

		// Is true if the field ListenerEnabled exists in the current object, otherwise is false.
		bool ListenerEnabledExists() const;

		// Remove ListenerEnabled field.
		void RemoveListenerEnabled(); 

		// Optional, A list of string elements, describing recent IDE redirection operations. The format of each element is: 'Date (MM/DD/YYYY), Time (hh:mm:ss), IP:Port'
		const vector<string> AccessLog() const;

		// Optional, A list of string elements, describing recent IDE redirection operations. The format of each element is: 'Date (MM/DD/YYYY), Time (hh:mm:ss), IP:Port'
		void AccessLog(const vector<string> &value); 

		// Is true if the field AccessLog exists in the current object, otherwise is false.
		bool AccessLogExists() const;

		// Remove AccessLog field.
		void RemoveAccessLog(); 

		//Input parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_INPUT(){}

			// Optional, The state requested for the element. This information will be placed into the RequestedState property of the instance if the return code of the RequestStateChange method is 0 ('Completed with No Error'), 3 ('Timeout'), or 4096 (0x1000) ('Job Started'). Refer to the description of the EnabledState and RequestedState properties for the detailed explanations of the RequestedState values.
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
			// disable IDER and SOL: 32768
			// enable IDER and disable SOL: 32769
			// enable SOL and disable IDER: 32770
			// enable IDER and SOL: 32771
			// Vendor Reserved: 32772..65535
			void RequestedState(const unsigned short value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' must be returned.
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
			// Reference to the job (can be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// Requests that the state of the element be changed to the value specified in the RequestedState parameter. When the requested state change takes place, the EnabledState and RequestedState of the element will be the same. Invoking the RequestStateChange method multiple times could result in earlier requests being overwritten or lost. 
		// If 0 is returned, then the task completed successfully and the use of ConcreteJob was not required. If 4096 (0x1000) is returned, then the task will take some time to complete, ConcreteJob will be created, and its reference returned in the output parameter Job. Any other return code indicates an error condition.
		virtual unsigned int RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output);

		//Input parameter for function TerminateSession
		class CIMFRAMEWORK_API TerminateSession_INPUT : public CimParam
		{
		public:
			// Class Constructor
			TerminateSession_INPUT() : CimParam() {}

			// Class Destructor
			~TerminateSession_INPUT(){}

			// Optional, The session type to cancel
			// Legal values:
			// IDER: 0
			// SOL: 1
			// Reserved: 2..
			void SessionType(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Terminate an ongoing redirection session
		virtual unsigned int TerminateSession(const TerminateSession_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_RedirectionService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_RedirectionService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_RedirectionService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // AMT_REDIRECTIONSERVICE_H
