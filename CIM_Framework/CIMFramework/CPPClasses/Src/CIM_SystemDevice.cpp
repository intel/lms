//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemDevice.cpp
//
//  Contents:   LogicalDevices can be aggregated by a System. This relationship is made explicit by the SystemDevice association.
//
//              This file was automatically generated from CIM_SystemDevice.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_SystemDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SystemDevice::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_SystemDevice::CreateFromCimObject(const CimObject &object)
	{
		CIM_SystemDevice *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SystemDevice>(object);
		}
		else
		{
			ret = new CIM_SystemDevice(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SystemDevice> > CIM_SystemDevice::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SystemDevice>(client, keys);
	}

	void CIM_SystemDevice::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SystemDevice::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SystemDevice::CLASS_NAME = "CIM_SystemDevice";
	const string CIM_SystemDevice::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemDevice";
	const string CIM_SystemDevice::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemDevice";
	const string CIM_SystemDevice::CLASS_NS_PREFIX = "ASy115";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SystemDevice::_classMetaData;
}
}
}
}
