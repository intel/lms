//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSProtocolEndpoint.h
//
//  Contents:   A communication point from which data may be sent or received. ProtocolEndpoints link system/computer interfaces to LogicalNetworks.
//
//              This file was automatically generated from AMT_TLSProtocolEndpoint.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_TLSPROTOCOLENDPOINT_H
#define AMT_TLSPROTOCOLENDPOINT_H 1
#include "CIM_ProtocolEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A communication point from which data may be sent or received. ProtocolEndpoints link system/computer interfaces to LogicalNetworks.
	class CIMFRAMEWORK_API AMT_TLSProtocolEndpoint  : public CIM_ProtocolEndpoint
	{
	public:

		//Default constructor
		AMT_TLSProtocolEndpoint()
			: CIM_ProtocolEndpoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_TLSProtocolEndpoint(ICimWsmanClient *client)
			: CIM_ProtocolEndpoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_TLSProtocolEndpoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_TLSProtocolEndpoint keys
		class CimKeys : public CIM_ProtocolEndpoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Describes what role the endpoint is playing in TLS exchanges.
		const unsigned char Role() const;

		// Optional, Describes what role the endpoint is playing in TLS exchanges.
		void Role(const unsigned char &value); 

		// Is true if the field Role exists in the current object, otherwise is false.
		bool RoleExists() const;

		// Remove Role field.
		void RemoveRole(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_TLSProtocolEndpoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_TLSProtocolEndpoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ProtocolEndpoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_TLSProtocolEndpoint(const CimObject &object)
			: CIM_ProtocolEndpoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ProtocolEndpoint::SetMetaData(childMetaData);
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
#endif // AMT_TLSPROTOCOLENDPOINT_H
