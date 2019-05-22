//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_8021xCredentialContext.cpp
//
//  Contents:   Association between an instance of IPS_IEEE8021xSettings and an instance of AMT_PublicKeyCertificate that it uses.
//
//              This file was automatically generated from IPS_8021xCredentialContext.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_8021xCredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_8021xCredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
	};
	// class fields
	CimBase *IPS_8021xCredentialContext::CreateFromCimObject(const CimObject &object)
	{
		IPS_8021xCredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_8021xCredentialContext>(object);
		}
		else
		{
			ret = new IPS_8021xCredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_8021xCredentialContext> > IPS_8021xCredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_8021xCredentialContext>(client, keys);
	}

	void IPS_8021xCredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_8021xCredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_8021xCredentialContext::CLASS_NAME = "IPS_8021xCredentialContext";
	const string IPS_8021xCredentialContext::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_8021xCredentialContext";
	const string IPS_8021xCredentialContext::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_8021xCredentialContext";
	const string IPS_8021xCredentialContext::CLASS_NS_PREFIX = "A80462";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_8021xCredentialContext::_classMetaData;
}
}
}
}
