//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyCondition.cpp
//
//  Contents:   A class representing a rule-specific or reusable policy condition to be evaluated in conjunction with a Policy Rule. Since all operational details of a PolicyCondition are provided in subclasses of this object, this class is abstract.
//
//              This file was automatically generated from CIM_PolicyCondition.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicyCondition.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicyCondition::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"PolicyRuleCreationClassName", true, false, false },
		{"PolicyRuleName", true, false, false },
		{"CreationClassName", true, false, false },
		{"PolicyConditionName", true, false, false },
	};
	// class fields
	const string CIM_PolicyCondition::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_PolicyCondition::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_PolicyCondition::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_PolicyCondition::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_PolicyCondition::PolicyRuleCreationClassName() const
	{
		return GetField("PolicyRuleCreationClassName")[0];
	}
	void CIM_PolicyCondition::PolicyRuleCreationClassName(const string &value)
	{
		SetOrAddField("PolicyRuleCreationClassName", value);
	}

	const string CIM_PolicyCondition::PolicyRuleName() const
	{
		return GetField("PolicyRuleName")[0];
	}
	void CIM_PolicyCondition::PolicyRuleName(const string &value)
	{
		SetOrAddField("PolicyRuleName", value);
	}

	const string CIM_PolicyCondition::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_PolicyCondition::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_PolicyCondition::PolicyConditionName() const
	{
		return GetField("PolicyConditionName")[0];
	}
	void CIM_PolicyCondition::PolicyConditionName(const string &value)
	{
		SetOrAddField("PolicyConditionName", value);
	}

	CimBase *CIM_PolicyCondition::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicyCondition *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicyCondition>(object);
		}
		else
		{
			ret = new CIM_PolicyCondition(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicyCondition> > CIM_PolicyCondition::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicyCondition>(client, keys);
	}

	void CIM_PolicyCondition::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicyCondition::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicyCondition::CLASS_NAME = "CIM_PolicyCondition";
	const string CIM_PolicyCondition::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyCondition";
	const string CIM_PolicyCondition::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyCondition";
	const string CIM_PolicyCondition::CLASS_NS_PREFIX = "APo895";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicyCondition::_classMetaData;
}
}
}
}
