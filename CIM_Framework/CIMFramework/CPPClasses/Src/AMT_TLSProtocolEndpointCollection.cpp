//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSProtocolEndpointCollection.cpp
//
//  Contents:   Collection of AMT_TLSProtocolEndpoint Instances. The instances are connected with CIM_MemberOfCollection.
//
//              This file was automatically generated from AMT_TLSProtocolEndpointCollection.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TLSProtocolEndpointCollection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TLSProtocolEndpointCollection::_metadata[] = {
		{"ElementName", true, false, false },
	};
	// class fields
	CimBase *AMT_TLSProtocolEndpointCollection::CreateFromCimObject(const CimObject &object)
	{
		AMT_TLSProtocolEndpointCollection *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TLSProtocolEndpointCollection>(object);
		}
		else
		{
			ret = new AMT_TLSProtocolEndpointCollection(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TLSProtocolEndpointCollection> > AMT_TLSProtocolEndpointCollection::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TLSProtocolEndpointCollection>(client, keys);
	}

	void AMT_TLSProtocolEndpointCollection::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TLSProtocolEndpointCollection::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_TLSProtocolEndpointCollection::CLASS_NAME = "AMT_TLSProtocolEndpointCollection";
	const string AMT_TLSProtocolEndpointCollection::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSProtocolEndpointCollection";
	const string AMT_TLSProtocolEndpointCollection::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSProtocolEndpointCollection";
	const string AMT_TLSProtocolEndpointCollection::CLASS_NS_PREFIX = "ATL479";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TLSProtocolEndpointCollection::_classMetaData;
}
}
}
}
