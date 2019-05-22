//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AccountOnSystem.cpp
//
//  Contents:   A system (e.g., ApplicationSystem, ComputerSystem, AdminDomain) aggregates Accounts and scopes the uniqueness of the Account names (i.e., userids).
//
//              This file was automatically generated from CIM_AccountOnSystem.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_AccountOnSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AccountOnSystem::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_AccountOnSystem::CreateFromCimObject(const CimObject &object)
	{
		CIM_AccountOnSystem *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AccountOnSystem>(object);
		}
		else
		{
			ret = new CIM_AccountOnSystem(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AccountOnSystem> > CIM_AccountOnSystem::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AccountOnSystem>(client, keys);
	}

	void CIM_AccountOnSystem::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AccountOnSystem::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AccountOnSystem::CLASS_NAME = "CIM_AccountOnSystem";
	const string CIM_AccountOnSystem::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountOnSystem";
	const string CIM_AccountOnSystem::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountOnSystem";
	const string CIM_AccountOnSystem::CLASS_NS_PREFIX = "AAc795";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AccountOnSystem::_classMetaData;
}
}
}
}
