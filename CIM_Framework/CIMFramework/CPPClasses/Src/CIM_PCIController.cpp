//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PCIController.cpp
//
//  Contents:   PCIController is a superclass for the PCIBridge and PCIDevice classes. These classes model adapters and bridges on a PCI bus. The properties in PCIController and its subclasses are defined in the various PCI Specifications that are published by the PCI SIG.
//
//              This file was automatically generated from CIM_PCIController.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#include "CIM_PCIController.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PCIController::_metadata[] = {
		{"CommandRegister", false, false, false },
		{"Capabilities", false, false, false },
		{"CapabilityDescriptions", false, false, false },
		{"DeviceSelectTiming", false, false, false },
		{"ClassCode", false, false, false },
		{"CacheLineSize", false, false, false },
		{"LatencyTimer", false, false, false },
		{"InterruptPin", false, false, false },
		{"ExpansionROMBaseAddress", false, false, false },
		{"SelfTestEnabled", false, false, false },
	};
	// class fields
	const unsigned short CIM_PCIController::CommandRegister() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CommandRegister"), ret);
		return ret;
	}
	void CIM_PCIController::CommandRegister(const unsigned short value)
	{
		SetOrAddField("CommandRegister", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::CommandRegisterExists() const
	{
		return ContainsField("CommandRegister");
	}
	void CIM_PCIController::RemoveCommandRegister()
	{
		RemoveField("CommandRegister");
	}

	const vector<unsigned short> CIM_PCIController::Capabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Capabilities"), ret);
		return ret;
	}
	void CIM_PCIController::Capabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("Capabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::CapabilitiesExists() const
	{
		return ContainsField("Capabilities");
	}
	void CIM_PCIController::RemoveCapabilities()
	{
		RemoveField("Capabilities");
	}

	const vector<string> CIM_PCIController::CapabilityDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CapabilityDescriptions"), ret);
		return ret;
	}
	void CIM_PCIController::CapabilityDescriptions(const vector<string> &value)
	{
		SetOrAddField("CapabilityDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::CapabilityDescriptionsExists() const
	{
		return ContainsField("CapabilityDescriptions");
	}
	void CIM_PCIController::RemoveCapabilityDescriptions()
	{
		RemoveField("CapabilityDescriptions");
	}

	const unsigned short CIM_PCIController::DeviceSelectTiming() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DeviceSelectTiming"), ret);
		return ret;
	}
	void CIM_PCIController::DeviceSelectTiming(const unsigned short value)
	{
		SetOrAddField("DeviceSelectTiming", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::DeviceSelectTimingExists() const
	{
		return ContainsField("DeviceSelectTiming");
	}
	void CIM_PCIController::RemoveDeviceSelectTiming()
	{
		RemoveField("DeviceSelectTiming");
	}

	const unsigned char CIM_PCIController::ClassCode() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("ClassCode"), ret);
		return ret;
	}
	void CIM_PCIController::ClassCode(const unsigned char &value)
	{
		SetOrAddField("ClassCode", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::ClassCodeExists() const
	{
		return ContainsField("ClassCode");
	}
	void CIM_PCIController::RemoveClassCode()
	{
		RemoveField("ClassCode");
	}

	const unsigned char CIM_PCIController::CacheLineSize() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("CacheLineSize"), ret);
		return ret;
	}
	void CIM_PCIController::CacheLineSize(const unsigned char &value)
	{
		SetOrAddField("CacheLineSize", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::CacheLineSizeExists() const
	{
		return ContainsField("CacheLineSize");
	}
	void CIM_PCIController::RemoveCacheLineSize()
	{
		RemoveField("CacheLineSize");
	}

	const unsigned char CIM_PCIController::LatencyTimer() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("LatencyTimer"), ret);
		return ret;
	}
	void CIM_PCIController::LatencyTimer(const unsigned char &value)
	{
		SetOrAddField("LatencyTimer", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::LatencyTimerExists() const
	{
		return ContainsField("LatencyTimer");
	}
	void CIM_PCIController::RemoveLatencyTimer()
	{
		RemoveField("LatencyTimer");
	}

	const unsigned short CIM_PCIController::InterruptPin() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("InterruptPin"), ret);
		return ret;
	}
	void CIM_PCIController::InterruptPin(const unsigned short value)
	{
		SetOrAddField("InterruptPin", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::InterruptPinExists() const
	{
		return ContainsField("InterruptPin");
	}
	void CIM_PCIController::RemoveInterruptPin()
	{
		RemoveField("InterruptPin");
	}

	const unsigned int CIM_PCIController::ExpansionROMBaseAddress() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ExpansionROMBaseAddress"), ret);
		return ret;
	}
	void CIM_PCIController::ExpansionROMBaseAddress(const unsigned int value)
	{
		SetOrAddField("ExpansionROMBaseAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::ExpansionROMBaseAddressExists() const
	{
		return ContainsField("ExpansionROMBaseAddress");
	}
	void CIM_PCIController::RemoveExpansionROMBaseAddress()
	{
		RemoveField("ExpansionROMBaseAddress");
	}

	const bool CIM_PCIController::SelfTestEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SelfTestEnabled"), ret);
		return ret;
	}
	void CIM_PCIController::SelfTestEnabled(const bool value)
	{
		SetOrAddField("SelfTestEnabled", TypeConverter::TypeToString(value));
	}
	bool CIM_PCIController::SelfTestEnabledExists() const
	{
		return ContainsField("SelfTestEnabled");
	}
	void CIM_PCIController::RemoveSelfTestEnabled()
	{
		RemoveField("SelfTestEnabled");
	}

	CimBase *CIM_PCIController::CreateFromCimObject(const CimObject &object)
	{
		CIM_PCIController *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PCIController>(object);
		}
		else
		{
			ret = new CIM_PCIController(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PCIController> > CIM_PCIController::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PCIController>(client, keys);
	}

	void CIM_PCIController::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PCIController::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_PCIController::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_PCIController::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_PCIController::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PCIController::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_PCIController::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_PCIController::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_PCIController::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute CIM_PCIController::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_PCIController::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_PCIController::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PCIController::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_PCIController::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	unsigned int CIM_PCIController::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_PCIController::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_PCIController::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PCIController::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_PCIController::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	const CimFieldAttribute CIM_PCIController::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_PCIController::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PCIController::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_PCIController::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_PCIController::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_PCIController::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PCIController::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_PCIController::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	unsigned int CIM_PCIController::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	unsigned int CIM_PCIController::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	unsigned int CIM_PCIController::BISTExecution()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("BISTExecution", input, output);
	}
	const string CIM_PCIController::CLASS_NAME = "CIM_PCIController";
	const string CIM_PCIController::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PCIController";
	const string CIM_PCIController::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PCIController";
	const string CIM_PCIController::CLASS_NS_PREFIX = "APC918";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PCIController::_classMetaData;
}
}
}
}
