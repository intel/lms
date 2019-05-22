//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Account.cpp
//
//  Contents:   CIM_Account is the information held by a SecurityService to track identity and privileges managed by that service. Common examples of an Account are the entries in a UNIX /etc/passwd file. Several kinds of security services use various information from those entries - the /bin/login program uses the account name ('root') and hashed password to authenticate users, and the file service, for instance, uses the UserID field ('0') and GroupID field ('0') to record ownership and determine access control privileges on files in the file system. This class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. 
//              
//              The semantics of Account overlap with that of the class, CIM_Identity. However, aspects of Account - such as its specific tie to a System - are valuable and have been widely implemented. For this reason, the Account and Identity classes are associated using a subclass of LogicalIdentity (AccountIdentity), instead of deprecating the Account class in the CIM Schema. When an Account has been authenticated, the corresponding Identity's TrustEstablished Boolean would be set to TRUE. Then, the Identity class can be used as defined for authorization purposes.
//
//              This file was automatically generated from CIM_Account.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_Account.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Account::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"UserID", false, false, false },
		{"ObjectClass", false, false, false },
		{"Descriptions", false, false, false },
		{"Host", false, false, false },
		{"LocalityName", false, false, false },
		{"OrganizationName", false, true, false },
		{"OU", false, false, false },
		{"SeeAlso", false, false, false },
		{"UserCertificate", false, false, false },
		{"UserPassword", false, false, false },
		{"UserPasswordEncryptionAlgorithm", false, false, false },
		{"OtherUserPasswordEncryptionAlgorithm", false, false, false },
		{"ComplexPasswordRulesEnforced", false, false, false },
		{"InactivityTimeout", false, false, false },
		{"LastLogin", false, false, false },
		{"MaximumSuccessiveLoginFailures", false, false, false },
		{"PasswordExpiration", false, false, false },
		{"PasswordHistoryDepth", false, false, false },
		{"UserPasswordEncoding", false, false, false },
	};
	// class fields
	const string CIM_Account::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_Account::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_Account::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_Account::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_Account::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_Account::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_Account::UserID() const
	{
		return GetField("UserID")[0];
	}
	void CIM_Account::UserID(const string &value)
	{
		SetOrAddField("UserID", value);
	}
	bool CIM_Account::UserIDExists() const
	{
		return ContainsField("UserID");
	}
	void CIM_Account::RemoveUserID()
	{
		RemoveField("UserID");
	}

	const vector<string> CIM_Account::ObjectClass() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ObjectClass"), ret);
		return ret;
	}
	void CIM_Account::ObjectClass(const vector<string> &value)
	{
		SetOrAddField("ObjectClass", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::ObjectClassExists() const
	{
		return ContainsField("ObjectClass");
	}
	void CIM_Account::RemoveObjectClass()
	{
		RemoveField("ObjectClass");
	}

	const vector<string> CIM_Account::Descriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("Descriptions"), ret);
		return ret;
	}
	void CIM_Account::Descriptions(const vector<string> &value)
	{
		SetOrAddField("Descriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::DescriptionsExists() const
	{
		return ContainsField("Descriptions");
	}
	void CIM_Account::RemoveDescriptions()
	{
		RemoveField("Descriptions");
	}

	const vector<string> CIM_Account::Host() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("Host"), ret);
		return ret;
	}
	void CIM_Account::Host(const vector<string> &value)
	{
		SetOrAddField("Host", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::HostExists() const
	{
		return ContainsField("Host");
	}
	void CIM_Account::RemoveHost()
	{
		RemoveField("Host");
	}

	const vector<string> CIM_Account::LocalityName() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("LocalityName"), ret);
		return ret;
	}
	void CIM_Account::LocalityName(const vector<string> &value)
	{
		SetOrAddField("LocalityName", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::LocalityNameExists() const
	{
		return ContainsField("LocalityName");
	}
	void CIM_Account::RemoveLocalityName()
	{
		RemoveField("LocalityName");
	}

	const vector<string> CIM_Account::OrganizationName() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OrganizationName"), ret);
		return ret;
	}
	void CIM_Account::OrganizationName(const vector<string> &value)
	{
		SetOrAddField("OrganizationName", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::OrganizationNameExists() const
	{
		return ContainsField("OrganizationName");
	}
	void CIM_Account::RemoveOrganizationName()
	{
		RemoveField("OrganizationName");
	}

	const vector<string> CIM_Account::OU() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OU"), ret);
		return ret;
	}
	void CIM_Account::OU(const vector<string> &value)
	{
		SetOrAddField("OU", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::OUExists() const
	{
		return ContainsField("OU");
	}
	void CIM_Account::RemoveOU()
	{
		RemoveField("OU");
	}

	const vector<string> CIM_Account::SeeAlso() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("SeeAlso"), ret);
		return ret;
	}
	void CIM_Account::SeeAlso(const vector<string> &value)
	{
		SetOrAddField("SeeAlso", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::SeeAlsoExists() const
	{
		return ContainsField("SeeAlso");
	}
	void CIM_Account::RemoveSeeAlso()
	{
		RemoveField("SeeAlso");
	}

	const HexBinary CIM_Account::UserCertificate() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("UserCertificate"), ret);
		return ret;
	}
	void CIM_Account::UserCertificate(const HexBinary &value)
	{
		SetOrAddField("UserCertificate", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::UserCertificateExists() const
	{
		return ContainsField("UserCertificate");
	}
	void CIM_Account::RemoveUserCertificate()
	{
		RemoveField("UserCertificate");
	}

	const HexBinary CIM_Account::UserPassword() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("UserPassword"), ret);
		return ret;
	}
	void CIM_Account::UserPassword(const HexBinary &value)
	{
		SetOrAddField("UserPassword", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::UserPasswordExists() const
	{
		return ContainsField("UserPassword");
	}
	void CIM_Account::RemoveUserPassword()
	{
		RemoveField("UserPassword");
	}

	const unsigned short CIM_Account::UserPasswordEncryptionAlgorithm() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("UserPasswordEncryptionAlgorithm"), ret);
		return ret;
	}
	void CIM_Account::UserPasswordEncryptionAlgorithm(const unsigned short value)
	{
		SetOrAddField("UserPasswordEncryptionAlgorithm", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::UserPasswordEncryptionAlgorithmExists() const
	{
		return ContainsField("UserPasswordEncryptionAlgorithm");
	}
	void CIM_Account::RemoveUserPasswordEncryptionAlgorithm()
	{
		RemoveField("UserPasswordEncryptionAlgorithm");
	}

	const string CIM_Account::OtherUserPasswordEncryptionAlgorithm() const
	{
		return GetField("OtherUserPasswordEncryptionAlgorithm")[0];
	}
	void CIM_Account::OtherUserPasswordEncryptionAlgorithm(const string &value)
	{
		SetOrAddField("OtherUserPasswordEncryptionAlgorithm", value);
	}
	bool CIM_Account::OtherUserPasswordEncryptionAlgorithmExists() const
	{
		return ContainsField("OtherUserPasswordEncryptionAlgorithm");
	}
	void CIM_Account::RemoveOtherUserPasswordEncryptionAlgorithm()
	{
		RemoveField("OtherUserPasswordEncryptionAlgorithm");
	}

	const vector<unsigned short> CIM_Account::ComplexPasswordRulesEnforced() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ComplexPasswordRulesEnforced"), ret);
		return ret;
	}
	void CIM_Account::ComplexPasswordRulesEnforced(const vector<unsigned short> &value)
	{
		SetOrAddField("ComplexPasswordRulesEnforced", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::ComplexPasswordRulesEnforcedExists() const
	{
		return ContainsField("ComplexPasswordRulesEnforced");
	}
	void CIM_Account::RemoveComplexPasswordRulesEnforced()
	{
		RemoveField("ComplexPasswordRulesEnforced");
	}

	const CimDateTime CIM_Account::InactivityTimeout() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("InactivityTimeout"), ret);
		return ret;
	}
	void CIM_Account::InactivityTimeout(const CimDateTime &value)
	{
		SetOrAddField("InactivityTimeout", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::InactivityTimeoutExists() const
	{
		return ContainsField("InactivityTimeout");
	}
	void CIM_Account::RemoveInactivityTimeout()
	{
		RemoveField("InactivityTimeout");
	}

	const CimDateTime CIM_Account::LastLogin() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("LastLogin"), ret);
		return ret;
	}
	void CIM_Account::LastLogin(const CimDateTime &value)
	{
		SetOrAddField("LastLogin", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::LastLoginExists() const
	{
		return ContainsField("LastLogin");
	}
	void CIM_Account::RemoveLastLogin()
	{
		RemoveField("LastLogin");
	}

	const unsigned short CIM_Account::MaximumSuccessiveLoginFailures() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaximumSuccessiveLoginFailures"), ret);
		return ret;
	}
	void CIM_Account::MaximumSuccessiveLoginFailures(const unsigned short value)
	{
		SetOrAddField("MaximumSuccessiveLoginFailures", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::MaximumSuccessiveLoginFailuresExists() const
	{
		return ContainsField("MaximumSuccessiveLoginFailures");
	}
	void CIM_Account::RemoveMaximumSuccessiveLoginFailures()
	{
		RemoveField("MaximumSuccessiveLoginFailures");
	}

	const CimDateTime CIM_Account::PasswordExpiration() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("PasswordExpiration"), ret);
		return ret;
	}
	void CIM_Account::PasswordExpiration(const CimDateTime &value)
	{
		SetOrAddField("PasswordExpiration", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::PasswordExpirationExists() const
	{
		return ContainsField("PasswordExpiration");
	}
	void CIM_Account::RemovePasswordExpiration()
	{
		RemoveField("PasswordExpiration");
	}

	const unsigned short CIM_Account::PasswordHistoryDepth() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PasswordHistoryDepth"), ret);
		return ret;
	}
	void CIM_Account::PasswordHistoryDepth(const unsigned short value)
	{
		SetOrAddField("PasswordHistoryDepth", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::PasswordHistoryDepthExists() const
	{
		return ContainsField("PasswordHistoryDepth");
	}
	void CIM_Account::RemovePasswordHistoryDepth()
	{
		RemoveField("PasswordHistoryDepth");
	}

	const unsigned int CIM_Account::UserPasswordEncoding() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("UserPasswordEncoding"), ret);
		return ret;
	}
	void CIM_Account::UserPasswordEncoding(const unsigned int value)
	{
		SetOrAddField("UserPasswordEncoding", TypeConverter::TypeToString(value));
	}
	bool CIM_Account::UserPasswordEncodingExists() const
	{
		return ContainsField("UserPasswordEncoding");
	}
	void CIM_Account::RemoveUserPasswordEncoding()
	{
		RemoveField("UserPasswordEncoding");
	}

	CimBase *CIM_Account::CreateFromCimObject(const CimObject &object)
	{
		CIM_Account *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Account>(object);
		}
		else
		{
			ret = new CIM_Account(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Account> > CIM_Account::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Account>(client, keys);
	}

	void CIM_Account::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Account::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_Account::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_Account::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_Account::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Account::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_Account::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_Account::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_Account::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_Account::CLASS_NAME = "CIM_Account";
	const string CIM_Account::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Account";
	const string CIM_Account::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Account";
	const string CIM_Account::CLASS_NS_PREFIX = "AAc931";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Account::_classMetaData;
}
}
}
}
