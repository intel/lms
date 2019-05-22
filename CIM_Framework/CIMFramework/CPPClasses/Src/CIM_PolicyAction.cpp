//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyAction.cpp
//
//  Contents:   A class representing a rule-specific or reusable policy action to be performed if the PolicyConditions for a Policy Rule evaluate to TRUE. Since all operational details of a PolicyAction are provided in subclasses of this object, this class is abstract.
//
//              This file was automatically generated from CIM_PolicyAction.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicyAction.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicyAction::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"PolicyRuleCreationClassName", true, false, false },
		{"PolicyRuleName", true, false, false },
		{"CreationClassName", true, false, false },
		{"PolicyActionName", true, false, false },
		{"DoActionLogging", false, false, false },
	};
	// class fields
	const string CIM_PolicyAction::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_PolicyAction::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_PolicyAction::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_PolicyAction::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_PolicyAction::PolicyRuleCreationClassName() const
	{
		return GetField("PolicyRuleCreationClassName")[0];
	}
	void CIM_PolicyAction::PolicyRuleCreationClassName(const string &value)
	{
		SetOrAddField("PolicyRuleCreationClassName", value);
	}

	const string CIM_PolicyAction::PolicyRuleName() const
	{
		return GetField("PolicyRuleName")[0];
	}
	void CIM_PolicyAction::PolicyRuleName(const string &value)
	{
		SetOrAddField("PolicyRuleName", value);
	}

	const string CIM_PolicyAction::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_PolicyAction::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_PolicyAction::PolicyActionName() const
	{
		return GetField("PolicyActionName")[0];
	}
	void CIM_PolicyAction::PolicyActionName(const string &value)
	{
		SetOrAddField("PolicyActionName", value);
	}

	const bool CIM_PolicyAction::DoActionLogging() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DoActionLogging"), ret);
		return ret;
	}
	void CIM_PolicyAction::DoActionLogging(const bool value)
	{
		SetOrAddField("DoActionLogging", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyAction::DoActionLoggingExists() const
	{
		return ContainsField("DoActionLogging");
	}
	void CIM_PolicyAction::RemoveDoActionLogging()
	{
		RemoveField("DoActionLogging");
	}

	CimBase *CIM_PolicyAction::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicyAction *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicyAction>(object);
		}
		else
		{
			ret = new CIM_PolicyAction(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicyAction> > CIM_PolicyAction::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicyAction>(client, keys);
	}

	void CIM_PolicyAction::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicyAction::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicyAction::CLASS_NAME = "CIM_PolicyAction";
	const string CIM_PolicyAction::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyAction";
	const string CIM_PolicyAction::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyAction";
	const string CIM_PolicyAction::CLASS_NS_PREFIX = "APo504";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicyAction::_classMetaData;
}
}
}
}
