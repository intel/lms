//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SetupAndConfigurationService.cpp
//
//  Contents:   Describes the Setup and Configuration Service, which is the logic in Intel(R) AMT that responds to Setup and Configuration requests.
//
//              This file was automatically generated from AMT_SetupAndConfigurationService.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SetupAndConfigurationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_SetupAndConfigurationService::_metadata[] = {
		{"ProvisioningMode", false, false, false },
		{"ProvisioningState", false, false, false },
		{"ZeroTouchConfigurationEnabled", false, false, false },
		{"ProvisioningServerOTP", false, false, false },
		{"ConfigurationServerFQDN", false, false, false },
		{"PasswordModel", false, false, false },
	};
	// class fields
	const unsigned char AMT_SetupAndConfigurationService::ProvisioningMode() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("ProvisioningMode"), ret);
		return ret;
	}
	void AMT_SetupAndConfigurationService::ProvisioningMode(const unsigned char &value)
	{
		SetOrAddField("ProvisioningMode", TypeConverter::TypeToString(value));
	}
	bool AMT_SetupAndConfigurationService::ProvisioningModeExists() const
	{
		return ContainsField("ProvisioningMode");
	}
	void AMT_SetupAndConfigurationService::RemoveProvisioningMode()
	{
		RemoveField("ProvisioningMode");
	}

	const unsigned char AMT_SetupAndConfigurationService::ProvisioningState() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("ProvisioningState"), ret);
		return ret;
	}
	void AMT_SetupAndConfigurationService::ProvisioningState(const unsigned char &value)
	{
		SetOrAddField("ProvisioningState", TypeConverter::TypeToString(value));
	}
	bool AMT_SetupAndConfigurationService::ProvisioningStateExists() const
	{
		return ContainsField("ProvisioningState");
	}
	void AMT_SetupAndConfigurationService::RemoveProvisioningState()
	{
		RemoveField("ProvisioningState");
	}

	const bool AMT_SetupAndConfigurationService::ZeroTouchConfigurationEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ZeroTouchConfigurationEnabled"), ret);
		return ret;
	}
	void AMT_SetupAndConfigurationService::ZeroTouchConfigurationEnabled(const bool value)
	{
		SetOrAddField("ZeroTouchConfigurationEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_SetupAndConfigurationService::ZeroTouchConfigurationEnabledExists() const
	{
		return ContainsField("ZeroTouchConfigurationEnabled");
	}
	void AMT_SetupAndConfigurationService::RemoveZeroTouchConfigurationEnabled()
	{
		RemoveField("ZeroTouchConfigurationEnabled");
	}

	const Base64 AMT_SetupAndConfigurationService::ProvisioningServerOTP() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ProvisioningServerOTP"), ret);
		return ret;
	}
	void AMT_SetupAndConfigurationService::ProvisioningServerOTP(const Base64 &value)
	{
		SetOrAddField("ProvisioningServerOTP", TypeConverter::TypeToString(value));
	}
	bool AMT_SetupAndConfigurationService::ProvisioningServerOTPExists() const
	{
		return ContainsField("ProvisioningServerOTP");
	}
	void AMT_SetupAndConfigurationService::RemoveProvisioningServerOTP()
	{
		RemoveField("ProvisioningServerOTP");
	}

	const string AMT_SetupAndConfigurationService::ConfigurationServerFQDN() const
	{
		return GetField("ConfigurationServerFQDN")[0];
	}
	void AMT_SetupAndConfigurationService::ConfigurationServerFQDN(const string &value)
	{
		SetOrAddField("ConfigurationServerFQDN", value);
	}
	bool AMT_SetupAndConfigurationService::ConfigurationServerFQDNExists() const
	{
		return ContainsField("ConfigurationServerFQDN");
	}
	void AMT_SetupAndConfigurationService::RemoveConfigurationServerFQDN()
	{
		RemoveField("ConfigurationServerFQDN");
	}

	const unsigned char AMT_SetupAndConfigurationService::PasswordModel() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("PasswordModel"), ret);
		return ret;
	}
	void AMT_SetupAndConfigurationService::PasswordModel(const unsigned char &value)
	{
		SetOrAddField("PasswordModel", TypeConverter::TypeToString(value));
	}
	bool AMT_SetupAndConfigurationService::PasswordModelExists() const
	{
		return ContainsField("PasswordModel");
	}
	void AMT_SetupAndConfigurationService::RemovePasswordModel()
	{
		RemoveField("PasswordModel");
	}

	CimBase *AMT_SetupAndConfigurationService::CreateFromCimObject(const CimObject &object)
	{
		AMT_SetupAndConfigurationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SetupAndConfigurationService>(object);
		}
		else
		{
			ret = new AMT_SetupAndConfigurationService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SetupAndConfigurationService> > AMT_SetupAndConfigurationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SetupAndConfigurationService>(client, keys);
	}

	void AMT_SetupAndConfigurationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SetupAndConfigurationService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int AMT_SetupAndConfigurationService::CommitChanges()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("CommitChanges", input, output);
	}
	const CimFieldAttribute AMT_SetupAndConfigurationService::Unprovision_INPUT::_metadata[] = {
		{"ProvisioningMode", false, false },
	};
	void AMT_SetupAndConfigurationService::Unprovision_INPUT::ProvisioningMode(const unsigned int value)
	{
		SetOrAddField("ProvisioningMode", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_SetupAndConfigurationService::Unprovision_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_SetupAndConfigurationService::Unprovision(const Unprovision_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("Unprovision", input, output);
	}
	unsigned int AMT_SetupAndConfigurationService::PartialUnprovision()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("PartialUnprovision", input, output);
	}
	const CimFieldAttribute AMT_SetupAndConfigurationService::ExtendProvisioningPeriod_INPUT::_metadata[] = {
		{"Duration", false, false },
	};
	void AMT_SetupAndConfigurationService::ExtendProvisioningPeriod_INPUT::Duration(const unsigned int value)
	{
		SetOrAddField("Duration", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_SetupAndConfigurationService::ExtendProvisioningPeriod_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_SetupAndConfigurationService::ExtendProvisioningPeriod(const ExtendProvisioningPeriod_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("ExtendProvisioningPeriod", input, output);
	}
	const CimFieldAttribute AMT_SetupAndConfigurationService::SetMEBxPassword_INPUT::_metadata[] = {
		{"Password", false, false },
	};
	void AMT_SetupAndConfigurationService::SetMEBxPassword_INPUT::Password(const string &value)
	{
		SetOrAddField("Password", value);
	}
	const VectorFieldData AMT_SetupAndConfigurationService::SetMEBxPassword_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_SetupAndConfigurationService::SetMEBxPassword(const SetMEBxPassword_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetMEBxPassword", input, output);
	}
	const Base64 AMT_SetupAndConfigurationService::GetUuid_OUTPUT::UUID() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("UUID"), ret);
		return ret;
	}
	bool AMT_SetupAndConfigurationService::GetUuid_OUTPUT::UUIDExists() const
	{
		return ContainsField("UUID");
	}
	unsigned int AMT_SetupAndConfigurationService::GetUuid(GetUuid_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetUuid", input, output);
	}
	const vector<unsigned int> AMT_SetupAndConfigurationService::GetUnprovisionBlockingComponents_OUTPUT::Component() const
	{
		vector<unsigned int> ret;
		if(ContainsField("Component"))
			TypeConverter::StringToType(GetField("Component"), ret);
		return ret;
	}
	unsigned int AMT_SetupAndConfigurationService::GetUnprovisionBlockingComponents(GetUnprovisionBlockingComponents_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetUnprovisionBlockingComponents", input, output);
	}
	const string AMT_SetupAndConfigurationService::CLASS_NAME = "AMT_SetupAndConfigurationService";
	const string AMT_SetupAndConfigurationService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SetupAndConfigurationService";
	const string AMT_SetupAndConfigurationService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SetupAndConfigurationService";
	const string AMT_SetupAndConfigurationService::CLASS_NS_PREFIX = "ASe984";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SetupAndConfigurationService::_classMetaData;
}
}
}
}
