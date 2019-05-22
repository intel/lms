//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProvidesServiceToElement.cpp
//
//  Contents:   Note: The use of the CIM_ProvidesServiceToElement class has been deprecated. Instead, ServiceAvailableToElement conveys the semantics of use, while the subclasses of ProvidesServiceToElement (or the ConcreteDependency association) describe dependency relationships. CIM_ProvidesServiceToElement was meant to generalize the ServiceServiceDependency association. This method indicates that ManagedElements can use the functionality provided by one or more Services. An example of the association is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of the service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated.
//
//              This file was automatically generated from CIM_ProvidesServiceToElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ProvidesServiceToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ProvidesServiceToElement::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ProvidesServiceToElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ProvidesServiceToElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ProvidesServiceToElement>(object);
		}
		else
		{
			ret = new CIM_ProvidesServiceToElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ProvidesServiceToElement> > CIM_ProvidesServiceToElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ProvidesServiceToElement>(client, keys);
	}

	void CIM_ProvidesServiceToElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ProvidesServiceToElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ProvidesServiceToElement::CLASS_NAME = "CIM_ProvidesServiceToElement";
	const string CIM_ProvidesServiceToElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProvidesServiceToElement";
	const string CIM_ProvidesServiceToElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProvidesServiceToElement";
	const string CIM_ProvidesServiceToElement::CLASS_NS_PREFIX = "APr402";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ProvidesServiceToElement::_classMetaData;
}
}
}
}
