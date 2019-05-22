//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MessageLog.cpp
//
//  Contents:   MessageLog represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Several methods are defined for retrieving, writing and deleting log entries, and maintaining the log. This type of log uses iterators to access the log records, whereas its peer class, RecordLog, uses more abstracted access mechanisms.
//
//              This file was automatically generated from CIM_MessageLog.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#include "CIM_MessageLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_MessageLog::_metadata[] = {
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"Capabilities", false, false, false },
		{"CapabilitiesDescriptions", false, false, false },
		{"MaxLogSize", false, false, false },
		{"SizeOfHeader", false, false, false },
		{"HeaderFormat", false, false, false },
		{"MaxRecordSize", false, false, false },
		{"SizeOfRecordHeader", false, false, false },
		{"RecordHeaderFormat", false, false, false },
		{"OverwritePolicy", false, false, false },
		{"OtherPolicyDescription", false, false, false },
		{"TimeWhenOutdated", false, false, false },
		{"PercentageNearFull", false, false, false },
		{"LastChange", false, false, false },
		{"TimeOfLastChange", false, false, false },
		{"RecordLastChanged", false, false, false },
		{"IsFrozen", false, false, false },
		{"CharacterSet", false, false, false },
	};
	// class fields
	const string CIM_MessageLog::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_MessageLog::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const vector<unsigned short> CIM_MessageLog::Capabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Capabilities"), ret);
		return ret;
	}
	void CIM_MessageLog::Capabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("Capabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::CapabilitiesExists() const
	{
		return ContainsField("Capabilities");
	}
	void CIM_MessageLog::RemoveCapabilities()
	{
		RemoveField("Capabilities");
	}

	const vector<string> CIM_MessageLog::CapabilitiesDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CapabilitiesDescriptions"), ret);
		return ret;
	}
	void CIM_MessageLog::CapabilitiesDescriptions(const vector<string> &value)
	{
		SetOrAddField("CapabilitiesDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::CapabilitiesDescriptionsExists() const
	{
		return ContainsField("CapabilitiesDescriptions");
	}
	void CIM_MessageLog::RemoveCapabilitiesDescriptions()
	{
		RemoveField("CapabilitiesDescriptions");
	}

	const Uint64 CIM_MessageLog::MaxLogSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxLogSize"), ret);
		return ret;
	}
	void CIM_MessageLog::MaxLogSize(const Uint64 value)
	{
		SetOrAddField("MaxLogSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::MaxLogSizeExists() const
	{
		return ContainsField("MaxLogSize");
	}
	void CIM_MessageLog::RemoveMaxLogSize()
	{
		RemoveField("MaxLogSize");
	}

	const Uint64 CIM_MessageLog::SizeOfHeader() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("SizeOfHeader"), ret);
		return ret;
	}
	void CIM_MessageLog::SizeOfHeader(const Uint64 value)
	{
		SetOrAddField("SizeOfHeader", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::SizeOfHeaderExists() const
	{
		return ContainsField("SizeOfHeader");
	}
	void CIM_MessageLog::RemoveSizeOfHeader()
	{
		RemoveField("SizeOfHeader");
	}

	const string CIM_MessageLog::HeaderFormat() const
	{
		return GetField("HeaderFormat")[0];
	}
	void CIM_MessageLog::HeaderFormat(const string &value)
	{
		SetOrAddField("HeaderFormat", value);
	}
	bool CIM_MessageLog::HeaderFormatExists() const
	{
		return ContainsField("HeaderFormat");
	}
	void CIM_MessageLog::RemoveHeaderFormat()
	{
		RemoveField("HeaderFormat");
	}

	const Uint64 CIM_MessageLog::MaxRecordSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxRecordSize"), ret);
		return ret;
	}
	void CIM_MessageLog::MaxRecordSize(const Uint64 value)
	{
		SetOrAddField("MaxRecordSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::MaxRecordSizeExists() const
	{
		return ContainsField("MaxRecordSize");
	}
	void CIM_MessageLog::RemoveMaxRecordSize()
	{
		RemoveField("MaxRecordSize");
	}

	const Uint64 CIM_MessageLog::SizeOfRecordHeader() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("SizeOfRecordHeader"), ret);
		return ret;
	}
	void CIM_MessageLog::SizeOfRecordHeader(const Uint64 value)
	{
		SetOrAddField("SizeOfRecordHeader", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::SizeOfRecordHeaderExists() const
	{
		return ContainsField("SizeOfRecordHeader");
	}
	void CIM_MessageLog::RemoveSizeOfRecordHeader()
	{
		RemoveField("SizeOfRecordHeader");
	}

	const string CIM_MessageLog::RecordHeaderFormat() const
	{
		return GetField("RecordHeaderFormat")[0];
	}
	void CIM_MessageLog::RecordHeaderFormat(const string &value)
	{
		SetOrAddField("RecordHeaderFormat", value);
	}
	bool CIM_MessageLog::RecordHeaderFormatExists() const
	{
		return ContainsField("RecordHeaderFormat");
	}
	void CIM_MessageLog::RemoveRecordHeaderFormat()
	{
		RemoveField("RecordHeaderFormat");
	}

	const string CIM_MessageLog::OtherPolicyDescription() const
	{
		return GetField("OtherPolicyDescription")[0];
	}
	void CIM_MessageLog::OtherPolicyDescription(const string &value)
	{
		SetOrAddField("OtherPolicyDescription", value);
	}
	bool CIM_MessageLog::OtherPolicyDescriptionExists() const
	{
		return ContainsField("OtherPolicyDescription");
	}
	void CIM_MessageLog::RemoveOtherPolicyDescription()
	{
		RemoveField("OtherPolicyDescription");
	}

	const CimDateTime CIM_MessageLog::TimeWhenOutdated() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeWhenOutdated"), ret);
		return ret;
	}
	void CIM_MessageLog::TimeWhenOutdated(const CimDateTime &value)
	{
		SetOrAddField("TimeWhenOutdated", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::TimeWhenOutdatedExists() const
	{
		return ContainsField("TimeWhenOutdated");
	}
	void CIM_MessageLog::RemoveTimeWhenOutdated()
	{
		RemoveField("TimeWhenOutdated");
	}

	const unsigned char CIM_MessageLog::PercentageNearFull() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("PercentageNearFull"), ret);
		return ret;
	}
	void CIM_MessageLog::PercentageNearFull(const unsigned char &value)
	{
		SetOrAddField("PercentageNearFull", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::PercentageNearFullExists() const
	{
		return ContainsField("PercentageNearFull");
	}
	void CIM_MessageLog::RemovePercentageNearFull()
	{
		RemoveField("PercentageNearFull");
	}

	const unsigned short CIM_MessageLog::LastChange() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LastChange"), ret);
		return ret;
	}
	void CIM_MessageLog::LastChange(const unsigned short value)
	{
		SetOrAddField("LastChange", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::LastChangeExists() const
	{
		return ContainsField("LastChange");
	}
	void CIM_MessageLog::RemoveLastChange()
	{
		RemoveField("LastChange");
	}

	const CimDateTime CIM_MessageLog::TimeOfLastChange() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastChange"), ret);
		return ret;
	}
	void CIM_MessageLog::TimeOfLastChange(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastChange", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::TimeOfLastChangeExists() const
	{
		return ContainsField("TimeOfLastChange");
	}
	void CIM_MessageLog::RemoveTimeOfLastChange()
	{
		RemoveField("TimeOfLastChange");
	}

	const Uint64 CIM_MessageLog::RecordLastChanged() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordLastChanged"), ret);
		return ret;
	}
	void CIM_MessageLog::RecordLastChanged(const Uint64 value)
	{
		SetOrAddField("RecordLastChanged", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::RecordLastChangedExists() const
	{
		return ContainsField("RecordLastChanged");
	}
	void CIM_MessageLog::RemoveRecordLastChanged()
	{
		RemoveField("RecordLastChanged");
	}

	const bool CIM_MessageLog::IsFrozen() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsFrozen"), ret);
		return ret;
	}
	void CIM_MessageLog::IsFrozen(const bool value)
	{
		SetOrAddField("IsFrozen", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::IsFrozenExists() const
	{
		return ContainsField("IsFrozen");
	}
	void CIM_MessageLog::RemoveIsFrozen()
	{
		RemoveField("IsFrozen");
	}

	const unsigned short CIM_MessageLog::CharacterSet() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CharacterSet"), ret);
		return ret;
	}
	void CIM_MessageLog::CharacterSet(const unsigned short value)
	{
		SetOrAddField("CharacterSet", TypeConverter::TypeToString(value));
	}
	bool CIM_MessageLog::CharacterSetExists() const
	{
		return ContainsField("CharacterSet");
	}
	void CIM_MessageLog::RemoveCharacterSet()
	{
		RemoveField("CharacterSet");
	}

	CimBase *CIM_MessageLog::CreateFromCimObject(const CimObject &object)
	{
		CIM_MessageLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_MessageLog>(object);
		}
		else
		{
			ret = new CIM_MessageLog(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_MessageLog> > CIM_MessageLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_MessageLog>(client, keys);
	}

	void CIM_MessageLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_MessageLog::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_MessageLog::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_MessageLog::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_MessageLog::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_MessageLog::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_MessageLog::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_MessageLog::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_MessageLog::PositionToFirstRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::PositionToFirstRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	unsigned int CIM_MessageLog::PositionToFirstRecord(PositionToFirstRecord_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("PositionToFirstRecord", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::PositionAtRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
		{"MoveAbsolute", false, false },
		{"RecordNumber", false, false },
	};
	void CIM_MessageLog::PositionAtRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void CIM_MessageLog::PositionAtRecord_INPUT::MoveAbsolute(const bool value)
	{
		SetOrAddField("MoveAbsolute", TypeConverter::TypeToString(value));
	}
	void CIM_MessageLog::PositionAtRecord_INPUT::RecordNumber(const Int64 value)
	{
		SetOrAddField("RecordNumber", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::PositionAtRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const string CIM_MessageLog::PositionAtRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::PositionAtRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	const Int64 CIM_MessageLog::PositionAtRecord_OUTPUT::RecordNumber() const
	{
		Int64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	bool CIM_MessageLog::PositionAtRecord_OUTPUT::RecordNumberExists() const
	{
		return ContainsField("RecordNumber");
	}
	unsigned int CIM_MessageLog::PositionAtRecord(const PositionAtRecord_INPUT &input, PositionAtRecord_OUTPUT &output)
	{
		return Invoke("PositionAtRecord", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::GetRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
		{"PositionToNext", false, false },
	};
	void CIM_MessageLog::GetRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void CIM_MessageLog::GetRecord_INPUT::PositionToNext(const bool value)
	{
		SetOrAddField("PositionToNext", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::GetRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string CIM_MessageLog::GetRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::GetRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	const Uint64 CIM_MessageLog::GetRecord_OUTPUT::RecordNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	bool CIM_MessageLog::GetRecord_OUTPUT::RecordNumberExists() const
	{
		return ContainsField("RecordNumber");
	}
	const vector<unsigned char> CIM_MessageLog::GetRecord_OUTPUT::RecordData() const
	{
		vector<unsigned char> ret;
		if(ContainsField("RecordData"))
			TypeConverter::StringToType(GetField("RecordData"), ret);
		return ret;
	}
	bool CIM_MessageLog::GetRecord_OUTPUT::RecordDataExists() const
	{
		return ContainsField("RecordData");
	}
	unsigned int CIM_MessageLog::GetRecord(const GetRecord_INPUT &input, GetRecord_OUTPUT &output)
	{
		return Invoke("GetRecord", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::DeleteRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
		{"PositionToNext", false, false },
	};
	void CIM_MessageLog::DeleteRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void CIM_MessageLog::DeleteRecord_INPUT::PositionToNext(const bool value)
	{
		SetOrAddField("PositionToNext", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::DeleteRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string CIM_MessageLog::DeleteRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::DeleteRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	const Uint64 CIM_MessageLog::DeleteRecord_OUTPUT::RecordNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	bool CIM_MessageLog::DeleteRecord_OUTPUT::RecordNumberExists() const
	{
		return ContainsField("RecordNumber");
	}
	const vector<unsigned char> CIM_MessageLog::DeleteRecord_OUTPUT::RecordData() const
	{
		vector<unsigned char> ret;
		if(ContainsField("RecordData"))
			TypeConverter::StringToType(GetField("RecordData"), ret);
		return ret;
	}
	bool CIM_MessageLog::DeleteRecord_OUTPUT::RecordDataExists() const
	{
		return ContainsField("RecordData");
	}
	unsigned int CIM_MessageLog::DeleteRecord(const DeleteRecord_INPUT &input, DeleteRecord_OUTPUT &output)
	{
		return Invoke("DeleteRecord", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::WriteRecord_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
		{"PositionToNext", false, false },
		{"RecordData", false, false },
	};
	void CIM_MessageLog::WriteRecord_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void CIM_MessageLog::WriteRecord_INPUT::PositionToNext(const bool value)
	{
		SetOrAddField("PositionToNext", TypeConverter::TypeToString(value));
	}
	void CIM_MessageLog::WriteRecord_INPUT::RecordData(const vector<unsigned char> &value)
	{
		SetOrAddField("RecordData", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::WriteRecord_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const string CIM_MessageLog::WriteRecord_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::WriteRecord_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	const Uint64 CIM_MessageLog::WriteRecord_OUTPUT::RecordNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	bool CIM_MessageLog::WriteRecord_OUTPUT::RecordNumberExists() const
	{
		return ContainsField("RecordNumber");
	}
	unsigned int CIM_MessageLog::WriteRecord(const WriteRecord_INPUT &input, WriteRecord_OUTPUT &output)
	{
		return Invoke("WriteRecord", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::CancelIteration_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
	};
	void CIM_MessageLog::CancelIteration_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	const VectorFieldData CIM_MessageLog::CancelIteration_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_MessageLog::CancelIteration(const CancelIteration_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("CancelIteration", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::FreezeLog_INPUT::_metadata[] = {
		{"Freeze", false, false },
	};
	void CIM_MessageLog::FreezeLog_INPUT::Freeze(const bool value)
	{
		SetOrAddField("Freeze", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::FreezeLog_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_MessageLog::FreezeLog(const FreezeLog_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("FreezeLog", input, output);
	}
	const CimFieldAttribute CIM_MessageLog::FlagRecordForOverwrite_INPUT::_metadata[] = {
		{"IterationIdentifier", false, false },
		{"PositionToNext", false, false },
	};
	void CIM_MessageLog::FlagRecordForOverwrite_INPUT::IterationIdentifier(const string &value)
	{
		SetOrAddField("IterationIdentifier", value);
	}
	void CIM_MessageLog::FlagRecordForOverwrite_INPUT::PositionToNext(const bool value)
	{
		SetOrAddField("PositionToNext", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_MessageLog::FlagRecordForOverwrite_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string CIM_MessageLog::FlagRecordForOverwrite_OUTPUT::IterationIdentifier() const
	{
		return GetField("IterationIdentifier")[0];
	}
	bool CIM_MessageLog::FlagRecordForOverwrite_OUTPUT::IterationIdentifierExists() const
	{
		return ContainsField("IterationIdentifier");
	}
	const Uint64 CIM_MessageLog::FlagRecordForOverwrite_OUTPUT::RecordNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RecordNumber"), ret);
		return ret;
	}
	bool CIM_MessageLog::FlagRecordForOverwrite_OUTPUT::RecordNumberExists() const
	{
		return ContainsField("RecordNumber");
	}
	unsigned int CIM_MessageLog::FlagRecordForOverwrite(const FlagRecordForOverwrite_INPUT &input, FlagRecordForOverwrite_OUTPUT &output)
	{
		return Invoke("FlagRecordForOverwrite", input, output);
	}
	const string CIM_MessageLog::CLASS_NAME = "CIM_MessageLog";
	const string CIM_MessageLog::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MessageLog";
	const string CIM_MessageLog::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MessageLog";
	const string CIM_MessageLog::CLASS_NS_PREFIX = "AMe755";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_MessageLog::_classMetaData;
}
}
}
}
