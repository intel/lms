//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AssociatedPowerManagementService.cpp
//
//  Contents:   The association between a Managed System Element and its power management service.
//
//              This file was automatically generated from CIM_AssociatedPowerManagementService.mof,  version: 2.24.1
//
//----------------------------------------------------------------------------
#include "CIM_AssociatedPowerManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AssociatedPowerManagementService::_metadata[] = {
		{"ServiceProvided", true, false, true },
		{"PowerState", false, false, false },
		{"OtherPowerState", false, false, false },
		{"RequestedPowerState", false, false, false },
		{"OtherRequestedPowerState", false, false, false },
		{"PowerOnTime", false, false, false },
		{"AvailableRequestedPowerStates", false, false, false },
		{"TransitioningToPowerState", false, false, false },
	};
	// class fields
	const unsigned short CIM_AssociatedPowerManagementService::PowerState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PowerState"), ret);
		return ret;
	}
	void CIM_AssociatedPowerManagementService::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPowerManagementService::PowerStateExists() const
	{
		return ContainsField("PowerState");
	}
	void CIM_AssociatedPowerManagementService::RemovePowerState()
	{
		RemoveField("PowerState");
	}

	const string CIM_AssociatedPowerManagementService::OtherPowerState() const
	{
		return GetField("OtherPowerState")[0];
	}
	void CIM_AssociatedPowerManagementService::OtherPowerState(const string &value)
	{
		SetOrAddField("OtherPowerState", value);
	}
	bool CIM_AssociatedPowerManagementService::OtherPowerStateExists() const
	{
		return ContainsField("OtherPowerState");
	}
	void CIM_AssociatedPowerManagementService::RemoveOtherPowerState()
	{
		RemoveField("OtherPowerState");
	}

	const unsigned short CIM_AssociatedPowerManagementService::RequestedPowerState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RequestedPowerState"), ret);
		return ret;
	}
	void CIM_AssociatedPowerManagementService::RequestedPowerState(const unsigned short value)
	{
		SetOrAddField("RequestedPowerState", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPowerManagementService::RequestedPowerStateExists() const
	{
		return ContainsField("RequestedPowerState");
	}
	void CIM_AssociatedPowerManagementService::RemoveRequestedPowerState()
	{
		RemoveField("RequestedPowerState");
	}

	const string CIM_AssociatedPowerManagementService::OtherRequestedPowerState() const
	{
		return GetField("OtherRequestedPowerState")[0];
	}
	void CIM_AssociatedPowerManagementService::OtherRequestedPowerState(const string &value)
	{
		SetOrAddField("OtherRequestedPowerState", value);
	}
	bool CIM_AssociatedPowerManagementService::OtherRequestedPowerStateExists() const
	{
		return ContainsField("OtherRequestedPowerState");
	}
	void CIM_AssociatedPowerManagementService::RemoveOtherRequestedPowerState()
	{
		RemoveField("OtherRequestedPowerState");
	}

	const CimDateTime CIM_AssociatedPowerManagementService::PowerOnTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("PowerOnTime"), ret);
		return ret;
	}
	void CIM_AssociatedPowerManagementService::PowerOnTime(const CimDateTime &value)
	{
		SetOrAddField("PowerOnTime", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPowerManagementService::PowerOnTimeExists() const
	{
		return ContainsField("PowerOnTime");
	}
	void CIM_AssociatedPowerManagementService::RemovePowerOnTime()
	{
		RemoveField("PowerOnTime");
	}

	const vector<unsigned short> CIM_AssociatedPowerManagementService::AvailableRequestedPowerStates() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("AvailableRequestedPowerStates"), ret);
		return ret;
	}
	void CIM_AssociatedPowerManagementService::AvailableRequestedPowerStates(const vector<unsigned short> &value)
	{
		SetOrAddField("AvailableRequestedPowerStates", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPowerManagementService::AvailableRequestedPowerStatesExists() const
	{
		return ContainsField("AvailableRequestedPowerStates");
	}
	void CIM_AssociatedPowerManagementService::RemoveAvailableRequestedPowerStates()
	{
		RemoveField("AvailableRequestedPowerStates");
	}

	const unsigned short CIM_AssociatedPowerManagementService::TransitioningToPowerState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TransitioningToPowerState"), ret);
		return ret;
	}
	void CIM_AssociatedPowerManagementService::TransitioningToPowerState(const unsigned short value)
	{
		SetOrAddField("TransitioningToPowerState", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPowerManagementService::TransitioningToPowerStateExists() const
	{
		return ContainsField("TransitioningToPowerState");
	}
	void CIM_AssociatedPowerManagementService::RemoveTransitioningToPowerState()
	{
		RemoveField("TransitioningToPowerState");
	}

	CimBase *CIM_AssociatedPowerManagementService::CreateFromCimObject(const CimObject &object)
	{
		CIM_AssociatedPowerManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AssociatedPowerManagementService>(object);
		}
		else
		{
			ret = new CIM_AssociatedPowerManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AssociatedPowerManagementService> > CIM_AssociatedPowerManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AssociatedPowerManagementService>(client, keys);
	}

	void CIM_AssociatedPowerManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AssociatedPowerManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AssociatedPowerManagementService::CLASS_NAME = "CIM_AssociatedPowerManagementService";
	const string CIM_AssociatedPowerManagementService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssociatedPowerManagementService";
	const string CIM_AssociatedPowerManagementService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssociatedPowerManagementService";
	const string CIM_AssociatedPowerManagementService::CLASS_NS_PREFIX = "AAs349";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AssociatedPowerManagementService::_classMetaData;
}
}
}
}
