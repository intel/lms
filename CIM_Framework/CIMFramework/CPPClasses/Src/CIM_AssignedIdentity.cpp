//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AssignedIdentity.cpp
//
//  Contents:   This relationship associates an Identity to a specific ManagedElement, whose trust is represented.
//
//              This file was automatically generated from CIM_AssignedIdentity.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_AssignedIdentity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AssignedIdentity::_metadata[] = {
		{"IdentityInfo", true, false, true },
		{"ManagedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_AssignedIdentity::IdentityInfo() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("IdentityInfo"), ret);
		return ret;
	}
	void CIM_AssignedIdentity::IdentityInfo(const CimReference &value)
	{
		SetOrAddField("IdentityInfo", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_AssignedIdentity::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_AssignedIdentity::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_AssignedIdentity::CreateFromCimObject(const CimObject &object)
	{
		CIM_AssignedIdentity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AssignedIdentity>(object);
		}
		else
		{
			ret = new CIM_AssignedIdentity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AssignedIdentity> > CIM_AssignedIdentity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AssignedIdentity>(client, keys);
	}

	void CIM_AssignedIdentity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AssignedIdentity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AssignedIdentity::CLASS_NAME = "CIM_AssignedIdentity";
	const string CIM_AssignedIdentity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssignedIdentity";
	const string CIM_AssignedIdentity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssignedIdentity";
	const string CIM_AssignedIdentity::CLASS_NS_PREFIX = "AAs588";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AssignedIdentity::_classMetaData;
}
}
}
}
