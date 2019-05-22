//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemComponent.cpp
//
//  Contents:   CIM_SystemComponent is a specialization of the CIM_Component association that establishes 'part of' relationships between a System and any ManagedSystemElements of which it is composed. 
//              Use this association with caution when using it instead of a subclass such as SystemDevice or a peer association such as HostedService. This class is very broadly defined, which can lead to erroneous use. For example, Access Points that are dependent on (and hosted on) a System are NOT Components of the System. The System is not made up of any AccessPoint 'parts', which is why a Dependency association, HostedAccessPoint, was defined. Similarly, a PhysicalPackage is not a 'part' of a System, because the physical element exists independently of any internal components, software, and so on. In fact, again, a Dependency relationship is true where a ComputerSystem is Dependent on its packaging, as described by the ComputerSystemPackage association.
//
//              This file was automatically generated from CIM_SystemComponent.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_SystemComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SystemComponent::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_SystemComponent::CreateFromCimObject(const CimObject &object)
	{
		CIM_SystemComponent *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SystemComponent>(object);
		}
		else
		{
			ret = new CIM_SystemComponent(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SystemComponent> > CIM_SystemComponent::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SystemComponent>(client, keys);
	}

	void CIM_SystemComponent::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SystemComponent::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SystemComponent::CLASS_NAME = "CIM_SystemComponent";
	const string CIM_SystemComponent::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemComponent";
	const string CIM_SystemComponent::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SystemComponent";
	const string CIM_SystemComponent::CLASS_NS_PREFIX = "ASy422";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SystemComponent::_classMetaData;
}
}
}
}
