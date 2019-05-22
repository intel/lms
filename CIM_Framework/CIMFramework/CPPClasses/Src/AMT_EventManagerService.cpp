//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EventManagerService.cpp
//
//  Contents:   Represents the Event Manager service in AMT.
//
//              This file was automatically generated from AMT_EventManagerService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EventManagerService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EventManagerService::_metadata[] = {
		{"DefaultCommunityString", false, false, false },
	};
	// class fields
	const string AMT_EventManagerService::DefaultCommunityString() const
	{
		return GetField("DefaultCommunityString")[0];
	}
	void AMT_EventManagerService::DefaultCommunityString(const string &value)
	{
		SetOrAddField("DefaultCommunityString", value);
	}
	bool AMT_EventManagerService::DefaultCommunityStringExists() const
	{
		return ContainsField("DefaultCommunityString");
	}
	void AMT_EventManagerService::RemoveDefaultCommunityString()
	{
		RemoveField("DefaultCommunityString");
	}

	CimBase *AMT_EventManagerService::CreateFromCimObject(const CimObject &object)
	{
		AMT_EventManagerService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EventManagerService>(object);
		}
		else
		{
			ret = new AMT_EventManagerService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EventManagerService> > AMT_EventManagerService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EventManagerService>(client, keys);
	}

	void AMT_EventManagerService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EventManagerService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_EventManagerService::CLASS_NAME = "AMT_EventManagerService";
	const string AMT_EventManagerService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventManagerService";
	const string AMT_EventManagerService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventManagerService";
	const string AMT_EventManagerService::CLASS_NS_PREFIX = "AEv357";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EventManagerService::_classMetaData;
}
}
}
}
