//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_8021XProfile.cpp
//
//  Contents:   This class represents a 802.1X profile in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_8021XProfile.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_8021XProfile.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_8021XProfile::_metadata[] = {
		{"Enabled", false, true, false },
		{"ActiveInS0", false, false, false },
		{"AuthenticationProtocol", false, false, false },
		{"RoamingIdentity", false, false, false },
		{"ServerCertificateName", false, false, false },
		{"ServerCertificateNameComparison", false, false, false },
		{"Username", false, false, false },
		{"Password", false, false, false },
		{"Domain", false, false, false },
		{"ProtectedAccessCredential", false, false, false },
		{"PACPassword", false, false, false },
		{"ClientCertificate", false, false, true },
		{"ServerCertificateIssuer", false, false, true },
		{"PxeTimeout", false, false, false },
	};
	// class fields
	const bool AMT_8021XProfile::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	void AMT_8021XProfile::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::EnabledExists() const
	{
		return ContainsField("Enabled");
	}
	void AMT_8021XProfile::RemoveEnabled()
	{
		RemoveField("Enabled");
	}

	const bool AMT_8021XProfile::ActiveInS0() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActiveInS0"), ret);
		return ret;
	}
	void AMT_8021XProfile::ActiveInS0(const bool value)
	{
		SetOrAddField("ActiveInS0", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::ActiveInS0Exists() const
	{
		return ContainsField("ActiveInS0");
	}
	void AMT_8021XProfile::RemoveActiveInS0()
	{
		RemoveField("ActiveInS0");
	}

	const unsigned short AMT_8021XProfile::AuthenticationProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AuthenticationProtocol"), ret);
		return ret;
	}
	void AMT_8021XProfile::AuthenticationProtocol(const unsigned short value)
	{
		SetOrAddField("AuthenticationProtocol", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::AuthenticationProtocolExists() const
	{
		return ContainsField("AuthenticationProtocol");
	}
	void AMT_8021XProfile::RemoveAuthenticationProtocol()
	{
		RemoveField("AuthenticationProtocol");
	}

	const string AMT_8021XProfile::RoamingIdentity() const
	{
		return GetField("RoamingIdentity")[0];
	}
	void AMT_8021XProfile::RoamingIdentity(const string &value)
	{
		SetOrAddField("RoamingIdentity", value);
	}
	bool AMT_8021XProfile::RoamingIdentityExists() const
	{
		return ContainsField("RoamingIdentity");
	}
	void AMT_8021XProfile::RemoveRoamingIdentity()
	{
		RemoveField("RoamingIdentity");
	}

	const string AMT_8021XProfile::ServerCertificateName() const
	{
		return GetField("ServerCertificateName")[0];
	}
	void AMT_8021XProfile::ServerCertificateName(const string &value)
	{
		SetOrAddField("ServerCertificateName", value);
	}
	bool AMT_8021XProfile::ServerCertificateNameExists() const
	{
		return ContainsField("ServerCertificateName");
	}
	void AMT_8021XProfile::RemoveServerCertificateName()
	{
		RemoveField("ServerCertificateName");
	}

	const unsigned short AMT_8021XProfile::ServerCertificateNameComparison() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ServerCertificateNameComparison"), ret);
		return ret;
	}
	void AMT_8021XProfile::ServerCertificateNameComparison(const unsigned short value)
	{
		SetOrAddField("ServerCertificateNameComparison", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::ServerCertificateNameComparisonExists() const
	{
		return ContainsField("ServerCertificateNameComparison");
	}
	void AMT_8021XProfile::RemoveServerCertificateNameComparison()
	{
		RemoveField("ServerCertificateNameComparison");
	}

	const string AMT_8021XProfile::Username() const
	{
		return GetField("Username")[0];
	}
	void AMT_8021XProfile::Username(const string &value)
	{
		SetOrAddField("Username", value);
	}
	bool AMT_8021XProfile::UsernameExists() const
	{
		return ContainsField("Username");
	}
	void AMT_8021XProfile::RemoveUsername()
	{
		RemoveField("Username");
	}

	const string AMT_8021XProfile::Password() const
	{
		return GetField("Password")[0];
	}
	void AMT_8021XProfile::Password(const string &value)
	{
		SetOrAddField("Password", value);
	}
	bool AMT_8021XProfile::PasswordExists() const
	{
		return ContainsField("Password");
	}
	void AMT_8021XProfile::RemovePassword()
	{
		RemoveField("Password");
	}

	const string AMT_8021XProfile::Domain() const
	{
		return GetField("Domain")[0];
	}
	void AMT_8021XProfile::Domain(const string &value)
	{
		SetOrAddField("Domain", value);
	}
	bool AMT_8021XProfile::DomainExists() const
	{
		return ContainsField("Domain");
	}
	void AMT_8021XProfile::RemoveDomain()
	{
		RemoveField("Domain");
	}

	const Base64 AMT_8021XProfile::ProtectedAccessCredential() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ProtectedAccessCredential"), ret);
		return ret;
	}
	void AMT_8021XProfile::ProtectedAccessCredential(const Base64 &value)
	{
		SetOrAddField("ProtectedAccessCredential", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::ProtectedAccessCredentialExists() const
	{
		return ContainsField("ProtectedAccessCredential");
	}
	void AMT_8021XProfile::RemoveProtectedAccessCredential()
	{
		RemoveField("ProtectedAccessCredential");
	}

	const string AMT_8021XProfile::PACPassword() const
	{
		return GetField("PACPassword")[0];
	}
	void AMT_8021XProfile::PACPassword(const string &value)
	{
		SetOrAddField("PACPassword", value);
	}
	bool AMT_8021XProfile::PACPasswordExists() const
	{
		return ContainsField("PACPassword");
	}
	void AMT_8021XProfile::RemovePACPassword()
	{
		RemoveField("PACPassword");
	}

	const CimReference AMT_8021XProfile::ClientCertificate() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ClientCertificate"), ret);
		return ret;
	}
	void AMT_8021XProfile::ClientCertificate(const CimReference &value)
	{
		SetOrAddField("ClientCertificate", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::ClientCertificateExists() const
	{
		return ContainsField("ClientCertificate");
	}
	void AMT_8021XProfile::RemoveClientCertificate()
	{
		RemoveField("ClientCertificate");
	}

	const CimReference AMT_8021XProfile::ServerCertificateIssuer() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ServerCertificateIssuer"), ret);
		return ret;
	}
	void AMT_8021XProfile::ServerCertificateIssuer(const CimReference &value)
	{
		SetOrAddField("ServerCertificateIssuer", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::ServerCertificateIssuerExists() const
	{
		return ContainsField("ServerCertificateIssuer");
	}
	void AMT_8021XProfile::RemoveServerCertificateIssuer()
	{
		RemoveField("ServerCertificateIssuer");
	}

	const unsigned int AMT_8021XProfile::PxeTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PxeTimeout"), ret);
		return ret;
	}
	void AMT_8021XProfile::PxeTimeout(const unsigned int value)
	{
		SetOrAddField("PxeTimeout", TypeConverter::TypeToString(value));
	}
	bool AMT_8021XProfile::PxeTimeoutExists() const
	{
		return ContainsField("PxeTimeout");
	}
	void AMT_8021XProfile::RemovePxeTimeout()
	{
		RemoveField("PxeTimeout");
	}

	CimBase *AMT_8021XProfile::CreateFromCimObject(const CimObject &object)
	{
		AMT_8021XProfile *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_8021XProfile>(object);
		}
		else
		{
			ret = new AMT_8021XProfile(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_8021XProfile> > AMT_8021XProfile::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_8021XProfile>(client, keys);
	}

	void AMT_8021XProfile::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_8021XProfile::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_8021XProfile::CLASS_NAME = "AMT_8021XProfile";
	const string AMT_8021XProfile::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_8021XProfile";
	const string AMT_8021XProfile::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_8021XProfile";
	const string AMT_8021XProfile::CLASS_NS_PREFIX = "A80681";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_8021XProfile::_classMetaData;
}
}
}
}
