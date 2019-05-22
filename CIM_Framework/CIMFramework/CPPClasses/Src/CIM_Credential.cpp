//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Credential.cpp
//
//  Contents:   Subclasses of CIM_Credential define materials, information or other data which are used to establish identity. Generally, there may be some shared information, or credential material which is used to identify and authenticate an entity in the process of gaining access to, or permission to use, resources. Such credential material may be used to authenticate an entity's identity initially, as done by a CIM_AuthenticationService, and additionally on an ongoing basis (for example, during the course of a connection or other security association), as proof that each received message or communication came from a valid 'user' of that credential material.
//
//              This file was automatically generated from CIM_Credential.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_Credential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Credential::_metadata[] = {
		{"Issued", false, false, false },
		{"Expires", false, false, false },
	};
	// class fields
	const CimDateTime CIM_Credential::Issued() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("Issued"), ret);
		return ret;
	}
	void CIM_Credential::Issued(const CimDateTime &value)
	{
		SetOrAddField("Issued", TypeConverter::TypeToString(value));
	}
	bool CIM_Credential::IssuedExists() const
	{
		return ContainsField("Issued");
	}
	void CIM_Credential::RemoveIssued()
	{
		RemoveField("Issued");
	}

	const CimDateTime CIM_Credential::Expires() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("Expires"), ret);
		return ret;
	}
	void CIM_Credential::Expires(const CimDateTime &value)
	{
		SetOrAddField("Expires", TypeConverter::TypeToString(value));
	}
	bool CIM_Credential::ExpiresExists() const
	{
		return ContainsField("Expires");
	}
	void CIM_Credential::RemoveExpires()
	{
		RemoveField("Expires");
	}

	CimBase *CIM_Credential::CreateFromCimObject(const CimObject &object)
	{
		CIM_Credential *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Credential>(object);
		}
		else
		{
			ret = new CIM_Credential(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Credential> > CIM_Credential::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Credential>(client, keys);
	}

	void CIM_Credential::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Credential::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Credential::CLASS_NAME = "CIM_Credential";
	const string CIM_Credential::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Credential";
	const string CIM_Credential::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Credential";
	const string CIM_Credential::CLASS_NS_PREFIX = "ACr929";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Credential::_classMetaData;
}
}
}
}
