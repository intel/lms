//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EthernetPortSettings.h
//
//  Contents:   This class contains all Intel(R) AMT specific settings (IP, DHCP, VLAN) for one network interface in the system.
//
//              This file was automatically generated from AMT_EthernetPortSettings.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ETHERNETPORTSETTINGS_H
#define AMT_ETHERNETPORTSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class contains all Intel(R) AMT specific settings (IP, DHCP, VLAN) for one network interface in the system.
	class CIMFRAMEWORK_API AMT_EthernetPortSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_EthernetPortSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//constructor which receives WSMan client
		AMT_EthernetPortSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//Destructor
		virtual ~AMT_EthernetPortSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_EthernetPortSettings keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, Indicates whether VLAN is in use and what is the VLAN tag when used.
		const unsigned short VLANTag() const;

		// Optional, Indicates whether VLAN is in use and what is the VLAN tag when used.
		void VLANTag(const unsigned short value); 

		// Is true if the field VLANTag exists in the current object, otherwise is false.
		bool VLANTagExists() const;

		// Remove VLANTag field.
		void RemoveVLANTag(); 

		// Optional, Indicates whether Intel(R) AMT shares it's MAC address with the host system.
		const bool SharedMAC() const;

		// Optional, Indicates whether Intel(R) AMT shares it's MAC address with the host system.
		void SharedMAC(const bool value); 

		// Is true if the field SharedMAC exists in the current object, otherwise is false.
		bool SharedMACExists() const;

		// Remove SharedMAC field.
		void RemoveSharedMAC(); 

		// Optional, The MAC address used by Intel(R) AMT in a string format. For Example: 01-02-3f-b0-99-99. (This property can only be read and can't be changed.)
		const string MACAddress() const;

		// Optional, The MAC address used by Intel(R) AMT in a string format. For Example: 01-02-3f-b0-99-99. (This property can only be read and can't be changed.)
		void MACAddress(const string &value); 

		// Is true if the field MACAddress exists in the current object, otherwise is false.
		bool MACAddressExists() const;

		// Remove MACAddress field.
		void RemoveMACAddress(); 

		// Optional, Indicates whether the network link is up
		const bool LinkIsUp() const;

		// Optional, Indicates whether the network link is up
		void LinkIsUp(const bool value); 

		// Is true if the field LinkIsUp exists in the current object, otherwise is false.
		bool LinkIsUpExists() const;

		// Remove LinkIsUp field.
		void RemoveLinkIsUp(); 

		// Optional, Enumeration values for link policy restrictions for better power consumption. If Intel(R) AMT will not be able to determine the exact power state, the more restrictive closest configuration applies.
		const vector<unsigned char> LinkPolicy() const;

		// Optional, Enumeration values for link policy restrictions for better power consumption. If Intel(R) AMT will not be able to determine the exact power state, the more restrictive closest configuration applies.
		void LinkPolicy(const vector<unsigned char> &value); 

		// Is true if the field LinkPolicy exists in the current object, otherwise is false.
		bool LinkPolicyExists() const;

		// Remove LinkPolicy field.
		void RemoveLinkPolicy(); 

		// Optional, Determines whether the link is preferred to be owned by ME or host
		const unsigned int LinkPreference() const;

		// Optional, Determines whether the link is preferred to be owned by ME or host
		void LinkPreference(const unsigned int value); 

		// Is true if the field LinkPreference exists in the current object, otherwise is false.
		bool LinkPreferenceExists() const;

		// Remove LinkPreference field.
		void RemoveLinkPreference(); 

		// Optional, Determines whether the link is owned by ME or host
		const unsigned int LinkControl() const;

		// Optional, Determines whether the link is owned by ME or host
		void LinkControl(const unsigned int value); 

		// Is true if the field LinkControl exists in the current object, otherwise is false.
		bool LinkControlExists() const;

		// Remove LinkControl field.
		void RemoveLinkControl(); 

		// Optional, Indicates whether the static host IP is shared with ME.
		const bool SharedStaticIp() const;

		// Optional, Indicates whether the static host IP is shared with ME.
		void SharedStaticIp(const bool value); 

		// Is true if the field SharedStaticIp exists in the current object, otherwise is false.
		bool SharedStaticIpExists() const;

		// Remove SharedStaticIp field.
		void RemoveSharedStaticIp(); 

		// Optional, Indicates whether the dynamic host IP is shared with ME.
		const bool SharedDynamicIP() const;

		// Optional, Indicates whether the dynamic host IP is shared with ME.
		void SharedDynamicIP(const bool value); 

		// Is true if the field SharedDynamicIP exists in the current object, otherwise is false.
		bool SharedDynamicIPExists() const;

		// Remove SharedDynamicIP field.
		void RemoveSharedDynamicIP(); 

		// Optional, Indicates whether the IP synchronization between host and ME is enabled.
		const bool IpSyncEnabled() const;

		// Optional, Indicates whether the IP synchronization between host and ME is enabled.
		void IpSyncEnabled(const bool value); 

		// Is true if the field IpSyncEnabled exists in the current object, otherwise is false.
		bool IpSyncEnabledExists() const;

		// Remove IpSyncEnabled field.
		void RemoveIpSyncEnabled(); 

		// Optional, Indicates whether DHCP is in use.
		const bool DHCPEnabled() const;

		// Optional, Indicates whether DHCP is in use.
		void DHCPEnabled(const bool value); 

		// Is true if the field DHCPEnabled exists in the current object, otherwise is false.
		bool DHCPEnabledExists() const;

		// Remove DHCPEnabled field.
		void RemoveDHCPEnabled(); 

		// Optional, String representation of IP address. Get operation - reports the acquired IP address (whether in static or DHCP mode). Put operation - sets the IP address (in static mode only).
		const string IPAddress() const;

		// Optional, String representation of IP address. Get operation - reports the acquired IP address (whether in static or DHCP mode). Put operation - sets the IP address (in static mode only).
		void IPAddress(const string &value); 

		// Is true if the field IPAddress exists in the current object, otherwise is false.
		bool IPAddressExists() const;

		// Remove IPAddress field.
		void RemoveIPAddress(); 

		// Optional, Subnet mask in a string format.For example: 255.255.0.0
		const string SubnetMask() const;

		// Optional, Subnet mask in a string format.For example: 255.255.0.0
		void SubnetMask(const string &value); 

		// Is true if the field SubnetMask exists in the current object, otherwise is false.
		bool SubnetMaskExists() const;

		// Remove SubnetMask field.
		void RemoveSubnetMask(); 

		// Optional, Default Gateway in a string format. For example: 10.12.232.1
		const string DefaultGateway() const;

		// Optional, Default Gateway in a string format. For example: 10.12.232.1
		void DefaultGateway(const string &value); 

		// Is true if the field DefaultGateway exists in the current object, otherwise is false.
		bool DefaultGatewayExists() const;

		// Remove DefaultGateway field.
		void RemoveDefaultGateway(); 

		// Optional, Primary DNS in a string format. For example: 10.12.232.1
		const string PrimaryDNS() const;

		// Optional, Primary DNS in a string format. For example: 10.12.232.1
		void PrimaryDNS(const string &value); 

		// Is true if the field PrimaryDNS exists in the current object, otherwise is false.
		bool PrimaryDNSExists() const;

		// Remove PrimaryDNS field.
		void RemovePrimaryDNS(); 

		// Optional, Secondary DNS in a string format. For example: 10.12.232.1
		const string SecondaryDNS() const;

		// Optional, Secondary DNS in a string format. For example: 10.12.232.1
		void SecondaryDNS(const string &value); 

		// Is true if the field SecondaryDNS exists in the current object, otherwise is false.
		bool SecondaryDNSExists() const;

		// Remove SecondaryDNS field.
		void RemoveSecondaryDNS(); 

		// Optional, Indicates the number of retransmissions host TCP SW tries ifno ack is accepted
		const unsigned int ConsoleTcpMaxRetransmissions() const;

		// Optional, Indicates the number of retransmissions host TCP SW tries ifno ack is accepted
		void ConsoleTcpMaxRetransmissions(const unsigned int value); 

		// Is true if the field ConsoleTcpMaxRetransmissions exists in the current object, otherwise is false.
		bool ConsoleTcpMaxRetransmissionsExists() const;

		// Remove ConsoleTcpMaxRetransmissions field.
		void RemoveConsoleTcpMaxRetransmissions(); 

		// Optional, Defines the level of the link protection feature activation. Read only property.
		const unsigned int WLANLinkProtectionLevel() const;

		// Optional, Defines the level of the link protection feature activation. Read only property.
		void WLANLinkProtectionLevel(const unsigned int value); 

		// Is true if the field WLANLinkProtectionLevel exists in the current object, otherwise is false.
		bool WLANLinkProtectionLevelExists() const;

		// Remove WLANLinkProtectionLevel field.
		void RemoveWLANLinkProtectionLevel(); 

		//Input parameter for function SetLinkPreference
		class CIMFRAMEWORK_API SetLinkPreference_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetLinkPreference_INPUT() : CimParam() {}

			// Class Destructor
			~SetLinkPreference_INPUT(){}

			// Required, The link preference which will be applied to the ethernet port - either ME or host
			// Legal values:
			// ME: 1
			// HOST: 2
			// Reserved: 3..
			void LinkPreference(const unsigned int value); 

			// Optional, The timeout (in seconds) after which the link preference return back to Host.Valid only when LinkPreference is 1 (ME).
			// Legal values:
			// Timeout value in seconds: 1..65535
			void Timeout(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Defines the link preferred owner entity
		virtual unsigned int SetLinkPreference(const SetLinkPreference_INPUT &input);

		// Used to cancel WLAN LP. When this API is called the Link Protection set by the MC (using the SetLinkPreference() API) is canceled. In addition, ME applications get the request to cancel LP and determine according to their policies whether to do so or not. AMT redirection applications will all cancel Link Protection when this API is called.This API can cancel Link Protection for a maximum of one hour. Once this time expires Link Protection will be restored if still needed by an ME application.
		virtual unsigned int CancelLinkProtection();

		// Used to restore Link Protection if previously canceled by calling CancelLinkProtection(). If there is no redirection session open or if link protection is already set, this API will do nothing. If there is a redirection session open, it will get a notification that Link Protection is requested to be restored and it will restore Link Protection. Each redirection application will cancel its own link protection when the session ends.
		virtual unsigned int RestoreLinkProtection();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_EthernetPortSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_EthernetPortSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_EthernetPortSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 19);
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
#endif // AMT_ETHERNETPORTSETTINGS_H
