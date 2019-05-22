//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiPortCapabilities.h
//
//  Contents:   CIM_WiFiPortCapabilities is a specialization of CIM_NetworkPortCapabilities that describes the capabilities of a WiFiPort.
//
//              This file was automatically generated from CIM_WiFiPortCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WIFIPORTCAPABILITIES_H
#define CIM_WIFIPORTCAPABILITIES_H 1
#include "CIM_NetworkPortCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_WiFiPortCapabilities is a specialization of CIM_NetworkPortCapabilities that describes the capabilities of a WiFiPort.
	class CIMFRAMEWORK_API CIM_WiFiPortCapabilities  : public CIM_NetworkPortCapabilities
	{
	public:

		//Default constructor
		CIM_WiFiPortCapabilities()
			: CIM_NetworkPortCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_WiFiPortCapabilities(ICimWsmanClient *client)
			: CIM_NetworkPortCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_WiFiPortCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_WiFiPortCapabilities keys
		class CimKeys : public CIM_NetworkPortCapabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The 802.11 modes that the Port supports. See description of PortType property in CIM_WiFiPort for more information.
		const vector<unsigned short> SupportedPortTypes() const;

		// Optional, The 802.11 modes that the Port supports. See description of PortType property in CIM_WiFiPort for more information.
		void SupportedPortTypes(const vector<unsigned short> &value); 

		// Is true if the field SupportedPortTypes exists in the current object, otherwise is false.
		bool SupportedPortTypesExists() const;

		// Remove SupportedPortTypes field.
		void RemoveSupportedPortTypes(); 

		// Optional, Additional 802.11 modes supported by the associated WiFiPort, but not listed in the valuemap for SupportedPortTypes.
		const vector<string> OtherSupportedPortTypes() const;

		// Optional, Additional 802.11 modes supported by the associated WiFiPort, but not listed in the valuemap for SupportedPortTypes.
		void OtherSupportedPortTypes(const vector<string> &value); 

		// Is true if the field OtherSupportedPortTypes exists in the current object, otherwise is false.
		bool OtherSupportedPortTypesExists() const;

		// Remove OtherSupportedPortTypes field.
		void RemoveOtherSupportedPortTypes(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_WiFiPortCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_WiFiPortCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_NetworkPortCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_WiFiPortCapabilities(const CimObject &object)
			: CIM_NetworkPortCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_NetworkPortCapabilities::SetMetaData(childMetaData);
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
#endif // CIM_WIFIPORTCAPABILITIES_H
