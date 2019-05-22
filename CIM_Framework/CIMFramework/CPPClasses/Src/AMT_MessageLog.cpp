//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_MessageLog.cpp
//
//  Contents:   Extends MessageLog with multiple record fetching
//
//              This file was automatically generated from AMT_MessageLog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_MessageLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_MessageLog::CreateFromCimObject(const CimObject &object)
	{
		AMT_MessageLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_MessageLog>(object);
		}
		else
		{
			ret = new AMT_MessageLog(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_MessageLog> > AMT_MessageLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_MessageLog>(client, keys);
	}

	void AMT_MessageLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_MessageLog::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_MessageLog::CancelIteration_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
	};
	void AMT_MessageLog::CancelIteration_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	const VectorFieldData AMT_MessageLog::CancelIteration_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_MessageLog::CancelIteration(const CancelIteration_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("CancelIteration", input, output);
	}
	const CimFieldAttribute AMT_MessageLog::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_MessageLog::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_MessageLog::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_MessageLog::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_MessageLog::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_MessageLog::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_MessageLog::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int AMT_MessageLog::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const CimFieldAttribute AMT_MessageLog::GetRecords_INPUT::_metadata[] = {
		{"IterationIdentifier", false, true },
		{"MaxReadRecords", false, true },
	};
	void AMT_MessageLog::GetRecords_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void AMT_MessageLog::GetRecords_INPUT::MaxReadRecords(const unsigned int value)
	{
		SetOrAddField("MaxReadRecords", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_MessageLog::GetRecords_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string AMT_MessageLog::GetRecords_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	const bool AMT_MessageLog::GetRecords_OUTPUT::NoMoreRecords() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("NoMoreRecords"), ret);
		return ret;
	}
	bool AMT_MessageLog::GetRecords_OUTPUT::NoMoreRecordsExists() const
	{
		return ContainsField("NoMoreRecords");
	}
	const vector<string> AMT_MessageLog::GetRecords_OUTPUT::RecordArray() const
	{
		vector<string> ret;
		if(ContainsField("RecordArray"))
			TypeConverter::StringToType(GetField("RecordArray"), ret);
		return ret;
	}
	bool AMT_MessageLog::GetRecords_OUTPUT::RecordArrayExists() const
	{
		return ContainsField("RecordArray");
	}
	unsigned int AMT_MessageLog::GetRecords(const GetRecords_INPUT &input, GetRecords_OUTPUT &output)
	{
		return Invoke("GetRecords", input, output);
	}
	const CimFieldAttribute AMT_MessageLog::GetRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, true },
		{"PositionToNext", false, false },
	};
	void AMT_MessageLog::GetRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void AMT_MessageLog::GetRecord_INPUT::PositionToNext(const bool value)
	{
		SetOrAddField("PositionToNext", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_MessageLog::GetRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string AMT_MessageLog::GetRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	const Uint64 AMT_MessageLog::GetRecord_OUTPUT::RecordNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	const vector<unsigned char> AMT_MessageLog::GetRecord_OUTPUT::RecordData() const
	{
		vector<unsigned char> ret;
		if(ContainsField("RecordData"))
			TypeConverter::StringToType(GetField("RecordData"), ret);
		return ret;
	}
	bool AMT_MessageLog::GetRecord_OUTPUT::RecordDataExists() const
	{
		return ContainsField("RecordData");
	}
	unsigned int AMT_MessageLog::GetRecord(const GetRecord_INPUT &input, GetRecord_OUTPUT &output)
	{
		return Invoke("GetRecord", input, output);
	}
	const CimFieldAttribute AMT_MessageLog::PositionAtRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, true },
		{"MoveAbsolute", false, true },
		{"RecordNumber", false, true },
	};
	void AMT_MessageLog::PositionAtRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void AMT_MessageLog::PositionAtRecord_INPUT::MoveAbsolute(const bool value)
	{
		SetOrAddField("MoveAbsolute", TypeConverter::TypeToString(value));
	}
	void AMT_MessageLog::PositionAtRecord_INPUT::RecordNumber(const Int64 value)
	{
		SetOrAddField("RecordNumber", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_MessageLog::PositionAtRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const string AMT_MessageLog::PositionAtRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	const Int64 AMT_MessageLog::PositionAtRecord_OUTPUT::RecordNumber() const
	{
		Int64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	unsigned int AMT_MessageLog::PositionAtRecord(const PositionAtRecord_INPUT &input, PositionAtRecord_OUTPUT &output)
	{
		return Invoke("PositionAtRecord", input, output);
	}
	const string AMT_MessageLog::PositionToFirstRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool AMT_MessageLog::PositionToFirstRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	unsigned int AMT_MessageLog::PositionToFirstRecord(PositionToFirstRecord_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("PositionToFirstRecord", input, output);
	}
	const CimFieldAttribute AMT_MessageLog::FreezeLog_INPUT::_metadata[] = {
		{"Freeze", false, true },
	};
	void AMT_MessageLog::FreezeLog_INPUT::Freeze(const bool value)
	{
		SetOrAddField("Freeze", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_MessageLog::FreezeLog_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_MessageLog::FreezeLog(const FreezeLog_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("FreezeLog", input, output);
	}
	const string AMT_MessageLog::CLASS_NAME = "AMT_MessageLog";
	const string AMT_MessageLog::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_MessageLog";
	const string AMT_MessageLog::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_MessageLog";
	const string AMT_MessageLog::CLASS_NS_PREFIX = "AMe500";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_MessageLog::_classMetaData;
}
}
}
}
