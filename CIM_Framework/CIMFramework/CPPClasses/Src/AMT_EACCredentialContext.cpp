//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EACCredentialContext.cpp
//
//  Contents:   This relationship defines a service context of an EAC Credential.
//
//              This file was automatically generated from AMT_EACCredentialContext.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EACCredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EACCredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
	};
	// class fields
	CimBase *AMT_EACCredentialContext::CreateFromCimObject(const CimObject &object)
	{
		AMT_EACCredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EACCredentialContext>(object);
		}
		else
		{
			ret = new AMT_EACCredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EACCredentialContext> > AMT_EACCredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EACCredentialContext>(client, keys);
	}

	void AMT_EACCredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EACCredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_EACCredentialContext::CLASS_NAME = "AMT_EACCredentialContext";
	const string AMT_EACCredentialContext::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EACCredentialContext";
	const string AMT_EACCredentialContext::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EACCredentialContext";
	const string AMT_EACCredentialContext::CLASS_NS_PREFIX = "AEA696";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EACCredentialContext::_classMetaData;
}
}
}
}
