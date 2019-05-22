//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_8021XProfile.h
//
//  Contents:   This class represents a 802.1X profile in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_8021XProfile.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_8021XPROFILE_H
#define AMT_8021XPROFILE_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class represents a 802.1X profile in the Intel(R) AMT system.
	class CIMFRAMEWORK_API AMT_8021XProfile  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_8021XProfile()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}

		//constructor which receives WSMan client
		AMT_8021XProfile(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}

		//Destructor
		virtual ~AMT_8021XProfile(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_8021XProfile keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, Indicates whether the 802.1x profile is enabled.
		const bool Enabled() const;

		// Required, Indicates whether the 802.1x profile is enabled.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		// Optional, Indicates the activity setting of the 802.1X module in S0 state. The default value for this property is 'true'.
		const bool ActiveInS0() const;

		// Optional, Indicates the activity setting of the 802.1X module in S0 state. The default value for this property is 'true'.
		void ActiveInS0(const bool value); 

		// Is true if the field ActiveInS0 exists in the current object, otherwise is false.
		bool ActiveInS0Exists() const;

		// Remove ActiveInS0 field.
		void RemoveActiveInS0(); 

		// Optional, Identifies the authentication protocol used to authenticate the access requestor to the AAA server.
		const unsigned short AuthenticationProtocol() const;

		// Optional, Identifies the authentication protocol used to authenticate the access requestor to the AAA server.
		void AuthenticationProtocol(const unsigned short value); 

		// Is true if the field AuthenticationProtocol exists in the current object, otherwise is false.
		bool AuthenticationProtocolExists() const;

		// Remove AuthenticationProtocol field.
		void RemoveAuthenticationProtocol(); 

		// Optional, A string presented to the authentication server in 802.1x protocol exchange. The AAA server determines the format of this string. Formats supported by AAA servers include: username@domain.
		const string RoamingIdentity() const;

		// Optional, A string presented to the authentication server in 802.1x protocol exchange. The AAA server determines the format of this string. Formats supported by AAA servers include: username@domain.
		void RoamingIdentity(const string &value); 

		// Is true if the field RoamingIdentity exists in the current object, otherwise is false.
		bool RoamingIdentityExists() const;

		// Remove RoamingIdentity field.
		void RemoveRoamingIdentity(); 

		// Optional, The name compared against the subject name field in the certificate provided by the AAA server. This name is either the full name of the AAA server, in which case ServerCertificateNameComparison is set to "FullName", or it is the domain suffix of the AAA server, in which case ServerCertificateNameComparison is set to "DomainSuffix"
		const string ServerCertificateName() const;

		// Optional, The name compared against the subject name field in the certificate provided by the AAA server. This name is either the full name of the AAA server, in which case ServerCertificateNameComparison is set to "FullName", or it is the domain suffix of the AAA server, in which case ServerCertificateNameComparison is set to "DomainSuffix"
		void ServerCertificateName(const string &value); 

		// Is true if the field ServerCertificateName exists in the current object, otherwise is false.
		bool ServerCertificateNameExists() const;

		// Remove ServerCertificateName field.
		void RemoveServerCertificateName(); 

		// Optional, Determines the comparison algorithm used between the ServerCertificateName value and the subject name field of the certificate presented by the AAA server.
		const unsigned short ServerCertificateNameComparison() const;

		// Optional, Determines the comparison algorithm used between the ServerCertificateName value and the subject name field of the certificate presented by the AAA server.
		void ServerCertificateNameComparison(const unsigned short value); 

		// Is true if the field ServerCertificateNameComparison exists in the current object, otherwise is false.
		bool ServerCertificateNameComparisonExists() const;

		// Remove ServerCertificateNameComparison field.
		void RemoveServerCertificateNameComparison(); 

		// Optional, Within the domain specified by Domain, Identifies the user that is requesting access to the network.
		const string Username() const;

		// Optional, Within the domain specified by Domain, Identifies the user that is requesting access to the network.
		void Username(const string &value); 

		// Is true if the field Username exists in the current object, otherwise is false.
		bool UsernameExists() const;

		// Remove Username field.
		void RemoveUsername(); 

		// Optional, The password associated with the user identified by Username and Domain.
		const string Password() const;

		// Optional, The password associated with the user identified by Username and Domain.
		void Password(const string &value); 

		// Is true if the field Password exists in the current object, otherwise is false.
		bool PasswordExists() const;

		// Remove Password field.
		void RemovePassword(); 

		// Optional, The domain within which Username is unique.
		const string Domain() const;

		// Optional, The domain within which Username is unique.
		void Domain(const string &value); 

		// Is true if the field Domain exists in the current object, otherwise is false.
		bool DomainExists() const;

		// Remove Domain field.
		void RemoveDomain(); 

		// Optional, A credential used by the supplicant and AAA server to establish a mutually authenticated encrypted tunnel for confidential user authentication.
		const Base64 ProtectedAccessCredential() const;

		// Optional, A credential used by the supplicant and AAA server to establish a mutually authenticated encrypted tunnel for confidential user authentication.
		void ProtectedAccessCredential(const Base64 &value); 

		// Is true if the field ProtectedAccessCredential exists in the current object, otherwise is false.
		bool ProtectedAccessCredentialExists() const;

		// Remove ProtectedAccessCredential field.
		void RemoveProtectedAccessCredential(); 

		// Optional, Optional password to extract the PAC (Protected Access Credential)information from the PAC data.
		const string PACPassword() const;

		// Optional, Optional password to extract the PAC (Protected Access Credential)information from the PAC data.
		void PACPassword(const string &value); 

		// Is true if the field PACPassword exists in the current object, otherwise is false.
		bool PACPasswordExists() const;

		// Remove PACPassword field.
		void RemovePACPassword(); 

		// Optional, The client certificate that should be used by the profile.
		const CimReference ClientCertificate() const;

		// Optional, The client certificate that should be used by the profile.
		void ClientCertificate(const CimReference &value); 

		// Is true if the field ClientCertificate exists in the current object, otherwise is false.
		bool ClientCertificateExists() const;

		// Remove ClientCertificate field.
		void RemoveClientCertificate(); 

		// Optional, The trusted root CA that should be used while verifying the server certificate.
		const CimReference ServerCertificateIssuer() const;

		// Optional, The trusted root CA that should be used while verifying the server certificate.
		void ServerCertificateIssuer(const CimReference &value); 

		// Is true if the field ServerCertificateIssuer exists in the current object, otherwise is false.
		bool ServerCertificateIssuerExists() const;

		// Remove ServerCertificateIssuer field.
		void RemoveServerCertificateIssuer(); 

		// Optional, Timeout in seconds, in which the Intel(R) AMT will hold an authenticated 802.1X session. During the defined period, Intel(R) AMT manages the 802.1X negotiation while a PXE boot takes place. After the timeout, control of the negotiation passes to the host. 
		// The maximum value is 86400 seconds (one day).
		// A value of 0 disables the feature. 
		// If this optional value is omitted, Intel(R) AMT sets a default value of 120 seconds.
		const unsigned int PxeTimeout() const;

		// Optional, Timeout in seconds, in which the Intel(R) AMT will hold an authenticated 802.1X session. During the defined period, Intel(R) AMT manages the 802.1X negotiation while a PXE boot takes place. After the timeout, control of the negotiation passes to the host. 
		// The maximum value is 86400 seconds (one day).
		// A value of 0 disables the feature. 
		// If this optional value is omitted, Intel(R) AMT sets a default value of 120 seconds.
		void PxeTimeout(const unsigned int value); 

		// Is true if the field PxeTimeout exists in the current object, otherwise is false.
		bool PxeTimeoutExists() const;

		// Remove PxeTimeout field.
		void RemovePxeTimeout(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_8021XProfile> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_8021XProfile(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_8021XProfile(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 14);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 14);
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
#endif // AMT_8021XPROFILE_H
