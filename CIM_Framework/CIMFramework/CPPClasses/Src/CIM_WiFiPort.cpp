//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiPort.cpp
//
//  Contents:   WiFiPort is the logical representation of wireless local area network communications hardware that conforms to the IEEE 802.11 series of specifications. It embodies properties at the lowest layers of a network stack, such as the antennas used for transmission and reception, the address permanently embedded into the hardware, and the operational bandwidth of the device.
//
//              This file was automatically generated from CIM_WiFiPort.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_WiFiPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_WiFiPort::_metadata[] = {
		{"Speed", false, false, false },
		{"MaxSpeed", false, false, false },
		{"PortType", false, false, false },
		{"PermanentAddress", false, false, false },
		{"NetworkAddresses", false, false, false },
	};
	// class fields
	CimBase *CIM_WiFiPort::CreateFromCimObject(const CimObject &object)
	{
		CIM_WiFiPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_WiFiPort>(object);
		}
		else
		{
			ret = new CIM_WiFiPort(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_WiFiPort> > CIM_WiFiPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_WiFiPort>(client, keys);
	}

	void CIM_WiFiPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_WiFiPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_WiFiPort::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_WiFiPort::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_WiFiPort::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_WiFiPort::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_WiFiPort::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_WiFiPort::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_WiFiPort::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_WiFiPort::CLASS_NAME = "CIM_WiFiPort";
	const string CIM_WiFiPort::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiPort";
	const string CIM_WiFiPort::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiPort";
	const string CIM_WiFiPort::CLASS_NS_PREFIX = "AWi62";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_WiFiPort::_classMetaData;
}
}
}
}
