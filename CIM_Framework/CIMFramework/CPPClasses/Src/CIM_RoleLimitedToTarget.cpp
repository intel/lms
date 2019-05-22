//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleLimitedToTarget.cpp
//
//  Contents:   The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope. When explicitly restricting the target elements that may be accessed from this Role, this association MUST be used.
//
//              This file was automatically generated from CIM_RoleLimitedToTarget.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_RoleLimitedToTarget.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RoleLimitedToTarget::_metadata[] = {
		{"DefiningRole", true, false, true },
		{"TargetElement", true, false, true },
	};
	// class fields
	const CimReference CIM_RoleLimitedToTarget::DefiningRole() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("DefiningRole"), ret);
		return ret;
	}
	void CIM_RoleLimitedToTarget::DefiningRole(const CimReference &value)
	{
		SetOrAddField("DefiningRole", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_RoleLimitedToTarget::TargetElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("TargetElement"), ret);
		return ret;
	}
	void CIM_RoleLimitedToTarget::TargetElement(const CimReference &value)
	{
		SetOrAddField("TargetElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_RoleLimitedToTarget::CreateFromCimObject(const CimObject &object)
	{
		CIM_RoleLimitedToTarget *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RoleLimitedToTarget>(object);
		}
		else
		{
			ret = new CIM_RoleLimitedToTarget(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RoleLimitedToTarget> > CIM_RoleLimitedToTarget::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RoleLimitedToTarget>(client, keys);
	}

	void CIM_RoleLimitedToTarget::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RoleLimitedToTarget::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RoleLimitedToTarget::CLASS_NAME = "CIM_RoleLimitedToTarget";
	const string CIM_RoleLimitedToTarget::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleLimitedToTarget";
	const string CIM_RoleLimitedToTarget::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RoleLimitedToTarget";
	const string CIM_RoleLimitedToTarget::CLASS_NS_PREFIX = "ARo976";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RoleLimitedToTarget::_classMetaData;
}
}
}
}
