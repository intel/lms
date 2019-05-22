//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EndpointAccessControlService.cpp
//
//  Contents:   A AMT_EndpointAccessControlService is a Logical Element that contains the information necessary to represent and manage the functionality provided by a the Endpoint Access Control manager of Intel(R) AMT.
//
//              This file was automatically generated from AMT_EndpointAccessControlService.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EndpointAccessControlService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_EndpointAccessControlService::CreateFromCimObject(const CimObject &object)
	{
		AMT_EndpointAccessControlService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EndpointAccessControlService>(object);
		}
		else
		{
			ret = new AMT_EndpointAccessControlService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EndpointAccessControlService> > AMT_EndpointAccessControlService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EndpointAccessControlService>(client, keys);
	}

	void AMT_EndpointAccessControlService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EndpointAccessControlService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_EndpointAccessControlService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void AMT_EndpointAccessControlService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void AMT_EndpointAccessControlService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EndpointAccessControlService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_EndpointAccessControlService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int AMT_EndpointAccessControlService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute AMT_EndpointAccessControlService::GetPosture_INPUT::_metadata[] = {
		{"PostureType", false, true },
	};
	void AMT_EndpointAccessControlService::GetPosture_INPUT::PostureType(const unsigned short value)
	{
		SetOrAddField("PostureType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EndpointAccessControlService::GetPosture_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const Base64 AMT_EndpointAccessControlService::GetPosture_OUTPUT::SignedPosture() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("SignedPosture"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::GetPosture_OUTPUT::SignedPostureExists() const
	{
		return ContainsField("SignedPosture");
	}
	const Base64 AMT_EndpointAccessControlService::GetPosture_OUTPUT::PostureChangeHash() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("PostureChangeHash"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::GetPosture_OUTPUT::PostureChangeHashExists() const
	{
		return ContainsField("PostureChangeHash");
	}
	unsigned int AMT_EndpointAccessControlService::GetPosture(const GetPosture_INPUT &input, GetPosture_OUTPUT &output)
	{
		return Invoke("GetPosture", input, output);
	}
	const CimFieldAttribute AMT_EndpointAccessControlService::GetPostureHash_INPUT::_metadata[] = {
		{"PostureType", false, true },
	};
	void AMT_EndpointAccessControlService::GetPostureHash_INPUT::PostureType(const unsigned short value)
	{
		SetOrAddField("PostureType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EndpointAccessControlService::GetPostureHash_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const Base64 AMT_EndpointAccessControlService::GetPostureHash_OUTPUT::PostureChangeHash() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("PostureChangeHash"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::GetPostureHash_OUTPUT::PostureChangeHashExists() const
	{
		return ContainsField("PostureChangeHash");
	}
	unsigned int AMT_EndpointAccessControlService::GetPostureHash(const GetPostureHash_INPUT &input, GetPostureHash_OUTPUT &output)
	{
		return Invoke("GetPostureHash", input, output);
	}
	const CimFieldAttribute AMT_EndpointAccessControlService::UpdatePostureState_INPUT::_metadata[] = {
		{"UpdateType", false, true },
	};
	void AMT_EndpointAccessControlService::UpdatePostureState_INPUT::UpdateType(const unsigned short value)
	{
		SetOrAddField("UpdateType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EndpointAccessControlService::UpdatePostureState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_EndpointAccessControlService::UpdatePostureState(const UpdatePostureState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UpdatePostureState", input, output);
	}
	const unsigned int AMT_EndpointAccessControlService::GetEacOptions_OUTPUT::EacVendors() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("EacVendors"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::GetEacOptions_OUTPUT::EacVendorsExists() const
	{
		return ContainsField("EacVendors");
	}
	const unsigned int AMT_EndpointAccessControlService::GetEacOptions_OUTPUT::PostureHashAlgorithm() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PostureHashAlgorithm"), ret);
		return ret;
	}
	bool AMT_EndpointAccessControlService::GetEacOptions_OUTPUT::PostureHashAlgorithmExists() const
	{
		return ContainsField("PostureHashAlgorithm");
	}
	unsigned int AMT_EndpointAccessControlService::GetEacOptions(GetEacOptions_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetEacOptions", input, output);
	}
	const CimFieldAttribute AMT_EndpointAccessControlService::SetEacOptions_INPUT::_metadata[] = {
		{"EacVendors", false, true },
		{"PostureHashAlgorithm", false, true },
	};
	void AMT_EndpointAccessControlService::SetEacOptions_INPUT::EacVendors(const unsigned int value)
	{
		SetOrAddField("EacVendors", TypeConverter::TypeToString(value));
	}
	void AMT_EndpointAccessControlService::SetEacOptions_INPUT::PostureHashAlgorithm(const unsigned int value)
	{
		SetOrAddField("PostureHashAlgorithm", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EndpointAccessControlService::SetEacOptions_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_EndpointAccessControlService::SetEacOptions(const SetEacOptions_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetEacOptions", input, output);
	}
	const string AMT_EndpointAccessControlService::CLASS_NAME = "AMT_EndpointAccessControlService";
	const string AMT_EndpointAccessControlService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EndpointAccessControlService";
	const string AMT_EndpointAccessControlService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EndpointAccessControlService";
	const string AMT_EndpointAccessControlService::CLASS_NS_PREFIX = "AEn576";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EndpointAccessControlService::_classMetaData;
}
}
}
}
