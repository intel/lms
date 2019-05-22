//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_PowerManagementCapabilities.cpp
//
//  Contents:   A class derived from CIM_PowerManagementCapabilitieslities that adds OS power saving aspects of an element (AKA connected standby).
//
//              This file was automatically generated from IPS_PowerManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#include "IPS_PowerManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_PowerManagementCapabilities::_metadata[] = {
		{"OSPowerSavingStateSupported", false, false, false },
		{"OSPowerSavingStateChangeSupported", false, false, false },
	};
	// class fields
	const unsigned short IPS_PowerManagementCapabilities::OSPowerSavingStateSupported() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OSPowerSavingStateSupported"), ret);
		return ret;
	}
	void IPS_PowerManagementCapabilities::OSPowerSavingStateSupported(const unsigned short value)
	{
		SetOrAddField("OSPowerSavingStateSupported", TypeConverter::TypeToString(value));
	}
	bool IPS_PowerManagementCapabilities::OSPowerSavingStateSupportedExists() const
	{
		return ContainsField("OSPowerSavingStateSupported");
	}
	void IPS_PowerManagementCapabilities::RemoveOSPowerSavingStateSupported()
	{
		RemoveField("OSPowerSavingStateSupported");
	}

	const unsigned short IPS_PowerManagementCapabilities::OSPowerSavingStateChangeSupported() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OSPowerSavingStateChangeSupported"), ret);
		return ret;
	}
	void IPS_PowerManagementCapabilities::OSPowerSavingStateChangeSupported(const unsigned short value)
	{
		SetOrAddField("OSPowerSavingStateChangeSupported", TypeConverter::TypeToString(value));
	}
	bool IPS_PowerManagementCapabilities::OSPowerSavingStateChangeSupportedExists() const
	{
		return ContainsField("OSPowerSavingStateChangeSupported");
	}
	void IPS_PowerManagementCapabilities::RemoveOSPowerSavingStateChangeSupported()
	{
		RemoveField("OSPowerSavingStateChangeSupported");
	}

	CimBase *IPS_PowerManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		IPS_PowerManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_PowerManagementCapabilities>(object);
		}
		else
		{
			ret = new IPS_PowerManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_PowerManagementCapabilities> > IPS_PowerManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_PowerManagementCapabilities>(client, keys);
	}

	void IPS_PowerManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_PowerManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_PowerManagementCapabilities::CLASS_NAME = "IPS_PowerManagementCapabilities";
	const string IPS_PowerManagementCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_PowerManagementCapabilities";
	const string IPS_PowerManagementCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_PowerManagementCapabilities";
	const string IPS_PowerManagementCapabilities::CLASS_NS_PREFIX = "APo763";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_PowerManagementCapabilities::_classMetaData;
}
}
}
}
