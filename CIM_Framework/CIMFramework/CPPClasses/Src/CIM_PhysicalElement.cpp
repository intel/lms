//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalElement.cpp
//
//  Contents:   Subclasses of CIM_PhysicalElement define any component of a System that has a distinct physical identity. Instances of this class can be defined as an object that can be seen or touched. All Processes, Files, and LogicalDevices are considered not to be Physical Elements. For example, it is not possible to touch the functionality of a 'modem.' You can touch only the card or package that implements the modem. The same card could also implement a LAN adapter. PhysicalElements are tangible ManagedSystemElements that have a physical manifestation of some sort. 
//              
//              Note that the properties of PhysicalElement describe a hardware entity. Possible replacement (FRU) information is defined by following the ElementFRU association to one or more instances of the ReplacementFRU class. This definition allows a client to determine what hardware can be replaced (FRUed) and what 'spare' parts might be required by a customer or engineer doing the replacement. If it can be instrumented or manually determined that an element actually replaced (FRUed) another, then this can be described in the model using the ElementHasBeenFRUed association.
//
//              This file was automatically generated from CIM_PhysicalElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalElement::_metadata[] = {
		{"Tag", true, false, false },
		{"Description", false, false, false },
		{"CreationClassName", true, false, false },
		{"ElementName", false, false, false },
		{"Manufacturer", false, false, false },
		{"Model", false, false, false },
		{"SKU", false, false, false },
		{"SerialNumber", false, false, false },
		{"Version", false, false, false },
		{"PartNumber", false, false, false },
		{"OtherIdentifyingInfo", false, false, false },
		{"PoweredOn", false, false, false },
		{"ManufactureDate", false, false, false },
		{"VendorEquipmentType", false, false, false },
		{"UserTracking", false, false, false },
		{"CanBeFRUed", false, false, false },
	};
	// class fields
	const string CIM_PhysicalElement::Tag() const
	{
		return GetField("Tag")[0];
	}
	void CIM_PhysicalElement::Tag(const string &value)
	{
		SetOrAddField("Tag", value);
	}

	const string CIM_PhysicalElement::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_PhysicalElement::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_PhysicalElement::Manufacturer() const
	{
		return GetField("Manufacturer")[0];
	}
	void CIM_PhysicalElement::Manufacturer(const string &value)
	{
		SetOrAddField("Manufacturer", value);
	}
	bool CIM_PhysicalElement::ManufacturerExists() const
	{
		return ContainsField("Manufacturer");
	}
	void CIM_PhysicalElement::RemoveManufacturer()
	{
		RemoveField("Manufacturer");
	}

	const string CIM_PhysicalElement::Model() const
	{
		return GetField("Model")[0];
	}
	void CIM_PhysicalElement::Model(const string &value)
	{
		SetOrAddField("Model", value);
	}
	bool CIM_PhysicalElement::ModelExists() const
	{
		return ContainsField("Model");
	}
	void CIM_PhysicalElement::RemoveModel()
	{
		RemoveField("Model");
	}

	const string CIM_PhysicalElement::SKU() const
	{
		return GetField("SKU")[0];
	}
	void CIM_PhysicalElement::SKU(const string &value)
	{
		SetOrAddField("SKU", value);
	}
	bool CIM_PhysicalElement::SKUExists() const
	{
		return ContainsField("SKU");
	}
	void CIM_PhysicalElement::RemoveSKU()
	{
		RemoveField("SKU");
	}

	const string CIM_PhysicalElement::SerialNumber() const
	{
		return GetField("SerialNumber")[0];
	}
	void CIM_PhysicalElement::SerialNumber(const string &value)
	{
		SetOrAddField("SerialNumber", value);
	}
	bool CIM_PhysicalElement::SerialNumberExists() const
	{
		return ContainsField("SerialNumber");
	}
	void CIM_PhysicalElement::RemoveSerialNumber()
	{
		RemoveField("SerialNumber");
	}

	const string CIM_PhysicalElement::Version() const
	{
		return GetField("Version")[0];
	}
	void CIM_PhysicalElement::Version(const string &value)
	{
		SetOrAddField("Version", value);
	}
	bool CIM_PhysicalElement::VersionExists() const
	{
		return ContainsField("Version");
	}
	void CIM_PhysicalElement::RemoveVersion()
	{
		RemoveField("Version");
	}

	const string CIM_PhysicalElement::PartNumber() const
	{
		return GetField("PartNumber")[0];
	}
	void CIM_PhysicalElement::PartNumber(const string &value)
	{
		SetOrAddField("PartNumber", value);
	}
	bool CIM_PhysicalElement::PartNumberExists() const
	{
		return ContainsField("PartNumber");
	}
	void CIM_PhysicalElement::RemovePartNumber()
	{
		RemoveField("PartNumber");
	}

	const string CIM_PhysicalElement::OtherIdentifyingInfo() const
	{
		return GetField("OtherIdentifyingInfo")[0];
	}
	void CIM_PhysicalElement::OtherIdentifyingInfo(const string &value)
	{
		SetOrAddField("OtherIdentifyingInfo", value);
	}
	bool CIM_PhysicalElement::OtherIdentifyingInfoExists() const
	{
		return ContainsField("OtherIdentifyingInfo");
	}
	void CIM_PhysicalElement::RemoveOtherIdentifyingInfo()
	{
		RemoveField("OtherIdentifyingInfo");
	}

	const bool CIM_PhysicalElement::PoweredOn() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PoweredOn"), ret);
		return ret;
	}
	void CIM_PhysicalElement::PoweredOn(const bool value)
	{
		SetOrAddField("PoweredOn", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalElement::PoweredOnExists() const
	{
		return ContainsField("PoweredOn");
	}
	void CIM_PhysicalElement::RemovePoweredOn()
	{
		RemoveField("PoweredOn");
	}

	const CimDateTime CIM_PhysicalElement::ManufactureDate() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ManufactureDate"), ret);
		return ret;
	}
	void CIM_PhysicalElement::ManufactureDate(const CimDateTime &value)
	{
		SetOrAddField("ManufactureDate", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalElement::ManufactureDateExists() const
	{
		return ContainsField("ManufactureDate");
	}
	void CIM_PhysicalElement::RemoveManufactureDate()
	{
		RemoveField("ManufactureDate");
	}

	const string CIM_PhysicalElement::VendorEquipmentType() const
	{
		return GetField("VendorEquipmentType")[0];
	}
	void CIM_PhysicalElement::VendorEquipmentType(const string &value)
	{
		SetOrAddField("VendorEquipmentType", value);
	}
	bool CIM_PhysicalElement::VendorEquipmentTypeExists() const
	{
		return ContainsField("VendorEquipmentType");
	}
	void CIM_PhysicalElement::RemoveVendorEquipmentType()
	{
		RemoveField("VendorEquipmentType");
	}

	const string CIM_PhysicalElement::UserTracking() const
	{
		return GetField("UserTracking")[0];
	}
	void CIM_PhysicalElement::UserTracking(const string &value)
	{
		SetOrAddField("UserTracking", value);
	}
	bool CIM_PhysicalElement::UserTrackingExists() const
	{
		return ContainsField("UserTracking");
	}
	void CIM_PhysicalElement::RemoveUserTracking()
	{
		RemoveField("UserTracking");
	}

	const bool CIM_PhysicalElement::CanBeFRUed() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("CanBeFRUed"), ret);
		return ret;
	}
	void CIM_PhysicalElement::CanBeFRUed(const bool value)
	{
		SetOrAddField("CanBeFRUed", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalElement::CanBeFRUedExists() const
	{
		return ContainsField("CanBeFRUed");
	}
	void CIM_PhysicalElement::RemoveCanBeFRUed()
	{
		RemoveField("CanBeFRUed");
	}

	CimBase *CIM_PhysicalElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalElement>(object);
		}
		else
		{
			ret = new CIM_PhysicalElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalElement> > CIM_PhysicalElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalElement>(client, keys);
	}

	void CIM_PhysicalElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalElement::CLASS_NAME = "CIM_PhysicalElement";
	const string CIM_PhysicalElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalElement";
	const string CIM_PhysicalElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalElement";
	const string CIM_PhysicalElement::CLASS_NS_PREFIX = "APh541";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalElement::_classMetaData;
}
}
}
}
