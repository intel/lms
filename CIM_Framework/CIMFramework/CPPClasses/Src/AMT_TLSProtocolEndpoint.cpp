//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSProtocolEndpoint.cpp
//
//  Contents:   A communication point from which data may be sent or received. ProtocolEndpoints link system/computer interfaces to LogicalNetworks.
//
//              This file was automatically generated from AMT_TLSProtocolEndpoint.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_TLSProtocolEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_TLSProtocolEndpoint::_metadata[] = {
		{"Role", false, false, false },
	};
	// class fields
	const unsigned char AMT_TLSProtocolEndpoint::Role() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Role"), ret);
		return ret;
	}
	void AMT_TLSProtocolEndpoint::Role(const unsigned char &value)
	{
		SetOrAddField("Role", TypeConverter::TypeToString(value));
	}
	bool AMT_TLSProtocolEndpoint::RoleExists() const
	{
		return ContainsField("Role");
	}
	void AMT_TLSProtocolEndpoint::RemoveRole()
	{
		RemoveField("Role");
	}

	CimBase *AMT_TLSProtocolEndpoint::CreateFromCimObject(const CimObject &object)
	{
		AMT_TLSProtocolEndpoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_TLSProtocolEndpoint>(object);
		}
		else
		{
			ret = new AMT_TLSProtocolEndpoint(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_TLSProtocolEndpoint> > AMT_TLSProtocolEndpoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_TLSProtocolEndpoint>(client, keys);
	}

	void AMT_TLSProtocolEndpoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_TLSProtocolEndpoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_TLSProtocolEndpoint::CLASS_NAME = "AMT_TLSProtocolEndpoint";
	const string AMT_TLSProtocolEndpoint::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSProtocolEndpoint";
	const string AMT_TLSProtocolEndpoint::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_TLSProtocolEndpoint";
	const string AMT_TLSProtocolEndpoint::CLASS_NS_PREFIX = "ATL847";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_TLSProtocolEndpoint::_classMetaData;
}
}
}
}
