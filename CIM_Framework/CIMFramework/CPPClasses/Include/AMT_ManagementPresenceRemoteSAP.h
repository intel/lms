//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ManagementPresenceRemoteSAP.h
//
//  Contents:   Represents a Management Presence Remote Service Access Point (or an MPS) to be accessed by the Intel(R) AMT subsystem from remote.
//
//              This file was automatically generated from AMT_ManagementPresenceRemoteSAP.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_MANAGEMENTPRESENCEREMOTESAP_H
#define AMT_MANAGEMENTPRESENCEREMOTESAP_H 1
#include "CIM_RemoteServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents a Management Presence Remote Service Access Point (or an MPS) to be accessed by the Intel(R) AMT subsystem from remote.
	class CIMFRAMEWORK_API AMT_ManagementPresenceRemoteSAP  : public CIM_RemoteServiceAccessPoint
	{
	public:

		//Default constructor
		AMT_ManagementPresenceRemoteSAP()
			: CIM_RemoteServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_ManagementPresenceRemoteSAP(ICimWsmanClient *client)
			: CIM_RemoteServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_ManagementPresenceRemoteSAP(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ManagementPresenceRemoteSAP keys
		class CimKeys : public CIM_RemoteServiceAccessPoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, The port to be used to establish a tunnel with the MPS.
		const unsigned short Port() const;

		// Required, The port to be used to establish a tunnel with the MPS.
		void Port(const unsigned short value); 

		// Is true if the field Port exists in the current object, otherwise is false.
		bool PortExists() const;

		// Remove Port field.
		void RemovePort(); 

		// Optional, A common name used when AccessInfo is an IP address.
		const string CN() const;

		// Optional, A common name used when AccessInfo is an IP address.
		void CN(const string &value); 

		// Is true if the field CN exists in the current object, otherwise is false.
		bool CNExists() const;

		// Remove CN field.
		void RemoveCN(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ManagementPresenceRemoteSAP> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ManagementPresenceRemoteSAP(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_RemoteServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ManagementPresenceRemoteSAP(const CimObject &object)
			: CIM_RemoteServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_RemoteServiceAccessPoint::SetMetaData(childMetaData);
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
#endif // AMT_MANAGEMENTPRESENCEREMOTESAP_H
