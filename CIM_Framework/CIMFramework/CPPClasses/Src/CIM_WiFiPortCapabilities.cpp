//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiPortCapabilities.cpp
//
//  Contents:   CIM_WiFiPortCapabilities is a specialization of CIM_NetworkPortCapabilities that describes the capabilities of a WiFiPort.
//
//              This file was automatically generated from CIM_WiFiPortCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_WiFiPortCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_WiFiPortCapabilities::_metadata[] = {
		{"SupportedPortTypes", false, false, false },
		{"OtherSupportedPortTypes", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_WiFiPortCapabilities::SupportedPortTypes() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedPortTypes"), ret);
		return ret;
	}
	void CIM_WiFiPortCapabilities::SupportedPortTypes(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedPortTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiPortCapabilities::SupportedPortTypesExists() const
	{
		return ContainsField("SupportedPortTypes");
	}
	void CIM_WiFiPortCapabilities::RemoveSupportedPortTypes()
	{
		RemoveField("SupportedPortTypes");
	}

	const vector<string> CIM_WiFiPortCapabilities::OtherSupportedPortTypes() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherSupportedPortTypes"), ret);
		return ret;
	}
	void CIM_WiFiPortCapabilities::OtherSupportedPortTypes(const vector<string> &value)
	{
		SetOrAddField("OtherSupportedPortTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_WiFiPortCapabilities::OtherSupportedPortTypesExists() const
	{
		return ContainsField("OtherSupportedPortTypes");
	}
	void CIM_WiFiPortCapabilities::RemoveOtherSupportedPortTypes()
	{
		RemoveField("OtherSupportedPortTypes");
	}

	CimBase *CIM_WiFiPortCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_WiFiPortCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_WiFiPortCapabilities>(object);
		}
		else
		{
			ret = new CIM_WiFiPortCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_WiFiPortCapabilities> > CIM_WiFiPortCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_WiFiPortCapabilities>(client, keys);
	}

	void CIM_WiFiPortCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_WiFiPortCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_WiFiPortCapabilities::CLASS_NAME = "CIM_WiFiPortCapabilities";
	const string CIM_WiFiPortCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiPortCapabilities";
	const string CIM_WiFiPortCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_WiFiPortCapabilities";
	const string CIM_WiFiPortCapabilities::CLASS_NS_PREFIX = "AWi452";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_WiFiPortCapabilities::_classMetaData;
}
}
}
}
