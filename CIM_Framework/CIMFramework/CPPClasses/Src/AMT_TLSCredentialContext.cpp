//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSCredentialContext.cpp
//
//  Contents:   This relationship defines a service context of a TLS Credential.
//
//              This file was automatically generated from AMT_TLSCredentialContext.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TLSCredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TLSCredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
	};
	// class fields
	CimBase *AMT_TLSCredentialContext::CreateFromCimObject(const CimObject &object)
	{
		AMT_TLSCredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TLSCredentialContext>(object);
		}
		else
		{
			ret = new AMT_TLSCredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TLSCredentialContext> > AMT_TLSCredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TLSCredentialContext>(client, keys);
	}

	void AMT_TLSCredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TLSCredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_TLSCredentialContext::CLASS_NAME = "AMT_TLSCredentialContext";
	const string AMT_TLSCredentialContext::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSCredentialContext";
	const string AMT_TLSCredentialContext::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSCredentialContext";
	const string AMT_TLSCredentialContext::CLASS_NS_PREFIX = "ATL836";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TLSCredentialContext::_classMetaData;
}
}
}
}
