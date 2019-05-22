//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceSAPDependency.cpp
//
//  Contents:   CIM_ServiceSAPDependency is an association between a Service and a ServiceAccessPoint that indicates that the referenced SAP is utilized by the Service to provide its functionality. For example, Boot Services can invoke BIOS Disk Services (interrupts) in order to function.
//
//              This file was automatically generated from CIM_ServiceSAPDependency.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceSAPDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceSAPDependency::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ServiceSAPDependency::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceSAPDependency *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceSAPDependency>(object);
		}
		else
		{
			ret = new CIM_ServiceSAPDependency(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceSAPDependency> > CIM_ServiceSAPDependency::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceSAPDependency>(client, keys);
	}

	void CIM_ServiceSAPDependency::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceSAPDependency::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ServiceSAPDependency::CLASS_NAME = "CIM_ServiceSAPDependency";
	const string CIM_ServiceSAPDependency::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceSAPDependency";
	const string CIM_ServiceSAPDependency::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceSAPDependency";
	const string CIM_ServiceSAPDependency::CLASS_NS_PREFIX = "ASe920";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceSAPDependency::_classMetaData;
}
}
}
}
