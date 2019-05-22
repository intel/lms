//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Component.cpp
//
//  Contents:   CIM_Component is a generic association used to establish 'part of' relationships between Managed Elements. For example, it could be used to define the components or parts of a System.
//
//              This file was automatically generated from CIM_Component.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_Component.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Component::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	const CimReference CIM_Component::GroupComponent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("GroupComponent"), ret);
		return ret;
	}
	void CIM_Component::GroupComponent(const CimReference &value)
	{
		SetOrAddField("GroupComponent", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_Component::PartComponent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("PartComponent"), ret);
		return ret;
	}
	void CIM_Component::PartComponent(const CimReference &value)
	{
		SetOrAddField("PartComponent", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_Component::CreateFromCimObject(const CimObject &object)
	{
		CIM_Component *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Component>(object);
		}
		else
		{
			ret = new CIM_Component(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Component> > CIM_Component::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Component>(client, keys);
	}

	void CIM_Component::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Component::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Component::CLASS_NAME = "CIM_Component";
	const string CIM_Component::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Component";
	const string CIM_Component::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Component";
	const string CIM_Component::CLASS_NS_PREFIX = "ACo837";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Component::_classMetaData;
}
}
}
}
