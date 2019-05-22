//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareFeatureSoftwareElements.cpp
//
//  Contents:   SoftwareFeatureSoftwareElements identifies the Software Elements that make up a particular SoftwareFeature.
//
//              This file was automatically generated from CIM_SoftwareFeatureSoftwareElements.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_SoftwareFeatureSoftwareElements.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SoftwareFeatureSoftwareElements::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_SoftwareFeatureSoftwareElements::CreateFromCimObject(const CimObject &object)
	{
		CIM_SoftwareFeatureSoftwareElements *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SoftwareFeatureSoftwareElements>(object);
		}
		else
		{
			ret = new CIM_SoftwareFeatureSoftwareElements(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SoftwareFeatureSoftwareElements> > CIM_SoftwareFeatureSoftwareElements::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SoftwareFeatureSoftwareElements>(client, keys);
	}

	void CIM_SoftwareFeatureSoftwareElements::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SoftwareFeatureSoftwareElements::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SoftwareFeatureSoftwareElements::CLASS_NAME = "CIM_SoftwareFeatureSoftwareElements";
	const string CIM_SoftwareFeatureSoftwareElements::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareFeatureSoftwareElements";
	const string CIM_SoftwareFeatureSoftwareElements::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareFeatureSoftwareElements";
	const string CIM_SoftwareFeatureSoftwareElements::CLASS_NS_PREFIX = "ASo315";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SoftwareFeatureSoftwareElements::_classMetaData;
}
}
}
}
