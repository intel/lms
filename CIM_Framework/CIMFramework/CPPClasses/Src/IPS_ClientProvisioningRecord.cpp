//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ClientProvisioningRecord.cpp
//
//  Contents:   The IPS_ClientProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a host based provisioning operation in client control mode.
//
//              This file was automatically generated from IPS_ClientProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_ClientProvisioningRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_ClientProvisioningRecord::_metadata[] = {
		{"HashAlgorithm", false, false, false },
		{"ProvCertificateHash", false, false, false },
	};
	// class fields
	const unsigned char IPS_ClientProvisioningRecord::HashAlgorithm() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HashAlgorithm"), ret);
		return ret;
	}
	void IPS_ClientProvisioningRecord::HashAlgorithm(const unsigned char &value)
	{
		SetOrAddField("HashAlgorithm", TypeConverter::TypeToString(value));
	}
	bool IPS_ClientProvisioningRecord::HashAlgorithmExists() const
	{
		return ContainsField("HashAlgorithm");
	}
	void IPS_ClientProvisioningRecord::RemoveHashAlgorithm()
	{
		RemoveField("HashAlgorithm");
	}

	const Base64 IPS_ClientProvisioningRecord::ProvCertificateHash() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ProvCertificateHash"), ret);
		return ret;
	}
	void IPS_ClientProvisioningRecord::ProvCertificateHash(const Base64 &value)
	{
		SetOrAddField("ProvCertificateHash", TypeConverter::TypeToString(value));
	}
	bool IPS_ClientProvisioningRecord::ProvCertificateHashExists() const
	{
		return ContainsField("ProvCertificateHash");
	}
	void IPS_ClientProvisioningRecord::RemoveProvCertificateHash()
	{
		RemoveField("ProvCertificateHash");
	}

	CimBase *IPS_ClientProvisioningRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_ClientProvisioningRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ClientProvisioningRecord>(object);
		}
		else
		{
			ret = new IPS_ClientProvisioningRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ClientProvisioningRecord> > IPS_ClientProvisioningRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ClientProvisioningRecord>(client, keys);
	}

	void IPS_ClientProvisioningRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ClientProvisioningRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_ClientProvisioningRecord::CLASS_NAME = "IPS_ClientProvisioningRecord";
	const string IPS_ClientProvisioningRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ClientProvisioningRecord";
	const string IPS_ClientProvisioningRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ClientProvisioningRecord";
	const string IPS_ClientProvisioningRecord::CLASS_NS_PREFIX = "ACl76";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ClientProvisioningRecord::_classMetaData;
}
}
}
}
