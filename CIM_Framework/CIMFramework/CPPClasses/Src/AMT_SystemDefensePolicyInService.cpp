//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SystemDefensePolicyInService.cpp
//
//  Contents:   A relationship between a System Defense Policy and its containing service
//
//              This file was automatically generated from AMT_SystemDefensePolicyInService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SystemDefensePolicyInService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_SystemDefensePolicyInService::_metadata[] = {
		{"Dependent", true, false, true },
		{"Antecedent", true, false, true },
	};
	// class fields
	CimBase *AMT_SystemDefensePolicyInService::CreateFromCimObject(const CimObject &object)
	{
		AMT_SystemDefensePolicyInService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SystemDefensePolicyInService>(object);
		}
		else
		{
			ret = new AMT_SystemDefensePolicyInService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SystemDefensePolicyInService> > AMT_SystemDefensePolicyInService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SystemDefensePolicyInService>(client, keys);
	}

	void AMT_SystemDefensePolicyInService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SystemDefensePolicyInService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_SystemDefensePolicyInService::CLASS_NAME = "AMT_SystemDefensePolicyInService";
	const string AMT_SystemDefensePolicyInService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefensePolicyInService";
	const string AMT_SystemDefensePolicyInService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefensePolicyInService";
	const string AMT_SystemDefensePolicyInService::CLASS_NS_PREFIX = "ASy356";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SystemDefensePolicyInService::_classMetaData;
}
}
}
}
