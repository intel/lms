//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HTTPProxyService.cpp
//
//  Contents:   Represents the HTTP Proxy Service.
//
//              This file was automatically generated from IPS_HTTPProxyService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_HTTPProxyService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_HTTPProxyService::_metadata[] = {
		{"SyncEnabled", false, false, false },
	};
	// class fields
	const bool IPS_HTTPProxyService::SyncEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SyncEnabled"), ret);
		return ret;
	}
	void IPS_HTTPProxyService::SyncEnabled(const bool value)
	{
		SetOrAddField("SyncEnabled", TypeConverter::TypeToString(value));
	}
	bool IPS_HTTPProxyService::SyncEnabledExists() const
	{
		return ContainsField("SyncEnabled");
	}
	void IPS_HTTPProxyService::RemoveSyncEnabled()
	{
		RemoveField("SyncEnabled");
	}

	CimBase *IPS_HTTPProxyService::CreateFromCimObject(const CimObject &object)
	{
		IPS_HTTPProxyService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_HTTPProxyService>(object);
		}
		else
		{
			ret = new IPS_HTTPProxyService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_HTTPProxyService> > IPS_HTTPProxyService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_HTTPProxyService>(client, keys);
	}

	void IPS_HTTPProxyService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_HTTPProxyService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::_metadata[] = {
		{"AccessInfo", false, true },
		{"InfoFormat", false, true },
		{"Port", false, true },
		{"NetworkDnsSuffix", false, true },
	};
	void IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::AccessInfo(const string &value)
	{
		SetOrAddField("AccessInfo", value);
	}
	void IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::InfoFormat(const unsigned short value)
	{
		SetOrAddField("InfoFormat", TypeConverter::TypeToString(value));
	}
	void IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::Port(const unsigned short value)
	{
		SetOrAddField("Port", TypeConverter::TypeToString(value));
	}
	void IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::NetworkDnsSuffix(const string &value)
	{
		SetOrAddField("NetworkDnsSuffix", value);
	}
	const VectorFieldData IPS_HTTPProxyService::AddProxyAccessPoint_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const CimReference IPS_HTTPProxyService::AddProxyAccessPoint_OUTPUT::ProxyAccessPoint() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ProxyAccessPoint"), ret);
		return ret;
	}
	bool IPS_HTTPProxyService::AddProxyAccessPoint_OUTPUT::ProxyAccessPointExists() const
	{
		return ContainsField("ProxyAccessPoint");
	}
	unsigned int IPS_HTTPProxyService::AddProxyAccessPoint(const AddProxyAccessPoint_INPUT &input, AddProxyAccessPoint_OUTPUT &output)
	{
		return Invoke("AddProxyAccessPoint", input, output);
	}
	const string IPS_HTTPProxyService::CLASS_NAME = "IPS_HTTPProxyService";
	const string IPS_HTTPProxyService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HTTPProxyService";
	const string IPS_HTTPProxyService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HTTPProxyService";
	const string IPS_HTTPProxyService::CLASS_NS_PREFIX = "AHT102";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_HTTPProxyService::_classMetaData;
}
}
}
}
