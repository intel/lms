//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_KerberosSettingData.cpp
//
//  Contents:   The AMT_KerberosSettingData class represents configuration-related and operational parameters for the kerberos service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_KerberosSettingData.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "AMT_KerberosSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_KerberosSettingData::_metadata[] = {
		{"RealmName", false, false, false },
		{"ServicePrincipalName", false, false, false },
		{"ServicePrincipalProtocol", false, false, false },
		{"KeyVersion", false, false, false },
		{"EncryptionAlgorithm", false, false, false },
		{"MasterKey", false, false, false },
		{"MaximumClockTolerance", false, false, false },
		{"KrbEnabled", false, true, false },
		{"Passphrase", false, false, false },
		{"Salt", false, false, false },
		{"IterationCount", false, false, false },
		{"SupportedEncryptionAlgorithms", false, false, false },
		{"ConfiguredEncryptionAlgorithms", false, false, false },
	};
	// class fields
	const string AMT_KerberosSettingData::RealmName() const
	{
		return GetField("RealmName")[0];
	}
	void AMT_KerberosSettingData::RealmName(const string &value)
	{
		SetOrAddField("RealmName", value);
	}
	bool AMT_KerberosSettingData::RealmNameExists() const
	{
		return ContainsField("RealmName");
	}
	void AMT_KerberosSettingData::RemoveRealmName()
	{
		RemoveField("RealmName");
	}

	const vector<string> AMT_KerberosSettingData::ServicePrincipalName() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ServicePrincipalName"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::ServicePrincipalName(const vector<string> &value)
	{
		SetOrAddField("ServicePrincipalName", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::ServicePrincipalNameExists() const
	{
		return ContainsField("ServicePrincipalName");
	}
	void AMT_KerberosSettingData::RemoveServicePrincipalName()
	{
		RemoveField("ServicePrincipalName");
	}

	const vector<unsigned short> AMT_KerberosSettingData::ServicePrincipalProtocol() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ServicePrincipalProtocol"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::ServicePrincipalProtocol(const vector<unsigned short> &value)
	{
		SetOrAddField("ServicePrincipalProtocol", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::ServicePrincipalProtocolExists() const
	{
		return ContainsField("ServicePrincipalProtocol");
	}
	void AMT_KerberosSettingData::RemoveServicePrincipalProtocol()
	{
		RemoveField("ServicePrincipalProtocol");
	}

	const unsigned int AMT_KerberosSettingData::KeyVersion() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("KeyVersion"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::KeyVersion(const unsigned int value)
	{
		SetOrAddField("KeyVersion", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::KeyVersionExists() const
	{
		return ContainsField("KeyVersion");
	}
	void AMT_KerberosSettingData::RemoveKeyVersion()
	{
		RemoveField("KeyVersion");
	}

	const unsigned short AMT_KerberosSettingData::EncryptionAlgorithm() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EncryptionAlgorithm"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::EncryptionAlgorithm(const unsigned short value)
	{
		SetOrAddField("EncryptionAlgorithm", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::EncryptionAlgorithmExists() const
	{
		return ContainsField("EncryptionAlgorithm");
	}
	void AMT_KerberosSettingData::RemoveEncryptionAlgorithm()
	{
		RemoveField("EncryptionAlgorithm");
	}

	const Base64 AMT_KerberosSettingData::MasterKey() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("MasterKey"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::MasterKey(const Base64 &value)
	{
		SetOrAddField("MasterKey", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::MasterKeyExists() const
	{
		return ContainsField("MasterKey");
	}
	void AMT_KerberosSettingData::RemoveMasterKey()
	{
		RemoveField("MasterKey");
	}

	const unsigned int AMT_KerberosSettingData::MaximumClockTolerance() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaximumClockTolerance"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::MaximumClockTolerance(const unsigned int value)
	{
		SetOrAddField("MaximumClockTolerance", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::MaximumClockToleranceExists() const
	{
		return ContainsField("MaximumClockTolerance");
	}
	void AMT_KerberosSettingData::RemoveMaximumClockTolerance()
	{
		RemoveField("MaximumClockTolerance");
	}

	const bool AMT_KerberosSettingData::KrbEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("KrbEnabled"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::KrbEnabled(const bool value)
	{
		SetOrAddField("KrbEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::KrbEnabledExists() const
	{
		return ContainsField("KrbEnabled");
	}
	void AMT_KerberosSettingData::RemoveKrbEnabled()
	{
		RemoveField("KrbEnabled");
	}

	const string AMT_KerberosSettingData::Passphrase() const
	{
		return GetField("Passphrase")[0];
	}
	void AMT_KerberosSettingData::Passphrase(const string &value)
	{
		SetOrAddField("Passphrase", value);
	}
	bool AMT_KerberosSettingData::PassphraseExists() const
	{
		return ContainsField("Passphrase");
	}
	void AMT_KerberosSettingData::RemovePassphrase()
	{
		RemoveField("Passphrase");
	}

	const string AMT_KerberosSettingData::Salt() const
	{
		return GetField("Salt")[0];
	}
	void AMT_KerberosSettingData::Salt(const string &value)
	{
		SetOrAddField("Salt", value);
	}
	bool AMT_KerberosSettingData::SaltExists() const
	{
		return ContainsField("Salt");
	}
	void AMT_KerberosSettingData::RemoveSalt()
	{
		RemoveField("Salt");
	}

	const unsigned int AMT_KerberosSettingData::IterationCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("IterationCount"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::IterationCount(const unsigned int value)
	{
		SetOrAddField("IterationCount", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::IterationCountExists() const
	{
		return ContainsField("IterationCount");
	}
	void AMT_KerberosSettingData::RemoveIterationCount()
	{
		RemoveField("IterationCount");
	}

	const vector<unsigned short> AMT_KerberosSettingData::SupportedEncryptionAlgorithms() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedEncryptionAlgorithms"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::SupportedEncryptionAlgorithms(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedEncryptionAlgorithms", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::SupportedEncryptionAlgorithmsExists() const
	{
		return ContainsField("SupportedEncryptionAlgorithms");
	}
	void AMT_KerberosSettingData::RemoveSupportedEncryptionAlgorithms()
	{
		RemoveField("SupportedEncryptionAlgorithms");
	}

	const vector<unsigned short> AMT_KerberosSettingData::ConfiguredEncryptionAlgorithms() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ConfiguredEncryptionAlgorithms"), ret);
		return ret;
	}
	void AMT_KerberosSettingData::ConfiguredEncryptionAlgorithms(const vector<unsigned short> &value)
	{
		SetOrAddField("ConfiguredEncryptionAlgorithms", TypeConverter::TypeToString(value));
	}
	bool AMT_KerberosSettingData::ConfiguredEncryptionAlgorithmsExists() const
	{
		return ContainsField("ConfiguredEncryptionAlgorithms");
	}
	void AMT_KerberosSettingData::RemoveConfiguredEncryptionAlgorithms()
	{
		RemoveField("ConfiguredEncryptionAlgorithms");
	}

	CimBase *AMT_KerberosSettingData::CreateFromCimObject(const CimObject &object)
	{
		AMT_KerberosSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_KerberosSettingData>(object);
		}
		else
		{
			ret = new AMT_KerberosSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_KerberosSettingData> > AMT_KerberosSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_KerberosSettingData>(client, keys);
	}

	void AMT_KerberosSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_KerberosSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const bool AMT_KerberosSettingData::GetCredentialCacheState_OUTPUT::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	unsigned int AMT_KerberosSettingData::GetCredentialCacheState(GetCredentialCacheState_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetCredentialCacheState", input, output);
	}
	const CimFieldAttribute AMT_KerberosSettingData::SetCredentialCacheState_INPUT::_metadata[] = {
		{"Enable", false, true },
	};
	void AMT_KerberosSettingData::SetCredentialCacheState_INPUT::Enable(const bool value)
	{
		SetOrAddField("Enable", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_KerberosSettingData::SetCredentialCacheState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_KerberosSettingData::SetCredentialCacheState(const SetCredentialCacheState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetCredentialCacheState", input, output);
	}
	const string AMT_KerberosSettingData::CLASS_NAME = "AMT_KerberosSettingData";
	const string AMT_KerberosSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_KerberosSettingData";
	const string AMT_KerberosSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_KerberosSettingData";
	const string AMT_KerberosSettingData::CLASS_NS_PREFIX = "AKe392";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_KerberosSettingData::_classMetaData;
}
}
}
}
