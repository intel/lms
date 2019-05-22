//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Location.cpp
//
//  Contents:   The Location class specifies the position and address of a PhysicalElement.
//
//              This file was automatically generated from CIM_Location.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_Location.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Location::_metadata[] = {
		{"Name", true, false, false },
		{"PhysicalPosition", true, false, false },
		{"Address", false, false, false },
	};
	// class fields
	const string CIM_Location::Name() const
	{
		return GetField("Name")[0];
	}
	void CIM_Location::Name(const string &value)
	{
		SetOrAddField("Name", value);
	}

	const string CIM_Location::PhysicalPosition() const
	{
		return GetField("PhysicalPosition")[0];
	}
	void CIM_Location::PhysicalPosition(const string &value)
	{
		SetOrAddField("PhysicalPosition", value);
	}

	const string CIM_Location::Address() const
	{
		return GetField("Address")[0];
	}
	void CIM_Location::Address(const string &value)
	{
		SetOrAddField("Address", value);
	}
	bool CIM_Location::AddressExists() const
	{
		return ContainsField("Address");
	}
	void CIM_Location::RemoveAddress()
	{
		RemoveField("Address");
	}

	CimBase *CIM_Location::CreateFromCimObject(const CimObject &object)
	{
		CIM_Location *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Location>(object);
		}
		else
		{
			ret = new CIM_Location(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Location> > CIM_Location::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Location>(client, keys);
	}

	void CIM_Location::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Location::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Location::CLASS_NAME = "CIM_Location";
	const string CIM_Location::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Location";
	const string CIM_Location::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Location";
	const string CIM_Location::CLASS_NS_PREFIX = "ALo173";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Location::_classMetaData;
}
}
}
}
