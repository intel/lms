//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Log.cpp
//
//  Contents:   Log represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Log does not dictate the form of the data represented or how records/messages are stored in the log and/or accessed. Subclasses will define the appropriate methods and behavior.
//
//              This file was automatically generated from CIM_Log.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_Log.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Log::_metadata[] = {
		{"MaxNumberOfRecords", false, false, false },
		{"CurrentNumberOfRecords", false, false, false },
		{"OverwritePolicy", false, false, false },
		{"LogState", false, false, false },
	};
	// class fields
	const Uint64 CIM_Log::MaxNumberOfRecords() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxNumberOfRecords"), ret);
		return ret;
	}
	void CIM_Log::MaxNumberOfRecords(const Uint64 value)
	{
		SetOrAddField("MaxNumberOfRecords", TypeConverter::TypeToString(value));
	}
	bool CIM_Log::MaxNumberOfRecordsExists() const
	{
		return ContainsField("MaxNumberOfRecords");
	}
	void CIM_Log::RemoveMaxNumberOfRecords()
	{
		RemoveField("MaxNumberOfRecords");
	}

	const Uint64 CIM_Log::CurrentNumberOfRecords() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("CurrentNumberOfRecords"), ret);
		return ret;
	}
	void CIM_Log::CurrentNumberOfRecords(const Uint64 value)
	{
		SetOrAddField("CurrentNumberOfRecords", TypeConverter::TypeToString(value));
	}
	bool CIM_Log::CurrentNumberOfRecordsExists() const
	{
		return ContainsField("CurrentNumberOfRecords");
	}
	void CIM_Log::RemoveCurrentNumberOfRecords()
	{
		RemoveField("CurrentNumberOfRecords");
	}

	const unsigned short CIM_Log::OverwritePolicy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OverwritePolicy"), ret);
		return ret;
	}
	void CIM_Log::OverwritePolicy(const unsigned short value)
	{
		SetOrAddField("OverwritePolicy", TypeConverter::TypeToString(value));
	}
	bool CIM_Log::OverwritePolicyExists() const
	{
		return ContainsField("OverwritePolicy");
	}
	void CIM_Log::RemoveOverwritePolicy()
	{
		RemoveField("OverwritePolicy");
	}

	const unsigned short CIM_Log::LogState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LogState"), ret);
		return ret;
	}
	void CIM_Log::LogState(const unsigned short value)
	{
		SetOrAddField("LogState", TypeConverter::TypeToString(value));
	}
	bool CIM_Log::LogStateExists() const
	{
		return ContainsField("LogState");
	}
	void CIM_Log::RemoveLogState()
	{
		RemoveField("LogState");
	}

	CimBase *CIM_Log::CreateFromCimObject(const CimObject &object)
	{
		CIM_Log *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Log>(object);
		}
		else
		{
			ret = new CIM_Log(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Log> > CIM_Log::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Log>(client, keys);
	}

	void CIM_Log::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Log::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_Log::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_Log::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_Log::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Log::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_Log::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_Log::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_Log::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int CIM_Log::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const string CIM_Log::CLASS_NAME = "CIM_Log";
	const string CIM_Log::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Log";
	const string CIM_Log::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Log";
	const string CIM_Log::CLASS_NS_PREFIX = "ALo348";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Log::_classMetaData;
}
}
}
}
