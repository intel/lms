//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HostIPSettings.cpp
//
//  Contents:   The IPS_HostIpSettings class represents the IP settings of the host computer.It will use to synchronize IP between host and ME if needed.
//
//              This file was automatically generated from IPS_HostIPSettings.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_HostIPSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_HostIPSettings::_metadata[] = {
		{"DHCPEnabled", false, false, false },
		{"IpAddress", false, false, false },
		{"SubnetMask", false, false, false },
		{"DefaultGateway", false, false, false },
		{"PrimaryDNS", false, false, false },
		{"SecondaryDNS", false, false, false },
	};
	// class fields
	const bool IPS_HostIPSettings::DHCPEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DHCPEnabled"), ret);
		return ret;
	}
	void IPS_HostIPSettings::DHCPEnabled(const bool value)
	{
		SetOrAddField("DHCPEnabled", TypeConverter::TypeToString(value));
	}
	bool IPS_HostIPSettings::DHCPEnabledExists() const
	{
		return ContainsField("DHCPEnabled");
	}
	void IPS_HostIPSettings::RemoveDHCPEnabled()
	{
		RemoveField("DHCPEnabled");
	}

	const string IPS_HostIPSettings::IpAddress() const
	{
		return GetField("IpAddress")[0];
	}
	void IPS_HostIPSettings::IpAddress(const string &value)
	{
		SetOrAddField("IpAddress", value);
	}
	bool IPS_HostIPSettings::IpAddressExists() const
	{
		return ContainsField("IpAddress");
	}
	void IPS_HostIPSettings::RemoveIpAddress()
	{
		RemoveField("IpAddress");
	}

	const string IPS_HostIPSettings::SubnetMask() const
	{
		return GetField("SubnetMask")[0];
	}
	void IPS_HostIPSettings::SubnetMask(const string &value)
	{
		SetOrAddField("SubnetMask", value);
	}
	bool IPS_HostIPSettings::SubnetMaskExists() const
	{
		return ContainsField("SubnetMask");
	}
	void IPS_HostIPSettings::RemoveSubnetMask()
	{
		RemoveField("SubnetMask");
	}

	const string IPS_HostIPSettings::DefaultGateway() const
	{
		return GetField("DefaultGateway")[0];
	}
	void IPS_HostIPSettings::DefaultGateway(const string &value)
	{
		SetOrAddField("DefaultGateway", value);
	}
	bool IPS_HostIPSettings::DefaultGatewayExists() const
	{
		return ContainsField("DefaultGateway");
	}
	void IPS_HostIPSettings::RemoveDefaultGateway()
	{
		RemoveField("DefaultGateway");
	}

	const string IPS_HostIPSettings::PrimaryDNS() const
	{
		return GetField("PrimaryDNS")[0];
	}
	void IPS_HostIPSettings::PrimaryDNS(const string &value)
	{
		SetOrAddField("PrimaryDNS", value);
	}
	bool IPS_HostIPSettings::PrimaryDNSExists() const
	{
		return ContainsField("PrimaryDNS");
	}
	void IPS_HostIPSettings::RemovePrimaryDNS()
	{
		RemoveField("PrimaryDNS");
	}

	const string IPS_HostIPSettings::SecondaryDNS() const
	{
		return GetField("SecondaryDNS")[0];
	}
	void IPS_HostIPSettings::SecondaryDNS(const string &value)
	{
		SetOrAddField("SecondaryDNS", value);
	}
	bool IPS_HostIPSettings::SecondaryDNSExists() const
	{
		return ContainsField("SecondaryDNS");
	}
	void IPS_HostIPSettings::RemoveSecondaryDNS()
	{
		RemoveField("SecondaryDNS");
	}

	CimBase *IPS_HostIPSettings::CreateFromCimObject(const CimObject &object)
	{
		IPS_HostIPSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_HostIPSettings>(object);
		}
		else
		{
			ret = new IPS_HostIPSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_HostIPSettings> > IPS_HostIPSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_HostIPSettings>(client, keys);
	}

	void IPS_HostIPSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_HostIPSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_HostIPSettings::CLASS_NAME = "IPS_HostIPSettings";
	const string IPS_HostIPSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostIPSettings";
	const string IPS_HostIPSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostIPSettings";
	const string IPS_HostIPSettings::CLASS_NS_PREFIX = "AHo619";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_HostIPSettings::_classMetaData;
}
}
}
}
