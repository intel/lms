//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Identity.cpp
//
//  Contents:   An instance of an Identity represents a ManagedElement that acts as a security principal within the scope in which it is defined and authenticated. (Note that the Identity's scope is specified using the association, CIM_IdentityContext.) ManagedElements with Identities can be OrganizationalEntities, Services, Systems, etc. The ManagedElement 'behind' an Identity is described using the AssignedIdentity association. 
//              
//              Within a given security context, an Identity may be imparted a level of trust, usually based on its credentials. A trust level is defined using the CIM_SecuritySensitivity class, and associated with Identity using CIM_ElementSecuritySensitivity. Whether an Identity is currently authenticated is evaluated by checking the CurrentlyAuthenticated boolean property. This property is set and cleared by the security infrastructure, and should only be readable within the management infrastructure. The conditions which must be met/authenticated in order for an Identity's CurrentlyAuthenticated Boolean to be TRUE are defined using a subclass of PolicyCondition - AuthenticationCondition. The inheritance tree for AuthenticationCondition is defined in the CIM Policy Model. 
//              
//              Subclasses of Identity may include specific information related to a given AuthenticationService or authority (such as a security token or computer hardware port/communication details) that more specifically determine the authenticity of the Identity. An instance of Identity may be persisted even though it is not CurrentlyAuthenticated, in order to maintain static relationships to Roles, associations to accounting information, and policy data defining authentication requirements. Note however, when an Identity is not authenticated (CurrentlyAuthenticated = FALSE), then Privileges or rights SHOULD NOT be authorized. The lifetime, validity, and propagation of the Identity is dependent on a security infrastructure's policies.
//
//              This file was automatically generated from CIM_Identity.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_Identity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Identity::_metadata[] = {
		{"InstanceID", true, false, false },
		{"CurrentlyAuthenticated", false, false, false },
	};
	// class fields
	const bool CIM_Identity::CurrentlyAuthenticated() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("CurrentlyAuthenticated"), ret);
		return ret;
	}
	void CIM_Identity::CurrentlyAuthenticated(const bool value)
	{
		SetOrAddField("CurrentlyAuthenticated", TypeConverter::TypeToString(value));
	}
	bool CIM_Identity::CurrentlyAuthenticatedExists() const
	{
		return ContainsField("CurrentlyAuthenticated");
	}
	void CIM_Identity::RemoveCurrentlyAuthenticated()
	{
		RemoveField("CurrentlyAuthenticated");
	}

	CimBase *CIM_Identity::CreateFromCimObject(const CimObject &object)
	{
		CIM_Identity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Identity>(object);
		}
		else
		{
			ret = new CIM_Identity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Identity> > CIM_Identity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Identity>(client, keys);
	}

	void CIM_Identity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Identity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Identity::CLASS_NAME = "CIM_Identity";
	const string CIM_Identity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Identity";
	const string CIM_Identity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Identity";
	const string CIM_Identity::CLASS_NS_PREFIX = "AId194";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Identity::_classMetaData;
}
}
}
}
