//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ComputerSystem.cpp
//
//  Contents:   A class derived from System that is a special collection of ManagedSystemElements. This collection is related to the providing of compute capabilities and MAY serve as an aggregation point to associate one or more of the following elements: FileSystem, OperatingSystem, Processor and Memory (Volatile and/or NonVolatile Storage).
//
//              This file was automatically generated from CIM_ComputerSystem.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#include "CIM_ComputerSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ComputerSystem::_metadata[] = {
		{"NameFormat", false, false, false },
		{"Dedicated", false, false, false },
		{"OtherDedicatedDescriptions", false, false, false },
		{"ResetCapability", false, false, false },
		{"PowerManagementCapabilities", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_ComputerSystem::Dedicated() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Dedicated"), ret);
		return ret;
	}
	void CIM_ComputerSystem::Dedicated(const vector<unsigned short> &value)
	{
		SetOrAddField("Dedicated", TypeConverter::TypeToString(value));
	}
	bool CIM_ComputerSystem::DedicatedExists() const
	{
		return ContainsField("Dedicated");
	}
	void CIM_ComputerSystem::RemoveDedicated()
	{
		RemoveField("Dedicated");
	}

	const vector<string> CIM_ComputerSystem::OtherDedicatedDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherDedicatedDescriptions"), ret);
		return ret;
	}
	void CIM_ComputerSystem::OtherDedicatedDescriptions(const vector<string> &value)
	{
		SetOrAddField("OtherDedicatedDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_ComputerSystem::OtherDedicatedDescriptionsExists() const
	{
		return ContainsField("OtherDedicatedDescriptions");
	}
	void CIM_ComputerSystem::RemoveOtherDedicatedDescriptions()
	{
		RemoveField("OtherDedicatedDescriptions");
	}

	const unsigned short CIM_ComputerSystem::ResetCapability() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ResetCapability"), ret);
		return ret;
	}
	void CIM_ComputerSystem::ResetCapability(const unsigned short value)
	{
		SetOrAddField("ResetCapability", TypeConverter::TypeToString(value));
	}
	bool CIM_ComputerSystem::ResetCapabilityExists() const
	{
		return ContainsField("ResetCapability");
	}
	void CIM_ComputerSystem::RemoveResetCapability()
	{
		RemoveField("ResetCapability");
	}

	const vector<unsigned short> CIM_ComputerSystem::PowerManagementCapabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("PowerManagementCapabilities"), ret);
		return ret;
	}
	void CIM_ComputerSystem::PowerManagementCapabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("PowerManagementCapabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_ComputerSystem::PowerManagementCapabilitiesExists() const
	{
		return ContainsField("PowerManagementCapabilities");
	}
	void CIM_ComputerSystem::RemovePowerManagementCapabilities()
	{
		RemoveField("PowerManagementCapabilities");
	}

	CimBase *CIM_ComputerSystem::CreateFromCimObject(const CimObject &object)
	{
		CIM_ComputerSystem *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ComputerSystem>(object);
		}
		else
		{
			ret = new CIM_ComputerSystem(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ComputerSystem> > CIM_ComputerSystem::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ComputerSystem>(client, keys);
	}

	void CIM_ComputerSystem::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ComputerSystem::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ComputerSystem::CLASS_NAME = "CIM_ComputerSystem";
	const string CIM_ComputerSystem::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystem";
	const string CIM_ComputerSystem::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystem";
	const string CIM_ComputerSystem::CLASS_NS_PREFIX = "ACo366";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ComputerSystem::_classMetaData;
}
}
}
}
