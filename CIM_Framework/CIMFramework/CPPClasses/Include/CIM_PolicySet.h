//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySet.h
//
//  Contents:   PolicySet is an abstract class that represents a set of policies that form a coherent set. The set of contained policies has a common decision strategy and a common set of policy roles (defined via the PolicySetInRole Collection association). Subclasses include PolicyGroup and PolicyRule.
//
//              This file was automatically generated from CIM_PolicySet.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYSET_H
#define CIM_POLICYSET_H 1
#include "CIM_Policy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PolicySet is an abstract class that represents a set of policies that form a coherent set. The set of contained policies has a common decision strategy and a common set of policy roles (defined via the PolicySetInRole Collection association). Subclasses include PolicyGroup and PolicyRule.
	class CIMFRAMEWORK_API CIM_PolicySet  : public CIM_Policy
	{
	public:

		//Default constructor
		CIM_PolicySet()
			: CIM_Policy(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicySet(ICimWsmanClient *client)
			: CIM_Policy(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_PolicySet(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicySet keys
		class CimKeys : public CIM_Policy::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, PolicyDecisionStrategy defines the evaluation method used for policies contained in the PolicySet. There are two values currently defined: 
		// - 'First Matching' (1) executes the actions of the first rule whose conditions evaluate to TRUE. The concept of 'first' is determined by examining the priority of the rule within the policy set (i.e., by examining the property, PolicySetComponent.Priority). Note that this ordering property MUST be maintained when processing the PolicyDecisionStrategy. 
		// - 'All' (2) executes the actions of ALL rules whose conditions evaluate to TRUE, in the set. As noted above, the order of processing of the rules is defined by the property, PolicySetComponent.Priority (and within a rule, the ordering of the actions is defined by the property, PolicyActionStructure.ActionOrder). Note that when this strategy is defined, processing MUST be completed of ALL rules whose conditions evaluate to TRUE, regardless of errors in the execution of the rule actions.
		const unsigned short PolicyDecisionStrategy() const;

		// Optional, PolicyDecisionStrategy defines the evaluation method used for policies contained in the PolicySet. There are two values currently defined: 
		// - 'First Matching' (1) executes the actions of the first rule whose conditions evaluate to TRUE. The concept of 'first' is determined by examining the priority of the rule within the policy set (i.e., by examining the property, PolicySetComponent.Priority). Note that this ordering property MUST be maintained when processing the PolicyDecisionStrategy. 
		// - 'All' (2) executes the actions of ALL rules whose conditions evaluate to TRUE, in the set. As noted above, the order of processing of the rules is defined by the property, PolicySetComponent.Priority (and within a rule, the ordering of the actions is defined by the property, PolicyActionStructure.ActionOrder). Note that when this strategy is defined, processing MUST be completed of ALL rules whose conditions evaluate to TRUE, regardless of errors in the execution of the rule actions.
		void PolicyDecisionStrategy(const unsigned short value); 

		// Is true if the field PolicyDecisionStrategy exists in the current object, otherwise is false.
		bool PolicyDecisionStrategyExists() const;

		// Remove PolicyDecisionStrategy field.
		void RemovePolicyDecisionStrategy(); 

		// Optional, The PolicyRoles property represents the roles associated with a PolicySet. All contained PolicySet instances inherit the values of the PolicyRoles of the aggregating PolicySet but the values are not copied. A contained PolicySet instance may, however, add additional PolicyRoles to those it inherits from its aggregating PolicySet(s). Each value in PolicyRoles multi-valued property represents a role for which the PolicySet applies, i.e., the PolicySet should be used by any enforcement point that assumes any of the listed PolicyRoles values. 
		// 
		// Although not officially designated as 'role combinations', multiple roles may be specified using the form: 
		// <RoleName>[&&<RoleName>]* 
		// where the individual role names appear in alphabetical order (according to the collating sequence for UCS-2). Implementations may treat PolicyRoles values that are specified as 'role combinations' as simple strings. 
		// 
		// This property is deprecated in lieu of the use of an association, CIM_PolicySetInRoleCollection. The latter is a more explicit and less error-prone approach to modeling that a PolicySet has one or more PolicyRoles.
		const vector<string> PolicyRoles() const;

		// Optional, The PolicyRoles property represents the roles associated with a PolicySet. All contained PolicySet instances inherit the values of the PolicyRoles of the aggregating PolicySet but the values are not copied. A contained PolicySet instance may, however, add additional PolicyRoles to those it inherits from its aggregating PolicySet(s). Each value in PolicyRoles multi-valued property represents a role for which the PolicySet applies, i.e., the PolicySet should be used by any enforcement point that assumes any of the listed PolicyRoles values. 
		// 
		// Although not officially designated as 'role combinations', multiple roles may be specified using the form: 
		// <RoleName>[&&<RoleName>]* 
		// where the individual role names appear in alphabetical order (according to the collating sequence for UCS-2). Implementations may treat PolicyRoles values that are specified as 'role combinations' as simple strings. 
		// 
		// This property is deprecated in lieu of the use of an association, CIM_PolicySetInRoleCollection. The latter is a more explicit and less error-prone approach to modeling that a PolicySet has one or more PolicyRoles.
		void PolicyRoles(const vector<string> &value); 

		// Is true if the field PolicyRoles exists in the current object, otherwise is false.
		bool PolicyRolesExists() const;

		// Remove PolicyRoles field.
		void RemovePolicyRoles(); 

		// Optional, Indicates whether this PolicySet is administratively enabled, administratively disabled, or enabled for debug. The "EnabledForDebug" property value is deprecated and, when it or any value not understood by the receiver is specified, the receiving enforcement point treats the PolicySet as "Disabled". To determine if a PolicySet is "Enabled", the containment hierarchy specified by the PolicySetComponent aggregation is examined and the Enabled property values of the hierarchy are ANDed together. Thus, for example, everything aggregated by a PolicyGroup may be disabled by setting the Enabled property in the PolicyGroup instance to "Disabled" without changing the Enabled property values of any of the aggregated instances. The default value is 1 ("Enabled").
		const unsigned short Enabled() const;

		// Optional, Indicates whether this PolicySet is administratively enabled, administratively disabled, or enabled for debug. The "EnabledForDebug" property value is deprecated and, when it or any value not understood by the receiver is specified, the receiving enforcement point treats the PolicySet as "Disabled". To determine if a PolicySet is "Enabled", the containment hierarchy specified by the PolicySetComponent aggregation is examined and the Enabled property values of the hierarchy are ANDed together. Thus, for example, everything aggregated by a PolicyGroup may be disabled by setting the Enabled property in the PolicyGroup instance to "Disabled" without changing the Enabled property values of any of the aggregated instances. The default value is 1 ("Enabled").
		void Enabled(const unsigned short value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicySet> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicySet(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Policy(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicySet(const CimObject &object)
			: CIM_Policy(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Policy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Policy::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // CIM_POLICYSET_H
