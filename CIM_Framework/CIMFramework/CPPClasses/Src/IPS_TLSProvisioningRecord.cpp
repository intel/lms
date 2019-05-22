//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_TLSProvisioningRecord.cpp
//
//  Contents:   The IPS_TLSProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a TLS provisioning method - PSK or PKI
//
//              This file was automatically generated from IPS_TLSProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_TLSProvisioningRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_TLSProvisioningRecord::_metadata[] = {
		{"ProvisioningTLSMode", false, false, false },
		{"SecureDNS", false, false, false },
		{"HostInitiated", false, false, false },
		{"ProvServerFQDN", false, false, false },
		{"SelectedHashType", false, false, false },
		{"SelectedHashData", false, false, false },
		{"CaCertificateSerials", false, false, false },
		{"AdditionalCaSerialNums", false, false, false },
		{"HashIsOemDefault", false, false, false },
		{"IsTimeValid", false, false, false },
		{"ProvServerIP", false, false, false },
	};
	// class fields
	const unsigned char IPS_TLSProvisioningRecord::ProvisioningTLSMode() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("ProvisioningTLSMode"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::ProvisioningTLSMode(const unsigned char &value)
	{
		SetOrAddField("ProvisioningTLSMode", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::ProvisioningTLSModeExists() const
	{
		return ContainsField("ProvisioningTLSMode");
	}
	void IPS_TLSProvisioningRecord::RemoveProvisioningTLSMode()
	{
		RemoveField("ProvisioningTLSMode");
	}

	const bool IPS_TLSProvisioningRecord::SecureDNS() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SecureDNS"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::SecureDNS(const bool value)
	{
		SetOrAddField("SecureDNS", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::SecureDNSExists() const
	{
		return ContainsField("SecureDNS");
	}
	void IPS_TLSProvisioningRecord::RemoveSecureDNS()
	{
		RemoveField("SecureDNS");
	}

	const bool IPS_TLSProvisioningRecord::HostInitiated() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HostInitiated"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::HostInitiated(const bool value)
	{
		SetOrAddField("HostInitiated", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::HostInitiatedExists() const
	{
		return ContainsField("HostInitiated");
	}
	void IPS_TLSProvisioningRecord::RemoveHostInitiated()
	{
		RemoveField("HostInitiated");
	}

	const string IPS_TLSProvisioningRecord::ProvServerFQDN() const
	{
		return GetField("ProvServerFQDN")[0];
	}
	void IPS_TLSProvisioningRecord::ProvServerFQDN(const string &value)
	{
		SetOrAddField("ProvServerFQDN", value);
	}
	bool IPS_TLSProvisioningRecord::ProvServerFQDNExists() const
	{
		return ContainsField("ProvServerFQDN");
	}
	void IPS_TLSProvisioningRecord::RemoveProvServerFQDN()
	{
		RemoveField("ProvServerFQDN");
	}

	const unsigned char IPS_TLSProvisioningRecord::SelectedHashType() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SelectedHashType"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::SelectedHashType(const unsigned char &value)
	{
		SetOrAddField("SelectedHashType", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::SelectedHashTypeExists() const
	{
		return ContainsField("SelectedHashType");
	}
	void IPS_TLSProvisioningRecord::RemoveSelectedHashType()
	{
		RemoveField("SelectedHashType");
	}

	const Base64 IPS_TLSProvisioningRecord::SelectedHashData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("SelectedHashData"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::SelectedHashData(const Base64 &value)
	{
		SetOrAddField("SelectedHashData", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::SelectedHashDataExists() const
	{
		return ContainsField("SelectedHashData");
	}
	void IPS_TLSProvisioningRecord::RemoveSelectedHashData()
	{
		RemoveField("SelectedHashData");
	}

	const HexBinary IPS_TLSProvisioningRecord::CaCertificateSerials() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("CaCertificateSerials"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::CaCertificateSerials(const HexBinary &value)
	{
		SetOrAddField("CaCertificateSerials", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::CaCertificateSerialsExists() const
	{
		return ContainsField("CaCertificateSerials");
	}
	void IPS_TLSProvisioningRecord::RemoveCaCertificateSerials()
	{
		RemoveField("CaCertificateSerials");
	}

	const bool IPS_TLSProvisioningRecord::AdditionalCaSerialNums() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AdditionalCaSerialNums"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::AdditionalCaSerialNums(const bool value)
	{
		SetOrAddField("AdditionalCaSerialNums", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::AdditionalCaSerialNumsExists() const
	{
		return ContainsField("AdditionalCaSerialNums");
	}
	void IPS_TLSProvisioningRecord::RemoveAdditionalCaSerialNums()
	{
		RemoveField("AdditionalCaSerialNums");
	}

	const bool IPS_TLSProvisioningRecord::HashIsOemDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("HashIsOemDefault"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::HashIsOemDefault(const bool value)
	{
		SetOrAddField("HashIsOemDefault", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::HashIsOemDefaultExists() const
	{
		return ContainsField("HashIsOemDefault");
	}
	void IPS_TLSProvisioningRecord::RemoveHashIsOemDefault()
	{
		RemoveField("HashIsOemDefault");
	}

	const bool IPS_TLSProvisioningRecord::IsTimeValid() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsTimeValid"), ret);
		return ret;
	}
	void IPS_TLSProvisioningRecord::IsTimeValid(const bool value)
	{
		SetOrAddField("IsTimeValid", TypeConverter::TypeToString(value));
	}
	bool IPS_TLSProvisioningRecord::IsTimeValidExists() const
	{
		return ContainsField("IsTimeValid");
	}
	void IPS_TLSProvisioningRecord::RemoveIsTimeValid()
	{
		RemoveField("IsTimeValid");
	}

	const string IPS_TLSProvisioningRecord::ProvServerIP() const
	{
		return GetField("ProvServerIP")[0];
	}
	void IPS_TLSProvisioningRecord::ProvServerIP(const string &value)
	{
		SetOrAddField("ProvServerIP", value);
	}
	bool IPS_TLSProvisioningRecord::ProvServerIPExists() const
	{
		return ContainsField("ProvServerIP");
	}
	void IPS_TLSProvisioningRecord::RemoveProvServerIP()
	{
		RemoveField("ProvServerIP");
	}

	CimBase *IPS_TLSProvisioningRecord::CreateFromCimObject(const CimObject &object)
	{
		IPS_TLSProvisioningRecord *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_TLSProvisioningRecord>(object);
		}
		else
		{
			ret = new IPS_TLSProvisioningRecord(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_TLSProvisioningRecord> > IPS_TLSProvisioningRecord::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_TLSProvisioningRecord>(client, keys);
	}

	void IPS_TLSProvisioningRecord::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_TLSProvisioningRecord::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_TLSProvisioningRecord::CLASS_NAME = "IPS_TLSProvisioningRecord";
	const string IPS_TLSProvisioningRecord::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_TLSProvisioningRecord";
	const string IPS_TLSProvisioningRecord::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_TLSProvisioningRecord";
	const string IPS_TLSProvisioningRecord::CLASS_NS_PREFIX = "ATL270";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_TLSProvisioningRecord::_classMetaData;
}
}
}
}
