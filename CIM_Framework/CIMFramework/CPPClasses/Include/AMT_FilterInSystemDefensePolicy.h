//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_FilterInSystemDefensePolicy.h
//
//  Contents:   This Class associates a System Defense Policy to a System Defense Filter.
//
//              This file was automatically generated from AMT_FilterInSystemDefensePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_FILTERINSYSTEMDEFENSEPOLICY_H
#define AMT_FILTERINSYSTEMDEFENSEPOLICY_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This Class associates a System Defense Policy to a System Defense Filter.
	class CIMFRAMEWORK_API AMT_FilterInSystemDefensePolicy  : public CIM_Dependency
	{
	public:

		//Default constructor
		AMT_FilterInSystemDefensePolicy()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_FilterInSystemDefensePolicy(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_FilterInSystemDefensePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_FilterInSystemDefensePolicy keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Required, Antecedent represents the independent object in this association. Specifically, the policy which aggregates the filter.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, Antecedent represents the independent object in this association. Specifically, the policy which aggregates the filter.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, Dependent represents the object dependent on the Antecedent, specifically, the filter connected to the policy.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, Dependent represents the object dependent on the Antecedent, specifically, the filter connected to the policy.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_FilterInSystemDefensePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_FilterInSystemDefensePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_FilterInSystemDefensePolicy(const CimObject &object)
			: CIM_Dependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Dependency::SetMetaData(childMetaData);
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
#endif // AMT_FILTERINSYSTEMDEFENSEPOLICY_H
