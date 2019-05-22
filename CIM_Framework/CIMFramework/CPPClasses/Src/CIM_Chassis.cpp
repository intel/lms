//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Chassis.cpp
//
//  Contents:   The Chassis class represents the PhysicalElements that enclose other Elements and provide definable functionality, such as a desktop, processing node, UPS, disk or tape storage, or a combination of these.
//
//              This file was automatically generated from CIM_Chassis.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#include "CIM_Chassis.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Chassis::_metadata[] = {
		{"NumberOfPowerCords", false, false, false },
		{"CurrentRequiredOrProduced", false, false, false },
		{"HeatGeneration", false, false, false },
		{"ChassisTypes", false, false, false },
		{"TypeDescriptions", false, false, false },
		{"ChassisPackageType", false, false, false },
		{"ChassisTypeDescription", false, false, false },
		{"MultipleSystemSupport", false, false, false },
		{"RackMountable", false, false, false },
	};
	// class fields
	const unsigned short CIM_Chassis::NumberOfPowerCords() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NumberOfPowerCords"), ret);
		return ret;
	}
	void CIM_Chassis::NumberOfPowerCords(const unsigned short value)
	{
		SetOrAddField("NumberOfPowerCords", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::NumberOfPowerCordsExists() const
	{
		return ContainsField("NumberOfPowerCords");
	}
	void CIM_Chassis::RemoveNumberOfPowerCords()
	{
		RemoveField("NumberOfPowerCords");
	}

	const short CIM_Chassis::CurrentRequiredOrProduced() const
	{
		short ret = 0;
		TypeConverter::StringToType(GetField("CurrentRequiredOrProduced"), ret);
		return ret;
	}
	void CIM_Chassis::CurrentRequiredOrProduced(const short value)
	{
		SetOrAddField("CurrentRequiredOrProduced", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::CurrentRequiredOrProducedExists() const
	{
		return ContainsField("CurrentRequiredOrProduced");
	}
	void CIM_Chassis::RemoveCurrentRequiredOrProduced()
	{
		RemoveField("CurrentRequiredOrProduced");
	}

	const unsigned short CIM_Chassis::HeatGeneration() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HeatGeneration"), ret);
		return ret;
	}
	void CIM_Chassis::HeatGeneration(const unsigned short value)
	{
		SetOrAddField("HeatGeneration", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::HeatGenerationExists() const
	{
		return ContainsField("HeatGeneration");
	}
	void CIM_Chassis::RemoveHeatGeneration()
	{
		RemoveField("HeatGeneration");
	}

	const vector<unsigned short> CIM_Chassis::ChassisTypes() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ChassisTypes"), ret);
		return ret;
	}
	void CIM_Chassis::ChassisTypes(const vector<unsigned short> &value)
	{
		SetOrAddField("ChassisTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::ChassisTypesExists() const
	{
		return ContainsField("ChassisTypes");
	}
	void CIM_Chassis::RemoveChassisTypes()
	{
		RemoveField("ChassisTypes");
	}

	const vector<string> CIM_Chassis::TypeDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("TypeDescriptions"), ret);
		return ret;
	}
	void CIM_Chassis::TypeDescriptions(const vector<string> &value)
	{
		SetOrAddField("TypeDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::TypeDescriptionsExists() const
	{
		return ContainsField("TypeDescriptions");
	}
	void CIM_Chassis::RemoveTypeDescriptions()
	{
		RemoveField("TypeDescriptions");
	}

	const unsigned short CIM_Chassis::ChassisPackageType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ChassisPackageType"), ret);
		return ret;
	}
	void CIM_Chassis::ChassisPackageType(const unsigned short value)
	{
		SetOrAddField("ChassisPackageType", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::ChassisPackageTypeExists() const
	{
		return ContainsField("ChassisPackageType");
	}
	void CIM_Chassis::RemoveChassisPackageType()
	{
		RemoveField("ChassisPackageType");
	}

	const string CIM_Chassis::ChassisTypeDescription() const
	{
		return GetField("ChassisTypeDescription")[0];
	}
	void CIM_Chassis::ChassisTypeDescription(const string &value)
	{
		SetOrAddField("ChassisTypeDescription", value);
	}
	bool CIM_Chassis::ChassisTypeDescriptionExists() const
	{
		return ContainsField("ChassisTypeDescription");
	}
	void CIM_Chassis::RemoveChassisTypeDescription()
	{
		RemoveField("ChassisTypeDescription");
	}

	const unsigned short CIM_Chassis::MultipleSystemSupport() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MultipleSystemSupport"), ret);
		return ret;
	}
	void CIM_Chassis::MultipleSystemSupport(const unsigned short value)
	{
		SetOrAddField("MultipleSystemSupport", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::MultipleSystemSupportExists() const
	{
		return ContainsField("MultipleSystemSupport");
	}
	void CIM_Chassis::RemoveMultipleSystemSupport()
	{
		RemoveField("MultipleSystemSupport");
	}

	const unsigned short CIM_Chassis::RackMountable() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RackMountable"), ret);
		return ret;
	}
	void CIM_Chassis::RackMountable(const unsigned short value)
	{
		SetOrAddField("RackMountable", TypeConverter::TypeToString(value));
	}
	bool CIM_Chassis::RackMountableExists() const
	{
		return ContainsField("RackMountable");
	}
	void CIM_Chassis::RemoveRackMountable()
	{
		RemoveField("RackMountable");
	}

	CimBase *CIM_Chassis::CreateFromCimObject(const CimObject &object)
	{
		CIM_Chassis *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Chassis>(object);
		}
		else
		{
			ret = new CIM_Chassis(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Chassis> > CIM_Chassis::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Chassis>(client, keys);
	}

	void CIM_Chassis::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Chassis::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Chassis::CLASS_NAME = "CIM_Chassis";
	const string CIM_Chassis::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Chassis";
	const string CIM_Chassis::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Chassis";
	const string CIM_Chassis::CLASS_NS_PREFIX = "ACh230";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Chassis::_classMetaData;
}
}
}
}
