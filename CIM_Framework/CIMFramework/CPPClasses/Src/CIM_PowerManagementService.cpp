//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerManagementService.cpp
//
//  Contents:   A class derived from Service that describes power management functionality, hosted on a System. Whether this service might be used to affect the power state of a particular element is defined by the CIM_ServiceAvailable ToElement association.
//
//              This file was automatically generated from CIM_PowerManagementService.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#include "CIM_PowerManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_PowerManagementService::CreateFromCimObject(const CimObject &object)
	{
		CIM_PowerManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PowerManagementService>(object);
		}
		else
		{
			ret = new CIM_PowerManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PowerManagementService> > CIM_PowerManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PowerManagementService>(client, keys);
	}

	void CIM_PowerManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PowerManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_PowerManagementService::RequestPowerStateChange_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"ManagedElement", false, false },
		{"Time", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_PowerManagementService::RequestPowerStateChange_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_PowerManagementService::RequestPowerStateChange_INPUT::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}
	void CIM_PowerManagementService::RequestPowerStateChange_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	void CIM_PowerManagementService::RequestPowerStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PowerManagementService::RequestPowerStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const CimReference CIM_PowerManagementService::RequestPowerStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_PowerManagementService::RequestPowerStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_PowerManagementService::RequestPowerStateChange(const RequestPowerStateChange_INPUT &input, RequestPowerStateChange_OUTPUT &output)
	{
		return Invoke("RequestPowerStateChange", input, output);
	}
	const string CIM_PowerManagementService::CLASS_NAME = "CIM_PowerManagementService";
	const string CIM_PowerManagementService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerManagementService";
	const string CIM_PowerManagementService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerManagementService";
	const string CIM_PowerManagementService::CLASS_NS_PREFIX = "APo59";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PowerManagementService::_classMetaData;
}
}
}
}
