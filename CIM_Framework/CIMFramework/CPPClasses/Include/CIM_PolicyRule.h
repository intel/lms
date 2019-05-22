//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyRule.h
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
#ifndef CIM_POLICYRULE_H
#define CIM_POLICYRULE_H 1
#include "CIM_PolicySet.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The central class used for representing the 'If Condition then Action' semantics of a policy rule. A PolicyRule condition, in the most general sense, is represented as either an ORed set of ANDed conditions (Disjunctive Normal Form, or DNF) or an ANDed set of ORed conditions (Conjunctive Normal Form, or CNF). Individual conditions may either be negated (NOT C) or unnegated (C). The actions specified by a PolicyRule are to be performed if and only if the PolicyRule condition (whether it is represented in DNF or CNF) evaluates to TRUE. 
	// 
	// The conditions and actions associated with a PolicyRule are modeled, respectively, with subclasses of PolicyCondition and PolicyAction. These condition and action objects are tied to instances of PolicyRule by the PolicyConditionInPolicyRule and PolicyActionInPolicyRule aggregations. 
	// 
	// A PolicyRule may also be associated with one or more policy time periods, indicating the schedule according to which the policy rule is active and inactive. In this case it is the PolicySetValidityPeriod aggregation that provides this linkage. 
	// 
	// The PolicyRule class uses the property ConditionListType, to indicate whether the conditions for the rule are in DNF (disjunctive normal form), CNF (conjunctive normal form) or, in the case of a rule with no conditions, as an UnconditionalRule. The PolicyConditionInPolicyRule aggregation contains two additional properties to complete the representation of the Rule's conditional expression. The first of these properties is an integer to partition the referenced PolicyConditions into one or more groups, and the second is a Boolean to indicate whether a referenced Condition is negated. An example shows how ConditionListType and these two additional properties provide a unique representation of a set of PolicyConditions in either DNF or CNF. 
	// 
	// Suppose we have a PolicyRule that aggregates five PolicyConditions C1 through C5, with the following values in the properties of the five PolicyConditionInPolicyRule associations: 
	// C1: GroupNumber = 1, ConditionNegated = FALSE 
	// C2: GroupNumber = 1, ConditionNegated = TRUE 
	// C3: GroupNumber = 1, ConditionNegated = FALSE 
	// C4: GroupNumber = 2, ConditionNegated = FALSE 
	// C5: GroupNumber = 2, ConditionNegated = FALSE 
	// 
	// If ConditionListType = DNF, then the overall condition for the PolicyRule is: 
	// (C1 AND (NOT C2) AND C3) OR (C4 AND C5) 
	// 
	// On the other hand, if ConditionListType = CNF, then the overall condition for the PolicyRule is: 
	// (C1 OR (NOT C2) OR C3) AND (C4 OR C5) 
	// 
	// In both cases, there is an unambiguous specification of the overall condition that is tested to determine whether to perform the PolicyActions associated with the PolicyRule. 
	// 
	// PolicyRule instances may also be used to aggregate other PolicyRules and/or PolicyGroups. When used in this way to implement nested rules, the conditions of the aggregating rule apply to the subordinate rules as well. However, any side effects of condition evaluation or the execution of actions MUST NOT affect the result of the evaluation of other conditions evaluated by the rule engine in the same evaluation pass. That is, an implementation of a rule engine MAY evaluate all conditions in any order before applying the priority and determining which actions are to be executed.
	class CIMFRAMEWORK_API CIM_PolicyRule  : public CIM_PolicySet
	{
	public:

		//Default constructor
		CIM_PolicyRule()
			: CIM_PolicySet(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySet::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicyRule(ICimWsmanClient *client)
			: CIM_PolicySet(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySet::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_PolicyRule(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicyRule keys
		class CimKeys : public CIM_PolicySet::CimKeys
		{
		public:
			// Key, Required, The scoping System's CreationClassName.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The scoping System's CreationClassName.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The scoping System's Name.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The scoping System's Name.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, A user-friendly name of this PolicyRule.
			const string PolicyRuleName() const
			{
				return GetKey("PolicyRuleName");
			}

			// Key, Required, A user-friendly name of this PolicyRule.
			void PolicyRuleName(const string &value)
			{
				SetOrAddKey("PolicyRuleName", value);
			}

		};

		// class fields declarations

		// Key, Required, The scoping System's CreationClassName.
		const string SystemCreationClassName() const;

		// Key, Required, The scoping System's CreationClassName.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The scoping System's Name.
		const string SystemName() const;

		// Key, Required, The scoping System's Name.
		void SystemName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Key, Required, A user-friendly name of this PolicyRule.
		const string PolicyRuleName() const;

		// Key, Required, A user-friendly name of this PolicyRule.
		void PolicyRuleName(const string &value); 


		// Optional, Indicates whether the list of PolicyConditions associated with this PolicyRule is in disjunctive normal form (DNF), conjunctive normal form (CNF), or has no conditions (i.e., is an UnconditionalRule) and is automatically evaluated to "True." The default value is 1 ("DNF").
		const unsigned short ConditionListType() const;

		// Optional, Indicates whether the list of PolicyConditions associated with this PolicyRule is in disjunctive normal form (DNF), conjunctive normal form (CNF), or has no conditions (i.e., is an UnconditionalRule) and is automatically evaluated to "True." The default value is 1 ("DNF").
		void ConditionListType(const unsigned short value); 

		// Is true if the field ConditionListType exists in the current object, otherwise is false.
		bool ConditionListTypeExists() const;

		// Remove ConditionListType field.
		void RemoveConditionListType(); 

		// Optional, A free-form string that can be used to provide guidelines on how this PolicyRule should be used.
		const string RuleUsage() const;

		// Optional, A free-form string that can be used to provide guidelines on how this PolicyRule should be used.
		void RuleUsage(const string &value); 

		// Is true if the field RuleUsage exists in the current object, otherwise is false.
		bool RuleUsageExists() const;

		// Remove RuleUsage field.
		void RemoveRuleUsage(); 

		// Optional, PolicyRule.Priority is deprecated and replaced by providing the priority for a rule (and a group) in the context of the aggregating PolicySet instead of the priority being used for all aggregating PolicySet instances. Thus, the assignment of priority values is much simpler. 
		// 
		// A non-negative integer for prioritizing this Policy Rule relative to other Rules. A larger value indicates a higher priority. The default value is 0.
		const unsigned short Priority() const;

		// Optional, PolicyRule.Priority is deprecated and replaced by providing the priority for a rule (and a group) in the context of the aggregating PolicySet instead of the priority being used for all aggregating PolicySet instances. Thus, the assignment of priority values is much simpler. 
		// 
		// A non-negative integer for prioritizing this Policy Rule relative to other Rules. A larger value indicates a higher priority. The default value is 0.
		void Priority(const unsigned short value); 

		// Is true if the field Priority exists in the current object, otherwise is false.
		bool PriorityExists() const;

		// Remove Priority field.
		void RemovePriority(); 

		// Optional, A flag indicating that the evaluation of the Policy Conditions and execution of PolicyActions (if the Conditions evaluate to TRUE) is required. The evaluation of a PolicyRule MUST be attempted if the Mandatory property value is TRUE. If the Mandatory property is FALSE, then the evaluation of the Rule is 'best effort' and MAY be ignored.
		const bool Mandatory() const;

		// Optional, A flag indicating that the evaluation of the Policy Conditions and execution of PolicyActions (if the Conditions evaluate to TRUE) is required. The evaluation of a PolicyRule MUST be attempted if the Mandatory property value is TRUE. If the Mandatory property is FALSE, then the evaluation of the Rule is 'best effort' and MAY be ignored.
		void Mandatory(const bool value); 

		// Is true if the field Mandatory exists in the current object, otherwise is false.
		bool MandatoryExists() const;

		// Remove Mandatory field.
		void RemoveMandatory(); 

		// Optional, This property gives a policy administrator a way of specifying how the ordering of the PolicyActions associated with this PolicyRule is to be interpreted. Three values are supported: 
		// o mandatory(1): Do the actions in the indicated order, or don't do them at all. 
		// o recommended(2): Do the actions in the indicated order if you can, but if you can't do them in this order, do them in another order if you can. 
		// o dontCare(3): Do them -- I don't care about the order. 
		// The default value is 3 ("DontCare").
		const unsigned short SequencedActions() const;

		// Optional, This property gives a policy administrator a way of specifying how the ordering of the PolicyActions associated with this PolicyRule is to be interpreted. Three values are supported: 
		// o mandatory(1): Do the actions in the indicated order, or don't do them at all. 
		// o recommended(2): Do the actions in the indicated order if you can, but if you can't do them in this order, do them in another order if you can. 
		// o dontCare(3): Do them -- I don't care about the order. 
		// The default value is 3 ("DontCare").
		void SequencedActions(const unsigned short value); 

		// Is true if the field SequencedActions exists in the current object, otherwise is false.
		bool SequencedActionsExists() const;

		// Remove SequencedActions field.
		void RemoveSequencedActions(); 

		// Optional, ExecutionStrategy defines the strategy to be used in executing the sequenced actions aggregated by this PolicyRule. There are three execution strategies: 
		// 
		// Do Until Success - execute actions according to predefined order, until successful execution of a single action. 
		// Do All - execute ALL actions which are part of the modeled set, according to their predefined order. Continue doing this, even if one or more of the actions fails. 
		// Do Until Failure - execute actions according to predefined order, until the first failure in execution of an action instance.
		const unsigned short ExecutionStrategy() const;

		// Optional, ExecutionStrategy defines the strategy to be used in executing the sequenced actions aggregated by this PolicyRule. There are three execution strategies: 
		// 
		// Do Until Success - execute actions according to predefined order, until successful execution of a single action. 
		// Do All - execute ALL actions which are part of the modeled set, according to their predefined order. Continue doing this, even if one or more of the actions fails. 
		// Do Until Failure - execute actions according to predefined order, until the first failure in execution of an action instance.
		void ExecutionStrategy(const unsigned short value); 

		// Is true if the field ExecutionStrategy exists in the current object, otherwise is false.
		bool ExecutionStrategyExists() const;

		// Remove ExecutionStrategy field.
		void RemoveExecutionStrategy(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicyRule> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicyRule(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicySet(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySet::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicyRule(const CimObject &object)
			: CIM_PolicySet(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySet::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicySet::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
		static const CimFieldAttribute _metadata[];
		static const string CLASS_NAME;
		static const string CLASS_URI;
		static const string CLASS_NS;
		static const string CLASS_NS_PREFIX;
		static vector<CimFieldAttribute> _classMetaData;
	};

} // close namespace Typed
} // close namespace Cim
} // close namespace Manageability
} // close namespace Intel
#endif // CIM_POLICYRULE_H
