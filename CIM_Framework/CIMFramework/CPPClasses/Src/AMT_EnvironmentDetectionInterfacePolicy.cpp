//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EnvironmentDetectionInterfacePolicy.cpp
//
//  Contents:   An existing association implies that a System Defense Policy has been configured to be activated for each interface that identifies it is external to the organization network.
//
//              This file was automatically generated from AMT_EnvironmentDetectionInterfacePolicy.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EnvironmentDetectionInterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EnvironmentDetectionInterfacePolicy::_metadata[] = {
		{"Enabled", false, false, false },
	};
	// class fields
	const bool AMT_EnvironmentDetectionInterfacePolicy::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_EnvironmentDetectionInterfacePolicy::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_EnvironmentDetectionInterfacePolicy::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_EnvironmentDetectionInterfacePolicy::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *AMT_EnvironmentDetectionInterfacePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_EnvironmentDetectionInterfacePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EnvironmentDetectionInterfacePolicy>(object);
		}
		else
		{
			ret = new AMT_EnvironmentDetectionInterfacePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EnvironmentDetectionInterfacePolicy> > AMT_EnvironmentDetectionInterfacePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EnvironmentDetectionInterfacePolicy>(client, keys);
	}

	void AMT_EnvironmentDetectionInterfacePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EnvironmentDetectionInterfacePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_EnvironmentDetectionInterfacePolicy::CLASS_NAME = "AMT_EnvironmentDetectionInterfacePolicy";
	const string AMT_EnvironmentDetectionInterfacePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EnvironmentDetectionInterfacePolicy";
	const string AMT_EnvironmentDetectionInterfacePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EnvironmentDetectionInterfacePolicy";
	const string AMT_EnvironmentDetectionInterfacePolicy::CLASS_NS_PREFIX = "AEn846";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EnvironmentDetectionInterfacePolicy::_classMetaData;
}
}
}
}
