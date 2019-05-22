//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PCIDevice.cpp
//
//  Contents:   Capabilities and management of a PCI device controller on an adapter card.
//
//              This file was automatically generated from AMT_PCIDevice.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PCIDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PCIDevice::_metadata[] = {
		{"BaseAddress", false, false, false },
		{"SubsystemID", false, false, false },
		{"VendorID", false, false, false },
		{"DeviceID", true, false, false },
		{"RevisionID", false, false, false },
		{"ProgIf", false, false, false },
		{"Subclass", false, false, false },
		{"ClassCode", false, false, false },
		{"DeviceLocation", false, false, false },
		{"SubsystemVendorID", false, false, false },
		{"MinGrantTime", false, false, false },
		{"MaxLatency", false, false, false },
	};
	// class fields
	const vector<unsigned int> AMT_PCIDevice::BaseAddress() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("BaseAddress"), ret);
		return ret;
	}
	void AMT_PCIDevice::BaseAddress(const vector<unsigned int> &value)
	{
		SetOrAddField("BaseAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::BaseAddressExists() const
	{
		return ContainsField("BaseAddress");
	}
	void AMT_PCIDevice::RemoveBaseAddress()
	{
		RemoveField("BaseAddress");
	}

	const unsigned short AMT_PCIDevice::SubsystemID() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SubsystemID"), ret);
		return ret;
	}
	void AMT_PCIDevice::SubsystemID(const unsigned short value)
	{
		SetOrAddField("SubsystemID", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::SubsystemIDExists() const
	{
		return ContainsField("SubsystemID");
	}
	void AMT_PCIDevice::RemoveSubsystemID()
	{
		RemoveField("SubsystemID");
	}

	const unsigned short AMT_PCIDevice::VendorID() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("VendorID"), ret);
		return ret;
	}
	void AMT_PCIDevice::VendorID(const unsigned short value)
	{
		SetOrAddField("VendorID", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::VendorIDExists() const
	{
		return ContainsField("VendorID");
	}
	void AMT_PCIDevice::RemoveVendorID()
	{
		RemoveField("VendorID");
	}

	const unsigned char AMT_PCIDevice::RevisionID() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("RevisionID"), ret);
		return ret;
	}
	void AMT_PCIDevice::RevisionID(const unsigned char &value)
	{
		SetOrAddField("RevisionID", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::RevisionIDExists() const
	{
		return ContainsField("RevisionID");
	}
	void AMT_PCIDevice::RemoveRevisionID()
	{
		RemoveField("RevisionID");
	}

	const unsigned char AMT_PCIDevice::ProgIf() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("ProgIf"), ret);
		return ret;
	}
	void AMT_PCIDevice::ProgIf(const unsigned char &value)
	{
		SetOrAddField("ProgIf", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::ProgIfExists() const
	{
		return ContainsField("ProgIf");
	}
	void AMT_PCIDevice::RemoveProgIf()
	{
		RemoveField("ProgIf");
	}

	const unsigned char AMT_PCIDevice::Subclass() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Subclass"), ret);
		return ret;
	}
	void AMT_PCIDevice::Subclass(const unsigned char &value)
	{
		SetOrAddField("Subclass", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::SubclassExists() const
	{
		return ContainsField("Subclass");
	}
	void AMT_PCIDevice::RemoveSubclass()
	{
		RemoveField("Subclass");
	}

	const unsigned short AMT_PCIDevice::DeviceLocation() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DeviceLocation"), ret);
		return ret;
	}
	void AMT_PCIDevice::DeviceLocation(const unsigned short value)
	{
		SetOrAddField("DeviceLocation", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::DeviceLocationExists() const
	{
		return ContainsField("DeviceLocation");
	}
	void AMT_PCIDevice::RemoveDeviceLocation()
	{
		RemoveField("DeviceLocation");
	}

	const unsigned short AMT_PCIDevice::SubsystemVendorID() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SubsystemVendorID"), ret);
		return ret;
	}
	void AMT_PCIDevice::SubsystemVendorID(const unsigned short value)
	{
		SetOrAddField("SubsystemVendorID", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::SubsystemVendorIDExists() const
	{
		return ContainsField("SubsystemVendorID");
	}
	void AMT_PCIDevice::RemoveSubsystemVendorID()
	{
		RemoveField("SubsystemVendorID");
	}

	const unsigned char AMT_PCIDevice::MinGrantTime() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("MinGrantTime"), ret);
		return ret;
	}
	void AMT_PCIDevice::MinGrantTime(const unsigned char &value)
	{
		SetOrAddField("MinGrantTime", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::MinGrantTimeExists() const
	{
		return ContainsField("MinGrantTime");
	}
	void AMT_PCIDevice::RemoveMinGrantTime()
	{
		RemoveField("MinGrantTime");
	}

	const unsigned char AMT_PCIDevice::MaxLatency() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("MaxLatency"), ret);
		return ret;
	}
	void AMT_PCIDevice::MaxLatency(const unsigned char &value)
	{
		SetOrAddField("MaxLatency", TypeConverter::TypeToString(value));
	}
	bool AMT_PCIDevice::MaxLatencyExists() const
	{
		return ContainsField("MaxLatency");
	}
	void AMT_PCIDevice::RemoveMaxLatency()
	{
		RemoveField("MaxLatency");
	}

	CimBase *AMT_PCIDevice::CreateFromCimObject(const CimObject &object)
	{
		AMT_PCIDevice *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PCIDevice>(object);
		}
		else
		{
			ret = new AMT_PCIDevice(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PCIDevice> > AMT_PCIDevice::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PCIDevice>(client, keys);
	}

	void AMT_PCIDevice::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PCIDevice::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PCIDevice::CLASS_NAME = "AMT_PCIDevice";
	const string AMT_PCIDevice::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PCIDevice";
	const string AMT_PCIDevice::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PCIDevice";
	const string AMT_PCIDevice::CLASS_NS_PREFIX = "APC965";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PCIDevice::_classMetaData;
}
}
}
}
