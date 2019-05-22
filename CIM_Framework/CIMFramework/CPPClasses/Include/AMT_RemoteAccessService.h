//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessService.h
//
//  Contents:   Represents the Remote Access Service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_RemoteAccessService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_REMOTEACCESSSERVICE_H
#define AMT_REMOTEACCESSSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the Remote Access Service in the Intel(R) AMT subsystem.
	class CIMFRAMEWORK_API AMT_RemoteAccessService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_RemoteAccessService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_RemoteAccessService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_RemoteAccessService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_RemoteAccessService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Input parameter for function AddMpServer
		class CIMFRAMEWORK_API AddMpServer_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddMpServer_INPUT() : CimParam() {}

			// Class Destructor
			~AddMpServer_INPUT(){}

			// Required, A string holding the IP address or FQDN of the server
			void AccessInfo(const string &value); 

			// Required, An enumerated integer describing the format and interpretation of the AccessInfo property.
			// Legal values:
			// IPv4 Address: 3
			// IPv6 Address: 4
			// FQDN: 201
			void InfoFormat(const unsigned short value); 

			// Required, The port to be used to establish a tunnel with the MPS.
			void Port(const unsigned short value); 

			// Required, Authentication method to be used when the Intel(R) AMT subsystem opens a tunnel to the MpServer
			// Legal values:
			// Mutual Authentication: 1
			// Username Password Authentication: 2
			void AuthMethod(const unsigned int value); 

			// Optional, A reference to a certificate. Required if AuthMethod is set to mutual authentication
			void Certificate(const CimReference &value); 

			// Optional, A Username to be used for the connection with the MPS if Username-Pwd authentication is used. Limited to 16 alphanumeric characters
			void Username(const string &value); 

			// Optional, A Password to be used for the connection with the MPS if Username-Pwd authentication is used. Limited to 16 characters
			void Password(const string &value); 

			// Optional, A common name used when AccessInfo is an IP address.
			void CN(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddMpServer
		class CIMFRAMEWORK_API AddMpServer_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddMpServer_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddMpServer_OUTPUT(){}

			// class fields
			// A reference to the created MPS if the operation succeeded.
			const CimReference MpServer() const;
			bool MpServerExists() const;
		private:
		};

		// Adds a Management Presence Server to the Intel(R) AMT subsystem. Creates an AMT_ManagementPresenceRemoteSAP instance and an AMT_RemoteAccessCredentialContext association to a credential. This credential may be an existing AMT_PublicKeyCertificate instance (if the created MPS is configured to use mutual authentication). If the created MpServer is configured to use username password authentication, an AMT_MPSUsernamePassword instance is created and used as the associated credential.
		virtual unsigned int AddMpServer(const AddMpServer_INPUT &input, AddMpServer_OUTPUT &output);

		//Input parameter for function AddRemoteAccessPolicyRule
		class CIMFRAMEWORK_API AddRemoteAccessPolicyRule_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddRemoteAccessPolicyRule_INPUT() : CimParam() {}

			// Class Destructor
			~AddRemoteAccessPolicyRule_INPUT(){}

			// Required, The event that will trigger the establishment of the remote connection to the MpServer.
			// Legal values:
			// User Initiated: 0
			// Alert: 1
			// Periodic: 2
			// Home Provisioning: 3
			void Trigger(const unsigned short value); 

			// Required, Defines the tunnel's lifetime in seconds, 0 means no lifetime- the tunnel should stay open until it is closed by CloseRemoteAccessConnection or when a different policy with higher priority needs to be processed.
			void TunnelLifeTime(const unsigned int value); 

			// Optional, Data associated with the policy, up to 32 bytes. The data should be in a network order. The extended data for a policy with a periodic trigger contains first a periodic type and after that the data for that type. For periodic type 0 [Interval - The CIRA connection will be established every fixed number of seconds] - the data should include a uint32 value that indicates the time period in seconds between tunnel establishments. For periodic type 1 [Daily - The CIRA connection will be established every day in a specific pre-defined time (hour and minutes)] - the data should include two uint32 values which define the wanted hour of the day and minutes of that hour. For the other triggers extended data is not defined and not needed. The length and data should be zero.
			void ExtendedData(const Base64 &value); 

			// Required, A list of MPSs the policy applies to. Maximum length is 2 MPSs.
			void MpServer(const vector<CimReference> &value); 

			// Required, A list of Internal MPSs the policy applies to. Maximum length is 2 MPSs.
			void InternalMpServer(const vector<CimReference> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddRemoteAccessPolicyRule
		class CIMFRAMEWORK_API AddRemoteAccessPolicyRule_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddRemoteAccessPolicyRule_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddRemoteAccessPolicyRule_OUTPUT(){}

			// class fields
			// A reference to the created policy if the operation succeeded.
			const CimReference PolicyRule() const;
			bool PolicyRuleExists() const;
		private:
		};

		// Adds a Remote Access policy to the Intel(R) AMT subsystem. The policy defines an event that will trigger an establishment of a tunnel between AMT and a pre-configured MPS. Creates an AMT_RemoteAccessPolicyRule instance and associates it to a given list of AMT_ManagementPresenceRemoteSAP instances with AMT_PolicySetAppliesToElement association instances.
		virtual unsigned int AddRemoteAccessPolicyRule(const AddRemoteAccessPolicyRule_INPUT &input, AddRemoteAccessPolicyRule_OUTPUT &output);

		// Closes a remote access connection if one is opened.
		virtual unsigned int CloseRemoteAccessConnection();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_RemoteAccessService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_RemoteAccessService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_RemoteAccessService(const CimObject &object)
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
#endif // AMT_REMOTEACCESSSERVICE_H
