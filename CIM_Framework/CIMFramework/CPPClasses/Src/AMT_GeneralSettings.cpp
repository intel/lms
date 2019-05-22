//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_GeneralSettings.cpp
//
//  Contents:   This class contains all Intel(R) AMT general settings.
//
//              This file was automatically generated from AMT_GeneralSettings.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "AMT_GeneralSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_GeneralSettings::_metadata[] = {
		{"InstanceID", true, false, false },
		{"NetworkInterfaceEnabled", false, false, false },
		{"DigestRealm", false, false, false },
		{"IdleWakeTimeout", false, false, false },
		{"HostName", false, false, false },
		{"DomainName", false, false, false },
		{"PingResponseEnabled", false, false, false },
		{"WsmanOnlyMode", false, false, false },
		{"PreferredAddressFamily", false, false, false },
		{"DHCPv6ConfigurationTimeout", false, false, false },
		{"DDNSUpdateEnabled", false, false, false },
		{"DDNSUpdateByDHCPServerEnabled", false, false, false },
		{"SharedFQDN", false, false, false },
		{"HostOSFQDN", false, false, false },
		{"DDNSTTL", false, false, false },
		{"AMTNetworkEnabled", false, false, false },
		{"RmcpPingResponseEnabled", false, false, false },
		{"DDNSPeriodicUpdateInterval", false, false, false },
		{"PresenceNotificationInterval", false, false, false },
		{"PrivacyLevel", false, false, false },
		{"PowerSource", false, false, false },
	};
	// class fields
	const bool AMT_GeneralSettings::NetworkInterfaceEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("NetworkInterfaceEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::NetworkInterfaceEnabled(const bool value)
	{
		SetOrAddField("NetworkInterfaceEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::NetworkInterfaceEnabledExists() const
	{
		return ContainsField("NetworkInterfaceEnabled");
	}
	void AMT_GeneralSettings::RemoveNetworkInterfaceEnabled()
	{
		RemoveField("NetworkInterfaceEnabled");
	}

	const string AMT_GeneralSettings::DigestRealm() const
	{
		return GetField("DigestRealm")[0];
	}
	void AMT_GeneralSettings::DigestRealm(const string &value)
	{
		SetOrAddField("DigestRealm", value);
	}
	bool AMT_GeneralSettings::DigestRealmExists() const
	{
		return ContainsField("DigestRealm");
	}
	void AMT_GeneralSettings::RemoveDigestRealm()
	{
		RemoveField("DigestRealm");
	}

	const unsigned int AMT_GeneralSettings::IdleWakeTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("IdleWakeTimeout"), ret);
		return ret;
	}
	void AMT_GeneralSettings::IdleWakeTimeout(const unsigned int value)
	{
		SetOrAddField("IdleWakeTimeout", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::IdleWakeTimeoutExists() const
	{
		return ContainsField("IdleWakeTimeout");
	}
	void AMT_GeneralSettings::RemoveIdleWakeTimeout()
	{
		RemoveField("IdleWakeTimeout");
	}

	const string AMT_GeneralSettings::HostName() const
	{
		return GetField("HostName")[0];
	}
	void AMT_GeneralSettings::HostName(const string &value)
	{
		SetOrAddField("HostName", value);
	}
	bool AMT_GeneralSettings::HostNameExists() const
	{
		return ContainsField("HostName");
	}
	void AMT_GeneralSettings::RemoveHostName()
	{
		RemoveField("HostName");
	}

	const string AMT_GeneralSettings::DomainName() const
	{
		return GetField("DomainName")[0];
	}
	void AMT_GeneralSettings::DomainName(const string &value)
	{
		SetOrAddField("DomainName", value);
	}
	bool AMT_GeneralSettings::DomainNameExists() const
	{
		return ContainsField("DomainName");
	}
	void AMT_GeneralSettings::RemoveDomainName()
	{
		RemoveField("DomainName");
	}

	const bool AMT_GeneralSettings::PingResponseEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PingResponseEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::PingResponseEnabled(const bool value)
	{
		SetOrAddField("PingResponseEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::PingResponseEnabledExists() const
	{
		return ContainsField("PingResponseEnabled");
	}
	void AMT_GeneralSettings::RemovePingResponseEnabled()
	{
		RemoveField("PingResponseEnabled");
	}

	const bool AMT_GeneralSettings::WsmanOnlyMode() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("WsmanOnlyMode"), ret);
		return ret;
	}
	void AMT_GeneralSettings::WsmanOnlyMode(const bool value)
	{
		SetOrAddField("WsmanOnlyMode", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::WsmanOnlyModeExists() const
	{
		return ContainsField("WsmanOnlyMode");
	}
	void AMT_GeneralSettings::RemoveWsmanOnlyMode()
	{
		RemoveField("WsmanOnlyMode");
	}

	const unsigned int AMT_GeneralSettings::PreferredAddressFamily() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PreferredAddressFamily"), ret);
		return ret;
	}
	void AMT_GeneralSettings::PreferredAddressFamily(const unsigned int value)
	{
		SetOrAddField("PreferredAddressFamily", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::PreferredAddressFamilyExists() const
	{
		return ContainsField("PreferredAddressFamily");
	}
	void AMT_GeneralSettings::RemovePreferredAddressFamily()
	{
		RemoveField("PreferredAddressFamily");
	}

	const unsigned short AMT_GeneralSettings::DHCPv6ConfigurationTimeout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DHCPv6ConfigurationTimeout"), ret);
		return ret;
	}
	void AMT_GeneralSettings::DHCPv6ConfigurationTimeout(const unsigned short value)
	{
		SetOrAddField("DHCPv6ConfigurationTimeout", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::DHCPv6ConfigurationTimeoutExists() const
	{
		return ContainsField("DHCPv6ConfigurationTimeout");
	}
	void AMT_GeneralSettings::RemoveDHCPv6ConfigurationTimeout()
	{
		RemoveField("DHCPv6ConfigurationTimeout");
	}

	const bool AMT_GeneralSettings::DDNSUpdateEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DDNSUpdateEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::DDNSUpdateEnabled(const bool value)
	{
		SetOrAddField("DDNSUpdateEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::DDNSUpdateEnabledExists() const
	{
		return ContainsField("DDNSUpdateEnabled");
	}
	void AMT_GeneralSettings::RemoveDDNSUpdateEnabled()
	{
		RemoveField("DDNSUpdateEnabled");
	}

	const bool AMT_GeneralSettings::DDNSUpdateByDHCPServerEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DDNSUpdateByDHCPServerEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::DDNSUpdateByDHCPServerEnabled(const bool value)
	{
		SetOrAddField("DDNSUpdateByDHCPServerEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::DDNSUpdateByDHCPServerEnabledExists() const
	{
		return ContainsField("DDNSUpdateByDHCPServerEnabled");
	}
	void AMT_GeneralSettings::RemoveDDNSUpdateByDHCPServerEnabled()
	{
		RemoveField("DDNSUpdateByDHCPServerEnabled");
	}

	const bool AMT_GeneralSettings::SharedFQDN() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SharedFQDN"), ret);
		return ret;
	}
	void AMT_GeneralSettings::SharedFQDN(const bool value)
	{
		SetOrAddField("SharedFQDN", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::SharedFQDNExists() const
	{
		return ContainsField("SharedFQDN");
	}
	void AMT_GeneralSettings::RemoveSharedFQDN()
	{
		RemoveField("SharedFQDN");
	}

	const string AMT_GeneralSettings::HostOSFQDN() const
	{
		return GetField("HostOSFQDN")[0];
	}
	void AMT_GeneralSettings::HostOSFQDN(const string &value)
	{
		SetOrAddField("HostOSFQDN", value);
	}
	bool AMT_GeneralSettings::HostOSFQDNExists() const
	{
		return ContainsField("HostOSFQDN");
	}
	void AMT_GeneralSettings::RemoveHostOSFQDN()
	{
		RemoveField("HostOSFQDN");
	}

	const unsigned int AMT_GeneralSettings::DDNSTTL() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("DDNSTTL"), ret);
		return ret;
	}
	void AMT_GeneralSettings::DDNSTTL(const unsigned int value)
	{
		SetOrAddField("DDNSTTL", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::DDNSTTLExists() const
	{
		return ContainsField("DDNSTTL");
	}
	void AMT_GeneralSettings::RemoveDDNSTTL()
	{
		RemoveField("DDNSTTL");
	}

	const unsigned int AMT_GeneralSettings::AMTNetworkEnabled() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AMTNetworkEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::AMTNetworkEnabled(const unsigned int value)
	{
		SetOrAddField("AMTNetworkEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::AMTNetworkEnabledExists() const
	{
		return ContainsField("AMTNetworkEnabled");
	}
	void AMT_GeneralSettings::RemoveAMTNetworkEnabled()
	{
		RemoveField("AMTNetworkEnabled");
	}

	const bool AMT_GeneralSettings::RmcpPingResponseEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RmcpPingResponseEnabled"), ret);
		return ret;
	}
	void AMT_GeneralSettings::RmcpPingResponseEnabled(const bool value)
	{
		SetOrAddField("RmcpPingResponseEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::RmcpPingResponseEnabledExists() const
	{
		return ContainsField("RmcpPingResponseEnabled");
	}
	void AMT_GeneralSettings::RemoveRmcpPingResponseEnabled()
	{
		RemoveField("RmcpPingResponseEnabled");
	}

	const unsigned int AMT_GeneralSettings::DDNSPeriodicUpdateInterval() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("DDNSPeriodicUpdateInterval"), ret);
		return ret;
	}
	void AMT_GeneralSettings::DDNSPeriodicUpdateInterval(const unsigned int value)
	{
		SetOrAddField("DDNSPeriodicUpdateInterval", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::DDNSPeriodicUpdateIntervalExists() const
	{
		return ContainsField("DDNSPeriodicUpdateInterval");
	}
	void AMT_GeneralSettings::RemoveDDNSPeriodicUpdateInterval()
	{
		RemoveField("DDNSPeriodicUpdateInterval");
	}

	const unsigned int AMT_GeneralSettings::PresenceNotificationInterval() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PresenceNotificationInterval"), ret);
		return ret;
	}
	void AMT_GeneralSettings::PresenceNotificationInterval(const unsigned int value)
	{
		SetOrAddField("PresenceNotificationInterval", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::PresenceNotificationIntervalExists() const
	{
		return ContainsField("PresenceNotificationInterval");
	}
	void AMT_GeneralSettings::RemovePresenceNotificationInterval()
	{
		RemoveField("PresenceNotificationInterval");
	}

	const unsigned int AMT_GeneralSettings::PrivacyLevel() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PrivacyLevel"), ret);
		return ret;
	}
	void AMT_GeneralSettings::PrivacyLevel(const unsigned int value)
	{
		SetOrAddField("PrivacyLevel", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::PrivacyLevelExists() const
	{
		return ContainsField("PrivacyLevel");
	}
	void AMT_GeneralSettings::RemovePrivacyLevel()
	{
		RemoveField("PrivacyLevel");
	}

	const unsigned int AMT_GeneralSettings::PowerSource() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PowerSource"), ret);
		return ret;
	}
	void AMT_GeneralSettings::PowerSource(const unsigned int value)
	{
		SetOrAddField("PowerSource", TypeConverter::TypeToString(value));
	}
	bool AMT_GeneralSettings::PowerSourceExists() const
	{
		return ContainsField("PowerSource");
	}
	void AMT_GeneralSettings::RemovePowerSource()
	{
		RemoveField("PowerSource");
	}

	CimBase *AMT_GeneralSettings::CreateFromCimObject(const CimObject &object)
	{
		AMT_GeneralSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_GeneralSettings>(object);
		}
		else
		{
			ret = new AMT_GeneralSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_GeneralSettings> > AMT_GeneralSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_GeneralSettings>(client, keys);
	}

	void AMT_GeneralSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_GeneralSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_GeneralSettings::CLASS_NAME = "AMT_GeneralSettings";
	const string AMT_GeneralSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_GeneralSettings";
	const string AMT_GeneralSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_GeneralSettings";
	const string AMT_GeneralSettings::CLASS_NS_PREFIX = "AGe700";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_GeneralSettings::_classMetaData;
}
}
}
}
