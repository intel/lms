//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyCondition.h
//
//  Contents:   A class representing a rule-specific or reusable policy condition to be evaluated in conjunction with a Policy Rule. Since all operational details of a PolicyCondition are provided in subclasses of this object, this class is abstract.
//
//              This file was automatically generated from CIM_PolicyCondition.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYCONDITION_H
#define CIM_POLICYCONDITION_H 1
#include "CIM_Policy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class representing a rule-specific or reusable policy condition to be evaluated in conjunction with a Policy Rule. Since all operational details of a PolicyCondition are provided in subclasses of this object, this class is abstract.
	class CIMFRAMEWORK_API CIM_PolicyCondition  : public CIM_Policy
	{
	public:

		//Default constructor
		CIM_PolicyCondition()
			: CIM_Policy(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicyCondition(ICimWsmanClient *client)
			: CIM_Policy(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~CIM_PolicyCondition(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicyCondition keys
		class CimKeys : public CIM_Policy::CimKeys
		{
		public:
			// Key, Required, The name of the class or the subclass used in the creation of the System object in whose scope this PolicyCondition is defined. 
			// 
			// This property helps to identify the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition. 
			// 
			// Note that this property, and the analogous property SystemName, do not represent propagated keys from an instance of the class System. Instead, they are properties defined in the context of this class, which repeat the values from the instance of System to which this PolicyCondition is related, either directly via the PolicyConditionInPolicyRepository association or indirectly via the PolicyConditionInPolicyRule aggregation.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The name of the class or the subclass used in the creation of the System object in whose scope this PolicyCondition is defined. 
			// 
			// This property helps to identify the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition. 
			// 
			// Note that this property, and the analogous property SystemName, do not represent propagated keys from an instance of the class System. Instead, they are properties defined in the context of this class, which repeat the values from the instance of System to which this PolicyCondition is related, either directly via the PolicyConditionInPolicyRepository association or indirectly via the PolicyConditionInPolicyRule aggregation.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The name of the System object in whose scope this PolicyCondition is defined. 
			// 
			// This property completes the identification of the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The name of the System object in whose scope this PolicyCondition is defined. 
			// 
			// This property completes the identification of the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, For a rule-specific PolicyCondition, the CreationClassName of the PolicyRule object with which this Condition is associated. For a reusable Policy Condition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
			const string PolicyRuleCreationClassName() const
			{
				return GetKey("PolicyRuleCreationClassName");
			}

			// Key, Required, For a rule-specific PolicyCondition, the CreationClassName of the PolicyRule object with which this Condition is associated. For a reusable Policy Condition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
			void PolicyRuleCreationClassName(const string &value)
			{
				SetOrAddKey("PolicyRuleCreationClassName", value);
			}

			// Key, Required, For a rule-specific PolicyCondition, the name of the PolicyRule object with which this Condition is associated. For a reusable PolicyCondition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
			const string PolicyRuleName() const
			{
				return GetKey("PolicyRuleName");
			}

			// Key, Required, For a rule-specific PolicyCondition, the name of the PolicyRule object with which this Condition is associated. For a reusable PolicyCondition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
			void PolicyRuleName(const string &value)
			{
				SetOrAddKey("PolicyRuleName", value);
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

			// Key, Required, A user-friendly name of this PolicyCondition.
			const string PolicyConditionName() const
			{
				return GetKey("PolicyConditionName");
			}

			// Key, Required, A user-friendly name of this PolicyCondition.
			void PolicyConditionName(const string &value)
			{
				SetOrAddKey("PolicyConditionName", value);
			}

		};

		// class fields declarations

		// Key, Required, The name of the class or the subclass used in the creation of the System object in whose scope this PolicyCondition is defined. 
		// 
		// This property helps to identify the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition. 
		// 
		// Note that this property, and the analogous property SystemName, do not represent propagated keys from an instance of the class System. Instead, they are properties defined in the context of this class, which repeat the values from the instance of System to which this PolicyCondition is related, either directly via the PolicyConditionInPolicyRepository association or indirectly via the PolicyConditionInPolicyRule aggregation.
		const string SystemCreationClassName() const;

		// Key, Required, The name of the class or the subclass used in the creation of the System object in whose scope this PolicyCondition is defined. 
		// 
		// This property helps to identify the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition. 
		// 
		// Note that this property, and the analogous property SystemName, do not represent propagated keys from an instance of the class System. Instead, they are properties defined in the context of this class, which repeat the values from the instance of System to which this PolicyCondition is related, either directly via the PolicyConditionInPolicyRepository association or indirectly via the PolicyConditionInPolicyRule aggregation.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The name of the System object in whose scope this PolicyCondition is defined. 
		// 
		// This property completes the identification of the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition.
		const string SystemName() const;

		// Key, Required, The name of the System object in whose scope this PolicyCondition is defined. 
		// 
		// This property completes the identification of the System object in whose scope this instance of PolicyCondition exists. For a rule-specific PolicyCondition, this is the System in whose context the PolicyRule is defined. For a reusable PolicyCondition, this is the instance of PolicyRepository (which is a subclass of System) that holds the Condition.
		void SystemName(const string &value); 


		// Key, Required, For a rule-specific PolicyCondition, the CreationClassName of the PolicyRule object with which this Condition is associated. For a reusable Policy Condition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
		const string PolicyRuleCreationClassName() const;

		// Key, Required, For a rule-specific PolicyCondition, the CreationClassName of the PolicyRule object with which this Condition is associated. For a reusable Policy Condition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
		void PolicyRuleCreationClassName(const string &value); 


		// Key, Required, For a rule-specific PolicyCondition, the name of the PolicyRule object with which this Condition is associated. For a reusable PolicyCondition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
		const string PolicyRuleName() const;

		// Key, Required, For a rule-specific PolicyCondition, the name of the PolicyRule object with which this Condition is associated. For a reusable PolicyCondition, a special value, 'NO RULE', should be used to indicate that this Condition is reusable and not associated with a single PolicyRule.
		void PolicyRuleName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Key, Required, A user-friendly name of this PolicyCondition.
		const string PolicyConditionName() const;

		// Key, Required, A user-friendly name of this PolicyCondition.
		void PolicyConditionName(const string &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicyCondition> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicyCondition(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Policy(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicyCondition(const CimObject &object)
			: CIM_Policy(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Policy::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // CIM_POLICYCONDITION_H
