//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PCIDevice.h
//
//  Contents:   Capabilities and management of a PCI device controller on an adapter card.
//
//              This file was automatically generated from AMT_PCIDevice.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PCIDEVICE_H
#define AMT_PCIDEVICE_H 1
#include "CIM_PCIController.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of a PCI device controller on an adapter card.
	class CIMFRAMEWORK_API AMT_PCIDevice  : public CIM_PCIController
	{
	public:

		//Default constructor
		AMT_PCIDevice()
			: CIM_PCIController(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PCIController::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//constructor which receives WSMan client
		AMT_PCIDevice(ICimWsmanClient *client)
			: CIM_PCIController(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PCIController::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//Destructor
		virtual ~AMT_PCIDevice(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PCIDevice keys
		class CimKeys : public CIM_PCIController::CimKeys
		{
		public:
			// Required, An address or other identifying information to uniquely name the PCI device.
			const string DeviceID() const
			{
				return GetKey("DeviceID");
			}

			// Required, An address or other identifying information to uniquely name the PCI device.
			void DeviceID(const string &value)
			{
				SetOrAddKey("DeviceID", value);
			}

		};

		// class fields declarations

		// Optional, Array of doubleword base-memory addresses.
		const vector<unsigned int> BaseAddress() const;

		// Optional, Array of doubleword base-memory addresses.
		void BaseAddress(const vector<unsigned int> &value); 

		// Is true if the field BaseAddress exists in the current object, otherwise is false.
		bool BaseAddressExists() const;

		// Remove BaseAddress field.
		void RemoveBaseAddress(); 

		// Optional, The subsystem ID read from the device's PCI configuration space.
		const unsigned short SubsystemID() const;

		// Optional, The subsystem ID read from the device's PCI configuration space.
		void SubsystemID(const unsigned short value); 

		// Is true if the field SubsystemID exists in the current object, otherwise is false.
		bool SubsystemIDExists() const;

		// Remove SubsystemID field.
		void RemoveSubsystemID(); 

		// Optional, The vendor ID read from the device's PCI configuration space.
		const unsigned short VendorID() const;

		// Optional, The vendor ID read from the device's PCI configuration space.
		void VendorID(const unsigned short value); 

		// Is true if the field VendorID exists in the current object, otherwise is false.
		bool VendorIDExists() const;

		// Remove VendorID field.
		void RemoveVendorID(); 

		// Optional, The revision ID read from the device's PCI configuration space.
		const unsigned char RevisionID() const;

		// Optional, The revision ID read from the device's PCI configuration space.
		void RevisionID(const unsigned char &value); 

		// Is true if the field RevisionID exists in the current object, otherwise is false.
		bool RevisionIDExists() const;

		// Remove RevisionID field.
		void RemoveRevisionID(); 

		// Optional, The programmatic interface code read from the device's PCI configuration space.
		const unsigned char ProgIf() const;

		// Optional, The programmatic interface code read from the device's PCI configuration space.
		void ProgIf(const unsigned char &value); 

		// Is true if the field ProgIf exists in the current object, otherwise is false.
		bool ProgIfExists() const;

		// Remove ProgIf field.
		void RemoveProgIf(); 

		// Optional, The PCI subclass code read from the device's PCI configuration space.
		const unsigned char Subclass() const;

		// Optional, The PCI subclass code read from the device's PCI configuration space.
		void Subclass(const unsigned char &value); 

		// Is true if the field Subclass exists in the current object, otherwise is false.
		bool SubclassExists() const;

		// Remove Subclass field.
		void RemoveSubclass(); 

		// Optional, The bus, device, and function number of the device.
		const unsigned short DeviceLocation() const;

		// Optional, The bus, device, and function number of the device.
		void DeviceLocation(const unsigned short value); 

		// Is true if the field DeviceLocation exists in the current object, otherwise is false.
		bool DeviceLocationExists() const;

		// Remove DeviceLocation field.
		void RemoveDeviceLocation(); 

		// Optional, Subsystem vendor ID. ID information is reported from a PCIDevice through protocol-specific requests. The correct place in the CIM Schema for this information is in CIM_Physical Element (the Manufacturer property) for hardware, and CIM_Product (the Vendor property) if the information is related to Product acquisition. This data is also reported here, because it is part of the standard output from the Device and is an optimization.
		const unsigned short SubsystemVendorID() const;

		// Optional, Subsystem vendor ID. ID information is reported from a PCIDevice through protocol-specific requests. The correct place in the CIM Schema for this information is in CIM_Physical Element (the Manufacturer property) for hardware, and CIM_Product (the Vendor property) if the information is related to Product acquisition. This data is also reported here, because it is part of the standard output from the Device and is an optimization.
		void SubsystemVendorID(const unsigned short value); 

		// Is true if the field SubsystemVendorID exists in the current object, otherwise is false.
		bool SubsystemVendorIDExists() const;

		// Remove SubsystemVendorID field.
		void RemoveSubsystemVendorID(); 

		// Optional, Register that indicates how long the master would like to retain PCI bus ownership whenever it initiates a transaction. A 0 value indicates no requirement.
		const unsigned char MinGrantTime() const;

		// Optional, Register that indicates how long the master would like to retain PCI bus ownership whenever it initiates a transaction. A 0 value indicates no requirement.
		void MinGrantTime(const unsigned char &value); 

		// Is true if the field MinGrantTime exists in the current object, otherwise is false.
		bool MinGrantTimeExists() const;

		// Remove MinGrantTime field.
		void RemoveMinGrantTime(); 

		// Optional, Register that specifies how often the device needs access to the PCI bus in 250ns. A 0 value indicates no requirement.
		const unsigned char MaxLatency() const;

		// Optional, Register that specifies how often the device needs access to the PCI bus in 250ns. A 0 value indicates no requirement.
		void MaxLatency(const unsigned char &value); 

		// Is true if the field MaxLatency exists in the current object, otherwise is false.
		bool MaxLatencyExists() const;

		// Remove MaxLatency field.
		void RemoveMaxLatency(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PCIDevice> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PCIDevice(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PCIController(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PCIController::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PCIDevice(const CimObject &object)
			: CIM_PCIController(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PCIController::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PCIController::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 12);
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
#endif // AMT_PCIDEVICE_H
