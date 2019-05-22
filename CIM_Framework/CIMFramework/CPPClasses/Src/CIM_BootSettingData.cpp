//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootSettingData.cpp
//
//  Contents:   BootSettingData is a set of settings that apply to system boot. An example of usage of this class is to hold several BIOS, NVRAM, firmware or system settings, typically seen in the BIOS setup screens. These settings would need to be modified by the system as part of the boot process. Since, it is often not possible to intercept the boot process to apply these settings, users can set these a priori in the instance associated with the selected BootSourceSetting, thereby instructing the system to apply them during the next system reboot.
//
//              This file was automatically generated from CIM_BootSettingData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_BootSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BootSettingData::_metadata[] = {
		{"OwningEntity", false, false, false },
	};
	// class fields
	const string CIM_BootSettingData::OwningEntity() const
	{
		return GetField("OwningEntity")[0];
	}
	void CIM_BootSettingData::OwningEntity(const string &value)
	{
		SetOrAddField("OwningEntity", value);
	}
	bool CIM_BootSettingData::OwningEntityExists() const
	{
		return ContainsField("OwningEntity");
	}
	void CIM_BootSettingData::RemoveOwningEntity()
	{
		RemoveField("OwningEntity");
	}

	CimBase *CIM_BootSettingData::CreateFromCimObject(const CimObject &object)
	{
		CIM_BootSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BootSettingData>(object);
		}
		else
		{
			ret = new CIM_BootSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BootSettingData> > CIM_BootSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BootSettingData>(client, keys);
	}

	void CIM_BootSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BootSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_BootSettingData::CLASS_NAME = "CIM_BootSettingData";
	const string CIM_BootSettingData::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootSettingData";
	const string CIM_BootSettingData::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootSettingData";
	const string CIM_BootSettingData::CLASS_NS_PREFIX = "ABo80";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BootSettingData::_classMetaData;
}
}
}
}
