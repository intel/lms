//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalPortCapabilities.cpp
//
//  Contents:   LogicalPortCapabilities describes the configuration capabilities for properties in LogicalPortSettings.
//
//              This file was automatically generated from CIM_LogicalPortCapabilities.mof,  version: 2.11.0
//
//----------------------------------------------------------------------------
#include "CIM_LogicalPortCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LogicalPortCapabilities::_metadata[] = {
		{"RequestedSpeedsSupported", false, false, false },
		{"AutoSenseSpeedConfigurable", false, false, false },
	};
	// class fields
	const vector<Uint64> CIM_LogicalPortCapabilities::RequestedSpeedsSupported() const
	{
		vector<Uint64> ret;
		TypeConverter::StringToType(GetField("RequestedSpeedsSupported"), ret);
		return ret;
	}
	void CIM_LogicalPortCapabilities::RequestedSpeedsSupported(const vector<Uint64> &value)
	{
		SetOrAddField("RequestedSpeedsSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPortCapabilities::RequestedSpeedsSupportedExists() const
	{
		return ContainsField("RequestedSpeedsSupported");
	}
	void CIM_LogicalPortCapabilities::RemoveRequestedSpeedsSupported()
	{
		RemoveField("RequestedSpeedsSupported");
	}

	const bool CIM_LogicalPortCapabilities::AutoSenseSpeedConfigurable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AutoSenseSpeedConfigurable"), ret);
		return ret;
	}
	void CIM_LogicalPortCapabilities::AutoSenseSpeedConfigurable(const bool value)
	{
		SetOrAddField("AutoSenseSpeedConfigurable", TypeConverter::TypeToString(value));
	}
	bool CIM_LogicalPortCapabilities::AutoSenseSpeedConfigurableExists() const
	{
		return ContainsField("AutoSenseSpeedConfigurable");
	}
	void CIM_LogicalPortCapabilities::RemoveAutoSenseSpeedConfigurable()
	{
		RemoveField("AutoSenseSpeedConfigurable");
	}

	CimBase *CIM_LogicalPortCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogicalPortCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogicalPortCapabilities>(object);
		}
		else
		{
			ret = new CIM_LogicalPortCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogicalPortCapabilities> > CIM_LogicalPortCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogicalPortCapabilities>(client, keys);
	}

	void CIM_LogicalPortCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogicalPortCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_LogicalPortCapabilities::CLASS_NAME = "CIM_LogicalPortCapabilities";
	const string CIM_LogicalPortCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalPortCapabilities";
	const string CIM_LogicalPortCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalPortCapabilities";
	const string CIM_LogicalPortCapabilities::CLASS_NS_PREFIX = "ALo488";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogicalPortCapabilities::_classMetaData;
}
}
}
}
