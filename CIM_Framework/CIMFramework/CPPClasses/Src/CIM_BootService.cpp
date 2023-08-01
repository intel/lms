//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootService.cpp
//
//  Contents:   A class derived from Service that provides the controls to manage the boot configuration of a managed computer system or device. This includes changing the order of the boot devices and affecting settings on managed elements during the boot process. This service can also affect the load of a specific operating system on the computer system through a BootSourceSetting that points to a specific operating system image.
//
//              This file was automatically generated from CIM_BootService.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_BootService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BootService::_metadata[] = {
		{"EnabledState", false, false, false },
	};
	// class fields
	CimBase *CIM_BootService::CreateFromCimObject(const CimObject &object)
	{
		CIM_BootService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BootService>(object);
		}
		else
		{
			ret = new CIM_BootService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BootService> > CIM_BootService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BootService>(client, keys);
	}

	void CIM_BootService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BootService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_BootService::SetBootConfigRole_INPUT::_metadata[] = {
		{"BootConfigSetting", false, true },
		{"Role", false, true },
	};
	void CIM_BootService::SetBootConfigRole_INPUT::BootConfigSetting(const CimReference &value)
	{
		SetOrAddField("BootConfigSetting", TypeConverter::TypeToString(value));
	}
	void CIM_BootService::SetBootConfigRole_INPUT::Role(const unsigned short value)
	{
		SetOrAddField("Role", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_BootService::SetBootConfigRole_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_BootService::SetBootConfigRole_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_BootService::SetBootConfigRole_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_BootService::SetBootConfigRole(const SetBootConfigRole_INPUT &input, SetBootConfigRole_OUTPUT &output)
	{
		return Invoke("SetBootConfigRole", input, output);
	}
	const string CIM_BootService::CLASS_NAME = "CIM_BootService";
	const string CIM_BootService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootService";
	const string CIM_BootService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootService";
	const string CIM_BootService::CLASS_NS_PREFIX = "ABo235";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BootService::_classMetaData;
}
}
}
}
