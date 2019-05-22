//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_CoolingDevice.cpp
//
//  Contents:   Capabilities and management of CoolingDevices.
//
//              This file was automatically generated from CIM_CoolingDevice.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_CoolingDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_CoolingDevice::_metadata[] = {
		{"ActiveCooling", false, false, false },
	};
	// class fields
	const bool CIM_CoolingDevice::ActiveCooling() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActiveCooling"), ret);
		return ret;
	}
	void CIM_CoolingDevice::ActiveCooling(const bool value)
	{
		SetOrAddField("ActiveCooling", TypeConverter::TypeToString(value));
	}
	bool CIM_CoolingDevice::ActiveCoolingExists() const
	{
		return ContainsField("ActiveCooling");
	}
	void CIM_CoolingDevice::RemoveActiveCooling()
	{
		RemoveField("ActiveCooling");
	}

	CimBase *CIM_CoolingDevice::CreateFromCimObject(const CimObject &object)
	{
		CIM_CoolingDevice *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_CoolingDevice>(object);
		}
		else
		{
			ret = new CIM_CoolingDevice(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_CoolingDevice> > CIM_CoolingDevice::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_CoolingDevice>(client, keys);
	}

	void CIM_CoolingDevice::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_CoolingDevice::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_CoolingDevice::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	unsigned int CIM_CoolingDevice::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	const CimFieldAttribute CIM_CoolingDevice::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_CoolingDevice::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CoolingDevice::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_CoolingDevice::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	const CimFieldAttribute CIM_CoolingDevice::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_CoolingDevice::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CoolingDevice::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_CoolingDevice::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_CoolingDevice::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_CoolingDevice::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CoolingDevice::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_CoolingDevice::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	unsigned int CIM_CoolingDevice::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_CoolingDevice::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_CoolingDevice::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_CoolingDevice::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CoolingDevice::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_CoolingDevice::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	const CimFieldAttribute CIM_CoolingDevice::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_CoolingDevice::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_CoolingDevice::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_CoolingDevice::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_CoolingDevice::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_CoolingDevice::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_CoolingDevice::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_CoolingDevice::CLASS_NAME = "CIM_CoolingDevice";
	const string CIM_CoolingDevice::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CoolingDevice";
	const string CIM_CoolingDevice::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CoolingDevice";
	const string CIM_CoolingDevice::CLASS_NS_PREFIX = "ACo81";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_CoolingDevice::_classMetaData;
}
}
}
}
