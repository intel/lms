//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpointCapabilities.h
//
//  Contents:   Describes the capabilities of a WiFiEndpoint.
//
//              This file was automatically generated from CIM_WiFiEndpointCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WIFIENDPOINTCAPABILITIES_H
#define CIM_WIFIENDPOINTCAPABILITIES_H 1
#include "CIM_EnabledLogicalElementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the capabilities of a WiFiEndpoint.
	class CIMFRAMEWORK_API CIM_WiFiEndpointCapabilities  : public CIM_EnabledLogicalElementCapabilities
	{
	public:

		//Default constructor
		CIM_WiFiEndpointCapabilities()
			: CIM_EnabledLogicalElementCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_WiFiEndpointCapabilities(ICimWsmanClient *client)
			: CIM_EnabledLogicalElementCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_WiFiEndpointCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_WiFiEndpointCapabilities keys
		class CimKeys : public CIM_EnabledLogicalElementCapabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The set of IEEE 802.11 encryption methods supported by the associated WifiEndpoint. Shall contain one or more of the values below.
		// 	* Other (1): shall indicate that at least one encryption method not specified in the list below is supported. If SupportedEncryptionMethods contains 1, OtherSupportedEncryptionMethods shall not be NULL and shall not be empty.
		// 	* WEP (2): shall indicate that Wired Equivalency Privacy (WEP) is supported. SupportedEncryptionMethods shall contain 2 only if SupportedAuthenticationMethods contains 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the Temporal Key Integrity Protocol (TKIP) is supported. SupportedEncryptionMethods shall contain 3 only if SupportedAuthenticationMethods contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP) is supported. SupportedEncryptionMethods shall contain 4 only if SupportedAuthenticationMethods contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that the associated WiFiEndpoint supports connecting to a network without encryption. SupportedEncryptionMethods shall contain 5 only if SupportedAuthenticationMethods contains 2 ("Open System") or 3 ("Shared Key").
		const vector<unsigned short> SupportedEncryptionMethods() const;

		// Optional, The set of IEEE 802.11 encryption methods supported by the associated WifiEndpoint. Shall contain one or more of the values below.
		// 	* Other (1): shall indicate that at least one encryption method not specified in the list below is supported. If SupportedEncryptionMethods contains 1, OtherSupportedEncryptionMethods shall not be NULL and shall not be empty.
		// 	* WEP (2): shall indicate that Wired Equivalency Privacy (WEP) is supported. SupportedEncryptionMethods shall contain 2 only if SupportedAuthenticationMethods contains 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the Temporal Key Integrity Protocol (TKIP) is supported. SupportedEncryptionMethods shall contain 3 only if SupportedAuthenticationMethods contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP) is supported. SupportedEncryptionMethods shall contain 4 only if SupportedAuthenticationMethods contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that the associated WiFiEndpoint supports connecting to a network without encryption. SupportedEncryptionMethods shall contain 5 only if SupportedAuthenticationMethods contains 2 ("Open System") or 3 ("Shared Key").
		void SupportedEncryptionMethods(const vector<unsigned short> &value); 

		// Is true if the field SupportedEncryptionMethods exists in the current object, otherwise is false.
		bool SupportedEncryptionMethodsExists() const;

		// Remove SupportedEncryptionMethods field.
		void RemoveSupportedEncryptionMethods(); 

		// Optional, Shall contain additional encryption methods supported by the associated WifiEndpoint, but not listed in the valuemap for SupportedEncryptionMethods. The positions of these strings are the lowest indices of the array, and do not correspond to the positions of the values in SupportedEncryptionMethods.
		const vector<string> OtherSupportedEncryptionMethods() const;

		// Optional, Shall contain additional encryption methods supported by the associated WifiEndpoint, but not listed in the valuemap for SupportedEncryptionMethods. The positions of these strings are the lowest indices of the array, and do not correspond to the positions of the values in SupportedEncryptionMethods.
		void OtherSupportedEncryptionMethods(const vector<string> &value); 

		// Is true if the field OtherSupportedEncryptionMethods exists in the current object, otherwise is false.
		bool OtherSupportedEncryptionMethodsExists() const;

		// Remove OtherSupportedEncryptionMethods field.
		void RemoveOtherSupportedEncryptionMethods(); 

		// Optional, The set of IEEE 802.11 authentication methods supported by the associated WifiEndpoint.	* Other (1): shall indicate that at least one authentication method not specified in the list below is supported. If SupportedAuthenticationMethods contains 1, OtherSupportedAuthenticationMethods shall not be NULL and shall not be empty.
		// 	* Open System (2): shall indicate that Open System authentication is supported. SupportedAuthenticationMethods shall contain 2 only if SupportedEncryptionMethods contains 2 ("WEP") or 5 ("None").
		// 	* Shared Key (3): shall indicate Shared Key authentication is supported. SupportedAuthenticationMethods shall contain 3 only if SupportedEncryptionMethods contains 2 ("WEP") or 5 ("None").
		// 	* WPA PSK (4): shall indicate that WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key) authentication is supported. SupportedAuthenticationMethods shall contain 4 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that WPA (Wi-Fi Protected Access) IEEE 802.1x authentication is supported. SupportedAuthenticationMethods shall contain 5 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key) authentication is supported. SupportedAuthenticationMethods shall contain 6 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicate that WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x authentication is supported. SupportedAuthenticationMethods shall contain 7 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		const vector<unsigned short> SupportedAuthenticationMethods() const;

		// Optional, The set of IEEE 802.11 authentication methods supported by the associated WifiEndpoint.	* Other (1): shall indicate that at least one authentication method not specified in the list below is supported. If SupportedAuthenticationMethods contains 1, OtherSupportedAuthenticationMethods shall not be NULL and shall not be empty.
		// 	* Open System (2): shall indicate that Open System authentication is supported. SupportedAuthenticationMethods shall contain 2 only if SupportedEncryptionMethods contains 2 ("WEP") or 5 ("None").
		// 	* Shared Key (3): shall indicate Shared Key authentication is supported. SupportedAuthenticationMethods shall contain 3 only if SupportedEncryptionMethods contains 2 ("WEP") or 5 ("None").
		// 	* WPA PSK (4): shall indicate that WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key) authentication is supported. SupportedAuthenticationMethods shall contain 4 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that WPA (Wi-Fi Protected Access) IEEE 802.1x authentication is supported. SupportedAuthenticationMethods shall contain 5 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key) authentication is supported. SupportedAuthenticationMethods shall contain 6 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicate that WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x authentication is supported. SupportedAuthenticationMethods shall contain 7 only if SupportedEncryptionMethods contains 3 ("TKIP") or 4 ("CCMP").
		void SupportedAuthenticationMethods(const vector<unsigned short> &value); 

		// Is true if the field SupportedAuthenticationMethods exists in the current object, otherwise is false.
		bool SupportedAuthenticationMethodsExists() const;

		// Remove SupportedAuthenticationMethods field.
		void RemoveSupportedAuthenticationMethods(); 

		// Optional, Shall contain additional authentication methods supported by the associated WifiEndpoint, but not listed in the valuemap for SupportedAuthenticationMethods. The positions of these strings are the lowest indices of the array, and do not correspond to the positions of the values in SupportedAuthenticationMethods.
		const vector<string> OtherSupportedAuthenticationMethods() const;

		// Optional, Shall contain additional authentication methods supported by the associated WifiEndpoint, but not listed in the valuemap for SupportedAuthenticationMethods. The positions of these strings are the lowest indices of the array, and do not correspond to the positions of the values in SupportedAuthenticationMethods.
		void OtherSupportedAuthenticationMethods(const vector<string> &value); 

		// Is true if the field OtherSupportedAuthenticationMethods exists in the current object, otherwise is false.
		bool OtherSupportedAuthenticationMethodsExists() const;

		// Remove OtherSupportedAuthenticationMethods field.
		void RemoveOtherSupportedAuthenticationMethods(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_WiFiEndpointCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_WiFiEndpointCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElementCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_WiFiEndpointCapabilities(const CimObject &object)
			: CIM_EnabledLogicalElementCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElementCapabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // CIM_WIFIENDPOINTCAPABILITIES_H
