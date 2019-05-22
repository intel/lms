//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessCredentialContext.cpp
//
//  Contents:   Association between an instance of AMT_ManagementPresenceRemoteSAP and the credential it uses.
//
//              This file was automatically generated from AMT_RemoteAccessCredentialContext.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RemoteAccessCredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_RemoteAccessCredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
	};
	// class fields
	CimBase *AMT_RemoteAccessCredentialContext::CreateFromCimObject(const CimObject &object)
	{
		AMT_RemoteAccessCredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RemoteAccessCredentialContext>(object);
		}
		else
		{
			ret = new AMT_RemoteAccessCredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RemoteAccessCredentialContext> > AMT_RemoteAccessCredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RemoteAccessCredentialContext>(client, keys);
	}

	void AMT_RemoteAccessCredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RemoteAccessCredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_RemoteAccessCredentialContext::CLASS_NAME = "AMT_RemoteAccessCredentialContext";
	const string AMT_RemoteAccessCredentialContext::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessCredentialContext";
	const string AMT_RemoteAccessCredentialContext::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessCredentialContext";
	const string AMT_RemoteAccessCredentialContext::CLASS_NS_PREFIX = "ARe529";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RemoteAccessCredentialContext::_classMetaData;
}
}
}
}
