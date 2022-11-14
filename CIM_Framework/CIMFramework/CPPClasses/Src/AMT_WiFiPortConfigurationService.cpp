//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_WiFiPortConfigurationService.cpp
//
//  Contents:   AMT_WiFiPortConfigurationService provides management of the Wi-Fi network interfaces associated with a Wi-Fi network port.
//
//              This file was automatically generated from AMT_WiFiPortConfigurationService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_WiFiPortConfigurationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_WiFiPortConfigurationService::_metadata[] = {
		{"localProfileSynchronizationEnabled", false, false, false },
		{"LastConnectedSsidUnderMeControl", false, false, false },
		{"NoHostCsmeSoftwarePolicy", false, false, false },
		{"UEFIWiFiProfileShareEnabled", false, false, false },
	};
	// class fields
	const unsigned int AMT_WiFiPortConfigurationService::localProfileSynchronizationEnabled() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("localProfileSynchronizationEnabled"), ret);
		return ret;
	}
	void AMT_WiFiPortConfigurationService::localProfileSynchronizationEnabled(const unsigned int value)
	{
		SetOrAddField("localProfileSynchronizationEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_WiFiPortConfigurationService::localProfileSynchronizationEnabledExists() const
	{
		return ContainsField("localProfileSynchronizationEnabled");
	}
	void AMT_WiFiPortConfigurationService::RemovelocalProfileSynchronizationEnabled()
	{
		RemoveField("localProfileSynchronizationEnabled");
	}

	const string AMT_WiFiPortConfigurationService::LastConnectedSsidUnderMeControl() const
	{
		return GetField("LastConnectedSsidUnderMeControl")[0];
	}
	void AMT_WiFiPortConfigurationService::LastConnectedSsidUnderMeControl(const string &value)
	{
		SetOrAddField("LastConnectedSsidUnderMeControl", value);
	}
	bool AMT_WiFiPortConfigurationService::LastConnectedSsidUnderMeControlExists() const
	{
		return ContainsField("LastConnectedSsidUnderMeControl");
	}
	void AMT_WiFiPortConfigurationService::RemoveLastConnectedSsidUnderMeControl()
	{
		RemoveField("LastConnectedSsidUnderMeControl");
	}

	const unsigned int AMT_WiFiPortConfigurationService::NoHostCsmeSoftwarePolicy() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("NoHostCsmeSoftwarePolicy"), ret);
		return ret;
	}
	void AMT_WiFiPortConfigurationService::NoHostCsmeSoftwarePolicy(const unsigned int value)
	{
		SetOrAddField("NoHostCsmeSoftwarePolicy", TypeConverter::TypeToString(value));
	}
	bool AMT_WiFiPortConfigurationService::NoHostCsmeSoftwarePolicyExists() const
	{
		return ContainsField("NoHostCsmeSoftwarePolicy");
	}
	void AMT_WiFiPortConfigurationService::RemoveNoHostCsmeSoftwarePolicy()
	{
		RemoveField("NoHostCsmeSoftwarePolicy");
	}

	const bool AMT_WiFiPortConfigurationService::UEFIWiFiProfileShareEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UEFIWiFiProfileShareEnabled"), ret);
		return ret;
	}
	void AMT_WiFiPortConfigurationService::UEFIWiFiProfileShareEnabled(const bool value)
	{
		SetOrAddField("UEFIWiFiProfileShareEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_WiFiPortConfigurationService::UEFIWiFiProfileShareEnabledExists() const
	{
		return ContainsField("UEFIWiFiProfileShareEnabled");
	}
	void AMT_WiFiPortConfigurationService::RemoveUEFIWiFiProfileShareEnabled()
	{
		RemoveField("UEFIWiFiProfileShareEnabled");
	}

	CimBase *AMT_WiFiPortConfigurationService::CreateFromCimObject(const CimObject &object)
	{
		AMT_WiFiPortConfigurationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_WiFiPortConfigurationService>(object);
		}
		else
		{
			ret = new AMT_WiFiPortConfigurationService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_WiFiPortConfigurationService> > AMT_WiFiPortConfigurationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_WiFiPortConfigurationService>(client, keys);
	}

	void AMT_WiFiPortConfigurationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_WiFiPortConfigurationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::_metadata[] = {
		{"WiFiEndpoint", false, true },
		{"WiFiEndpointSettingsInput", false, true },
		{"IEEE8021xSettingsInput", false, false },
		{"ClientCredential", false, false },
		{"CACredential", false, false },
	};
	void AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::WiFiEndpoint(const CimReference &value)
	{
		SetOrAddField("WiFiEndpoint", TypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::WiFiEndpointSettingsInput(const CIM_WiFiEndpointSettings &value)
	{
		SetOrAddField("WiFiEndpointSettingsInput", TypedTypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::IEEE8021xSettingsInput(const CIM_IEEE8021xSettings &value)
	{
		SetOrAddField("IEEE8021xSettingsInput", TypedTypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::ClientCredential(const CimReference &value)
	{
		SetOrAddField("ClientCredential", TypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::CACredential(const CimReference &value)
	{
		SetOrAddField("CACredential", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const CimReference AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT::WiFiEndpointSettings() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("WiFiEndpointSettings"), ret);
		return ret;
	}
	bool AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT::WiFiEndpointSettingsExists() const
	{
		return ContainsField("WiFiEndpointSettings");
	}
	const CimReference AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT::IEEE8021xSettings() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("IEEE8021xSettings"), ret);
		return ret;
	}
	bool AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT::IEEE8021xSettingsExists() const
	{
		return ContainsField("IEEE8021xSettings");
	}
	unsigned int AMT_WiFiPortConfigurationService::AddWiFiSettings(const AddWiFiSettings_INPUT &input, AddWiFiSettings_OUTPUT &output)
	{
		return Invoke("AddWiFiSettings", input, output);
	}
	const CimFieldAttribute AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::_metadata[] = {
		{"WiFiEndpointSettings", false, true },
		{"WiFiEndpointSettingsInput", false, true },
		{"IEEE8021xSettingsInput", false, false },
		{"ClientCredential", false, false },
		{"CACredential", false, false },
	};
	void AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::WiFiEndpointSettings(const CimReference &value)
	{
		SetOrAddField("WiFiEndpointSettings", TypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::WiFiEndpointSettingsInput(const CIM_WiFiEndpointSettings &value)
	{
		SetOrAddField("WiFiEndpointSettingsInput", TypedTypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::IEEE8021xSettingsInput(const CIM_IEEE8021xSettings &value)
	{
		SetOrAddField("IEEE8021xSettingsInput", TypedTypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::ClientCredential(const CimReference &value)
	{
		SetOrAddField("ClientCredential", TypeConverter::TypeToString(value));
	}
	void AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::CACredential(const CimReference &value)
	{
		SetOrAddField("CACredential", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const CimReference AMT_WiFiPortConfigurationService::UpdateWiFiSettings_OUTPUT::IEEE8021xSettings() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("IEEE8021xSettings"), ret);
		return ret;
	}
	bool AMT_WiFiPortConfigurationService::UpdateWiFiSettings_OUTPUT::IEEE8021xSettingsExists() const
	{
		return ContainsField("IEEE8021xSettings");
	}
	unsigned int AMT_WiFiPortConfigurationService::UpdateWiFiSettings(const UpdateWiFiSettings_INPUT &input, UpdateWiFiSettings_OUTPUT &output)
	{
		return Invoke("UpdateWiFiSettings", input, output);
	}
	unsigned int AMT_WiFiPortConfigurationService::DeleteAllITProfiles()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("DeleteAllITProfiles", input, output);
	}
	unsigned int AMT_WiFiPortConfigurationService::DeleteAllUserProfiles()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("DeleteAllUserProfiles", input, output);
	}
	const string AMT_WiFiPortConfigurationService::CLASS_NAME = "AMT_WiFiPortConfigurationService";
	const string AMT_WiFiPortConfigurationService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_WiFiPortConfigurationService";
	const string AMT_WiFiPortConfigurationService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_WiFiPortConfigurationService";
	const string AMT_WiFiPortConfigurationService::CLASS_NS_PREFIX = "AWi84";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_WiFiPortConfigurationService::_classMetaData;
}
}
}
}
