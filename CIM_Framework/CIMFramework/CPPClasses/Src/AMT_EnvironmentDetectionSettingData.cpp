//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EnvironmentDetectionSettingData.cpp
//
//  Contents:   The AMT_EnvironmentDetectionSettingData class represents configuration-related and operational parameters for the Environment-Detection service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_EnvironmentDetectionSettingData.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_EnvironmentDetectionSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_EnvironmentDetectionSettingData::_metadata[] = {
		{"DetectionAlgorithm", false, true, false },
		{"DetectionStrings", false, false, false },
		{"DetectionIPv6LocalPrefixes", false, false, false },
	};
	// class fields
	const unsigned short AMT_EnvironmentDetectionSettingData::DetectionAlgorithm() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DetectionAlgorithm"), ret);
		return ret;
	}
	void AMT_EnvironmentDetectionSettingData::DetectionAlgorithm(const unsigned short value)
	{
		SetOrAddField("DetectionAlgorithm", TypeConverter::TypeToString(value));
	}
	bool AMT_EnvironmentDetectionSettingData::DetectionAlgorithmExists() const
	{
		return ContainsField("DetectionAlgorithm");
	}
	void AMT_EnvironmentDetectionSettingData::RemoveDetectionAlgorithm()
	{
		RemoveField("DetectionAlgorithm");
	}

	const vector<string> AMT_EnvironmentDetectionSettingData::DetectionStrings() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("DetectionStrings"), ret);
		return ret;
	}
	void AMT_EnvironmentDetectionSettingData::DetectionStrings(const vector<string> &value)
	{
		SetOrAddField("DetectionStrings", TypeConverter::TypeToString(value));
	}
	bool AMT_EnvironmentDetectionSettingData::DetectionStringsExists() const
	{
		return ContainsField("DetectionStrings");
	}
	void AMT_EnvironmentDetectionSettingData::RemoveDetectionStrings()
	{
		RemoveField("DetectionStrings");
	}

	const vector<string> AMT_EnvironmentDetectionSettingData::DetectionIPv6LocalPrefixes() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("DetectionIPv6LocalPrefixes"), ret);
		return ret;
	}
	void AMT_EnvironmentDetectionSettingData::DetectionIPv6LocalPrefixes(const vector<string> &value)
	{
		SetOrAddField("DetectionIPv6LocalPrefixes", TypeConverter::TypeToString(value));
	}
	bool AMT_EnvironmentDetectionSettingData::DetectionIPv6LocalPrefixesExists() const
	{
		return ContainsField("DetectionIPv6LocalPrefixes");
	}
	void AMT_EnvironmentDetectionSettingData::RemoveDetectionIPv6LocalPrefixes()
	{
		RemoveField("DetectionIPv6LocalPrefixes");
	}

	CimBase *AMT_EnvironmentDetectionSettingData::CreateFromCimObject(const CimObject &object)
	{
		AMT_EnvironmentDetectionSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_EnvironmentDetectionSettingData>(object);
		}
		else
		{
			ret = new AMT_EnvironmentDetectionSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_EnvironmentDetectionSettingData> > AMT_EnvironmentDetectionSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_EnvironmentDetectionSettingData>(client, keys);
	}

	void AMT_EnvironmentDetectionSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_EnvironmentDetectionSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_EnvironmentDetectionSettingData::SetSystemDefensePolicy_INPUT::_metadata[] = {
		{"Policy", false, false },
	};
	void AMT_EnvironmentDetectionSettingData::SetSystemDefensePolicy_INPUT::Policy(const CimReference &value)
	{
		SetOrAddField("Policy", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EnvironmentDetectionSettingData::SetSystemDefensePolicy_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_EnvironmentDetectionSettingData::SetSystemDefensePolicy(const SetSystemDefensePolicy_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetSystemDefensePolicy", input, output);
	}
	const CimFieldAttribute AMT_EnvironmentDetectionSettingData::EnableVpnRouting_INPUT::_metadata[] = {
		{"Enable", false, true },
	};
	void AMT_EnvironmentDetectionSettingData::EnableVpnRouting_INPUT::Enable(const bool value)
	{
		SetOrAddField("Enable", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_EnvironmentDetectionSettingData::EnableVpnRouting_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_EnvironmentDetectionSettingData::EnableVpnRouting(const EnableVpnRouting_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableVpnRouting", input, output);
	}
	const string AMT_EnvironmentDetectionSettingData::CLASS_NAME = "AMT_EnvironmentDetectionSettingData";
	const string AMT_EnvironmentDetectionSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EnvironmentDetectionSettingData";
	const string AMT_EnvironmentDetectionSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_EnvironmentDetectionSettingData";
	const string AMT_EnvironmentDetectionSettingData::CLASS_NS_PREFIX = "AEn759";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_EnvironmentDetectionSettingData::_classMetaData;
}
}
}
}
