//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_IEEE8021xSettings.cpp
//
//  Contents:   
//
//              This file was automatically generated from IPS_IEEE8021xSettings.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_IEEE8021xSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_IEEE8021xSettings::_metadata[] = {
		{"PxeTimeout", false, false, false },
		{"AvailableInS0", false, false, false },
		{"Enabled", false, true, false },
	};
	// class fields
	const unsigned int IPS_IEEE8021xSettings::PxeTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PxeTimeout"), ret);
		return ret;
	}
	void IPS_IEEE8021xSettings::PxeTimeout(const unsigned int value)
	{
		SetOrAddField("PxeTimeout", TypeConverter::TypeToString(value));
	}
	bool IPS_IEEE8021xSettings::PxeTimeoutExists() const
	{
		return ContainsField("PxeTimeout");
	}
	void IPS_IEEE8021xSettings::RemovePxeTimeout()
	{
		RemoveField("PxeTimeout");
	}

	const bool IPS_IEEE8021xSettings::AvailableInS0() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("AvailableInS0"), ret);
		return ret;
	}
	void IPS_IEEE8021xSettings::AvailableInS0(const bool value)
	{
		SetOrAddField("AvailableInS0", TypeConverter::TypeToString(value));
	}
	bool IPS_IEEE8021xSettings::AvailableInS0Exists() const
	{
		return ContainsField("AvailableInS0");
	}
	void IPS_IEEE8021xSettings::RemoveAvailableInS0()
	{
		RemoveField("AvailableInS0");
	}

	const unsigned int IPS_IEEE8021xSettings::Enabled() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void IPS_IEEE8021xSettings::Enabled(const unsigned int value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool IPS_IEEE8021xSettings::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void IPS_IEEE8021xSettings::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	CimBase *IPS_IEEE8021xSettings::CreateFromCimObject(const CimObject &object)
	{
		IPS_IEEE8021xSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_IEEE8021xSettings>(object);
		}
		else
		{
			ret = new IPS_IEEE8021xSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_IEEE8021xSettings> > IPS_IEEE8021xSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_IEEE8021xSettings>(client, keys);
	}

	void IPS_IEEE8021xSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_IEEE8021xSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_IEEE8021xSettings::SetCertificates_INPUT::_metadata[] = {
		{"ServerCertificateIssuer", false, false },
		{"ClientCertificate", false, false },
	};
	void IPS_IEEE8021xSettings::SetCertificates_INPUT::ServerCertificateIssuer(const CimReference &value)
	{
		SetOrAddField("ServerCertificateIssuer", TypeConverter::TypeToString(value));
	}
	void IPS_IEEE8021xSettings::SetCertificates_INPUT::ClientCertificate(const CimReference &value)
	{
		SetOrAddField("ClientCertificate", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_IEEE8021xSettings::SetCertificates_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int IPS_IEEE8021xSettings::SetCertificates(const SetCertificates_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetCertificates", input, output);
	}
	const string IPS_IEEE8021xSettings::CLASS_NAME = "IPS_IEEE8021xSettings";
	const string IPS_IEEE8021xSettings::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IEEE8021xSettings";
	const string IPS_IEEE8021xSettings::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_IEEE8021xSettings";
	const string IPS_IEEE8021xSettings::CLASS_NS_PREFIX = "AIE867";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_IEEE8021xSettings::_classMetaData;
}
}
}
}
