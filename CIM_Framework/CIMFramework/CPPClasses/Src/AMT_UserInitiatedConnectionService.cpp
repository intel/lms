//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_UserInitiatedConnectionService.cpp
//
//  Contents:   Represents the user initiated connection service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_UserInitiatedConnectionService.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_UserInitiatedConnectionService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_UserInitiatedConnectionService::_metadata[] = {
		{"EnabledState", false, false, false },
		{"LastConnectionReason", false, false, false },
	};
	// class fields
	const string AMT_UserInitiatedConnectionService::LastConnectionReason() const
	{
		return GetField("LastConnectionReason")[0];
	}
	void AMT_UserInitiatedConnectionService::LastConnectionReason(const string &value)
	{
		SetOrAddField("LastConnectionReason", value);
	}
	bool AMT_UserInitiatedConnectionService::LastConnectionReasonExists() const
	{
		return ContainsField("LastConnectionReason");
	}
	void AMT_UserInitiatedConnectionService::RemoveLastConnectionReason()
	{
		RemoveField("LastConnectionReason");
	}

	CimBase *AMT_UserInitiatedConnectionService::CreateFromCimObject(const CimObject &object)
	{
		AMT_UserInitiatedConnectionService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_UserInitiatedConnectionService>(object);
		}
		else
		{
			ret = new AMT_UserInitiatedConnectionService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_UserInitiatedConnectionService> > AMT_UserInitiatedConnectionService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_UserInitiatedConnectionService>(client, keys);
	}

	void AMT_UserInitiatedConnectionService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_UserInitiatedConnectionService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_UserInitiatedConnectionService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_UserInitiatedConnectionService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_UserInitiatedConnectionService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_UserInitiatedConnectionService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_UserInitiatedConnectionService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_UserInitiatedConnectionService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_UserInitiatedConnectionService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string AMT_UserInitiatedConnectionService::CLASS_NAME = "AMT_UserInitiatedConnectionService";
	const string AMT_UserInitiatedConnectionService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_UserInitiatedConnectionService";
	const string AMT_UserInitiatedConnectionService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_UserInitiatedConnectionService";
	const string AMT_UserInitiatedConnectionService::CLASS_NS_PREFIX = "AUs582";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_UserInitiatedConnectionService::_classMetaData;
}
}
}
}
