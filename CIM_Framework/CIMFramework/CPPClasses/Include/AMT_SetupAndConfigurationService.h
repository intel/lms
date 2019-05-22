//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SetupAndConfigurationService.h
//
//  Contents:   Describes the Setup and Configuration Service, which is the logic in Intel(R) AMT that responds to Setup and Configuration requests.
//
//              This file was automatically generated from AMT_SetupAndConfigurationService.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_SETUPANDCONFIGURATIONSERVICE_H
#define AMT_SETUPANDCONFIGURATIONSERVICE_H 1
#include "CIM_CredentialManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the Setup and Configuration Service, which is the logic in Intel(R) AMT that responds to Setup and Configuration requests.
	class CIMFRAMEWORK_API AMT_SetupAndConfigurationService  : public CIM_CredentialManagementService
	{
	public:

		//Default constructor
		AMT_SetupAndConfigurationService()
			: CIM_CredentialManagementService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CredentialManagementService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		AMT_SetupAndConfigurationService(ICimWsmanClient *client)
			: CIM_CredentialManagementService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CredentialManagementService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~AMT_SetupAndConfigurationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_SetupAndConfigurationService keys
		class CimKeys : public CIM_CredentialManagementService::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A Read-Only enumeration value that determines the behavior of Intel(R) AMT when it is deployed. Starting from Release 7.0, this enumeration indicates whether AMT is deployed in "Admin control mode" or "Client control mode". In "Admin" mode, AMT functionality is on the same level of previous releases. In "Client" mode fucntionality is limited or requires user consent.
		const unsigned char ProvisioningMode() const;

		// Optional, A Read-Only enumeration value that determines the behavior of Intel(R) AMT when it is deployed. Starting from Release 7.0, this enumeration indicates whether AMT is deployed in "Admin control mode" or "Client control mode". In "Admin" mode, AMT functionality is on the same level of previous releases. In "Client" mode fucntionality is limited or requires user consent.
		void ProvisioningMode(const unsigned char &value); 

		// Is true if the field ProvisioningMode exists in the current object, otherwise is false.
		bool ProvisioningModeExists() const;

		// Remove ProvisioningMode field.
		void RemoveProvisioningMode(); 

		// Optional, An enumeration value that indicates the state of the Intel(R) AMT subsystem in the provisioning process"Pre" - the setup operation has not started."In" - the setup operation is in progress."Post" - Intel(R) AMT is configured.
		const unsigned char ProvisioningState() const;

		// Optional, An enumeration value that indicates the state of the Intel(R) AMT subsystem in the provisioning process"Pre" - the setup operation has not started."In" - the setup operation is in progress."Post" - Intel(R) AMT is configured.
		void ProvisioningState(const unsigned char &value); 

		// Is true if the field ProvisioningState exists in the current object, otherwise is false.
		bool ProvisioningStateExists() const;

		// Remove ProvisioningState field.
		void RemoveProvisioningState(); 

		// Optional, Indicates if Zero Touch Configuration (Remote Configuration) is enabled or disabled. This property affects only enterprise mode. It can be modified while in SMB mode
		const bool ZeroTouchConfigurationEnabled() const;

		// Optional, Indicates if Zero Touch Configuration (Remote Configuration) is enabled or disabled. This property affects only enterprise mode. It can be modified while in SMB mode
		void ZeroTouchConfigurationEnabled(const bool value); 

		// Is true if the field ZeroTouchConfigurationEnabled exists in the current object, otherwise is false.
		bool ZeroTouchConfigurationEnabledExists() const;

		// Remove ZeroTouchConfigurationEnabled field.
		void RemoveZeroTouchConfigurationEnabled(); 

		// Optional, A optional binary data value containing 8-32 characters,that represents a one-time password (OTP), used to authenticate the Intel(R) AMT to the configuration server. This property can be retrieved only in IN Provisioning state, nevertheless, it is settable also in POST provisioning state.
		const Base64 ProvisioningServerOTP() const;

		// Optional, A optional binary data value containing 8-32 characters,that represents a one-time password (OTP), used to authenticate the Intel(R) AMT to the configuration server. This property can be retrieved only in IN Provisioning state, nevertheless, it is settable also in POST provisioning state.
		void ProvisioningServerOTP(const Base64 &value); 

		// Is true if the field ProvisioningServerOTP exists in the current object, otherwise is false.
		bool ProvisioningServerOTPExists() const;

		// Remove ProvisioningServerOTP field.
		void RemoveProvisioningServerOTP(); 

		// Optional, The FQDN of the configuration server.
		const string ConfigurationServerFQDN() const;

		// Optional, The FQDN of the configuration server.
		void ConfigurationServerFQDN(const string &value); 

		// Is true if the field ConfigurationServerFQDN exists in the current object, otherwise is false.
		bool ConfigurationServerFQDNExists() const;

		// Remove ConfigurationServerFQDN field.
		void RemoveConfigurationServerFQDN(); 

		// Optional, An enumeration value that determines the password model of Intel(R) AMT.
		const unsigned char PasswordModel() const;

		// Optional, An enumeration value that determines the password model of Intel(R) AMT.
		void PasswordModel(const unsigned char &value); 

		// Is true if the field PasswordModel exists in the current object, otherwise is false.
		bool PasswordModelExists() const;

		// Remove PasswordModel field.
		void RemovePasswordModel(); 

		// Commits pending configuration commands made to the Intel(R) AMT device. Completes configuration when in "IN-provisioning" state
		virtual unsigned int CommitChanges();

		//Input parameter for function Unprovision
		class CIMFRAMEWORK_API Unprovision_INPUT : public CimParam
		{
		public:
			// Class Constructor
			Unprovision_INPUT() : CimParam() {}

			// Class Destructor
			~Unprovision_INPUT(){}

			// Optional, Indicates the provisioning mode (Enterprise , Small Business or Remote Connectivity) the device will enter following successful completion of the command. Starting from Release 6.0 only effective value is ProvisioningModeEnterprise
			// Legal values:
			// ProvisioningModeCurrent: 0
			// ProvisioningModeEnterprise: 1
			// ProvisioningModeSmallBusiness: 2
			// ProvisioningRemoteConnectivity: 3
			void ProvisioningMode(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Resets the Intel(R) AMT device to default factory settings. The device will need to be re-provisioned after this command.
		virtual unsigned int Unprovision(const Unprovision_INPUT &input);

		// Transfers Intel(R) AMT into a partially-unprovisioned state: Except for configuration settings required for the next provisioning: Admin ACL settings, TLS-PSK keys, Host & Domain name, and provisioning server IP and port number, settings will be restored to factory defaults. The device will need to be re-provisioned after this command.
		virtual unsigned int PartialUnprovision();

		//Input parameter for function ExtendProvisioningPeriod
		class CIMFRAMEWORK_API ExtendProvisioningPeriod_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ExtendProvisioningPeriod_INPUT() : CimParam() {}

			// Class Destructor
			~ExtendProvisioningPeriod_INPUT(){}

			// Optional, The extension duration in hours (limited to maximum value of 24 in each call).
			void Duration(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method allows a configuration server to extend the configuration time, in which Intel(R) AMT is expected to be provisioned. If a configuration server does not call this command before the provisioning period expires, Intel(R) AMT will close the network interface.
		virtual unsigned int ExtendProvisioningPeriod(const ExtendProvisioningPeriod_INPUT &input);

		//Input parameter for function SetMEBxPassword
		class CIMFRAMEWORK_API SetMEBxPassword_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetMEBxPassword_INPUT() : CimParam() {}

			// Class Destructor
			~SetMEBxPassword_INPUT(){}

			// Optional, Password needs to be strong: Contain at least one of: upper-case, lower-case, digit and special character
			void Password(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method sets the ME Bios extension password. It allows a remote caller to change the ME access password for the BIOS extension screen. This call succeeds depending on the password policy rule defined in MEBx (BIOS extension):"Default Password Only" - Method succeeds only when the current password is still the default value and only in PKI provisioning. "During Setup and Configuration" - Method succeeds only during provisioning, regardless of provisioning method or previous password value."ANYTIME" - Method will always succeed. (i.e. even when configured)
		virtual unsigned int SetMEBxPassword(const SetMEBxPassword_INPUT &input);

		//Output parameter for function GetUuid
		class CIMFRAMEWORK_API GetUuid_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetUuid_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetUuid_OUTPUT(){}

			// class fields
			// UUID of the system. If the value is all FFh, the ID is not currently present in the system, but is settable. If the value is all 00h, the ID is not present in the system. Corresponds to the UUID field of the SMBIOS Type 1 structure
			const Base64 UUID() const;
			bool UUIDExists() const;
		private:
		};

		// This method returns the Universal Unique ID of the platform (UUID).
		virtual unsigned int GetUuid(GetUuid_OUTPUT &output);

		//Output parameter for function GetUnprovisionBlockingComponents
		class CIMFRAMEWORK_API GetUnprovisionBlockingComponents_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetUnprovisionBlockingComponents_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetUnprovisionBlockingComponents_OUTPUT(){}

			// class fields
			// components that caused the last unprovisioning (full or partial) request to fail
			// Legal values:
			// COMPONENT_AUDIT_LOG: 1
			// Reserved: 2..65535
			const vector<unsigned int> Component() const;
		private:
		};

		// This command returns the components that caused the last unprovisioning (full or partial) request to fail with the PT_STATUS_BLOCKING_COMPONENT error.
		virtual unsigned int GetUnprovisionBlockingComponents(GetUnprovisionBlockingComponents_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_SetupAndConfigurationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_SetupAndConfigurationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_CredentialManagementService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CredentialManagementService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_SetupAndConfigurationService(const CimObject &object)
			: CIM_CredentialManagementService(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_CredentialManagementService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_CredentialManagementService::SetMetaData(childMetaData);
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
#endif // AMT_SETUPANDCONFIGURATIONSERVICE_H
