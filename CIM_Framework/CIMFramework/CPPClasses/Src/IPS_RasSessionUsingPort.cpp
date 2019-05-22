//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_RasSessionUsingPort.cpp
//
//  Contents:   The IPS_RasSessionUsingPort is an association between the CIM_RemoteAccessService that manages the CIRA session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_RasSessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_RasSessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_RasSessionUsingPort::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *IPS_RasSessionUsingPort::CreateFromCimObject(const CimObject &object)
	{
		IPS_RasSessionUsingPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_RasSessionUsingPort>(object);
		}
		else
		{
			ret = new IPS_RasSessionUsingPort(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_RasSessionUsingPort> > IPS_RasSessionUsingPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_RasSessionUsingPort>(client, keys);
	}

	void IPS_RasSessionUsingPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_RasSessionUsingPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_RasSessionUsingPort::CLASS_NAME = "IPS_RasSessionUsingPort";
	const string IPS_RasSessionUsingPort::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_RasSessionUsingPort";
	const string IPS_RasSessionUsingPort::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_RasSessionUsingPort";
	const string IPS_RasSessionUsingPort::CLASS_NS_PREFIX = "ARa232";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_RasSessionUsingPort::_classMetaData;
}
}
}
}
