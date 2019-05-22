//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalPackage.cpp
//
//  Contents:   The PhysicalPackage class represents PhysicalElements that contain or host other components. Examples are a Rack enclosure or an adapter Card.
//
//              This file was automatically generated from CIM_PhysicalPackage.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalPackage.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalPackage::_metadata[] = {
		{"RemovalConditions", false, false, false },
		{"Removable", false, false, false },
		{"Replaceable", false, false, false },
		{"HotSwappable", false, false, false },
		{"Height", false, false, false },
		{"Depth", false, false, false },
		{"Width", false, false, false },
		{"Weight", false, false, false },
		{"PackageType", false, false, false },
		{"OtherPackageType", false, false, false },
		{"VendorCompatibilityStrings", false, false, false },
	};
	// class fields
	const unsigned short CIM_PhysicalPackage::RemovalConditions() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RemovalConditions"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::RemovalConditions(const unsigned short value)
	{
		SetOrAddField("RemovalConditions", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::RemovalConditionsExists() const
	{
		return ContainsField("RemovalConditions");
	}
	void CIM_PhysicalPackage::RemoveRemovalConditions()
	{
		RemoveField("RemovalConditions");
	}

	const bool CIM_PhysicalPackage::Removable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Removable"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Removable(const bool value)
	{
		SetOrAddField("Removable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::RemovableExists() const
	{
		return ContainsField("Removable");
	}
	void CIM_PhysicalPackage::RemoveRemovable()
	{
		RemoveField("Removable");
	}

	const bool CIM_PhysicalPackage::Replaceable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Replaceable"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Replaceable(const bool value)
	{
		SetOrAddField("Replaceable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::ReplaceableExists() const
	{
		return ContainsField("Replaceable");
	}
	void CIM_PhysicalPackage::RemoveReplaceable()
	{
		RemoveField("Replaceable");
	}

	const bool CIM_PhysicalPackage::HotSwappable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HotSwappable"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::HotSwappable(const bool value)
	{
		SetOrAddField("HotSwappable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::HotSwappableExists() const
	{
		return ContainsField("HotSwappable");
	}
	void CIM_PhysicalPackage::RemoveHotSwappable()
	{
		RemoveField("HotSwappable");
	}

	const double CIM_PhysicalPackage::Height() const
	{
		double ret = 0;
		TypeConverter::StringToType(GetField("Height"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Height(const double value)
	{
		SetOrAddField("Height", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::HeightExists() const
	{
		return ContainsField("Height");
	}
	void CIM_PhysicalPackage::RemoveHeight()
	{
		RemoveField("Height");
	}

	const double CIM_PhysicalPackage::Depth() const
	{
		double ret = 0;
		TypeConverter::StringToType(GetField("Depth"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Depth(const double value)
	{
		SetOrAddField("Depth", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::DepthExists() const
	{
		return ContainsField("Depth");
	}
	void CIM_PhysicalPackage::RemoveDepth()
	{
		RemoveField("Depth");
	}

	const double CIM_PhysicalPackage::Width() const
	{
		double ret = 0;
		TypeConverter::StringToType(GetField("Width"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Width(const double value)
	{
		SetOrAddField("Width", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::WidthExists() const
	{
		return ContainsField("Width");
	}
	void CIM_PhysicalPackage::RemoveWidth()
	{
		RemoveField("Width");
	}

	const double CIM_PhysicalPackage::Weight() const
	{
		double ret = 0;
		TypeConverter::StringToType(GetField("Weight"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::Weight(const double value)
	{
		SetOrAddField("Weight", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::WeightExists() const
	{
		return ContainsField("Weight");
	}
	void CIM_PhysicalPackage::RemoveWeight()
	{
		RemoveField("Weight");
	}

	const unsigned short CIM_PhysicalPackage::PackageType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PackageType"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::PackageType(const unsigned short value)
	{
		SetOrAddField("PackageType", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::PackageTypeExists() const
	{
		return ContainsField("PackageType");
	}
	void CIM_PhysicalPackage::RemovePackageType()
	{
		RemoveField("PackageType");
	}

	const string CIM_PhysicalPackage::OtherPackageType() const
	{
		return GetField("OtherPackageType")[0];
	}
	void CIM_PhysicalPackage::OtherPackageType(const string &value)
	{
		SetOrAddField("OtherPackageType", value);
	}
	bool CIM_PhysicalPackage::OtherPackageTypeExists() const
	{
		return ContainsField("OtherPackageType");
	}
	void CIM_PhysicalPackage::RemoveOtherPackageType()
	{
		RemoveField("OtherPackageType");
	}

	const vector<string> CIM_PhysicalPackage::VendorCompatibilityStrings() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("VendorCompatibilityStrings"), ret);
		return ret;
	}
	void CIM_PhysicalPackage::VendorCompatibilityStrings(const vector<string> &value)
	{
		SetOrAddField("VendorCompatibilityStrings", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalPackage::VendorCompatibilityStringsExists() const
	{
		return ContainsField("VendorCompatibilityStrings");
	}
	void CIM_PhysicalPackage::RemoveVendorCompatibilityStrings()
	{
		RemoveField("VendorCompatibilityStrings");
	}

	CimBase *CIM_PhysicalPackage::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalPackage *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalPackage>(object);
		}
		else
		{
			ret = new CIM_PhysicalPackage(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalPackage> > CIM_PhysicalPackage::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalPackage>(client, keys);
	}

	void CIM_PhysicalPackage::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalPackage::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalPackage::CLASS_NAME = "CIM_PhysicalPackage";
	const string CIM_PhysicalPackage::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalPackage";
	const string CIM_PhysicalPackage::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalPackage";
	const string CIM_PhysicalPackage::CLASS_NS_PREFIX = "APh217";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalPackage::_classMetaData;
}
}
}
}
