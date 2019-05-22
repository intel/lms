//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AuthorizationService.cpp
//
//  Contents:   CIM_AuthorizationService determines whether an Identity, established by an AuthorizationService, is permitted access to a resource or set of resources.
//
//              This file was automatically generated from CIM_AuthorizationService.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_AuthorizationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_AuthorizationService::CreateFromCimObject(const CimObject &object)
	{
		CIM_AuthorizationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AuthorizationService>(object);
		}
		else
		{
			ret = new CIM_AuthorizationService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AuthorizationService> > CIM_AuthorizationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AuthorizationService>(client, keys);
	}

	void CIM_AuthorizationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AuthorizationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_AuthorizationService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_AuthorizationService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_AuthorizationService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_AuthorizationService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_AuthorizationService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_AuthorizationService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_AuthorizationService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int CIM_AuthorizationService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	unsigned int CIM_AuthorizationService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	const string CIM_AuthorizationService::CLASS_NAME = "CIM_AuthorizationService";
	const string CIM_AuthorizationService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthorizationService";
	const string CIM_AuthorizationService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AuthorizationService";
	const string CIM_AuthorizationService::CLASS_NS_PREFIX = "AAu308";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AuthorizationService::_classMetaData;
}
}
}
}
