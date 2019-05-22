//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPortConfigurationService.cpp
//
//  Contents:   CIM_NetworkPortConfigurationService provides management of the network interfaces associated with a network port.
//
//              This file was automatically generated from CIM_NetworkPortConfigurationService.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_NetworkPortConfigurationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_NetworkPortConfigurationService::CreateFromCimObject(const CimObject &object)
	{
		CIM_NetworkPortConfigurationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_NetworkPortConfigurationService>(object);
		}
		else
		{
			ret = new CIM_NetworkPortConfigurationService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_NetworkPortConfigurationService> > CIM_NetworkPortConfigurationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_NetworkPortConfigurationService>(client, keys);
	}

	void CIM_NetworkPortConfigurationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_NetworkPortConfigurationService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_NetworkPortConfigurationService::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	unsigned int CIM_NetworkPortConfigurationService::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	const CimFieldAttribute CIM_NetworkPortConfigurationService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_NetworkPortConfigurationService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_NetworkPortConfigurationService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPortConfigurationService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_NetworkPortConfigurationService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_NetworkPortConfigurationService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_NetworkPortConfigurationService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::_metadata[] = {
		{"Port", false, true },
		{"Address", false, true },
		{"LANID", false, false },
		{"AliasAddresses", false, false },
		{"GroupAddresses", false, false },
	};
	void CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::Port(const CimReference &value)
	{
		SetOrAddField("Port", TypeConverter::TypeToString(value));
	}
	void CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::Address(const string &value)
	{
		SetOrAddField("Address", value);
	}
	void CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::LANID(const string &value)
	{
		SetOrAddField("LANID", value);
	}
	void CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::AliasAddresses(const vector<string> &value)
	{
		SetOrAddField("AliasAddresses", TypeConverter::TypeToString(value));
	}
	void CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::GroupAddresses(const vector<string> &value)
	{
		SetOrAddField("GroupAddresses", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPortConfigurationService::AddLANEndpoint_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const CimReference CIM_NetworkPortConfigurationService::AddLANEndpoint_OUTPUT::Endpoint() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Endpoint"), ret);
		return ret;
	}
	bool CIM_NetworkPortConfigurationService::AddLANEndpoint_OUTPUT::EndpointExists() const
	{
		return ContainsField("Endpoint");
	}
	unsigned int CIM_NetworkPortConfigurationService::AddLANEndpoint(const AddLANEndpoint_INPUT &input, AddLANEndpoint_OUTPUT &output)
	{
		return Invoke("AddLANEndpoint", input, output);
	}
	const string CIM_NetworkPortConfigurationService::CLASS_NAME = "CIM_NetworkPortConfigurationService";
	const string CIM_NetworkPortConfigurationService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPortConfigurationService";
	const string CIM_NetworkPortConfigurationService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPortConfigurationService";
	const string CIM_NetworkPortConfigurationService::CLASS_NS_PREFIX = "ANe622";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_NetworkPortConfigurationService::_classMetaData;
}
}
}
}
