//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuthorizationService.h
//
//  Contents:   Describes the Authorization Service, which is responsible for Access Control management in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_AuthorizationService.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AUTHORIZATIONSERVICE_H
#define AMT_AUTHORIZATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the Authorization Service, which is responsible for Access Control management in the Intel(R) AMT subsystem.
	class CIMFRAMEWORK_API AMT_AuthorizationService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_AuthorizationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_AuthorizationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_AuthorizationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AuthorizationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Input parameter for function AddUserAclEntryEx
		class CIMFRAMEWORK_API AddUserAclEntryEx_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddUserAclEntryEx_INPUT() : CimParam() {}

			// Class Destructor
			~AddUserAclEntryEx_INPUT(){}

			// Optional, Username for access control. Contains 7-bit ASCII characters. String length is limited to 16 characters. Username cannot be an empty string.
			void DigestUsername(const string &value); 

			// Optional, An MD5 Hash of these parameters concatenated together (Username + ":" + DigestRealm + ":" + Password). The DigestRealm is a field in AMT_GeneralSettings
			void DigestPassword(const Base64 &value); 

			// Optional, Descriptor for user (SID) which is authenticated using the Kerberos Authentication. Byte array, specifying the Security Identifier (SID) according to the Kerberos specification. Current requirements imply that SID should be not smaller than 1 byte length and no longer than 28 bytes. SID length should also be a multiplicand of 4.
			void KerberosUserSid(const Base64 &value); 

			// Required, Indicates whether the User is allowed to access Intel(R) AMT from the Network or Local Interfaces. Note: this definition is restricted by the Default Interface Access Permissions of each Realm.
			// Legal values:
			// LocalAccessPermission: 0
			// NetworkAccessPermission: 1
			// AnyAccessPermission: 2
			void AccessPermission(const unsigned int value); 

			// Required, Array of interface names the ACL entry is allowed to access.
			// Legal values:
			// InvalidRealm: 0
			// ReservedRealm0: 1
			// RedirectionRealm: 2
			// PTAdministrationRealm: 3
			// HardwareAssetRealm: 4
			// RemoteControlRealm: 5
			// StorageRealm: 6
			// EventManagerRealm: 7
			// StorageAdminRealm: 8
			// AgentPresenceLocalRealm: 9
			// AgentPresenceRemoteRealm: 10
			// CircuitBreakerRealm: 11
			// NetworkTimeRealm: 12
			// GeneralInfoRealm: 13
			// FirmwareUpdateRealm: 14
			// EITRealm: 15
			// LocalUN: 16
			// EndpointAccessControlRealm: 17
			// EndpointAccessControlAdminRealm: 18
			// EventLogReaderRealm: 19
			// AuditLogRealm: 20
			// ACLRealm: 21
			// ReservedRealm1: 22
			// ReservedRealm2: 23
			// LocalSystemRealm: 24
			// Reserved: ..
			void Realms(const vector<unsigned int> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddUserAclEntryEx
		class CIMFRAMEWORK_API AddUserAclEntryEx_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddUserAclEntryEx_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddUserAclEntryEx_OUTPUT(){}

			// class fields
			// Contains a creation handle.
			const unsigned int Handle() const;
			bool HandleExists() const;
		private:
		};

		// Adds a user entry to the Intel(R) AMT device.
		virtual unsigned int AddUserAclEntryEx(const AddUserAclEntryEx_INPUT &input, AddUserAclEntryEx_OUTPUT &output);

		//Input parameter for function EnumerateUserAclEntries
		class CIMFRAMEWORK_API EnumerateUserAclEntries_INPUT : public CimParam
		{
		public:
			// Class Constructor
			EnumerateUserAclEntries_INPUT() : CimParam() {}

			// Class Destructor
			~EnumerateUserAclEntries_INPUT(){}

			// Required, Indicates the first ACL entry to retrieve. To enumerate the entire list, an application sends this message with StartIndex set to 1.
			void StartIndex(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function EnumerateUserAclEntries
		class CIMFRAMEWORK_API EnumerateUserAclEntries_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			EnumerateUserAclEntries_OUTPUT() : CimParam() {}

			// Class Destructor
			~EnumerateUserAclEntries_OUTPUT(){}

			// class fields
			// Contains the total number of entries in the User ACL.
			const unsigned int TotalCount() const;
			bool TotalCountExists() const;
			// Contains the number of entries in the returned list.
			const unsigned int HandlesCount() const;
			bool HandlesCountExists() const;
			// Contains a list of HandleCount entry handles.
			const vector<unsigned int> Handles() const;
			bool HandlesExists() const;
		private:
		};

		// Enumerates entries in the User Access Control List (ACL).
		virtual unsigned int EnumerateUserAclEntries(const EnumerateUserAclEntries_INPUT &input, EnumerateUserAclEntries_OUTPUT &output);

		//Input parameter for function GetUserAclEntryEx
		class CIMFRAMEWORK_API GetUserAclEntryEx_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetUserAclEntryEx_INPUT() : CimParam() {}

			// Class Destructor
			~GetUserAclEntryEx_INPUT(){}

			// Required, Specifies the ACL entry to fetch.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetUserAclEntryEx
		class CIMFRAMEWORK_API GetUserAclEntryEx_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetUserAclEntryEx_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetUserAclEntryEx_OUTPUT(){}

			// class fields
			// Username for access control.
			const string DigestUsername() const;
			bool DigestUsernameExists() const;
			// Confidential information, such as password (hash) is omitted from the response.
			const Base64 DigestPassword() const;
			bool DigestPasswordExists() const;
			// Descriptor for user (SID) which is authenticated using the Kerberos Authentication. Byte array, specifying the Security Identifier (SID) according to the Kerberos specification.
			const Base64 KerberosUserSid() const;
			bool KerberosUserSidExists() const;
			// Indicates whether the User is allowed to access Intel(R) AMT from the Network or Local Interfaces. Note: this definition is restricted by the Default Interface Access Permissions of each Realm.
			// Legal values:
			// LocalAccessPermission: 0
			// NetworkAccessPermission: 1
			// AnyAccessPermission: 2
			const unsigned int AccessPermission() const;
			bool AccessPermissionExists() const;
			// Array of interface names the ACL entry is allowed to access.
			// Legal values:
			// InvalidRealm: 0
			// ReservedRealm0: 1
			// RedirectionRealm: 2
			// PTAdministrationRealm: 3
			// HardwareAssetRealm: 4
			// RemoteControlRealm: 5
			// StorageRealm: 6
			// EventManagerRealm: 7
			// StorageAdminRealm: 8
			// AgentPresenceLocalRealm: 9
			// AgentPresenceRemoteRealm: 10
			// CircuitBreakerRealm: 11
			// NetworkTimeRealm: 12
			// GeneralInfoRealm: 13
			// FirmwareUpdateRealm: 14
			// EITRealm: 15
			// LocalUN: 16
			// EndpointAccessControlRealm: 17
			// EndpointAccessControlAdminRealm: 18
			// EventLogReaderRealm: 19
			// AuditLogRealm: 20
			// ACLRealm: 21
			// ReservedRealm1: 22
			// ReservedRealm2: 23
			// LocalSystemRealm: 24
			// Reserved: ..
			const vector<unsigned int> Realms() const;
			bool RealmsExists() const;
		private:
		};

		// Reads a user entry from the Intel(R) AMT device. Note: confidential information, such as password (hash) is omitted or zeroed in the response.
		virtual unsigned int GetUserAclEntryEx(const GetUserAclEntryEx_INPUT &input, GetUserAclEntryEx_OUTPUT &output);

		//Input parameter for function UpdateUserAclEntryEx
		class CIMFRAMEWORK_API UpdateUserAclEntryEx_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdateUserAclEntryEx_INPUT() : CimParam() {}

			// Class Destructor
			~UpdateUserAclEntryEx_INPUT(){}

			// Required, Creation handle to a User ACL entry.
			void Handle(const unsigned int value); 

			// Optional, Username for access control. Contains 7-bit ASCII characters. String length is limited to 16 characters. Username cannot be an empty string.
			void DigestUsername(const string &value); 

			// Optional, An MD5 Hash of these parameters concatenated together (Username + ":" + DigestRealm + ":" + Password). The DigestRealm is a field in AMT_GeneralSettings
			void DigestPassword(const Base64 &value); 

			// Optional, Descriptor for user (SID) which is authenticated using the Kerberos Authentication. Byte array, specifying the Security Identifier (SID) according to the Kerberos specification. Current requirements imply that SID should be not smaller than 1 byte length and no longer than 28 bytes. SID length should also be a multiplicand of 4.
			void KerberosUserSid(const Base64 &value); 

			// Required, Indicates whether the User is allowed to access Intel(R) AMT from the Network or Local Interfaces. Note: this definition is restricted by the Default Interface Access Permissions of each Realm.
			// Legal values:
			// LocalAccessPermission: 0
			// NetworkAccessPermission: 1
			// AnyAccessPermission: 2
			void AccessPermission(const unsigned int value); 

			// Required, Array of interface names the ACL entry is allowed to access.
			// Legal values:
			// InvalidRealm: 0
			// ReservedRealm0: 1
			// RedirectionRealm: 2
			// PTAdministrationRealm: 3
			// HardwareAssetRealm: 4
			// RemoteControlRealm: 5
			// StorageRealm: 6
			// EventManagerRealm: 7
			// StorageAdminRealm: 8
			// AgentPresenceLocalRealm: 9
			// AgentPresenceRemoteRealm: 10
			// CircuitBreakerRealm: 11
			// NetworkTimeRealm: 12
			// GeneralInfoRealm: 13
			// FirmwareUpdateRealm: 14
			// EITRealm: 15
			// LocalUN: 16
			// EndpointAccessControlRealm: 17
			// EndpointAccessControlAdminRealm: 18
			// EventLogReaderRealm: 19
			// AuditLogRealm: 20
			// ACLRealm: 21
			// ReservedRealm1: 22
			// ReservedRealm2: 23
			// LocalSystemRealm: 24
			// Reserved: ..
			void Realms(const vector<unsigned int> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Updates a user entry in the Intel(R) AMT device.
		virtual unsigned int UpdateUserAclEntryEx(const UpdateUserAclEntryEx_INPUT &input);

		//Input parameter for function RemoveUserAclEntry
		class CIMFRAMEWORK_API RemoveUserAclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemoveUserAclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~RemoveUserAclEntry_INPUT(){}

			// Required, Specifies the ACL entry to be removed.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Removes an entry from the User Access Control List (ACL), given a handle.
		virtual unsigned int RemoveUserAclEntry(const RemoveUserAclEntry_INPUT &input);

		//Input parameter for function SetAdminAclEntryEx
		class CIMFRAMEWORK_API SetAdminAclEntryEx_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAdminAclEntryEx_INPUT() : CimParam() {}

			// Class Destructor
			~SetAdminAclEntryEx_INPUT(){}

			// Required, Username for access control. Contains 7-bit ASCII characters. String length is limited to 16 characters. Username cannot be an empty string.
			void Username(const string &value); 

			// Required, An MD5 Hash of these parameters concatenated together (Username + ":" + DigestRealm + ":" + Password). The DigestRealm is a field in AMT_GeneralSettings
			void DigestPassword(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Updates an Admin entry in the Intel(R) AMT device.
		virtual unsigned int SetAdminAclEntryEx(const SetAdminAclEntryEx_INPUT &input);

		//Output parameter for function GetAdminAclEntry
		class CIMFRAMEWORK_API GetAdminAclEntry_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAdminAclEntry_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetAdminAclEntry_OUTPUT(){}

			// class fields
			// Contains the username of the Admin ACL.
			const string Username() const;
			bool UsernameExists() const;
		private:
		};

		// Returns the username attribute of the Admin ACL.
		virtual unsigned int GetAdminAclEntry(GetAdminAclEntry_OUTPUT &output);

		//Output parameter for function GetAdminAclEntryStatus
		class CIMFRAMEWORK_API GetAdminAclEntryStatus_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAdminAclEntryStatus_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetAdminAclEntryStatus_OUTPUT(){}

			// class fields
			// TRUE if the admin ACL entry (admin password) was never changed by the user. Otherwise, the parameter is FALSE.
			const bool IsDefault() const;
			bool IsDefaultExists() const;
		private:
		};

		// Reads the Admin ACL Entry status from Intel(R) AMT. The return state changes as a function of the admin password.
		virtual unsigned int GetAdminAclEntryStatus(GetAdminAclEntryStatus_OUTPUT &output);

		//Output parameter for function GetAdminNetAclEntryStatus
		class CIMFRAMEWORK_API GetAdminNetAclEntryStatus_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAdminNetAclEntryStatus_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetAdminNetAclEntryStatus_OUTPUT(){}

			// class fields
			// TRUE if the remote admin ACL entry (remote admin password) was never changed by the user. Otherwise, the parameter is FALSE.
			const bool IsDefault() const;
			bool IsDefaultExists() const;
		private:
		};

		// Reads the remote Admin ACL Entry status from Intel(R) AMT. The return state changes as a function of the remote admin password.
		virtual unsigned int GetAdminNetAclEntryStatus(GetAdminNetAclEntryStatus_OUTPUT &output);

		//Input parameter for function SetAclEnabledState
		class CIMFRAMEWORK_API SetAclEnabledState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAclEnabledState_INPUT() : CimParam() {}

			// Class Destructor
			~SetAclEnabledState_INPUT(){}

			// Required, Specifies the ACL entry to update
			void Handle(const unsigned int value); 

			// Required, Specifies the state of the ACL entry
			void Enabled(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Enables or disables a user ACL entry.Disabling ACL entries is useful when accounts that cannot be removed (system accounts - starting with $$) are required to be disabled.
		virtual unsigned int SetAclEnabledState(const SetAclEnabledState_INPUT &input);

		//Input parameter for function GetAclEnabledState
		class CIMFRAMEWORK_API GetAclEnabledState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAclEnabledState_INPUT() : CimParam() {}

			// Class Destructor
			~GetAclEnabledState_INPUT(){}

			// Required, Specifies the ACL entry
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetAclEnabledState
		class CIMFRAMEWORK_API GetAclEnabledState_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAclEnabledState_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetAclEnabledState_OUTPUT(){}

			// class fields
			// Specifies the state of the ACL entry
			const bool Enabled() const;
		private:
		};

		// Gets the state of a user ACL entry (enabled/disabled)
		virtual unsigned int GetAclEnabledState(const GetAclEnabledState_INPUT &input, GetAclEnabledState_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AuthorizationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AuthorizationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AuthorizationService(const CimObject &object)
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
#endif // AMT_AUTHORIZATIONSERVICE_H
