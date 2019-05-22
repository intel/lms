//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ComplexFilterEntryBase.cpp
//
//  Contents:   Class AMT_ComplexFilterEntryBase is an abstract class, representing any type of filter which can be identified by InstanceID and Name
//
//              This file was automatically generated from AMT_ComplexFilterEntryBase.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ComplexFilterEntryBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_ComplexFilterEntryBase::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"InstanceID", true, false, false },
	};
	// class fields
	const string AMT_ComplexFilterEntryBase::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void AMT_ComplexFilterEntryBase::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string AMT_ComplexFilterEntryBase::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void AMT_ComplexFilterEntryBase::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string AMT_ComplexFilterEntryBase::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void AMT_ComplexFilterEntryBase::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	CimBase *AMT_ComplexFilterEntryBase::CreateFromCimObject(const CimObject &object)
	{
		AMT_ComplexFilterEntryBase *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ComplexFilterEntryBase>(object);
		}
		else
		{
			ret = new AMT_ComplexFilterEntryBase(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ComplexFilterEntryBase> > AMT_ComplexFilterEntryBase::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ComplexFilterEntryBase>(client, keys);
	}

	void AMT_ComplexFilterEntryBase::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ComplexFilterEntryBase::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_ComplexFilterEntryBase::CLASS_NAME = "AMT_ComplexFilterEntryBase";
	const string AMT_ComplexFilterEntryBase::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ComplexFilterEntryBase";
	const string AMT_ComplexFilterEntryBase::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ComplexFilterEntryBase";
	const string AMT_ComplexFilterEntryBase::CLASS_NS_PREFIX = "ACo986";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ComplexFilterEntryBase::_classMetaData;
}
}
}
}
