//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OrderedComponent.cpp
//
//  Contents:   CIM_OrderedComponent is a generic association used to establish 'part of' relationships between ManagedElements. It arranges the PartComponents in a specific assigned order. The semantics of the order depends on the context and use by the referencing classes. For example, if this association is used to arrange settings in a hierarchical order, then this specifies the sequence in which the settings are applied.
//
//              This file was automatically generated from CIM_OrderedComponent.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#include "CIM_OrderedComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_OrderedComponent::_metadata[] = {
		{"AssignedSequence", false, false, false },
	};
	// class fields
	const Uint64 CIM_OrderedComponent::AssignedSequence() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("AssignedSequence"), ret);
		return ret;
	}
	void CIM_OrderedComponent::AssignedSequence(const Uint64 value)
	{
		SetOrAddField("AssignedSequence", TypeConverter::TypeToString(value));
	}
	bool CIM_OrderedComponent::AssignedSequenceExists() const
	{
		return ContainsField("AssignedSequence");
	}
	void CIM_OrderedComponent::RemoveAssignedSequence()
	{
		RemoveField("AssignedSequence");
	}

	CimBase *CIM_OrderedComponent::CreateFromCimObject(const CimObject &object)
	{
		CIM_OrderedComponent *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_OrderedComponent>(object);
		}
		else
		{
			ret = new CIM_OrderedComponent(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_OrderedComponent> > CIM_OrderedComponent::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_OrderedComponent>(client, keys);
	}

	void CIM_OrderedComponent::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_OrderedComponent::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_OrderedComponent::CLASS_NAME = "CIM_OrderedComponent";
	const string CIM_OrderedComponent::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OrderedComponent";
	const string CIM_OrderedComponent::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OrderedComponent";
	const string CIM_OrderedComponent::CLASS_NS_PREFIX = "AOr352";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_OrderedComponent::_classMetaData;
}
}
}
}
