//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterStatistics.cpp
//
//  Contents:   Represents the state of the Heuristics System Defense feature
//
//              This file was automatically generated from AMT_HeuristicPacketFilterStatistics.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_HeuristicPacketFilterStatistics.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_HeuristicPacketFilterStatistics::_metadata[] = {
		{"State", false, false, false },
		{"BlockedAll", false, false, false },
		{"TimeStamp", false, false, false },
		{"TriggerReason", false, false, false },
		{"BlockedOffensivePort", false, false, false },
		{"BlockedOffensivePortProtocol", false, false, false },
		{"EnabledPolicy", false, false, false },
	};
	// class fields
	const unsigned short AMT_HeuristicPacketFilterStatistics::State() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("State"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::State(const unsigned short value)
	{
		SetOrAddField("State", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::StateExists() const
	{
		return ContainsField("State");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveState()
	{
		RemoveField("State");
	}

	const bool AMT_HeuristicPacketFilterStatistics::BlockedAll() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BlockedAll"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::BlockedAll(const bool value)
	{
		SetOrAddField("BlockedAll", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::BlockedAllExists() const
	{
		return ContainsField("BlockedAll");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveBlockedAll()
	{
		RemoveField("BlockedAll");
	}

	const CimDateTime AMT_HeuristicPacketFilterStatistics::TimeStamp() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeStamp"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::TimeStamp(const CimDateTime &value)
	{
		SetOrAddField("TimeStamp", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::TimeStampExists() const
	{
		return ContainsField("TimeStamp");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveTimeStamp()
	{
		RemoveField("TimeStamp");
	}

	const unsigned short AMT_HeuristicPacketFilterStatistics::TriggerReason() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TriggerReason"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::TriggerReason(const unsigned short value)
	{
		SetOrAddField("TriggerReason", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::TriggerReasonExists() const
	{
		return ContainsField("TriggerReason");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveTriggerReason()
	{
		RemoveField("TriggerReason");
	}

	const unsigned short AMT_HeuristicPacketFilterStatistics::BlockedOffensivePort() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BlockedOffensivePort"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::BlockedOffensivePort(const unsigned short value)
	{
		SetOrAddField("BlockedOffensivePort", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::BlockedOffensivePortExists() const
	{
		return ContainsField("BlockedOffensivePort");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveBlockedOffensivePort()
	{
		RemoveField("BlockedOffensivePort");
	}

	const unsigned short AMT_HeuristicPacketFilterStatistics::BlockedOffensivePortProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BlockedOffensivePortProtocol"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::BlockedOffensivePortProtocol(const unsigned short value)
	{
		SetOrAddField("BlockedOffensivePortProtocol", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::BlockedOffensivePortProtocolExists() const
	{
		return ContainsField("BlockedOffensivePortProtocol");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveBlockedOffensivePortProtocol()
	{
		RemoveField("BlockedOffensivePortProtocol");
	}

	const bool AMT_HeuristicPacketFilterStatistics::EnabledPolicy() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("EnabledPolicy"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterStatistics::EnabledPolicy(const bool value)
	{
		SetOrAddField("EnabledPolicy", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterStatistics::EnabledPolicyExists() const
	{
		return ContainsField("EnabledPolicy");
	}
	void AMT_HeuristicPacketFilterStatistics::RemoveEnabledPolicy()
	{
		RemoveField("EnabledPolicy");
	}

	CimBase *AMT_HeuristicPacketFilterStatistics::CreateFromCimObject(const CimObject &object)
	{
		AMT_HeuristicPacketFilterStatistics *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_HeuristicPacketFilterStatistics>(object);
		}
		else
		{
			ret = new AMT_HeuristicPacketFilterStatistics(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_HeuristicPacketFilterStatistics> > AMT_HeuristicPacketFilterStatistics::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_HeuristicPacketFilterStatistics>(client, keys);
	}

	void AMT_HeuristicPacketFilterStatistics::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_HeuristicPacketFilterStatistics::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_HeuristicPacketFilterStatistics::ResetSelectedStats_INPUT::_metadata[] = {
		{"SelectedStatistics", false, false },
	};
	void AMT_HeuristicPacketFilterStatistics::ResetSelectedStats_INPUT::SelectedStatistics(const vector<string> &value)
	{
		SetOrAddField("SelectedStatistics", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_HeuristicPacketFilterStatistics::ResetSelectedStats_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_HeuristicPacketFilterStatistics::ResetSelectedStats(const ResetSelectedStats_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("ResetSelectedStats", input, output);
	}
	const string AMT_HeuristicPacketFilterStatistics::CLASS_NAME = "AMT_HeuristicPacketFilterStatistics";
	const string AMT_HeuristicPacketFilterStatistics::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterStatistics";
	const string AMT_HeuristicPacketFilterStatistics::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterStatistics";
	const string AMT_HeuristicPacketFilterStatistics::CLASS_NS_PREFIX = "AHe198";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_HeuristicPacketFilterStatistics::_classMetaData;
}
}
}
}
