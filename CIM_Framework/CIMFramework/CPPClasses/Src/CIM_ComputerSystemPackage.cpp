//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ComputerSystemPackage.cpp
//
//  Contents:   Similar to the way that LogicalDevices are 'Realized' by PhysicalElements, ComputerSystem may be realized realized in one or more PhysicalPackages. The ComputerSystemPackage association explicitly defines this relationship.
//
//              This file was automatically generated from CIM_ComputerSystemPackage.mof,  version: 2.13.0
//
//----------------------------------------------------------------------------
#include "CIM_ComputerSystemPackage.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ComputerSystemPackage::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"PlatformGUID", false, false, false },
	};
	// class fields
	const string CIM_ComputerSystemPackage::PlatformGUID() const
	{
		return GetField("PlatformGUID")[0];
	}
	void CIM_ComputerSystemPackage::PlatformGUID(const string &value)
	{
		SetOrAddField("PlatformGUID", value);
	}
	bool CIM_ComputerSystemPackage::PlatformGUIDExists() const
	{
		return ContainsField("PlatformGUID");
	}
	void CIM_ComputerSystemPackage::RemovePlatformGUID()
	{
		RemoveField("PlatformGUID");
	}

	CimBase *CIM_ComputerSystemPackage::CreateFromCimObject(const CimObject &object)
	{
		CIM_ComputerSystemPackage *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ComputerSystemPackage>(object);
		}
		else
		{
			ret = new CIM_ComputerSystemPackage(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ComputerSystemPackage> > CIM_ComputerSystemPackage::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ComputerSystemPackage>(client, keys);
	}

	void CIM_ComputerSystemPackage::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ComputerSystemPackage::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ComputerSystemPackage::CLASS_NAME = "CIM_ComputerSystemPackage";
	const string CIM_ComputerSystemPackage::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystemPackage";
	const string CIM_ComputerSystemPackage::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystemPackage";
	const string CIM_ComputerSystemPackage::CLASS_NS_PREFIX = "ACo820";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ComputerSystemPackage::_classMetaData;
}
}
}
}
