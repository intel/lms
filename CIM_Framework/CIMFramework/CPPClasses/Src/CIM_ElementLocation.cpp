//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementLocation.cpp
//
//  Contents:   ElementLocation associates a ManagedElement with a location for positioning, inventory, maintenance and similar purposes. PhysicalElements can certainly have locations. They are explicitly defined in a subclass, PhysicalElement Location. However, other ManagedElements can also be associated with locations. For example, Organizations can be 'in' one or more locations, or Services can be restricted to a location.
//
//              This file was automatically generated from CIM_ElementLocation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ElementLocation.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementLocation::_metadata[] = {
		{"Element", true, false, true },
		{"PhysicalLocation", true, false, true },
	};
	// class fields
	const CimReference CIM_ElementLocation::Element() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Element"), ret);
		return ret;
	}
	void CIM_ElementLocation::Element(const CimReference &value)
	{
		SetOrAddField("Element", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ElementLocation::PhysicalLocation() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("PhysicalLocation"), ret);
		return ret;
	}
	void CIM_ElementLocation::PhysicalLocation(const CimReference &value)
	{
		SetOrAddField("PhysicalLocation", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_ElementLocation::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementLocation *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementLocation>(object);
		}
		else
		{
			ret = new CIM_ElementLocation(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementLocation> > CIM_ElementLocation::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementLocation>(client, keys);
	}

	void CIM_ElementLocation::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementLocation::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementLocation::CLASS_NAME = "CIM_ElementLocation";
	const string CIM_ElementLocation::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementLocation";
	const string CIM_ElementLocation::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementLocation";
	const string CIM_ElementLocation::CLASS_NS_PREFIX = "AEl41";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementLocation::_classMetaData;
}
}
}
}
