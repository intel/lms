//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TimeSynchronizationService.cpp
//
//  Contents:   Exposes Intel(R) AMT time synchronization services to management clients.
//
//              This file was automatically generated from AMT_TimeSynchronizationService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TimeSynchronizationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TimeSynchronizationService::_metadata[] = {
		{"LocalTimeSyncEnabled", false, false, false },
		{"TimeSource", false, false, false },
	};
	// class fields
	const unsigned int AMT_TimeSynchronizationService::LocalTimeSyncEnabled() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("LocalTimeSyncEnabled"), ret);
		return ret;
	}
	void AMT_TimeSynchronizationService::LocalTimeSyncEnabled(const unsigned int value)
	{
		SetOrAddField("LocalTimeSyncEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_TimeSynchronizationService::LocalTimeSyncEnabledExists() const
	{
		return ContainsField("LocalTimeSyncEnabled");
	}
	void AMT_TimeSynchronizationService::RemoveLocalTimeSyncEnabled()
	{
		RemoveField("LocalTimeSyncEnabled");
	}

	const unsigned int AMT_TimeSynchronizationService::TimeSource() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TimeSource"), ret);
		return ret;
	}
	void AMT_TimeSynchronizationService::TimeSource(const unsigned int value)
	{
		SetOrAddField("TimeSource", TypeConverter::TypeToString(value));
	}
	bool AMT_TimeSynchronizationService::TimeSourceExists() const
	{
		return ContainsField("TimeSource");
	}
	void AMT_TimeSynchronizationService::RemoveTimeSource()
	{
		RemoveField("TimeSource");
	}

	CimBase *AMT_TimeSynchronizationService::CreateFromCimObject(const CimObject &object)
	{
		AMT_TimeSynchronizationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TimeSynchronizationService>(object);
		}
		else
		{
			ret = new AMT_TimeSynchronizationService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TimeSynchronizationService> > AMT_TimeSynchronizationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TimeSynchronizationService>(client, keys);
	}

	void AMT_TimeSynchronizationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TimeSynchronizationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const unsigned int AMT_TimeSynchronizationService::GetLowAccuracyTimeSynch_OUTPUT::Ta0() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Ta0"), ret);
		return ret;
	}
	bool AMT_TimeSynchronizationService::GetLowAccuracyTimeSynch_OUTPUT::Ta0Exists() const
	{
		return ContainsField("Ta0");
	}
	unsigned int AMT_TimeSynchronizationService::GetLowAccuracyTimeSynch(GetLowAccuracyTimeSynch_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetLowAccuracyTimeSynch", input, output);
	}
	const CimFieldAttribute AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT::_metadata[] = {
		{"Ta0", false, true },
		{"Tm1", false, true },
		{"Tm2", false, true },
	};
	void AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT::Ta0(const unsigned int value)
	{
		SetOrAddField("Ta0", TypeConverter::TypeToString(value));
	}
	void AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT::Tm1(const unsigned int value)
	{
		SetOrAddField("Tm1", TypeConverter::TypeToString(value));
	}
	void AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT::Tm2(const unsigned int value)
	{
		SetOrAddField("Tm2", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch(const SetHighAccuracyTimeSynch_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetHighAccuracyTimeSynch", input, output);
	}
	const CimFieldAttribute AMT_TimeSynchronizationService::EnableLocalTimeSync_INPUT::_metadata[] = {
		{"Enable", false, true },
	};
	void AMT_TimeSynchronizationService::EnableLocalTimeSync_INPUT::Enable(const bool value)
	{
		SetOrAddField("Enable", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_TimeSynchronizationService::EnableLocalTimeSync_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_TimeSynchronizationService::EnableLocalTimeSync(const EnableLocalTimeSync_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableLocalTimeSync", input, output);
	}
	const string AMT_TimeSynchronizationService::CLASS_NAME = "AMT_TimeSynchronizationService";
	const string AMT_TimeSynchronizationService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TimeSynchronizationService";
	const string AMT_TimeSynchronizationService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TimeSynchronizationService";
	const string AMT_TimeSynchronizationService::CLASS_NS_PREFIX = "ATi535";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TimeSynchronizationService::_classMetaData;
}
}
}
}
