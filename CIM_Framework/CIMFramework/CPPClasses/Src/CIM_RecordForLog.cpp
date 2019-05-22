//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RecordForLog.cpp
//
//  Contents:   The RecordForLog class is used to instantiate records to be aggregated to a Log.
//
//              This file was automatically generated from CIM_RecordForLog.mof,  version: 2.25.0
//
//----------------------------------------------------------------------------
#include "CIM_RecordForLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RecordForLog::_metadata[] = {
		{"RecordFormat", false, false, false },
		{"RecordData", false, false, false },
		{"Locale", false, false, false },
		{"PerceivedSeverity", false, false, false },
	};
	// class fields
	const string CIM_RecordForLog::RecordFormat() const
	{
		return GetField("RecordFormat")[0];
	}
	void CIM_RecordForLog::RecordFormat(const string &value)
	{
		SetOrAddField("RecordFormat", value);
	}
	bool CIM_RecordForLog::RecordFormatExists() const
	{
		return ContainsField("RecordFormat");
	}
	void CIM_RecordForLog::RemoveRecordFormat()
	{
		RemoveField("RecordFormat");
	}

	const string CIM_RecordForLog::RecordData() const
	{
		return GetField("RecordData")[0];
	}
	void CIM_RecordForLog::RecordData(const string &value)
	{
		SetOrAddField("RecordData", value);
	}
	bool CIM_RecordForLog::RecordDataExists() const
	{
		return ContainsField("RecordData");
	}
	void CIM_RecordForLog::RemoveRecordData()
	{
		RemoveField("RecordData");
	}

	const string CIM_RecordForLog::Locale() const
	{
		return GetField("Locale")[0];
	}
	void CIM_RecordForLog::Locale(const string &value)
	{
		SetOrAddField("Locale", value);
	}
	bool CIM_RecordForLog::LocaleExists() const
	{
		return ContainsField("Locale");
	}
	void CIM_RecordForLog::RemoveLocale()
	{
		RemoveField("Locale");
	}

	const unsigned short CIM_RecordForLog::PerceivedSeverity() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PerceivedSeverity"), ret);
		return ret;
	}
	void CIM_RecordForLog::PerceivedSeverity(const unsigned short value)
	{
		SetOrAddField("PerceivedSeverity", TypeConverter::TypeToString(value));
	}
	bool CIM_RecordForLog::PerceivedSeverityExists() const
	{
		return ContainsField("PerceivedSeverity");
	}
	void CIM_RecordForLog::RemovePerceivedSeverity()
	{
		RemoveField("PerceivedSeverity");
	}

	CimBase *CIM_RecordForLog::CreateFromCimObject(const CimObject &object)
	{
		CIM_RecordForLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RecordForLog>(object);
		}
		else
		{
			ret = new CIM_RecordForLog(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RecordForLog> > CIM_RecordForLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RecordForLog>(client, keys);
	}

	void CIM_RecordForLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RecordForLog::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RecordForLog::CLASS_NAME = "CIM_RecordForLog";
	const string CIM_RecordForLog::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RecordForLog";
	const string CIM_RecordForLog::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RecordForLog";
	const string CIM_RecordForLog::CLASS_NS_PREFIX = "ARe676";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RecordForLog::_classMetaData;
}
}
}
}
