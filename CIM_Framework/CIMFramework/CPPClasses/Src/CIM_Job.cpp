//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Job.cpp
//
//  Contents:   A Job is a LogicalElement that represents an executing unit of work, such as a script or a print job. A Job is distinct from a Process in that a Job can be scheduled or queued, and its execution is not limited to a single system.
//
//              This file was automatically generated from CIM_Job.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_Job.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Job::_metadata[] = {
		{"JobStatus", false, false, false },
		{"TimeSubmitted", false, false, false },
		{"ScheduledStartTime", false, false, false },
		{"StartTime", false, false, false },
		{"ElapsedTime", false, false, false },
		{"JobRunTimes", false, false, false },
		{"RunMonth", false, false, false },
		{"RunDay", false, false, false },
		{"RunDayOfWeek", false, false, false },
		{"RunStartInterval", false, false, false },
		{"LocalOrUtcTime", false, false, false },
		{"UntilTime", false, false, false },
		{"Notify", false, false, false },
		{"Owner", false, false, false },
		{"Priority", false, false, false },
		{"PercentComplete", false, false, false },
		{"DeleteOnCompletion", false, false, false },
		{"ErrorCode", false, false, false },
		{"ErrorDescription", false, false, false },
		{"RecoveryAction", false, false, false },
		{"OtherRecoveryAction", false, false, false },
	};
	// class fields
	const string CIM_Job::JobStatus() const
	{
		return GetField("JobStatus")[0];
	}
	void CIM_Job::JobStatus(const string &value)
	{
		SetOrAddField("JobStatus", value);
	}
	bool CIM_Job::JobStatusExists() const
	{
		return ContainsField("JobStatus");
	}
	void CIM_Job::RemoveJobStatus()
	{
		RemoveField("JobStatus");
	}

	const CimDateTime CIM_Job::TimeSubmitted() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeSubmitted"), ret);
		return ret;
	}
	void CIM_Job::TimeSubmitted(const CimDateTime &value)
	{
		SetOrAddField("TimeSubmitted", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::TimeSubmittedExists() const
	{
		return ContainsField("TimeSubmitted");
	}
	void CIM_Job::RemoveTimeSubmitted()
	{
		RemoveField("TimeSubmitted");
	}

	const CimDateTime CIM_Job::ScheduledStartTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ScheduledStartTime"), ret);
		return ret;
	}
	void CIM_Job::ScheduledStartTime(const CimDateTime &value)
	{
		SetOrAddField("ScheduledStartTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::ScheduledStartTimeExists() const
	{
		return ContainsField("ScheduledStartTime");
	}
	void CIM_Job::RemoveScheduledStartTime()
	{
		RemoveField("ScheduledStartTime");
	}

	const CimDateTime CIM_Job::StartTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("StartTime"), ret);
		return ret;
	}
	void CIM_Job::StartTime(const CimDateTime &value)
	{
		SetOrAddField("StartTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::StartTimeExists() const
	{
		return ContainsField("StartTime");
	}
	void CIM_Job::RemoveStartTime()
	{
		RemoveField("StartTime");
	}

	const CimDateTime CIM_Job::ElapsedTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ElapsedTime"), ret);
		return ret;
	}
	void CIM_Job::ElapsedTime(const CimDateTime &value)
	{
		SetOrAddField("ElapsedTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::ElapsedTimeExists() const
	{
		return ContainsField("ElapsedTime");
	}
	void CIM_Job::RemoveElapsedTime()
	{
		RemoveField("ElapsedTime");
	}

	const unsigned int CIM_Job::JobRunTimes() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("JobRunTimes"), ret);
		return ret;
	}
	void CIM_Job::JobRunTimes(const unsigned int value)
	{
		SetOrAddField("JobRunTimes", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::JobRunTimesExists() const
	{
		return ContainsField("JobRunTimes");
	}
	void CIM_Job::RemoveJobRunTimes()
	{
		RemoveField("JobRunTimes");
	}

	const unsigned char CIM_Job::RunMonth() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("RunMonth"), ret);
		return ret;
	}
	void CIM_Job::RunMonth(const unsigned char &value)
	{
		SetOrAddField("RunMonth", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::RunMonthExists() const
	{
		return ContainsField("RunMonth");
	}
	void CIM_Job::RemoveRunMonth()
	{
		RemoveField("RunMonth");
	}

	const char CIM_Job::RunDay() const
	{
		char ret = 0;
		TypeConverter::StringToType(GetField("RunDay"), ret);
		return ret;
	}
	void CIM_Job::RunDay(const char &value)
	{
		SetOrAddField("RunDay", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::RunDayExists() const
	{
		return ContainsField("RunDay");
	}
	void CIM_Job::RemoveRunDay()
	{
		RemoveField("RunDay");
	}

	const char CIM_Job::RunDayOfWeek() const
	{
		char ret = 0;
		TypeConverter::StringToType(GetField("RunDayOfWeek"), ret);
		return ret;
	}
	void CIM_Job::RunDayOfWeek(const char &value)
	{
		SetOrAddField("RunDayOfWeek", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::RunDayOfWeekExists() const
	{
		return ContainsField("RunDayOfWeek");
	}
	void CIM_Job::RemoveRunDayOfWeek()
	{
		RemoveField("RunDayOfWeek");
	}

	const CimDateTime CIM_Job::RunStartInterval() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("RunStartInterval"), ret);
		return ret;
	}
	void CIM_Job::RunStartInterval(const CimDateTime &value)
	{
		SetOrAddField("RunStartInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::RunStartIntervalExists() const
	{
		return ContainsField("RunStartInterval");
	}
	void CIM_Job::RemoveRunStartInterval()
	{
		RemoveField("RunStartInterval");
	}

	const unsigned short CIM_Job::LocalOrUtcTime() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LocalOrUtcTime"), ret);
		return ret;
	}
	void CIM_Job::LocalOrUtcTime(const unsigned short value)
	{
		SetOrAddField("LocalOrUtcTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::LocalOrUtcTimeExists() const
	{
		return ContainsField("LocalOrUtcTime");
	}
	void CIM_Job::RemoveLocalOrUtcTime()
	{
		RemoveField("LocalOrUtcTime");
	}

	const CimDateTime CIM_Job::UntilTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("UntilTime"), ret);
		return ret;
	}
	void CIM_Job::UntilTime(const CimDateTime &value)
	{
		SetOrAddField("UntilTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::UntilTimeExists() const
	{
		return ContainsField("UntilTime");
	}
	void CIM_Job::RemoveUntilTime()
	{
		RemoveField("UntilTime");
	}

	const string CIM_Job::Notify() const
	{
		return GetField("Notify")[0];
	}
	void CIM_Job::Notify(const string &value)
	{
		SetOrAddField("Notify", value);
	}
	bool CIM_Job::NotifyExists() const
	{
		return ContainsField("Notify");
	}
	void CIM_Job::RemoveNotify()
	{
		RemoveField("Notify");
	}

	const string CIM_Job::Owner() const
	{
		return GetField("Owner")[0];
	}
	void CIM_Job::Owner(const string &value)
	{
		SetOrAddField("Owner", value);
	}
	bool CIM_Job::OwnerExists() const
	{
		return ContainsField("Owner");
	}
	void CIM_Job::RemoveOwner()
	{
		RemoveField("Owner");
	}

	const unsigned int CIM_Job::Priority() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Priority"), ret);
		return ret;
	}
	void CIM_Job::Priority(const unsigned int value)
	{
		SetOrAddField("Priority", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::PriorityExists() const
	{
		return ContainsField("Priority");
	}
	void CIM_Job::RemovePriority()
	{
		RemoveField("Priority");
	}

	const unsigned short CIM_Job::PercentComplete() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PercentComplete"), ret);
		return ret;
	}
	void CIM_Job::PercentComplete(const unsigned short value)
	{
		SetOrAddField("PercentComplete", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::PercentCompleteExists() const
	{
		return ContainsField("PercentComplete");
	}
	void CIM_Job::RemovePercentComplete()
	{
		RemoveField("PercentComplete");
	}

	const bool CIM_Job::DeleteOnCompletion() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DeleteOnCompletion"), ret);
		return ret;
	}
	void CIM_Job::DeleteOnCompletion(const bool value)
	{
		SetOrAddField("DeleteOnCompletion", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::DeleteOnCompletionExists() const
	{
		return ContainsField("DeleteOnCompletion");
	}
	void CIM_Job::RemoveDeleteOnCompletion()
	{
		RemoveField("DeleteOnCompletion");
	}

	const unsigned short CIM_Job::ErrorCode() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorCode"), ret);
		return ret;
	}
	void CIM_Job::ErrorCode(const unsigned short value)
	{
		SetOrAddField("ErrorCode", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::ErrorCodeExists() const
	{
		return ContainsField("ErrorCode");
	}
	void CIM_Job::RemoveErrorCode()
	{
		RemoveField("ErrorCode");
	}

	const string CIM_Job::ErrorDescription() const
	{
		return GetField("ErrorDescription")[0];
	}
	void CIM_Job::ErrorDescription(const string &value)
	{
		SetOrAddField("ErrorDescription", value);
	}
	bool CIM_Job::ErrorDescriptionExists() const
	{
		return ContainsField("ErrorDescription");
	}
	void CIM_Job::RemoveErrorDescription()
	{
		RemoveField("ErrorDescription");
	}

	const unsigned short CIM_Job::RecoveryAction() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RecoveryAction"), ret);
		return ret;
	}
	void CIM_Job::RecoveryAction(const unsigned short value)
	{
		SetOrAddField("RecoveryAction", TypeConverter::TypeToString(value));
	}
	bool CIM_Job::RecoveryActionExists() const
	{
		return ContainsField("RecoveryAction");
	}
	void CIM_Job::RemoveRecoveryAction()
	{
		RemoveField("RecoveryAction");
	}

	const string CIM_Job::OtherRecoveryAction() const
	{
		return GetField("OtherRecoveryAction")[0];
	}
	void CIM_Job::OtherRecoveryAction(const string &value)
	{
		SetOrAddField("OtherRecoveryAction", value);
	}
	bool CIM_Job::OtherRecoveryActionExists() const
	{
		return ContainsField("OtherRecoveryAction");
	}
	void CIM_Job::RemoveOtherRecoveryAction()
	{
		RemoveField("OtherRecoveryAction");
	}

	CimBase *CIM_Job::CreateFromCimObject(const CimObject &object)
	{
		CIM_Job *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Job>(object);
		}
		else
		{
			ret = new CIM_Job(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Job> > CIM_Job::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Job>(client, keys);
	}

	void CIM_Job::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Job::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_Job::KillJob_INPUT::_metadata[] = {
		{"DeleteOnKill", false, false },
	};
	void CIM_Job::KillJob_INPUT::DeleteOnKill(const bool value)
	{
		SetOrAddField("DeleteOnKill", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Job::KillJob_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_Job::KillJob(const KillJob_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("KillJob", input, output);
	}
	const string CIM_Job::CLASS_NAME = "CIM_Job";
	const string CIM_Job::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Job";
	const string CIM_Job::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Job";
	const string CIM_Job::CLASS_NS_PREFIX = "AJo421";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Job::_classMetaData;
}
}
}
}
