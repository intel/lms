//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_FilterEntryBase.cpp
//
//  Contents:   Class AMT_FilterEntryBase is an abstract class, representing any type of filter
//
//              This file was automatically generated from AMT_FilterEntryBase.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_FilterEntryBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_FilterEntryBase::_metadata[] = {
		{"IsNegated", false, false, false },
	};
	// class fields
	const bool AMT_FilterEntryBase::IsNegated() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsNegated"), ret);
		return ret;
	}
	void AMT_FilterEntryBase::IsNegated(const bool value)
	{
		SetOrAddField("IsNegated", TypeConverter::TypeToString(value));
	}
	bool AMT_FilterEntryBase::IsNegatedExists() const
	{
		return ContainsField("IsNegated");
	}
	void AMT_FilterEntryBase::RemoveIsNegated()
	{
		RemoveField("IsNegated");
	}

	CimBase *AMT_FilterEntryBase::CreateFromCimObject(const CimObject &object)
	{
		AMT_FilterEntryBase *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_FilterEntryBase>(object);
		}
		else
		{
			ret = new AMT_FilterEntryBase(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_FilterEntryBase> > AMT_FilterEntryBase::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_FilterEntryBase>(client, keys);
	}

	void AMT_FilterEntryBase::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_FilterEntryBase::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_FilterEntryBase::CLASS_NAME = "AMT_FilterEntryBase";
	const string AMT_FilterEntryBase::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_FilterEntryBase";
	const string AMT_FilterEntryBase::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_FilterEntryBase";
	const string AMT_FilterEntryBase::CLASS_NS_PREFIX = "AFi852";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_FilterEntryBase::_classMetaData;
}
}
}
}
