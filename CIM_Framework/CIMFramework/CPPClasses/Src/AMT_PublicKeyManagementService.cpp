//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyManagementService.cpp
//
//  Contents:   This service contains the information necessary to represent and manage the functionality provided by the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicKeyManagementService.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PublicKeyManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_PublicKeyManagementService::CreateFromCimObject(const CimObject &object)
	{
		AMT_PublicKeyManagementService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PublicKeyManagementService>(object);
		}
		else
		{
			ret = new AMT_PublicKeyManagementService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PublicKeyManagementService> > AMT_PublicKeyManagementService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PublicKeyManagementService>(client, keys);
	}

	void AMT_PublicKeyManagementService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PublicKeyManagementService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::AddCRL_INPUT::_metadata[] = {
		{"Url", false, false },
		{"SerialNumbers", false, false },
	};
	void AMT_PublicKeyManagementService::AddCRL_INPUT::Url(const string &value)
	{
		SetOrAddField("Url", value);
	}
	void AMT_PublicKeyManagementService::AddCRL_INPUT::SerialNumbers(const vector<string> &value)
	{
		SetOrAddField("SerialNumbers", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::AddCRL_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_PublicKeyManagementService::AddCRL_OUTPUT::CRL() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("CRL"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::AddCRL_OUTPUT::CRLExists() const
	{
		return ContainsField("CRL");
	}
	unsigned int AMT_PublicKeyManagementService::AddCRL(const AddCRL_INPUT &input, AddCRL_OUTPUT &output)
	{
		return Invoke("AddCRL", input, output);
	}
	unsigned int AMT_PublicKeyManagementService::ResetCRLList()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ResetCRLList", input, output);
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::AddCertificate_INPUT::_metadata[] = {
		{"CertificateBlob", false, true },
	};
	void AMT_PublicKeyManagementService::AddCertificate_INPUT::CertificateBlob(const Base64 &value)
	{
		SetOrAddField("CertificateBlob", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::AddCertificate_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const CimReference AMT_PublicKeyManagementService::AddCertificate_OUTPUT::CreatedCertificate() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("CreatedCertificate"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::AddCertificate_OUTPUT::CreatedCertificateExists() const
	{
		return ContainsField("CreatedCertificate");
	}
	unsigned int AMT_PublicKeyManagementService::AddCertificate(const AddCertificate_INPUT &input, AddCertificate_OUTPUT &output)
	{
		return Invoke("AddCertificate", input, output);
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::AddTrustedRootCertificate_INPUT::_metadata[] = {
		{"CertificateBlob", false, true },
	};
	void AMT_PublicKeyManagementService::AddTrustedRootCertificate_INPUT::CertificateBlob(const Base64 &value)
	{
		SetOrAddField("CertificateBlob", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::AddTrustedRootCertificate_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const CimReference AMT_PublicKeyManagementService::AddTrustedRootCertificate_OUTPUT::CreatedCertificate() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("CreatedCertificate"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::AddTrustedRootCertificate_OUTPUT::CreatedCertificateExists() const
	{
		return ContainsField("CreatedCertificate");
	}
	unsigned int AMT_PublicKeyManagementService::AddTrustedRootCertificate(const AddTrustedRootCertificate_INPUT &input, AddTrustedRootCertificate_OUTPUT &output)
	{
		return Invoke("AddTrustedRootCertificate", input, output);
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::AddKey_INPUT::_metadata[] = {
		{"KeyBlob", false, true },
	};
	void AMT_PublicKeyManagementService::AddKey_INPUT::KeyBlob(const Base64 &value)
	{
		SetOrAddField("KeyBlob", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::AddKey_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const CimReference AMT_PublicKeyManagementService::AddKey_OUTPUT::CreatedKey() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("CreatedKey"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::AddKey_OUTPUT::CreatedKeyExists() const
	{
		return ContainsField("CreatedKey");
	}
	unsigned int AMT_PublicKeyManagementService::AddKey(const AddKey_INPUT &input, AddKey_OUTPUT &output)
	{
		return Invoke("AddKey", input, output);
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_INPUT::_metadata[] = {
		{"KeyPair", false, true },
		{"SigningAlgorithm", false, true },
		{"NullSignedCertificateRequest", false, true },
	};
	void AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_INPUT::KeyPair(const CimReference &value)
	{
		SetOrAddField("KeyPair", TypeConverter::TypeToString(value));
	}
	void AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_INPUT::SigningAlgorithm(const unsigned int value)
	{
		SetOrAddField("SigningAlgorithm", TypeConverter::TypeToString(value));
	}
	void AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_INPUT::NullSignedCertificateRequest(const Base64 &value)
	{
		SetOrAddField("NullSignedCertificateRequest", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const Base64 AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_OUTPUT::SignedCertificateRequest() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("SignedCertificateRequest"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::GeneratePKCS10RequestEx_OUTPUT::SignedCertificateRequestExists() const
	{
		return ContainsField("SignedCertificateRequest");
	}
	unsigned int AMT_PublicKeyManagementService::GeneratePKCS10RequestEx(const GeneratePKCS10RequestEx_INPUT &input, GeneratePKCS10RequestEx_OUTPUT &output)
	{
		return Invoke("GeneratePKCS10RequestEx", input, output);
	}
	const CimFieldAttribute AMT_PublicKeyManagementService::GenerateKeyPair_INPUT::_metadata[] = {
		{"KeyAlgorithm", false, true },
		{"KeyLength", false, true },
	};
	void AMT_PublicKeyManagementService::GenerateKeyPair_INPUT::KeyAlgorithm(const unsigned int value)
	{
		SetOrAddField("KeyAlgorithm", TypeConverter::TypeToString(value));
	}
	void AMT_PublicKeyManagementService::GenerateKeyPair_INPUT::KeyLength(const unsigned int value)
	{
		SetOrAddField("KeyLength", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_PublicKeyManagementService::GenerateKeyPair_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference AMT_PublicKeyManagementService::GenerateKeyPair_OUTPUT::KeyPair() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("KeyPair"), ret);
		return ret;
	}
	bool AMT_PublicKeyManagementService::GenerateKeyPair_OUTPUT::KeyPairExists() const
	{
		return ContainsField("KeyPair");
	}
	unsigned int AMT_PublicKeyManagementService::GenerateKeyPair(const GenerateKeyPair_INPUT &input, GenerateKeyPair_OUTPUT &output)
	{
		return Invoke("GenerateKeyPair", input, output);
	}
	const string AMT_PublicKeyManagementService::CLASS_NAME = "AMT_PublicKeyManagementService";
	const string AMT_PublicKeyManagementService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyManagementService";
	const string AMT_PublicKeyManagementService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PublicKeyManagementService";
	const string AMT_PublicKeyManagementService::CLASS_NS_PREFIX = "APu509";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PublicKeyManagementService::_classMetaData;
}
}
}
}
