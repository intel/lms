//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalMemory.cpp
//
//  Contents:   PhysicalMemory is a subclass of CIM_Chip, representing low level memory devices - SIMMS, DIMMs, raw memory chips, etc.
//
//              This file was automatically generated from CIM_PhysicalMemory.mof,  version: 2.33.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalMemory.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalMemory::_metadata[] = {
		{"FormFactor", false, false, false },
		{"MemoryType", false, false, false },
		{"TotalWidth", false, false, false },
		{"DataWidth", false, false, false },
		{"Speed", false, false, false },
		{"Capacity", false, false, false },
		{"BankLabel", false, false, false },
		{"PositionInRow", false, false, false },
		{"InterleavePosition", false, false, false },
		{"ConfiguredMemoryClockSpeed", false, false, false },
		{"IsSpeedInMhz", false, false, false },
		{"MaxMemorySpeed", false, false, false },
	};
	// class fields
	const unsigned short CIM_PhysicalMemory::MemoryType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MemoryType"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::MemoryType(const unsigned short value)
	{
		SetOrAddField("MemoryType", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::MemoryTypeExists() const
	{
		return ContainsField("MemoryType");
	}
	void CIM_PhysicalMemory::RemoveMemoryType()
	{
		RemoveField("MemoryType");
	}

	const unsigned short CIM_PhysicalMemory::TotalWidth() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TotalWidth"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::TotalWidth(const unsigned short value)
	{
		SetOrAddField("TotalWidth", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::TotalWidthExists() const
	{
		return ContainsField("TotalWidth");
	}
	void CIM_PhysicalMemory::RemoveTotalWidth()
	{
		RemoveField("TotalWidth");
	}

	const unsigned short CIM_PhysicalMemory::DataWidth() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DataWidth"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::DataWidth(const unsigned short value)
	{
		SetOrAddField("DataWidth", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::DataWidthExists() const
	{
		return ContainsField("DataWidth");
	}
	void CIM_PhysicalMemory::RemoveDataWidth()
	{
		RemoveField("DataWidth");
	}

	const unsigned int CIM_PhysicalMemory::Speed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Speed"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::Speed(const unsigned int value)
	{
		SetOrAddField("Speed", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::SpeedExists() const
	{
		return ContainsField("Speed");
	}
	void CIM_PhysicalMemory::RemoveSpeed()
	{
		RemoveField("Speed");
	}

	const Uint64 CIM_PhysicalMemory::Capacity() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("Capacity"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::Capacity(const Uint64 value)
	{
		SetOrAddField("Capacity", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::CapacityExists() const
	{
		return ContainsField("Capacity");
	}
	void CIM_PhysicalMemory::RemoveCapacity()
	{
		RemoveField("Capacity");
	}

	const string CIM_PhysicalMemory::BankLabel() const
	{
		return GetField("BankLabel")[0];
	}
	void CIM_PhysicalMemory::BankLabel(const string &value)
	{
		SetOrAddField("BankLabel", value);
	}
	bool CIM_PhysicalMemory::BankLabelExists() const
	{
		return ContainsField("BankLabel");
	}
	void CIM_PhysicalMemory::RemoveBankLabel()
	{
		RemoveField("BankLabel");
	}

	const unsigned int CIM_PhysicalMemory::PositionInRow() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PositionInRow"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::PositionInRow(const unsigned int value)
	{
		SetOrAddField("PositionInRow", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::PositionInRowExists() const
	{
		return ContainsField("PositionInRow");
	}
	void CIM_PhysicalMemory::RemovePositionInRow()
	{
		RemoveField("PositionInRow");
	}

	const unsigned int CIM_PhysicalMemory::InterleavePosition() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("InterleavePosition"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::InterleavePosition(const unsigned int value)
	{
		SetOrAddField("InterleavePosition", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::InterleavePositionExists() const
	{
		return ContainsField("InterleavePosition");
	}
	void CIM_PhysicalMemory::RemoveInterleavePosition()
	{
		RemoveField("InterleavePosition");
	}

	const unsigned int CIM_PhysicalMemory::ConfiguredMemoryClockSpeed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ConfiguredMemoryClockSpeed"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::ConfiguredMemoryClockSpeed(const unsigned int value)
	{
		SetOrAddField("ConfiguredMemoryClockSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::ConfiguredMemoryClockSpeedExists() const
	{
		return ContainsField("ConfiguredMemoryClockSpeed");
	}
	void CIM_PhysicalMemory::RemoveConfiguredMemoryClockSpeed()
	{
		RemoveField("ConfiguredMemoryClockSpeed");
	}

	const bool CIM_PhysicalMemory::IsSpeedInMhz() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsSpeedInMhz"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::IsSpeedInMhz(const bool value)
	{
		SetOrAddField("IsSpeedInMhz", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::IsSpeedInMhzExists() const
	{
		return ContainsField("IsSpeedInMhz");
	}
	void CIM_PhysicalMemory::RemoveIsSpeedInMhz()
	{
		RemoveField("IsSpeedInMhz");
	}

	const unsigned int CIM_PhysicalMemory::MaxMemorySpeed() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxMemorySpeed"), ret);
		return ret;
	}
	void CIM_PhysicalMemory::MaxMemorySpeed(const unsigned int value)
	{
		SetOrAddField("MaxMemorySpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalMemory::MaxMemorySpeedExists() const
	{
		return ContainsField("MaxMemorySpeed");
	}
	void CIM_PhysicalMemory::RemoveMaxMemorySpeed()
	{
		RemoveField("MaxMemorySpeed");
	}

	CimBase *CIM_PhysicalMemory::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalMemory *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalMemory>(object);
		}
		else
		{
			ret = new CIM_PhysicalMemory(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalMemory> > CIM_PhysicalMemory::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalMemory>(client, keys);
	}

	void CIM_PhysicalMemory::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalMemory::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalMemory::CLASS_NAME = "CIM_PhysicalMemory";
	const string CIM_PhysicalMemory::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalMemory";
	const string CIM_PhysicalMemory::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalMemory";
	const string CIM_PhysicalMemory::CLASS_NS_PREFIX = "APh560";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalMemory::_classMetaData;
}
}
}
}
