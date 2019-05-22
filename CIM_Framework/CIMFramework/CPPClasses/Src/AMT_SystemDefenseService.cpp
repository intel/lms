//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SystemDefenseService.cpp
//
//  Contents:   Represents the System Defense and Heuristic Packet Filter service.
//
//              This file was automatically generated from AMT_SystemDefenseService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SystemDefenseService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_SystemDefenseService::CreateFromCimObject(const CimObject &object)
	{
		AMT_SystemDefenseService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SystemDefenseService>(object);
		}
		else
		{
			ret = new AMT_SystemDefenseService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SystemDefenseService> > AMT_SystemDefenseService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SystemDefenseService>(client, keys);
	}

	void AMT_SystemDefenseService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SystemDefenseService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_SystemDefenseService::CLASS_NAME = "AMT_SystemDefenseService";
	const string AMT_SystemDefenseService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefenseService";
	const string AMT_SystemDefenseService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefenseService";
	const string AMT_SystemDefenseService::CLASS_NS_PREFIX = "ASy293";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SystemDefenseService::_classMetaData;
}
}
}
}
