//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ReferencedProfile.cpp
//
//  Contents:   A profile that is referenced by another RegisteredProfile.
//
//              This file was automatically generated from CIM_ReferencedProfile.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_ReferencedProfile.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ReferencedProfile::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ReferencedProfile::CreateFromCimObject(const CimObject &object)
	{
		CIM_ReferencedProfile *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ReferencedProfile>(object);
		}
		else
		{
			ret = new CIM_ReferencedProfile(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ReferencedProfile> > CIM_ReferencedProfile::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ReferencedProfile>(client, keys);
	}

	void CIM_ReferencedProfile::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ReferencedProfile::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ReferencedProfile::CLASS_NAME = "CIM_ReferencedProfile";
	const string CIM_ReferencedProfile::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ReferencedProfile";
	const string CIM_ReferencedProfile::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ReferencedProfile";
	const string CIM_ReferencedProfile::CLASS_NS_PREFIX = "ARe824";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ReferencedProfile::_classMetaData;
}
}
}
}
