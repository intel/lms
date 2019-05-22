//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Dependency.cpp
//
//  Contents:   CIM_Dependency is a generic association used to establish dependency relationships between ManagedElements.
//
//              This file was automatically generated from CIM_Dependency.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Dependency::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	const CimReference CIM_Dependency::Antecedent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Antecedent"), ret);
		return ret;
	}
	void CIM_Dependency::Antecedent(const CimReference &value)
	{
		SetOrAddField("Antecedent", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_Dependency::Dependent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Dependent"), ret);
		return ret;
	}
	void CIM_Dependency::Dependent(const CimReference &value)
	{
		SetOrAddField("Dependent", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_Dependency::CreateFromCimObject(const CimObject &object)
	{
		CIM_Dependency *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Dependency>(object);
		}
		else
		{
			ret = new CIM_Dependency(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Dependency> > CIM_Dependency::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Dependency>(client, keys);
	}

	void CIM_Dependency::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Dependency::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Dependency::CLASS_NAME = "CIM_Dependency";
	const string CIM_Dependency::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Dependency";
	const string CIM_Dependency::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Dependency";
	const string CIM_Dependency::CLASS_NS_PREFIX = "ADe155";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Dependency::_classMetaData;
}
}
}
}
