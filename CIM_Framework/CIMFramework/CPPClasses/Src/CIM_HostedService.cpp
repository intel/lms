//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_HostedService.cpp
//
//  Contents:   CIM_HostedService is an association between a Service and the System on which the functionality is located. The cardinality of this association is one-to-many. A System can host many Services. Services are weak with respect to their hosting System. Heuristic: A Service is hosted on the System where the LogicalDevices or SoftwareFeatures that implement the Service are located. The model does not represent Services hosted across multiple systems. The model is as an ApplicationSystem that acts as an aggregation point for Services that are each located on a single host.
//
//              This file was automatically generated from CIM_HostedService.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_HostedService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_HostedService::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_HostedService::CreateFromCimObject(const CimObject &object)
	{
		CIM_HostedService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_HostedService>(object);
		}
		else
		{
			ret = new CIM_HostedService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_HostedService> > CIM_HostedService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_HostedService>(client, keys);
	}

	void CIM_HostedService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_HostedService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_HostedService::CLASS_NAME = "CIM_HostedService";
	const string CIM_HostedService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedService";
	const string CIM_HostedService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_HostedService";
	const string CIM_HostedService::CLASS_NS_PREFIX = "AHo710";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_HostedService::_classMetaData;
}
}
}
}
