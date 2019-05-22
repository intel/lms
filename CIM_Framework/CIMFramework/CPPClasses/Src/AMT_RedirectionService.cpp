//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RedirectionService.cpp
//
//  Contents:   Represents the redirection service, which encompasses the IDER and SOL redirection functionalities
//
//              This file was automatically generated from AMT_RedirectionService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RedirectionService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_RedirectionService::_metadata[] = {
		{"ListenerEnabled", false, false, false },
		{"AccessLog", false, false, false },
		{"EnabledState", false, false, false },
	};
	// class fields
	const bool AMT_RedirectionService::ListenerEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ListenerEnabled"), ret);
		return ret;
	}
	void AMT_RedirectionService::ListenerEnabled(const bool value)
	{
		SetOrAddField("ListenerEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_RedirectionService::ListenerEnabledExists() const
	{
		return ContainsField("ListenerEnabled");
	}
	void AMT_RedirectionService::RemoveListenerEnabled()
	{
		RemoveField("ListenerEnabled");
	}

	const vector<string> AMT_RedirectionService::AccessLog() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("AccessLog"), ret);
		return ret;
	}
	void AMT_RedirectionService::AccessLog(const vector<string> &value)
	{
		SetOrAddField("AccessLog", TypeConverter::TypeToString(value));
	}
	bool AMT_RedirectionService::AccessLogExists() const
	{
		return ContainsField("AccessLog");
	}
	void AMT_RedirectionService::RemoveAccessLog()
	{
		RemoveField("AccessLog");
	}

	CimBase *AMT_RedirectionService::CreateFromCimObject(const CimObject &object)
	{
		AMT_RedirectionService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RedirectionService>(object);
		}
		else
		{
			ret = new AMT_RedirectionService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RedirectionService> > AMT_RedirectionService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RedirectionService>(client, keys);
	}

	void AMT_RedirectionService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RedirectionService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_RedirectionService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_RedirectionService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_RedirectionService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_RedirectionService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_RedirectionService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_RedirectionService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_RedirectionService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute AMT_RedirectionService::TerminateSession_INPUT::_metadata[] = {
		{"SessionType", false, false },
	};
	void AMT_RedirectionService::TerminateSession_INPUT::SessionType(const unsigned int value)
	{
		SetOrAddField("SessionType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_RedirectionService::TerminateSession_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_RedirectionService::TerminateSession(const TerminateSession_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("TerminateSession", input, output);
	}
	const string AMT_RedirectionService::CLASS_NAME = "AMT_RedirectionService";
	const string AMT_RedirectionService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RedirectionService";
	const string AMT_RedirectionService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RedirectionService";
	const string AMT_RedirectionService::CLASS_NS_PREFIX = "ARe176";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RedirectionService::_classMetaData;
}
}
}
}
