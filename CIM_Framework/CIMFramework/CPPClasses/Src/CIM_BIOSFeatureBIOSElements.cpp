//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSFeatureBIOSElements.cpp
//
//  Contents:   A link between BIOSFeature and its aggregated BIOSElements.
//
//              This file was automatically generated from CIM_BIOSFeatureBIOSElements.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_BIOSFeatureBIOSElements.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BIOSFeatureBIOSElements::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_BIOSFeatureBIOSElements::CreateFromCimObject(const CimObject &object)
	{
		CIM_BIOSFeatureBIOSElements *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BIOSFeatureBIOSElements>(object);
		}
		else
		{
			ret = new CIM_BIOSFeatureBIOSElements(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BIOSFeatureBIOSElements> > CIM_BIOSFeatureBIOSElements::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BIOSFeatureBIOSElements>(client, keys);
	}

	void CIM_BIOSFeatureBIOSElements::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BIOSFeatureBIOSElements::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_BIOSFeatureBIOSElements::CLASS_NAME = "CIM_BIOSFeatureBIOSElements";
	const string CIM_BIOSFeatureBIOSElements::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSFeatureBIOSElements";
	const string CIM_BIOSFeatureBIOSElements::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSFeatureBIOSElements";
	const string CIM_BIOSFeatureBIOSElements::CLASS_NS_PREFIX = "ABI539";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BIOSFeatureBIOSElements::_classMetaData;
}
}
}
}
