//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSSettingData.cpp
//
//  Contents:   The AMT_TLSSettingData class represents configuration-related and operational parameters for the TLS service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_TLSSettingData.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TLSSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TLSSettingData::_metadata[] = {
		{"MutualAuthentication", false, false, false },
		{"Enabled", false, true, false },
		{"TrustedCN", false, false, false },
		{"X509IssuerName", false, false, false },
		{"X509SerialNumber", false, false, false },
		{"AcceptNonSecureConnections", false, false, false },
	};
	// class fields
	const bool AMT_TLSSettingData::MutualAuthentication() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("MutualAuthentication"), ret);
		return ret;
	}
	void AMT_TLSSettingData::MutualAuthentication(const bool value)
	{
		SetOrAddField("MutualAuthentication", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSSettingData::MutualAuthenticationExists() const
	{
		return ContainsField("MutualAuthentication");
	}
	void AMT_TLSSettingData::RemoveMutualAuthentication()
	{
		RemoveField("MutualAuthentication");
	}

	const bool AMT_TLSSettingData::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_TLSSettingData::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSSettingData::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_TLSSettingData::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	const vector<string> AMT_TLSSettingData::TrustedCN() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("TrustedCN"), ret);
		return ret;
	}
	void AMT_TLSSettingData::TrustedCN(const vector<string> &value)
	{
		SetOrAddField("TrustedCN", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSSettingData::TrustedCNExists() const
	{
		return ContainsField("TrustedCN");
	}
	void AMT_TLSSettingData::RemoveTrustedCN()
	{
		RemoveField("TrustedCN");
	}

	const string AMT_TLSSettingData::X509IssuerName() const
	{
		return GetField("X509IssuerName")[0];
	}
	void AMT_TLSSettingData::X509IssuerName(const string &value)
	{
		SetOrAddField("X509IssuerName", value);
	}
	bool AMT_TLSSettingData::X509IssuerNameExists() const
	{
		return ContainsField("X509IssuerName");
	}
	void AMT_TLSSettingData::RemoveX509IssuerName()
	{
		RemoveField("X509IssuerName");
	}

	const Base64 AMT_TLSSettingData::X509SerialNumber() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("X509SerialNumber"), ret);
		return ret;
	}
	void AMT_TLSSettingData::X509SerialNumber(const Base64 &value)
	{
		SetOrAddField("X509SerialNumber", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSSettingData::X509SerialNumberExists() const
	{
		return ContainsField("X509SerialNumber");
	}
	void AMT_TLSSettingData::RemoveX509SerialNumber()
	{
		RemoveField("X509SerialNumber");
	}

	const bool AMT_TLSSettingData::AcceptNonSecureConnections() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AcceptNonSecureConnections"), ret);
		return ret;
	}
	void AMT_TLSSettingData::AcceptNonSecureConnections(const bool value)
	{
		SetOrAddField("AcceptNonSecureConnections", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSSettingData::AcceptNonSecureConnectionsExists() const
	{
		return ContainsField("AcceptNonSecureConnections");
	}
	void AMT_TLSSettingData::RemoveAcceptNonSecureConnections()
	{
		RemoveField("AcceptNonSecureConnections");
	}

	CimBase *AMT_TLSSettingData::CreateFromCimObject(const CimObject &object)
	{
		AMT_TLSSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TLSSettingData>(object);
		}
		else
		{
			ret = new AMT_TLSSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TLSSettingData> > AMT_TLSSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TLSSettingData>(client, keys);
	}

	void AMT_TLSSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TLSSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_TLSSettingData::CLASS_NAME = "AMT_TLSSettingData";
	const string AMT_TLSSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSSettingData";
	const string AMT_TLSSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSSettingData";
	const string AMT_TLSSettingData::CLASS_NS_PREFIX = "ATL886";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TLSSettingData::_classMetaData;
}
}
}
}
