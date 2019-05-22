//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SharedCredential.cpp
//
//  Contents:   SharedCredential is a secret (such as a password or the response to a challenge question) that is shared between a principal and a particular SharedCredential security service. Secrets may be in the form of a password used for initial authentication, or as with a session key, used as part of a message to verify the originator of the message. It is important to note that SharedCredential is not just a password, but rather is the password used with a particular security service.
//
//              This file was automatically generated from CIM_SharedCredential.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_SharedCredential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SharedCredential::_metadata[] = {
		{"InstanceID", true, false, false },
		{"RemoteID", false, false, false },
		{"Secret", false, false, false },
		{"Algorithm", false, false, false },
		{"Protocol", false, false, false },
	};
	// class fields
	const string CIM_SharedCredential::RemoteID() const
	{
		return GetField("RemoteID")[0];
	}
	void CIM_SharedCredential::RemoteID(const string &value)
	{
		SetOrAddField("RemoteID", value);
	}
	bool CIM_SharedCredential::RemoteIDExists() const
	{
		return ContainsField("RemoteID");
	}
	void CIM_SharedCredential::RemoveRemoteID()
	{
		RemoveField("RemoteID");
	}

	const string CIM_SharedCredential::Secret() const
	{
		return GetField("Secret")[0];
	}
	void CIM_SharedCredential::Secret(const string &value)
	{
		SetOrAddField("Secret", value);
	}
	bool CIM_SharedCredential::SecretExists() const
	{
		return ContainsField("Secret");
	}
	void CIM_SharedCredential::RemoveSecret()
	{
		RemoveField("Secret");
	}

	const string CIM_SharedCredential::Algorithm() const
	{
		return GetField("Algorithm")[0];
	}
	void CIM_SharedCredential::Algorithm(const string &value)
	{
		SetOrAddField("Algorithm", value);
	}
	bool CIM_SharedCredential::AlgorithmExists() const
	{
		return ContainsField("Algorithm");
	}
	void CIM_SharedCredential::RemoveAlgorithm()
	{
		RemoveField("Algorithm");
	}

	const string CIM_SharedCredential::Protocol() const
	{
		return GetField("Protocol")[0];
	}
	void CIM_SharedCredential::Protocol(const string &value)
	{
		SetOrAddField("Protocol", value);
	}
	bool CIM_SharedCredential::ProtocolExists() const
	{
		return ContainsField("Protocol");
	}
	void CIM_SharedCredential::RemoveProtocol()
	{
		RemoveField("Protocol");
	}

	CimBase *CIM_SharedCredential::CreateFromCimObject(const CimObject &object)
	{
		CIM_SharedCredential *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SharedCredential>(object);
		}
		else
		{
			ret = new CIM_SharedCredential(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SharedCredential> > CIM_SharedCredential::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SharedCredential>(client, keys);
	}

	void CIM_SharedCredential::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SharedCredential::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SharedCredential::CLASS_NAME = "CIM_SharedCredential";
	const string CIM_SharedCredential::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SharedCredential";
	const string CIM_SharedCredential::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SharedCredential";
	const string CIM_SharedCredential::CLASS_NS_PREFIX = "ASh356";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SharedCredential::_classMetaData;
}
}
}
}
