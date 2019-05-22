//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerSupply.cpp
//
//  Contents:   Capabilities and management of the PowerSupply LogicalDevice.
//
//              This file was automatically generated from CIM_PowerSupply.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_PowerSupply.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PowerSupply::_metadata[] = {
		{"IsSwitchingSupply", false, false, false },
		{"Range1InputVoltageLow", false, false, false },
		{"Range1InputVoltageHigh", false, false, false },
		{"Range1InputFrequencyLow", false, false, false },
		{"Range1InputFrequencyHigh", false, false, false },
		{"Range2InputVoltageLow", false, false, false },
		{"Range2InputVoltageHigh", false, false, false },
		{"Range2InputFrequencyLow", false, false, false },
		{"Range2InputFrequencyHigh", false, false, false },
		{"ActiveInputVoltage", false, false, false },
		{"TypeOfRangeSwitching", false, false, false },
		{"TotalOutputPower", false, false, false },
	};
	// class fields
	const bool CIM_PowerSupply::IsSwitchingSupply() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsSwitchingSupply"), ret);
		return ret;
	}
	void CIM_PowerSupply::IsSwitchingSupply(const bool value)
	{
		SetOrAddField("IsSwitchingSupply", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::IsSwitchingSupplyExists() const
	{
		return ContainsField("IsSwitchingSupply");
	}
	void CIM_PowerSupply::RemoveIsSwitchingSupply()
	{
		RemoveField("IsSwitchingSupply");
	}

	const unsigned int CIM_PowerSupply::Range1InputVoltageLow() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range1InputVoltageLow"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range1InputVoltageLow(const unsigned int value)
	{
		SetOrAddField("Range1InputVoltageLow", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range1InputVoltageLowExists() const
	{
		return ContainsField("Range1InputVoltageLow");
	}
	void CIM_PowerSupply::RemoveRange1InputVoltageLow()
	{
		RemoveField("Range1InputVoltageLow");
	}

	const unsigned int CIM_PowerSupply::Range1InputVoltageHigh() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range1InputVoltageHigh"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range1InputVoltageHigh(const unsigned int value)
	{
		SetOrAddField("Range1InputVoltageHigh", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range1InputVoltageHighExists() const
	{
		return ContainsField("Range1InputVoltageHigh");
	}
	void CIM_PowerSupply::RemoveRange1InputVoltageHigh()
	{
		RemoveField("Range1InputVoltageHigh");
	}

	const unsigned int CIM_PowerSupply::Range1InputFrequencyLow() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range1InputFrequencyLow"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range1InputFrequencyLow(const unsigned int value)
	{
		SetOrAddField("Range1InputFrequencyLow", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range1InputFrequencyLowExists() const
	{
		return ContainsField("Range1InputFrequencyLow");
	}
	void CIM_PowerSupply::RemoveRange1InputFrequencyLow()
	{
		RemoveField("Range1InputFrequencyLow");
	}

	const unsigned int CIM_PowerSupply::Range1InputFrequencyHigh() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range1InputFrequencyHigh"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range1InputFrequencyHigh(const unsigned int value)
	{
		SetOrAddField("Range1InputFrequencyHigh", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range1InputFrequencyHighExists() const
	{
		return ContainsField("Range1InputFrequencyHigh");
	}
	void CIM_PowerSupply::RemoveRange1InputFrequencyHigh()
	{
		RemoveField("Range1InputFrequencyHigh");
	}

	const unsigned int CIM_PowerSupply::Range2InputVoltageLow() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range2InputVoltageLow"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range2InputVoltageLow(const unsigned int value)
	{
		SetOrAddField("Range2InputVoltageLow", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range2InputVoltageLowExists() const
	{
		return ContainsField("Range2InputVoltageLow");
	}
	void CIM_PowerSupply::RemoveRange2InputVoltageLow()
	{
		RemoveField("Range2InputVoltageLow");
	}

	const unsigned int CIM_PowerSupply::Range2InputVoltageHigh() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range2InputVoltageHigh"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range2InputVoltageHigh(const unsigned int value)
	{
		SetOrAddField("Range2InputVoltageHigh", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range2InputVoltageHighExists() const
	{
		return ContainsField("Range2InputVoltageHigh");
	}
	void CIM_PowerSupply::RemoveRange2InputVoltageHigh()
	{
		RemoveField("Range2InputVoltageHigh");
	}

	const unsigned int CIM_PowerSupply::Range2InputFrequencyLow() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range2InputFrequencyLow"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range2InputFrequencyLow(const unsigned int value)
	{
		SetOrAddField("Range2InputFrequencyLow", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range2InputFrequencyLowExists() const
	{
		return ContainsField("Range2InputFrequencyLow");
	}
	void CIM_PowerSupply::RemoveRange2InputFrequencyLow()
	{
		RemoveField("Range2InputFrequencyLow");
	}

	const unsigned int CIM_PowerSupply::Range2InputFrequencyHigh() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Range2InputFrequencyHigh"), ret);
		return ret;
	}
	void CIM_PowerSupply::Range2InputFrequencyHigh(const unsigned int value)
	{
		SetOrAddField("Range2InputFrequencyHigh", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::Range2InputFrequencyHighExists() const
	{
		return ContainsField("Range2InputFrequencyHigh");
	}
	void CIM_PowerSupply::RemoveRange2InputFrequencyHigh()
	{
		RemoveField("Range2InputFrequencyHigh");
	}

	const unsigned short CIM_PowerSupply::ActiveInputVoltage() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ActiveInputVoltage"), ret);
		return ret;
	}
	void CIM_PowerSupply::ActiveInputVoltage(const unsigned short value)
	{
		SetOrAddField("ActiveInputVoltage", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::ActiveInputVoltageExists() const
	{
		return ContainsField("ActiveInputVoltage");
	}
	void CIM_PowerSupply::RemoveActiveInputVoltage()
	{
		RemoveField("ActiveInputVoltage");
	}

	const unsigned short CIM_PowerSupply::TypeOfRangeSwitching() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TypeOfRangeSwitching"), ret);
		return ret;
	}
	void CIM_PowerSupply::TypeOfRangeSwitching(const unsigned short value)
	{
		SetOrAddField("TypeOfRangeSwitching", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::TypeOfRangeSwitchingExists() const
	{
		return ContainsField("TypeOfRangeSwitching");
	}
	void CIM_PowerSupply::RemoveTypeOfRangeSwitching()
	{
		RemoveField("TypeOfRangeSwitching");
	}

	const unsigned int CIM_PowerSupply::TotalOutputPower() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalOutputPower"), ret);
		return ret;
	}
	void CIM_PowerSupply::TotalOutputPower(const unsigned int value)
	{
		SetOrAddField("TotalOutputPower", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerSupply::TotalOutputPowerExists() const
	{
		return ContainsField("TotalOutputPower");
	}
	void CIM_PowerSupply::RemoveTotalOutputPower()
	{
		RemoveField("TotalOutputPower");
	}

	CimBase *CIM_PowerSupply::CreateFromCimObject(const CimObject &object)
	{
		CIM_PowerSupply *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PowerSupply>(object);
		}
		else
		{
			ret = new CIM_PowerSupply(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PowerSupply> > CIM_PowerSupply::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PowerSupply>(client, keys);
	}

	void CIM_PowerSupply::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PowerSupply::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PowerSupply::CLASS_NAME = "CIM_PowerSupply";
	const string CIM_PowerSupply::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerSupply";
	const string CIM_PowerSupply::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerSupply";
	const string CIM_PowerSupply::CLASS_NS_PREFIX = "APo380";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PowerSupply::_classMetaData;
}
}
}
}
