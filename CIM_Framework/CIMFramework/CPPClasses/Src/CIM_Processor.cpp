//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Processor.cpp
//
//  Contents:   Capabilities and management of the Processor LogicalDevice.
//
//              This file was automatically generated from CIM_Processor.mof,  version: 2.45.0
//
//----------------------------------------------------------------------------
#include "CIM_Processor.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Processor::_metadata[] = {
		{"Role", false, false, false },
		{"Family", false, false, false },
		{"OtherFamilyDescription", false, false, false },
		{"UpgradeMethod", false, false, false },
		{"MaxClockSpeed", false, false, false },
		{"CurrentClockSpeed", false, false, false },
		{"DataWidth", false, false, false },
		{"AddressWidth", false, false, false },
		{"LoadPercentage", false, false, false },
		{"Stepping", false, false, false },
		{"UniqueID", false, false, false },
		{"CPUStatus", false, false, false },
		{"ExternalBusClockSpeed", false, false, false },
		{"Characteristics", false, false, false },
		{"EnabledProcessorCharacteristics", false, false, false },
		{"NumberOfEnabledCores", false, false, false },
	};
	// class fields
	const string CIM_Processor::Role() const
	{
		return GetField("Role")[0];
	}
	void CIM_Processor::Role(const string &value)
	{
		SetOrAddField("Role", value);
	}
	bool CIM_Processor::RoleExists() const
	{
		return ContainsField("Role");
	}
	void CIM_Processor::RemoveRole()
	{
		RemoveField("Role");
	}

	const unsigned short CIM_Processor::Family() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Family"), ret);
		return ret;
	}
	void CIM_Processor::Family(const unsigned short value)
	{
		SetOrAddField("Family", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::FamilyExists() const
	{
		return ContainsField("Family");
	}
	void CIM_Processor::RemoveFamily()
	{
		RemoveField("Family");
	}

	const string CIM_Processor::OtherFamilyDescription() const
	{
		return GetField("OtherFamilyDescription")[0];
	}
	void CIM_Processor::OtherFamilyDescription(const string &value)
	{
		SetOrAddField("OtherFamilyDescription", value);
	}
	bool CIM_Processor::OtherFamilyDescriptionExists() const
	{
		return ContainsField("OtherFamilyDescription");
	}
	void CIM_Processor::RemoveOtherFamilyDescription()
	{
		RemoveField("OtherFamilyDescription");
	}

	const unsigned short CIM_Processor::UpgradeMethod() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("UpgradeMethod"), ret);
		return ret;
	}
	void CIM_Processor::UpgradeMethod(const unsigned short value)
	{
		SetOrAddField("UpgradeMethod", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::UpgradeMethodExists() const
	{
		return ContainsField("UpgradeMethod");
	}
	void CIM_Processor::RemoveUpgradeMethod()
	{
		RemoveField("UpgradeMethod");
	}

	const unsigned int CIM_Processor::MaxClockSpeed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxClockSpeed"), ret);
		return ret;
	}
	void CIM_Processor::MaxClockSpeed(const unsigned int value)
	{
		SetOrAddField("MaxClockSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::MaxClockSpeedExists() const
	{
		return ContainsField("MaxClockSpeed");
	}
	void CIM_Processor::RemoveMaxClockSpeed()
	{
		RemoveField("MaxClockSpeed");
	}

	const unsigned int CIM_Processor::CurrentClockSpeed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CurrentClockSpeed"), ret);
		return ret;
	}
	void CIM_Processor::CurrentClockSpeed(const unsigned int value)
	{
		SetOrAddField("CurrentClockSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::CurrentClockSpeedExists() const
	{
		return ContainsField("CurrentClockSpeed");
	}
	void CIM_Processor::RemoveCurrentClockSpeed()
	{
		RemoveField("CurrentClockSpeed");
	}

	const unsigned short CIM_Processor::DataWidth() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DataWidth"), ret);
		return ret;
	}
	void CIM_Processor::DataWidth(const unsigned short value)
	{
		SetOrAddField("DataWidth", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::DataWidthExists() const
	{
		return ContainsField("DataWidth");
	}
	void CIM_Processor::RemoveDataWidth()
	{
		RemoveField("DataWidth");
	}

	const unsigned short CIM_Processor::AddressWidth() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AddressWidth"), ret);
		return ret;
	}
	void CIM_Processor::AddressWidth(const unsigned short value)
	{
		SetOrAddField("AddressWidth", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::AddressWidthExists() const
	{
		return ContainsField("AddressWidth");
	}
	void CIM_Processor::RemoveAddressWidth()
	{
		RemoveField("AddressWidth");
	}

	const unsigned short CIM_Processor::LoadPercentage() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LoadPercentage"), ret);
		return ret;
	}
	void CIM_Processor::LoadPercentage(const unsigned short value)
	{
		SetOrAddField("LoadPercentage", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::LoadPercentageExists() const
	{
		return ContainsField("LoadPercentage");
	}
	void CIM_Processor::RemoveLoadPercentage()
	{
		RemoveField("LoadPercentage");
	}

	const string CIM_Processor::Stepping() const
	{
		return GetField("Stepping")[0];
	}
	void CIM_Processor::Stepping(const string &value)
	{
		SetOrAddField("Stepping", value);
	}
	bool CIM_Processor::SteppingExists() const
	{
		return ContainsField("Stepping");
	}
	void CIM_Processor::RemoveStepping()
	{
		RemoveField("Stepping");
	}

	const string CIM_Processor::UniqueID() const
	{
		return GetField("UniqueID")[0];
	}
	void CIM_Processor::UniqueID(const string &value)
	{
		SetOrAddField("UniqueID", value);
	}
	bool CIM_Processor::UniqueIDExists() const
	{
		return ContainsField("UniqueID");
	}
	void CIM_Processor::RemoveUniqueID()
	{
		RemoveField("UniqueID");
	}

	const unsigned short CIM_Processor::CPUStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CPUStatus"), ret);
		return ret;
	}
	void CIM_Processor::CPUStatus(const unsigned short value)
	{
		SetOrAddField("CPUStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::CPUStatusExists() const
	{
		return ContainsField("CPUStatus");
	}
	void CIM_Processor::RemoveCPUStatus()
	{
		RemoveField("CPUStatus");
	}

	const unsigned int CIM_Processor::ExternalBusClockSpeed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ExternalBusClockSpeed"), ret);
		return ret;
	}
	void CIM_Processor::ExternalBusClockSpeed(const unsigned int value)
	{
		SetOrAddField("ExternalBusClockSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::ExternalBusClockSpeedExists() const
	{
		return ContainsField("ExternalBusClockSpeed");
	}
	void CIM_Processor::RemoveExternalBusClockSpeed()
	{
		RemoveField("ExternalBusClockSpeed");
	}

	const vector<unsigned short> CIM_Processor::Characteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Characteristics"), ret);
		return ret;
	}
	void CIM_Processor::Characteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("Characteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::CharacteristicsExists() const
	{
		return ContainsField("Characteristics");
	}
	void CIM_Processor::RemoveCharacteristics()
	{
		RemoveField("Characteristics");
	}

	const vector<unsigned short> CIM_Processor::EnabledProcessorCharacteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("EnabledProcessorCharacteristics"), ret);
		return ret;
	}
	void CIM_Processor::EnabledProcessorCharacteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("EnabledProcessorCharacteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::EnabledProcessorCharacteristicsExists() const
	{
		return ContainsField("EnabledProcessorCharacteristics");
	}
	void CIM_Processor::RemoveEnabledProcessorCharacteristics()
	{
		RemoveField("EnabledProcessorCharacteristics");
	}

	const unsigned short CIM_Processor::NumberOfEnabledCores() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NumberOfEnabledCores"), ret);
		return ret;
	}
	void CIM_Processor::NumberOfEnabledCores(const unsigned short value)
	{
		SetOrAddField("NumberOfEnabledCores", TypeConverter::TypeToString(value));
	}
	bool CIM_Processor::NumberOfEnabledCoresExists() const
	{
		return ContainsField("NumberOfEnabledCores");
	}
	void CIM_Processor::RemoveNumberOfEnabledCores()
	{
		RemoveField("NumberOfEnabledCores");
	}

	CimBase *CIM_Processor::CreateFromCimObject(const CimObject &object)
	{
		CIM_Processor *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Processor>(object);
		}
		else
		{
			ret = new CIM_Processor(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Processor> > CIM_Processor::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Processor>(client, keys);
	}

	void CIM_Processor::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Processor::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Processor::CLASS_NAME = "CIM_Processor";
	const string CIM_Processor::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Processor";
	const string CIM_Processor::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Processor";
	const string CIM_Processor::CLASS_NS_PREFIX = "APr634";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Processor::_classMetaData;
}
}
}
}
