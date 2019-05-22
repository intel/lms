//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_StateTransitionCondition.cpp
//
//  Contents:   Represents an application watchdog state transition that can trigger an action.
//
//              This file was automatically generated from AMT_StateTransitionCondition.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_StateTransitionCondition.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_StateTransitionCondition::_metadata[] = {
		{"OldState", false, false, false },
		{"NewState", false, false, false },
		{"StateSpace", false, false, false },
	};
	// class fields
	const unsigned short AMT_StateTransitionCondition::OldState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OldState"), ret);
		return ret;
	}
	void AMT_StateTransitionCondition::OldState(const unsigned short value)
	{
		SetOrAddField("OldState", TypeConverter::TypeToString(value));
	}
	bool AMT_StateTransitionCondition::OldStateExists() const
	{
		return ContainsField("OldState");
	}
	void AMT_StateTransitionCondition::RemoveOldState()
	{
		RemoveField("OldState");
	}

	const unsigned short AMT_StateTransitionCondition::NewState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NewState"), ret);
		return ret;
	}
	void AMT_StateTransitionCondition::NewState(const unsigned short value)
	{
		SetOrAddField("NewState", TypeConverter::TypeToString(value));
	}
	bool AMT_StateTransitionCondition::NewStateExists() const
	{
		return ContainsField("NewState");
	}
	void AMT_StateTransitionCondition::RemoveNewState()
	{
		RemoveField("NewState");
	}

	const string AMT_StateTransitionCondition::StateSpace() const
	{
		return GetField("StateSpace")[0];
	}
	void AMT_StateTransitionCondition::StateSpace(const string &value)
	{
		SetOrAddField("StateSpace", value);
	}
	bool AMT_StateTransitionCondition::StateSpaceExists() const
	{
		return ContainsField("StateSpace");
	}
	void AMT_StateTransitionCondition::RemoveStateSpace()
	{
		RemoveField("StateSpace");
	}

	CimBase *AMT_StateTransitionCondition::CreateFromCimObject(const CimObject &object)
	{
		AMT_StateTransitionCondition *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_StateTransitionCondition>(object);
		}
		else
		{
			ret = new AMT_StateTransitionCondition(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_StateTransitionCondition> > AMT_StateTransitionCondition::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_StateTransitionCondition>(client, keys);
	}

	void AMT_StateTransitionCondition::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_StateTransitionCondition::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_StateTransitionCondition::CLASS_NAME = "AMT_StateTransitionCondition";
	const string AMT_StateTransitionCondition::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_StateTransitionCondition";
	const string AMT_StateTransitionCondition::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_StateTransitionCondition";
	const string AMT_StateTransitionCondition::CLASS_NS_PREFIX = "ASt300";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_StateTransitionCondition::_classMetaData;
}
}
}
}
