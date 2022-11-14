//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HTTPProxyAccessPoint.cpp
//
//  Contents:   The IPS_HTTPProxyAccessPoint class represents the set of proxy settings that should be used by AMT when connecting through a HTTP proxy.
//
//              This file was automatically generated from IPS_HTTPProxyAccessPoint.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_HTTPProxyAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_HTTPProxyAccessPoint::_metadata[] = {
		{"Type", false, true, false },
		{"Port", false, true, false },
		{"NetworkDnsSuffix", false, true, false },
		{"Priority", false, true, false },
	};
	// class fields
	const unsigned char IPS_HTTPProxyAccessPoint::Type() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("Type"), ret);
		return ret;
	}
	void IPS_HTTPProxyAccessPoint::Type(const unsigned char &value)
	{
		SetOrAddField("Type", TypeConverter::TypeToString(value));
	}
	bool IPS_HTTPProxyAccessPoint::TypeExists() const
	{
		return ContainsField("Type");
	}
	void IPS_HTTPProxyAccessPoint::RemoveType()
	{
		RemoveField("Type");
	}

	const unsigned short IPS_HTTPProxyAccessPoint::Port() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Port"), ret);
		return ret;
	}
	void IPS_HTTPProxyAccessPoint::Port(const unsigned short value)
	{
		SetOrAddField("Port", TypeConverter::TypeToString(value));
	}
	bool IPS_HTTPProxyAccessPoint::PortExists() const
	{
		return ContainsField("Port");
	}
	void IPS_HTTPProxyAccessPoint::RemovePort()
	{
		RemoveField("Port");
	}

	const string IPS_HTTPProxyAccessPoint::NetworkDnsSuffix() const
	{
		return GetField("NetworkDnsSuffix")[0];
	}
	void IPS_HTTPProxyAccessPoint::NetworkDnsSuffix(const string &value)
	{
		SetOrAddField("NetworkDnsSuffix", value);
	}
	bool IPS_HTTPProxyAccessPoint::NetworkDnsSuffixExists() const
	{
		return ContainsField("NetworkDnsSuffix");
	}
	void IPS_HTTPProxyAccessPoint::RemoveNetworkDnsSuffix()
	{
		RemoveField("NetworkDnsSuffix");
	}

	const unsigned int IPS_HTTPProxyAccessPoint::Priority() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Priority"), ret);
		return ret;
	}
	void IPS_HTTPProxyAccessPoint::Priority(const unsigned int value)
	{
		SetOrAddField("Priority", TypeConverter::TypeToString(value));
	}
	bool IPS_HTTPProxyAccessPoint::PriorityExists() const
	{
		return ContainsField("Priority");
	}
	void IPS_HTTPProxyAccessPoint::RemovePriority()
	{
		RemoveField("Priority");
	}

	CimBase *IPS_HTTPProxyAccessPoint::CreateFromCimObject(const CimObject &object)
	{
		IPS_HTTPProxyAccessPoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_HTTPProxyAccessPoint>(object);
		}
		else
		{
			ret = new IPS_HTTPProxyAccessPoint(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_HTTPProxyAccessPoint> > IPS_HTTPProxyAccessPoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_HTTPProxyAccessPoint>(client, keys);
	}

	void IPS_HTTPProxyAccessPoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_HTTPProxyAccessPoint::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int IPS_HTTPProxyAccessPoint::UpdatePriority()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("UpdatePriority", input, output);
	}
	const string IPS_HTTPProxyAccessPoint::CLASS_NAME = "IPS_HTTPProxyAccessPoint";
	const string IPS_HTTPProxyAccessPoint::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HTTPProxyAccessPoint";
	const string IPS_HTTPProxyAccessPoint::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HTTPProxyAccessPoint";
	const string IPS_HTTPProxyAccessPoint::CLASS_NS_PREFIX = "AHT487";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_HTTPProxyAccessPoint::_classMetaData;
}
}
}
}
