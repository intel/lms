//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EventSubscriber.cpp
//
//  Contents:   Represents an event subscriber in AMT
//
//              This file was automatically generated from AMT_EventSubscriber.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EventSubscriber.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_EventSubscriber::CreateFromCimObject(const CimObject &object)
	{
		AMT_EventSubscriber *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EventSubscriber>(object);
		}
		else
		{
			ret = new AMT_EventSubscriber(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EventSubscriber> > AMT_EventSubscriber::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EventSubscriber>(client, keys);
	}

	void AMT_EventSubscriber::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EventSubscriber::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_EventSubscriber::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_EventSubscriber::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_EventSubscriber::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EventSubscriber::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_EventSubscriber::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_EventSubscriber::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_EventSubscriber::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string AMT_EventSubscriber::CLASS_NAME = "AMT_EventSubscriber";
	const string AMT_EventSubscriber::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventSubscriber";
	const string AMT_EventSubscriber::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EventSubscriber";
	const string AMT_EventSubscriber::CLASS_NS_PREFIX = "AEv757";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EventSubscriber::_classMetaData;
}
}
}
}
