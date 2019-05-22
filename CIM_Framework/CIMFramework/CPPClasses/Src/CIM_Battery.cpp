//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Battery.cpp
//
//  Contents:   Capabilities and management of the Battery. This class applies to both batteries in Laptop Systems and other internal or external batteries, such as an uninterruptible power supply (UPS).
//
//              This file was automatically generated from CIM_Battery.mof,  version: 2.26.0
//
//----------------------------------------------------------------------------
#include "CIM_Battery.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Battery::_metadata[] = {
		{"BatteryStatus", false, false, false },
		{"TimeOnBattery", false, false, false },
		{"EstimatedRunTime", false, false, false },
		{"EstimatedChargeRemaining", false, false, false },
		{"Chemistry", false, false, false },
		{"DesignCapacity", false, false, false },
		{"FullChargeCapacity", false, false, false },
		{"DesignVoltage", false, false, false },
		{"SmartBatteryVersion", false, false, false },
		{"TimeToFullCharge", false, false, false },
		{"ExpectedLife", false, false, false },
		{"MaxRechargeTime", false, false, false },
		{"RechargeCount", false, false, false },
		{"MaxRechargeCount", false, false, false },
		{"RemainingCapacity", false, false, false },
		{"RemainingCapacityMaxError", false, false, false },
		{"OtherChemistryDescription", false, false, false },
		{"ChargingStatus", false, false, false },
		{"HealthPercent", false, false, false },
	};
	// class fields
	const unsigned short CIM_Battery::BatteryStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BatteryStatus"), ret);
		return ret;
	}
	void CIM_Battery::BatteryStatus(const unsigned short value)
	{
		SetOrAddField("BatteryStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::BatteryStatusExists() const
	{
		return ContainsField("BatteryStatus");
	}
	void CIM_Battery::RemoveBatteryStatus()
	{
		RemoveField("BatteryStatus");
	}

	const unsigned int CIM_Battery::TimeOnBattery() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TimeOnBattery"), ret);
		return ret;
	}
	void CIM_Battery::TimeOnBattery(const unsigned int value)
	{
		SetOrAddField("TimeOnBattery", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::TimeOnBatteryExists() const
	{
		return ContainsField("TimeOnBattery");
	}
	void CIM_Battery::RemoveTimeOnBattery()
	{
		RemoveField("TimeOnBattery");
	}

	const unsigned int CIM_Battery::EstimatedRunTime() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("EstimatedRunTime"), ret);
		return ret;
	}
	void CIM_Battery::EstimatedRunTime(const unsigned int value)
	{
		SetOrAddField("EstimatedRunTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::EstimatedRunTimeExists() const
	{
		return ContainsField("EstimatedRunTime");
	}
	void CIM_Battery::RemoveEstimatedRunTime()
	{
		RemoveField("EstimatedRunTime");
	}

	const unsigned short CIM_Battery::EstimatedChargeRemaining() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EstimatedChargeRemaining"), ret);
		return ret;
	}
	void CIM_Battery::EstimatedChargeRemaining(const unsigned short value)
	{
		SetOrAddField("EstimatedChargeRemaining", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::EstimatedChargeRemainingExists() const
	{
		return ContainsField("EstimatedChargeRemaining");
	}
	void CIM_Battery::RemoveEstimatedChargeRemaining()
	{
		RemoveField("EstimatedChargeRemaining");
	}

	const unsigned short CIM_Battery::Chemistry() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Chemistry"), ret);
		return ret;
	}
	void CIM_Battery::Chemistry(const unsigned short value)
	{
		SetOrAddField("Chemistry", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::ChemistryExists() const
	{
		return ContainsField("Chemistry");
	}
	void CIM_Battery::RemoveChemistry()
	{
		RemoveField("Chemistry");
	}

	const unsigned int CIM_Battery::DesignCapacity() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("DesignCapacity"), ret);
		return ret;
	}
	void CIM_Battery::DesignCapacity(const unsigned int value)
	{
		SetOrAddField("DesignCapacity", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::DesignCapacityExists() const
	{
		return ContainsField("DesignCapacity");
	}
	void CIM_Battery::RemoveDesignCapacity()
	{
		RemoveField("DesignCapacity");
	}

	const unsigned int CIM_Battery::FullChargeCapacity() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("FullChargeCapacity"), ret);
		return ret;
	}
	void CIM_Battery::FullChargeCapacity(const unsigned int value)
	{
		SetOrAddField("FullChargeCapacity", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::FullChargeCapacityExists() const
	{
		return ContainsField("FullChargeCapacity");
	}
	void CIM_Battery::RemoveFullChargeCapacity()
	{
		RemoveField("FullChargeCapacity");
	}

	const Uint64 CIM_Battery::DesignVoltage() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("DesignVoltage"), ret);
		return ret;
	}
	void CIM_Battery::DesignVoltage(const Uint64 value)
	{
		SetOrAddField("DesignVoltage", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::DesignVoltageExists() const
	{
		return ContainsField("DesignVoltage");
	}
	void CIM_Battery::RemoveDesignVoltage()
	{
		RemoveField("DesignVoltage");
	}

	const string CIM_Battery::SmartBatteryVersion() const
	{
		return GetField("SmartBatteryVersion")[0];
	}
	void CIM_Battery::SmartBatteryVersion(const string &value)
	{
		SetOrAddField("SmartBatteryVersion", value);
	}
	bool CIM_Battery::SmartBatteryVersionExists() const
	{
		return ContainsField("SmartBatteryVersion");
	}
	void CIM_Battery::RemoveSmartBatteryVersion()
	{
		RemoveField("SmartBatteryVersion");
	}

	const unsigned int CIM_Battery::TimeToFullCharge() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TimeToFullCharge"), ret);
		return ret;
	}
	void CIM_Battery::TimeToFullCharge(const unsigned int value)
	{
		SetOrAddField("TimeToFullCharge", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::TimeToFullChargeExists() const
	{
		return ContainsField("TimeToFullCharge");
	}
	void CIM_Battery::RemoveTimeToFullCharge()
	{
		RemoveField("TimeToFullCharge");
	}

	const unsigned int CIM_Battery::ExpectedLife() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ExpectedLife"), ret);
		return ret;
	}
	void CIM_Battery::ExpectedLife(const unsigned int value)
	{
		SetOrAddField("ExpectedLife", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::ExpectedLifeExists() const
	{
		return ContainsField("ExpectedLife");
	}
	void CIM_Battery::RemoveExpectedLife()
	{
		RemoveField("ExpectedLife");
	}

	const unsigned int CIM_Battery::MaxRechargeTime() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxRechargeTime"), ret);
		return ret;
	}
	void CIM_Battery::MaxRechargeTime(const unsigned int value)
	{
		SetOrAddField("MaxRechargeTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::MaxRechargeTimeExists() const
	{
		return ContainsField("MaxRechargeTime");
	}
	void CIM_Battery::RemoveMaxRechargeTime()
	{
		RemoveField("MaxRechargeTime");
	}

	const unsigned int CIM_Battery::RechargeCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RechargeCount"), ret);
		return ret;
	}
	void CIM_Battery::RechargeCount(const unsigned int value)
	{
		SetOrAddField("RechargeCount", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::RechargeCountExists() const
	{
		return ContainsField("RechargeCount");
	}
	void CIM_Battery::RemoveRechargeCount()
	{
		RemoveField("RechargeCount");
	}

	const unsigned int CIM_Battery::MaxRechargeCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxRechargeCount"), ret);
		return ret;
	}
	void CIM_Battery::MaxRechargeCount(const unsigned int value)
	{
		SetOrAddField("MaxRechargeCount", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::MaxRechargeCountExists() const
	{
		return ContainsField("MaxRechargeCount");
	}
	void CIM_Battery::RemoveMaxRechargeCount()
	{
		RemoveField("MaxRechargeCount");
	}

	const unsigned int CIM_Battery::RemainingCapacity() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RemainingCapacity"), ret);
		return ret;
	}
	void CIM_Battery::RemainingCapacity(const unsigned int value)
	{
		SetOrAddField("RemainingCapacity", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::RemainingCapacityExists() const
	{
		return ContainsField("RemainingCapacity");
	}
	void CIM_Battery::RemoveRemainingCapacity()
	{
		RemoveField("RemainingCapacity");
	}

	const unsigned char CIM_Battery::RemainingCapacityMaxError() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("RemainingCapacityMaxError"), ret);
		return ret;
	}
	void CIM_Battery::RemainingCapacityMaxError(const unsigned char &value)
	{
		SetOrAddField("RemainingCapacityMaxError", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::RemainingCapacityMaxErrorExists() const
	{
		return ContainsField("RemainingCapacityMaxError");
	}
	void CIM_Battery::RemoveRemainingCapacityMaxError()
	{
		RemoveField("RemainingCapacityMaxError");
	}

	const string CIM_Battery::OtherChemistryDescription() const
	{
		return GetField("OtherChemistryDescription")[0];
	}
	void CIM_Battery::OtherChemistryDescription(const string &value)
	{
		SetOrAddField("OtherChemistryDescription", value);
	}
	bool CIM_Battery::OtherChemistryDescriptionExists() const
	{
		return ContainsField("OtherChemistryDescription");
	}
	void CIM_Battery::RemoveOtherChemistryDescription()
	{
		RemoveField("OtherChemistryDescription");
	}

	const unsigned short CIM_Battery::ChargingStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ChargingStatus"), ret);
		return ret;
	}
	void CIM_Battery::ChargingStatus(const unsigned short value)
	{
		SetOrAddField("ChargingStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::ChargingStatusExists() const
	{
		return ContainsField("ChargingStatus");
	}
	void CIM_Battery::RemoveChargingStatus()
	{
		RemoveField("ChargingStatus");
	}

	const unsigned char CIM_Battery::HealthPercent() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HealthPercent"), ret);
		return ret;
	}
	void CIM_Battery::HealthPercent(const unsigned char &value)
	{
		SetOrAddField("HealthPercent", TypeConverter::TypeToString(value));
	}
	bool CIM_Battery::HealthPercentExists() const
	{
		return ContainsField("HealthPercent");
	}
	void CIM_Battery::RemoveHealthPercent()
	{
		RemoveField("HealthPercent");
	}

	CimBase *CIM_Battery::CreateFromCimObject(const CimObject &object)
	{
		CIM_Battery *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Battery>(object);
		}
		else
		{
			ret = new CIM_Battery(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Battery> > CIM_Battery::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Battery>(client, keys);
	}

	void CIM_Battery::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Battery::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Battery::CLASS_NAME = "CIM_Battery";
	const string CIM_Battery::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Battery";
	const string CIM_Battery::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Battery";
	const string CIM_Battery::CLASS_NS_PREFIX = "ABa13";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Battery::_classMetaData;
}
}
}
}
