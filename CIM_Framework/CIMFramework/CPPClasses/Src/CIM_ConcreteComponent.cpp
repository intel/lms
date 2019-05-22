//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ConcreteComponent.cpp
//
//  Contents:   CIM_ConcreteComponent is a generic association used to establish 'part of' relationships between ManagedElements. It is defined as a concrete subclass of the abstract CIM_Component class, to be used in place of many specific subclasses of Component that add no semantics, that is subclasses that do not clarify the type of composition, update cardinalities, or add or remove qualifiers. Note that when you define additional semantics for Component, this class must not be subclassed. Specific semantics continue to be defined as subclasses of the abstract CIM_Component. ConcreteComponent is limited in its use as a concrete form of a general composition. 
//              
//              It was deemed more prudent to create this concrete subclass than to change Component from an abstract to a concrete class. Industry usage and impact could not be anticipated.
//
//              This file was automatically generated from CIM_ConcreteComponent.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ConcreteComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ConcreteComponent::_metadata[] = {
		{"GroupComponent", true, false, true },
		{"PartComponent", true, false, true },
	};
	// class fields
	CimBase *CIM_ConcreteComponent::CreateFromCimObject(const CimObject &object)
	{
		CIM_ConcreteComponent *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ConcreteComponent>(object);
		}
		else
		{
			ret = new CIM_ConcreteComponent(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ConcreteComponent> > CIM_ConcreteComponent::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ConcreteComponent>(client, keys);
	}

	void CIM_ConcreteComponent::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ConcreteComponent::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ConcreteComponent::CLASS_NAME = "CIM_ConcreteComponent";
	const string CIM_ConcreteComponent::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteComponent";
	const string CIM_ConcreteComponent::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteComponent";
	const string CIM_ConcreteComponent::CLASS_NS_PREFIX = "ACo320";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ConcreteComponent::_classMetaData;
}
}
}
}
