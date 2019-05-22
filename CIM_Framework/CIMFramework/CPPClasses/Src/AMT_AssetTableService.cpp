//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AssetTableService.cpp
//
//  Contents:   Represents the Asset Table Service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_AssetTableService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AssetTableService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AssetTableService::_metadata[] = {
		{"TableTypes", false, true, false },
	};
	// class fields
	const vector<string> AMT_AssetTableService::TableTypes() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("TableTypes"), ret);
		return ret;
	}
	void AMT_AssetTableService::TableTypes(const vector<string> &value)
	{
		SetOrAddField("TableTypes", TypeConverter::TypeToString(value));
	}
	bool AMT_AssetTableService::TableTypesExists() const
	{
		return ContainsField("TableTypes");
	}
	void AMT_AssetTableService::RemoveTableTypes()
	{
		RemoveField("TableTypes");
	}

	CimBase *AMT_AssetTableService::CreateFromCimObject(const CimObject &object)
	{
		AMT_AssetTableService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AssetTableService>(object);
		}
		else
		{
			ret = new AMT_AssetTableService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AssetTableService> > AMT_AssetTableService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AssetTableService>(client, keys);
	}

	void AMT_AssetTableService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AssetTableService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_AssetTableService::RequestMediaDeviceTableUpdate_INPUT::_metadata[] = {
		{"FullUpdate", false, true },
		{"Sticky", false, true },
	};
	void AMT_AssetTableService::RequestMediaDeviceTableUpdate_INPUT::FullUpdate(const bool value)
	{
		SetOrAddField("FullUpdate", TypeConverter::TypeToString(value));
	}
	void AMT_AssetTableService::RequestMediaDeviceTableUpdate_INPUT::Sticky(const bool value)
	{
		SetOrAddField("Sticky", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AssetTableService::RequestMediaDeviceTableUpdate_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_AssetTableService::RequestMediaDeviceTableUpdate(const RequestMediaDeviceTableUpdate_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RequestMediaDeviceTableUpdate", input, output);
	}
	const string AMT_AssetTableService::CLASS_NAME = "AMT_AssetTableService";
	const string AMT_AssetTableService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AssetTableService";
	const string AMT_AssetTableService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AssetTableService";
	const string AMT_AssetTableService::CLASS_NS_PREFIX = "AAs112";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AssetTableService::_classMetaData;
}
}
}
}
