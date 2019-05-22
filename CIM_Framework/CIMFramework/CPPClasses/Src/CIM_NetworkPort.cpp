//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPort.cpp
//
//  Contents:   NetworkPort is the logical representation of network communications hardware such as a physical connector and the setup or operation of the network chips, at the lowest layers of a network stack.
//
//              This file was automatically generated from CIM_NetworkPort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_NetworkPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_NetworkPort::_metadata[] = {
		{"Speed", false, false, false },
		{"OtherNetworkPortType", false, false, false },
		{"PortNumber", false, false, false },
		{"LinkTechnology", false, false, false },
		{"OtherLinkTechnology", false, false, false },
		{"PermanentAddress", false, false, false },
		{"NetworkAddresses", false, false, false },
		{"FullDuplex", false, false, false },
		{"AutoSense", false, false, false },
		{"SupportedMaximumTransmissionUnit", false, false, false },
		{"ActiveMaximumTransmissionUnit", false, false, false },
	};
	// class fields
	const string CIM_NetworkPort::OtherNetworkPortType() const
	{
		return GetField("OtherNetworkPortType")[0];
	}
	void CIM_NetworkPort::OtherNetworkPortType(const string &value)
	{
		SetOrAddField("OtherNetworkPortType", value);
	}
	bool CIM_NetworkPort::OtherNetworkPortTypeExists() const
	{
		return ContainsField("OtherNetworkPortType");
	}
	void CIM_NetworkPort::RemoveOtherNetworkPortType()
	{
		RemoveField("OtherNetworkPortType");
	}

	const unsigned short CIM_NetworkPort::PortNumber() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PortNumber"), ret);
		return ret;
	}
	void CIM_NetworkPort::PortNumber(const unsigned short value)
	{
		SetOrAddField("PortNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::PortNumberExists() const
	{
		return ContainsField("PortNumber");
	}
	void CIM_NetworkPort::RemovePortNumber()
	{
		RemoveField("PortNumber");
	}

	const unsigned short CIM_NetworkPort::LinkTechnology() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LinkTechnology"), ret);
		return ret;
	}
	void CIM_NetworkPort::LinkTechnology(const unsigned short value)
	{
		SetOrAddField("LinkTechnology", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::LinkTechnologyExists() const
	{
		return ContainsField("LinkTechnology");
	}
	void CIM_NetworkPort::RemoveLinkTechnology()
	{
		RemoveField("LinkTechnology");
	}

	const string CIM_NetworkPort::OtherLinkTechnology() const
	{
		return GetField("OtherLinkTechnology")[0];
	}
	void CIM_NetworkPort::OtherLinkTechnology(const string &value)
	{
		SetOrAddField("OtherLinkTechnology", value);
	}
	bool CIM_NetworkPort::OtherLinkTechnologyExists() const
	{
		return ContainsField("OtherLinkTechnology");
	}
	void CIM_NetworkPort::RemoveOtherLinkTechnology()
	{
		RemoveField("OtherLinkTechnology");
	}

	const string CIM_NetworkPort::PermanentAddress() const
	{
		return GetField("PermanentAddress")[0];
	}
	void CIM_NetworkPort::PermanentAddress(const string &value)
	{
		SetOrAddField("PermanentAddress", value);
	}
	bool CIM_NetworkPort::PermanentAddressExists() const
	{
		return ContainsField("PermanentAddress");
	}
	void CIM_NetworkPort::RemovePermanentAddress()
	{
		RemoveField("PermanentAddress");
	}

	const vector<string> CIM_NetworkPort::NetworkAddresses() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("NetworkAddresses"), ret);
		return ret;
	}
	void CIM_NetworkPort::NetworkAddresses(const vector<string> &value)
	{
		SetOrAddField("NetworkAddresses", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::NetworkAddressesExists() const
	{
		return ContainsField("NetworkAddresses");
	}
	void CIM_NetworkPort::RemoveNetworkAddresses()
	{
		RemoveField("NetworkAddresses");
	}

	const bool CIM_NetworkPort::FullDuplex() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("FullDuplex"), ret);
		return ret;
	}
	void CIM_NetworkPort::FullDuplex(const bool value)
	{
		SetOrAddField("FullDuplex", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::FullDuplexExists() const
	{
		return ContainsField("FullDuplex");
	}
	void CIM_NetworkPort::RemoveFullDuplex()
	{
		RemoveField("FullDuplex");
	}

	const bool CIM_NetworkPort::AutoSense() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AutoSense"), ret);
		return ret;
	}
	void CIM_NetworkPort::AutoSense(const bool value)
	{
		SetOrAddField("AutoSense", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::AutoSenseExists() const
	{
		return ContainsField("AutoSense");
	}
	void CIM_NetworkPort::RemoveAutoSense()
	{
		RemoveField("AutoSense");
	}

	const Uint64 CIM_NetworkPort::SupportedMaximumTransmissionUnit() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("SupportedMaximumTransmissionUnit"), ret);
		return ret;
	}
	void CIM_NetworkPort::SupportedMaximumTransmissionUnit(const Uint64 value)
	{
		SetOrAddField("SupportedMaximumTransmissionUnit", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::SupportedMaximumTransmissionUnitExists() const
	{
		return ContainsField("SupportedMaximumTransmissionUnit");
	}
	void CIM_NetworkPort::RemoveSupportedMaximumTransmissionUnit()
	{
		RemoveField("SupportedMaximumTransmissionUnit");
	}

	const Uint64 CIM_NetworkPort::ActiveMaximumTransmissionUnit() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("ActiveMaximumTransmissionUnit"), ret);
		return ret;
	}
	void CIM_NetworkPort::ActiveMaximumTransmissionUnit(const Uint64 value)
	{
		SetOrAddField("ActiveMaximumTransmissionUnit", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPort::ActiveMaximumTransmissionUnitExists() const
	{
		return ContainsField("ActiveMaximumTransmissionUnit");
	}
	void CIM_NetworkPort::RemoveActiveMaximumTransmissionUnit()
	{
		RemoveField("ActiveMaximumTransmissionUnit");
	}

	CimBase *CIM_NetworkPort::CreateFromCimObject(const CimObject &object)
	{
		CIM_NetworkPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_NetworkPort>(object);
		}
		else
		{
			ret = new CIM_NetworkPort(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_NetworkPort> > CIM_NetworkPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_NetworkPort>(client, keys);
	}

	void CIM_NetworkPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_NetworkPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_NetworkPort::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_NetworkPort::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_NetworkPort::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPort::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_NetworkPort::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_NetworkPort::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_NetworkPort::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute CIM_NetworkPort::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_NetworkPort::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_NetworkPort::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPort::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_NetworkPort::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	unsigned int CIM_NetworkPort::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_NetworkPort::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_NetworkPort::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPort::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_NetworkPort::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	const CimFieldAttribute CIM_NetworkPort::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_NetworkPort::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPort::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_NetworkPort::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_NetworkPort::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_NetworkPort::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_NetworkPort::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_NetworkPort::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	unsigned int CIM_NetworkPort::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	unsigned int CIM_NetworkPort::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	const string CIM_NetworkPort::CLASS_NAME = "CIM_NetworkPort";
	const string CIM_NetworkPort::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPort";
	const string CIM_NetworkPort::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPort";
	const string CIM_NetworkPort::CLASS_NS_PREFIX = "ANe239";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_NetworkPort::_classMetaData;
}
}
}
}
