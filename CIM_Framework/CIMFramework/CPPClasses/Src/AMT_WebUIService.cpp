//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_WebUIService.cpp
//
//  Contents:   Represents the Web User-Interface service in AMT.
//
//              This file was automatically generated from AMT_WebUIService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_WebUIService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_WebUIService::CreateFromCimObject(const CimObject &object)
	{
		AMT_WebUIService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_WebUIService>(object);
		}
		else
		{
			ret = new AMT_WebUIService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_WebUIService> > AMT_WebUIService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_WebUIService>(client, keys);
	}

	void AMT_WebUIService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_WebUIService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_WebUIService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_WebUIService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_WebUIService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_WebUIService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_WebUIService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_WebUIService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_WebUIService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string AMT_WebUIService::CLASS_NAME = "AMT_WebUIService";
	const string AMT_WebUIService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_WebUIService";
	const string AMT_WebUIService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_WebUIService";
	const string AMT_WebUIService::CLASS_NS_PREFIX = "AWe988";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_WebUIService::_classMetaData;
}
}
}
}
