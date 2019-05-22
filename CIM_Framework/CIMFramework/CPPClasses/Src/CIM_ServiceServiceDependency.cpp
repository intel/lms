//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceServiceDependency.cpp
//
//  Contents:   CIM_ServiceServiceDependency is an association between a Service and another Service, which indicates that the latter cooperates with the former, is required to be present, required to have completed, or must be absent for the former Service to provide its functionality. For example, Boot Services might be dependent upon underlying system initialization Services. In the case of the initialization Services, the Boot Service might be dependent on the completion of the init Services. 
//              When examining the ServiceServiceDependency class definition, note that its superclass ProvidesServiceToElement is deprecated. Unfortunately, ProvidesServiceToElement cannot be removed from the object hierarchy without a major Schema release. When or if a major release occurs, the ProvidesServiceToElement superclass will be removed, and ServiceServiceDependency will subclass from CIM_Dependency directly.
//
//              This file was automatically generated from CIM_ServiceServiceDependency.mof,  version: 2.16.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceServiceDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceServiceDependency::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"TypeOfDependency", false, false, false },
		{"RestartService", false, false, false },
	};
	// class fields
	const unsigned short CIM_ServiceServiceDependency::TypeOfDependency() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TypeOfDependency"), ret);
		return ret;
	}
	void CIM_ServiceServiceDependency::TypeOfDependency(const unsigned short value)
	{
		SetOrAddField("TypeOfDependency", TypeConverter::TypeToString(value));
	}
	bool CIM_ServiceServiceDependency::TypeOfDependencyExists() const
	{
		return ContainsField("TypeOfDependency");
	}
	void CIM_ServiceServiceDependency::RemoveTypeOfDependency()
	{
		RemoveField("TypeOfDependency");
	}

	const bool CIM_ServiceServiceDependency::RestartService() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RestartService"), ret);
		return ret;
	}
	void CIM_ServiceServiceDependency::RestartService(const bool value)
	{
		SetOrAddField("RestartService", TypeConverter::TypeToString(value));
	}
	bool CIM_ServiceServiceDependency::RestartServiceExists() const
	{
		return ContainsField("RestartService");
	}
	void CIM_ServiceServiceDependency::RemoveRestartService()
	{
		RemoveField("RestartService");
	}

	CimBase *CIM_ServiceServiceDependency::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceServiceDependency *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceServiceDependency>(object);
		}
		else
		{
			ret = new CIM_ServiceServiceDependency(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceServiceDependency> > CIM_ServiceServiceDependency::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceServiceDependency>(client, keys);
	}

	void CIM_ServiceServiceDependency::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceServiceDependency::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ServiceServiceDependency::CLASS_NAME = "CIM_ServiceServiceDependency";
	const string CIM_ServiceServiceDependency::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceServiceDependency";
	const string CIM_ServiceServiceDependency::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceServiceDependency";
	const string CIM_ServiceServiceDependency::CLASS_NS_PREFIX = "ASe915";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceServiceDependency::_classMetaData;
}
}
}
}
