//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PrivilegeManagementService.cpp
//
//  Contents:   The PrivilegeManagementService is responsible for creating, deleting, and associating AuthorizedPrivilege instances. References to 'subject' and 'target' define the entities that are associated with an AuthorizedPrivilege instance via the relationships, AuthorizedSubject and AuthorizedTarget, respectively. When created, an AuthorizedPrivilege instance is related to this (PrivilegeManagement)Service via the association, ConcreteDependency.
//
//              This file was automatically generated from CIM_PrivilegeManagementService.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_PrivilegeManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_PrivilegeManagementService::CreateFromCimObject(const CimObject &object)
	{
		CIM_PrivilegeManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PrivilegeManagementService>(object);
		}
		else
		{
			ret = new CIM_PrivilegeManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PrivilegeManagementService> > CIM_PrivilegeManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PrivilegeManagementService>(client, keys);
	}

	void CIM_PrivilegeManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PrivilegeManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_PrivilegeManagementService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	unsigned int CIM_PrivilegeManagementService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	const CimFieldAttribute CIM_PrivilegeManagementService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_PrivilegeManagementService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PrivilegeManagementService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_PrivilegeManagementService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_PrivilegeManagementService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_PrivilegeManagementService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute CIM_PrivilegeManagementService::AssignAccess_INPUT::_metadata[] = {
		{"Subject", false, true },
		{"PrivilegeGranted", false, false },
		{"Activities", false, false },
		{"ActivityQualifiers", false, false },
		{"QualifierFormats", false, false },
		{"Target", false, true },
		{"Privilege", false, false },
	};
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::Subject(const CimReference &value)
	{
		SetOrAddField("Subject", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::PrivilegeGranted(const bool value)
	{
		SetOrAddField("PrivilegeGranted", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::Activities(const vector<unsigned short> &value)
	{
		SetOrAddField("Activities", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::ActivityQualifiers(const vector<string> &value)
	{
		SetOrAddField("ActivityQualifiers", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::QualifierFormats(const vector<unsigned short> &value)
	{
		SetOrAddField("QualifierFormats", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::Target(const CimReference &value)
	{
		SetOrAddField("Target", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::AssignAccess_INPUT::Privilege(const CimReference &value)
	{
		SetOrAddField("Privilege", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PrivilegeManagementService::AssignAccess_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 7);
		return ret;
	}
	const CimReference CIM_PrivilegeManagementService::AssignAccess_OUTPUT::Privilege() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Privilege"), ret);
		return ret;
	}
	bool CIM_PrivilegeManagementService::AssignAccess_OUTPUT::PrivilegeExists() const
	{
		return ContainsField("Privilege");
	}
	unsigned int CIM_PrivilegeManagementService::AssignAccess(const AssignAccess_INPUT &input, AssignAccess_OUTPUT &output)
	{
		return Invoke("AssignAccess", input, output);
	}
	const CimFieldAttribute CIM_PrivilegeManagementService::RemoveAccess_INPUT::_metadata[] = {
		{"Subject", false, false },
		{"Privilege", false, false },
		{"Target", false, false },
	};
	void CIM_PrivilegeManagementService::RemoveAccess_INPUT::Subject(const CimReference &value)
	{
		SetOrAddField("Subject", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::RemoveAccess_INPUT::Privilege(const CimReference &value)
	{
		SetOrAddField("Privilege", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::RemoveAccess_INPUT::Target(const CimReference &value)
	{
		SetOrAddField("Target", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PrivilegeManagementService::RemoveAccess_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int CIM_PrivilegeManagementService::RemoveAccess(const RemoveAccess_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemoveAccess", input, output);
	}
	const CimFieldAttribute CIM_PrivilegeManagementService::ShowAccess_INPUT::_metadata[] = {
		{"Subject", false, false },
		{"Target", false, false },
	};
	void CIM_PrivilegeManagementService::ShowAccess_INPUT::Subject(const CimReference &value)
	{
		SetOrAddField("Subject", TypeConverter::TypeToString(value));
	}
	void CIM_PrivilegeManagementService::ShowAccess_INPUT::Target(const CimReference &value)
	{
		SetOrAddField("Target", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PrivilegeManagementService::ShowAccess_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const vector<CimReference> CIM_PrivilegeManagementService::ShowAccess_OUTPUT::OutSubjects() const
	{
		vector<CimReference> ret;
		if(ContainsField("OutSubjects"))
			TypeConverter::StringToType(GetField("OutSubjects"), ret);
		return ret;
	}
	bool CIM_PrivilegeManagementService::ShowAccess_OUTPUT::OutSubjectsExists() const
	{
		return ContainsField("OutSubjects");
	}
	const vector<CimReference> CIM_PrivilegeManagementService::ShowAccess_OUTPUT::OutTargets() const
	{
		vector<CimReference> ret;
		if(ContainsField("OutTargets"))
			TypeConverter::StringToType(GetField("OutTargets"), ret);
		return ret;
	}
	bool CIM_PrivilegeManagementService::ShowAccess_OUTPUT::OutTargetsExists() const
	{
		return ContainsField("OutTargets");
	}
	const vector<string> CIM_PrivilegeManagementService::ShowAccess_OUTPUT::Privileges() const
	{
		vector<string> ret;
		if(ContainsField("Privileges"))
			TypeConverter::StringToType(GetField("Privileges"), ret);
		return ret;
	}
	bool CIM_PrivilegeManagementService::ShowAccess_OUTPUT::PrivilegesExists() const
	{
		return ContainsField("Privileges");
	}
	unsigned int CIM_PrivilegeManagementService::ShowAccess(const ShowAccess_INPUT &input, ShowAccess_OUTPUT &output)
	{
		return Invoke("ShowAccess", input, output);
	}
	const string CIM_PrivilegeManagementService::CLASS_NAME = "CIM_PrivilegeManagementService";
	const string CIM_PrivilegeManagementService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PrivilegeManagementService";
	const string CIM_PrivilegeManagementService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PrivilegeManagementService";
	const string CIM_PrivilegeManagementService::CLASS_NS_PREFIX = "APr249";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PrivilegeManagementService::_classMetaData;
}
}
}
}
