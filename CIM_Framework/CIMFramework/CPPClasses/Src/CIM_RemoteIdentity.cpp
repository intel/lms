//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteIdentity.cpp
//
//  Contents:   An instance of RemoteIdentity is an Identity that should be used to provide a persistent representation of a security principal for which authoritative information required for mapping to users or groups is not otherwise modeled.
//
//              This file was automatically generated from CIM_RemoteIdentity.mof,  version: 2.16.0
//
//----------------------------------------------------------------------------
#include "CIM_RemoteIdentity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RemoteIdentity::_metadata[] = {
		{"Name", false, false, false },
		{"NameFormat", false, false, false },
		{"OtherNameFormat", false, false, false },
	};
	// class fields
	const Base64 CIM_RemoteIdentity::Name() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("Name"), ret);
		return ret;
	}
	void CIM_RemoteIdentity::Name(const Base64 &value)
	{
		SetOrAddField("Name", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteIdentity::NameExists() const
	{
		return ContainsField("Name");
	}
	void CIM_RemoteIdentity::RemoveName()
	{
		RemoveField("Name");
	}

	const unsigned short CIM_RemoteIdentity::NameFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NameFormat"), ret);
		return ret;
	}
	void CIM_RemoteIdentity::NameFormat(const unsigned short value)
	{
		SetOrAddField("NameFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteIdentity::NameFormatExists() const
	{
		return ContainsField("NameFormat");
	}
	void CIM_RemoteIdentity::RemoveNameFormat()
	{
		RemoveField("NameFormat");
	}

	const string CIM_RemoteIdentity::OtherNameFormat() const
	{
		return GetField("OtherNameFormat")[0];
	}
	void CIM_RemoteIdentity::OtherNameFormat(const string &value)
	{
		SetOrAddField("OtherNameFormat", value);
	}
	bool CIM_RemoteIdentity::OtherNameFormatExists() const
	{
		return ContainsField("OtherNameFormat");
	}
	void CIM_RemoteIdentity::RemoveOtherNameFormat()
	{
		RemoveField("OtherNameFormat");
	}

	CimBase *CIM_RemoteIdentity::CreateFromCimObject(const CimObject &object)
	{
		CIM_RemoteIdentity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RemoteIdentity>(object);
		}
		else
		{
			ret = new CIM_RemoteIdentity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RemoteIdentity> > CIM_RemoteIdentity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RemoteIdentity>(client, keys);
	}

	void CIM_RemoteIdentity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RemoteIdentity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RemoteIdentity::CLASS_NAME = "CIM_RemoteIdentity";
	const string CIM_RemoteIdentity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteIdentity";
	const string CIM_RemoteIdentity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteIdentity";
	const string CIM_RemoteIdentity::CLASS_NS_PREFIX = "ARe572";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RemoteIdentity::_classMetaData;
}
}
}
}
