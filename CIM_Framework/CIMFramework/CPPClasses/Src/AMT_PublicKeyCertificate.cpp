//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyCertificate.cpp
//
//  Contents:   This class represents a X.509 Certificate in the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicKeyCertificate.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PublicKeyCertificate.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PublicKeyCertificate::_metadata[] = {
		{"InstanceID", true, false, false },
		{"X509Certificate", false, false, false },
		{"TrustedRootCertficate", false, false, false },
		{"Issuer", false, false, false },
		{"Subject", false, false, false },
	};
	// class fields
	const Base64 AMT_PublicKeyCertificate::X509Certificate() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("X509Certificate"), ret);
		return ret;
	}
	void AMT_PublicKeyCertificate::X509Certificate(const Base64 &value)
	{
		SetOrAddField("X509Certificate", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyCertificate::X509CertificateExists() const
	{
		return ContainsField("X509Certificate");
	}
	void AMT_PublicKeyCertificate::RemoveX509Certificate()
	{
		RemoveField("X509Certificate");
	}

	const bool AMT_PublicKeyCertificate::TrustedRootCertficate() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("TrustedRootCertficate"), ret);
		return ret;
	}
	void AMT_PublicKeyCertificate::TrustedRootCertficate(const bool value)
	{
		SetOrAddField("TrustedRootCertficate", TypeConverter::TypeToString(value));
	}
	bool AMT_PublicKeyCertificate::TrustedRootCertficateExists() const
	{
		return ContainsField("TrustedRootCertficate");
	}
	void AMT_PublicKeyCertificate::RemoveTrustedRootCertficate()
	{
		RemoveField("TrustedRootCertficate");
	}

	const string AMT_PublicKeyCertificate::Issuer() const
	{
		return GetField("Issuer")[0];
	}
	void AMT_PublicKeyCertificate::Issuer(const string &value)
	{
		SetOrAddField("Issuer", value);
	}
	bool AMT_PublicKeyCertificate::IssuerExists() const
	{
		return ContainsField("Issuer");
	}
	void AMT_PublicKeyCertificate::RemoveIssuer()
	{
		RemoveField("Issuer");
	}

	const string AMT_PublicKeyCertificate::Subject() const
	{
		return GetField("Subject")[0];
	}
	void AMT_PublicKeyCertificate::Subject(const string &value)
	{
		SetOrAddField("Subject", value);
	}
	bool AMT_PublicKeyCertificate::SubjectExists() const
	{
		return ContainsField("Subject");
	}
	void AMT_PublicKeyCertificate::RemoveSubject()
	{
		RemoveField("Subject");
	}

	CimBase *AMT_PublicKeyCertificate::CreateFromCimObject(const CimObject &object)
	{
		AMT_PublicKeyCertificate *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PublicKeyCertificate>(object);
		}
		else
		{
			ret = new AMT_PublicKeyCertificate(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PublicKeyCertificate> > AMT_PublicKeyCertificate::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PublicKeyCertificate>(client, keys);
	}

	void AMT_PublicKeyCertificate::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PublicKeyCertificate::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PublicKeyCertificate::CLASS_NAME = "AMT_PublicKeyCertificate";
	const string AMT_PublicKeyCertificate::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyCertificate";
	const string AMT_PublicKeyCertificate::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyCertificate";
	const string AMT_PublicKeyCertificate::CLASS_NS_PREFIX = "APu832";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PublicKeyCertificate::_classMetaData;
}
}
}
}
