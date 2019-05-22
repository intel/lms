//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSProtocolEndpointCollection.h
//
//  Contents:   Collection of AMT_TLSProtocolEndpoint Instances. The instances are connected with CIM_MemberOfCollection.
//
//              This file was automatically generated from AMT_TLSProtocolEndpointCollection.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_TLSPROTOCOLENDPOINTCOLLECTION_H
#define AMT_TLSPROTOCOLENDPOINTCOLLECTION_H 1
#include "CIM_Collection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Collection of AMT_TLSProtocolEndpoint Instances. The instances are connected with CIM_MemberOfCollection.
	class CIMFRAMEWORK_API AMT_TLSProtocolEndpointCollection  : public CIM_Collection
	{
	public:

		//Default constructor
		AMT_TLSProtocolEndpointCollection()
			: CIM_Collection(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_TLSProtocolEndpointCollection(ICimWsmanClient *client)
			: CIM_Collection(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_TLSProtocolEndpointCollection(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_TLSProtocolEndpointCollection keys
		class CimKeys : public CIM_Collection::CimKeys
		{
		public:
			// Key, Required, A user-friendly name for the object.
			const string ElementName() const
			{
				return GetKey("ElementName");
			}

			// Key, Required, A user-friendly name for the object.
			void ElementName(const string &value)
			{
				SetOrAddKey("ElementName", value);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_TLSProtocolEndpointCollection> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_TLSProtocolEndpointCollection(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Collection(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_TLSProtocolEndpointCollection(const CimObject &object)
			: CIM_Collection(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Collection::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // AMT_TLSPROTOCOLENDPOINTCOLLECTION_H
