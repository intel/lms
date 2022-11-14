//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HTTPProxyAccessPoint.h
//
//  Contents:   The IPS_HTTPProxyAccessPoint class represents the set of proxy settings that should be used by AMT when connecting through a HTTP proxy.
//
//              This file was automatically generated from IPS_HTTPProxyAccessPoint.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_HTTPPROXYACCESSPOINT_H
#define IPS_HTTPPROXYACCESSPOINT_H 1
#include "CIM_RemoteServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_HTTPProxyAccessPoint class represents the set of proxy settings that should be used by AMT when connecting through a HTTP proxy.
	class CIMFRAMEWORK_API IPS_HTTPProxyAccessPoint  : public CIM_RemoteServiceAccessPoint
	{
	public:

		//Default constructor
		IPS_HTTPProxyAccessPoint()
			: CIM_RemoteServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		IPS_HTTPProxyAccessPoint(ICimWsmanClient *client)
			: CIM_RemoteServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~IPS_HTTPProxyAccessPoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_HTTPProxyAccessPoint keys
		class CimKeys : public CIM_RemoteServiceAccessPoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, This property will hold the information whether this proxy was set by IT or through ProxySync.
		const unsigned char Type() const;

		// Required, This property will hold the information whether this proxy was set by IT or through ProxySync.
		void Type(const unsigned char &value); 

		// Is true if the field Type exists in the current object, otherwise is false.
		bool TypeExists() const;

		// Remove Type field.
		void RemoveType(); 

		// Required, The port to be used for that HTTP proxy.
		const unsigned short Port() const;

		// Required, The port to be used for that HTTP proxy.
		void Port(const unsigned short value); 

		// Is true if the field Port exists in the current object, otherwise is false.
		bool PortExists() const;

		// Remove Port field.
		void RemovePort(); 

		// Required, Domain name of the network this proxy belongs to.
		const string NetworkDnsSuffix() const;

		// Required, Domain name of the network this proxy belongs to.
		void NetworkDnsSuffix(const string &value); 

		// Is true if the field NetworkDnsSuffix exists in the current object, otherwise is false.
		bool NetworkDnsSuffixExists() const;

		// Remove NetworkDnsSuffix field.
		void RemoveNetworkDnsSuffix(); 

		// Required, Will be initialized to the current priority counter when proxy is added. Increases whenever proxy is accessed
		const unsigned int Priority() const;

		// Required, Will be initialized to the current priority counter when proxy is added. Increases whenever proxy is accessed
		void Priority(const unsigned int value); 

		// Is true if the field Priority exists in the current object, otherwise is false.
		bool PriorityExists() const;

		// Remove Priority field.
		void RemovePriority(); 

		// Set proxy priority to highest priority 
		virtual unsigned int UpdatePriority();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_HTTPProxyAccessPoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_HTTPProxyAccessPoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_RemoteServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_HTTPProxyAccessPoint(const CimObject &object)
			: CIM_RemoteServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_RemoteServiceAccessPoint::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // IPS_HTTPPROXYACCESSPOINT_H
