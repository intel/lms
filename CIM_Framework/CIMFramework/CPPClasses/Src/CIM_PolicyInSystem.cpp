//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyInSystem.cpp
//
//  Contents:   CIM_PolicyInSystem is a generic association used to establish dependency relationships between Policies and the Systems that host them. These Systems may be ComputerSystems where Policies are 'running' or they may be Policy Repositories where Policies are stored. This relationship is similar to the concept of CIM_Services being dependent on CIM_Systems as defined by the HostedService association. 
//              
//              Cardinality is Max (1) for the Antecedent/System reference since Policies can only be hosted in at most one System context. Some subclasses of the association will further refine this definition to make the Policies Weak to Systems. Other subclasses of PolicyInSystem will define an optional hosting relationship. Examples of each of these are the PolicyRuleInSystem and PolicyConditionIn PolicyRepository associations, respectively.
//
//              This file was automatically generated from CIM_PolicyInSystem.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicyInSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicyInSystem::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_PolicyInSystem::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicyInSystem *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicyInSystem>(object);
		}
		else
		{
			ret = new CIM_PolicyInSystem(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicyInSystem> > CIM_PolicyInSystem::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicyInSystem>(client, keys);
	}

	void CIM_PolicyInSystem::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicyInSystem::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicyInSystem::CLASS_NAME = "CIM_PolicyInSystem";
	const string CIM_PolicyInSystem::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyInSystem";
	const string CIM_PolicyInSystem::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyInSystem";
	const string CIM_PolicyInSystem::CLASS_NS_PREFIX = "APo822";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicyInSystem::_classMetaData;
}
}
}
}
