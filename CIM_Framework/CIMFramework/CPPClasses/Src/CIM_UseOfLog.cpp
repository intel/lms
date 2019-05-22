//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_UseOfLog.cpp
//
//  Contents:   ManagedSystemElements may record their event, error or informational data within Logs. The use of a Log to hold a ManagedSystemElement's data is described by this association. The type of Element data captured by the Log can be specified using the RecordedData string property.
//
//              This file was automatically generated from CIM_UseOfLog.mof,  version: 2.9.0
//
//----------------------------------------------------------------------------
#include "CIM_UseOfLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_UseOfLog::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"RecordedData", false, false, false },
	};
	// class fields
	const string CIM_UseOfLog::RecordedData() const
	{
		return GetField("RecordedData")[0];
	}
	void CIM_UseOfLog::RecordedData(const string &value)
	{
		SetOrAddField("RecordedData", value);
	}
	bool CIM_UseOfLog::RecordedDataExists() const
	{
		return ContainsField("RecordedData");
	}
	void CIM_UseOfLog::RemoveRecordedData()
	{
		RemoveField("RecordedData");
	}

	CimBase *CIM_UseOfLog::CreateFromCimObject(const CimObject &object)
	{
		CIM_UseOfLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_UseOfLog>(object);
		}
		else
		{
			ret = new CIM_UseOfLog(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_UseOfLog> > CIM_UseOfLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_UseOfLog>(client, keys);
	}

	void CIM_UseOfLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_UseOfLog::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_UseOfLog::CLASS_NAME = "CIM_UseOfLog";
	const string CIM_UseOfLog::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_UseOfLog";
	const string CIM_UseOfLog::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_UseOfLog";
	const string CIM_UseOfLog::CLASS_NS_PREFIX = "AUs594";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_UseOfLog::_classMetaData;
}
}
}
}
