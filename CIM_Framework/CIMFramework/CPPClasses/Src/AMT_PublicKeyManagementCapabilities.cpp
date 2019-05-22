//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyManagementCapabilities.cpp
//
//  Contents:   Represents the Certificate Store Capabilitites of the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_PublicKeyManagementCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PublicKeyManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PublicKeyManagementCapabilities::_metadata[] = {
		{"MaximumCRLSize", false, false, false },
		{"RootCertMaxSize", false, false, false },
		{"RootCertMaxCount", false, false, false },
		{"CommonNameMaxSize", false, false, false },
		{"CommonNameMaxCount", false, false, false },
		{"CertChainMaxSize", false, false, false },
		{"SupportedKeyLengths", false, false, false },
	};
	// class fields
	const unsigned int AMT_PublicKeyManagementCapabilities::MaximumCRLSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaximumCRLSize"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::MaximumCRLSize(const unsigned int value)
	{
		SetOrAddField("MaximumCRLSize", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::MaximumCRLSizeExists() const
	{
		return ContainsField("MaximumCRLSize");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveMaximumCRLSize()
	{
		RemoveField("MaximumCRLSize");
	}

	const unsigned int AMT_PublicKeyManagementCapabilities::RootCertMaxSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RootCertMaxSize"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::RootCertMaxSize(const unsigned int value)
	{
		SetOrAddField("RootCertMaxSize", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::RootCertMaxSizeExists() const
	{
		return ContainsField("RootCertMaxSize");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveRootCertMaxSize()
	{
		RemoveField("RootCertMaxSize");
	}

	const unsigned int AMT_PublicKeyManagementCapabilities::RootCertMaxCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RootCertMaxCount"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::RootCertMaxCount(const unsigned int value)
	{
		SetOrAddField("RootCertMaxCount", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::RootCertMaxCountExists() const
	{
		return ContainsField("RootCertMaxCount");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveRootCertMaxCount()
	{
		RemoveField("RootCertMaxCount");
	}

	const unsigned int AMT_PublicKeyManagementCapabilities::CommonNameMaxSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CommonNameMaxSize"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::CommonNameMaxSize(const unsigned int value)
	{
		SetOrAddField("CommonNameMaxSize", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::CommonNameMaxSizeExists() const
	{
		return ContainsField("CommonNameMaxSize");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveCommonNameMaxSize()
	{
		RemoveField("CommonNameMaxSize");
	}

	const unsigned int AMT_PublicKeyManagementCapabilities::CommonNameMaxCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CommonNameMaxCount"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::CommonNameMaxCount(const unsigned int value)
	{
		SetOrAddField("CommonNameMaxCount", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::CommonNameMaxCountExists() const
	{
		return ContainsField("CommonNameMaxCount");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveCommonNameMaxCount()
	{
		RemoveField("CommonNameMaxCount");
	}

	const unsigned int AMT_PublicKeyManagementCapabilities::CertChainMaxSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CertChainMaxSize"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::CertChainMaxSize(const unsigned int value)
	{
		SetOrAddField("CertChainMaxSize", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::CertChainMaxSizeExists() const
	{
		return ContainsField("CertChainMaxSize");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveCertChainMaxSize()
	{
		RemoveField("CertChainMaxSize");
	}

	const vector<unsigned int> AMT_PublicKeyManagementCapabilities::SupportedKeyLengths() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("SupportedKeyLengths"), ret);
		return ret;
	}
	void AMT_PublicKeyManagementCapabilities::SupportedKeyLengths(const vector<unsigned int> &value)
	{
		SetOrAddField("SupportedKeyLengths", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyManagementCapabilities::SupportedKeyLengthsExists() const
	{
		return ContainsField("SupportedKeyLengths");
	}
	void AMT_PublicKeyManagementCapabilities::RemoveSupportedKeyLengths()
	{
		RemoveField("SupportedKeyLengths");
	}

	CimBase *AMT_PublicKeyManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_PublicKeyManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PublicKeyManagementCapabilities>(object);
		}
		else
		{
			ret = new AMT_PublicKeyManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PublicKeyManagementCapabilities> > AMT_PublicKeyManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PublicKeyManagementCapabilities>(client, keys);
	}

	void AMT_PublicKeyManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PublicKeyManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PublicKeyManagementCapabilities::CLASS_NAME = "AMT_PublicKeyManagementCapabilities";
	const string AMT_PublicKeyManagementCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyManagementCapabilities";
	const string AMT_PublicKeyManagementCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyManagementCapabilities";
	const string AMT_PublicKeyManagementCapabilities::CLASS_NS_PREFIX = "APu688";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PublicKeyManagementCapabilities::_classMetaData;
}
}
}
}
