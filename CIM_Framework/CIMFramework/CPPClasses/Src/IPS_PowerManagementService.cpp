//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_PowerManagementService.cpp
//
//  Contents:   The IPS_PowerManagementService inherits CIM_PowerManagementService and adds capability to control OS power state
//
//              This file was automatically generated from IPS_PowerManagementService.mof,  version: 10.0
//
//----------------------------------------------------------------------------
#include "IPS_PowerManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_PowerManagementService::_metadata[] = {
		{"OSPowerSavingState", false, false, false },
	};
	// class fields
	const unsigned short IPS_PowerManagementService::OSPowerSavingState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OSPowerSavingState"), ret);
		return ret;
	}
	void IPS_PowerManagementService::OSPowerSavingState(const unsigned short value)
	{
		SetOrAddField("OSPowerSavingState", TypeConverter::TypeToString(value));
	}
	bool IPS_PowerManagementService::OSPowerSavingStateExists() const
	{
		return ContainsField("OSPowerSavingState");
	}
	void IPS_PowerManagementService::RemoveOSPowerSavingState()
	{
		RemoveField("OSPowerSavingState");
	}

	CimBase *IPS_PowerManagementService::CreateFromCimObject(const CimObject &object)
	{
		IPS_PowerManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_PowerManagementService>(object);
		}
		else
		{
			ret = new IPS_PowerManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_PowerManagementService> > IPS_PowerManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_PowerManagementService>(client, keys);
	}

	void IPS_PowerManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_PowerManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::_metadata[] = {
		{"OSPowerSavingState", false, false },
		{"ManagedElement", false, false },
		{"Time", false, false },
		{"TimeoutPeriod", false, false },
	};
	void IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::OSPowerSavingState(const unsigned short value)
	{
		SetOrAddField("OSPowerSavingState", TypeConverter::TypeToString(value));
	}
	void IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}
	void IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	void IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_PowerManagementService::RequestOSPowerSavingStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const CimReference IPS_PowerManagementService::RequestOSPowerSavingStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool IPS_PowerManagementService::RequestOSPowerSavingStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int IPS_PowerManagementService::RequestOSPowerSavingStateChange(const RequestOSPowerSavingStateChange_INPUT &input, RequestOSPowerSavingStateChange_OUTPUT &output)
	{
		return Invoke("RequestOSPowerSavingStateChange", input, output);
	}
	const string IPS_PowerManagementService::CLASS_NAME = "IPS_PowerManagementService";
	const string IPS_PowerManagementService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_PowerManagementService";
	const string IPS_PowerManagementService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_PowerManagementService";
	const string IPS_PowerManagementService::CLASS_NS_PREFIX = "APo48";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_PowerManagementService::_classMetaData;
}
}
}
}
