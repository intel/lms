//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_IPv6PortSettings.cpp
//
//  Contents:   Intel(R) AMT IPv6 settings.
//
//              This file was automatically generated from IPS_IPv6PortSettings.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_IPv6PortSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_IPv6PortSettings::_metadata[] = {
		{"InstanceID", true, false, false },
		{"InterfaceIDType", false, false, false },
		{"ManualInterfaceID", false, false, false },
		{"IPv6Address", false, false, false },
		{"PrimaryDNS", false, false, false },
		{"SecondaryDNS", false, false, false },
		{"DefaultRouter", false, false, false },
		{"CurrentAddressInfo", false, false, false },
		{"CurrentPrimaryDNS", false, false, false },
		{"CurrentSecondaryDNS", false, false, false },
		{"CurrentDefaultRouter", false, false, false },
	};
	// class fields
	const unsigned int IPS_IPv6PortSettings::InterfaceIDType() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("InterfaceIDType"), ret);
		return ret;
	}
	void IPS_IPv6PortSettings::InterfaceIDType(const unsigned int value)
	{
		SetOrAddField("InterfaceIDType", TypeConverter::TypeToString(value));
	}
	bool IPS_IPv6PortSettings::InterfaceIDTypeExists() const
	{
		return ContainsField("InterfaceIDType");
	}
	void IPS_IPv6PortSettings::RemoveInterfaceIDType()
	{
		RemoveField("InterfaceIDType");
	}

	const HexBinary IPS_IPv6PortSettings::ManualInterfaceID() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("ManualInterfaceID"), ret);
		return ret;
	}
	void IPS_IPv6PortSettings::ManualInterfaceID(const HexBinary &value)
	{
		SetOrAddField("ManualInterfaceID", TypeConverter::TypeToString(value));
	}
	bool IPS_IPv6PortSettings::ManualInterfaceIDExists() const
	{
		return ContainsField("ManualInterfaceID");
	}
	void IPS_IPv6PortSettings::RemoveManualInterfaceID()
	{
		RemoveField("ManualInterfaceID");
	}

	const string IPS_IPv6PortSettings::IPv6Address() const
	{
		return GetField("IPv6Address")[0];
	}
	void IPS_IPv6PortSettings::IPv6Address(const string &value)
	{
		SetOrAddField("IPv6Address", value);
	}
	bool IPS_IPv6PortSettings::IPv6AddressExists() const
	{
		return ContainsField("IPv6Address");
	}
	void IPS_IPv6PortSettings::RemoveIPv6Address()
	{
		RemoveField("IPv6Address");
	}

	const string IPS_IPv6PortSettings::PrimaryDNS() const
	{
		return GetField("PrimaryDNS")[0];
	}
	void IPS_IPv6PortSettings::PrimaryDNS(const string &value)
	{
		SetOrAddField("PrimaryDNS", value);
	}
	bool IPS_IPv6PortSettings::PrimaryDNSExists() const
	{
		return ContainsField("PrimaryDNS");
	}
	void IPS_IPv6PortSettings::RemovePrimaryDNS()
	{
		RemoveField("PrimaryDNS");
	}

	const string IPS_IPv6PortSettings::SecondaryDNS() const
	{
		return GetField("SecondaryDNS")[0];
	}
	void IPS_IPv6PortSettings::SecondaryDNS(const string &value)
	{
		SetOrAddField("SecondaryDNS", value);
	}
	bool IPS_IPv6PortSettings::SecondaryDNSExists() const
	{
		return ContainsField("SecondaryDNS");
	}
	void IPS_IPv6PortSettings::RemoveSecondaryDNS()
	{
		RemoveField("SecondaryDNS");
	}

	const string IPS_IPv6PortSettings::DefaultRouter() const
	{
		return GetField("DefaultRouter")[0];
	}
	void IPS_IPv6PortSettings::DefaultRouter(const string &value)
	{
		SetOrAddField("DefaultRouter", value);
	}
	bool IPS_IPv6PortSettings::DefaultRouterExists() const
	{
		return ContainsField("DefaultRouter");
	}
	void IPS_IPv6PortSettings::RemoveDefaultRouter()
	{
		RemoveField("DefaultRouter");
	}

	const vector<string> IPS_IPv6PortSettings::CurrentAddressInfo() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CurrentAddressInfo"), ret);
		return ret;
	}
	void IPS_IPv6PortSettings::CurrentAddressInfo(const vector<string> &value)
	{
		SetOrAddField("CurrentAddressInfo", TypeConverter::TypeToString(value));
	}
	bool IPS_IPv6PortSettings::CurrentAddressInfoExists() const
	{
		return ContainsField("CurrentAddressInfo");
	}
	void IPS_IPv6PortSettings::RemoveCurrentAddressInfo()
	{
		RemoveField("CurrentAddressInfo");
	}

	const string IPS_IPv6PortSettings::CurrentPrimaryDNS() const
	{
		return GetField("CurrentPrimaryDNS")[0];
	}
	void IPS_IPv6PortSettings::CurrentPrimaryDNS(const string &value)
	{
		SetOrAddField("CurrentPrimaryDNS", value);
	}
	bool IPS_IPv6PortSettings::CurrentPrimaryDNSExists() const
	{
		return ContainsField("CurrentPrimaryDNS");
	}
	void IPS_IPv6PortSettings::RemoveCurrentPrimaryDNS()
	{
		RemoveField("CurrentPrimaryDNS");
	}

	const string IPS_IPv6PortSettings::CurrentSecondaryDNS() const
	{
		return GetField("CurrentSecondaryDNS")[0];
	}
	void IPS_IPv6PortSettings::CurrentSecondaryDNS(const string &value)
	{
		SetOrAddField("CurrentSecondaryDNS", value);
	}
	bool IPS_IPv6PortSettings::CurrentSecondaryDNSExists() const
	{
		return ContainsField("CurrentSecondaryDNS");
	}
	void IPS_IPv6PortSettings::RemoveCurrentSecondaryDNS()
	{
		RemoveField("CurrentSecondaryDNS");
	}

	const string IPS_IPv6PortSettings::CurrentDefaultRouter() const
	{
		return GetField("CurrentDefaultRouter")[0];
	}
	void IPS_IPv6PortSettings::CurrentDefaultRouter(const string &value)
	{
		SetOrAddField("CurrentDefaultRouter", value);
	}
	bool IPS_IPv6PortSettings::CurrentDefaultRouterExists() const
	{
		return ContainsField("CurrentDefaultRouter");
	}
	void IPS_IPv6PortSettings::RemoveCurrentDefaultRouter()
	{
		RemoveField("CurrentDefaultRouter");
	}

	CimBase *IPS_IPv6PortSettings::CreateFromCimObject(const CimObject &object)
	{
		IPS_IPv6PortSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_IPv6PortSettings>(object);
		}
		else
		{
			ret = new IPS_IPv6PortSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_IPv6PortSettings> > IPS_IPv6PortSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_IPv6PortSettings>(client, keys);
	}

	void IPS_IPv6PortSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_IPv6PortSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_IPv6PortSettings::CLASS_NAME = "IPS_IPv6PortSettings";
	const string IPS_IPv6PortSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IPv6PortSettings";
	const string IPS_IPv6PortSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IPv6PortSettings";
	const string IPS_IPv6PortSettings::CLASS_NS_PREFIX = "AIP174";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_IPv6PortSettings::_classMetaData;
}
}
}
}
