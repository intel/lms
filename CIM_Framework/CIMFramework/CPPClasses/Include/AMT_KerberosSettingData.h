//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_KerberosSettingData.h
//
//  Contents:   The AMT_KerberosSettingData class represents configuration-related and operational parameters for the kerberos service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_KerberosSettingData.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_KERBEROSSETTINGDATA_H
#define AMT_KERBEROSSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The AMT_KerberosSettingData class represents configuration-related and operational parameters for the kerberos service in the Intel(R) AMT.
	class CIMFRAMEWORK_API AMT_KerberosSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_KerberosSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}

		//constructor which receives WSMan client
		AMT_KerberosSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}

		//Destructor
		virtual ~AMT_KerberosSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_KerberosSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Kerberos Realm name.
		const string RealmName() const;

		// Optional, Kerberos Realm name.
		void RealmName(const string &value); 

		// Is true if the field RealmName exists in the current object, otherwise is false.
		bool RealmNameExists() const;

		// Remove RealmName field.
		void RemoveRealmName(); 

		// Optional, An array of strings, each of which names a distinct service principal.
		const vector<string> ServicePrincipalName() const;

		// Optional, An array of strings, each of which names a distinct service principal.
		void ServicePrincipalName(const vector<string> &value); 

		// Is true if the field ServicePrincipalName exists in the current object, otherwise is false.
		bool ServicePrincipalNameExists() const;

		// Remove ServicePrincipalName field.
		void RemoveServicePrincipalName(); 

		// Optional, An array of 16-bit enumeration values, each of which corresponds to the string in the same position of ServicePrincipalName.
		const vector<unsigned short> ServicePrincipalProtocol() const;

		// Optional, An array of 16-bit enumeration values, each of which corresponds to the string in the same position of ServicePrincipalName.
		void ServicePrincipalProtocol(const vector<unsigned short> &value); 

		// Is true if the field ServicePrincipalProtocol exists in the current object, otherwise is false.
		bool ServicePrincipalProtocolExists() const;

		// Remove ServicePrincipalProtocol field.
		void RemoveServicePrincipalProtocol(); 

		// Optional, Key version number. User can update the value each time the master key is changed.
		const unsigned int KeyVersion() const;

		// Optional, Key version number. User can update the value each time the master key is changed.
		void KeyVersion(const unsigned int value); 

		// Is true if the field KeyVersion exists in the current object, otherwise is false.
		bool KeyVersionExists() const;

		// Remove KeyVersion field.
		void RemoveKeyVersion(); 

		// Optional, A 16-bit enumeration value that identifiers the encryption algorithm used in Kerberos authentication.
		const unsigned short EncryptionAlgorithm() const;

		// Optional, A 16-bit enumeration value that identifiers the encryption algorithm used in Kerberos authentication.
		void EncryptionAlgorithm(const unsigned short value); 

		// Is true if the field EncryptionAlgorithm exists in the current object, otherwise is false.
		bool EncryptionAlgorithmExists() const;

		// Remove EncryptionAlgorithm field.
		void RemoveEncryptionAlgorithm(); 

		// Optional, A 128-bit binary key value. MasterKey cannot be used if the key generation method is used (using the Passphrase property)
		const Base64 MasterKey() const;

		// Optional, A 128-bit binary key value. MasterKey cannot be used if the key generation method is used (using the Passphrase property)
		void MasterKey(const Base64 &value); 

		// Is true if the field MasterKey exists in the current object, otherwise is false.
		bool MasterKeyExists() const;

		// Remove MasterKey field.
		void RemoveMasterKey(); 

		// Optional, The number of minutes by which the clocks of the Intel(R) AMT device and the client and KDC can be out of sync - typically 5 minutes.
		const unsigned int MaximumClockTolerance() const;

		// Optional, The number of minutes by which the clocks of the Intel(R) AMT device and the client and KDC can be out of sync - typically 5 minutes.
		void MaximumClockTolerance(const unsigned int value); 

		// Is true if the field MaximumClockTolerance exists in the current object, otherwise is false.
		bool MaximumClockToleranceExists() const;

		// Remove MaximumClockTolerance field.
		void RemoveMaximumClockTolerance(); 

		// Required, Indicates whether Kerberos authentication is enabled or disable.
		const bool KrbEnabled() const;

		// Required, Indicates whether Kerberos authentication is enabled or disable.
		void KrbEnabled(const bool value); 

		// Is true if the field KrbEnabled exists in the current object, otherwise is false.
		bool KrbEnabledExists() const;

		// Remove KrbEnabled field.
		void RemoveKrbEnabled(); 

		// Optional, Used when the key generation method is chosen (RFC 3961,3962). Salt and IterationCount must be supplied also.
		const string Passphrase() const;

		// Optional, Used when the key generation method is chosen (RFC 3961,3962). Salt and IterationCount must be supplied also.
		void Passphrase(const string &value); 

		// Is true if the field Passphrase exists in the current object, otherwise is false.
		bool PassphraseExists() const;

		// Remove Passphrase field.
		void RemovePassphrase(); 

		// Optional, Used when the key generation method is chosen (RFC 3961,3962)
		const string Salt() const;

		// Optional, Used when the key generation method is chosen (RFC 3961,3962)
		void Salt(const string &value); 

		// Is true if the field Salt exists in the current object, otherwise is false.
		bool SaltExists() const;

		// Remove Salt field.
		void RemoveSalt(); 

		// Optional, Can be used when the key generation method is chosen (RFC 3961,3962)
		const unsigned int IterationCount() const;

		// Optional, Can be used when the key generation method is chosen (RFC 3961,3962)
		void IterationCount(const unsigned int value); 

		// Is true if the field IterationCount exists in the current object, otherwise is false.
		bool IterationCountExists() const;

		// Remove IterationCount field.
		void RemoveIterationCount(); 

		// Optional, A 16-bit enumeration values that identifier the supported encryption algorithms used in Kerberos authentication.
		const vector<unsigned short> SupportedEncryptionAlgorithms() const;

		// Optional, A 16-bit enumeration values that identifier the supported encryption algorithms used in Kerberos authentication.
		void SupportedEncryptionAlgorithms(const vector<unsigned short> &value); 

		// Is true if the field SupportedEncryptionAlgorithms exists in the current object, otherwise is false.
		bool SupportedEncryptionAlgorithmsExists() const;

		// Remove SupportedEncryptionAlgorithms field.
		void RemoveSupportedEncryptionAlgorithms(); 

		// Optional, A 16-bit enumeration values that identifier the configured encryption algorithms used in Kerberos authentication.
		const vector<unsigned short> ConfiguredEncryptionAlgorithms() const;

		// Optional, A 16-bit enumeration values that identifier the configured encryption algorithms used in Kerberos authentication.
		void ConfiguredEncryptionAlgorithms(const vector<unsigned short> &value); 

		// Is true if the field ConfiguredEncryptionAlgorithms exists in the current object, otherwise is false.
		bool ConfiguredEncryptionAlgorithmsExists() const;

		// Remove ConfiguredEncryptionAlgorithms field.
		void RemoveConfiguredEncryptionAlgorithms(); 

		//Output parameter for function GetCredentialCacheState
		class CIMFRAMEWORK_API GetCredentialCacheState_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetCredentialCacheState_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetCredentialCacheState_OUTPUT(){}

			// class fields
			// Output state of the credential caching functionality
			const bool Enabled() const;
		private:
		};

		// GetCredentialCacheState gets the current state of the credential caching functionality
		virtual unsigned int GetCredentialCacheState(GetCredentialCacheState_OUTPUT &output);

		//Input parameter for function SetCredentialCacheState
		class CIMFRAMEWORK_API SetCredentialCacheState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetCredentialCacheState_INPUT() : CimParam() {}

			// Class Destructor
			~SetCredentialCacheState_INPUT(){}

			// Required, New state of the functionality
			void Enable(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// SetCredentialCacheState enables/disables the credential caching functionality
		virtual unsigned int SetCredentialCacheState(const SetCredentialCacheState_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_KerberosSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_KerberosSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_KerberosSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 13);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 13);
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
#endif // AMT_KERBEROSSETTINGDATA_H
