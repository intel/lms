//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AuthorizedPrivilege.cpp
//
//  Contents:   Privilege is the base class for all types of activities which are granted or denied to a Role or an Identity. AuthorizedPrivilege is a subclass defining static renderings of authorization policy rules. The association of Roles and Identities to AuthorizedPrivilege is accomplished using the AuthorizedSubject relationship. The entities that are protected are defined using the AuthorizedTarget relationship. 
//              
//              Note that this class and its AuthorizedSubject/Target associations provide a short-hand, static mechanism to represent authorization policies.
//
//              This file was automatically generated from CIM_AuthorizedPrivilege.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_AuthorizedPrivilege.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_AuthorizedPrivilege::CreateFromCimObject(const CimObject &object)
	{
		CIM_AuthorizedPrivilege *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AuthorizedPrivilege>(object);
		}
		else
		{
			ret = new CIM_AuthorizedPrivilege(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AuthorizedPrivilege> > CIM_AuthorizedPrivilege::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AuthorizedPrivilege>(client, keys);
	}

	void CIM_AuthorizedPrivilege::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AuthorizedPrivilege::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AuthorizedPrivilege::CLASS_NAME = "CIM_AuthorizedPrivilege";
	const string CIM_AuthorizedPrivilege::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthorizedPrivilege";
	const string CIM_AuthorizedPrivilege::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthorizedPrivilege";
	const string CIM_AuthorizedPrivilege::CLASS_NS_PREFIX = "AAu14";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AuthorizedPrivilege::_classMetaData;
}
}
}
}
