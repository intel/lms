//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_CredentialContext.cpp
//
//  Contents:   This relationship defines a context (e.g., a System or Service) of a Credential. One example is a shared secret/ password which is defined within the context of an application (or Service). Generally, there is one scoping element for a Credential, however the multiplicities of the association allow a Credential to be scoped by more than one element. If this association is not instantiated for a Credential, that Credential is assumed to be scoped to the Namespace.
//              This association may also be used to indicate that a Credential is valid in some other environment. For instance associating the Credential to a RemoteServiceAccessPoint would indicate that the Credential is used to access the remote service.
//
//              This file was automatically generated from CIM_CredentialContext.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_CredentialContext.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_CredentialContext::_metadata[] = {
		{"ElementInContext", true, false, true },
		{"ElementProvidingContext", true, false, true },
		{"Usage", false, false, false },
	};
	// class fields
	const CimReference CIM_CredentialContext::ElementInContext() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ElementInContext"), ret);
		return ret;
	}
	void CIM_CredentialContext::ElementInContext(const CimReference &value)
	{
		SetOrAddField("ElementInContext", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_CredentialContext::ElementProvidingContext() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ElementProvidingContext"), ret);
		return ret;
	}
	void CIM_CredentialContext::ElementProvidingContext(const CimReference &value)
	{
		SetOrAddField("ElementProvidingContext", TypeConverter::TypeToString(value));
	}

	const unsigned short CIM_CredentialContext::Usage() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Usage"), ret);
		return ret;
	}
	void CIM_CredentialContext::Usage(const unsigned short value)
	{
		SetOrAddField("Usage", TypeConverter::TypeToString(value));
	}
	bool CIM_CredentialContext::UsageExists() const
	{
		return ContainsField("Usage");
	}
	void CIM_CredentialContext::RemoveUsage()
	{
		RemoveField("Usage");
	}

	CimBase *CIM_CredentialContext::CreateFromCimObject(const CimObject &object)
	{
		CIM_CredentialContext *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_CredentialContext>(object);
		}
		else
		{
			ret = new CIM_CredentialContext(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_CredentialContext> > CIM_CredentialContext::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_CredentialContext>(client, keys);
	}

	void CIM_CredentialContext::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_CredentialContext::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_CredentialContext::CLASS_NAME = "CIM_CredentialContext";
	const string CIM_CredentialContext::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CredentialContext";
	const string CIM_CredentialContext::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_CredentialContext";
	const string CIM_CredentialContext::CLASS_NS_PREFIX = "ACr712";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_CredentialContext::_classMetaData;
}
}
}
}
