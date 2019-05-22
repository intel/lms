//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RedirectionService.cpp
//
//  Contents:   RedirectionService provides the capability to manage redirection services. Examples of this include any video stream directed to a Network Port (by the operating system) on a Computer System redirected out to a remote administrator's console. Similarly this can include input redirected into the same Network Port. Other examples include the redirection of IO from a logical element to a remote or local destination. Each redirection stream is accessible via a SAP. This service can support multiple redirection types via multiple associated SAPs.
//
//              This file was automatically generated from CIM_RedirectionService.mof,  version: 2.17.0
//
//----------------------------------------------------------------------------
#include "CIM_RedirectionService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RedirectionService::_metadata[] = {
		{"RedirectionServiceType", false, false, false },
		{"OtherRedirectionServiceType", false, false, false },
		{"MaxCurrentEnabledSAPs", false, false, false },
		{"SharingMode", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_RedirectionService::RedirectionServiceType() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("RedirectionServiceType"), ret);
		return ret;
	}
	void CIM_RedirectionService::RedirectionServiceType(const vector<unsigned short> &value)
	{
		SetOrAddField("RedirectionServiceType", TypeConverter::TypeToString(value));
	}
	bool CIM_RedirectionService::RedirectionServiceTypeExists() const
	{
		return ContainsField("RedirectionServiceType");
	}
	void CIM_RedirectionService::RemoveRedirectionServiceType()
	{
		RemoveField("RedirectionServiceType");
	}

	const string CIM_RedirectionService::OtherRedirectionServiceType() const
	{
		return GetField("OtherRedirectionServiceType")[0];
	}
	void CIM_RedirectionService::OtherRedirectionServiceType(const string &value)
	{
		SetOrAddField("OtherRedirectionServiceType", value);
	}
	bool CIM_RedirectionService::OtherRedirectionServiceTypeExists() const
	{
		return ContainsField("OtherRedirectionServiceType");
	}
	void CIM_RedirectionService::RemoveOtherRedirectionServiceType()
	{
		RemoveField("OtherRedirectionServiceType");
	}

	const unsigned short CIM_RedirectionService::MaxCurrentEnabledSAPs() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxCurrentEnabledSAPs"), ret);
		return ret;
	}
	void CIM_RedirectionService::MaxCurrentEnabledSAPs(const unsigned short value)
	{
		SetOrAddField("MaxCurrentEnabledSAPs", TypeConverter::TypeToString(value));
	}
	bool CIM_RedirectionService::MaxCurrentEnabledSAPsExists() const
	{
		return ContainsField("MaxCurrentEnabledSAPs");
	}
	void CIM_RedirectionService::RemoveMaxCurrentEnabledSAPs()
	{
		RemoveField("MaxCurrentEnabledSAPs");
	}

	const unsigned short CIM_RedirectionService::SharingMode() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SharingMode"), ret);
		return ret;
	}
	void CIM_RedirectionService::SharingMode(const unsigned short value)
	{
		SetOrAddField("SharingMode", TypeConverter::TypeToString(value));
	}
	bool CIM_RedirectionService::SharingModeExists() const
	{
		return ContainsField("SharingMode");
	}
	void CIM_RedirectionService::RemoveSharingMode()
	{
		RemoveField("SharingMode");
	}

	CimBase *CIM_RedirectionService::CreateFromCimObject(const CimObject &object)
	{
		CIM_RedirectionService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RedirectionService>(object);
		}
		else
		{
			ret = new CIM_RedirectionService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RedirectionService> > CIM_RedirectionService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RedirectionService>(client, keys);
	}

	void CIM_RedirectionService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RedirectionService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_RedirectionService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_RedirectionService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_RedirectionService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_RedirectionService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_RedirectionService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_RedirectionService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_RedirectionService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_RedirectionService::CLASS_NAME = "CIM_RedirectionService";
	const string CIM_RedirectionService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RedirectionService";
	const string CIM_RedirectionService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RedirectionService";
	const string CIM_RedirectionService::CLASS_NS_PREFIX = "ARe479";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RedirectionService::_classMetaData;
}
}
}
}
