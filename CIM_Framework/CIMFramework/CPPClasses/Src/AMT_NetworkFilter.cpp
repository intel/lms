//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkFilter.cpp
//
//  Contents:   Represents a general network filter.
//
//              This file was automatically generated from AMT_NetworkFilter.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_NetworkFilter.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_NetworkFilter::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"OwnerID", true, false, false },
	};
	// class fields
	const string AMT_NetworkFilter::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void AMT_NetworkFilter::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string AMT_NetworkFilter::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void AMT_NetworkFilter::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string AMT_NetworkFilter::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void AMT_NetworkFilter::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const unsigned int AMT_NetworkFilter::OwnerID() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("OwnerID"), ret);
		return ret;
	}
	void AMT_NetworkFilter::OwnerID(const unsigned int value)
	{
		SetOrAddField("OwnerID", TypeConverter::TypeToString(value));
	}

	CimBase *AMT_NetworkFilter::CreateFromCimObject(const CimObject &object)
	{
		AMT_NetworkFilter *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_NetworkFilter>(object);
		}
		else
		{
			ret = new AMT_NetworkFilter(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_NetworkFilter> > AMT_NetworkFilter::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_NetworkFilter>(client, keys);
	}

	void AMT_NetworkFilter::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_NetworkFilter::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_NetworkFilter::CLASS_NAME = "AMT_NetworkFilter";
	const string AMT_NetworkFilter::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkFilter";
	const string AMT_NetworkFilter::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_NetworkFilter";
	const string AMT_NetworkFilter::CLASS_NS_PREFIX = "ANe137";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_NetworkFilter::_classMetaData;
}
}
}
}
