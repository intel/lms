//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuditLog.cpp
//
//  Contents:   Represents an Audit Log
//
//              This file was automatically generated from AMT_AuditLog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AuditLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AuditLog::_metadata[] = {
		{"PercentageFree", false, true, false },
		{"Name", true, false, false },
		{"TimeOfLastRecord", false, false, false },
		{"AuditState", false, true, false },
		{"MaxAllowedAuditors", false, true, false },
		{"StoragePolicy", false, false, false },
		{"MinDaysToKeep", false, false, false },
	};
	// class fields
	const unsigned int AMT_AuditLog::PercentageFree() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PercentageFree"), ret);
		return ret;
	}
	void AMT_AuditLog::PercentageFree(const unsigned int value)
	{
		SetOrAddField("PercentageFree", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::PercentageFreeExists() const
	{
		return ContainsField("PercentageFree");
	}
	void AMT_AuditLog::RemovePercentageFree()
	{
		RemoveField("PercentageFree");
	}

	const CimDateTime AMT_AuditLog::TimeOfLastRecord() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastRecord"), ret);
		return ret;
	}
	void AMT_AuditLog::TimeOfLastRecord(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastRecord", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::TimeOfLastRecordExists() const
	{
		return ContainsField("TimeOfLastRecord");
	}
	void AMT_AuditLog::RemoveTimeOfLastRecord()
	{
		RemoveField("TimeOfLastRecord");
	}

	const unsigned int AMT_AuditLog::AuditState() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AuditState"), ret);
		return ret;
	}
	void AMT_AuditLog::AuditState(const unsigned int value)
	{
		SetOrAddField("AuditState", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::AuditStateExists() const
	{
		return ContainsField("AuditState");
	}
	void AMT_AuditLog::RemoveAuditState()
	{
		RemoveField("AuditState");
	}

	const unsigned short AMT_AuditLog::MaxAllowedAuditors() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxAllowedAuditors"), ret);
		return ret;
	}
	void AMT_AuditLog::MaxAllowedAuditors(const unsigned short value)
	{
		SetOrAddField("MaxAllowedAuditors", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::MaxAllowedAuditorsExists() const
	{
		return ContainsField("MaxAllowedAuditors");
	}
	void AMT_AuditLog::RemoveMaxAllowedAuditors()
	{
		RemoveField("MaxAllowedAuditors");
	}

	const unsigned char AMT_AuditLog::StoragePolicy() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("StoragePolicy"), ret);
		return ret;
	}
	void AMT_AuditLog::StoragePolicy(const unsigned char &value)
	{
		SetOrAddField("StoragePolicy", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::StoragePolicyExists() const
	{
		return ContainsField("StoragePolicy");
	}
	void AMT_AuditLog::RemoveStoragePolicy()
	{
		RemoveField("StoragePolicy");
	}

	const unsigned char AMT_AuditLog::MinDaysToKeep() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("MinDaysToKeep"), ret);
		return ret;
	}
	void AMT_AuditLog::MinDaysToKeep(const unsigned char &value)
	{
		SetOrAddField("MinDaysToKeep", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditLog::MinDaysToKeepExists() const
	{
		return ContainsField("MinDaysToKeep");
	}
	void AMT_AuditLog::RemoveMinDaysToKeep()
	{
		RemoveField("MinDaysToKeep");
	}

	CimBase *AMT_AuditLog::CreateFromCimObject(const CimObject &object)
	{
		AMT_AuditLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AuditLog>(object);
		}
		else
		{
			ret = new AMT_AuditLog(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AuditLog> > AMT_AuditLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AuditLog>(client, keys);
	}

	void AMT_AuditLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AuditLog::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int AMT_AuditLog::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const CimFieldAttribute AMT_AuditLog::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_AuditLog::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditLog::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_AuditLog::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_AuditLog::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_AuditLog::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute AMT_AuditLog::ReadRecords_INPUT::_metadata[] = {
		{"StartIndex", false, true },
	};
	void AMT_AuditLog::ReadRecords_INPUT::StartIndex(const unsigned int value)
	{
		SetOrAddField("StartIndex", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditLog::ReadRecords_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_AuditLog::ReadRecords_OUTPUT::TotalRecordCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalRecordCount"), ret);
		return ret;
	}
	bool AMT_AuditLog::ReadRecords_OUTPUT::TotalRecordCountExists() const
	{
		return ContainsField("TotalRecordCount");
	}
	const unsigned int AMT_AuditLog::ReadRecords_OUTPUT::RecordsReturned() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RecordsReturned"), ret);
		return ret;
	}
	bool AMT_AuditLog::ReadRecords_OUTPUT::RecordsReturnedExists() const
	{
		return ContainsField("RecordsReturned");
	}
	const vector<string> AMT_AuditLog::ReadRecords_OUTPUT::EventRecords() const
	{
		vector<string> ret;
		if(ContainsField("EventRecords"))
			TypeConverter::StringToType(GetField("EventRecords"), ret);
		return ret;
	}
	bool AMT_AuditLog::ReadRecords_OUTPUT::EventRecordsExists() const
	{
		return ContainsField("EventRecords");
	}
	unsigned int AMT_AuditLog::ReadRecords(const ReadRecords_INPUT &input, ReadRecords_OUTPUT &output)
	{
		return Invoke("ReadRecords", input, output);
	}
	const CimFieldAttribute AMT_AuditLog::SetAuditLock_INPUT::_metadata[] = {
		{"LockTimeoutInSeconds", false, false },
		{"Flag", false, true },
		{"Handle", false, false },
	};
	void AMT_AuditLog::SetAuditLock_INPUT::LockTimeoutInSeconds(const unsigned int value)
	{
		SetOrAddField("LockTimeoutInSeconds", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::SetAuditLock_INPUT::Flag(const unsigned int value)
	{
		SetOrAddField("Flag", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::SetAuditLock_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditLog::SetAuditLock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const unsigned int AMT_AuditLog::SetAuditLock_OUTPUT::Handle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Handle"), ret);
		return ret;
	}
	bool AMT_AuditLog::SetAuditLock_OUTPUT::HandleExists() const
	{
		return ContainsField("Handle");
	}
	unsigned int AMT_AuditLog::SetAuditLock(const SetAuditLock_INPUT &input, SetAuditLock_OUTPUT &output)
	{
		return Invoke("SetAuditLock", input, output);
	}
	const CimFieldAttribute AMT_AuditLog::ExportAuditLogSignature_INPUT::_metadata[] = {
		{"SigningMechanism", false, true },
	};
	void AMT_AuditLog::ExportAuditLogSignature_INPUT::SigningMechanism(const unsigned int value)
	{
		SetOrAddField("SigningMechanism", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditLog::ExportAuditLogSignature_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_AuditLog::ExportAuditLogSignature_OUTPUT::TotalRecordCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalRecordCount"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::TotalRecordCountExists() const
	{
		return ContainsField("TotalRecordCount");
	}
	const CimDateTime AMT_AuditLog::ExportAuditLogSignature_OUTPUT::StartLogTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("StartLogTime"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::StartLogTimeExists() const
	{
		return ContainsField("StartLogTime");
	}
	const CimDateTime AMT_AuditLog::ExportAuditLogSignature_OUTPUT::EndLogTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("EndLogTime"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::EndLogTimeExists() const
	{
		return ContainsField("EndLogTime");
	}
	const CimDateTime AMT_AuditLog::ExportAuditLogSignature_OUTPUT::GenerationTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("GenerationTime"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::GenerationTimeExists() const
	{
		return ContainsField("GenerationTime");
	}
	const HexBinary AMT_AuditLog::ExportAuditLogSignature_OUTPUT::UUID() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("UUID"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::UUIDExists() const
	{
		return ContainsField("UUID");
	}
	const string AMT_AuditLog::ExportAuditLogSignature_OUTPUT::FQDN() const
	{
		return GetField("FQDN")[0];
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::FQDNExists() const
	{
		return ContainsField("FQDN");
	}
	const unsigned int AMT_AuditLog::ExportAuditLogSignature_OUTPUT::SignatureMechanism() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("SignatureMechanism"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::SignatureMechanismExists() const
	{
		return ContainsField("SignatureMechanism");
	}
	const Base64 AMT_AuditLog::ExportAuditLogSignature_OUTPUT::Signature() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("Signature"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::SignatureExists() const
	{
		return ContainsField("Signature");
	}
	const vector<unsigned short> AMT_AuditLog::ExportAuditLogSignature_OUTPUT::LengthOfCertificates() const
	{
		vector<unsigned short> ret;
		if(ContainsField("LengthOfCertificates"))
			TypeConverter::StringToType(GetField("LengthOfCertificates"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::LengthOfCertificatesExists() const
	{
		return ContainsField("LengthOfCertificates");
	}
	const Base64 AMT_AuditLog::ExportAuditLogSignature_OUTPUT::Certificates() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("Certificates"), ret);
		return ret;
	}
	bool AMT_AuditLog::ExportAuditLogSignature_OUTPUT::CertificatesExists() const
	{
		return ContainsField("Certificates");
	}
	unsigned int AMT_AuditLog::ExportAuditLogSignature(const ExportAuditLogSignature_INPUT &input, ExportAuditLogSignature_OUTPUT &output)
	{
		return Invoke("ExportAuditLogSignature", input, output);
	}
	const CimFieldAttribute AMT_AuditLog::SetSigningKeyMaterial_INPUT::_metadata[] = {
		{"SigningMechanismType", false, true },
		{"SigningKey", false, true },
		{"LengthOfCertificates", false, true },
		{"Certificates", false, true },
	};
	void AMT_AuditLog::SetSigningKeyMaterial_INPUT::SigningMechanismType(const unsigned int value)
	{
		SetOrAddField("SigningMechanismType", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::SetSigningKeyMaterial_INPUT::SigningKey(const Base64 &value)
	{
		SetOrAddField("SigningKey", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::SetSigningKeyMaterial_INPUT::LengthOfCertificates(const vector<unsigned short> &value)
	{
		SetOrAddField("LengthOfCertificates", TypeConverter::TypeToString(value));
	}
	void AMT_AuditLog::SetSigningKeyMaterial_INPUT::Certificates(const Base64 &value)
	{
		SetOrAddField("Certificates", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditLog::SetSigningKeyMaterial_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_AuditLog::SetSigningKeyMaterial(const SetSigningKeyMaterial_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetSigningKeyMaterial", input, output);
	}
	const string AMT_AuditLog::CLASS_NAME = "AMT_AuditLog";
	const string AMT_AuditLog::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuditLog";
	const string AMT_AuditLog::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuditLog";
	const string AMT_AuditLog::CLASS_NS_PREFIX = "AAu88";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AuditLog::_classMetaData;
}
}
}
}
