//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiEndpointSettings.cpp
//
//  Contents:   CIM_WiFiEndpointSettings describes setting data that can be applied to an instance of CIM_WiFiEndpoint to enable it to associate to a particular Wi-Fi network.
//
//              This file was automatically generated from CIM_WiFiEndpointSettings.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_WiFiEndpointSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_WiFiEndpointSettings::_metadata[] = {
		{"Priority", false, false, false },
		{"SSID", false, false, false },
		{"BSSType", false, false, false },
		{"EncryptionMethod", false, false, false },
		{"OtherEncryptionMethod", false, false, false },
		{"AuthenticationMethod", false, false, false },
		{"OtherAuthenticationMethod", false, false, false },
		{"Keys", false, false, false },
		{"KeyIndex", false, false, false },
		{"PSKValue", false, false, false },
		{"PSKPassPhrase", false, false, false },
	};
	// class fields
	const unsigned char CIM_WiFiEndpointSettings::Priority() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Priority"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::Priority(const unsigned char &value)
	{
		SetOrAddField("Priority", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::PriorityExists() const
	{
		return ContainsField("Priority");
	}
	void CIM_WiFiEndpointSettings::RemovePriority()
	{
		RemoveField("Priority");
	}

	const string CIM_WiFiEndpointSettings::SSID() const
	{
		return GetField("SSID")[0];
	}
	void CIM_WiFiEndpointSettings::SSID(const string &value)
	{
		SetOrAddField("SSID", value);
	}
	bool CIM_WiFiEndpointSettings::SSIDExists() const
	{
		return ContainsField("SSID");
	}
	void CIM_WiFiEndpointSettings::RemoveSSID()
	{
		RemoveField("SSID");
	}

	const unsigned short CIM_WiFiEndpointSettings::BSSType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BSSType"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::BSSType(const unsigned short value)
	{
		SetOrAddField("BSSType", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::BSSTypeExists() const
	{
		return ContainsField("BSSType");
	}
	void CIM_WiFiEndpointSettings::RemoveBSSType()
	{
		RemoveField("BSSType");
	}

	const unsigned short CIM_WiFiEndpointSettings::EncryptionMethod() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EncryptionMethod"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::EncryptionMethod(const unsigned short value)
	{
		SetOrAddField("EncryptionMethod", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::EncryptionMethodExists() const
	{
		return ContainsField("EncryptionMethod");
	}
	void CIM_WiFiEndpointSettings::RemoveEncryptionMethod()
	{
		RemoveField("EncryptionMethod");
	}

	const string CIM_WiFiEndpointSettings::OtherEncryptionMethod() const
	{
		return GetField("OtherEncryptionMethod")[0];
	}
	void CIM_WiFiEndpointSettings::OtherEncryptionMethod(const string &value)
	{
		SetOrAddField("OtherEncryptionMethod", value);
	}
	bool CIM_WiFiEndpointSettings::OtherEncryptionMethodExists() const
	{
		return ContainsField("OtherEncryptionMethod");
	}
	void CIM_WiFiEndpointSettings::RemoveOtherEncryptionMethod()
	{
		RemoveField("OtherEncryptionMethod");
	}

	const unsigned short CIM_WiFiEndpointSettings::AuthenticationMethod() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AuthenticationMethod"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::AuthenticationMethod(const unsigned short value)
	{
		SetOrAddField("AuthenticationMethod", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::AuthenticationMethodExists() const
	{
		return ContainsField("AuthenticationMethod");
	}
	void CIM_WiFiEndpointSettings::RemoveAuthenticationMethod()
	{
		RemoveField("AuthenticationMethod");
	}

	const string CIM_WiFiEndpointSettings::OtherAuthenticationMethod() const
	{
		return GetField("OtherAuthenticationMethod")[0];
	}
	void CIM_WiFiEndpointSettings::OtherAuthenticationMethod(const string &value)
	{
		SetOrAddField("OtherAuthenticationMethod", value);
	}
	bool CIM_WiFiEndpointSettings::OtherAuthenticationMethodExists() const
	{
		return ContainsField("OtherAuthenticationMethod");
	}
	void CIM_WiFiEndpointSettings::RemoveOtherAuthenticationMethod()
	{
		RemoveField("OtherAuthenticationMethod");
	}

	const vector<HexBinary> CIM_WiFiEndpointSettings::Keys() const
	{
		vector<HexBinary> ret;
		TypeConverter::StringToType(GetField("Keys"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::Keys(const vector<HexBinary> &value)
	{
		SetOrAddField("Keys", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::KeysExists() const
	{
		return ContainsField("Keys");
	}
	void CIM_WiFiEndpointSettings::RemoveKeys()
	{
		RemoveField("Keys");
	}

	const unsigned char CIM_WiFiEndpointSettings::KeyIndex() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("KeyIndex"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::KeyIndex(const unsigned char &value)
	{
		SetOrAddField("KeyIndex", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::KeyIndexExists() const
	{
		return ContainsField("KeyIndex");
	}
	void CIM_WiFiEndpointSettings::RemoveKeyIndex()
	{
		RemoveField("KeyIndex");
	}

	const Base64 CIM_WiFiEndpointSettings::PSKValue() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("PSKValue"), ret);
		return ret;
	}
	void CIM_WiFiEndpointSettings::PSKValue(const Base64 &value)
	{
		SetOrAddField("PSKValue", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiEndpointSettings::PSKValueExists() const
	{
		return ContainsField("PSKValue");
	}
	void CIM_WiFiEndpointSettings::RemovePSKValue()
	{
		RemoveField("PSKValue");
	}

	const string CIM_WiFiEndpointSettings::PSKPassPhrase() const
	{
		return GetField("PSKPassPhrase")[0];
	}
	void CIM_WiFiEndpointSettings::PSKPassPhrase(const string &value)
	{
		SetOrAddField("PSKPassPhrase", value);
	}
	bool CIM_WiFiEndpointSettings::PSKPassPhraseExists() const
	{
		return ContainsField("PSKPassPhrase");
	}
	void CIM_WiFiEndpointSettings::RemovePSKPassPhrase()
	{
		RemoveField("PSKPassPhrase");
	}

	CimBase *CIM_WiFiEndpointSettings::CreateFromCimObject(const CimObject &object)
	{
		CIM_WiFiEndpointSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_WiFiEndpointSettings>(object);
		}
		else
		{
			ret = new CIM_WiFiEndpointSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_WiFiEndpointSettings> > CIM_WiFiEndpointSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_WiFiEndpointSettings>(client, keys);
	}

	void CIM_WiFiEndpointSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_WiFiEndpointSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_WiFiEndpointSettings::CLASS_NAME = "CIM_WiFiEndpointSettings";
	const string CIM_WiFiEndpointSettings::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpointSettings";
	const string CIM_WiFiEndpointSettings::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiEndpointSettings";
	const string CIM_WiFiEndpointSettings::CLASS_NS_PREFIX = "AWi941";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_WiFiEndpointSettings::_classMetaData;
}
}
}
}
