//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicPrivateKeyPair.cpp
//
//  Contents:   This class represents a public-private key in the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicPrivateKeyPair.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PublicPrivateKeyPair.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PublicPrivateKeyPair::_metadata[] = {
		{"InstanceID", true, false, false },
		{"DERKey", false, false, false },
	};
	// class fields
	const Base64 AMT_PublicPrivateKeyPair::DERKey() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("DERKey"), ret);
		return ret;
	}
	void AMT_PublicPrivateKeyPair::DERKey(const Base64 &value)
	{
		SetOrAddField("DERKey", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicPrivateKeyPair::DERKeyExists() const
	{
		return ContainsField("DERKey");
	}
	void AMT_PublicPrivateKeyPair::RemoveDERKey()
	{
		RemoveField("DERKey");
	}

	CimBase *AMT_PublicPrivateKeyPair::CreateFromCimObject(const CimObject &object)
	{
		AMT_PublicPrivateKeyPair *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PublicPrivateKeyPair>(object);
		}
		else
		{
			ret = new AMT_PublicPrivateKeyPair(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PublicPrivateKeyPair> > AMT_PublicPrivateKeyPair::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PublicPrivateKeyPair>(client, keys);
	}

	void AMT_PublicPrivateKeyPair::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PublicPrivateKeyPair::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PublicPrivateKeyPair::CLASS_NAME = "AMT_PublicPrivateKeyPair";
	const string AMT_PublicPrivateKeyPair::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicPrivateKeyPair";
	const string AMT_PublicPrivateKeyPair::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicPrivateKeyPair";
	const string AMT_PublicPrivateKeyPair::CLASS_NS_PREFIX = "APu738";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PublicPrivateKeyPair::_classMetaData;
}
}
}
}
