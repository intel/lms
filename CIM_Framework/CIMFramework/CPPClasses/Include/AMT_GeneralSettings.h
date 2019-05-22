//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_GeneralSettings.h
//
//  Contents:   This class contains all Intel(R) AMT general settings.
//
//              This file was automatically generated from AMT_GeneralSettings.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_GENERALSETTINGS_H
#define AMT_GENERALSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class contains all Intel(R) AMT general settings.
	class CIMFRAMEWORK_API AMT_GeneralSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_GeneralSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}

		//constructor which receives WSMan client
		AMT_GeneralSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}

		//Destructor
		virtual ~AMT_GeneralSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_GeneralSettings keys
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

		// Optional, Indicates whether the network interface is enabled
		const bool NetworkInterfaceEnabled() const;

		// Optional, Indicates whether the network interface is enabled
		void NetworkInterfaceEnabled(const bool value); 

		// Is true if the field NetworkInterfaceEnabled exists in the current object, otherwise is false.
		bool NetworkInterfaceEnabledExists() const;

		// Remove NetworkInterfaceEnabled field.
		void RemoveNetworkInterfaceEnabled(); 

		// Optional, The Intel(R) AMT device Digest Authentication Realm parameter as defined by RFC 2617.
		const string DigestRealm() const;

		// Optional, The Intel(R) AMT device Digest Authentication Realm parameter as defined by RFC 2617.
		void DigestRealm(const string &value); 

		// Is true if the field DigestRealm exists in the current object, otherwise is false.
		bool DigestRealmExists() const;

		// Remove DigestRealm field.
		void RemoveDigestRealm(); 

		// Optional, Defines the minimum time value, in minutes, that Intel(R) AMT will be powered after waking up from a sleep power state, or after the host enters sleep or off state.This timer value will be reloaded whenever Intel(R) AMT is servicing requests. Note: this setting may not be applicable under some power package definitions.
		const unsigned int IdleWakeTimeout() const;

		// Optional, Defines the minimum time value, in minutes, that Intel(R) AMT will be powered after waking up from a sleep power state, or after the host enters sleep or off state.This timer value will be reloaded whenever Intel(R) AMT is servicing requests. Note: this setting may not be applicable under some power package definitions.
		void IdleWakeTimeout(const unsigned int value); 

		// Is true if the field IdleWakeTimeout exists in the current object, otherwise is false.
		bool IdleWakeTimeoutExists() const;

		// Remove IdleWakeTimeout field.
		void RemoveIdleWakeTimeout(); 

		// Optional, Intel(R) AMT host setting.
		const string HostName() const;

		// Optional, Intel(R) AMT host setting.
		void HostName(const string &value); 

		// Is true if the field HostName exists in the current object, otherwise is false.
		bool HostNameExists() const;

		// Remove HostName field.
		void RemoveHostName(); 

		// Optional, Intel(R) AMT domain name setting.
		const string DomainName() const;

		// Optional, Intel(R) AMT domain name setting.
		void DomainName(const string &value); 

		// Is true if the field DomainName exists in the current object, otherwise is false.
		bool DomainNameExists() const;

		// Remove DomainName field.
		void RemoveDomainName(); 

		// Optional, Indicates whether Intel(R) AMT should respond to ping Echo Request messages.
		const bool PingResponseEnabled() const;

		// Optional, Indicates whether Intel(R) AMT should respond to ping Echo Request messages.
		void PingResponseEnabled(const bool value); 

		// Is true if the field PingResponseEnabled exists in the current object, otherwise is false.
		bool PingResponseEnabledExists() const;

		// Remove PingResponseEnabled field.
		void RemovePingResponseEnabled(); 

		// Optional, Indicates whether Intel(R) AMT should block network interfaces other than WS-Management.
		const bool WsmanOnlyMode() const;

		// Optional, Indicates whether Intel(R) AMT should block network interfaces other than WS-Management.
		void WsmanOnlyMode(const bool value); 

		// Is true if the field WsmanOnlyMode exists in the current object, otherwise is false.
		bool WsmanOnlyModeExists() const;

		// Remove WsmanOnlyMode field.
		void RemoveWsmanOnlyMode(); 

		// Optional, Preferred Address Family (IPv4/IPv6).
		const unsigned int PreferredAddressFamily() const;

		// Optional, Preferred Address Family (IPv4/IPv6).
		void PreferredAddressFamily(const unsigned int value); 

		// Is true if the field PreferredAddressFamily exists in the current object, otherwise is false.
		bool PreferredAddressFamilyExists() const;

		// Remove PreferredAddressFamily field.
		void RemovePreferredAddressFamily(); 

		// Optional, Defines the Maximum Duration (DHCPv6 MRD for the Solicit Message) in seconds during which the Intel(R) ME FW tries to locate a DHCPv6 server. 0 - means try forever. The default value for this property is 0.
		const unsigned short DHCPv6ConfigurationTimeout() const;

		// Optional, Defines the Maximum Duration (DHCPv6 MRD for the Solicit Message) in seconds during which the Intel(R) ME FW tries to locate a DHCPv6 server. 0 - means try forever. The default value for this property is 0.
		void DHCPv6ConfigurationTimeout(const unsigned short value); 

		// Is true if the field DHCPv6ConfigurationTimeout exists in the current object, otherwise is false.
		bool DHCPv6ConfigurationTimeoutExists() const;

		// Remove DHCPv6ConfigurationTimeout field.
		void RemoveDHCPv6ConfigurationTimeout(); 

		// Optional, Defines whether the Dynamic DNS Update Client in FW is enabled or not. (The default value for this property is disabled)
		const bool DDNSUpdateEnabled() const;

		// Optional, Defines whether the Dynamic DNS Update Client in FW is enabled or not. (The default value for this property is disabled)
		void DDNSUpdateEnabled(const bool value); 

		// Is true if the field DDNSUpdateEnabled exists in the current object, otherwise is false.
		bool DDNSUpdateEnabledExists() const;

		// Remove DDNSUpdateEnabled field.
		void RemoveDDNSUpdateEnabled(); 

		// Optional, If the DDNS Update client in FW is  disabled then this property will define whether DDNS Update should be requested from the DHCP Server for the shared IPv4 address and shared FQDN. (The default value for this property is enabled)
		const bool DDNSUpdateByDHCPServerEnabled() const;

		// Optional, If the DDNS Update client in FW is  disabled then this property will define whether DDNS Update should be requested from the DHCP Server for the shared IPv4 address and shared FQDN. (The default value for this property is enabled)
		void DDNSUpdateByDHCPServerEnabled(const bool value); 

		// Is true if the field DDNSUpdateByDHCPServerEnabled exists in the current object, otherwise is false.
		bool DDNSUpdateByDHCPServerEnabledExists() const;

		// Remove DDNSUpdateByDHCPServerEnabled field.
		void RemoveDDNSUpdateByDHCPServerEnabled(); 

		// Optional, Defines Whether the FQDN (HostName.DomainName) is shared with the Host or dedicated to ME. (The default value for this property is shared - TRUE).
		const bool SharedFQDN() const;

		// Optional, Defines Whether the FQDN (HostName.DomainName) is shared with the Host or dedicated to ME. (The default value for this property is shared - TRUE).
		void SharedFQDN(const bool value); 

		// Is true if the field SharedFQDN exists in the current object, otherwise is false.
		bool SharedFQDNExists() const;

		// Remove SharedFQDN field.
		void RemoveSharedFQDN(); 

		// Optional, Intel(R) AMT host OS FQDN. This value of host FQDN is needed for the case that FW is set with a dedicated FQDN - this allows the SW to correlate the FW name with the Host name.
		const string HostOSFQDN() const;

		// Optional, Intel(R) AMT host OS FQDN. This value of host FQDN is needed for the case that FW is set with a dedicated FQDN - this allows the SW to correlate the FW name with the Host name.
		void HostOSFQDN(const string &value); 

		// Is true if the field HostOSFQDN exists in the current object, otherwise is false.
		bool HostOSFQDNExists() const;

		// Remove HostOSFQDN field.
		void RemoveHostOSFQDN(); 

		// Optional, Defines the Time To Live value (cachable time) of RRs registered by the FW DDNSUpdateClient. Units are seconds. (The default value for this property is 15 minutes).
		const unsigned int DDNSTTL() const;

		// Optional, Defines the Time To Live value (cachable time) of RRs registered by the FW DDNSUpdateClient. Units are seconds. (The default value for this property is 15 minutes).
		void DDNSTTL(const unsigned int value); 

		// Is true if the field DDNSTTL exists in the current object, otherwise is false.
		bool DDNSTTLExists() const;

		// Remove DDNSTTL field.
		void RemoveDDNSTTL(); 

		// Optional, When set to Disabled, the AMT OOB network interfaces (LAN and WLAN) are disabled including AMT user initiated applications, Environment Detection and RMCPPing. Since OOB networking is disabled, there will not be an option to enable it back remotely.
		const unsigned int AMTNetworkEnabled() const;

		// Optional, When set to Disabled, the AMT OOB network interfaces (LAN and WLAN) are disabled including AMT user initiated applications, Environment Detection and RMCPPing. Since OOB networking is disabled, there will not be an option to enable it back remotely.
		void AMTNetworkEnabled(const unsigned int value); 

		// Is true if the field AMTNetworkEnabled exists in the current object, otherwise is false.
		bool AMTNetworkEnabledExists() const;

		// Remove AMTNetworkEnabled field.
		void RemoveAMTNetworkEnabled(); 

		// Optional, Indicates whether Intel(R) AMT should respond to RMCP ping Echo Request messages.
		const bool RmcpPingResponseEnabled() const;

		// Optional, Indicates whether Intel(R) AMT should respond to RMCP ping Echo Request messages.
		void RmcpPingResponseEnabled(const bool value); 

		// Is true if the field RmcpPingResponseEnabled exists in the current object, otherwise is false.
		bool RmcpPingResponseEnabledExists() const;

		// Remove RmcpPingResponseEnabled field.
		void RemoveRmcpPingResponseEnabled(); 

		// Optional, Defines the interval at which the FW DDNS Update client will send periodic updates for all the RRs registered by FW. Should be set according to corporate DNS scavenging policy. Units are minutes. Can be : either 0, or 20 and over. A value of 0 disables periodic update. (The default value for this property is 24 hours - 1440 minutes).
		const unsigned int DDNSPeriodicUpdateInterval() const;

		// Optional, Defines the interval at which the FW DDNS Update client will send periodic updates for all the RRs registered by FW. Should be set according to corporate DNS scavenging policy. Units are minutes. Can be : either 0, or 20 and over. A value of 0 disables periodic update. (The default value for this property is 24 hours - 1440 minutes).
		void DDNSPeriodicUpdateInterval(const unsigned int value); 

		// Is true if the field DDNSPeriodicUpdateInterval exists in the current object, otherwise is false.
		bool DDNSPeriodicUpdateIntervalExists() const;

		// Remove DDNSPeriodicUpdateInterval field.
		void RemoveDDNSPeriodicUpdateInterval(); 

		// Optional, Defines the interval at which the FW will send periodic WS-management events notifications (for the subscribed clients) whenever network settings are changed. Units are minutes. A value of 0 disables periodic events. The default value for this property is 0 (notifications are disabled). The minimal allowed value is 15 minutes.
		const unsigned int PresenceNotificationInterval() const;

		// Optional, Defines the interval at which the FW will send periodic WS-management events notifications (for the subscribed clients) whenever network settings are changed. Units are minutes. A value of 0 disables periodic events. The default value for this property is 0 (notifications are disabled). The minimal allowed value is 15 minutes.
		void PresenceNotificationInterval(const unsigned int value); 

		// Is true if the field PresenceNotificationInterval exists in the current object, otherwise is false.
		bool PresenceNotificationIntervalExists() const;

		// Remove PresenceNotificationInterval field.
		void RemovePresenceNotificationInterval(); 

		// Optional, Defines the Privacy Level setting.Privacy Level defines the values for privacy-related parameters by default and upon ME-unconfigure event.The setting can have the following values: 
		// Default: 
		// SOL enabled = true, IDER enabled = true, KVM enabled = true, Opt-in can be disabled =  true, opt-in configurable remotely = true. 
		// Enhanced: 
		// SOL enabled = true, IDER enabled = true, KVM enabled = true, Opt-in can be disabled =  false, opt-in configurable remotely = true. 
		// Extreme:  
		// SOL enabled = false, IDER enabled = false, KVM enabled = false, Opt-in can be disabled =  false, opt-in configurable remotely = false. 
		const unsigned int PrivacyLevel() const;

		// Optional, Defines the Privacy Level setting.Privacy Level defines the values for privacy-related parameters by default and upon ME-unconfigure event.The setting can have the following values: 
		// Default: 
		// SOL enabled = true, IDER enabled = true, KVM enabled = true, Opt-in can be disabled =  true, opt-in configurable remotely = true. 
		// Enhanced: 
		// SOL enabled = true, IDER enabled = true, KVM enabled = true, Opt-in can be disabled =  false, opt-in configurable remotely = true. 
		// Extreme:  
		// SOL enabled = false, IDER enabled = false, KVM enabled = false, Opt-in can be disabled =  false, opt-in configurable remotely = false. 
		void PrivacyLevel(const unsigned int value); 

		// Is true if the field PrivacyLevel exists in the current object, otherwise is false.
		bool PrivacyLevelExists() const;

		// Remove PrivacyLevel field.
		void RemovePrivacyLevel(); 

		// Optional, The system current power source
		const unsigned int PowerSource() const;

		// Optional, The system current power source
		void PowerSource(const unsigned int value); 

		// Is true if the field PowerSource exists in the current object, otherwise is false.
		bool PowerSourceExists() const;

		// Remove PowerSource field.
		void RemovePowerSource(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_GeneralSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_GeneralSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_GeneralSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 21);
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
#endif // AMT_GENERALSETTINGS_H
