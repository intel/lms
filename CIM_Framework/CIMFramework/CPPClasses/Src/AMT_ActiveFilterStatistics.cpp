//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ActiveFilterStatistics.cpp
//
//  Contents:   Represents an active filter in a policy.
//
//              This file was automatically generated from AMT_ActiveFilterStatistics.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ActiveFilterStatistics.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_ActiveFilterStatistics::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"ReadCount", false, false, false },
		{"FilterMatched", false, false, false },
		{"ActivationTime", false, false, false },
		{"LastResetTime", false, false, false },
	};
	// class fields
	const CimReference AMT_ActiveFilterStatistics::Antecedent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Antecedent"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::Antecedent(const CimReference &value)
	{
		SetOrAddField("Antecedent", TypeConverter::TypeToString(value));
	}

	const CimReference AMT_ActiveFilterStatistics::Dependent() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Dependent"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::Dependent(const CimReference &value)
	{
		SetOrAddField("Dependent", TypeConverter::TypeToString(value));
	}

	const unsigned int AMT_ActiveFilterStatistics::ReadCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ReadCount"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::ReadCount(const unsigned int value)
	{
		SetOrAddField("ReadCount", TypeConverter::TypeToString(value));
	}
	bool AMT_ActiveFilterStatistics::ReadCountExists() const
	{
		return ContainsField("ReadCount");
	}
	void AMT_ActiveFilterStatistics::RemoveReadCount()
	{
		RemoveField("ReadCount");
	}

	const bool AMT_ActiveFilterStatistics::FilterMatched() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("FilterMatched"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::FilterMatched(const bool value)
	{
		SetOrAddField("FilterMatched", TypeConverter::TypeToString(value));
	}
	bool AMT_ActiveFilterStatistics::FilterMatchedExists() const
	{
		return ContainsField("FilterMatched");
	}
	void AMT_ActiveFilterStatistics::RemoveFilterMatched()
	{
		RemoveField("FilterMatched");
	}

	const CimDateTime AMT_ActiveFilterStatistics::ActivationTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ActivationTime"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::ActivationTime(const CimDateTime &value)
	{
		SetOrAddField("ActivationTime", TypeConverter::TypeToString(value));
	}
	bool AMT_ActiveFilterStatistics::ActivationTimeExists() const
	{
		return ContainsField("ActivationTime");
	}
	void AMT_ActiveFilterStatistics::RemoveActivationTime()
	{
		RemoveField("ActivationTime");
	}

	const CimDateTime AMT_ActiveFilterStatistics::LastResetTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("LastResetTime"), ret);
		return ret;
	}
	void AMT_ActiveFilterStatistics::LastResetTime(const CimDateTime &value)
	{
		SetOrAddField("LastResetTime", TypeConverter::TypeToString(value));
	}
	bool AMT_ActiveFilterStatistics::LastResetTimeExists() const
	{
		return ContainsField("LastResetTime");
	}
	void AMT_ActiveFilterStatistics::RemoveLastResetTime()
	{
		RemoveField("LastResetTime");
	}

	CimBase *AMT_ActiveFilterStatistics::CreateFromCimObject(const CimObject &object)
	{
		AMT_ActiveFilterStatistics *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ActiveFilterStatistics>(object);
		}
		else
		{
			ret = new AMT_ActiveFilterStatistics(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ActiveFilterStatistics> > AMT_ActiveFilterStatistics::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ActiveFilterStatistics>(client, keys);
	}

	void AMT_ActiveFilterStatistics::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ActiveFilterStatistics::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_ActiveFilterStatistics::CLASS_NAME = "AMT_ActiveFilterStatistics";
	const string AMT_ActiveFilterStatistics::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ActiveFilterStatistics";
	const string AMT_ActiveFilterStatistics::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ActiveFilterStatistics";
	const string AMT_ActiveFilterStatistics::CLASS_NS_PREFIX = "AAc960";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ActiveFilterStatistics::_classMetaData;
}
}
}
}
