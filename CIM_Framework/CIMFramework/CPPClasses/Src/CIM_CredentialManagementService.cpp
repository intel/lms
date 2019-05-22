//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_CredentialManagementService.cpp
//
//  Contents:   CIM_CredentialManagementService issues credentials and manages the credential lifecycle.
//
//              This file was automatically generated from CIM_CredentialManagementService.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_CredentialManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_CredentialManagementService::CreateFromCimObject(const CimObject &object)
	{
		CIM_CredentialManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_CredentialManagementService>(object);
		}
		else
		{
			ret = new CIM_CredentialManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_CredentialManagementService> > CIM_CredentialManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_CredentialManagementService>(client, keys);
	}

	void CIM_CredentialManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_CredentialManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_CredentialManagementService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	unsigned int CIM_CredentialManagementService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	const CimFieldAttribute CIM_CredentialManagementService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_CredentialManagementService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_CredentialManagementService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CredentialManagementService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_CredentialManagementService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_CredentialManagementService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_CredentialManagementService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_CredentialManagementService::CLASS_NAME = "CIM_CredentialManagementService";
	const string CIM_CredentialManagementService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CredentialManagementService";
	const string CIM_CredentialManagementService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CredentialManagementService";
	const string CIM_CredentialManagementService::CLASS_NS_PREFIX = "ACr917";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_CredentialManagementService::_classMetaData;
}
}
}
}
