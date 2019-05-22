//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemotePort.h
//
//  Contents:   RemotePort adds port information to the access data (such as IP Address) that is specified in and inherited from RemoteServiceAccessPoint. For example, using the additional properties in this class, you could indicate that UDP Port 123 is accessed at IP Address xyz. The IP Address would be specified in the inherited AccessInfo property, while the UDP Port number would be specified in the PortInfo property of this class.
//
//              This file was automatically generated from CIM_RemotePort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REMOTEPORT_H
#define CIM_REMOTEPORT_H 1
#include "CIM_RemoteServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// RemotePort adds port information to the access data (such as IP Address) that is specified in and inherited from RemoteServiceAccessPoint. For example, using the additional properties in this class, you could indicate that UDP Port 123 is accessed at IP Address xyz. The IP Address would be specified in the inherited AccessInfo property, while the UDP Port number would be specified in the PortInfo property of this class.
	class CIMFRAMEWORK_API CIM_RemotePort  : public CIM_RemoteServiceAccessPoint
	{
	public:

		//Default constructor
		CIM_RemotePort()
			: CIM_RemoteServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_RemotePort(ICimWsmanClient *client)
			: CIM_RemoteServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_RemotePort(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RemotePort keys
		class CimKeys : public CIM_RemoteServiceAccessPoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Port information that might further specify the remote access information.
		const string PortInfo() const;

		// Optional, Port information that might further specify the remote access information.
		void PortInfo(const string &value); 

		// Is true if the field PortInfo exists in the current object, otherwise is false.
		bool PortInfoExists() const;

		// Remove PortInfo field.
		void RemovePortInfo(); 

		// Optional, An enumerated integer that describes the protocol of the port that is addressed by PortInformation.
		const unsigned short PortProtocol() const;

		// Optional, An enumerated integer that describes the protocol of the port that is addressed by PortInformation.
		void PortProtocol(const unsigned short value); 

		// Is true if the field PortProtocol exists in the current object, otherwise is false.
		bool PortProtocolExists() const;

		// Remove PortProtocol field.
		void RemovePortProtocol(); 

		// Optional, Describes the protocol when the property PortProtocol is set to 1 (Other).
		const string OtherProtocolDescription() const;

		// Optional, Describes the protocol when the property PortProtocol is set to 1 (Other).
		void OtherProtocolDescription(const string &value); 

		// Is true if the field OtherProtocolDescription exists in the current object, otherwise is false.
		bool OtherProtocolDescriptionExists() const;

		// Remove OtherProtocolDescription field.
		void RemoveOtherProtocolDescription(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RemotePort> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RemotePort(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_RemoteServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RemotePort(const CimObject &object)
			: CIM_RemoteServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RemoteServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_RemoteServiceAccessPoint::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // CIM_REMOTEPORT_H
