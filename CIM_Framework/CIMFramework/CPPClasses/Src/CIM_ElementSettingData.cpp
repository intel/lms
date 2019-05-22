//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementSettingData.cpp
//
//  Contents:   ElementSettingData represents the association between ManagedElements and applicable setting data. This association also describes whether this is a default or current setting.
//
//              This file was automatically generated from CIM_ElementSettingData.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#include "CIM_ElementSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementSettingData::_metadata[] = {
		{"ManagedElement", true, false, true },
		{"SettingData", true, false, true },
		{"IsDefault", false, false, false },
		{"IsCurrent", false, false, false },
		{"IsNext", false, false, false },
	};
	// class fields
	const CimReference CIM_ElementSettingData::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_ElementSettingData::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ElementSettingData::SettingData() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("SettingData"), ret);
		return ret;
	}
	void CIM_ElementSettingData::SettingData(const CimReference &value)
	{
		SetOrAddField("SettingData", TypeConverter::TypeToString(value));
	}

	const unsigned short CIM_ElementSettingData::IsDefault() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IsDefault"), ret);
		return ret;
	}
	void CIM_ElementSettingData::IsDefault(const unsigned short value)
	{
		SetOrAddField("IsDefault", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementSettingData::IsDefaultExists() const
	{
		return ContainsField("IsDefault");
	}
	void CIM_ElementSettingData::RemoveIsDefault()
	{
		RemoveField("IsDefault");
	}

	const unsigned short CIM_ElementSettingData::IsCurrent() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IsCurrent"), ret);
		return ret;
	}
	void CIM_ElementSettingData::IsCurrent(const unsigned short value)
	{
		SetOrAddField("IsCurrent", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementSettingData::IsCurrentExists() const
	{
		return ContainsField("IsCurrent");
	}
	void CIM_ElementSettingData::RemoveIsCurrent()
	{
		RemoveField("IsCurrent");
	}

	const unsigned short CIM_ElementSettingData::IsNext() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("IsNext"), ret);
		return ret;
	}
	void CIM_ElementSettingData::IsNext(const unsigned short value)
	{
		SetOrAddField("IsNext", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementSettingData::IsNextExists() const
	{
		return ContainsField("IsNext");
	}
	void CIM_ElementSettingData::RemoveIsNext()
	{
		RemoveField("IsNext");
	}

	CimBase *CIM_ElementSettingData::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementSettingData>(object);
		}
		else
		{
			ret = new CIM_ElementSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementSettingData> > CIM_ElementSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementSettingData>(client, keys);
	}

	void CIM_ElementSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementSettingData::CLASS_NAME = "CIM_ElementSettingData";
	const string CIM_ElementSettingData::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementSettingData";
	const string CIM_ElementSettingData::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementSettingData";
	const string CIM_ElementSettingData::CLASS_NS_PREFIX = "AEl94";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementSettingData::_classMetaData;
}
}
}
}
