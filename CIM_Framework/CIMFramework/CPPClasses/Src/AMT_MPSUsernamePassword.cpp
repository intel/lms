//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_MPSUsernamePassword.cpp
//
//  Contents:   A username and password used to access an MPS.
//
//              This file was automatically generated from AMT_MPSUsernamePassword.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_MPSUsernamePassword.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_MPSUsernamePassword::_metadata[] = {
		{"Secret", false, false, false },
		{"RemoteID", false, false, false },
	};
	// class fields
	CimBase *AMT_MPSUsernamePassword::CreateFromCimObject(const CimObject &object)
	{
		AMT_MPSUsernamePassword *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_MPSUsernamePassword>(object);
		}
		else
		{
			ret = new AMT_MPSUsernamePassword(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_MPSUsernamePassword> > AMT_MPSUsernamePassword::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_MPSUsernamePassword>(client, keys);
	}

	void AMT_MPSUsernamePassword::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_MPSUsernamePassword::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_MPSUsernamePassword::CLASS_NAME = "AMT_MPSUsernamePassword";
	const string AMT_MPSUsernamePassword::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_MPSUsernamePassword";
	const string AMT_MPSUsernamePassword::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_MPSUsernamePassword";
	const string AMT_MPSUsernamePassword::CLASS_NS_PREFIX = "AMP934";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_MPSUsernamePassword::_classMetaData;
}
}
}
}
