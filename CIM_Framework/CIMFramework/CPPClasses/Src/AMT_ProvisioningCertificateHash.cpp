//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ProvisioningCertificateHash.cpp
//
//  Contents:   A class derived from Credential that describes provisioning certificate hash entry.
//
//              This file was automatically generated from AMT_ProvisioningCertificateHash.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ProvisioningCertificateHash.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_ProvisioningCertificateHash::_metadata[] = {
		{"Description", false, false, false },
		{"InstanceID", true, false, false },
		{"IsDefault", false, false, false },
		{"HashType", false, false, false },
		{"HashData", false, false, false },
		{"Enabled", false, false, false },
	};
	// class fields
	const bool AMT_ProvisioningCertificateHash::IsDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsDefault"), ret);
		return ret;
	}
	void AMT_ProvisioningCertificateHash::IsDefault(const bool value)
	{
		SetOrAddField("IsDefault", TypeConverter::TypeToString(value));
	}
	bool AMT_ProvisioningCertificateHash::IsDefaultExists() const
	{
		return ContainsField("IsDefault");
	}
	void AMT_ProvisioningCertificateHash::RemoveIsDefault()
	{
		RemoveField("IsDefault");
	}

	const unsigned char AMT_ProvisioningCertificateHash::HashType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HashType"), ret);
		return ret;
	}
	void AMT_ProvisioningCertificateHash::HashType(const unsigned char &value)
	{
		SetOrAddField("HashType", TypeConverter::TypeToString(value));
	}
	bool AMT_ProvisioningCertificateHash::HashTypeExists() const
	{
		return ContainsField("HashType");
	}
	void AMT_ProvisioningCertificateHash::RemoveHashType()
	{
		RemoveField("HashType");
	}

	const Base64 AMT_ProvisioningCertificateHash::HashData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("HashData"), ret);
		return ret;
	}
	void AMT_ProvisioningCertificateHash::HashData(const Base64 &value)
	{
		SetOrAddField("HashData", TypeConverter::TypeToString(value));
	}
	bool AMT_ProvisioningCertificateHash::HashDataExists() const
	{
		return ContainsField("HashData");
	}
	void AMT_ProvisioningCertificateHash::RemoveHashData()
	{
		RemoveField("HashData");
	}

	const bool AMT_ProvisioningCertificateHash::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_ProvisioningCertificateHash::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_ProvisioningCertificateHash::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_ProvisioningCertificateHash::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *AMT_ProvisioningCertificateHash::CreateFromCimObject(const CimObject &object)
	{
		AMT_ProvisioningCertificateHash *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ProvisioningCertificateHash>(object);
		}
		else
		{
			ret = new AMT_ProvisioningCertificateHash(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ProvisioningCertificateHash> > AMT_ProvisioningCertificateHash::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ProvisioningCertificateHash>(client, keys);
	}

	void AMT_ProvisioningCertificateHash::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ProvisioningCertificateHash::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_ProvisioningCertificateHash::CLASS_NAME = "AMT_ProvisioningCertificateHash";
	const string AMT_ProvisioningCertificateHash::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ProvisioningCertificateHash";
	const string AMT_ProvisioningCertificateHash::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ProvisioningCertificateHash";
	const string AMT_ProvisioningCertificateHash::CLASS_NS_PREFIX = "APr569";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ProvisioningCertificateHash::_classMetaData;
}
}
}
}
