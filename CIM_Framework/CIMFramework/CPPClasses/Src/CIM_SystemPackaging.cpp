//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemPackaging.cpp
//
//  Contents:   Similar to the way that LogicalDevices are 'Realized' by PhysicalElements, Systems can be associated with specific packaging or PhysicalElements. This association explicitly defines the relationship between a System and its packaging.
//
//              This file was automatically generated from CIM_SystemPackaging.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_SystemPackaging.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SystemPackaging::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_SystemPackaging::CreateFromCimObject(const CimObject &object)
	{
		CIM_SystemPackaging *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SystemPackaging>(object);
		}
		else
		{
			ret = new CIM_SystemPackaging(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SystemPackaging> > CIM_SystemPackaging::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SystemPackaging>(client, keys);
	}

	void CIM_SystemPackaging::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SystemPackaging::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SystemPackaging::CLASS_NAME = "CIM_SystemPackaging";
	const string CIM_SystemPackaging::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemPackaging";
	const string CIM_SystemPackaging::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemPackaging";
	const string CIM_SystemPackaging::CLASS_NS_PREFIX = "ASy996";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SystemPackaging::_classMetaData;
}
}
}
}
