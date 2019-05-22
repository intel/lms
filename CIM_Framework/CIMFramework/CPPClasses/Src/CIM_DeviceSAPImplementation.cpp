//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_DeviceSAPImplementation.cpp
//
//  Contents:   An association between a ServiceAccessPoint (SAP) and how it is implemented. The cardinality of this association is many-to-many. A SAP can be provided by more than one LogicalDevice, operating in conjunction. And, any Device can provide more than one ServiceAccessPoint. When many LogicalDevices are associated with a single SAP, it is assumed that these elements operate in conjunction to provide the AccessPoint. If different implementations of a SAP exist, each of these implementations would result in individual instantiations of the ServiceAccessPoint object. These individual instantiations would then have associations to the unique implementations.
//
//              This file was automatically generated from CIM_DeviceSAPImplementation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_DeviceSAPImplementation.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_DeviceSAPImplementation::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_DeviceSAPImplementation::CreateFromCimObject(const CimObject &object)
	{
		CIM_DeviceSAPImplementation *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_DeviceSAPImplementation>(object);
		}
		else
		{
			ret = new CIM_DeviceSAPImplementation(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_DeviceSAPImplementation> > CIM_DeviceSAPImplementation::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_DeviceSAPImplementation>(client, keys);
	}

	void CIM_DeviceSAPImplementation::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_DeviceSAPImplementation::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_DeviceSAPImplementation::CLASS_NAME = "CIM_DeviceSAPImplementation";
	const string CIM_DeviceSAPImplementation::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_DeviceSAPImplementation";
	const string CIM_DeviceSAPImplementation::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_DeviceSAPImplementation";
	const string CIM_DeviceSAPImplementation::CLASS_NS_PREFIX = "ADe238";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_DeviceSAPImplementation::_classMetaData;
}
}
}
}
