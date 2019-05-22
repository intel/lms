//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SystemDefensePolicy.cpp
//
//  Contents:   Describes a System Defense Policy
//
//              This file was automatically generated from AMT_SystemDefensePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SystemDefensePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_SystemDefensePolicy::_metadata[] = {
		{"InstanceID", true, false, false },
		{"PolicyName", false, false, false },
		{"PolicyPrecedence", false, true, false },
		{"AntiSpoofingSupport", false, false, false },
		{"FilterCreationHandles", false, false, false },
		{"TxDefaultDrop", false, true, false },
		{"TxDefaultMatchEvent", false, true, false },
		{"TxDefaultCount", false, true, false },
		{"RxDefaultDrop", false, true, false },
		{"RxDefaultMatchEvent", false, true, false },
		{"RxDefaultCount", false, true, false },
	};
	// class fields
	const string AMT_SystemDefensePolicy::PolicyName() const
	{
		return GetField("PolicyName")[0];
	}
	void AMT_SystemDefensePolicy::PolicyName(const string &value)
	{
		SetOrAddField("PolicyName", value);
	}
	bool AMT_SystemDefensePolicy::PolicyNameExists() const
	{
		return ContainsField("PolicyName");
	}
	void AMT_SystemDefensePolicy::RemovePolicyName()
	{
		RemoveField("PolicyName");
	}

	const unsigned int AMT_SystemDefensePolicy::PolicyPrecedence() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PolicyPrecedence"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::PolicyPrecedence(const unsigned int value)
	{
		SetOrAddField("PolicyPrecedence", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::PolicyPrecedenceExists() const
	{
		return ContainsField("PolicyPrecedence");
	}
	void AMT_SystemDefensePolicy::RemovePolicyPrecedence()
	{
		RemoveField("PolicyPrecedence");
	}

	const unsigned int AMT_SystemDefensePolicy::AntiSpoofingSupport() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AntiSpoofingSupport"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::AntiSpoofingSupport(const unsigned int value)
	{
		SetOrAddField("AntiSpoofingSupport", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::AntiSpoofingSupportExists() const
	{
		return ContainsField("AntiSpoofingSupport");
	}
	void AMT_SystemDefensePolicy::RemoveAntiSpoofingSupport()
	{
		RemoveField("AntiSpoofingSupport");
	}

	const vector<unsigned int> AMT_SystemDefensePolicy::FilterCreationHandles() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("FilterCreationHandles"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::FilterCreationHandles(const vector<unsigned int> &value)
	{
		SetOrAddField("FilterCreationHandles", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::FilterCreationHandlesExists() const
	{
		return ContainsField("FilterCreationHandles");
	}
	void AMT_SystemDefensePolicy::RemoveFilterCreationHandles()
	{
		RemoveField("FilterCreationHandles");
	}

	const bool AMT_SystemDefensePolicy::TxDefaultDrop() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("TxDefaultDrop"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::TxDefaultDrop(const bool value)
	{
		SetOrAddField("TxDefaultDrop", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::TxDefaultDropExists() const
	{
		return ContainsField("TxDefaultDrop");
	}
	void AMT_SystemDefensePolicy::RemoveTxDefaultDrop()
	{
		RemoveField("TxDefaultDrop");
	}

	const bool AMT_SystemDefensePolicy::TxDefaultMatchEvent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("TxDefaultMatchEvent"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::TxDefaultMatchEvent(const bool value)
	{
		SetOrAddField("TxDefaultMatchEvent", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::TxDefaultMatchEventExists() const
	{
		return ContainsField("TxDefaultMatchEvent");
	}
	void AMT_SystemDefensePolicy::RemoveTxDefaultMatchEvent()
	{
		RemoveField("TxDefaultMatchEvent");
	}

	const bool AMT_SystemDefensePolicy::TxDefaultCount() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("TxDefaultCount"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::TxDefaultCount(const bool value)
	{
		SetOrAddField("TxDefaultCount", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::TxDefaultCountExists() const
	{
		return ContainsField("TxDefaultCount");
	}
	void AMT_SystemDefensePolicy::RemoveTxDefaultCount()
	{
		RemoveField("TxDefaultCount");
	}

	const bool AMT_SystemDefensePolicy::RxDefaultDrop() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RxDefaultDrop"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::RxDefaultDrop(const bool value)
	{
		SetOrAddField("RxDefaultDrop", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::RxDefaultDropExists() const
	{
		return ContainsField("RxDefaultDrop");
	}
	void AMT_SystemDefensePolicy::RemoveRxDefaultDrop()
	{
		RemoveField("RxDefaultDrop");
	}

	const bool AMT_SystemDefensePolicy::RxDefaultMatchEvent() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RxDefaultMatchEvent"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::RxDefaultMatchEvent(const bool value)
	{
		SetOrAddField("RxDefaultMatchEvent", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::RxDefaultMatchEventExists() const
	{
		return ContainsField("RxDefaultMatchEvent");
	}
	void AMT_SystemDefensePolicy::RemoveRxDefaultMatchEvent()
	{
		RemoveField("RxDefaultMatchEvent");
	}

	const bool AMT_SystemDefensePolicy::RxDefaultCount() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RxDefaultCount"), ret);
		return ret;
	}
	void AMT_SystemDefensePolicy::RxDefaultCount(const bool value)
	{
		SetOrAddField("RxDefaultCount", TypeConverter::TypeToString(value));
	}
	bool AMT_SystemDefensePolicy::RxDefaultCountExists() const
	{
		return ContainsField("RxDefaultCount");
	}
	void AMT_SystemDefensePolicy::RemoveRxDefaultCount()
	{
		RemoveField("RxDefaultCount");
	}

	CimBase *AMT_SystemDefensePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_SystemDefensePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SystemDefensePolicy>(object);
		}
		else
		{
			ret = new AMT_SystemDefensePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SystemDefensePolicy> > AMT_SystemDefensePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SystemDefensePolicy>(client, keys);
	}

	void AMT_SystemDefensePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SystemDefensePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const unsigned int AMT_SystemDefensePolicy::GetTimeout_OUTPUT::Timeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Timeout"), ret);
		return ret;
	}
	bool AMT_SystemDefensePolicy::GetTimeout_OUTPUT::TimeoutExists() const
	{
		return ContainsField("Timeout");
	}
	unsigned int AMT_SystemDefensePolicy::GetTimeout(GetTimeout_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetTimeout", input, output);
	}
	const CimFieldAttribute AMT_SystemDefensePolicy::SetTimeout_INPUT::_metadata[] = {
		{"Timeout", false, true },
	};
	void AMT_SystemDefensePolicy::SetTimeout_INPUT::Timeout(const unsigned int value)
	{
		SetOrAddField("Timeout", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_SystemDefensePolicy::SetTimeout_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_SystemDefensePolicy::SetTimeout(const SetTimeout_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetTimeout", input, output);
	}
	const CimFieldAttribute AMT_SystemDefensePolicy::UpdateStatistics_INPUT::_metadata[] = {
		{"NetworkInterface", false, true },
		{"ResetOnRead", false, true },
	};
	void AMT_SystemDefensePolicy::UpdateStatistics_INPUT::NetworkInterface(const CimReference &value)
	{
		SetOrAddField("NetworkInterface", TypeConverter::TypeToString(value));
	}
	void AMT_SystemDefensePolicy::UpdateStatistics_INPUT::ResetOnRead(const bool value)
	{
		SetOrAddField("ResetOnRead", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_SystemDefensePolicy::UpdateStatistics_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_SystemDefensePolicy::UpdateStatistics(const UpdateStatistics_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UpdateStatistics", input, output);
	}
	const string AMT_SystemDefensePolicy::CLASS_NAME = "AMT_SystemDefensePolicy";
	const string AMT_SystemDefensePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefensePolicy";
	const string AMT_SystemDefensePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SystemDefensePolicy";
	const string AMT_SystemDefensePolicy::CLASS_NS_PREFIX = "ASy636";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SystemDefensePolicy::_classMetaData;
}
}
}
}
