//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IEEE8021xCapabilities.cpp
//
//  Contents:   CIM_IEEE8021xCapabilities describes the IEEE 802.1x security capabilities of a layer 2 ProtocolEndpoint.
//
//              This file was automatically generated from CIM_IEEE8021xCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_IEEE8021xCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_IEEE8021xCapabilities::_metadata[] = {
		{"SupportedAuthenticationProtocols", false, false, false },
		{"RoamingSupported", false, false, false },
		{"FastRoamingSupported", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_IEEE8021xCapabilities::SupportedAuthenticationProtocols() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedAuthenticationProtocols"), ret);
		return ret;
	}
	void CIM_IEEE8021xCapabilities::SupportedAuthenticationProtocols(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedAuthenticationProtocols", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xCapabilities::SupportedAuthenticationProtocolsExists() const
	{
		return ContainsField("SupportedAuthenticationProtocols");
	}
	void CIM_IEEE8021xCapabilities::RemoveSupportedAuthenticationProtocols()
	{
		RemoveField("SupportedAuthenticationProtocols");
	}

	const bool CIM_IEEE8021xCapabilities::RoamingSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RoamingSupported"), ret);
		return ret;
	}
	void CIM_IEEE8021xCapabilities::RoamingSupported(const bool value)
	{
		SetOrAddField("RoamingSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xCapabilities::RoamingSupportedExists() const
	{
		return ContainsField("RoamingSupported");
	}
	void CIM_IEEE8021xCapabilities::RemoveRoamingSupported()
	{
		RemoveField("RoamingSupported");
	}

	const bool CIM_IEEE8021xCapabilities::FastRoamingSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("FastRoamingSupported"), ret);
		return ret;
	}
	void CIM_IEEE8021xCapabilities::FastRoamingSupported(const bool value)
	{
		SetOrAddField("FastRoamingSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xCapabilities::FastRoamingSupportedExists() const
	{
		return ContainsField("FastRoamingSupported");
	}
	void CIM_IEEE8021xCapabilities::RemoveFastRoamingSupported()
	{
		RemoveField("FastRoamingSupported");
	}

	CimBase *CIM_IEEE8021xCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_IEEE8021xCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_IEEE8021xCapabilities>(object);
		}
		else
		{
			ret = new CIM_IEEE8021xCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_IEEE8021xCapabilities> > CIM_IEEE8021xCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_IEEE8021xCapabilities>(client, keys);
	}

	void CIM_IEEE8021xCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_IEEE8021xCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_IEEE8021xCapabilities::CLASS_NAME = "CIM_IEEE8021xCapabilities";
	const string CIM_IEEE8021xCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IEEE8021xCapabilities";
	const string CIM_IEEE8021xCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IEEE8021xCapabilities";
	const string CIM_IEEE8021xCapabilities::CLASS_NS_PREFIX = "AIE371";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_IEEE8021xCapabilities::_classMetaData;
}
}
}
}
