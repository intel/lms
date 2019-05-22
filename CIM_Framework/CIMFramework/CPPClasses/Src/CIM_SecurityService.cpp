//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SecurityService.cpp
//
//  Contents:   A service providing security functionaity.
//
//              This file was automatically generated from CIM_SecurityService.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_SecurityService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_SecurityService::CreateFromCimObject(const CimObject &object)
	{
		CIM_SecurityService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SecurityService>(object);
		}
		else
		{
			ret = new CIM_SecurityService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SecurityService> > CIM_SecurityService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SecurityService>(client, keys);
	}

	void CIM_SecurityService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SecurityService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_SecurityService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	unsigned int CIM_SecurityService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	const CimFieldAttribute CIM_SecurityService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_SecurityService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_SecurityService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_SecurityService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_SecurityService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_SecurityService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_SecurityService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_SecurityService::CLASS_NAME = "CIM_SecurityService";
	const string CIM_SecurityService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SecurityService";
	const string CIM_SecurityService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SecurityService";
	const string CIM_SecurityService::CLASS_NS_PREFIX = "ASe885";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SecurityService::_classMetaData;
}
}
}
}
