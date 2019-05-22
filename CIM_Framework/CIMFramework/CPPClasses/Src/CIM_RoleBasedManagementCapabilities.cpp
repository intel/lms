//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleBasedManagementCapabilities.cpp
//
//  Contents:   A subclass that extends the capabilities of the CIM_RoleBasedAuthorizationService.
//
//              This file was automatically generated from CIM_RoleBasedManagementCapabilities.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_RoleBasedManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RoleBasedManagementCapabilities::_metadata[] = {
		{"SupportedMethods", false, false, false },
	};
	// class fields
	CimBase *CIM_RoleBasedManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_RoleBasedManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RoleBasedManagementCapabilities>(object);
		}
		else
		{
			ret = new CIM_RoleBasedManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RoleBasedManagementCapabilities> > CIM_RoleBasedManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RoleBasedManagementCapabilities>(client, keys);
	}

	void CIM_RoleBasedManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RoleBasedManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RoleBasedManagementCapabilities::CLASS_NAME = "CIM_RoleBasedManagementCapabilities";
	const string CIM_RoleBasedManagementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleBasedManagementCapabilities";
	const string CIM_RoleBasedManagementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleBasedManagementCapabilities";
	const string CIM_RoleBasedManagementCapabilities::CLASS_NS_PREFIX = "ARo982";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RoleBasedManagementCapabilities::_classMetaData;
}
}
}
}
