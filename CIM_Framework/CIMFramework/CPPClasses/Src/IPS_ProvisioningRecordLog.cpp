//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ProvisioningRecordLog.cpp
//
//  Contents:   IPS_ProvisioningRecordLog serves as an aggregation point for IPS_ProvisioningAuditRecord objects.
//
//              This file was automatically generated from IPS_ProvisioningRecordLog.mof,  version: 6.1.0
//
//----------------------------------------------------------------------------
#include "IPS_ProvisioningRecordLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *IPS_ProvisioningRecordLog::CreateFromCimObject(const CimObject &object)
	{
		IPS_ProvisioningRecordLog *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ProvisioningRecordLog>(object);
		}
		else
		{
			ret = new IPS_ProvisioningRecordLog(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ProvisioningRecordLog> > IPS_ProvisioningRecordLog::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ProvisioningRecordLog>(client, keys);
	}

	void IPS_ProvisioningRecordLog::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ProvisioningRecordLog::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_ProvisioningRecordLog::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void IPS_ProvisioningRecordLog::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void IPS_ProvisioningRecordLog::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_ProvisioningRecordLog::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference IPS_ProvisioningRecordLog::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool IPS_ProvisioningRecordLog::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int IPS_ProvisioningRecordLog::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int IPS_ProvisioningRecordLog::ClearLog()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ClearLog", input, output);
	}
	const string IPS_ProvisioningRecordLog::CLASS_NAME = "IPS_ProvisioningRecordLog";
	const string IPS_ProvisioningRecordLog::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ProvisioningRecordLog";
	const string IPS_ProvisioningRecordLog::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ProvisioningRecordLog";
	const string IPS_ProvisioningRecordLog::CLASS_NS_PREFIX = "APr995";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ProvisioningRecordLog::_classMetaData;
}
}
}
}
