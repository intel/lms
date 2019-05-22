//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AccountManagementCapabilities.cpp
//
//  Contents:   AccountManagementCapabilities describes the capabilities supported for managing Accounts associated with an instance of AccountManagementService. AccountManagementCapabilities is associated with an instance of AccountManagementService through the ElementCapabilities association.
//
//              This file was automatically generated from CIM_AccountManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#include "CIM_AccountManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AccountManagementCapabilities::_metadata[] = {
		{"OperationsSupported", false, false, false },
		{"OtherSupportedUserPasswordEncryptionAlgorithms", false, false, false },
		{"SupportedUserPasswordEncryptionAlgorithms", false, false, false },
		{"UserPasswordEncryptionSalt", false, false, false },
		{"MaximumAccountsSupported", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_AccountManagementCapabilities::OperationsSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("OperationsSupported"), ret);
		return ret;
	}
	void CIM_AccountManagementCapabilities::OperationsSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("OperationsSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_AccountManagementCapabilities::OperationsSupportedExists() const
	{
		return ContainsField("OperationsSupported");
	}
	void CIM_AccountManagementCapabilities::RemoveOperationsSupported()
	{
		RemoveField("OperationsSupported");
	}

	const vector<string> CIM_AccountManagementCapabilities::OtherSupportedUserPasswordEncryptionAlgorithms() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherSupportedUserPasswordEncryptionAlgorithms"), ret);
		return ret;
	}
	void CIM_AccountManagementCapabilities::OtherSupportedUserPasswordEncryptionAlgorithms(const vector<string> &value)
	{
		SetOrAddField("OtherSupportedUserPasswordEncryptionAlgorithms", TypeConverter::TypeToString(value));
	}
	bool CIM_AccountManagementCapabilities::OtherSupportedUserPasswordEncryptionAlgorithmsExists() const
	{
		return ContainsField("OtherSupportedUserPasswordEncryptionAlgorithms");
	}
	void CIM_AccountManagementCapabilities::RemoveOtherSupportedUserPasswordEncryptionAlgorithms()
	{
		RemoveField("OtherSupportedUserPasswordEncryptionAlgorithms");
	}

	const vector<unsigned short> CIM_AccountManagementCapabilities::SupportedUserPasswordEncryptionAlgorithms() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedUserPasswordEncryptionAlgorithms"), ret);
		return ret;
	}
	void CIM_AccountManagementCapabilities::SupportedUserPasswordEncryptionAlgorithms(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedUserPasswordEncryptionAlgorithms", TypeConverter::TypeToString(value));
	}
	bool CIM_AccountManagementCapabilities::SupportedUserPasswordEncryptionAlgorithmsExists() const
	{
		return ContainsField("SupportedUserPasswordEncryptionAlgorithms");
	}
	void CIM_AccountManagementCapabilities::RemoveSupportedUserPasswordEncryptionAlgorithms()
	{
		RemoveField("SupportedUserPasswordEncryptionAlgorithms");
	}

	const string CIM_AccountManagementCapabilities::UserPasswordEncryptionSalt() const
	{
		return GetField("UserPasswordEncryptionSalt")[0];
	}
	void CIM_AccountManagementCapabilities::UserPasswordEncryptionSalt(const string &value)
	{
		SetOrAddField("UserPasswordEncryptionSalt", value);
	}
	bool CIM_AccountManagementCapabilities::UserPasswordEncryptionSaltExists() const
	{
		return ContainsField("UserPasswordEncryptionSalt");
	}
	void CIM_AccountManagementCapabilities::RemoveUserPasswordEncryptionSalt()
	{
		RemoveField("UserPasswordEncryptionSalt");
	}

	const unsigned short CIM_AccountManagementCapabilities::MaximumAccountsSupported() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaximumAccountsSupported"), ret);
		return ret;
	}
	void CIM_AccountManagementCapabilities::MaximumAccountsSupported(const unsigned short value)
	{
		SetOrAddField("MaximumAccountsSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_AccountManagementCapabilities::MaximumAccountsSupportedExists() const
	{
		return ContainsField("MaximumAccountsSupported");
	}
	void CIM_AccountManagementCapabilities::RemoveMaximumAccountsSupported()
	{
		RemoveField("MaximumAccountsSupported");
	}

	CimBase *CIM_AccountManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_AccountManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AccountManagementCapabilities>(object);
		}
		else
		{
			ret = new CIM_AccountManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AccountManagementCapabilities> > CIM_AccountManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AccountManagementCapabilities>(client, keys);
	}

	void CIM_AccountManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AccountManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AccountManagementCapabilities::CLASS_NAME = "CIM_AccountManagementCapabilities";
	const string CIM_AccountManagementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountManagementCapabilities";
	const string CIM_AccountManagementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AccountManagementCapabilities";
	const string CIM_AccountManagementCapabilities::CLASS_NS_PREFIX = "AAc622";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AccountManagementCapabilities::_classMetaData;
}
}
}
}
