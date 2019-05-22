//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_LANEndpoint.h
//
//  Contents:   Represents the LAN end point of Intel(r) AMT.
//
//              This file was automatically generated from IPS_LANEndpoint.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_LANENDPOINT_H
#define IPS_LANENDPOINT_H 1
#include "CIM_LANEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the LAN end point of Intel(r) AMT.
	class CIMFRAMEWORK_API IPS_LANEndpoint  : public CIM_LANEndpoint
	{
	public:

		//Default constructor
		IPS_LANEndpoint()
			: CIM_LANEndpoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_LANEndpoint::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		IPS_LANEndpoint(ICimWsmanClient *client)
			: CIM_LANEndpoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_LANEndpoint::GetMetaData();
			}
		}

		//Destructor
		virtual ~IPS_LANEndpoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_LANEndpoint keys
		class CimKeys : public CIM_LANEndpoint::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_LANEndpoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_LANEndpoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LANEndpoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_LANEndpoint::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		IPS_LANEndpoint(const CimObject &object)
			: CIM_LANEndpoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_LANEndpoint::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LANEndpoint::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // IPS_LANENDPOINT_H
