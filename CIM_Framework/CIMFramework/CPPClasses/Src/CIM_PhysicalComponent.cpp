//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalComponent.cpp
//
//  Contents:   The PhysicalComponent class represents any low-level or basic Component within a Package. A Component object either can not or does not need to be decomposed into its constituent parts. For example, an ASIC (or Chip) can not be further decomposed. A tape for data storage (PhysicalMedia) does not need to be decomposed. Any PhysicalElement that is not a Link, Connector, or Package is a descendent (or member) of this class. For example, the UART chipset on an internal modem Card would be a subclass (if additional properties or associations are defined) or an instance of PhysicalComponent.
//
//              This file was automatically generated from CIM_PhysicalComponent.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalComponent::_metadata[] = {
		{"RemovalConditions", false, false, false },
		{"Removable", false, false, false },
		{"Replaceable", false, false, false },
		{"HotSwappable", false, false, false },
	};
	// class fields
	const unsigned short CIM_PhysicalComponent::RemovalConditions() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RemovalConditions"), ret);
		return ret;
	}
	void CIM_PhysicalComponent::RemovalConditions(const unsigned short value)
	{
		SetOrAddField("RemovalConditions", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalComponent::RemovalConditionsExists() const
	{
		return ContainsField("RemovalConditions");
	}
	void CIM_PhysicalComponent::RemoveRemovalConditions()
	{
		RemoveField("RemovalConditions");
	}

	const bool CIM_PhysicalComponent::Removable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Removable"), ret);
		return ret;
	}
	void CIM_PhysicalComponent::Removable(const bool value)
	{
		SetOrAddField("Removable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalComponent::RemovableExists() const
	{
		return ContainsField("Removable");
	}
	void CIM_PhysicalComponent::RemoveRemovable()
	{
		RemoveField("Removable");
	}

	const bool CIM_PhysicalComponent::Replaceable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Replaceable"), ret);
		return ret;
	}
	void CIM_PhysicalComponent::Replaceable(const bool value)
	{
		SetOrAddField("Replaceable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalComponent::ReplaceableExists() const
	{
		return ContainsField("Replaceable");
	}
	void CIM_PhysicalComponent::RemoveReplaceable()
	{
		RemoveField("Replaceable");
	}

	const bool CIM_PhysicalComponent::HotSwappable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HotSwappable"), ret);
		return ret;
	}
	void CIM_PhysicalComponent::HotSwappable(const bool value)
	{
		SetOrAddField("HotSwappable", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalComponent::HotSwappableExists() const
	{
		return ContainsField("HotSwappable");
	}
	void CIM_PhysicalComponent::RemoveHotSwappable()
	{
		RemoveField("HotSwappable");
	}

	CimBase *CIM_PhysicalComponent::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalComponent *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalComponent>(object);
		}
		else
		{
			ret = new CIM_PhysicalComponent(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalComponent> > CIM_PhysicalComponent::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalComponent>(client, keys);
	}

	void CIM_PhysicalComponent::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalComponent::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalComponent::CLASS_NAME = "CIM_PhysicalComponent";
	const string CIM_PhysicalComponent::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalComponent";
	const string CIM_PhysicalComponent::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalComponent";
	const string CIM_PhysicalComponent::CLASS_NS_PREFIX = "APh990";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalComponent::_classMetaData;
}
}
}
}
