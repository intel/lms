//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SettingsDefineState.cpp
//
//  Contents:   SettingsDefineState is used to associate an instance of SettingData with an instance of ManagedElement. This association indicates that the SettingData instance provides additional information about the Current State of the associated ManagedElement. State is broadly defined to include the configuration, status, capabilities, and other information of an instance. 
//              Use of the same instance of SettingData to represent more than one of Current State (SettingsDefineState) and Desired State (ElementSettingData) and Possible State (SettingsDefineCapabilities) for a ManagedElement is not recommended.
//
//              This file was automatically generated from CIM_SettingsDefineState.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_SettingsDefineState.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SettingsDefineState::_metadata[] = {
		{"ManagedElement", true, false, true },
		{"SettingData", true, false, true },
	};
	// class fields
	const CimReference CIM_SettingsDefineState::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_SettingsDefineState::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_SettingsDefineState::SettingData() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("SettingData"), ret);
		return ret;
	}
	void CIM_SettingsDefineState::SettingData(const CimReference &value)
	{
		SetOrAddField("SettingData", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_SettingsDefineState::CreateFromCimObject(const CimObject &object)
	{
		CIM_SettingsDefineState *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SettingsDefineState>(object);
		}
		else
		{
			ret = new CIM_SettingsDefineState(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SettingsDefineState> > CIM_SettingsDefineState::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SettingsDefineState>(client, keys);
	}

	void CIM_SettingsDefineState::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SettingsDefineState::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SettingsDefineState::CLASS_NAME = "CIM_SettingsDefineState";
	const string CIM_SettingsDefineState::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SettingsDefineState";
	const string CIM_SettingsDefineState::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SettingsDefineState";
	const string CIM_SettingsDefineState::CLASS_NS_PREFIX = "ASe813";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SettingsDefineState::_classMetaData;
}
}
}
}
