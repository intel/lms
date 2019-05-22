//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_FilterCollection.h
//
//  Contents:   A FilterCollection is a subclass of CIM_Collection which aggregates instances of CIM_IndicationFilter.
//
//              This file was automatically generated from CIM_FilterCollection.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_FILTERCOLLECTION_H
#define CIM_FILTERCOLLECTION_H 1
#include "CIM_Collection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A FilterCollection is a subclass of CIM_Collection which aggregates instances of CIM_IndicationFilter.
	class CIMFRAMEWORK_API CIM_FilterCollection  : public CIM_Collection
	{
	public:

		//Default constructor
		CIM_FilterCollection()
			: CIM_Collection(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_FilterCollection(ICimWsmanClient *client)
			: CIM_Collection(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_FilterCollection(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_FilterCollection keys
		class CimKeys : public CIM_Collection::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID shall be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID shall be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, The Collection Name is to be specified by a profile or owning organization such that it can be used to identify a particular collection of indication filters. The value of CollectionName shall be constructed using the following algorithm: 
		// <OrgID>:<CollectionID> 
		// Where <OrgID> and <CollectionID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the CollectionName. In addition, to ensure uniqueness <OrgID> shall not contain a colon (':').
		// <CollectionID> is the string label defined in the specification defining the collection.
		const string CollectionName() const;

		// Optional, The Collection Name is to be specified by a profile or owning organization such that it can be used to identify a particular collection of indication filters. The value of CollectionName shall be constructed using the following algorithm: 
		// <OrgID>:<CollectionID> 
		// Where <OrgID> and <CollectionID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the CollectionName. In addition, to ensure uniqueness <OrgID> shall not contain a colon (':').
		// <CollectionID> is the string label defined in the specification defining the collection.
		void CollectionName(const string &value); 

		// Is true if the field CollectionName exists in the current object, otherwise is false.
		bool CollectionNameExists() const;

		// Remove CollectionName field.
		void RemoveCollectionName(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_FilterCollection> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_FilterCollection(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Collection(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_FilterCollection(const CimObject &object)
			: CIM_Collection(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Collection::SetMetaData(childMetaData);
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
#endif // CIM_FILTERCOLLECTION_H
