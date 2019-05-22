//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AdminDomain.cpp
//
//  Contents:   This is a special grouping of ManagedSystemElements. The grouping is viewed as a single entity, reflecting that all of its components are administered similarly, either by the same user, group of users, or policy. It serves as an aggregation point to associate one or more of the following elements: network devices, such as routers and switches, servers, and other resources that can be accessed by end systems. This grouping of devices plays an essential role in ensuring that the same administrative policy and actions are applied to all of the devices in the grouping. The specific behavior and/or semantics of the AdminDomain can be identified through its aggregated and associated entities.
//
//              This file was automatically generated from CIM_AdminDomain.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_AdminDomain.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AdminDomain::_metadata[] = {
		{"NameFormat", false, false, false },
	};
	// class fields
	CimBase *CIM_AdminDomain::CreateFromCimObject(const CimObject &object)
	{
		CIM_AdminDomain *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AdminDomain>(object);
		}
		else
		{
			ret = new CIM_AdminDomain(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AdminDomain> > CIM_AdminDomain::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AdminDomain>(client, keys);
	}

	void CIM_AdminDomain::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AdminDomain::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AdminDomain::CLASS_NAME = "CIM_AdminDomain";
	const string CIM_AdminDomain::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AdminDomain";
	const string CIM_AdminDomain::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AdminDomain";
	const string CIM_AdminDomain::CLASS_NS_PREFIX = "AAd269";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AdminDomain::_classMetaData;
}
}
}
}
