//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalDevice.cpp
//
//  Contents:   An abstraction or emulation of a hardware entity, that may or may not be Realized in physical hardware. Any characteristics of a LogicalDevice that are used to manage its operation or configuration are contained in, or associated with, the LogicalDevice object. Examples of the operational properties of a Printer would be paper sizes supported, or detected errors. Examples of the configuration properties of a Sensor Device would be threshold settings. Various configurations could exist for a LogicalDevice. These configurations could be contained in Setting objects and associated with the LogicalDevice.
//
//              This file was automatically generated from CIM_LogicalDevice.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LogicalDevice::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"DeviceID", true, false, false },
		{"PowerManagementSupported", false, false, false },
		{"PowerManagementCapabilities", false, false, false },
		{"Availability", false, false, false },
		{"StatusInfo", false, false, false },
		{"LastErrorCode", false, false, false },
		{"ErrorDescription", false, false, false },
		{"ErrorCleared", false, false, false },
		{"OtherIdentifyingInfo", false, false, false },
		{"PowerOnHours", false, false, false },
		{"TotalPowerOnHours", false, false, false },
		{"IdentifyingDescriptions", false, false, false },
		{"AdditionalAvailability", false, false, false },
		{"MaxQuiesceTime", false, false, false },
	};
	// class fields
	const string CIM_LogicalDevice::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_LogicalDevice::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_LogicalDevice::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_LogicalDevice::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_LogicalDevice::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_LogicalDevice::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_LogicalDevice::DeviceID() const
	{
		return GetField("DeviceID")[0];
	}
	void CIM_LogicalDevice::DeviceID(const string &value)
	{
		SetOrAddField("DeviceID", value);
	}

	const bool CIM_LogicalDevice::PowerManagementSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PowerManagementSupported"), ret);
		return ret;
	}
	void CIM_LogicalDevice::PowerManagementSupported(const bool value)
	{
		SetOrAddField("PowerManagementSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::PowerManagementSupportedExists() const
	{
		return ContainsField("PowerManagementSupported");
	}
	void CIM_LogicalDevice::RemovePowerManagementSupported()
	{
		RemoveField("PowerManagementSupported");
	}

	const vector<unsigned short> CIM_LogicalDevice::PowerManagementCapabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("PowerManagementCapabilities"), ret);
		return ret;
	}
	void CIM_LogicalDevice::PowerManagementCapabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("PowerManagementCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::PowerManagementCapabilitiesExists() const
	{
		return ContainsField("PowerManagementCapabilities");
	}
	void CIM_LogicalDevice::RemovePowerManagementCapabilities()
	{
		RemoveField("PowerManagementCapabilities");
	}

	const unsigned short CIM_LogicalDevice::Availability() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Availability"), ret);
		return ret;
	}
	void CIM_LogicalDevice::Availability(const unsigned short value)
	{
		SetOrAddField("Availability", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::AvailabilityExists() const
	{
		return ContainsField("Availability");
	}
	void CIM_LogicalDevice::RemoveAvailability()
	{
		RemoveField("Availability");
	}

	const unsigned short CIM_LogicalDevice::StatusInfo() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("StatusInfo"), ret);
		return ret;
	}
	void CIM_LogicalDevice::StatusInfo(const unsigned short value)
	{
		SetOrAddField("StatusInfo", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::StatusInfoExists() const
	{
		return ContainsField("StatusInfo");
	}
	void CIM_LogicalDevice::RemoveStatusInfo()
	{
		RemoveField("StatusInfo");
	}

	const unsigned int CIM_LogicalDevice::LastErrorCode() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("LastErrorCode"), ret);
		return ret;
	}
	void CIM_LogicalDevice::LastErrorCode(const unsigned int value)
	{
		SetOrAddField("LastErrorCode", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::LastErrorCodeExists() const
	{
		return ContainsField("LastErrorCode");
	}
	void CIM_LogicalDevice::RemoveLastErrorCode()
	{
		RemoveField("LastErrorCode");
	}

	const string CIM_LogicalDevice::ErrorDescription() const
	{
		return GetField("ErrorDescription")[0];
	}
	void CIM_LogicalDevice::ErrorDescription(const string &value)
	{
		SetOrAddField("ErrorDescription", value);
	}
	bool CIM_LogicalDevice::ErrorDescriptionExists() const
	{
		return ContainsField("ErrorDescription");
	}
	void CIM_LogicalDevice::RemoveErrorDescription()
	{
		RemoveField("ErrorDescription");
	}

	const bool CIM_LogicalDevice::ErrorCleared() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ErrorCleared"), ret);
		return ret;
	}
	void CIM_LogicalDevice::ErrorCleared(const bool value)
	{
		SetOrAddField("ErrorCleared", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::ErrorClearedExists() const
	{
		return ContainsField("ErrorCleared");
	}
	void CIM_LogicalDevice::RemoveErrorCleared()
	{
		RemoveField("ErrorCleared");
	}

	const vector<string> CIM_LogicalDevice::OtherIdentifyingInfo() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherIdentifyingInfo"), ret);
		return ret;
	}
	void CIM_LogicalDevice::OtherIdentifyingInfo(const vector<string> &value)
	{
		SetOrAddField("OtherIdentifyingInfo", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::OtherIdentifyingInfoExists() const
	{
		return ContainsField("OtherIdentifyingInfo");
	}
	void CIM_LogicalDevice::RemoveOtherIdentifyingInfo()
	{
		RemoveField("OtherIdentifyingInfo");
	}

	const Uint64 CIM_LogicalDevice::PowerOnHours() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("PowerOnHours"), ret);
		return ret;
	}
	void CIM_LogicalDevice::PowerOnHours(const Uint64 value)
	{
		SetOrAddField("PowerOnHours", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::PowerOnHoursExists() const
	{
		return ContainsField("PowerOnHours");
	}
	void CIM_LogicalDevice::RemovePowerOnHours()
	{
		RemoveField("PowerOnHours");
	}

	const Uint64 CIM_LogicalDevice::TotalPowerOnHours() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("TotalPowerOnHours"), ret);
		return ret;
	}
	void CIM_LogicalDevice::TotalPowerOnHours(const Uint64 value)
	{
		SetOrAddField("TotalPowerOnHours", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::TotalPowerOnHoursExists() const
	{
		return ContainsField("TotalPowerOnHours");
	}
	void CIM_LogicalDevice::RemoveTotalPowerOnHours()
	{
		RemoveField("TotalPowerOnHours");
	}

	const vector<string> CIM_LogicalDevice::IdentifyingDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("IdentifyingDescriptions"), ret);
		return ret;
	}
	void CIM_LogicalDevice::IdentifyingDescriptions(const vector<string> &value)
	{
		SetOrAddField("IdentifyingDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::IdentifyingDescriptionsExists() const
	{
		return ContainsField("IdentifyingDescriptions");
	}
	void CIM_LogicalDevice::RemoveIdentifyingDescriptions()
	{
		RemoveField("IdentifyingDescriptions");
	}

	const vector<unsigned short> CIM_LogicalDevice::AdditionalAvailability() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("AdditionalAvailability"), ret);
		return ret;
	}
	void CIM_LogicalDevice::AdditionalAvailability(const vector<unsigned short> &value)
	{
		SetOrAddField("AdditionalAvailability", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::AdditionalAvailabilityExists() const
	{
		return ContainsField("AdditionalAvailability");
	}
	void CIM_LogicalDevice::RemoveAdditionalAvailability()
	{
		RemoveField("AdditionalAvailability");
	}

	const Uint64 CIM_LogicalDevice::MaxQuiesceTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxQuiesceTime"), ret);
		return ret;
	}
	void CIM_LogicalDevice::MaxQuiesceTime(const Uint64 value)
	{
		SetOrAddField("MaxQuiesceTime", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalDevice::MaxQuiesceTimeExists() const
	{
		return ContainsField("MaxQuiesceTime");
	}
	void CIM_LogicalDevice::RemoveMaxQuiesceTime()
	{
		RemoveField("MaxQuiesceTime");
	}

	CimBase *CIM_LogicalDevice::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogicalDevice *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogicalDevice>(object);
		}
		else
		{
			ret = new CIM_LogicalDevice(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogicalDevice> > CIM_LogicalDevice::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogicalDevice>(client, keys);
	}

	void CIM_LogicalDevice::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogicalDevice::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_LogicalDevice::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_LogicalDevice::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_LogicalDevice::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalDevice::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_LogicalDevice::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_LogicalDevice::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_LogicalDevice::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute CIM_LogicalDevice::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_LogicalDevice::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_LogicalDevice::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalDevice::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_LogicalDevice::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	unsigned int CIM_LogicalDevice::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_LogicalDevice::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_LogicalDevice::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalDevice::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalDevice::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	const CimFieldAttribute CIM_LogicalDevice::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_LogicalDevice::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalDevice::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalDevice::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_LogicalDevice::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_LogicalDevice::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalDevice::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalDevice::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	unsigned int CIM_LogicalDevice::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	unsigned int CIM_LogicalDevice::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	const string CIM_LogicalDevice::CLASS_NAME = "CIM_LogicalDevice";
	const string CIM_LogicalDevice::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalDevice";
	const string CIM_LogicalDevice::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalDevice";
	const string CIM_LogicalDevice::CLASS_NS_PREFIX = "ALo775";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogicalDevice::_classMetaData;
}
}
}
}
