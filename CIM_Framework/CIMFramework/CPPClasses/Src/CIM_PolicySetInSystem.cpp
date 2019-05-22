//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySetInSystem.cpp
//
//  Contents:   PolicySetInSystem is an abstract association class that represents a relationship between a System and a PolicySet used in the administrative scope of that system (e.g., AdminDomain, ComputerSystem). The Priority property is used to assign a relative priority to a PolicySet within the administrative scope in contexts where it is not a component of another PolicySet.
//
//              This file was automatically generated from CIM_PolicySetInSystem.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicySetInSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicySetInSystem::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"Priority", false, false, false },
	};
	// class fields
	const unsigned short CIM_PolicySetInSystem::Priority() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Priority"), ret);
		return ret;
	}
	void CIM_PolicySetInSystem::Priority(const unsigned short value)
	{
		SetOrAddField("Priority", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicySetInSystem::PriorityExists() const
	{
		return ContainsField("Priority");
	}
	void CIM_PolicySetInSystem::RemovePriority()
	{
		RemoveField("Priority");
	}

	CimBase *CIM_PolicySetInSystem::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicySetInSystem *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicySetInSystem>(object);
		}
		else
		{
			ret = new CIM_PolicySetInSystem(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicySetInSystem> > CIM_PolicySetInSystem::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicySetInSystem>(client, keys);
	}

	void CIM_PolicySetInSystem::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicySetInSystem::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicySetInSystem::CLASS_NAME = "CIM_PolicySetInSystem";
	const string CIM_PolicySetInSystem::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySetInSystem";
	const string CIM_PolicySetInSystem::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySetInSystem";
	const string CIM_PolicySetInSystem::CLASS_NS_PREFIX = "APo852";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicySetInSystem::_classMetaData;
}
}
}
}
