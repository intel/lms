//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AccountManagementService.cpp
//
//  Contents:   CIM_AccountManagementService creates, manages, and if necessary destroys Accounts on behalf of other SecuritySerices.
//
//              This file was automatically generated from CIM_AccountManagementService.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_AccountManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_AccountManagementService::CreateFromCimObject(const CimObject &object)
	{
		CIM_AccountManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AccountManagementService>(object);
		}
		else
		{
			ret = new CIM_AccountManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AccountManagementService> > CIM_AccountManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AccountManagementService>(client, keys);
	}

	void CIM_AccountManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AccountManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_AccountManagementService::CreateAccount_INPUT::_metadata[] = {
		{"System", false, true },
		{"AccountTemplate", false, true },
	};
	void CIM_AccountManagementService::CreateAccount_INPUT::System(const CimReference &value)
	{
		SetOrAddField("System", TypeConverter::TypeToString(value));
	}
	void CIM_AccountManagementService::CreateAccount_INPUT::AccountTemplate(const CIM_Account &value)
	{
		SetOrAddField("AccountTemplate", TypedTypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_AccountManagementService::CreateAccount_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_AccountManagementService::CreateAccount_OUTPUT::Account() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Account"), ret);
		return ret;
	}
	bool CIM_AccountManagementService::CreateAccount_OUTPUT::AccountExists() const
	{
		return ContainsField("Account");
	}
	const vector<CimReference> CIM_AccountManagementService::CreateAccount_OUTPUT::Identities() const
	{
		vector<CimReference> ret;
		if(ContainsField("Identities"))
			TypeConverter::StringToType(GetField("Identities"), ret);
		return ret;
	}
	bool CIM_AccountManagementService::CreateAccount_OUTPUT::IdentitiesExists() const
	{
		return ContainsField("Identities");
	}
	unsigned int CIM_AccountManagementService::CreateAccount(const CreateAccount_INPUT &input, CreateAccount_OUTPUT &output)
	{
		return Invoke("CreateAccount", input, output);
	}
	const string CIM_AccountManagementService::CLASS_NAME = "CIM_AccountManagementService";
	const string CIM_AccountManagementService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountManagementService";
	const string CIM_AccountManagementService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountManagementService";
	const string CIM_AccountManagementService::CLASS_NS_PREFIX = "AAc67";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AccountManagementService::_classMetaData;
}
}
}
}
