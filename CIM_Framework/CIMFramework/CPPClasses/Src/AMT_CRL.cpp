//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_CRL.cpp
//
//  Contents:   A Certificate Revocation List is a list of certificates which a Certificate Authority has revoked and which are not yet expired.
//
//              This file was automatically generated from AMT_CRL.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_CRL.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_CRL::_metadata[] = {
		{"Url", false, false, false },
		{"SerialNumbers", false, false, false },
	};
	// class fields
	const string AMT_CRL::Url() const
	{
		return GetField("Url")[0];
	}
	void AMT_CRL::Url(const string &value)
	{
		SetOrAddField("Url", value);
	}
	bool AMT_CRL::UrlExists() const
	{
		return ContainsField("Url");
	}
	void AMT_CRL::RemoveUrl()
	{
		RemoveField("Url");
	}

	const vector<string> AMT_CRL::SerialNumbers() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("SerialNumbers"), ret);
		return ret;
	}
	void AMT_CRL::SerialNumbers(const vector<string> &value)
	{
		SetOrAddField("SerialNumbers", TypeConverter::TypeToString(value));
	}
	bool AMT_CRL::SerialNumbersExists() const
	{
		return ContainsField("SerialNumbers");
	}
	void AMT_CRL::RemoveSerialNumbers()
	{
		RemoveField("SerialNumbers");
	}

	CimBase *AMT_CRL::CreateFromCimObject(const CimObject &object)
	{
		AMT_CRL *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_CRL>(object);
		}
		else
		{
			ret = new AMT_CRL(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_CRL> > AMT_CRL::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_CRL>(client, keys);
	}

	void AMT_CRL::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_CRL::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_CRL::CLASS_NAME = "AMT_CRL";
	const string AMT_CRL::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_CRL";
	const string AMT_CRL::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_CRL";
	const string AMT_CRL::CLASS_NS_PREFIX = "ACR338";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_CRL::_classMetaData;
}
}
}
}
