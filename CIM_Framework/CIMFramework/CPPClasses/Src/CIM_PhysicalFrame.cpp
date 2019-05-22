//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalFrame.cpp
//
//  Contents:   PhysicalFrame is a superclass of Rack, Chassis and other frame enclosures, as they are defined in extension classes. Properties like visible or audible alarm, and data related to security breaches are in this superclass.
//
//              This file was automatically generated from CIM_PhysicalFrame.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalFrame.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalFrame::_metadata[] = {
		{"CableManagementStrategy", false, false, false },
		{"ServicePhilosophy", false, false, false },
		{"ServiceDescriptions", false, false, false },
		{"LockPresent", false, false, false },
		{"AudibleAlarm", false, false, false },
		{"VisibleAlarm", false, false, false },
		{"SecurityBreach", false, false, false },
		{"BreachDescription", false, false, false },
		{"IsLocked", false, false, false },
	};
	// class fields
	const string CIM_PhysicalFrame::CableManagementStrategy() const
	{
		return GetField("CableManagementStrategy")[0];
	}
	void CIM_PhysicalFrame::CableManagementStrategy(const string &value)
	{
		SetOrAddField("CableManagementStrategy", value);
	}
	bool CIM_PhysicalFrame::CableManagementStrategyExists() const
	{
		return ContainsField("CableManagementStrategy");
	}
	void CIM_PhysicalFrame::RemoveCableManagementStrategy()
	{
		RemoveField("CableManagementStrategy");
	}

	const vector<unsigned short> CIM_PhysicalFrame::ServicePhilosophy() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ServicePhilosophy"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::ServicePhilosophy(const vector<unsigned short> &value)
	{
		SetOrAddField("ServicePhilosophy", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::ServicePhilosophyExists() const
	{
		return ContainsField("ServicePhilosophy");
	}
	void CIM_PhysicalFrame::RemoveServicePhilosophy()
	{
		RemoveField("ServicePhilosophy");
	}

	const vector<string> CIM_PhysicalFrame::ServiceDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ServiceDescriptions"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::ServiceDescriptions(const vector<string> &value)
	{
		SetOrAddField("ServiceDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::ServiceDescriptionsExists() const
	{
		return ContainsField("ServiceDescriptions");
	}
	void CIM_PhysicalFrame::RemoveServiceDescriptions()
	{
		RemoveField("ServiceDescriptions");
	}

	const bool CIM_PhysicalFrame::LockPresent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LockPresent"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::LockPresent(const bool value)
	{
		SetOrAddField("LockPresent", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::LockPresentExists() const
	{
		return ContainsField("LockPresent");
	}
	void CIM_PhysicalFrame::RemoveLockPresent()
	{
		RemoveField("LockPresent");
	}

	const bool CIM_PhysicalFrame::AudibleAlarm() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AudibleAlarm"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::AudibleAlarm(const bool value)
	{
		SetOrAddField("AudibleAlarm", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::AudibleAlarmExists() const
	{
		return ContainsField("AudibleAlarm");
	}
	void CIM_PhysicalFrame::RemoveAudibleAlarm()
	{
		RemoveField("AudibleAlarm");
	}

	const bool CIM_PhysicalFrame::VisibleAlarm() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("VisibleAlarm"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::VisibleAlarm(const bool value)
	{
		SetOrAddField("VisibleAlarm", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::VisibleAlarmExists() const
	{
		return ContainsField("VisibleAlarm");
	}
	void CIM_PhysicalFrame::RemoveVisibleAlarm()
	{
		RemoveField("VisibleAlarm");
	}

	const unsigned short CIM_PhysicalFrame::SecurityBreach() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SecurityBreach"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::SecurityBreach(const unsigned short value)
	{
		SetOrAddField("SecurityBreach", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::SecurityBreachExists() const
	{
		return ContainsField("SecurityBreach");
	}
	void CIM_PhysicalFrame::RemoveSecurityBreach()
	{
		RemoveField("SecurityBreach");
	}

	const string CIM_PhysicalFrame::BreachDescription() const
	{
		return GetField("BreachDescription")[0];
	}
	void CIM_PhysicalFrame::BreachDescription(const string &value)
	{
		SetOrAddField("BreachDescription", value);
	}
	bool CIM_PhysicalFrame::BreachDescriptionExists() const
	{
		return ContainsField("BreachDescription");
	}
	void CIM_PhysicalFrame::RemoveBreachDescription()
	{
		RemoveField("BreachDescription");
	}

	const bool CIM_PhysicalFrame::IsLocked() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsLocked"), ret);
		return ret;
	}
	void CIM_PhysicalFrame::IsLocked(const bool value)
	{
		SetOrAddField("IsLocked", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalFrame::IsLockedExists() const
	{
		return ContainsField("IsLocked");
	}
	void CIM_PhysicalFrame::RemoveIsLocked()
	{
		RemoveField("IsLocked");
	}

	CimBase *CIM_PhysicalFrame::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalFrame *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalFrame>(object);
		}
		else
		{
			ret = new CIM_PhysicalFrame(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalFrame> > CIM_PhysicalFrame::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalFrame>(client, keys);
	}

	void CIM_PhysicalFrame::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalFrame::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_PhysicalFrame::IsCompatible_INPUT::_metadata[] = {
		{"ElementToCheck", false, false },
	};
	void CIM_PhysicalFrame::IsCompatible_INPUT::ElementToCheck(const CimReference &value)
	{
		SetOrAddField("ElementToCheck", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_PhysicalFrame::IsCompatible_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_PhysicalFrame::IsCompatible(const IsCompatible_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("IsCompatible", input, output);
	}
	const string CIM_PhysicalFrame::CLASS_NAME = "CIM_PhysicalFrame";
	const string CIM_PhysicalFrame::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalFrame";
	const string CIM_PhysicalFrame::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalFrame";
	const string CIM_PhysicalFrame::CLASS_NS_PREFIX = "APh498";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalFrame::_classMetaData;
}
}
}
}
