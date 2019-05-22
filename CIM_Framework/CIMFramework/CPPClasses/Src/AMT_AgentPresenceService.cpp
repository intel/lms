//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceService.cpp
//
//  Contents:   Represents the Agent Presence Service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_AgentPresenceService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AgentPresenceService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_AgentPresenceService::CreateFromCimObject(const CimObject &object)
	{
		AMT_AgentPresenceService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AgentPresenceService>(object);
		}
		else
		{
			ret = new AMT_AgentPresenceService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AgentPresenceService> > AMT_AgentPresenceService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AgentPresenceService>(client, keys);
	}

	void AMT_AgentPresenceService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AgentPresenceService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_AgentPresenceService::CLASS_NAME = "AMT_AgentPresenceService";
	const string AMT_AgentPresenceService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceService";
	const string AMT_AgentPresenceService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AgentPresenceService";
	const string AMT_AgentPresenceService::CLASS_NS_PREFIX = "AAg268";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AgentPresenceService::_classMetaData;
}
}
}
}
