//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessService.cpp
//
//  Contents:   Represents the Remote Access Service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_RemoteAccessService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RemoteAccessService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_RemoteAccessService::CreateFromCimObject(const CimObject &object)
	{
		AMT_RemoteAccessService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RemoteAccessService>(object);
		}
		else
		{
			ret = new AMT_RemoteAccessService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RemoteAccessService> > AMT_RemoteAccessService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RemoteAccessService>(client, keys);
	}

	void AMT_RemoteAccessService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RemoteAccessService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_RemoteAccessService::AddMpServer_INPUT::_metadata[] = {
		{"AccessInfo", false, true },
		{"InfoFormat", false, true },
		{"Port", false, true },
		{"AuthMethod", false, true },
		{"Certificate", false, false },
		{"Username", false, false },
		{"Password", false, false },
		{"CN", false, false },
	};
	void AMT_RemoteAccessService::AddMpServer_INPUT::AccessInfo(const string &value)
	{
		SetOrAddField("AccessInfo", value);
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::InfoFormat(const unsigned short value)
	{
		SetOrAddField("InfoFormat", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::Port(const unsigned short value)
	{
		SetOrAddField("Port", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::AuthMethod(const unsigned int value)
	{
		SetOrAddField("AuthMethod", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::Certificate(const CimReference &value)
	{
		SetOrAddField("Certificate", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::Username(const string &value)
	{
		SetOrAddField("Username", value);
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::Password(const string &value)
	{
		SetOrAddField("Password", value);
	}
	void AMT_RemoteAccessService::AddMpServer_INPUT::CN(const string &value)
	{
		SetOrAddField("CN", value);
	}
	const VectorFieldData AMT_RemoteAccessService::AddMpServer_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 8);
		return ret;
	}
	const CimReference AMT_RemoteAccessService::AddMpServer_OUTPUT::MpServer() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("MpServer"), ret);
		return ret;
	}
	bool AMT_RemoteAccessService::AddMpServer_OUTPUT::MpServerExists() const
	{
		return ContainsField("MpServer");
	}
	unsigned int AMT_RemoteAccessService::AddMpServer(const AddMpServer_INPUT &input, AddMpServer_OUTPUT &output)
	{
		return Invoke("AddMpServer", input, output);
	}
	const CimFieldAttribute AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::_metadata[] = {
		{"Trigger", false, true },
		{"TunnelLifeTime", false, true },
		{"ExtendedData", false, false },
		{"MpServer", false, false },
		{"InternalMpServer", false, false },
	};
	void AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::Trigger(const unsigned short value)
	{
		SetOrAddField("Trigger", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::TunnelLifeTime(const unsigned int value)
	{
		SetOrAddField("TunnelLifeTime", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::ExtendedData(const Base64 &value)
	{
		SetOrAddField("ExtendedData", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::MpServer(const vector<CimReference> &value)
	{
		SetOrAddField("MpServer", TypeConverter::TypeToString(value));
	}
	void AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::InternalMpServer(const vector<CimReference> &value)
	{
		SetOrAddField("InternalMpServer", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_RemoteAccessService::AddRemoteAccessPolicyRule_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const CimReference AMT_RemoteAccessService::AddRemoteAccessPolicyRule_OUTPUT::PolicyRule() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("PolicyRule"), ret);
		return ret;
	}
	bool AMT_RemoteAccessService::AddRemoteAccessPolicyRule_OUTPUT::PolicyRuleExists() const
	{
		return ContainsField("PolicyRule");
	}
	unsigned int AMT_RemoteAccessService::AddRemoteAccessPolicyRule(const AddRemoteAccessPolicyRule_INPUT &input, AddRemoteAccessPolicyRule_OUTPUT &output)
	{
		return Invoke("AddRemoteAccessPolicyRule", input, output);
	}
	unsigned int AMT_RemoteAccessService::CloseRemoteAccessConnection()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("CloseRemoteAccessConnection", input, output);
	}
	const string AMT_RemoteAccessService::CLASS_NAME = "AMT_RemoteAccessService";
	const string AMT_RemoteAccessService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessService";
	const string AMT_RemoteAccessService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessService";
	const string AMT_RemoteAccessService::CLASS_NS_PREFIX = "ARe364";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RemoteAccessService::_classMetaData;
}
}
}
}
