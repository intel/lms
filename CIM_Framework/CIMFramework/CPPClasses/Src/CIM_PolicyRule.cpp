//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyRule.cpp
//
//  Contents:   The central class used for representing the 'If Condition then Action' semantics of a policy rule. A PolicyRule condition, in the most general sense, is represented as either an ORed set of ANDed conditions (Disjunctive Normal Form, or DNF) or an ANDed set of ORed conditions (Conjunctive Normal Form, or CNF). Individual conditions may either be negated (NOT C) or unnegated (C). The actions specified by a PolicyRule are to be performed if and only if the PolicyRule condition (whether it is represented in DNF or CNF) evaluates to TRUE. 
//              
//              The conditions and actions associated with a PolicyRule are modeled, respectively, with subclasses of PolicyCondition and PolicyAction. These condition and action objects are tied to instances of PolicyRule by the PolicyConditionInPolicyRule and PolicyActionInPolicyRule aggregations. 
//              
//              A PolicyRule may also be associated with one or more policy time periods, indicating the schedule according to which the policy rule is active and inactive. In this case it is the PolicySetValidityPeriod aggregation that provides this linkage. 
//              
//              The PolicyRule class uses the property ConditionListType, to indicate whether the conditions for the rule are in DNF (disjunctive normal form), CNF (conjunctive normal form) or, in the case of a rule with no conditions, as an UnconditionalRule. The PolicyConditionInPolicyRule aggregation contains two additional properties to complete the representation of the Rule's conditional expression. The first of these properties is an integer to partition the referenced PolicyConditions into one or more groups, and the second is a Boolean to indicate whether a referenced Condition is negated. An example shows how ConditionListType and these two additional properties provide a unique representation of a set of PolicyConditions in either DNF or CNF. 
//              
//              Suppose we have a PolicyRule that aggregates five PolicyConditions C1 through C5, with the following values in the properties of the five PolicyConditionInPolicyRule associations: 
//              C1: GroupNumber = 1, ConditionNegated = FALSE 
//              C2: GroupNumber = 1, ConditionNegated = TRUE 
//              C3: GroupNumber = 1, ConditionNegated = FALSE 
//              C4: GroupNumber = 2, ConditionNegated = FALSE 
//              C5: GroupNumber = 2, ConditionNegated = FALSE 
//              
//              If ConditionListType = DNF, then the overall condition for the PolicyRule is: 
//              (C1 AND (NOT C2) AND C3) OR (C4 AND C5) 
//              
//              On the other hand, if ConditionListType = CNF, then the overall condition for the PolicyRule is: 
//              (C1 OR (NOT C2) OR C3) AND (C4 OR C5) 
//              
//              In both cases, there is an unambiguous specification of the overall condition that is tested to determine whether to perform the PolicyActions associated with the PolicyRule. 
//              
//              PolicyRule instances may also be used to aggregate other PolicyRules and/or PolicyGroups. When used in this way to implement nested rules, the conditions of the aggregating rule apply to the subordinate rules as well. However, any side effects of condition evaluation or the execution of actions MUST NOT affect the result of the evaluation of other conditions evaluated by the rule engine in the same evaluation pass. That is, an implementation of a rule engine MAY evaluate all conditions in any order before applying the priority and determining which actions are to be executed.
//
//              This file was automatically generated from CIM_PolicyRule.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_PolicyRule.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PolicyRule::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"PolicyRuleName", true, false, false },
		{"ConditionListType", false, false, false },
		{"RuleUsage", false, false, false },
		{"Priority", false, false, false },
		{"Mandatory", false, false, false },
		{"SequencedActions", false, false, false },
		{"ExecutionStrategy", false, false, false },
	};
	// class fields
	const string CIM_PolicyRule::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_PolicyRule::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_PolicyRule::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_PolicyRule::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_PolicyRule::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_PolicyRule::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_PolicyRule::PolicyRuleName() const
	{
		return GetField("PolicyRuleName")[0];
	}
	void CIM_PolicyRule::PolicyRuleName(const string &value)
	{
		SetOrAddField("PolicyRuleName", value);
	}

	const unsigned short CIM_PolicyRule::ConditionListType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ConditionListType"), ret);
		return ret;
	}
	void CIM_PolicyRule::ConditionListType(const unsigned short value)
	{
		SetOrAddField("ConditionListType", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyRule::ConditionListTypeExists() const
	{
		return ContainsField("ConditionListType");
	}
	void CIM_PolicyRule::RemoveConditionListType()
	{
		RemoveField("ConditionListType");
	}

	const string CIM_PolicyRule::RuleUsage() const
	{
		return GetField("RuleUsage")[0];
	}
	void CIM_PolicyRule::RuleUsage(const string &value)
	{
		SetOrAddField("RuleUsage", value);
	}
	bool CIM_PolicyRule::RuleUsageExists() const
	{
		return ContainsField("RuleUsage");
	}
	void CIM_PolicyRule::RemoveRuleUsage()
	{
		RemoveField("RuleUsage");
	}

	const unsigned short CIM_PolicyRule::Priority() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Priority"), ret);
		return ret;
	}
	void CIM_PolicyRule::Priority(const unsigned short value)
	{
		SetOrAddField("Priority", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyRule::PriorityExists() const
	{
		return ContainsField("Priority");
	}
	void CIM_PolicyRule::RemovePriority()
	{
		RemoveField("Priority");
	}

	const bool CIM_PolicyRule::Mandatory() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Mandatory"), ret);
		return ret;
	}
	void CIM_PolicyRule::Mandatory(const bool value)
	{
		SetOrAddField("Mandatory", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyRule::MandatoryExists() const
	{
		return ContainsField("Mandatory");
	}
	void CIM_PolicyRule::RemoveMandatory()
	{
		RemoveField("Mandatory");
	}

	const unsigned short CIM_PolicyRule::SequencedActions() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SequencedActions"), ret);
		return ret;
	}
	void CIM_PolicyRule::SequencedActions(const unsigned short value)
	{
		SetOrAddField("SequencedActions", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyRule::SequencedActionsExists() const
	{
		return ContainsField("SequencedActions");
	}
	void CIM_PolicyRule::RemoveSequencedActions()
	{
		RemoveField("SequencedActions");
	}

	const unsigned short CIM_PolicyRule::ExecutionStrategy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ExecutionStrategy"), ret);
		return ret;
	}
	void CIM_PolicyRule::ExecutionStrategy(const unsigned short value)
	{
		SetOrAddField("ExecutionStrategy", TypeConverter::TypeToString(value));
	}
	bool CIM_PolicyRule::ExecutionStrategyExists() const
	{
		return ContainsField("ExecutionStrategy");
	}
	void CIM_PolicyRule::RemoveExecutionStrategy()
	{
		RemoveField("ExecutionStrategy");
	}

	CimBase *CIM_PolicyRule::CreateFromCimObject(const CimObject &object)
	{
		CIM_PolicyRule *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PolicyRule>(object);
		}
		else
		{
			ret = new CIM_PolicyRule(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PolicyRule> > CIM_PolicyRule::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PolicyRule>(client, keys);
	}

	void CIM_PolicyRule::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PolicyRule::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PolicyRule::CLASS_NAME = "CIM_PolicyRule";
	const string CIM_PolicyRule::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyRule";
	const string CIM_PolicyRule::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PolicyRule";
	const string CIM_PolicyRule::CLASS_NS_PREFIX = "APo434";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PolicyRule::_classMetaData;
}
}
}
}
