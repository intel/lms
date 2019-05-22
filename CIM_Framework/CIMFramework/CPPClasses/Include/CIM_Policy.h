//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Policy.h
//
//  Contents:   An abstract class defining the common properties of the policy managed elements derived from CIM_Policy. The subclasses are used to create rules and groups of rules that work together to form a coherent set of policies within an administrative domain or set of domains.
//
//              This file was automatically generated from CIM_Policy.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICY_H
#define CIM_POLICY_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An abstract class defining the common properties of the policy managed elements derived from CIM_Policy. The subclasses are used to create rules and groups of rules that work together to form a coherent set of policies within an administrative domain or set of domains.
	class CIMFRAMEWORK_API CIM_Policy  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_Policy()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_Policy(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_Policy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Policy keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A user-friendly name of this policy-related object.
		const string CommonName() const;

		// Optional, A user-friendly name of this policy-related object.
		void CommonName(const string &value); 

		// Is true if the field CommonName exists in the current object, otherwise is false.
		bool CommonNameExists() const;

		// Remove CommonName field.
		void RemoveCommonName(); 

		// Optional, An array of keywords for characterizing / categorizing policy objects. Keywords are of one of two types: 
		// - Keywords defined in this and other MOFs, or in DMTF white papers. These keywords provide a vendor- independent, installation-independent way of characterizing policy objects. 
		// - Installation-dependent keywords for characterizing policy objects. Examples include 'Engineering', 'Billing', and 'Review in December 2000'. 
		// This MOF defines the following keywords: 'UNKNOWN', 'CONFIGURATION', 'USAGE', 'SECURITY', 'SERVICE', 'MOTIVATIONAL', 'INSTALLATION', and 'EVENT'. These concepts are self-explanatory and are further discussed in the SLA/Policy White Paper. One additional keyword is defined: 'POLICY'. The role of this keyword is to identify policy-related instances that may not be otherwise identifiable, in some implementations. The keyword 'POLICY' is NOT mutually exclusive of the other keywords specified above.
		const vector<string> PolicyKeywords() const;

		// Optional, An array of keywords for characterizing / categorizing policy objects. Keywords are of one of two types: 
		// - Keywords defined in this and other MOFs, or in DMTF white papers. These keywords provide a vendor- independent, installation-independent way of characterizing policy objects. 
		// - Installation-dependent keywords for characterizing policy objects. Examples include 'Engineering', 'Billing', and 'Review in December 2000'. 
		// This MOF defines the following keywords: 'UNKNOWN', 'CONFIGURATION', 'USAGE', 'SECURITY', 'SERVICE', 'MOTIVATIONAL', 'INSTALLATION', and 'EVENT'. These concepts are self-explanatory and are further discussed in the SLA/Policy White Paper. One additional keyword is defined: 'POLICY'. The role of this keyword is to identify policy-related instances that may not be otherwise identifiable, in some implementations. The keyword 'POLICY' is NOT mutually exclusive of the other keywords specified above.
		void PolicyKeywords(const vector<string> &value); 

		// Is true if the field PolicyKeywords exists in the current object, otherwise is false.
		bool PolicyKeywordsExists() const;

		// Remove PolicyKeywords field.
		void RemovePolicyKeywords(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Policy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Policy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Policy(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // CIM_POLICY_H
