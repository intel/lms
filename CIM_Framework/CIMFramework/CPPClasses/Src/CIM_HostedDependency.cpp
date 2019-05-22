//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_HostedDependency.cpp
//
//  Contents:   HostedDependency defines a ManagedElement in the context of another ManagedElement in which it resides.
//
//              This file was automatically generated from CIM_HostedDependency.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_HostedDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_HostedDependency::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_HostedDependency::CreateFromCimObject(const CimObject &object)
	{
		CIM_HostedDependency *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_HostedDependency>(object);
		}
		else
		{
			ret = new CIM_HostedDependency(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_HostedDependency> > CIM_HostedDependency::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_HostedDependency>(client, keys);
	}

	void CIM_HostedDependency::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_HostedDependency::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_HostedDependency::CLASS_NAME = "CIM_HostedDependency";
	const string CIM_HostedDependency::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedDependency";
	const string CIM_HostedDependency::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedDependency";
	const string CIM_HostedDependency::CLASS_NS_PREFIX = "AHo806";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_HostedDependency::_classMetaData;
}
}
}
}
