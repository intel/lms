//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ManagementPresenceRemoteSAP.cpp
//
//  Contents:   Represents a Management Presence Remote Service Access Point (or an MPS) to be accessed by the Intel(R) AMT subsystem from remote.
//
//              This file was automatically generated from AMT_ManagementPresenceRemoteSAP.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ManagementPresenceRemoteSAP.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_ManagementPresenceRemoteSAP::_metadata[] = {
		{"Port", false, true, false },
		{"CN", false, false, false },
	};
	// class fields
	const unsigned short AMT_ManagementPresenceRemoteSAP::Port() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Port"), ret);
		return ret;
	}
	void AMT_ManagementPresenceRemoteSAP::Port(const unsigned short value)
	{
		SetOrAddField("Port", TypeConverter::TypeToString(value));
	}
	bool AMT_ManagementPresenceRemoteSAP::PortExists() const
	{
		return ContainsField("Port");
	}
	void AMT_ManagementPresenceRemoteSAP::RemovePort()
	{
		RemoveField("Port");
	}

	const string AMT_ManagementPresenceRemoteSAP::CN() const
	{
		return GetField("CN")[0];
	}
	void AMT_ManagementPresenceRemoteSAP::CN(const string &value)
	{
		SetOrAddField("CN", value);
	}
	bool AMT_ManagementPresenceRemoteSAP::CNExists() const
	{
		return ContainsField("CN");
	}
	void AMT_ManagementPresenceRemoteSAP::RemoveCN()
	{
		RemoveField("CN");
	}

	CimBase *AMT_ManagementPresenceRemoteSAP::CreateFromCimObject(const CimObject &object)
	{
		AMT_ManagementPresenceRemoteSAP *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ManagementPresenceRemoteSAP>(object);
		}
		else
		{
			ret = new AMT_ManagementPresenceRemoteSAP(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ManagementPresenceRemoteSAP> > AMT_ManagementPresenceRemoteSAP::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ManagementPresenceRemoteSAP>(client, keys);
	}

	void AMT_ManagementPresenceRemoteSAP::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ManagementPresenceRemoteSAP::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_ManagementPresenceRemoteSAP::CLASS_NAME = "AMT_ManagementPresenceRemoteSAP";
	const string AMT_ManagementPresenceRemoteSAP::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ManagementPresenceRemoteSAP";
	const string AMT_ManagementPresenceRemoteSAP::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ManagementPresenceRemoteSAP";
	const string AMT_ManagementPresenceRemoteSAP::CLASS_NS_PREFIX = "AMa935";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ManagementPresenceRemoteSAP::_classMetaData;
}
}
}
}
