//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_FilterCollectionSubscription.cpp
//
//  Contents:   CIM_FilterCollectionSubscription associates the CIM_FilterCollection with a CIM_ListenerDestionation.
//
//              This file was automatically generated from CIM_FilterCollectionSubscription.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_FilterCollectionSubscription.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_FilterCollectionSubscription::_metadata[] = {
		{"Filter", true, false, true },
		{"Handler", true, false, true },
	};
	// class fields
	CimBase *CIM_FilterCollectionSubscription::CreateFromCimObject(const CimObject &object)
	{
		CIM_FilterCollectionSubscription *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_FilterCollectionSubscription>(object);
		}
		else
		{
			ret = new CIM_FilterCollectionSubscription(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_FilterCollectionSubscription> > CIM_FilterCollectionSubscription::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_FilterCollectionSubscription>(client, keys);
	}

	void CIM_FilterCollectionSubscription::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_FilterCollectionSubscription::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_FilterCollectionSubscription::CLASS_NAME = "CIM_FilterCollectionSubscription";
	const string CIM_FilterCollectionSubscription::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollectionSubscription";
	const string CIM_FilterCollectionSubscription::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollectionSubscription";
	const string CIM_FilterCollectionSubscription::CLASS_NS_PREFIX = "AFi931";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_FilterCollectionSubscription::_classMetaData;
}
}
}
}
