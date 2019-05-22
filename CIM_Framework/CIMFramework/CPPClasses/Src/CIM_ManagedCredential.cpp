//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ManagedCredential.cpp
//
//  Contents:   This relationship associates a CredentialManagementService with the Credential it manages.
//
//              This file was automatically generated from CIM_ManagedCredential.mof,  version: 2.16.0
//
//----------------------------------------------------------------------------
#include "CIM_ManagedCredential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ManagedCredential::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ManagedCredential::CreateFromCimObject(const CimObject &object)
	{
		CIM_ManagedCredential *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ManagedCredential>(object);
		}
		else
		{
			ret = new CIM_ManagedCredential(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ManagedCredential> > CIM_ManagedCredential::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ManagedCredential>(client, keys);
	}

	void CIM_ManagedCredential::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ManagedCredential::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ManagedCredential::CLASS_NAME = "CIM_ManagedCredential";
	const string CIM_ManagedCredential::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedCredential";
	const string CIM_ManagedCredential::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedCredential";
	const string CIM_ManagedCredential::CLASS_NS_PREFIX = "AMa978";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ManagedCredential::_classMetaData;
}
}
}
}
