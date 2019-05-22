//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpointCapabilities.cpp
//
//  Contents:   Describes the capabilities of a WiFiEndpoint.
//
//              This file was automatically generated from CIM_WiFiEndpointCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_WiFiEndpointCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_WiFiEndpointCapabilities::_metadata[] = {
		{"SupportedEncryptionMethods", false, false, false },
		{"OtherSupportedEncryptionMethods", false, false, false },
		{"SupportedAuthenticationMethods", false, false, false },
		{"OtherSupportedAuthenticationMethods", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_WiFiEndpointCapabilities::SupportedEncryptionMethods() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedEncryptionMethods"), ret);
		return ret;
	}
	void CIM_WiFiEndpointCapabilities::SupportedEncryptionMethods(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedEncryptionMethods", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointCapabilities::SupportedEncryptionMethodsExists() const
	{
		return ContainsField("SupportedEncryptionMethods");
	}
	void CIM_WiFiEndpointCapabilities::RemoveSupportedEncryptionMethods()
	{
		RemoveField("SupportedEncryptionMethods");
	}

	const vector<string> CIM_WiFiEndpointCapabilities::OtherSupportedEncryptionMethods() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherSupportedEncryptionMethods"), ret);
		return ret;
	}
	void CIM_WiFiEndpointCapabilities::OtherSupportedEncryptionMethods(const vector<string> &value)
	{
		SetOrAddField("OtherSupportedEncryptionMethods", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointCapabilities::OtherSupportedEncryptionMethodsExists() const
	{
		return ContainsField("OtherSupportedEncryptionMethods");
	}
	void CIM_WiFiEndpointCapabilities::RemoveOtherSupportedEncryptionMethods()
	{
		RemoveField("OtherSupportedEncryptionMethods");
	}

	const vector<unsigned short> CIM_WiFiEndpointCapabilities::SupportedAuthenticationMethods() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedAuthenticationMethods"), ret);
		return ret;
	}
	void CIM_WiFiEndpointCapabilities::SupportedAuthenticationMethods(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedAuthenticationMethods", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointCapabilities::SupportedAuthenticationMethodsExists() const
	{
		return ContainsField("SupportedAuthenticationMethods");
	}
	void CIM_WiFiEndpointCapabilities::RemoveSupportedAuthenticationMethods()
	{
		RemoveField("SupportedAuthenticationMethods");
	}

	const vector<string> CIM_WiFiEndpointCapabilities::OtherSupportedAuthenticationMethods() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherSupportedAuthenticationMethods"), ret);
		return ret;
	}
	void CIM_WiFiEndpointCapabilities::OtherSupportedAuthenticationMethods(const vector<string> &value)
	{
		SetOrAddField("OtherSupportedAuthenticationMethods", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointCapabilities::OtherSupportedAuthenticationMethodsExists() const
	{
		return ContainsField("OtherSupportedAuthenticationMethods");
	}
	void CIM_WiFiEndpointCapabilities::RemoveOtherSupportedAuthenticationMethods()
	{
		RemoveField("OtherSupportedAuthenticationMethods");
	}

	CimBase *CIM_WiFiEndpointCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_WiFiEndpointCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_WiFiEndpointCapabilities>(object);
		}
		else
		{
			ret = new CIM_WiFiEndpointCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_WiFiEndpointCapabilities> > CIM_WiFiEndpointCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_WiFiEndpointCapabilities>(client, keys);
	}

	void CIM_WiFiEndpointCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_WiFiEndpointCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_WiFiEndpointCapabilities::CLASS_NAME = "CIM_WiFiEndpointCapabilities";
	const string CIM_WiFiEndpointCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpointCapabilities";
	const string CIM_WiFiEndpointCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpointCapabilities";
	const string CIM_WiFiEndpointCapabilities::CLASS_NS_PREFIX = "AWi336";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_WiFiEndpointCapabilities::_classMetaData;
}
}
}
}
