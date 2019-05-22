//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuditPolicyRule.cpp
//
//  Contents:   Represents event policies.
//
//              This file was automatically generated from AMT_AuditPolicyRule.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AuditPolicyRule.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AuditPolicyRule::_metadata[] = {
		{"AuditApplicationEventID", false, true, false },
		{"PolicyType", false, true, false },
	};
	// class fields
	const vector<unsigned int> AMT_AuditPolicyRule::AuditApplicationEventID() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("AuditApplicationEventID"), ret);
		return ret;
	}
	void AMT_AuditPolicyRule::AuditApplicationEventID(const vector<unsigned int> &value)
	{
		SetOrAddField("AuditApplicationEventID", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditPolicyRule::AuditApplicationEventIDExists() const
	{
		return ContainsField("AuditApplicationEventID");
	}
	void AMT_AuditPolicyRule::RemoveAuditApplicationEventID()
	{
		RemoveField("AuditApplicationEventID");
	}

	const vector<unsigned int> AMT_AuditPolicyRule::PolicyType() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("PolicyType"), ret);
		return ret;
	}
	void AMT_AuditPolicyRule::PolicyType(const vector<unsigned int> &value)
	{
		SetOrAddField("PolicyType", TypeConverter::TypeToString(value));
	}
	bool AMT_AuditPolicyRule::PolicyTypeExists() const
	{
		return ContainsField("PolicyType");
	}
	void AMT_AuditPolicyRule::RemovePolicyType()
	{
		RemoveField("PolicyType");
	}

	CimBase *AMT_AuditPolicyRule::CreateFromCimObject(const CimObject &object)
	{
		AMT_AuditPolicyRule *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AuditPolicyRule>(object);
		}
		else
		{
			ret = new AMT_AuditPolicyRule(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AuditPolicyRule> > AMT_AuditPolicyRule::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AuditPolicyRule>(client, keys);
	}

	void AMT_AuditPolicyRule::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AuditPolicyRule::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_AuditPolicyRule::SetAuditPolicy_INPUT::_metadata[] = {
		{"Enable", false, true },
		{"AuditedAppID", false, true },
		{"EventID", false, true },
		{"PolicyType", false, false },
	};
	void AMT_AuditPolicyRule::SetAuditPolicy_INPUT::Enable(const bool value)
	{
		SetOrAddField("Enable", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicy_INPUT::AuditedAppID(const unsigned short value)
	{
		SetOrAddField("AuditedAppID", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicy_INPUT::EventID(const unsigned short value)
	{
		SetOrAddField("EventID", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicy_INPUT::PolicyType(const unsigned int value)
	{
		SetOrAddField("PolicyType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditPolicyRule::SetAuditPolicy_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_AuditPolicyRule::SetAuditPolicy(const SetAuditPolicy_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetAuditPolicy", input, output);
	}
	const CimFieldAttribute AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::_metadata[] = {
		{"Enable", false, true },
		{"AuditedAppID", false, true },
		{"EventID", false, true },
		{"PolicyType", false, true },
	};
	void AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::Enable(const vector<bool> &value)
	{
		SetOrAddField("Enable", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::AuditedAppID(const vector<unsigned short> &value)
	{
		SetOrAddField("AuditedAppID", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::EventID(const vector<unsigned short> &value)
	{
		SetOrAddField("EventID", TypeConverter::TypeToString(value));
	}
	void AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::PolicyType(const vector<unsigned int> &value)
	{
		SetOrAddField("PolicyType", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuditPolicyRule::SetAuditPolicyBulk_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_AuditPolicyRule::SetAuditPolicyBulk(const SetAuditPolicyBulk_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetAuditPolicyBulk", input, output);
	}
	const string AMT_AuditPolicyRule::CLASS_NAME = "AMT_AuditPolicyRule";
	const string AMT_AuditPolicyRule::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuditPolicyRule";
	const string AMT_AuditPolicyRule::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuditPolicyRule";
	const string AMT_AuditPolicyRule::CLASS_NS_PREFIX = "AAu906";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AuditPolicyRule::_classMetaData;
}
}
}
}
