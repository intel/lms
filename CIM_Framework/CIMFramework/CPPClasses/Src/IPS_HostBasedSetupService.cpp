//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HostBasedSetupService.cpp
//
//  Contents:   Describes the Host Based Setup Service, which is the logic in Intel(R) AMT that responds to setup requests initiated from the host using OS Administrator credentials. Also provides a method to upgrade to Admin Control mode that can be initiated remotely.
//
//              This file was automatically generated from IPS_HostBasedSetupService.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_HostBasedSetupService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_HostBasedSetupService::_metadata[] = {
		{"CurrentControlMode", false, false, false },
		{"AllowedControlModes", false, false, false },
		{"ConfigurationNonce", false, false, false },
		{"CertChainStatus", false, false, false },
	};
	// class fields
	const unsigned char IPS_HostBasedSetupService::CurrentControlMode() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("CurrentControlMode"), ret);
		return ret;
	}
	void IPS_HostBasedSetupService::CurrentControlMode(const unsigned char &value)
	{
		SetOrAddField("CurrentControlMode", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBasedSetupService::CurrentControlModeExists() const
	{
		return ContainsField("CurrentControlMode");
	}
	void IPS_HostBasedSetupService::RemoveCurrentControlMode()
	{
		RemoveField("CurrentControlMode");
	}

	const vector<unsigned char> IPS_HostBasedSetupService::AllowedControlModes() const
	{
		vector<unsigned char> ret;
		TypeConverter::StringToType(GetField("AllowedControlModes"), ret);
		return ret;
	}
	void IPS_HostBasedSetupService::AllowedControlModes(const vector<unsigned char> &value)
	{
		SetOrAddField("AllowedControlModes", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBasedSetupService::AllowedControlModesExists() const
	{
		return ContainsField("AllowedControlModes");
	}
	void IPS_HostBasedSetupService::RemoveAllowedControlModes()
	{
		RemoveField("AllowedControlModes");
	}

	const Base64 IPS_HostBasedSetupService::ConfigurationNonce() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ConfigurationNonce"), ret);
		return ret;
	}
	void IPS_HostBasedSetupService::ConfigurationNonce(const Base64 &value)
	{
		SetOrAddField("ConfigurationNonce", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBasedSetupService::ConfigurationNonceExists() const
	{
		return ContainsField("ConfigurationNonce");
	}
	void IPS_HostBasedSetupService::RemoveConfigurationNonce()
	{
		RemoveField("ConfigurationNonce");
	}

	const unsigned char IPS_HostBasedSetupService::CertChainStatus() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("CertChainStatus"), ret);
		return ret;
	}
	void IPS_HostBasedSetupService::CertChainStatus(const unsigned char &value)
	{
		SetOrAddField("CertChainStatus", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBasedSetupService::CertChainStatusExists() const
	{
		return ContainsField("CertChainStatus");
	}
	void IPS_HostBasedSetupService::RemoveCertChainStatus()
	{
		RemoveField("CertChainStatus");
	}

	CimBase *IPS_HostBasedSetupService::CreateFromCimObject(const CimObject &object)
	{
		IPS_HostBasedSetupService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_HostBasedSetupService>(object);
		}
		else
		{
			ret = new IPS_HostBasedSetupService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_HostBasedSetupService> > IPS_HostBasedSetupService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_HostBasedSetupService>(client, keys);
	}

	void IPS_HostBasedSetupService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_HostBasedSetupService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_HostBasedSetupService::Setup_INPUT::_metadata[] = {
		{"NetAdminPassEncryptionType", false, true },
		{"NetworkAdminPassword", false, true },
		{"McNonce", false, false },
		{"Certificate", false, false },
		{"SigningAlgorithm", false, false },
		{"DigitalSignature", false, false },
	};
	void IPS_HostBasedSetupService::Setup_INPUT::NetAdminPassEncryptionType(const unsigned short value)
	{
		SetOrAddField("NetAdminPassEncryptionType", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::Setup_INPUT::NetworkAdminPassword(const HexBinary &value)
	{
		SetOrAddField("NetworkAdminPassword", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::Setup_INPUT::McNonce(const Base64 &value)
	{
		SetOrAddField("McNonce", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::Setup_INPUT::Certificate(const Base64 &value)
	{
		SetOrAddField("Certificate", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::Setup_INPUT::SigningAlgorithm(const unsigned short value)
	{
		SetOrAddField("SigningAlgorithm", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::Setup_INPUT::DigitalSignature(const Base64 &value)
	{
		SetOrAddField("DigitalSignature", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_HostBasedSetupService::Setup_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 6);
		return ret;
	}
	unsigned int IPS_HostBasedSetupService::Setup(const Setup_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("Setup", input, output);
	}
	const CimFieldAttribute IPS_HostBasedSetupService::AddNextCertInChain_INPUT::_metadata[] = {
		{"NextCertificate", false, true },
		{"IsLeafCertificate", false, false },
		{"IsRootCertificate", false, false },
	};
	void IPS_HostBasedSetupService::AddNextCertInChain_INPUT::NextCertificate(const Base64 &value)
	{
		SetOrAddField("NextCertificate", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AddNextCertInChain_INPUT::IsLeafCertificate(const bool value)
	{
		SetOrAddField("IsLeafCertificate", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AddNextCertInChain_INPUT::IsRootCertificate(const bool value)
	{
		SetOrAddField("IsRootCertificate", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_HostBasedSetupService::AddNextCertInChain_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int IPS_HostBasedSetupService::AddNextCertInChain(const AddNextCertInChain_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AddNextCertInChain", input, output);
	}
	const CimFieldAttribute IPS_HostBasedSetupService::AdminSetup_INPUT::_metadata[] = {
		{"NetAdminPassEncryptionType", false, true },
		{"NetworkAdminPassword", false, true },
		{"McNonce", false, false },
		{"SigningAlgorithm", false, false },
		{"DigitalSignature", false, false },
	};
	void IPS_HostBasedSetupService::AdminSetup_INPUT::NetAdminPassEncryptionType(const unsigned short value)
	{
		SetOrAddField("NetAdminPassEncryptionType", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AdminSetup_INPUT::NetworkAdminPassword(const HexBinary &value)
	{
		SetOrAddField("NetworkAdminPassword", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AdminSetup_INPUT::McNonce(const Base64 &value)
	{
		SetOrAddField("McNonce", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AdminSetup_INPUT::SigningAlgorithm(const unsigned short value)
	{
		SetOrAddField("SigningAlgorithm", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::AdminSetup_INPUT::DigitalSignature(const Base64 &value)
	{
		SetOrAddField("DigitalSignature", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_HostBasedSetupService::AdminSetup_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	unsigned int IPS_HostBasedSetupService::AdminSetup(const AdminSetup_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AdminSetup", input, output);
	}
	const CimFieldAttribute IPS_HostBasedSetupService::UpgradeClientToAdmin_INPUT::_metadata[] = {
		{"McNonce", false, false },
		{"SigningAlgorithm", false, false },
		{"DigitalSignature", false, false },
	};
	void IPS_HostBasedSetupService::UpgradeClientToAdmin_INPUT::McNonce(const Base64 &value)
	{
		SetOrAddField("McNonce", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::UpgradeClientToAdmin_INPUT::SigningAlgorithm(const unsigned short value)
	{
		SetOrAddField("SigningAlgorithm", TypeConverter::TypeToString(value));
	}
	void IPS_HostBasedSetupService::UpgradeClientToAdmin_INPUT::DigitalSignature(const Base64 &value)
	{
		SetOrAddField("DigitalSignature", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_HostBasedSetupService::UpgradeClientToAdmin_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int IPS_HostBasedSetupService::UpgradeClientToAdmin(const UpgradeClientToAdmin_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UpgradeClientToAdmin", input, output);
	}
	unsigned int IPS_HostBasedSetupService::DisableClientControlMode()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("DisableClientControlMode", input, output);
	}
	const string IPS_HostBasedSetupService::CLASS_NAME = "IPS_HostBasedSetupService";
	const string IPS_HostBasedSetupService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostBasedSetupService";
	const string IPS_HostBasedSetupService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostBasedSetupService";
	const string IPS_HostBasedSetupService::CLASS_NS_PREFIX = "AHo608";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_HostBasedSetupService::_classMetaData;
}
}
}
}
