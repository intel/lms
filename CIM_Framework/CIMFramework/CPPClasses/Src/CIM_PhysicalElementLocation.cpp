//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalElementLocation.cpp
//
//  Contents:   PhysicalElementLocation associates a PhysicalElement with a Location object for inventory or replacement purposes.
//
//              This file was automatically generated from CIM_PhysicalElementLocation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalElementLocation.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalElementLocation::_metadata[] = {
		{"Element", true, false, true },
		{"PhysicalLocation", true, false, true },
	};
	// class fields
	CimBase *CIM_PhysicalElementLocation::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalElementLocation *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalElementLocation>(object);
		}
		else
		{
			ret = new CIM_PhysicalElementLocation(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalElementLocation> > CIM_PhysicalElementLocation::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalElementLocation>(client, keys);
	}

	void CIM_PhysicalElementLocation::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalElementLocation::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalElementLocation::CLASS_NAME = "CIM_PhysicalElementLocation";
	const string CIM_PhysicalElementLocation::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalElementLocation";
	const string CIM_PhysicalElementLocation::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalElementLocation";
	const string CIM_PhysicalElementLocation::CLASS_NS_PREFIX = "APh822";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalElementLocation::_classMetaData;
}
}
}
}
