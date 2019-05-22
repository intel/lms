//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OwningCollectionElement.h
//
//  Contents:   OwningCollectionElement represents an association between a Collection and the ManagedElement responsible for the control or ownership of the Collection.
//
//              This file was automatically generated from CIM_OwningCollectionElement.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_OWNINGCOLLECTIONELEMENT_H
#define CIM_OWNINGCOLLECTIONELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// OwningCollectionElement represents an association between a Collection and the ManagedElement responsible for the control or ownership of the Collection.
	class CIMFRAMEWORK_API CIM_OwningCollectionElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_OwningCollectionElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_OwningCollectionElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_OwningCollectionElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_OwningCollectionElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The ManagedElement acting as the 'owner' or object that isresponsible for the control of the Collection.
			const CimReference OwningElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("OwningElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement acting as the 'owner' or object that isresponsible for the control of the Collection.
			void OwningElement(const CimReference &value)
			{
				SetOrAddKey("OwningElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The Collection owned or controlled by the ManagedElement.
			const CimReference OwnedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("OwnedElement"), ret);
				return ret;
			}

			// Key, Required, The Collection owned or controlled by the ManagedElement.
			void OwnedElement(const CimReference &value)
			{
				SetOrAddKey("OwnedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The ManagedElement acting as the 'owner' or object that isresponsible for the control of the Collection.
		const CimReference OwningElement() const;

		// Key, Required, The ManagedElement acting as the 'owner' or object that isresponsible for the control of the Collection.
		void OwningElement(const CimReference &value); 


		// Key, Required, The Collection owned or controlled by the ManagedElement.
		const CimReference OwnedElement() const;

		// Key, Required, The Collection owned or controlled by the ManagedElement.
		void OwnedElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_OwningCollectionElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_OwningCollectionElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_OwningCollectionElement(const CimObject &object)
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
#endif // CIM_OWNINGCOLLECTIONELEMENT_H
