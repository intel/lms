//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_SessionUsingPort.cpp
//
//  Contents:   The IPS_SessionUsingPort is an association between a service class that represents a management session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_SessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "IPS_SessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_SessionUsingPort::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *IPS_SessionUsingPort::CreateFromCimObject(const CimObject &object)
	{
		IPS_SessionUsingPort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_SessionUsingPort>(object);
		}
		else
		{
			ret = new IPS_SessionUsingPort(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_SessionUsingPort> > IPS_SessionUsingPort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_SessionUsingPort>(client, keys);
	}

	void IPS_SessionUsingPort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_SessionUsingPort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_SessionUsingPort::CLASS_NAME = "IPS_SessionUsingPort";
	const string IPS_SessionUsingPort::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SessionUsingPort";
	const string IPS_SessionUsingPort::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SessionUsingPort";
	const string IPS_SessionUsingPort::CLASS_NS_PREFIX = "ASe602";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_SessionUsingPort::_classMetaData;
}
}
}
}
