//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpoint.cpp
//
//  Contents:   A wireless communication endpoint which, when its associated interface device is associated with an IEEE 802.11 wireless LAN, may send and receive data frames.
//
//              This file was automatically generated from CIM_WiFiEndpoint.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_WiFiEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_WiFiEndpoint::_metadata[] = {
		{"LANID", false, false, false },
		{"ProtocolIFType", false, false, false },
		{"EncryptionMethod", false, false, false },
		{"OtherEncryptionMethod", false, false, false },
		{"AuthenticationMethod", false, false, false },
		{"OtherAuthenticationMethod", false, false, false },
		{"IEEE8021xAuthenticationProtocol", false, false, false },
		{"AccessPointAddress", false, false, false },
		{"BSSType", false, false, false },
		{"Associated", false, false, false },
	};
	// class fields
	const unsigned short CIM_WiFiEndpoint::EncryptionMethod() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EncryptionMethod"), ret);
		return ret;
	}
	void CIM_WiFiEndpoint::EncryptionMethod(const unsigned short value)
	{
		SetOrAddField("EncryptionMethod", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpoint::EncryptionMethodExists() const
	{
		return ContainsField("EncryptionMethod");
	}
	void CIM_WiFiEndpoint::RemoveEncryptionMethod()
	{
		RemoveField("EncryptionMethod");
	}

	const string CIM_WiFiEndpoint::OtherEncryptionMethod() const
	{
		return GetField("OtherEncryptionMethod")[0];
	}
	void CIM_WiFiEndpoint::OtherEncryptionMethod(const string &value)
	{
		SetOrAddField("OtherEncryptionMethod", value);
	}
	bool CIM_WiFiEndpoint::OtherEncryptionMethodExists() const
	{
		return ContainsField("OtherEncryptionMethod");
	}
	void CIM_WiFiEndpoint::RemoveOtherEncryptionMethod()
	{
		RemoveField("OtherEncryptionMethod");
	}

	const unsigned short CIM_WiFiEndpoint::AuthenticationMethod() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AuthenticationMethod"), ret);
		return ret;
	}
	void CIM_WiFiEndpoint::AuthenticationMethod(const unsigned short value)
	{
		SetOrAddField("AuthenticationMethod", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpoint::AuthenticationMethodExists() const
	{
		return ContainsField("AuthenticationMethod");
	}
	void CIM_WiFiEndpoint::RemoveAuthenticationMethod()
	{
		RemoveField("AuthenticationMethod");
	}

	const string CIM_WiFiEndpoint::OtherAuthenticationMethod() const
	{
		return GetField("OtherAuthenticationMethod")[0];
	}
	void CIM_WiFiEndpoint::OtherAuthenticationMethod(const string &value)
	{
		SetOrAddField("OtherAuthenticationMethod", value);
	}
	bool CIM_WiFiEndpoint::OtherAuthenticationMethodExists() const
	{
		return ContainsField("OtherAuthenticationMethod");
	}
	void CIM_WiFiEndpoint::RemoveOtherAuthenticationMethod()
	{
		RemoveField("OtherAuthenticationMethod");
	}

	const unsigned short CIM_WiFiEndpoint::IEEE8021xAuthenticationProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IEEE8021xAuthenticationProtocol"), ret);
		return ret;
	}
	void CIM_WiFiEndpoint::IEEE8021xAuthenticationProtocol(const unsigned short value)
	{
		SetOrAddField("IEEE8021xAuthenticationProtocol", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpoint::IEEE8021xAuthenticationProtocolExists() const
	{
		return ContainsField("IEEE8021xAuthenticationProtocol");
	}
	void CIM_WiFiEndpoint::RemoveIEEE8021xAuthenticationProtocol()
	{
		RemoveField("IEEE8021xAuthenticationProtocol");
	}

	const string CIM_WiFiEndpoint::AccessPointAddress() const
	{
		return GetField("AccessPointAddress")[0];
	}
	void CIM_WiFiEndpoint::AccessPointAddress(const string &value)
	{
		SetOrAddField("AccessPointAddress", value);
	}
	bool CIM_WiFiEndpoint::AccessPointAddressExists() const
	{
		return ContainsField("AccessPointAddress");
	}
	void CIM_WiFiEndpoint::RemoveAccessPointAddress()
	{
		RemoveField("AccessPointAddress");
	}

	const unsigned short CIM_WiFiEndpoint::BSSType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BSSType"), ret);
		return ret;
	}
	void CIM_WiFiEndpoint::BSSType(const unsigned short value)
	{
		SetOrAddField("BSSType", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpoint::BSSTypeExists() const
	{
		return ContainsField("BSSType");
	}
	void CIM_WiFiEndpoint::RemoveBSSType()
	{
		RemoveField("BSSType");
	}

	const bool CIM_WiFiEndpoint::Associated() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Associated"), ret);
		return ret;
	}
	void CIM_WiFiEndpoint::Associated(const bool value)
	{
		SetOrAddField("Associated", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpoint::AssociatedExists() const
	{
		return ContainsField("Associated");
	}
	void CIM_WiFiEndpoint::RemoveAssociated()
	{
		RemoveField("Associated");
	}

	CimBase *CIM_WiFiEndpoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_WiFiEndpoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_WiFiEndpoint>(object);
		}
		else
		{
			ret = new CIM_WiFiEndpoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_WiFiEndpoint> > CIM_WiFiEndpoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_WiFiEndpoint>(client, keys);
	}

	void CIM_WiFiEndpoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_WiFiEndpoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_WiFiEndpoint::CLASS_NAME = "CIM_WiFiEndpoint";
	const string CIM_WiFiEndpoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpoint";
	const string CIM_WiFiEndpoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpoint";
	const string CIM_WiFiEndpoint::CLASS_NS_PREFIX = "AWi630";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_WiFiEndpoint::_classMetaData;
}
}
}
}
