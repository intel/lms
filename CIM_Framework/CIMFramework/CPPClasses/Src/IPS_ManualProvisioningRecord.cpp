//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ManualProvisioningRecord.cpp
//
//  Contents:   The IPS_ManualProvisioningRecord provides information related to a single Intel(R) AMT provisioning occurrence that was performed using a manual provisioning operation.
//
//              This file was automatically generated from IPS_ManualProvisioningRecord.mof,  version: 6.1.0
//
//----------------------------------------------------------------------------
#include "IPS_ManualProvisioningRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *IPS_ManualProvisioningRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_ManualProvisioningRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ManualProvisioningRecord>(object);
		}
		else
		{
			ret = new IPS_ManualProvisioningRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ManualProvisioningRecord> > IPS_ManualProvisioningRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ManualProvisioningRecord>(client, keys);
	}

	void IPS_ManualProvisioningRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ManualProvisioningRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_ManualProvisioningRecord::CLASS_NAME = "IPS_ManualProvisioningRecord";
	const string IPS_ManualProvisioningRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ManualProvisioningRecord";
	const string IPS_ManualProvisioningRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ManualProvisioningRecord";
	const string IPS_ManualProvisioningRecord::CLASS_NS_PREFIX = "AMa249";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ManualProvisioningRecord::_classMetaData;
}
}
}
}
