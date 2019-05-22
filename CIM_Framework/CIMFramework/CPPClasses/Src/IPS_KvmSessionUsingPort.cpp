//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_KvmSessionUsingPort.cpp
//
//  Contents:   The IPS_KvmSessionUsingPort is an association between the CIM_RedirectionService that manages the KVM session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_KvmSessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_KvmSessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_KvmSessionUsingPort::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *IPS_KvmSessionUsingPort::CreateFromCimObject(const CimObject &object)
	{
		IPS_KvmSessionUsingPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_KvmSessionUsingPort>(object);
		}
		else
		{
			ret = new IPS_KvmSessionUsingPort(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_KvmSessionUsingPort> > IPS_KvmSessionUsingPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_KvmSessionUsingPort>(client, keys);
	}

	void IPS_KvmSessionUsingPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_KvmSessionUsingPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_KvmSessionUsingPort::CLASS_NAME = "IPS_KvmSessionUsingPort";
	const string IPS_KvmSessionUsingPort::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_KvmSessionUsingPort";
	const string IPS_KvmSessionUsingPort::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_KvmSessionUsingPort";
	const string IPS_KvmSessionUsingPort::CLASS_NS_PREFIX = "AKv786";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_KvmSessionUsingPort::_classMetaData;
}
}
}
}
