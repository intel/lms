//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_AdminProvisioningRecord.cpp
//
//  Contents:   The IPS_AdminProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a Admin  control mode
//
//              This file was automatically generated from IPS_AdminProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_AdminProvisioningRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_AdminProvisioningRecord::_metadata[] = {
		{"SecureDNS", false, false, false },
		{"CertificateCN", false, false, false },
		{"SelectedHashType", false, false, false },
		{"SelectedHashData", false, false, false },
		{"CaCertificateSerials", false, false, false },
		{"AdditionalCaSerialNums", false, false, false },
		{"HashIsOemDefault", false, false, false },
		{"EHBCState", false, false, false },
	};
	// class fields
	const bool IPS_AdminProvisioningRecord::SecureDNS() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SecureDNS"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::SecureDNS(const bool value)
	{
		SetOrAddField("SecureDNS", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::SecureDNSExists() const
	{
		return ContainsField("SecureDNS");
	}
	void IPS_AdminProvisioningRecord::RemoveSecureDNS()
	{
		RemoveField("SecureDNS");
	}

	const string IPS_AdminProvisioningRecord::CertificateCN() const
	{
		return GetField("CertificateCN")[0];
	}
	void IPS_AdminProvisioningRecord::CertificateCN(const string &value)
	{
		SetOrAddField("CertificateCN", value);
	}
	bool IPS_AdminProvisioningRecord::CertificateCNExists() const
	{
		return ContainsField("CertificateCN");
	}
	void IPS_AdminProvisioningRecord::RemoveCertificateCN()
	{
		RemoveField("CertificateCN");
	}

	const unsigned char IPS_AdminProvisioningRecord::SelectedHashType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SelectedHashType"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::SelectedHashType(const unsigned char &value)
	{
		SetOrAddField("SelectedHashType", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::SelectedHashTypeExists() const
	{
		return ContainsField("SelectedHashType");
	}
	void IPS_AdminProvisioningRecord::RemoveSelectedHashType()
	{
		RemoveField("SelectedHashType");
	}

	const Base64 IPS_AdminProvisioningRecord::SelectedHashData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("SelectedHashData"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::SelectedHashData(const Base64 &value)
	{
		SetOrAddField("SelectedHashData", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::SelectedHashDataExists() const
	{
		return ContainsField("SelectedHashData");
	}
	void IPS_AdminProvisioningRecord::RemoveSelectedHashData()
	{
		RemoveField("SelectedHashData");
	}

	const HexBinary IPS_AdminProvisioningRecord::CaCertificateSerials() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("CaCertificateSerials"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::CaCertificateSerials(const HexBinary &value)
	{
		SetOrAddField("CaCertificateSerials", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::CaCertificateSerialsExists() const
	{
		return ContainsField("CaCertificateSerials");
	}
	void IPS_AdminProvisioningRecord::RemoveCaCertificateSerials()
	{
		RemoveField("CaCertificateSerials");
	}

	const bool IPS_AdminProvisioningRecord::AdditionalCaSerialNums() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AdditionalCaSerialNums"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::AdditionalCaSerialNums(const bool value)
	{
		SetOrAddField("AdditionalCaSerialNums", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::AdditionalCaSerialNumsExists() const
	{
		return ContainsField("AdditionalCaSerialNums");
	}
	void IPS_AdminProvisioningRecord::RemoveAdditionalCaSerialNums()
	{
		RemoveField("AdditionalCaSerialNums");
	}

	const bool IPS_AdminProvisioningRecord::HashIsOemDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HashIsOemDefault"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::HashIsOemDefault(const bool value)
	{
		SetOrAddField("HashIsOemDefault", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::HashIsOemDefaultExists() const
	{
		return ContainsField("HashIsOemDefault");
	}
	void IPS_AdminProvisioningRecord::RemoveHashIsOemDefault()
	{
		RemoveField("HashIsOemDefault");
	}

	const unsigned char IPS_AdminProvisioningRecord::EHBCState() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("EHBCState"), ret);
		return ret;
	}
	void IPS_AdminProvisioningRecord::EHBCState(const unsigned char &value)
	{
		SetOrAddField("EHBCState", TypeConverter::TypeToString(value));
	}
	bool IPS_AdminProvisioningRecord::EHBCStateExists() const
	{
		return ContainsField("EHBCState");
	}
	void IPS_AdminProvisioningRecord::RemoveEHBCState()
	{
		RemoveField("EHBCState");
	}

	CimBase *IPS_AdminProvisioningRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_AdminProvisioningRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_AdminProvisioningRecord>(object);
		}
		else
		{
			ret = new IPS_AdminProvisioningRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_AdminProvisioningRecord> > IPS_AdminProvisioningRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_AdminProvisioningRecord>(client, keys);
	}

	void IPS_AdminProvisioningRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_AdminProvisioningRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_AdminProvisioningRecord::CLASS_NAME = "IPS_AdminProvisioningRecord";
	const string IPS_AdminProvisioningRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_AdminProvisioningRecord";
	const string IPS_AdminProvisioningRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_AdminProvisioningRecord";
	const string IPS_AdminProvisioningRecord::CLASS_NS_PREFIX = "AAd382";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_AdminProvisioningRecord::_classMetaData;
}
}
}
}
