//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Card.cpp
//
//  Contents:   The Card class represents a type of physical container that can be plugged into another Card or HostingBoard, or is itself a HostingBoard/Motherboard in a Chassis. The CIM_Card class includes any package capable of carrying signals and providing a mounting point for PhysicalComponents, such as Chips, or other PhysicalPackages, such as other Cards.
//
//              This file was automatically generated from CIM_Card.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_Card.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Card::_metadata[] = {
		{"HostingBoard", false, false, false },
		{"SlotLayout", false, false, false },
		{"RequiresDaughterBoard", false, false, false },
		{"SpecialRequirements", false, false, false },
		{"RequirementsDescription", false, false, false },
		{"OperatingVoltages", false, false, false },
	};
	// class fields
	const bool CIM_Card::HostingBoard() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HostingBoard"), ret);
		return ret;
	}
	void CIM_Card::HostingBoard(const bool value)
	{
		SetOrAddField("HostingBoard", TypeConverter::TypeToString(value));
	}
	bool CIM_Card::HostingBoardExists() const
	{
		return ContainsField("HostingBoard");
	}
	void CIM_Card::RemoveHostingBoard()
	{
		RemoveField("HostingBoard");
	}

	const string CIM_Card::SlotLayout() const
	{
		return GetField("SlotLayout")[0];
	}
	void CIM_Card::SlotLayout(const string &value)
	{
		SetOrAddField("SlotLayout", value);
	}
	bool CIM_Card::SlotLayoutExists() const
	{
		return ContainsField("SlotLayout");
	}
	void CIM_Card::RemoveSlotLayout()
	{
		RemoveField("SlotLayout");
	}

	const bool CIM_Card::RequiresDaughterBoard() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RequiresDaughterBoard"), ret);
		return ret;
	}
	void CIM_Card::RequiresDaughterBoard(const bool value)
	{
		SetOrAddField("RequiresDaughterBoard", TypeConverter::TypeToString(value));
	}
	bool CIM_Card::RequiresDaughterBoardExists() const
	{
		return ContainsField("RequiresDaughterBoard");
	}
	void CIM_Card::RemoveRequiresDaughterBoard()
	{
		RemoveField("RequiresDaughterBoard");
	}

	const bool CIM_Card::SpecialRequirements() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SpecialRequirements"), ret);
		return ret;
	}
	void CIM_Card::SpecialRequirements(const bool value)
	{
		SetOrAddField("SpecialRequirements", TypeConverter::TypeToString(value));
	}
	bool CIM_Card::SpecialRequirementsExists() const
	{
		return ContainsField("SpecialRequirements");
	}
	void CIM_Card::RemoveSpecialRequirements()
	{
		RemoveField("SpecialRequirements");
	}

	const string CIM_Card::RequirementsDescription() const
	{
		return GetField("RequirementsDescription")[0];
	}
	void CIM_Card::RequirementsDescription(const string &value)
	{
		SetOrAddField("RequirementsDescription", value);
	}
	bool CIM_Card::RequirementsDescriptionExists() const
	{
		return ContainsField("RequirementsDescription");
	}
	void CIM_Card::RemoveRequirementsDescription()
	{
		RemoveField("RequirementsDescription");
	}

	const vector<short> CIM_Card::OperatingVoltages() const
	{
		vector<short> ret;
		TypeConverter::StringToType(GetField("OperatingVoltages"), ret);
		return ret;
	}
	void CIM_Card::OperatingVoltages(const vector<short> &value)
	{
		SetOrAddField("OperatingVoltages", TypeConverter::TypeToString(value));
	}
	bool CIM_Card::OperatingVoltagesExists() const
	{
		return ContainsField("OperatingVoltages");
	}
	void CIM_Card::RemoveOperatingVoltages()
	{
		RemoveField("OperatingVoltages");
	}

	CimBase *CIM_Card::CreateFromCimObject(const CimObject &object)
	{
		CIM_Card *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Card>(object);
		}
		else
		{
			ret = new CIM_Card(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Card> > CIM_Card::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Card>(client, keys);
	}

	void CIM_Card::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Card::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Card::CLASS_NAME = "CIM_Card";
	const string CIM_Card::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Card";
	const string CIM_Card::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Card";
	const string CIM_Card::CLASS_NS_PREFIX = "ACa600";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Card::_classMetaData;
}
}
}
}
