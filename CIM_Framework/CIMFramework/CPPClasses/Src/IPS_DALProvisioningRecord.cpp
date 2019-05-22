//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_DALProvisioningRecord.cpp
//
//  Contents:   The IPS_DALProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using DAL.
//
//              This file was automatically generated from IPS_DALProvisioningRecord.mof,  version: 12.0.0
//
//----------------------------------------------------------------------------
#include "IPS_DALProvisioningRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_DALProvisioningRecord::_metadata[] = {
		{"DALRecord", false, false, false },
	};
	// class fields
	const Base64 IPS_DALProvisioningRecord::DALRecord() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("DALRecord"), ret);
		return ret;
	}
	void IPS_DALProvisioningRecord::DALRecord(const Base64 &value)
	{
		SetOrAddField("DALRecord", TypeConverter::TypeToString(value));
	}
	bool IPS_DALProvisioningRecord::DALRecordExists() const
	{
		return ContainsField("DALRecord");
	}
	void IPS_DALProvisioningRecord::RemoveDALRecord()
	{
		RemoveField("DALRecord");
	}

	CimBase *IPS_DALProvisioningRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_DALProvisioningRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_DALProvisioningRecord>(object);
		}
		else
		{
			ret = new IPS_DALProvisioningRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_DALProvisioningRecord> > IPS_DALProvisioningRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_DALProvisioningRecord>(client, keys);
	}

	void IPS_DALProvisioningRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_DALProvisioningRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_DALProvisioningRecord::CLASS_NAME = "IPS_DALProvisioningRecord";
	const string IPS_DALProvisioningRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_DALProvisioningRecord";
	const string IPS_DALProvisioningRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_DALProvisioningRecord";
	const string IPS_DALProvisioningRecord::CLASS_NS_PREFIX = "ADA358";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_DALProvisioningRecord::_classMetaData;
}
}
}
}
