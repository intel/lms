//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_StatisticalData.cpp
//
//  Contents:   CIM_StatisticalData is a root class for any arbitrary collection of statistical data and/or metrics applicable to one or more ManagedElements. These statistics MUST represent the most recent observations and MUST NOT be provided if irrelevant or stale. Note that this class uses a simplified naming/identity algorithm as compared to CIM_StatisticalInformation.
//
//              This file was automatically generated from CIM_StatisticalData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_StatisticalData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_StatisticalData::_metadata[] = {
		{"InstanceID", true, false, false },
		{"ElementName", false, true, false },
		{"StartStatisticTime", false, false, false },
		{"StatisticTime", false, false, false },
		{"SampleInterval", false, false, false },
	};
	// class fields
	const CimDateTime CIM_StatisticalData::StartStatisticTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("StartStatisticTime"), ret);
		return ret;
	}
	void CIM_StatisticalData::StartStatisticTime(const CimDateTime &value)
	{
		SetOrAddField("StartStatisticTime", TypeConverter::TypeToString(value));
	}
	bool CIM_StatisticalData::StartStatisticTimeExists() const
	{
		return ContainsField("StartStatisticTime");
	}
	void CIM_StatisticalData::RemoveStartStatisticTime()
	{
		RemoveField("StartStatisticTime");
	}

	const CimDateTime CIM_StatisticalData::StatisticTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("StatisticTime"), ret);
		return ret;
	}
	void CIM_StatisticalData::StatisticTime(const CimDateTime &value)
	{
		SetOrAddField("StatisticTime", TypeConverter::TypeToString(value));
	}
	bool CIM_StatisticalData::StatisticTimeExists() const
	{
		return ContainsField("StatisticTime");
	}
	void CIM_StatisticalData::RemoveStatisticTime()
	{
		RemoveField("StatisticTime");
	}

	const CimDateTime CIM_StatisticalData::SampleInterval() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("SampleInterval"), ret);
		return ret;
	}
	void CIM_StatisticalData::SampleInterval(const CimDateTime &value)
	{
		SetOrAddField("SampleInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_StatisticalData::SampleIntervalExists() const
	{
		return ContainsField("SampleInterval");
	}
	void CIM_StatisticalData::RemoveSampleInterval()
	{
		RemoveField("SampleInterval");
	}

	CimBase *CIM_StatisticalData::CreateFromCimObject(const CimObject &object)
	{
		CIM_StatisticalData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_StatisticalData>(object);
		}
		else
		{
			ret = new CIM_StatisticalData(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_StatisticalData> > CIM_StatisticalData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_StatisticalData>(client, keys);
	}

	void CIM_StatisticalData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_StatisticalData::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_StatisticalData::ResetSelectedStats_INPUT::_metadata[] = {
		{"SelectedStatistics", false, false },
	};
	void CIM_StatisticalData::ResetSelectedStats_INPUT::SelectedStatistics(const vector<string> &value)
	{
		SetOrAddField("SelectedStatistics", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StatisticalData::ResetSelectedStats_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_StatisticalData::ResetSelectedStats(const ResetSelectedStats_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("ResetSelectedStats", input, output);
	}
	const string CIM_StatisticalData::CLASS_NAME = "CIM_StatisticalData";
	const string CIM_StatisticalData::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_StatisticalData";
	const string CIM_StatisticalData::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_StatisticalData";
	const string CIM_StatisticalData::CLASS_NS_PREFIX = "ASt627";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_StatisticalData::_classMetaData;
}
}
}
}
