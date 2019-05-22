//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleBasedAuthorizationService.cpp
//
//  Contents:   The CIM_RoleBasedAuthorizationService class represents the authorization service that manages and configures roles on a managed system. The CIM_RoleBasedAuthorizationService is responsible for creating, and deleting CIM_Role instances. Privileges of the roles are represented through the instance(s) of CIM_Privilege class associated to CIM_Role instances through the CIM_MemberOfCollection association. As a result of creating, and deleting CIM_Role instances the CIM_Privilege instances can also be affected. The limiting scope of the role is determined by the CIM_RoleLimitedToTarget association.
//
//              This file was automatically generated from CIM_RoleBasedAuthorizationService.mof,  version: 2.26.0
//
//----------------------------------------------------------------------------
#include "CIM_RoleBasedAuthorizationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_RoleBasedAuthorizationService::CreateFromCimObject(const CimObject &object)
	{
		CIM_RoleBasedAuthorizationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RoleBasedAuthorizationService>(object);
		}
		else
		{
			ret = new CIM_RoleBasedAuthorizationService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RoleBasedAuthorizationService> > CIM_RoleBasedAuthorizationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RoleBasedAuthorizationService>(client, keys);
	}

	void CIM_RoleBasedAuthorizationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RoleBasedAuthorizationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RoleBasedAuthorizationService::CLASS_NAME = "CIM_RoleBasedAuthorizationService";
	const string CIM_RoleBasedAuthorizationService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleBasedAuthorizationService";
	const string CIM_RoleBasedAuthorizationService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleBasedAuthorizationService";
	const string CIM_RoleBasedAuthorizationService::CLASS_NS_PREFIX = "ARo319";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RoleBasedAuthorizationService::_classMetaData;
}
}
}
}
