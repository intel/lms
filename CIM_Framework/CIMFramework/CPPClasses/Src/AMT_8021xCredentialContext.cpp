//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_8021xCredentialContext.cpp
//
//  Contents:   Association between an instance of AMT_8021XProfile and an instance of AMT_PublicKeyCertificate that it uses.
//
//              This file was automatically generated from AMT_8021xCredentialContext.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_8021xCredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_8021xCredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
	};
	// class fields
	CimBase *AMT_8021xCredentialContext::CreateFromCimObject(const CimObject &object)
	{
		AMT_8021xCredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_8021xCredentialContext>(object);
		}
		else
		{
			ret = new AMT_8021xCredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_8021xCredentialContext> > AMT_8021xCredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_8021xCredentialContext>(client, keys);
	}

	void AMT_8021xCredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_8021xCredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_8021xCredentialContext::CLASS_NAME = "AMT_8021xCredentialContext";
	const string AMT_8021xCredentialContext::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_8021xCredentialContext";
	const string AMT_8021xCredentialContext::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_8021xCredentialContext";
	const string AMT_8021xCredentialContext::CLASS_NS_PREFIX = "A80938";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_8021xCredentialContext::_classMetaData;
}
}
}
}
