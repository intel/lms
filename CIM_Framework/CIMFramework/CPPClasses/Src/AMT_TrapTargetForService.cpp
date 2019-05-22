//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TrapTargetForService.cpp
//
//  Contents:   TrapTargetForService specifies the endpoint to which traps events are sent by the alerting service.
//
//              This file was automatically generated from AMT_TrapTargetForService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TrapTargetForService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TrapTargetForService::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *AMT_TrapTargetForService::CreateFromCimObject(const CimObject &object)
	{
		AMT_TrapTargetForService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TrapTargetForService>(object);
		}
		else
		{
			ret = new AMT_TrapTargetForService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TrapTargetForService> > AMT_TrapTargetForService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TrapTargetForService>(client, keys);
	}

	void AMT_TrapTargetForService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TrapTargetForService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_TrapTargetForService::CLASS_NAME = "AMT_TrapTargetForService";
	const string AMT_TrapTargetForService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TrapTargetForService";
	const string AMT_TrapTargetForService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TrapTargetForService";
	const string AMT_TrapTargetForService::CLASS_NS_PREFIX = "ATr719";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TrapTargetForService::_classMetaData;
}
}
}
}
