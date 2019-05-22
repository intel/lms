//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicyRuleInSystem.h
//
//  Contents:   An association that links a PolicyRule to the System in whose scope the Rule is defined.
//
//              This file was automatically generated from CIM_PolicyRuleInSystem.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYRULEINSYSTEM_H
#define CIM_POLICYRULEINSYSTEM_H 1
#include "CIM_PolicySetInSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An association that links a PolicyRule to the System in whose scope the Rule is defined.
	class CIMFRAMEWORK_API CIM_PolicyRuleInSystem  : public CIM_PolicySetInSystem
	{
	public:

		//Default constructor
		CIM_PolicyRuleInSystem()
			: CIM_PolicySetInSystem(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicyRuleInSystem(ICimWsmanClient *client)
			: CIM_PolicySetInSystem(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_PolicyRuleInSystem(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicyRuleInSystem keys
		class CimKeys : public CIM_PolicySetInSystem::CimKeys
		{
		public:
			// Required, The System in whose scope a PolicyRule is defined.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The System in whose scope a PolicyRule is defined.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, A PolicyRule named within the scope of a System.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, A PolicyRule named within the scope of a System.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicyRuleInSystem> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicyRuleInSystem(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicySetInSystem(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicyRuleInSystem(const CimObject &object)
			: CIM_PolicySetInSystem(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicySetInSystem::SetMetaData(childMetaData);
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
#endif // CIM_POLICYRULEINSYSTEM_H
