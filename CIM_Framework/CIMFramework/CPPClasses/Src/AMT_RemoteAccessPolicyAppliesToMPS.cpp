//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessPolicyAppliesToMPS.cpp
//
//  Contents:   This class associates a Management Presence Server with a Remote Access Policy rule. When a Policy Rule is triggered, the Intel(R) AMT subsystem will attempt to connect to the MpServers associated with the triggered policy in the order by which the associations were created. This order is indicated in the OrderOfAccess field where lower numbers indicate a higher priority.
//
//              This file was automatically generated from AMT_RemoteAccessPolicyAppliesToMPS.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_RemoteAccessPolicyAppliesToMPS.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_RemoteAccessPolicyAppliesToMPS::_metadata[] = {
		{"PolicySet", true, false, true },
		{"ManagedElement", true, false, true },
		{"OrderOfAccess", false, false, false },
		{"MpsType", false, false, false },
	};
	// class fields
	const unsigned short AMT_RemoteAccessPolicyAppliesToMPS::OrderOfAccess() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OrderOfAccess"), ret);
		return ret;
	}
	void AMT_RemoteAccessPolicyAppliesToMPS::OrderOfAccess(const unsigned short value)
	{
		SetOrAddField("OrderOfAccess", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessPolicyAppliesToMPS::OrderOfAccessExists() const
	{
		return ContainsField("OrderOfAccess");
	}
	void AMT_RemoteAccessPolicyAppliesToMPS::RemoveOrderOfAccess()
	{
		RemoveField("OrderOfAccess");
	}

	const unsigned short AMT_RemoteAccessPolicyAppliesToMPS::MpsType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MpsType"), ret);
		return ret;
	}
	void AMT_RemoteAccessPolicyAppliesToMPS::MpsType(const unsigned short value)
	{
		SetOrAddField("MpsType", TypeConverter::TypeToString(value));
	}
	bool AMT_RemoteAccessPolicyAppliesToMPS::MpsTypeExists() const
	{
		return ContainsField("MpsType");
	}
	void AMT_RemoteAccessPolicyAppliesToMPS::RemoveMpsType()
	{
		RemoveField("MpsType");
	}

	CimBase *AMT_RemoteAccessPolicyAppliesToMPS::CreateFromCimObject(const CimObject &object)
	{
		AMT_RemoteAccessPolicyAppliesToMPS *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_RemoteAccessPolicyAppliesToMPS>(object);
		}
		else
		{
			ret = new AMT_RemoteAccessPolicyAppliesToMPS(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_RemoteAccessPolicyAppliesToMPS> > AMT_RemoteAccessPolicyAppliesToMPS::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_RemoteAccessPolicyAppliesToMPS>(client, keys);
	}

	void AMT_RemoteAccessPolicyAppliesToMPS::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_RemoteAccessPolicyAppliesToMPS::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_RemoteAccessPolicyAppliesToMPS::CLASS_NAME = "AMT_RemoteAccessPolicyAppliesToMPS";
	const string AMT_RemoteAccessPolicyAppliesToMPS::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessPolicyAppliesToMPS";
	const string AMT_RemoteAccessPolicyAppliesToMPS::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_RemoteAccessPolicyAppliesToMPS";
	const string AMT_RemoteAccessPolicyAppliesToMPS::CLASS_NS_PREFIX = "ARe660";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_RemoteAccessPolicyAppliesToMPS::_classMetaData;
}
}
}
}
