//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EthernetPortSettings.cpp
//
//  Contents:   This class contains all Intel(R) AMT specific settings (IP, DHCP, VLAN) for one network interface in the system.
//
//              This file was automatically generated from AMT_EthernetPortSettings.mof,  version: 12.0.20
//
//----------------------------------------------------------------------------
#include "AMT_EthernetPortSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EthernetPortSettings::_metadata[] = {
		{"InstanceID", true, false, false },
		{"VLANTag", false, false, false },
		{"SharedMAC", false, false, false },
		{"MACAddress", false, false, false },
		{"LinkIsUp", false, false, false },
		{"LinkPolicy", false, false, false },
		{"LinkPreference", false, false, false },
		{"LinkControl", false, false, false },
		{"SharedStaticIp", false, false, false },
		{"SharedDynamicIP", false, false, false },
		{"IpSyncEnabled", false, false, false },
		{"DHCPEnabled", false, false, false },
		{"IPAddress", false, false, false },
		{"SubnetMask", false, false, false },
		{"DefaultGateway", false, false, false },
		{"PrimaryDNS", false, false, false },
		{"SecondaryDNS", false, false, false },
		{"ConsoleTcpMaxRetransmissions", false, false, false },
		{"PhysicalConnectionType", false, false, false },
		{"PhysicalNicMedium", false, false, false },
		{"WLANLinkProtectionLevel", false, false, false },
	};
	// class fields
	const unsigned short AMT_EthernetPortSettings::VLANTag() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("VLANTag"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::VLANTag(const unsigned short value)
	{
		SetOrAddField("VLANTag", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::VLANTagExists() const
	{
		return ContainsField("VLANTag");
	}
	void AMT_EthernetPortSettings::RemoveVLANTag()
	{
		RemoveField("VLANTag");
	}

	const bool AMT_EthernetPortSettings::SharedMAC() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SharedMAC"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::SharedMAC(const bool value)
	{
		SetOrAddField("SharedMAC", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::SharedMACExists() const
	{
		return ContainsField("SharedMAC");
	}
	void AMT_EthernetPortSettings::RemoveSharedMAC()
	{
		RemoveField("SharedMAC");
	}

	const string AMT_EthernetPortSettings::MACAddress() const
	{
		return GetField("MACAddress")[0];
	}
	void AMT_EthernetPortSettings::MACAddress(const string &value)
	{
		SetOrAddField("MACAddress", value);
	}
	bool AMT_EthernetPortSettings::MACAddressExists() const
	{
		return ContainsField("MACAddress");
	}
	void AMT_EthernetPortSettings::RemoveMACAddress()
	{
		RemoveField("MACAddress");
	}

	const bool AMT_EthernetPortSettings::LinkIsUp() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LinkIsUp"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::LinkIsUp(const bool value)
	{
		SetOrAddField("LinkIsUp", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::LinkIsUpExists() const
	{
		return ContainsField("LinkIsUp");
	}
	void AMT_EthernetPortSettings::RemoveLinkIsUp()
	{
		RemoveField("LinkIsUp");
	}

	const vector<unsigned char> AMT_EthernetPortSettings::LinkPolicy() const
	{
		vector<unsigned char> ret;
		TypeConverter::StringToType(GetField("LinkPolicy"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::LinkPolicy(const vector<unsigned char> &value)
	{
		SetOrAddField("LinkPolicy", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::LinkPolicyExists() const
	{
		return ContainsField("LinkPolicy");
	}
	void AMT_EthernetPortSettings::RemoveLinkPolicy()
	{
		RemoveField("LinkPolicy");
	}

	const unsigned int AMT_EthernetPortSettings::LinkPreference() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("LinkPreference"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::LinkPreference(const unsigned int value)
	{
		SetOrAddField("LinkPreference", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::LinkPreferenceExists() const
	{
		return ContainsField("LinkPreference");
	}
	void AMT_EthernetPortSettings::RemoveLinkPreference()
	{
		RemoveField("LinkPreference");
	}

	const unsigned int AMT_EthernetPortSettings::LinkControl() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("LinkControl"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::LinkControl(const unsigned int value)
	{
		SetOrAddField("LinkControl", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::LinkControlExists() const
	{
		return ContainsField("LinkControl");
	}
	void AMT_EthernetPortSettings::RemoveLinkControl()
	{
		RemoveField("LinkControl");
	}

	const bool AMT_EthernetPortSettings::SharedStaticIp() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SharedStaticIp"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::SharedStaticIp(const bool value)
	{
		SetOrAddField("SharedStaticIp", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::SharedStaticIpExists() const
	{
		return ContainsField("SharedStaticIp");
	}
	void AMT_EthernetPortSettings::RemoveSharedStaticIp()
	{
		RemoveField("SharedStaticIp");
	}

	const bool AMT_EthernetPortSettings::SharedDynamicIP() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SharedDynamicIP"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::SharedDynamicIP(const bool value)
	{
		SetOrAddField("SharedDynamicIP", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::SharedDynamicIPExists() const
	{
		return ContainsField("SharedDynamicIP");
	}
	void AMT_EthernetPortSettings::RemoveSharedDynamicIP()
	{
		RemoveField("SharedDynamicIP");
	}

	const bool AMT_EthernetPortSettings::IpSyncEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IpSyncEnabled"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::IpSyncEnabled(const bool value)
	{
		SetOrAddField("IpSyncEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::IpSyncEnabledExists() const
	{
		return ContainsField("IpSyncEnabled");
	}
	void AMT_EthernetPortSettings::RemoveIpSyncEnabled()
	{
		RemoveField("IpSyncEnabled");
	}

	const bool AMT_EthernetPortSettings::DHCPEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DHCPEnabled"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::DHCPEnabled(const bool value)
	{
		SetOrAddField("DHCPEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::DHCPEnabledExists() const
	{
		return ContainsField("DHCPEnabled");
	}
	void AMT_EthernetPortSettings::RemoveDHCPEnabled()
	{
		RemoveField("DHCPEnabled");
	}

	const string AMT_EthernetPortSettings::IPAddress() const
	{
		return GetField("IPAddress")[0];
	}
	void AMT_EthernetPortSettings::IPAddress(const string &value)
	{
		SetOrAddField("IPAddress", value);
	}
	bool AMT_EthernetPortSettings::IPAddressExists() const
	{
		return ContainsField("IPAddress");
	}
	void AMT_EthernetPortSettings::RemoveIPAddress()
	{
		RemoveField("IPAddress");
	}

	const string AMT_EthernetPortSettings::SubnetMask() const
	{
		return GetField("SubnetMask")[0];
	}
	void AMT_EthernetPortSettings::SubnetMask(const string &value)
	{
		SetOrAddField("SubnetMask", value);
	}
	bool AMT_EthernetPortSettings::SubnetMaskExists() const
	{
		return ContainsField("SubnetMask");
	}
	void AMT_EthernetPortSettings::RemoveSubnetMask()
	{
		RemoveField("SubnetMask");
	}

	const string AMT_EthernetPortSettings::DefaultGateway() const
	{
		return GetField("DefaultGateway")[0];
	}
	void AMT_EthernetPortSettings::DefaultGateway(const string &value)
	{
		SetOrAddField("DefaultGateway", value);
	}
	bool AMT_EthernetPortSettings::DefaultGatewayExists() const
	{
		return ContainsField("DefaultGateway");
	}
	void AMT_EthernetPortSettings::RemoveDefaultGateway()
	{
		RemoveField("DefaultGateway");
	}

	const string AMT_EthernetPortSettings::PrimaryDNS() const
	{
		return GetField("PrimaryDNS")[0];
	}
	void AMT_EthernetPortSettings::PrimaryDNS(const string &value)
	{
		SetOrAddField("PrimaryDNS", value);
	}
	bool AMT_EthernetPortSettings::PrimaryDNSExists() const
	{
		return ContainsField("PrimaryDNS");
	}
	void AMT_EthernetPortSettings::RemovePrimaryDNS()
	{
		RemoveField("PrimaryDNS");
	}

	const string AMT_EthernetPortSettings::SecondaryDNS() const
	{
		return GetField("SecondaryDNS")[0];
	}
	void AMT_EthernetPortSettings::SecondaryDNS(const string &value)
	{
		SetOrAddField("SecondaryDNS", value);
	}
	bool AMT_EthernetPortSettings::SecondaryDNSExists() const
	{
		return ContainsField("SecondaryDNS");
	}
	void AMT_EthernetPortSettings::RemoveSecondaryDNS()
	{
		RemoveField("SecondaryDNS");
	}

	const unsigned int AMT_EthernetPortSettings::ConsoleTcpMaxRetransmissions() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ConsoleTcpMaxRetransmissions"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::ConsoleTcpMaxRetransmissions(const unsigned int value)
	{
		SetOrAddField("ConsoleTcpMaxRetransmissions", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::ConsoleTcpMaxRetransmissionsExists() const
	{
		return ContainsField("ConsoleTcpMaxRetransmissions");
	}
	void AMT_EthernetPortSettings::RemoveConsoleTcpMaxRetransmissions()
	{
		RemoveField("ConsoleTcpMaxRetransmissions");
	}

	const unsigned int AMT_EthernetPortSettings::PhysicalConnectionType() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PhysicalConnectionType"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::PhysicalConnectionType(const unsigned int value)
	{
		SetOrAddField("PhysicalConnectionType", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::PhysicalConnectionTypeExists() const
	{
		return ContainsField("PhysicalConnectionType");
	}
	void AMT_EthernetPortSettings::RemovePhysicalConnectionType()
	{
		RemoveField("PhysicalConnectionType");
	}

	const unsigned int AMT_EthernetPortSettings::PhysicalNicMedium() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PhysicalNicMedium"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::PhysicalNicMedium(const unsigned int value)
	{
		SetOrAddField("PhysicalNicMedium", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::PhysicalNicMediumExists() const
	{
		return ContainsField("PhysicalNicMedium");
	}
	void AMT_EthernetPortSettings::RemovePhysicalNicMedium()
	{
		RemoveField("PhysicalNicMedium");
	}

	const unsigned int AMT_EthernetPortSettings::WLANLinkProtectionLevel() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("WLANLinkProtectionLevel"), ret);
		return ret;
	}
	void AMT_EthernetPortSettings::WLANLinkProtectionLevel(const unsigned int value)
	{
		SetOrAddField("WLANLinkProtectionLevel", TypeConverter::TypeToString(value));
	}
	bool AMT_EthernetPortSettings::WLANLinkProtectionLevelExists() const
	{
		return ContainsField("WLANLinkProtectionLevel");
	}
	void AMT_EthernetPortSettings::RemoveWLANLinkProtectionLevel()
	{
		RemoveField("WLANLinkProtectionLevel");
	}

	CimBase *AMT_EthernetPortSettings::CreateFromCimObject(const CimObject &object)
	{
		AMT_EthernetPortSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EthernetPortSettings>(object);
		}
		else
		{
			ret = new AMT_EthernetPortSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EthernetPortSettings> > AMT_EthernetPortSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EthernetPortSettings>(client, keys);
	}

	void AMT_EthernetPortSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EthernetPortSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_EthernetPortSettings::SetLinkPreference_INPUT::_metadata[] = {
		{"LinkPreference", false, true },
		{"Timeout", false, false },
	};
	void AMT_EthernetPortSettings::SetLinkPreference_INPUT::LinkPreference(const unsigned int value)
	{
		SetOrAddField("LinkPreference", TypeConverter::TypeToString(value));
	}
	void AMT_EthernetPortSettings::SetLinkPreference_INPUT::Timeout(const unsigned int value)
	{
		SetOrAddField("Timeout", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EthernetPortSettings::SetLinkPreference_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_EthernetPortSettings::SetLinkPreference(const SetLinkPreference_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetLinkPreference", input, output);
	}
	unsigned int AMT_EthernetPortSettings::CancelLinkProtection()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("CancelLinkProtection", input, output);
	}
	unsigned int AMT_EthernetPortSettings::RestoreLinkProtection()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreLinkProtection", input, output);
	}
	const string AMT_EthernetPortSettings::CLASS_NAME = "AMT_EthernetPortSettings";
	const string AMT_EthernetPortSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EthernetPortSettings";
	const string AMT_EthernetPortSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EthernetPortSettings";
	const string AMT_EthernetPortSettings::CLASS_NS_PREFIX = "AEt838";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EthernetPortSettings::_classMetaData;
}
}
}
}
