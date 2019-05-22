//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_SolSessionUsingPort.cpp
//
//  Contents:   The IPS_SolSessionUsingPort is an association between the AMT_RedirectionService that manages the SOL session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_SolSessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_SolSessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_SolSessionUsingPort::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *IPS_SolSessionUsingPort::CreateFromCimObject(const CimObject &object)
	{
		IPS_SolSessionUsingPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_SolSessionUsingPort>(object);
		}
		else
		{
			ret = new IPS_SolSessionUsingPort(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_SolSessionUsingPort> > IPS_SolSessionUsingPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_SolSessionUsingPort>(client, keys);
	}

	void IPS_SolSessionUsingPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_SolSessionUsingPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_SolSessionUsingPort::CLASS_NAME = "IPS_SolSessionUsingPort";
	const string IPS_SolSessionUsingPort::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SolSessionUsingPort";
	const string IPS_SolSessionUsingPort::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SolSessionUsingPort";
	const string IPS_SolSessionUsingPort::CLASS_NS_PREFIX = "ASo316";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_SolSessionUsingPort::_classMetaData;
}
}
}
}
