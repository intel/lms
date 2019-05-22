//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ConcreteDependency.cpp
//
//  Contents:   CIM_ConcreteDependency is a generic association used to establish dependency relationships between ManagedElements. It is defined as a concrete subclass of the abstract CIM_Dependency class, to be used in place of many specific subclasses of Dependency that add no semantics, that is subclasses that do not clarify the type of dependency, update cardinalities, or add or remove qualifiers. Note that when you define additional semantics for Dependency, this class must not be subclassed. Specific semantics continue to be defined as subclasses of the abstract CIM_Dependency. ConcreteDependency is limited in its use as a concrete form of a general dependency. 
//              
//              It was deemed more prudent to create this concrete subclass than to change Dependency from an abstract to a concrete class. Dependency already had multiple abstract subclasses in the CIM Schema, and wider industry usage and impact could not be anticipated.
//
//              This file was automatically generated from CIM_ConcreteDependency.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ConcreteDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ConcreteDependency::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ConcreteDependency::CreateFromCimObject(const CimObject &object)
	{
		CIM_ConcreteDependency *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ConcreteDependency>(object);
		}
		else
		{
			ret = new CIM_ConcreteDependency(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ConcreteDependency> > CIM_ConcreteDependency::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ConcreteDependency>(client, keys);
	}

	void CIM_ConcreteDependency::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ConcreteDependency::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ConcreteDependency::CLASS_NAME = "CIM_ConcreteDependency";
	const string CIM_ConcreteDependency::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteDependency";
	const string CIM_ConcreteDependency::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteDependency";
	const string CIM_ConcreteDependency::CLASS_NS_PREFIX = "ACo536";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ConcreteDependency::_classMetaData;
}
}
}
}
