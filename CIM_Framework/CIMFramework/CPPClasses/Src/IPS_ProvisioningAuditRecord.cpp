//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ProvisioningAuditRecord.cpp
//
//  Contents:   The IPS_ProvisioningAuditRecord provides information related to a single Intel (R) AMT provisioning occurrence
//
//              This file was automatically generated from IPS_ProvisioningAuditRecord.mof,  version: 6.1.0
//
//----------------------------------------------------------------------------
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_ProvisioningAuditRecord::_metadata[] = {
		{"CreationTimeStamp", false, false, false },
	};
	// class fields
	CimBase *IPS_ProvisioningAuditRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_ProvisioningAuditRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ProvisioningAuditRecord>(object);
		}
		else
		{
			ret = new IPS_ProvisioningAuditRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ProvisioningAuditRecord> > IPS_ProvisioningAuditRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ProvisioningAuditRecord>(client, keys);
	}

	void IPS_ProvisioningAuditRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ProvisioningAuditRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_ProvisioningAuditRecord::CLASS_NAME = "IPS_ProvisioningAuditRecord";
	const string IPS_ProvisioningAuditRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ProvisioningAuditRecord";
	const string IPS_ProvisioningAuditRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ProvisioningAuditRecord";
	const string IPS_ProvisioningAuditRecord::CLASS_NS_PREFIX = "APr764";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ProvisioningAuditRecord::_classMetaData;
}
}
}
}
