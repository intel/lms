//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AuthenticationService.cpp
//
//  Contents:   CIM_AuthenticationService verifies users' identities through some means. These services are decomposed into a subclass that provides credentials to users and a subclass that provides for the verification of the validity of a credential and, perhaps, the appropriateness of its use for access to target resources. The persistent state information used from one such verification to another is maintained in an instance of Identity class.
//
//              This file was automatically generated from CIM_AuthenticationService.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_AuthenticationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_AuthenticationService::CreateFromCimObject(const CimObject &object)
	{
		CIM_AuthenticationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AuthenticationService>(object);
		}
		else
		{
			ret = new CIM_AuthenticationService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AuthenticationService> > CIM_AuthenticationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AuthenticationService>(client, keys);
	}

	void CIM_AuthenticationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AuthenticationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_AuthenticationService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_AuthenticationService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_AuthenticationService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_AuthenticationService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_AuthenticationService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_AuthenticationService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_AuthenticationService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int CIM_AuthenticationService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	unsigned int CIM_AuthenticationService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	const string CIM_AuthenticationService::CLASS_NAME = "CIM_AuthenticationService";
	const string CIM_AuthenticationService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthenticationService";
	const string CIM_AuthenticationService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthenticationService";
	const string CIM_AuthenticationService::CLASS_NS_PREFIX = "AAu845";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AuthenticationService::_classMetaData;
}
}
}
}
