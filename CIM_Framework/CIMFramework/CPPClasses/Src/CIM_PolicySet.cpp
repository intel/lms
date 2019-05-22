//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySet.cpp
//
//  Contents:   PolicySet is an abstract class that represents a set of policies that form a coherent set. The set of contained policies has a common decision strategy and a common set of policy roles (defined via the PolicySetInRole Collection association). Subclasses include PolicyGroup and PolicyRule.
//
//              This file was automatically generated from CIM_PolicySet.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicySet.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicySet::_metadata[] = {
		{"PolicyDecisionStrategy", false, false, false },
		{"PolicyRoles", false, false, false },
		{"Enabled", false, false, false },
	};
	// class fields
	const unsigned short CIM_PolicySet::PolicyDecisionStrategy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PolicyDecisionStrategy"), ret);
		return ret;
	}
	void CIM_PolicySet::PolicyDecisionStrategy(const unsigned short value)
	{
		SetOrAddField("PolicyDecisionStrategy", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicySet::PolicyDecisionStrategyExists() const
	{
		return ContainsField("PolicyDecisionStrategy");
	}
	void CIM_PolicySet::RemovePolicyDecisionStrategy()
	{
		RemoveField("PolicyDecisionStrategy");
	}

	const vector<string> CIM_PolicySet::PolicyRoles() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("PolicyRoles"), ret);
		return ret;
	}
	void CIM_PolicySet::PolicyRoles(const vector<string> &value)
	{
		SetOrAddField("PolicyRoles", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicySet::PolicyRolesExists() const
	{
		return ContainsField("PolicyRoles");
	}
	void CIM_PolicySet::RemovePolicyRoles()
	{
		RemoveField("PolicyRoles");
	}

	const unsigned short CIM_PolicySet::Enabled() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void CIM_PolicySet::Enabled(const unsigned short value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicySet::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void CIM_PolicySet::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *CIM_PolicySet::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicySet *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicySet>(object);
		}
		else
		{
			ret = new CIM_PolicySet(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicySet> > CIM_PolicySet::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicySet>(client, keys);
	}

	void CIM_PolicySet::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicySet::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicySet::CLASS_NAME = "CIM_PolicySet";
	const string CIM_PolicySet::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySet";
	const string CIM_PolicySet::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicySet";
	const string CIM_PolicySet::CLASS_NS_PREFIX = "APo728";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicySet::_classMetaData;
}
}
}
}
