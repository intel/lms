//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RecordLog.cpp
//
//  Contents:   RecordLog serves as an aggregation point for LogRecord objects. This class presents a higher level view of a log than its peer class MessageLog (which uses iterators) and introduces a new key structure. Access to records in this log is achieved through the use of the standard CIM Operations defined as part of WBEM.
//
//              This file was automatically generated from CIM_RecordLog.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_RecordLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RecordLog::_metadata[] = {
		{"InstanceID", true, false, false },
	};
	// class fields
	CimBase *CIM_RecordLog::CreateFromCimObject(const CimObject &object)
	{
		CIM_RecordLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RecordLog>(object);
		}
		else
		{
			ret = new CIM_RecordLog(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RecordLog> > CIM_RecordLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RecordLog>(client, keys);
	}

	void CIM_RecordLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RecordLog::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_RecordLog::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const CimFieldAttribute CIM_RecordLog::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_RecordLog::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_RecordLog::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_RecordLog::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_RecordLog::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_RecordLog::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_RecordLog::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_RecordLog::CLASS_NAME = "CIM_RecordLog";
	const string CIM_RecordLog::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RecordLog";
	const string CIM_RecordLog::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RecordLog";
	const string CIM_RecordLog::CLASS_NS_PREFIX = "ARe221";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RecordLog::_classMetaData;
}
}
}
}
