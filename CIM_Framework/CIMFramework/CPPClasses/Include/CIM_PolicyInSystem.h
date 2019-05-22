//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyInSystem.h
//
//  Contents:   CIM_PolicyInSystem is a generic association used to establish dependency relationships between Policies and the Systems that host them. These Systems may be ComputerSystems where Policies are 'running' or they may be Policy Repositories where Policies are stored. This relationship is similar to the concept of CIM_Services being dependent on CIM_Systems as defined by the HostedService association. 
//              
//              Cardinality is Max (1) for the Antecedent/System reference since Policies can only be hosted in at most one System context. Some subclasses of the association will further refine this definition to make the Policies Weak to Systems. Other subclasses of PolicyInSystem will define an optional hosting relationship. Examples of each of these are the PolicyRuleInSystem and PolicyConditionIn PolicyRepository associations, respectively.
//
//              This file was automatically generated from CIM_PolicyInSystem.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYINSYSTEM_H
#define CIM_POLICYINSYSTEM_H 1
#include "CIM_HostedDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_PolicyInSystem is a generic association used to establish dependency relationships between Policies and the Systems that host them. These Systems may be ComputerSystems where Policies are 'running' or they may be Policy Repositories where Policies are stored. This relationship is similar to the concept of CIM_Services being dependent on CIM_Systems as defined by the HostedService association. 
	// 
	// Cardinality is Max (1) for the Antecedent/System reference since Policies can only be hosted in at most one System context. Some subclasses of the association will further refine this definition to make the Policies Weak to Systems. Other subclasses of PolicyInSystem will define an optional hosting relationship. Examples of each of these are the PolicyRuleInSystem and PolicyConditionIn PolicyRepository associations, respectively.
	class CIMFRAMEWORK_API CIM_PolicyInSystem  : public CIM_HostedDependency
	{
	public:

		//Default constructor
		CIM_PolicyInSystem()
			: CIM_HostedDependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicyInSystem(ICimWsmanClient *client)
			: CIM_HostedDependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_PolicyInSystem(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicyInSystem keys
		class CimKeys : public CIM_HostedDependency::CimKeys
		{
		public:
			// Required, The hosting System.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The hosting System.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The hosted Policy.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The hosted Policy.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicyInSystem> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicyInSystem(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_HostedDependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicyInSystem(const CimObject &object)
			: CIM_HostedDependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_HostedDependency::SetMetaData(childMetaData);
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
#endif // CIM_POLICYINSYSTEM_H
