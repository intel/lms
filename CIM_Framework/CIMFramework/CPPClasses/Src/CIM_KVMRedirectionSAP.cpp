//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_KVMRedirectionSAP.cpp
//
//  Contents:   A class derived from Service Access Point, that describes an access point to start the KVM redirection. One access point represents access to a single KVM redirection stream.
//
//              This file was automatically generated from CIM_KVMRedirectionSAP.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_KVMRedirectionSAP.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_KVMRedirectionSAP::_metadata[] = {
		{"KVMProtocol", false, false, false },
		{"OtherKVMProtocol", false, false, false },
	};
	// class fields
	const unsigned short CIM_KVMRedirectionSAP::KVMProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("KVMProtocol"), ret);
		return ret;
	}
	void CIM_KVMRedirectionSAP::KVMProtocol(const unsigned short value)
	{
		SetOrAddField("KVMProtocol", TypeConverter::TypeToString(value));
	}
	bool CIM_KVMRedirectionSAP::KVMProtocolExists() const
	{
		return ContainsField("KVMProtocol");
	}
	void CIM_KVMRedirectionSAP::RemoveKVMProtocol()
	{
		RemoveField("KVMProtocol");
	}

	const string CIM_KVMRedirectionSAP::OtherKVMProtocol() const
	{
		return GetField("OtherKVMProtocol")[0];
	}
	void CIM_KVMRedirectionSAP::OtherKVMProtocol(const string &value)
	{
		SetOrAddField("OtherKVMProtocol", value);
	}
	bool CIM_KVMRedirectionSAP::OtherKVMProtocolExists() const
	{
		return ContainsField("OtherKVMProtocol");
	}
	void CIM_KVMRedirectionSAP::RemoveOtherKVMProtocol()
	{
		RemoveField("OtherKVMProtocol");
	}

	CimBase *CIM_KVMRedirectionSAP::CreateFromCimObject(const CimObject &object)
	{
		CIM_KVMRedirectionSAP *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_KVMRedirectionSAP>(object);
		}
		else
		{
			ret = new CIM_KVMRedirectionSAP(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_KVMRedirectionSAP> > CIM_KVMRedirectionSAP::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_KVMRedirectionSAP>(client, keys);
	}

	void CIM_KVMRedirectionSAP::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_KVMRedirectionSAP::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_KVMRedirectionSAP::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_KVMRedirectionSAP::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_KVMRedirectionSAP::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_KVMRedirectionSAP::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_KVMRedirectionSAP::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_KVMRedirectionSAP::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_KVMRedirectionSAP::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_KVMRedirectionSAP::CLASS_NAME = "CIM_KVMRedirectionSAP";
	const string CIM_KVMRedirectionSAP::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_KVMRedirectionSAP";
	const string CIM_KVMRedirectionSAP::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_KVMRedirectionSAP";
	const string CIM_KVMRedirectionSAP::CLASS_NS_PREFIX = "AKV256";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_KVMRedirectionSAP::_classMetaData;
}
}
}
}
