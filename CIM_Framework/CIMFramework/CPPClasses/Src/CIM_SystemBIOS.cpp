//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemBIOS.cpp
//
//  Contents:   SystemBIOS associates a UnitaryComputerSystem's BIOS with the System itself.
//
//              This file was automatically generated from CIM_SystemBIOS.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_SystemBIOS.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SystemBIOS::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_SystemBIOS::CreateFromCimObject(const CimObject &object)
	{
		CIM_SystemBIOS *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SystemBIOS>(object);
		}
		else
		{
			ret = new CIM_SystemBIOS(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SystemBIOS> > CIM_SystemBIOS::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SystemBIOS>(client, keys);
	}

	void CIM_SystemBIOS::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SystemBIOS::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SystemBIOS::CLASS_NAME = "CIM_SystemBIOS";
	const string CIM_SystemBIOS::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemBIOS";
	const string CIM_SystemBIOS::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemBIOS";
	const string CIM_SystemBIOS::CLASS_NS_PREFIX = "ASy450";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SystemBIOS::_classMetaData;
}
}
}
}
