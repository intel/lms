//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyRuleInSystem.cpp
//
//  Contents:   An association that links a PolicyRule to the System in whose scope the Rule is defined.
//
//              This file was automatically generated from CIM_PolicyRuleInSystem.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicyRuleInSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicyRuleInSystem::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_PolicyRuleInSystem::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicyRuleInSystem *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicyRuleInSystem>(object);
		}
		else
		{
			ret = new CIM_PolicyRuleInSystem(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicyRuleInSystem> > CIM_PolicyRuleInSystem::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicyRuleInSystem>(client, keys);
	}

	void CIM_PolicyRuleInSystem::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicyRuleInSystem::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicyRuleInSystem::CLASS_NAME = "CIM_PolicyRuleInSystem";
	const string CIM_PolicyRuleInSystem::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyRuleInSystem";
	const string CIM_PolicyRuleInSystem::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyRuleInSystem";
	const string CIM_PolicyRuleInSystem::CLASS_NS_PREFIX = "APo922";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicyRuleInSystem::_classMetaData;
}
}
}
}
