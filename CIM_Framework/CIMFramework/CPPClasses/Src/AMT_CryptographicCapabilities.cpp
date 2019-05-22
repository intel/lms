//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_CryptographicCapabilities.cpp
//
//  Contents:   Describes the cryptographic capabilities of the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_CryptographicCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_CryptographicCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_CryptographicCapabilities::_metadata[] = {
		{"HardwareAcceleration", false, false, false },
	};
	// class fields
	const unsigned int AMT_CryptographicCapabilities::HardwareAcceleration() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("HardwareAcceleration"), ret);
		return ret;
	}
	void AMT_CryptographicCapabilities::HardwareAcceleration(const unsigned int value)
	{
		SetOrAddField("HardwareAcceleration", TypeConverter::TypeToString(value));
	}
	bool AMT_CryptographicCapabilities::HardwareAccelerationExists() const
	{
		return ContainsField("HardwareAcceleration");
	}
	void AMT_CryptographicCapabilities::RemoveHardwareAcceleration()
	{
		RemoveField("HardwareAcceleration");
	}

	CimBase *AMT_CryptographicCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_CryptographicCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_CryptographicCapabilities>(object);
		}
		else
		{
			ret = new AMT_CryptographicCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_CryptographicCapabilities> > AMT_CryptographicCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_CryptographicCapabilities>(client, keys);
	}

	void AMT_CryptographicCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_CryptographicCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_CryptographicCapabilities::CLASS_NAME = "AMT_CryptographicCapabilities";
	const string AMT_CryptographicCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_CryptographicCapabilities";
	const string AMT_CryptographicCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_CryptographicCapabilities";
	const string AMT_CryptographicCapabilities::CLASS_NS_PREFIX = "ACr306";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_CryptographicCapabilities::_classMetaData;
}
}
}
}
