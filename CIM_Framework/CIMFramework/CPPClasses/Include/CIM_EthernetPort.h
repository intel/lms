//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EthernetPort.h
//
//  Contents:   Capabilities and management of an EthernetPort.
//
//              This file was automatically generated from CIM_EthernetPort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ETHERNETPORT_H
#define CIM_ETHERNETPORT_H 1
#include "CIM_NetworkPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of an EthernetPort.
	class CIMFRAMEWORK_API CIM_EthernetPort  : public CIM_NetworkPort
	{
	public:

		//Default constructor
		CIM_EthernetPort()
			: CIM_NetworkPort(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		CIM_EthernetPort(ICimWsmanClient *client)
			: CIM_NetworkPort(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~CIM_EthernetPort(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_EthernetPort keys
		class CimKeys : public CIM_NetworkPort::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The maximum size of the INFO (non-MAC) field that will be received or transmitted.
		const unsigned int MaxDataSize() const;

		// Optional, The maximum size of the INFO (non-MAC) field that will be received or transmitted.
		void MaxDataSize(const unsigned int value); 

		// Is true if the field MaxDataSize exists in the current object, otherwise is false.
		bool MaxDataSizeExists() const;

		// Remove MaxDataSize field.
		void RemoveMaxDataSize(); 

		// Optional, Capabilities of the EthernetPort. For example, the Device might support AlertOnLan, WakeOnLan, Load Balancing, or FailOver. If failover or load balancing capabilities are listed, a SpareGroup (failover) or ExtraCapacityGroup (load balancing) should also be defined to completely describe the capability.
		const vector<unsigned short> Capabilities() const;

		// Optional, Capabilities of the EthernetPort. For example, the Device might support AlertOnLan, WakeOnLan, Load Balancing, or FailOver. If failover or load balancing capabilities are listed, a SpareGroup (failover) or ExtraCapacityGroup (load balancing) should also be defined to completely describe the capability.
		void Capabilities(const vector<unsigned short> &value); 

		// Is true if the field Capabilities exists in the current object, otherwise is false.
		bool CapabilitiesExists() const;

		// Remove Capabilities field.
		void RemoveCapabilities(); 

		// Optional, An array of free-form strings that provides more detailed explanations for any of the EthernetPort features that are indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		const vector<string> CapabilityDescriptions() const;

		// Optional, An array of free-form strings that provides more detailed explanations for any of the EthernetPort features that are indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		void CapabilityDescriptions(const vector<string> &value); 

		// Is true if the field CapabilityDescriptions exists in the current object, otherwise is false.
		bool CapabilityDescriptionsExists() const;

		// Remove CapabilityDescriptions field.
		void RemoveCapabilityDescriptions(); 

		// Optional, Specifies which capabilities are enabled from the list of all supported ones, which are defined in the Capabilities array.
		const vector<unsigned short> EnabledCapabilities() const;

		// Optional, Specifies which capabilities are enabled from the list of all supported ones, which are defined in the Capabilities array.
		void EnabledCapabilities(const vector<unsigned short> &value); 

		// Is true if the field EnabledCapabilities exists in the current object, otherwise is false.
		bool EnabledCapabilitiesExists() const;

		// Remove EnabledCapabilities field.
		void RemoveEnabledCapabilities(); 

		// Optional, An array of free-form strings that provides more detailed explanations for any of the enabled capabilities that are specified as 'Other'.
		const vector<string> OtherEnabledCapabilities() const;

		// Optional, An array of free-form strings that provides more detailed explanations for any of the enabled capabilities that are specified as 'Other'.
		void OtherEnabledCapabilities(const vector<string> &value); 

		// Is true if the field OtherEnabledCapabilities exists in the current object, otherwise is false.
		bool OtherEnabledCapabilitiesExists() const;

		// Remove OtherEnabledCapabilities field.
		void RemoveOtherEnabledCapabilities(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_EthernetPort> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_EthernetPort(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_NetworkPort(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_EthernetPort(const CimObject &object)
			: CIM_NetworkPort(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_NetworkPort::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 7);
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
#endif // CIM_ETHERNETPORT_H
