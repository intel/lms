//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Realizes.cpp
//
//  Contents:   CIM_Realizes is the association that defines the mapping between LogicalDevices and the PhysicalElements that implement them.
//
//              This file was automatically generated from CIM_Realizes.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_Realizes.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Realizes::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_Realizes::CreateFromCimObject(const CimObject &object)
	{
		CIM_Realizes *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Realizes>(object);
		}
		else
		{
			ret = new CIM_Realizes(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Realizes> > CIM_Realizes::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Realizes>(client, keys);
	}

	void CIM_Realizes::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Realizes::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Realizes::CLASS_NAME = "CIM_Realizes";
	const string CIM_Realizes::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Realizes";
	const string CIM_Realizes::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Realizes";
	const string CIM_Realizes::CLASS_NS_PREFIX = "ARe163";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Realizes::_classMetaData;
}
}
}
}
