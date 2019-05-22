//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IEEE8021xCapabilities.h
//
//  Contents:   CIM_IEEE8021xCapabilities describes the IEEE 802.1x security capabilities of a layer 2 ProtocolEndpoint.
//
//              This file was automatically generated from CIM_IEEE8021xCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_IEEE8021XCAPABILITIES_H
#define CIM_IEEE8021XCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_IEEE8021xCapabilities describes the IEEE 802.1x security capabilities of a layer 2 ProtocolEndpoint.
	class CIMFRAMEWORK_API CIM_IEEE8021xCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		CIM_IEEE8021xCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_IEEE8021xCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_IEEE8021xCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_IEEE8021xCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The IEEE 802.1x Extensible Authentication Protocol types supported by the associated ProtocolEndpoint. See AuthenticationProtocol description in CIM_IEEE8021xSettings for more information.
		const vector<unsigned short> SupportedAuthenticationProtocols() const;

		// Optional, The IEEE 802.1x Extensible Authentication Protocol types supported by the associated ProtocolEndpoint. See AuthenticationProtocol description in CIM_IEEE8021xSettings for more information.
		void SupportedAuthenticationProtocols(const vector<unsigned short> &value); 

		// Is true if the field SupportedAuthenticationProtocols exists in the current object, otherwise is false.
		bool SupportedAuthenticationProtocolsExists() const;

		// Remove SupportedAuthenticationProtocols field.
		void RemoveSupportedAuthenticationProtocols(); 

		// Optional, Indicates whether the associated ProtocolEndpoint supports moving a session due to roaming.
		const bool RoamingSupported() const;

		// Optional, Indicates whether the associated ProtocolEndpoint supports moving a session due to roaming.
		void RoamingSupported(const bool value); 

		// Is true if the field RoamingSupported exists in the current object, otherwise is false.
		bool RoamingSupportedExists() const;

		// Remove RoamingSupported field.
		void RemoveRoamingSupported(); 

		// Optional, Indicates whether the associated ProtocolEndpoint supports fast reconnection of an IEEE 802.1x session when it roams from one access point to another.
		const bool FastRoamingSupported() const;

		// Optional, Indicates whether the associated ProtocolEndpoint supports fast reconnection of an IEEE 802.1x session when it roams from one access point to another.
		void FastRoamingSupported(const bool value); 

		// Is true if the field FastRoamingSupported exists in the current object, otherwise is false.
		bool FastRoamingSupportedExists() const;

		// Remove FastRoamingSupported field.
		void RemoveFastRoamingSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_IEEE8021xCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_IEEE8021xCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_IEEE8021xCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
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
#endif // CIM_IEEE8021XCAPABILITIES_H
