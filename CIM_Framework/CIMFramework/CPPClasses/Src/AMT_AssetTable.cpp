//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AssetTable.cpp
//
//  Contents:   Represents an Asset Table
//
//              This file was automatically generated from AMT_AssetTable.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AssetTable.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AssetTable::_metadata[] = {
		{"TableType", true, false, false },
		{"InstanceID", true, false, false },
		{"TableTypeInfo", false, false, false },
		{"TableData", false, true, false },
	};
	// class fields
	const unsigned int AMT_AssetTable::TableType() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TableType"), ret);
		return ret;
	}
	void AMT_AssetTable::TableType(const unsigned int value)
	{
		SetOrAddField("TableType", TypeConverter::TypeToString(value));
	}

	const string AMT_AssetTable::TableTypeInfo() const
	{
		return GetField("TableTypeInfo")[0];
	}
	void AMT_AssetTable::TableTypeInfo(const string &value)
	{
		SetOrAddField("TableTypeInfo", value);
	}
	bool AMT_AssetTable::TableTypeInfoExists() const
	{
		return ContainsField("TableTypeInfo");
	}
	void AMT_AssetTable::RemoveTableTypeInfo()
	{
		RemoveField("TableTypeInfo");
	}

	const Base64 AMT_AssetTable::TableData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("TableData"), ret);
		return ret;
	}
	void AMT_AssetTable::TableData(const Base64 &value)
	{
		SetOrAddField("TableData", TypeConverter::TypeToString(value));
	}
	bool AMT_AssetTable::TableDataExists() const
	{
		return ContainsField("TableData");
	}
	void AMT_AssetTable::RemoveTableData()
	{
		RemoveField("TableData");
	}

	CimBase *AMT_AssetTable::CreateFromCimObject(const CimObject &object)
	{
		AMT_AssetTable *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AssetTable>(object);
		}
		else
		{
			ret = new AMT_AssetTable(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AssetTable> > AMT_AssetTable::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AssetTable>(client, keys);
	}

	void AMT_AssetTable::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AssetTable::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_AssetTable::CLASS_NAME = "AMT_AssetTable";
	const string AMT_AssetTable::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AssetTable";
	const string AMT_AssetTable::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AssetTable";
	const string AMT_AssetTable::CLASS_NS_PREFIX = "AAs235";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AssetTable::_classMetaData;
}
}
}
}
