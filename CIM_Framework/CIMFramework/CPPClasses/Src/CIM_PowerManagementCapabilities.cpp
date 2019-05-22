//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerManagementCapabilities.cpp
//
//  Contents:   A class derived from Capabilities that describes the power management aspects of an element (typically a system or device). The element's power management capabilities are decoupled from a PowerManagementService, since a single service could apply to multiple elements, each with specific capabilities.
//
//              This file was automatically generated from CIM_PowerManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#include "CIM_PowerManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PowerManagementCapabilities::_metadata[] = {
		{"PowerCapabilities", false, false, false },
		{"OtherPowerCapabilitiesDescriptions", false, false, false },
		{"PowerStatesSupported", false, false, false },
		{"PowerChangeCapabilities", false, false, false },
		{"OtherPowerChangeCapabilities", false, false, false },
		{"RequestedPowerStatesSupported", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_PowerManagementCapabilities::PowerCapabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("PowerCapabilities"), ret);
		return ret;
	}
	void CIM_PowerManagementCapabilities::PowerCapabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("PowerCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerManagementCapabilities::PowerCapabilitiesExists() const
	{
		return ContainsField("PowerCapabilities");
	}
	void CIM_PowerManagementCapabilities::RemovePowerCapabilities()
	{
		RemoveField("PowerCapabilities");
	}

	const vector<string> CIM_PowerManagementCapabilities::OtherPowerCapabilitiesDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherPowerCapabilitiesDescriptions"), ret);
		return ret;
	}
	void CIM_PowerManagementCapabilities::OtherPowerCapabilitiesDescriptions(const vector<string> &value)
	{
		SetOrAddField("OtherPowerCapabilitiesDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerManagementCapabilities::OtherPowerCapabilitiesDescriptionsExists() const
	{
		return ContainsField("OtherPowerCapabilitiesDescriptions");
	}
	void CIM_PowerManagementCapabilities::RemoveOtherPowerCapabilitiesDescriptions()
	{
		RemoveField("OtherPowerCapabilitiesDescriptions");
	}

	const vector<unsigned short> CIM_PowerManagementCapabilities::PowerStatesSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("PowerStatesSupported"), ret);
		return ret;
	}
	void CIM_PowerManagementCapabilities::PowerStatesSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("PowerStatesSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerManagementCapabilities::PowerStatesSupportedExists() const
	{
		return ContainsField("PowerStatesSupported");
	}
	void CIM_PowerManagementCapabilities::RemovePowerStatesSupported()
	{
		RemoveField("PowerStatesSupported");
	}

	const vector<unsigned short> CIM_PowerManagementCapabilities::PowerChangeCapabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("PowerChangeCapabilities"), ret);
		return ret;
	}
	void CIM_PowerManagementCapabilities::PowerChangeCapabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("PowerChangeCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerManagementCapabilities::PowerChangeCapabilitiesExists() const
	{
		return ContainsField("PowerChangeCapabilities");
	}
	void CIM_PowerManagementCapabilities::RemovePowerChangeCapabilities()
	{
		RemoveField("PowerChangeCapabilities");
	}

	const string CIM_PowerManagementCapabilities::OtherPowerChangeCapabilities() const
	{
		return GetField("OtherPowerChangeCapabilities")[0];
	}
	void CIM_PowerManagementCapabilities::OtherPowerChangeCapabilities(const string &value)
	{
		SetOrAddField("OtherPowerChangeCapabilities", value);
	}
	bool CIM_PowerManagementCapabilities::OtherPowerChangeCapabilitiesExists() const
	{
		return ContainsField("OtherPowerChangeCapabilities");
	}
	void CIM_PowerManagementCapabilities::RemoveOtherPowerChangeCapabilities()
	{
		RemoveField("OtherPowerChangeCapabilities");
	}

	const vector<unsigned short> CIM_PowerManagementCapabilities::RequestedPowerStatesSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("RequestedPowerStatesSupported"), ret);
		return ret;
	}
	void CIM_PowerManagementCapabilities::RequestedPowerStatesSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("RequestedPowerStatesSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PowerManagementCapabilities::RequestedPowerStatesSupportedExists() const
	{
		return ContainsField("RequestedPowerStatesSupported");
	}
	void CIM_PowerManagementCapabilities::RemoveRequestedPowerStatesSupported()
	{
		RemoveField("RequestedPowerStatesSupported");
	}

	CimBase *CIM_PowerManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_PowerManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PowerManagementCapabilities>(object);
		}
		else
		{
			ret = new CIM_PowerManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PowerManagementCapabilities> > CIM_PowerManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PowerManagementCapabilities>(client, keys);
	}

	void CIM_PowerManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PowerManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PowerManagementCapabilities::CLASS_NAME = "CIM_PowerManagementCapabilities";
	const string CIM_PowerManagementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerManagementCapabilities";
	const string CIM_PowerManagementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PowerManagementCapabilities";
	const string CIM_PowerManagementCapabilities::CLASS_NS_PREFIX = "APo634";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PowerManagementCapabilities::_classMetaData;
}
}
}
}
