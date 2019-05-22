//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterSettings.cpp
//
//  Contents:   Represents the system settings for the Heuristics System Defense feature
//
//              This file was automatically generated from AMT_HeuristicPacketFilterSettings.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_HeuristicPacketFilterSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_HeuristicPacketFilterSettings::_metadata[] = {
		{"Enabled", false, true, false },
		{"FastConnectionRateThreshold", false, false, false },
		{"FastConnectionRateClearTime", false, false, false },
		{"SlowConnectionRateThreshold", false, false, false },
		{"SlowConnectionRateClearTime", false, false, false },
		{"BlockAll", false, false, false },
		{"BlockOffensivePort", false, false, false },
		{"EncounterTimeout", false, true, false },
	};
	// class fields
	const bool AMT_HeuristicPacketFilterSettings::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	const unsigned int AMT_HeuristicPacketFilterSettings::FastConnectionRateThreshold() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("FastConnectionRateThreshold"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::FastConnectionRateThreshold(const unsigned int value)
	{
		SetOrAddField("FastConnectionRateThreshold", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::FastConnectionRateThresholdExists() const
	{
		return ContainsField("FastConnectionRateThreshold");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveFastConnectionRateThreshold()
	{
		RemoveField("FastConnectionRateThreshold");
	}

	const unsigned int AMT_HeuristicPacketFilterSettings::FastConnectionRateClearTime() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("FastConnectionRateClearTime"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::FastConnectionRateClearTime(const unsigned int value)
	{
		SetOrAddField("FastConnectionRateClearTime", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::FastConnectionRateClearTimeExists() const
	{
		return ContainsField("FastConnectionRateClearTime");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveFastConnectionRateClearTime()
	{
		RemoveField("FastConnectionRateClearTime");
	}

	const unsigned int AMT_HeuristicPacketFilterSettings::SlowConnectionRateThreshold() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("SlowConnectionRateThreshold"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::SlowConnectionRateThreshold(const unsigned int value)
	{
		SetOrAddField("SlowConnectionRateThreshold", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::SlowConnectionRateThresholdExists() const
	{
		return ContainsField("SlowConnectionRateThreshold");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveSlowConnectionRateThreshold()
	{
		RemoveField("SlowConnectionRateThreshold");
	}

	const unsigned int AMT_HeuristicPacketFilterSettings::SlowConnectionRateClearTime() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("SlowConnectionRateClearTime"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::SlowConnectionRateClearTime(const unsigned int value)
	{
		SetOrAddField("SlowConnectionRateClearTime", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::SlowConnectionRateClearTimeExists() const
	{
		return ContainsField("SlowConnectionRateClearTime");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveSlowConnectionRateClearTime()
	{
		RemoveField("SlowConnectionRateClearTime");
	}

	const bool AMT_HeuristicPacketFilterSettings::BlockAll() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BlockAll"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::BlockAll(const bool value)
	{
		SetOrAddField("BlockAll", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::BlockAllExists() const
	{
		return ContainsField("BlockAll");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveBlockAll()
	{
		RemoveField("BlockAll");
	}

	const bool AMT_HeuristicPacketFilterSettings::BlockOffensivePort() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BlockOffensivePort"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::BlockOffensivePort(const bool value)
	{
		SetOrAddField("BlockOffensivePort", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::BlockOffensivePortExists() const
	{
		return ContainsField("BlockOffensivePort");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveBlockOffensivePort()
	{
		RemoveField("BlockOffensivePort");
	}

	const unsigned short AMT_HeuristicPacketFilterSettings::EncounterTimeout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EncounterTimeout"), ret);
		return ret;
	}
	void AMT_HeuristicPacketFilterSettings::EncounterTimeout(const unsigned short value)
	{
		SetOrAddField("EncounterTimeout", TypeConverter::TypeToString(value));
	}
	bool AMT_HeuristicPacketFilterSettings::EncounterTimeoutExists() const
	{
		return ContainsField("EncounterTimeout");
	}
	void AMT_HeuristicPacketFilterSettings::RemoveEncounterTimeout()
	{
		RemoveField("EncounterTimeout");
	}

	CimBase *AMT_HeuristicPacketFilterSettings::CreateFromCimObject(const CimObject &object)
	{
		AMT_HeuristicPacketFilterSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_HeuristicPacketFilterSettings>(object);
		}
		else
		{
			ret = new AMT_HeuristicPacketFilterSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_HeuristicPacketFilterSettings> > AMT_HeuristicPacketFilterSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_HeuristicPacketFilterSettings>(client, keys);
	}

	void AMT_HeuristicPacketFilterSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_HeuristicPacketFilterSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_HeuristicPacketFilterSettings::CLASS_NAME = "AMT_HeuristicPacketFilterSettings";
	const string AMT_HeuristicPacketFilterSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterSettings";
	const string AMT_HeuristicPacketFilterSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_HeuristicPacketFilterSettings";
	const string AMT_HeuristicPacketFilterSettings::CLASS_NS_PREFIX = "AHe578";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_HeuristicPacketFilterSettings::_classMetaData;
}
}
}
}
