//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAvailableToElement.cpp
//
//  Contents:   CIM_ServiceAvailableToElement conveys the semantics of a Service that is available for the use of a ManagedElement. An example of an available Service is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of this service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated between the Service and specific CIM_Processors and CIM_Chassis.
//
//              This file was automatically generated from CIM_ServiceAvailableToElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceAvailableToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceAvailableToElement::_metadata[] = {
		{"ServiceProvided", true, false, true },
		{"UserOfService", true, false, true },
	};
	// class fields
	const CimReference CIM_ServiceAvailableToElement::ServiceProvided() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ServiceProvided"), ret);
		return ret;
	}
	void CIM_ServiceAvailableToElement::ServiceProvided(const CimReference &value)
	{
		SetOrAddField("ServiceProvided", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ServiceAvailableToElement::UserOfService() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("UserOfService"), ret);
		return ret;
	}
	void CIM_ServiceAvailableToElement::UserOfService(const CimReference &value)
	{
		SetOrAddField("UserOfService", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_ServiceAvailableToElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceAvailableToElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceAvailableToElement>(object);
		}
		else
		{
			ret = new CIM_ServiceAvailableToElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceAvailableToElement> > CIM_ServiceAvailableToElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceAvailableToElement>(client, keys);
	}

	void CIM_ServiceAvailableToElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceAvailableToElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ServiceAvailableToElement::CLASS_NAME = "CIM_ServiceAvailableToElement";
	const string CIM_ServiceAvailableToElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAvailableToElement";
	const string CIM_ServiceAvailableToElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAvailableToElement";
	const string CIM_ServiceAvailableToElement::CLASS_NS_PREFIX = "ASe515";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceAvailableToElement::_classMetaData;
}
}
}
}
