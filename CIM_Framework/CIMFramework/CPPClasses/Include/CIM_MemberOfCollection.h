//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MemberOfCollection.h
//
//  Contents:   CIM_MemberOfCollection is an aggregation used to establish membership of ManagedElements in a Collection.
//
//              This file was automatically generated from CIM_MemberOfCollection.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MEMBEROFCOLLECTION_H
#define CIM_MEMBEROFCOLLECTION_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_MemberOfCollection is an aggregation used to establish membership of ManagedElements in a Collection.
	class CIMFRAMEWORK_API CIM_MemberOfCollection  : public CimBase
	{
	public:

		//Default constructor
		CIM_MemberOfCollection()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_MemberOfCollection(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_MemberOfCollection(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_MemberOfCollection keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Collection that aggregates members.
			const CimReference Collection() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Collection"), ret);
				return ret;
			}

			// Key, Required, The Collection that aggregates members.
			void Collection(const CimReference &value)
			{
				SetOrAddKey("Collection", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The aggregated member of the Collection.
			const CimReference Member() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Member"), ret);
				return ret;
			}

			// Key, Required, The aggregated member of the Collection.
			void Member(const CimReference &value)
			{
				SetOrAddKey("Member", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Collection that aggregates members.
		const CimReference Collection() const;

		// Key, Required, The Collection that aggregates members.
		void Collection(const CimReference &value); 


		// Key, Required, The aggregated member of the Collection.
		const CimReference Member() const;

		// Key, Required, The aggregated member of the Collection.
		void Member(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_MemberOfCollection> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_MemberOfCollection(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_MemberOfCollection(const CimObject &object)
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
#endif // CIM_MEMBEROFCOLLECTION_H
