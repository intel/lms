//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpoint.h
//
//  Contents:   A wireless communication endpoint which, when its associated interface device is associated with an IEEE 802.11 wireless LAN, may send and receive data frames.
//
//              This file was automatically generated from CIM_WiFiEndpoint.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WIFIENDPOINT_H
#define CIM_WIFIENDPOINT_H 1
#include "CIM_LANEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A wireless communication endpoint which, when its associated interface device is associated with an IEEE 802.11 wireless LAN, may send and receive data frames.
	class CIMFRAMEWORK_API CIM_WiFiEndpoint  : public CIM_LANEndpoint
	{
	public:

		//Default constructor
		CIM_WiFiEndpoint()
			: CIM_LANEndpoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LANEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_WiFiEndpoint(ICimWsmanClient *client)
			: CIM_LANEndpoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LANEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_WiFiEndpoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_WiFiEndpoint keys
		class CimKeys : public CIM_LANEndpoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, EncryptionMethod shall specify the encryption method in use to protect the confidentiality of data sent and received by the WiFiEndpoint.
		// 	* Unknown (0): shall indicate that the encryption method is unknown to the server.
		// 	* Other (1): shall indicate that the encryption method is known to the server but not defined in the list below. If EncryptionMethod contains 1, OtherEncryptionMethod shall not be NULL and shall not be empty.
		// 	* WEP (2): shall indicate that the encryption method is Wired Equivalency Privacy (WEP). The value of EncryptionMethod shall be 2 only if the value of AuthenticationMethod is 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the encryption method is Temporal Key Integrity Protocol (TKIP). The value of EncryptionMethod shall be 3 only if the value of AuthenticationMethod is 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the encryption method is Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP). The value of EncryptionMethod shall be 4 only if the value of AuthenticationMethod is 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that no encryption method is in use. The value of EncryptionMethod shall be 5 only if the value of AuthenticationMethod is 2 ("Open System") or 3 ("Shared Key").
		const unsigned short EncryptionMethod() const;

		// Optional, EncryptionMethod shall specify the encryption method in use to protect the confidentiality of data sent and received by the WiFiEndpoint.
		// 	* Unknown (0): shall indicate that the encryption method is unknown to the server.
		// 	* Other (1): shall indicate that the encryption method is known to the server but not defined in the list below. If EncryptionMethod contains 1, OtherEncryptionMethod shall not be NULL and shall not be empty.
		// 	* WEP (2): shall indicate that the encryption method is Wired Equivalency Privacy (WEP). The value of EncryptionMethod shall be 2 only if the value of AuthenticationMethod is 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the encryption method is Temporal Key Integrity Protocol (TKIP). The value of EncryptionMethod shall be 3 only if the value of AuthenticationMethod is 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the encryption method is Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP). The value of EncryptionMethod shall be 4 only if the value of AuthenticationMethod is 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that no encryption method is in use. The value of EncryptionMethod shall be 5 only if the value of AuthenticationMethod is 2 ("Open System") or 3 ("Shared Key").
		void EncryptionMethod(const unsigned short value); 

		// Is true if the field EncryptionMethod exists in the current object, otherwise is false.
		bool EncryptionMethodExists() const;

		// Remove EncryptionMethod field.
		void RemoveEncryptionMethod(); 

		// Optional, OtherEncryptionMethod shall specify the 802.11 encryption method if and only if EncryptionMethod contains "Other". The format of this string shall be vendor-specific.
		const string OtherEncryptionMethod() const;

		// Optional, OtherEncryptionMethod shall specify the 802.11 encryption method if and only if EncryptionMethod contains "Other". The format of this string shall be vendor-specific.
		void OtherEncryptionMethod(const string &value); 

		// Is true if the field OtherEncryptionMethod exists in the current object, otherwise is false.
		bool OtherEncryptionMethodExists() const;

		// Remove OtherEncryptionMethod field.
		void RemoveOtherEncryptionMethod(); 

		// Optional, AuthenticationMethod shall specify the method used to authenticate the WiFiEndpoint and the network to one another.
		// 	* Unknown (0): shall indicate that the authentication method is unknown to the server.	* Other (1): shall indicate that the authentication method is known to the server but not specified in the list below. If AuthenticationMethod contains 1, OtherAuthenticationMethod shall not be NULL and shall not be empty.
		// 	* Open System (2): shall indicate that the authentication method is Open System. AuthenticationMethod shall contain 2 only if EncryptionMethod contains 2 ("WEP").
		// 	* Shared Key (3): shall indicate that the authentication method is Shared Key. AuthenticationMethod shall contain 3 only if EncryptionMethod contains 2 ("WEP").
		// 	* WPA PSK (4): shall indicate that the authentication method is WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key). AuthenticationMethod shall contain 4 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that the authentication method is WPA (Wi-Fi Protected Access) IEEE 802.1x. AuthenticationMethod shall contain 5 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that the authentication method is WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key). AuthenticationMethod shall contain 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicate that the authentication method is WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x. AuthenticationMethod shall contain 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* CCKM IEEE 802.1x (8): CCKM (Cisco Centralized Key Management with LEAP or EAP-FAST)
		const unsigned short AuthenticationMethod() const;

		// Optional, AuthenticationMethod shall specify the method used to authenticate the WiFiEndpoint and the network to one another.
		// 	* Unknown (0): shall indicate that the authentication method is unknown to the server.	* Other (1): shall indicate that the authentication method is known to the server but not specified in the list below. If AuthenticationMethod contains 1, OtherAuthenticationMethod shall not be NULL and shall not be empty.
		// 	* Open System (2): shall indicate that the authentication method is Open System. AuthenticationMethod shall contain 2 only if EncryptionMethod contains 2 ("WEP").
		// 	* Shared Key (3): shall indicate that the authentication method is Shared Key. AuthenticationMethod shall contain 3 only if EncryptionMethod contains 2 ("WEP").
		// 	* WPA PSK (4): shall indicate that the authentication method is WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key). AuthenticationMethod shall contain 4 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that the authentication method is WPA (Wi-Fi Protected Access) IEEE 802.1x. AuthenticationMethod shall contain 5 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that the authentication method is WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key). AuthenticationMethod shall contain 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicate that the authentication method is WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x. AuthenticationMethod shall contain 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* CCKM IEEE 802.1x (8): CCKM (Cisco Centralized Key Management with LEAP or EAP-FAST)
		void AuthenticationMethod(const unsigned short value); 

		// Is true if the field AuthenticationMethod exists in the current object, otherwise is false.
		bool AuthenticationMethodExists() const;

		// Remove AuthenticationMethod field.
		void RemoveAuthenticationMethod(); 

		// Optional, OtherAuthenticationMethod shall specify the 802.11 authentication method if and only if AuthenticationMethod contains "Other". The format of this string shall be vendor-specific.
		const string OtherAuthenticationMethod() const;

		// Optional, OtherAuthenticationMethod shall specify the 802.11 authentication method if and only if AuthenticationMethod contains "Other". The format of this string shall be vendor-specific.
		void OtherAuthenticationMethod(const string &value); 

		// Is true if the field OtherAuthenticationMethod exists in the current object, otherwise is false.
		bool OtherAuthenticationMethodExists() const;

		// Remove OtherAuthenticationMethod field.
		void RemoveOtherAuthenticationMethod(); 

		// Optional, IEEE8021xAuthenticationProtocol shall contain the EAP (Extensible Authentication Protocol) type if and only if AuthenticationMethod contains "WPA IEEE 802.1x" or "WPA2 IEEE 802.1x" or "CCKM IEEE 802.1x"
		// .	* EAP-TLS (0): shall indicate the Transport Layer Security EAP type specified in RFC 2716.
		// 	* EAP-TTLS/MSCHAPv2 (1): shall indicate the Tunneled TLS Authentication Protocol EAP type (specified in draft-ietf-pppext-eap-ttls) with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* PEAPv0/EAP-MSCHAPv2 (2): shall indicate the Protected Extensible Authentication Protocol (PEAP) Version 0 EAP type (specified in draft-kamath-pppext-peapv0), with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* PEAPv1/EAP-GTC (3): shall indicate the Protected Extensible Authentication Protocol (PEAP) Version 1 EAP type (specified in draft-josefsson-pppext-eap-tls-eap), with Generic Token Card (GTC) as the inner authentication method.
		// 	* EAP-FAST/MSCHAPv2 (4): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* EAP-FAST/GTC (5): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Generic Token Card (GTC) as the inner authentication method.
		// 	* EAP-MD5 (6): shall indicate the EAP MD5 authentication method, specified in RFC 3748.
		// 	* EAP-PSK (7): shall indicate the EAP-PSK (Pre-shared Key) Protocol specified in RFC 4764.
		// 	* EAP-SIM (8): shall indicate the Extensible Authentication Protocol Method for Global System for Mobile Communications (GSM) Subscriber Identity Modules (EAP-SIM), specified in RFC 4186.
		// 	* EAP-AKA (9): shall indicate the Extensible Authentication Protocol Method for 3rd Generation Authentication and Key Agreement (EAP-AKA) authentication method, specified in RFC 4187.
		// 	* EAP-FAST/TLS (10): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with TLS as the inner authentication method.
		const unsigned short IEEE8021xAuthenticationProtocol() const;

		// Optional, IEEE8021xAuthenticationProtocol shall contain the EAP (Extensible Authentication Protocol) type if and only if AuthenticationMethod contains "WPA IEEE 802.1x" or "WPA2 IEEE 802.1x" or "CCKM IEEE 802.1x"
		// .	* EAP-TLS (0): shall indicate the Transport Layer Security EAP type specified in RFC 2716.
		// 	* EAP-TTLS/MSCHAPv2 (1): shall indicate the Tunneled TLS Authentication Protocol EAP type (specified in draft-ietf-pppext-eap-ttls) with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* PEAPv0/EAP-MSCHAPv2 (2): shall indicate the Protected Extensible Authentication Protocol (PEAP) Version 0 EAP type (specified in draft-kamath-pppext-peapv0), with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* PEAPv1/EAP-GTC (3): shall indicate the Protected Extensible Authentication Protocol (PEAP) Version 1 EAP type (specified in draft-josefsson-pppext-eap-tls-eap), with Generic Token Card (GTC) as the inner authentication method.
		// 	* EAP-FAST/MSCHAPv2 (4): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Microsoft PPP CHAP Extensions, Version 2 (MSCHAPv2) as the inner authentication method.
		// 	* EAP-FAST/GTC (5): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with Generic Token Card (GTC) as the inner authentication method.
		// 	* EAP-MD5 (6): shall indicate the EAP MD5 authentication method, specified in RFC 3748.
		// 	* EAP-PSK (7): shall indicate the EAP-PSK (Pre-shared Key) Protocol specified in RFC 4764.
		// 	* EAP-SIM (8): shall indicate the Extensible Authentication Protocol Method for Global System for Mobile Communications (GSM) Subscriber Identity Modules (EAP-SIM), specified in RFC 4186.
		// 	* EAP-AKA (9): shall indicate the Extensible Authentication Protocol Method for 3rd Generation Authentication and Key Agreement (EAP-AKA) authentication method, specified in RFC 4187.
		// 	* EAP-FAST/TLS (10): shall indicate the Flexible Authentication Extensible Authentication Protocol EAP type specified in IETF RFC 4851, with TLS as the inner authentication method.
		void IEEE8021xAuthenticationProtocol(const unsigned short value); 

		// Is true if the field IEEE8021xAuthenticationProtocol exists in the current object, otherwise is false.
		bool IEEE8021xAuthenticationProtocolExists() const;

		// Remove IEEE8021xAuthenticationProtocol field.
		void RemoveIEEE8021xAuthenticationProtocol(); 

		// Optional, AccessPointAddress shall contain the MAC address of the access point with which the WiFiEndpoint is currently associated. If the WiFiEndpoint is not currently associated, then AccessPointAddress shall be NULL.The MAC address shall be formatted as twelve hexadecimal digits (for example, "010203040506"), with each pair representing one of the six octets of the MAC address in "canonical" bit order. (Therefore, the Group address bit is found in the low order bit of the first character of the string.)
		const string AccessPointAddress() const;

		// Optional, AccessPointAddress shall contain the MAC address of the access point with which the WiFiEndpoint is currently associated. If the WiFiEndpoint is not currently associated, then AccessPointAddress shall be NULL.The MAC address shall be formatted as twelve hexadecimal digits (for example, "010203040506"), with each pair representing one of the six octets of the MAC address in "canonical" bit order. (Therefore, the Group address bit is found in the low order bit of the first character of the string.)
		void AccessPointAddress(const string &value); 

		// Is true if the field AccessPointAddress exists in the current object, otherwise is false.
		bool AccessPointAddressExists() const;

		// Remove AccessPointAddress field.
		void RemoveAccessPointAddress(); 

		// Optional, BSSType shall indicate the Basic Service Set (BSS) Type of the network that corresponds to the instance. A Basic Service Set is a set of stations controlled by a single coordination function.
		// 	* Independent: the WiFiEndpoint is associated directly to another client station.
		// 	* Infrastructure: the WiFiEndpoint is associated to a network via an access point.
		const unsigned short BSSType() const;

		// Optional, BSSType shall indicate the Basic Service Set (BSS) Type of the network that corresponds to the instance. A Basic Service Set is a set of stations controlled by a single coordination function.
		// 	* Independent: the WiFiEndpoint is associated directly to another client station.
		// 	* Infrastructure: the WiFiEndpoint is associated to a network via an access point.
		void BSSType(const unsigned short value); 

		// Is true if the field BSSType exists in the current object, otherwise is false.
		bool BSSTypeExists() const;

		// Remove BSSType field.
		void RemoveBSSType(); 

		// Optional, Associated shall indicate whether or not the WiFiEndpoint is currently associated to an access point or client station.
		const bool Associated() const;

		// Optional, Associated shall indicate whether or not the WiFiEndpoint is currently associated to an access point or client station.
		void Associated(const bool value); 

		// Is true if the field Associated exists in the current object, otherwise is false.
		bool AssociatedExists() const;

		// Remove Associated field.
		void RemoveAssociated(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_WiFiEndpoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_WiFiEndpoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LANEndpoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LANEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_WiFiEndpoint(const CimObject &object)
			: CIM_LANEndpoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LANEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LANEndpoint::SetMetaData(childMetaData);
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
#endif // CIM_WIFIENDPOINT_H
