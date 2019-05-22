//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SNMPEventSubscriber.cpp
//
//  Contents:   Represents a SNMP-events subscriber in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_SNMPEventSubscriber.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_SNMPEventSubscriber.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_SNMPEventSubscriber::_metadata[] = {
		{"AccessInfo", false, true, false },
		{"PolicyID", false, true, false },
		{"CommunityString", false, false, false },
	};
	// class fields
	const unsigned char AMT_SNMPEventSubscriber::PolicyID() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("PolicyID"), ret);
		return ret;
	}
	void AMT_SNMPEventSubscriber::PolicyID(const unsigned char &value)
	{
		SetOrAddField("PolicyID", TypeConverter::TypeToString(value));
	}
	bool AMT_SNMPEventSubscriber::PolicyIDExists() const
	{
		return ContainsField("PolicyID");
	}
	void AMT_SNMPEventSubscriber::RemovePolicyID()
	{
		RemoveField("PolicyID");
	}

	const string AMT_SNMPEventSubscriber::CommunityString() const
	{
		return GetField("CommunityString")[0];
	}
	void AMT_SNMPEventSubscriber::CommunityString(const string &value)
	{
		SetOrAddField("CommunityString", value);
	}
	bool AMT_SNMPEventSubscriber::CommunityStringExists() const
	{
		return ContainsField("CommunityString");
	}
	void AMT_SNMPEventSubscriber::RemoveCommunityString()
	{
		RemoveField("CommunityString");
	}

	CimBase *AMT_SNMPEventSubscriber::CreateFromCimObject(const CimObject &object)
	{
		AMT_SNMPEventSubscriber *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_SNMPEventSubscriber>(object);
		}
		else
		{
			ret = new AMT_SNMPEventSubscriber(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_SNMPEventSubscriber> > AMT_SNMPEventSubscriber::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_SNMPEventSubscriber>(client, keys);
	}

	void AMT_SNMPEventSubscriber::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_SNMPEventSubscriber::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_SNMPEventSubscriber::CLASS_NAME = "AMT_SNMPEventSubscriber";
	const string AMT_SNMPEventSubscriber::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SNMPEventSubscriber";
	const string AMT_SNMPEventSubscriber::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_SNMPEventSubscriber";
	const string AMT_SNMPEventSubscriber::CLASS_NS_PREFIX = "ASN309";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_SNMPEventSubscriber::_classMetaData;
}
}
}
}
