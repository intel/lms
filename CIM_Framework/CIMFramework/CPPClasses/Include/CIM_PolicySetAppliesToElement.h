//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySetAppliesToElement.h
//
//  Contents:   PolicySetAppliesToElement makes explicit which PolicySets (i.e., policy rules and groups of rules) ARE CURRENTLY applied to a particular Element. This association indicates that the PolicySets that are appropriate for a ManagedElement (specified using the PolicyRoleCollection aggregation) have actually been deployed in the policy management infrastructure. Note that if the named Element refers to a Collection, then the PolicySet is assumed to be applied to all the members of the Collection.
//
//              This file was automatically generated from CIM_PolicySetAppliesToElement.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYSETAPPLIESTOELEMENT_H
#define CIM_POLICYSETAPPLIESTOELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PolicySetAppliesToElement makes explicit which PolicySets (i.e., policy rules and groups of rules) ARE CURRENTLY applied to a particular Element. This association indicates that the PolicySets that are appropriate for a ManagedElement (specified using the PolicyRoleCollection aggregation) have actually been deployed in the policy management infrastructure. Note that if the named Element refers to a Collection, then the PolicySet is assumed to be applied to all the members of the Collection.
	class CIMFRAMEWORK_API CIM_PolicySetAppliesToElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_PolicySetAppliesToElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicySetAppliesToElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_PolicySetAppliesToElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicySetAppliesToElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The PolicyRules and/or groups of rules that are currently applied to an Element.
			const CimReference PolicySet() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PolicySet"), ret);
				return ret;
			}

			// Key, Required, The PolicyRules and/or groups of rules that are currently applied to an Element.
			void PolicySet(const CimReference &value)
			{
				SetOrAddKey("PolicySet", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The ManagedElement to which the PolicySet applies.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement to which the PolicySet applies.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The PolicyRules and/or groups of rules that are currently applied to an Element.
		const CimReference PolicySet() const;

		// Key, Required, The PolicyRules and/or groups of rules that are currently applied to an Element.
		void PolicySet(const CimReference &value); 


		// Key, Required, The ManagedElement to which the PolicySet applies.
		const CimReference ManagedElement() const;

		// Key, Required, The ManagedElement to which the PolicySet applies.
		void ManagedElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicySetAppliesToElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicySetAppliesToElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicySetAppliesToElement(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_POLICYSETAPPLIESTOELEMENT_H
