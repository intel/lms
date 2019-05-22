//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_LANEndpoint.cpp
//
//  Contents:   Represents the LAN end point of Intel(r) AMT.
//
//              This file was automatically generated from IPS_LANEndpoint.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_LANEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *IPS_LANEndpoint::CreateFromCimObject(const CimObject &object)
	{
		IPS_LANEndpoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_LANEndpoint>(object);
		}
		else
		{
			ret = new IPS_LANEndpoint(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_LANEndpoint> > IPS_LANEndpoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_LANEndpoint>(client, keys);
	}

	void IPS_LANEndpoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_LANEndpoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_LANEndpoint::CLASS_NAME = "IPS_LANEndpoint";
	const string IPS_LANEndpoint::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_LANEndpoint";
	const string IPS_LANEndpoint::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_LANEndpoint";
	const string IPS_LANEndpoint::CLASS_NS_PREFIX = "ALA155";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_LANEndpoint::_classMetaData;
}
}
}
}
