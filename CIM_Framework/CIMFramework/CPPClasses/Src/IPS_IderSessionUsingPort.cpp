//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_IderSessionUsingPort.cpp
//
//  Contents:   The IPS_IderSessionUsingPort is an association between the AMT_RedirectionService that manages the IDER session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_IderSessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_IderSessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_IderSessionUsingPort::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *IPS_IderSessionUsingPort::CreateFromCimObject(const CimObject &object)
	{
		IPS_IderSessionUsingPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_IderSessionUsingPort>(object);
		}
		else
		{
			ret = new IPS_IderSessionUsingPort(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_IderSessionUsingPort> > IPS_IderSessionUsingPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_IderSessionUsingPort>(client, keys);
	}

	void IPS_IderSessionUsingPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_IderSessionUsingPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_IderSessionUsingPort::CLASS_NAME = "IPS_IderSessionUsingPort";
	const string IPS_IderSessionUsingPort::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IderSessionUsingPort";
	const string IPS_IderSessionUsingPort::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IderSessionUsingPort";
	const string IPS_IderSessionUsingPort::CLASS_NS_PREFIX = "AId770";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_IderSessionUsingPort::_classMetaData;
}
}
}
}
