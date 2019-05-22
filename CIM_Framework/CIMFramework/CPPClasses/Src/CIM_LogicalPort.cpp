//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalPort.cpp
//
//  Contents:   The abstraction of a port or connection point of a Device. This object should be instantiated when the Port has independent management characteristics from the Device that includes it. Examples are a Fibre Channel Port and a USB Port.
//
//              This file was automatically generated from CIM_LogicalPort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_LogicalPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LogicalPort::_metadata[] = {
		{"Speed", false, false, false },
		{"MaxSpeed", false, false, false },
		{"RequestedSpeed", false, false, false },
		{"UsageRestriction", false, false, false },
		{"PortType", false, false, false },
		{"OtherPortType", false, false, false },
	};
	// class fields
	const Uint64 CIM_LogicalPort::Speed() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("Speed"), ret);
		return ret;
	}
	void CIM_LogicalPort::Speed(const Uint64 value)
	{
		SetOrAddField("Speed", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPort::SpeedExists() const
	{
		return ContainsField("Speed");
	}
	void CIM_LogicalPort::RemoveSpeed()
	{
		RemoveField("Speed");
	}

	const Uint64 CIM_LogicalPort::MaxSpeed() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxSpeed"), ret);
		return ret;
	}
	void CIM_LogicalPort::MaxSpeed(const Uint64 value)
	{
		SetOrAddField("MaxSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPort::MaxSpeedExists() const
	{
		return ContainsField("MaxSpeed");
	}
	void CIM_LogicalPort::RemoveMaxSpeed()
	{
		RemoveField("MaxSpeed");
	}

	const Uint64 CIM_LogicalPort::RequestedSpeed() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("RequestedSpeed"), ret);
		return ret;
	}
	void CIM_LogicalPort::RequestedSpeed(const Uint64 value)
	{
		SetOrAddField("RequestedSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPort::RequestedSpeedExists() const
	{
		return ContainsField("RequestedSpeed");
	}
	void CIM_LogicalPort::RemoveRequestedSpeed()
	{
		RemoveField("RequestedSpeed");
	}

	const unsigned short CIM_LogicalPort::UsageRestriction() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("UsageRestriction"), ret);
		return ret;
	}
	void CIM_LogicalPort::UsageRestriction(const unsigned short value)
	{
		SetOrAddField("UsageRestriction", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPort::UsageRestrictionExists() const
	{
		return ContainsField("UsageRestriction");
	}
	void CIM_LogicalPort::RemoveUsageRestriction()
	{
		RemoveField("UsageRestriction");
	}

	const unsigned short CIM_LogicalPort::PortType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PortType"), ret);
		return ret;
	}
	void CIM_LogicalPort::PortType(const unsigned short value)
	{
		SetOrAddField("PortType", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPort::PortTypeExists() const
	{
		return ContainsField("PortType");
	}
	void CIM_LogicalPort::RemovePortType()
	{
		RemoveField("PortType");
	}

	const string CIM_LogicalPort::OtherPortType() const
	{
		return GetField("OtherPortType")[0];
	}
	void CIM_LogicalPort::OtherPortType(const string &value)
	{
		SetOrAddField("OtherPortType", value);
	}
	bool CIM_LogicalPort::OtherPortTypeExists() const
	{
		return ContainsField("OtherPortType");
	}
	void CIM_LogicalPort::RemoveOtherPortType()
	{
		RemoveField("OtherPortType");
	}

	CimBase *CIM_LogicalPort::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogicalPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogicalPort>(object);
		}
		else
		{
			ret = new CIM_LogicalPort(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogicalPort> > CIM_LogicalPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogicalPort>(client, keys);
	}

	void CIM_LogicalPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogicalPort::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_LogicalPort::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	unsigned int CIM_LogicalPort::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	const CimFieldAttribute CIM_LogicalPort::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_LogicalPort::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalPort::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalPort::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	const CimFieldAttribute CIM_LogicalPort::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_LogicalPort::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalPort::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalPort::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_LogicalPort::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_LogicalPort::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalPort::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_LogicalPort::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	unsigned int CIM_LogicalPort::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_LogicalPort::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_LogicalPort::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_LogicalPort::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalPort::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_LogicalPort::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	const CimFieldAttribute CIM_LogicalPort::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_LogicalPort::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_LogicalPort::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LogicalPort::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_LogicalPort::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_LogicalPort::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_LogicalPort::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_LogicalPort::CLASS_NAME = "CIM_LogicalPort";
	const string CIM_LogicalPort::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalPort";
	const string CIM_LogicalPort::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalPort";
	const string CIM_LogicalPort::CLASS_NS_PREFIX = "ALo610";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogicalPort::_classMetaData;
}
}
}
}
