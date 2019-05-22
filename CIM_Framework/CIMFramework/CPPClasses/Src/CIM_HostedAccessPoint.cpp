//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_HostedAccessPoint.cpp
//
//  Contents:   CIM_HostedAccessPoint is an association between a Service AccessPoint and the System on which it is provided. The cardinality of this association is one-to-many and is weak with respect to the System. Each System can host many ServiceAccessPoints. Heuristic: If the implementation of the ServiceAccessPoint is modeled, it must be implemented by a Device or SoftwareFeature that is part of the System that is hosting the ServiceAccessPoint.
//
//              This file was automatically generated from CIM_HostedAccessPoint.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_HostedAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_HostedAccessPoint::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_HostedAccessPoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_HostedAccessPoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_HostedAccessPoint>(object);
		}
		else
		{
			ret = new CIM_HostedAccessPoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_HostedAccessPoint> > CIM_HostedAccessPoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_HostedAccessPoint>(client, keys);
	}

	void CIM_HostedAccessPoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_HostedAccessPoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_HostedAccessPoint::CLASS_NAME = "CIM_HostedAccessPoint";
	const string CIM_HostedAccessPoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedAccessPoint";
	const string CIM_HostedAccessPoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedAccessPoint";
	const string CIM_HostedAccessPoint::CLASS_NS_PREFIX = "AHo595";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_HostedAccessPoint::_classMetaData;
}
}
}
}
