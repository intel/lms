//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogManagesRecord.cpp
//
//  Contents:   LogManagesRecord describes the aggregation or location of Records managed by a Log.
//
//              This file was automatically generated from CIM_LogManagesRecord.mof,  version: 2.9.0
//
//----------------------------------------------------------------------------
#include "CIM_LogManagesRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LogManagesRecord::_metadata[] = {
		{"Log", true, false, true },
		{"Record", true, false, true },
	};
	// class fields
	const CimReference CIM_LogManagesRecord::Log() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Log"), ret);
		return ret;
	}
	void CIM_LogManagesRecord::Log(const CimReference &value)
	{
		SetOrAddField("Log", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_LogManagesRecord::Record() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Record"), ret);
		return ret;
	}
	void CIM_LogManagesRecord::Record(const CimReference &value)
	{
		SetOrAddField("Record", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_LogManagesRecord::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogManagesRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogManagesRecord>(object);
		}
		else
		{
			ret = new CIM_LogManagesRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogManagesRecord> > CIM_LogManagesRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogManagesRecord>(client, keys);
	}

	void CIM_LogManagesRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogManagesRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_LogManagesRecord::CLASS_NAME = "CIM_LogManagesRecord";
	const string CIM_LogManagesRecord::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogManagesRecord";
	const string CIM_LogManagesRecord::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogManagesRecord";
	const string CIM_LogManagesRecord::CLASS_NS_PREFIX = "ALo667";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogManagesRecord::_classMetaData;
}
}
}
}
