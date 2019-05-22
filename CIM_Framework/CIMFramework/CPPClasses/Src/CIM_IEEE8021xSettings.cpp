//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IEEE8021xSettings.cpp
//
//  Contents:   IEEE8021xSettings specifies a set of IEEE 802.1x Port-Based Network Access Control settings that can be applied to a ISO OSI layer 2 ProtocolEndpoint.
//
//              This file was automatically generated from CIM_IEEE8021xSettings.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_IEEE8021xSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_IEEE8021xSettings::_metadata[] = {
		{"AuthenticationProtocol", false, false, false },
		{"RoamingIdentity", false, false, false },
		{"ServerCertificateName", false, false, false },
		{"ServerCertificateNameComparison", false, false, false },
		{"Username", false, false, false },
		{"Password", false, false, false },
		{"Domain", false, false, false },
		{"ProtectedAccessCredential", false, false, false },
		{"PACPassword", false, false, false },
		{"PSK", false, false, false },
	};
	// class fields
	const unsigned short CIM_IEEE8021xSettings::AuthenticationProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AuthenticationProtocol"), ret);
		return ret;
	}
	void CIM_IEEE8021xSettings::AuthenticationProtocol(const unsigned short value)
	{
		SetOrAddField("AuthenticationProtocol", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xSettings::AuthenticationProtocolExists() const
	{
		return ContainsField("AuthenticationProtocol");
	}
	void CIM_IEEE8021xSettings::RemoveAuthenticationProtocol()
	{
		RemoveField("AuthenticationProtocol");
	}

	const string CIM_IEEE8021xSettings::RoamingIdentity() const
	{
		return GetField("RoamingIdentity")[0];
	}
	void CIM_IEEE8021xSettings::RoamingIdentity(const string &value)
	{
		SetOrAddField("RoamingIdentity", value);
	}
	bool CIM_IEEE8021xSettings::RoamingIdentityExists() const
	{
		return ContainsField("RoamingIdentity");
	}
	void CIM_IEEE8021xSettings::RemoveRoamingIdentity()
	{
		RemoveField("RoamingIdentity");
	}

	const string CIM_IEEE8021xSettings::ServerCertificateName() const
	{
		return GetField("ServerCertificateName")[0];
	}
	void CIM_IEEE8021xSettings::ServerCertificateName(const string &value)
	{
		SetOrAddField("ServerCertificateName", value);
	}
	bool CIM_IEEE8021xSettings::ServerCertificateNameExists() const
	{
		return ContainsField("ServerCertificateName");
	}
	void CIM_IEEE8021xSettings::RemoveServerCertificateName()
	{
		RemoveField("ServerCertificateName");
	}

	const unsigned short CIM_IEEE8021xSettings::ServerCertificateNameComparison() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ServerCertificateNameComparison"), ret);
		return ret;
	}
	void CIM_IEEE8021xSettings::ServerCertificateNameComparison(const unsigned short value)
	{
		SetOrAddField("ServerCertificateNameComparison", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xSettings::ServerCertificateNameComparisonExists() const
	{
		return ContainsField("ServerCertificateNameComparison");
	}
	void CIM_IEEE8021xSettings::RemoveServerCertificateNameComparison()
	{
		RemoveField("ServerCertificateNameComparison");
	}

	const string CIM_IEEE8021xSettings::Username() const
	{
		return GetField("Username")[0];
	}
	void CIM_IEEE8021xSettings::Username(const string &value)
	{
		SetOrAddField("Username", value);
	}
	bool CIM_IEEE8021xSettings::UsernameExists() const
	{
		return ContainsField("Username");
	}
	void CIM_IEEE8021xSettings::RemoveUsername()
	{
		RemoveField("Username");
	}

	const string CIM_IEEE8021xSettings::Password() const
	{
		return GetField("Password")[0];
	}
	void CIM_IEEE8021xSettings::Password(const string &value)
	{
		SetOrAddField("Password", value);
	}
	bool CIM_IEEE8021xSettings::PasswordExists() const
	{
		return ContainsField("Password");
	}
	void CIM_IEEE8021xSettings::RemovePassword()
	{
		RemoveField("Password");
	}

	const string CIM_IEEE8021xSettings::Domain() const
	{
		return GetField("Domain")[0];
	}
	void CIM_IEEE8021xSettings::Domain(const string &value)
	{
		SetOrAddField("Domain", value);
	}
	bool CIM_IEEE8021xSettings::DomainExists() const
	{
		return ContainsField("Domain");
	}
	void CIM_IEEE8021xSettings::RemoveDomain()
	{
		RemoveField("Domain");
	}

	const Base64 CIM_IEEE8021xSettings::ProtectedAccessCredential() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ProtectedAccessCredential"), ret);
		return ret;
	}
	void CIM_IEEE8021xSettings::ProtectedAccessCredential(const Base64 &value)
	{
		SetOrAddField("ProtectedAccessCredential", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xSettings::ProtectedAccessCredentialExists() const
	{
		return ContainsField("ProtectedAccessCredential");
	}
	void CIM_IEEE8021xSettings::RemoveProtectedAccessCredential()
	{
		RemoveField("ProtectedAccessCredential");
	}

	const string CIM_IEEE8021xSettings::PACPassword() const
	{
		return GetField("PACPassword")[0];
	}
	void CIM_IEEE8021xSettings::PACPassword(const string &value)
	{
		SetOrAddField("PACPassword", value);
	}
	bool CIM_IEEE8021xSettings::PACPasswordExists() const
	{
		return ContainsField("PACPassword");
	}
	void CIM_IEEE8021xSettings::RemovePACPassword()
	{
		RemoveField("PACPassword");
	}

	const Base64 CIM_IEEE8021xSettings::PSK() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("PSK"), ret);
		return ret;
	}
	void CIM_IEEE8021xSettings::PSK(const Base64 &value)
	{
		SetOrAddField("PSK", TypeConverter::TypeToString(value));
	}
	bool CIM_IEEE8021xSettings::PSKExists() const
	{
		return ContainsField("PSK");
	}
	void CIM_IEEE8021xSettings::RemovePSK()
	{
		RemoveField("PSK");
	}

	CimBase *CIM_IEEE8021xSettings::CreateFromCimObject(const CimObject &object)
	{
		CIM_IEEE8021xSettings *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_IEEE8021xSettings>(object);
		}
		else
		{
			ret = new CIM_IEEE8021xSettings(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_IEEE8021xSettings> > CIM_IEEE8021xSettings::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_IEEE8021xSettings>(client, keys);
	}

	void CIM_IEEE8021xSettings::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_IEEE8021xSettings::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_IEEE8021xSettings::CLASS_NAME = "CIM_IEEE8021xSettings";
	const string CIM_IEEE8021xSettings::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IEEE8021xSettings";
	const string CIM_IEEE8021xSettings::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IEEE8021xSettings";
	const string CIM_IEEE8021xSettings::CLASS_NS_PREFIX = "AIE160";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_IEEE8021xSettings::_classMetaData;
}
}
}
}
