//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HTTPProxyService.h
//
//  Contents:   Represents the HTTP Proxy Service.
//
//              This file was automatically generated from IPS_HTTPProxyService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_HTTPPROXYSERVICE_H
#define IPS_HTTPPROXYSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the HTTP Proxy Service.
	class CIMFRAMEWORK_API IPS_HTTPProxyService  : public CIM_Service
	{
	public:

		//Default constructor
		IPS_HTTPProxyService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		IPS_HTTPProxyService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~IPS_HTTPProxyService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_HTTPProxyService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, This property defines whether the HTTP proxies sync (from local) is allowed
		const bool SyncEnabled() const;

		// Optional, This property defines whether the HTTP proxies sync (from local) is allowed
		void SyncEnabled(const bool value); 

		// Is true if the field SyncEnabled exists in the current object, otherwise is false.
		bool SyncEnabledExists() const;

		// Remove SyncEnabled field.
		void RemoveSyncEnabled(); 

		//Input parameter for function AddProxyAccessPoint
		class CIMFRAMEWORK_API AddProxyAccessPoint_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddProxyAccessPoint_INPUT() : CimParam() {}

			// Class Destructor
			~AddProxyAccessPoint_INPUT(){}

			// Required, A string holding the IP address or FQDN of the server
			void AccessInfo(const string &value); 

			// Required, An enumerated integer describing the format and interpretation of the AccessInfo property.
			// Legal values:
			// IPv4 Address: 3
			// IPv6 Address: 4
			// FQDN: 201
			void InfoFormat(const unsigned short value); 

			// Required, The port to be used for that HTTP proxy.
			void Port(const unsigned short value); 

			// Required, Domain name of the network this proxy belongs to
			void NetworkDnsSuffix(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddProxyAccessPoint
		class CIMFRAMEWORK_API AddProxyAccessPoint_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddProxyAccessPoint_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddProxyAccessPoint_OUTPUT(){}

			// class fields
			// A reference to the created Proxy Access Point if the operation succeeded.
			const CimReference ProxyAccessPoint() const;
			bool ProxyAccessPointExists() const;
		private:
		};

		// Adds a Proxy access point that will be used when FW needs to open a user-initiated connection
		virtual unsigned int AddProxyAccessPoint(const AddProxyAccessPoint_INPUT &input, AddProxyAccessPoint_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_HTTPProxyService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_HTTPProxyService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_HTTPProxyService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // IPS_HTTPPROXYSERVICE_H
