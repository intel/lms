//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpointSettings.h
//
//  Contents:   CIM_WiFiEndpointSettings describes setting data that can be applied to an instance of CIM_WiFiEndpoint to enable it to associate to a particular Wi-Fi network.
//
//              This file was automatically generated from CIM_WiFiEndpointSettings.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WIFIENDPOINTSETTINGS_H
#define CIM_WIFIENDPOINTSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_WiFiEndpointSettings describes setting data that can be applied to an instance of CIM_WiFiEndpoint to enable it to associate to a particular Wi-Fi network.
	class CIMFRAMEWORK_API CIM_WiFiEndpointSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		CIM_WiFiEndpointSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		CIM_WiFiEndpointSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~CIM_WiFiEndpointSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_WiFiEndpointSettings keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Priority shall indicate the priority of the instance among all WiFiEndpointSettings instances.
		const unsigned char Priority() const;

		// Optional, Priority shall indicate the priority of the instance among all WiFiEndpointSettings instances.
		void Priority(const unsigned char &value); 

		// Is true if the field Priority exists in the current object, otherwise is false.
		bool PriorityExists() const;

		// Remove Priority field.
		void RemovePriority(); 

		// Optional, SSID shall indicate the Service Set Identifier (SSID) that shall be used when the settings are applied to a WiFiEndpoint. An SSID identifies a wireless network.
		const string SSID() const;

		// Optional, SSID shall indicate the Service Set Identifier (SSID) that shall be used when the settings are applied to a WiFiEndpoint. An SSID identifies a wireless network.
		void SSID(const string &value); 

		// Is true if the field SSID exists in the current object, otherwise is false.
		bool SSIDExists() const;

		// Remove SSID field.
		void RemoveSSID(); 

		// Optional, BSSType shall indicate the Basic Service Set (BSS) Type that shall be used when the settings are applied. A Basic Service Set is a set of stations controlled by a single coordination function.
		// 	* Independent: the WiFiEndpoint is associated directly to another client station.
		// 	* Infrastructure: the WiFiEndpoint is associated to a network via an access point.
		const unsigned short BSSType() const;

		// Optional, BSSType shall indicate the Basic Service Set (BSS) Type that shall be used when the settings are applied. A Basic Service Set is a set of stations controlled by a single coordination function.
		// 	* Independent: the WiFiEndpoint is associated directly to another client station.
		// 	* Infrastructure: the WiFiEndpoint is associated to a network via an access point.
		void BSSType(const unsigned short value); 

		// Is true if the field BSSType exists in the current object, otherwise is false.
		bool BSSTypeExists() const;

		// Remove BSSType field.
		void RemoveBSSType(); 

		// Optional, EncryptionMethod shall specify the 802.11 encryption method used when the settings are applied. 	* Other (1): shall indicate that the desired encryption method is not specified in the list below. If this value is used, OtherEncryptionMethod should not be NULL and should not be empty.
		// 	* WEP (2): shall indicate that the desired encryption method is Wired Equivalency Privacy (WEP). This value should be used only if AuthenticationMethod contains 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the desired encryption method is Temporal Key Integrity Protocol (TKIP). This value should be used only if AuthenticationMethod contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the desired encryption method is Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP). This value should be used only if AuthenticationMethod contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that no encryption is desired. This value should be used only if AuthenticationMethod contains 2 ("Open System") or 3 ("Shared Key").
		const unsigned short EncryptionMethod() const;

		// Optional, EncryptionMethod shall specify the 802.11 encryption method used when the settings are applied. 	* Other (1): shall indicate that the desired encryption method is not specified in the list below. If this value is used, OtherEncryptionMethod should not be NULL and should not be empty.
		// 	* WEP (2): shall indicate that the desired encryption method is Wired Equivalency Privacy (WEP). This value should be used only if AuthenticationMethod contains 2 ("Open System") or 3 ("Shared Key").
		// 	* TKIP (3): shall indicate that the desired encryption method is Temporal Key Integrity Protocol (TKIP). This value should be used only if AuthenticationMethod contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* CCMP (4): shall indicate that the desired encryption method is Counter Mode with Cipher Block Chaining Message Authentication Code Protocol (CCMP). This value should be used only if AuthenticationMethod contains 4 ("WPA PSK"), 5 ("WPA IEEE 802.1x"), 6 ("WPA2 PSK"), or 7 ("WPA2 IEEE 802.1x").
		// 	* None (5): shall indicate that no encryption is desired. This value should be used only if AuthenticationMethod contains 2 ("Open System") or 3 ("Shared Key").
		void EncryptionMethod(const unsigned short value); 

		// Is true if the field EncryptionMethod exists in the current object, otherwise is false.
		bool EncryptionMethodExists() const;

		// Remove EncryptionMethod field.
		void RemoveEncryptionMethod(); 

		// Optional, OtherEncryptionMethod shall specify the 802.11 encryption method used when the settings are applied if and only if EncryptionMethod contains "Other". The format of this string shall be vendor-specific.
		const string OtherEncryptionMethod() const;

		// Optional, OtherEncryptionMethod shall specify the 802.11 encryption method used when the settings are applied if and only if EncryptionMethod contains "Other". The format of this string shall be vendor-specific.
		void OtherEncryptionMethod(const string &value); 

		// Is true if the field OtherEncryptionMethod exists in the current object, otherwise is false.
		bool OtherEncryptionMethodExists() const;

		// Remove OtherEncryptionMethod field.
		void RemoveOtherEncryptionMethod(); 

		// Optional, AuthenticationMethod shall specify the 802.11 authentication method used when the settings are applied. 	* Other (1): shall indicate that the desired authentication method is not specified in the list below. If AuthenticationMethod contains 1, OtherAuthenticationMethod should not be NULL and should not be empty.
		// 	* Open System (2): shall indicate that the desired authentication method is Open System. AuthenticationMethod should contain 2 only if EncryptionMethod contains 2 ("WEP") or 5 ("None").
		// 	* Shared Key (3): shall indicate that the desired authentication method is Shared Key. AuthenticationMethod should contain 3 only if EncryptionMethod contains 2 ("WEP") or 5 ("None").
		// 	* WPA PSK (4): shall indicate that the desired authentication method is WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key). AuthenticationMethod should contain 4 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that the desired authentication method is WPA (Wi-Fi Protected Access) IEEE 802.1x. AuthenticationMethod should contain 5 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that the desired authentication method is WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key). AuthenticationMethod should containt 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicated that the desired authentication method is WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x. AuthenticationMethod should contain 7 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		const unsigned short AuthenticationMethod() const;

		// Optional, AuthenticationMethod shall specify the 802.11 authentication method used when the settings are applied. 	* Other (1): shall indicate that the desired authentication method is not specified in the list below. If AuthenticationMethod contains 1, OtherAuthenticationMethod should not be NULL and should not be empty.
		// 	* Open System (2): shall indicate that the desired authentication method is Open System. AuthenticationMethod should contain 2 only if EncryptionMethod contains 2 ("WEP") or 5 ("None").
		// 	* Shared Key (3): shall indicate that the desired authentication method is Shared Key. AuthenticationMethod should contain 3 only if EncryptionMethod contains 2 ("WEP") or 5 ("None").
		// 	* WPA PSK (4): shall indicate that the desired authentication method is WPA (Wi-Fi Protected Access) PSK (Pre-Shared Key). AuthenticationMethod should contain 4 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA IEEE 802.1x (5): shall indicate that the desired authentication method is WPA (Wi-Fi Protected Access) IEEE 802.1x. AuthenticationMethod should contain 5 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 PSK (6): shall indicate that the desired authentication method is WPA2 (Wi-Fi Protected Access Version 2) PSK (Pre-Shared Key). AuthenticationMethod should containt 6 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		// 	* WPA2 IEEE 802.1x (7): shall indicated that the desired authentication method is WPA2 (Wi-Fi Protected Access Version 2) IEEE 802.1x. AuthenticationMethod should contain 7 only if EncryptionMethod contains 3 ("TKIP") or 4 ("CCMP").
		void AuthenticationMethod(const unsigned short value); 

		// Is true if the field AuthenticationMethod exists in the current object, otherwise is false.
		bool AuthenticationMethodExists() const;

		// Remove AuthenticationMethod field.
		void RemoveAuthenticationMethod(); 

		// Optional, OtherAuthenticationMethod shall specify the 802.11 authentication method used when the settings are applied if and only if AuthenticationMethod contains "Other". The format of this string shall be vendor-specific.
		const string OtherAuthenticationMethod() const;

		// Optional, OtherAuthenticationMethod shall specify the 802.11 authentication method used when the settings are applied if and only if AuthenticationMethod contains "Other". The format of this string shall be vendor-specific.
		void OtherAuthenticationMethod(const string &value); 

		// Is true if the field OtherAuthenticationMethod exists in the current object, otherwise is false.
		bool OtherAuthenticationMethodExists() const;

		// Remove OtherAuthenticationMethod field.
		void RemoveOtherAuthenticationMethod(); 

		// Optional, Keys shall contain the default WEP encryption keys. Keys should be non-NULL if and only if EncryptionMethod contains 2 ("WEP").
		const vector<HexBinary> Keys() const;

		// Optional, Keys shall contain the default WEP encryption keys. Keys should be non-NULL if and only if EncryptionMethod contains 2 ("WEP").
		void Keys(const vector<HexBinary> &value); 

		// Is true if the field Keys exists in the current object, otherwise is false.
		bool KeysExists() const;

		// Remove Keys field.
		void RemoveKeys(); 

		// Optional, KeyIndex shall contain the index of the active key in the Keys array property. KeyIndex should be non-NULL if and only Keys is non-NULL.
		const unsigned char KeyIndex() const;

		// Optional, KeyIndex shall contain the index of the active key in the Keys array property. KeyIndex should be non-NULL if and only Keys is non-NULL.
		void KeyIndex(const unsigned char &value); 

		// Is true if the field KeyIndex exists in the current object, otherwise is false.
		bool KeyIndexExists() const;

		// Remove KeyIndex field.
		void RemoveKeyIndex(); 

		// Optional, The actual binary value of a PSK (pre-shared key). PSKValue and PSKPassPhrase should not both be non-NULL. PSKValue should be NULL if AuthenticationMethod does not contain 4 ("WPA PSK") or 6 ("WPA2 PSK").
		const Base64 PSKValue() const;

		// Optional, The actual binary value of a PSK (pre-shared key). PSKValue and PSKPassPhrase should not both be non-NULL. PSKValue should be NULL if AuthenticationMethod does not contain 4 ("WPA PSK") or 6 ("WPA2 PSK").
		void PSKValue(const Base64 &value); 

		// Is true if the field PSKValue exists in the current object, otherwise is false.
		bool PSKValueExists() const;

		// Remove PSKValue field.
		void RemovePSKValue(); 

		// Optional, An ASCII alphanumeric string used to generate a PSK (pre-shared key). PSKPassPhrase and PSKValue should not both be non-NULL. PSKPassPhrase should be NULL if AuthenticationMethod does not contain 4 ("WPA PSK") or 6 ("WPA2 PSK").
		const string PSKPassPhrase() const;

		// Optional, An ASCII alphanumeric string used to generate a PSK (pre-shared key). PSKPassPhrase and PSKValue should not both be non-NULL. PSKPassPhrase should be NULL if AuthenticationMethod does not contain 4 ("WPA PSK") or 6 ("WPA2 PSK").
		void PSKPassPhrase(const string &value); 

		// Is true if the field PSKPassPhrase exists in the current object, otherwise is false.
		bool PSKPassPhraseExists() const;

		// Remove PSKPassPhrase field.
		void RemovePSKPassPhrase(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_WiFiEndpointSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_WiFiEndpointSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_WiFiEndpointSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 11);
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
#endif // CIM_WIFIENDPOINTSETTINGS_H
