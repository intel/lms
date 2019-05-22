//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootSourceSetting.cpp
//
//  Contents:   A class derived from SettingData that provides the information necessary to describe a boot source. This may be optionally associated to a bootable logical device, such as a hard disk partition, or a network device. The information from this class instance is used by the boot manager, such as BIOS/EFI or OS Loader to initiate the boot process, when this instance appears in a BootConfigSetting collection.
//
//              This file was automatically generated from CIM_BootSourceSetting.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_BootSourceSetting.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BootSourceSetting::_metadata[] = {
		{"BootString", false, false, false },
		{"BIOSBootString", false, false, false },
		{"StructuredBootString", false, false, false },
		{"FailThroughSupported", false, false, false },
	};
	// class fields
	const string CIM_BootSourceSetting::BootString() const
	{
		return GetField("BootString")[0];
	}
	void CIM_BootSourceSetting::BootString(const string &value)
	{
		SetOrAddField("BootString", value);
	}
	bool CIM_BootSourceSetting::BootStringExists() const
	{
		return ContainsField("BootString");
	}
	void CIM_BootSourceSetting::RemoveBootString()
	{
		RemoveField("BootString");
	}

	const string CIM_BootSourceSetting::BIOSBootString() const
	{
		return GetField("BIOSBootString")[0];
	}
	void CIM_BootSourceSetting::BIOSBootString(const string &value)
	{
		SetOrAddField("BIOSBootString", value);
	}
	bool CIM_BootSourceSetting::BIOSBootStringExists() const
	{
		return ContainsField("BIOSBootString");
	}
	void CIM_BootSourceSetting::RemoveBIOSBootString()
	{
		RemoveField("BIOSBootString");
	}

	const string CIM_BootSourceSetting::StructuredBootString() const
	{
		return GetField("StructuredBootString")[0];
	}
	void CIM_BootSourceSetting::StructuredBootString(const string &value)
	{
		SetOrAddField("StructuredBootString", value);
	}
	bool CIM_BootSourceSetting::StructuredBootStringExists() const
	{
		return ContainsField("StructuredBootString");
	}
	void CIM_BootSourceSetting::RemoveStructuredBootString()
	{
		RemoveField("StructuredBootString");
	}

	const unsigned short CIM_BootSourceSetting::FailThroughSupported() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FailThroughSupported"), ret);
		return ret;
	}
	void CIM_BootSourceSetting::FailThroughSupported(const unsigned short value)
	{
		SetOrAddField("FailThroughSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_BootSourceSetting::FailThroughSupportedExists() const
	{
		return ContainsField("FailThroughSupported");
	}
	void CIM_BootSourceSetting::RemoveFailThroughSupported()
	{
		RemoveField("FailThroughSupported");
	}

	CimBase *CIM_BootSourceSetting::CreateFromCimObject(const CimObject &object)
	{
		CIM_BootSourceSetting *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BootSourceSetting>(object);
		}
		else
		{
			ret = new CIM_BootSourceSetting(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BootSourceSetting> > CIM_BootSourceSetting::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BootSourceSetting>(client, keys);
	}

	void CIM_BootSourceSetting::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BootSourceSetting::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_BootSourceSetting::CLASS_NAME = "CIM_BootSourceSetting";
	const string CIM_BootSourceSetting::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootSourceSetting";
	const string CIM_BootSourceSetting::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootSourceSetting";
	const string CIM_BootSourceSetting::CLASS_NS_PREFIX = "ABo253";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BootSourceSetting::_classMetaData;
}
}
}
}
