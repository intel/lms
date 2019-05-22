//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootConfigSetting.cpp
//
//  Contents:   A class derived from SettingData that provides the container to arrange all the BootSourceSetting instances in an ordered sequence. There can be one or more of the BootConfigSetting instances associated to a ComputerSystem. For example, one such BootConfigSetting could be a default boot configuration supplied by the manufacturer, a second one could be a configuration recommended by the IT Administrator. A third one could be the one actually to be used on next system boot.
//
//              This file was automatically generated from CIM_BootConfigSetting.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_BootConfigSetting.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_BootConfigSetting::CreateFromCimObject(const CimObject &object)
	{
		CIM_BootConfigSetting *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BootConfigSetting>(object);
		}
		else
		{
			ret = new CIM_BootConfigSetting(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BootConfigSetting> > CIM_BootConfigSetting::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BootConfigSetting>(client, keys);
	}

	void CIM_BootConfigSetting::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BootConfigSetting::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_BootConfigSetting::ChangeBootOrder_INPUT::_metadata[] = {
		{"Source", false, false },
	};
	void CIM_BootConfigSetting::ChangeBootOrder_INPUT::Source(const vector<CimReference> &value)
	{
		SetOrAddField("Source", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_BootConfigSetting::ChangeBootOrder_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const CimReference CIM_BootConfigSetting::ChangeBootOrder_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_BootConfigSetting::ChangeBootOrder_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_BootConfigSetting::ChangeBootOrder(const ChangeBootOrder_INPUT &input, ChangeBootOrder_OUTPUT &output)
	{
		return Invoke("ChangeBootOrder", input, output);
	}
	const string CIM_BootConfigSetting::CLASS_NAME = "CIM_BootConfigSetting";
	const string CIM_BootConfigSetting::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootConfigSetting";
	const string CIM_BootConfigSetting::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BootConfigSetting";
	const string CIM_BootConfigSetting::CLASS_NS_PREFIX = "ABo564";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BootConfigSetting::_classMetaData;
}
}
}
}
