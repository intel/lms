//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SystemPowerScheme.cpp
//
//  Contents:   Represents a system power scheme
//
//              This file was automatically generated from AMT_SystemPowerScheme.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SystemPowerScheme.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_SystemPowerScheme::_metadata[] = {
		{"ElementName", false, true, false },
		{"InstanceID", true, false, false },
		{"SchemeGUID", true, false, false },
	};
	// class fields
	const string AMT_SystemPowerScheme::SchemeGUID() const
	{
		return GetField("SchemeGUID")[0];
	}
	void AMT_SystemPowerScheme::SchemeGUID(const string &value)
	{
		SetOrAddField("SchemeGUID", value);
	}

	CimBase *AMT_SystemPowerScheme::CreateFromCimObject(const CimObject &object)
	{
		AMT_SystemPowerScheme *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SystemPowerScheme>(object);
		}
		else
		{
			ret = new AMT_SystemPowerScheme(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SystemPowerScheme> > AMT_SystemPowerScheme::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SystemPowerScheme>(client, keys);
	}

	void AMT_SystemPowerScheme::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SystemPowerScheme::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int AMT_SystemPowerScheme::SetPowerScheme()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SetPowerScheme", input, output);
	}
	const string AMT_SystemPowerScheme::CLASS_NAME = "AMT_SystemPowerScheme";
	const string AMT_SystemPowerScheme::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemPowerScheme";
	const string AMT_SystemPowerScheme::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemPowerScheme";
	const string AMT_SystemPowerScheme::CLASS_NS_PREFIX = "ASy356";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SystemPowerScheme::_classMetaData;
}
}
}
}
