//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IEEE8021xSettings.h
//
//  Contents:   IEEE8021xSettings specifies a set of IEEE 802.1x Port-Based Network Access Control settings that can be applied to a ISO OSI layer 2 ProtocolEndpoint.
//
//              This file was automatically generated from CIM_IEEE8021xSettings.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_IEEE8021XSETTINGS_H
#define CIM_IEEE8021XSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// IEEE8021xSettings specifies a set of IEEE 802.1x Port-Based Network Access Control settings that can be applied to a ISO OSI layer 2 ProtocolEndpoint.
	class CIMFRAMEWORK_API CIM_IEEE8021xSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		CIM_IEEE8021xSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_IEEE8021xSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_IEEE8021xSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_IEEE8021xSettings keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, AuthenticationProtocol shall indicate the desired EAP (Extensible Authentication Protocol) type.
		// 	* EAP-TLS (0): shall indicate that the desired EAP type is the Transport Layer Security EAP type specified in RFC 2716. If AuthenticationProtocol contains 0, Username should not be null, ServerCertificateName and ServerCertificateNameComparison may be null or not null, and RoamingIdentity, Password, Domain, ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-TTLS/MSCHAPv2 (1): shall indicate that the desired EAP type is the Tunneled TLS Authentication Protocol EAP type specified in draft-ietf-pppext-eap-ttls, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains 1, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* PEAPv0/EAP-MSCHAPv2 (2): shall indicate that the desired EAP type is the Protected Extensible Authentication Protocol (PEAP) Version 0 EAP type specified in draft-kamath-pppext-peapv0, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains2, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* PEAPv1/EAP-GTC (3): shall indicate that the desired EAP type is the Protected Extensible Authentication Protocol (PEAP) Version 1 EAP type specified in draft-josefsson-pppext-eap-tls-eap, with Generic Token Card (GTC) as the inner authentication method. If AuthenticationProtocol contains 3, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-FAST/MSCHAPv2 (4): shall indicate that the desired EAP type is the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains 4, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		// 	* EAP-FAST/GTC (5): shall indicate that the desired EAP type is the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Generic Token Card (GTC) as the inner authentication method. If AuthenticationProtocol contains 5, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		// 	* EAP-MD5 (6): shall indicate that the desired EAP type is the EAP MD5 authentication method, specified in RFC 3748. If AuthenticationProtocol contains 6, Username and Password should not be null, Domain may be null or not null, and RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-PSK (7): shall indicate that the desired EAP type is the EAP-PSK (Pre-Shared Key) EAP type specified in RFC 4764. If AuthenticationProtocol contains 7, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-SIM (8): shall indicate that the desired EAP type is the Extensible Authentication Protocol Method for Global System for Mobile Communications (GSM) Subscriber Identity Modules (EAP-SIM), specified in RFC 4186. If AuthenticationProtocol contains 8, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-AKA (9): shall indicate that the desired EAP type is the EAP Method for 3rd Generation Authentication and Key Agreement (EAP-AKA), specified in RFC 4187. If AuthenticationProtocol contains 9, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-FAST/TLS (10): shall indicate that the desired EAP type is the Flexible Authentication EAP type specified in IETF RFC 4851, with TLS as the inner authentication method. If AuthenticationProtocol contains 10, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		const unsigned short AuthenticationProtocol() const;

		// Optional, AuthenticationProtocol shall indicate the desired EAP (Extensible Authentication Protocol) type.
		// 	* EAP-TLS (0): shall indicate that the desired EAP type is the Transport Layer Security EAP type specified in RFC 2716. If AuthenticationProtocol contains 0, Username should not be null, ServerCertificateName and ServerCertificateNameComparison may be null or not null, and RoamingIdentity, Password, Domain, ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-TTLS/MSCHAPv2 (1): shall indicate that the desired EAP type is the Tunneled TLS Authentication Protocol EAP type specified in draft-ietf-pppext-eap-ttls, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains 1, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* PEAPv0/EAP-MSCHAPv2 (2): shall indicate that the desired EAP type is the Protected Extensible Authentication Protocol (PEAP) Version 0 EAP type specified in draft-kamath-pppext-peapv0, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains2, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* PEAPv1/EAP-GTC (3): shall indicate that the desired EAP type is the Protected Extensible Authentication Protocol (PEAP) Version 1 EAP type specified in draft-josefsson-pppext-eap-tls-eap, with Generic Token Card (GTC) as the inner authentication method. If AuthenticationProtocol contains 3, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, and Domain may be null or not null, and ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-FAST/MSCHAPv2 (4): shall indicate that the desired EAP type is the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method. If AuthenticationProtocol contains 4, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		// 	* EAP-FAST/GTC (5): shall indicate that the desired EAP type is the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Generic Token Card (GTC) as the inner authentication method. If AuthenticationProtocol contains 5, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		// 	* EAP-MD5 (6): shall indicate that the desired EAP type is the EAP MD5 authentication method, specified in RFC 3748. If AuthenticationProtocol contains 6, Username and Password should not be null, Domain may be null or not null, and RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, PACPassword, and PSK should be null.
		// 	* EAP-PSK (7): shall indicate that the desired EAP type is the EAP-PSK (Pre-Shared Key) EAP type specified in RFC 4764. If AuthenticationProtocol contains 7, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-SIM (8): shall indicate that the desired EAP type is the Extensible Authentication Protocol Method for Global System for Mobile Communications (GSM) Subscriber Identity Modules (EAP-SIM), specified in RFC 4186. If AuthenticationProtocol contains 8, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-AKA (9): shall indicate that the desired EAP type is the EAP Method for 3rd Generation Authentication and Key Agreement (EAP-AKA), specified in RFC 4187. If AuthenticationProtocol contains 9, Username and PSK should not be null, Domain and RoamingIdentity may be null or not null, and Password, ServerCertificateName, ServerCertificateNameComparison, ProtectedAccessCredential, and PACPassword should be null.
		// 	* EAP-FAST/TLS (10): shall indicate that the desired EAP type is the Flexible Authentication EAP type specified in IETF RFC 4851, with TLS as the inner authentication method. If AuthenticationProtocol contains 10, Username and Password should not be null, RoamingIdentity, ServerCertificateName, ServerCertificateNameComparison, Domain, ProtectedAccessCredential, and PACPassword may be null or not null, and PSK should be null.
		void AuthenticationProtocol(const unsigned short value); 

		// Is true if the field AuthenticationProtocol exists in the current object, otherwise is false.
		bool AuthenticationProtocolExists() const;

		// Remove AuthenticationProtocol field.
		void RemoveAuthenticationProtocol(); 

		// Optional, A string presented to the authentication server in 802.1x protocol exchange. The AAA server determines the format of this string. Formats supported by AAA servers include: <domain>\<username>, <username>@<domain>.
		const string RoamingIdentity() const;

		// Optional, A string presented to the authentication server in 802.1x protocol exchange. The AAA server determines the format of this string. Formats supported by AAA servers include: <domain>\<username>, <username>@<domain>.
		void RoamingIdentity(const string &value); 

		// Is true if the field RoamingIdentity exists in the current object, otherwise is false.
		bool RoamingIdentityExists() const;

		// Remove RoamingIdentity field.
		void RemoveRoamingIdentity(); 

		// Optional, The name that shall be compared against the subject name field in the certificate provided by the AAA server. Shall contain either the fully qualified domain name of the AAA server, in which case ServerCertificateNameComparison shall contain "FullName", or the domain suffix of the AAA server, in which case ServerCertificateNameComparison shall contain "DomainSuffix".
		const string ServerCertificateName() const;

		// Optional, The name that shall be compared against the subject name field in the certificate provided by the AAA server. Shall contain either the fully qualified domain name of the AAA server, in which case ServerCertificateNameComparison shall contain "FullName", or the domain suffix of the AAA server, in which case ServerCertificateNameComparison shall contain "DomainSuffix".
		void ServerCertificateName(const string &value); 

		// Is true if the field ServerCertificateName exists in the current object, otherwise is false.
		bool ServerCertificateNameExists() const;

		// Remove ServerCertificateName field.
		void RemoveServerCertificateName(); 

		// Optional, The comparison algorithm that shall be used by the server to validate the subject name field of the certificate presented by the AAA server against the value of the ServerCertificateName property.
		const unsigned short ServerCertificateNameComparison() const;

		// Optional, The comparison algorithm that shall be used by the server to validate the subject name field of the certificate presented by the AAA server against the value of the ServerCertificateName property.
		void ServerCertificateNameComparison(const unsigned short value); 

		// Is true if the field ServerCertificateNameComparison exists in the current object, otherwise is false.
		bool ServerCertificateNameComparisonExists() const;

		// Remove ServerCertificateNameComparison field.
		void RemoveServerCertificateNameComparison(); 

		// Optional, Identifies the user requesting access to the network.
		const string Username() const;

		// Optional, Identifies the user requesting access to the network.
		void Username(const string &value); 

		// Is true if the field Username exists in the current object, otherwise is false.
		bool UsernameExists() const;

		// Remove Username field.
		void RemoveUsername(); 

		// Optional, A password associated with the user identified by Username within Domain.
		const string Password() const;

		// Optional, A password associated with the user identified by Username within Domain.
		void Password(const string &value); 

		// Is true if the field Password exists in the current object, otherwise is false.
		bool PasswordExists() const;

		// Remove Password field.
		void RemovePassword(); 

		// Optional, The domain (also known as realm) within which Username is unique.
		const string Domain() const;

		// Optional, The domain (also known as realm) within which Username is unique.
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

		// Optional, Optional password to extract the PAC (Protected Access Credential) information from the PAC data.
		const string PACPassword() const;

		// Optional, Optional password to extract the PAC (Protected Access Credential) information from the PAC data.
		void PACPassword(const string &value); 

		// Is true if the field PACPassword exists in the current object, otherwise is false.
		bool PACPasswordExists() const;

		// Remove PACPassword field.
		void RemovePACPassword(); 

		// Optional, A pre-shared key used for pre-shared key EAP types such as EAP-PSK, EAP-SIM, and EAP-AKA.
		const Base64 PSK() const;

		// Optional, A pre-shared key used for pre-shared key EAP types such as EAP-PSK, EAP-SIM, and EAP-AKA.
		void PSK(const Base64 &value); 

		// Is true if the field PSK exists in the current object, otherwise is false.
		bool PSKExists() const;

		// Remove PSK field.
		void RemovePSK(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_IEEE8021xSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_IEEE8021xSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_IEEE8021xSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
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
#endif // CIM_IEEE8021XSETTINGS_H
