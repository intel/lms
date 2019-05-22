//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EthernetPort.cpp
//
//  Contents:   Capabilities and management of an EthernetPort.
//
//              This file was automatically generated from CIM_EthernetPort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_EthernetPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_EthernetPort::_metadata[] = {
		{"PortType", false, false, false },
		{"NetworkAddresses", false, false, false },
		{"MaxDataSize", false, false, false },
		{"Capabilities", false, false, false },
		{"CapabilityDescriptions", false, false, false },
		{"EnabledCapabilities", false, false, false },
		{"OtherEnabledCapabilities", false, false, false },
	};
	// class fields
	const unsigned int CIM_EthernetPort::MaxDataSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxDataSize"), ret);
		return ret;
	}
	void CIM_EthernetPort::MaxDataSize(const unsigned int value)
	{
		SetOrAddField("MaxDataSize", TypeConverter::TypeToString(value));
	}
	bool CIM_EthernetPort::MaxDataSizeExists() const
	{
		return ContainsField("MaxDataSize");
	}
	void CIM_EthernetPort::RemoveMaxDataSize()
	{
		RemoveField("MaxDataSize");
	}

	const vector<unsigned short> CIM_EthernetPort::Capabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Capabilities"), ret);
		return ret;
	}
	void CIM_EthernetPort::Capabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("Capabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_EthernetPort::CapabilitiesExists() const
	{
		return ContainsField("Capabilities");
	}
	void CIM_EthernetPort::RemoveCapabilities()
	{
		RemoveField("Capabilities");
	}

	const vector<string> CIM_EthernetPort::CapabilityDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CapabilityDescriptions"), ret);
		return ret;
	}
	void CIM_EthernetPort::CapabilityDescriptions(const vector<string> &value)
	{
		SetOrAddField("CapabilityDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_EthernetPort::CapabilityDescriptionsExists() const
	{
		return ContainsField("CapabilityDescriptions");
	}
	void CIM_EthernetPort::RemoveCapabilityDescriptions()
	{
		RemoveField("CapabilityDescriptions");
	}

	const vector<unsigned short> CIM_EthernetPort::EnabledCapabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("EnabledCapabilities"), ret);
		return ret;
	}
	void CIM_EthernetPort::EnabledCapabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("EnabledCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_EthernetPort::EnabledCapabilitiesExists() const
	{
		return ContainsField("EnabledCapabilities");
	}
	void CIM_EthernetPort::RemoveEnabledCapabilities()
	{
		RemoveField("EnabledCapabilities");
	}

	const vector<string> CIM_EthernetPort::OtherEnabledCapabilities() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherEnabledCapabilities"), ret);
		return ret;
	}
	void CIM_EthernetPort::OtherEnabledCapabilities(const vector<string> &value)
	{
		SetOrAddField("OtherEnabledCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_EthernetPort::OtherEnabledCapabilitiesExists() const
	{
		return ContainsField("OtherEnabledCapabilities");
	}
	void CIM_EthernetPort::RemoveOtherEnabledCapabilities()
	{
		RemoveField("OtherEnabledCapabilities");
	}

	CimBase *CIM_EthernetPort::CreateFromCimObject(const CimObject &object)
	{
		CIM_EthernetPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_EthernetPort>(object);
		}
		else
		{
			ret = new CIM_EthernetPort(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_EthernetPort> > CIM_EthernetPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_EthernetPort>(client, keys);
	}

	void CIM_EthernetPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_EthernetPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_EthernetPort::CLASS_NAME = "CIM_EthernetPort";
	const string CIM_EthernetPort::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EthernetPort";
	const string CIM_EthernetPort::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EthernetPort";
	const string CIM_EthernetPort::CLASS_NS_PREFIX = "AEt992";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_EthernetPort::_classMetaData;
}
}
}
}
