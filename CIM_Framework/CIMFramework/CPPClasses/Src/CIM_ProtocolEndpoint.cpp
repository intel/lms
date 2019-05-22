//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProtocolEndpoint.cpp
//
//  Contents:   A communication point from which data can be sent or received. ProtocolEndpoints link system or computer interfaces to LogicalNetworks.
//
//              This file was automatically generated from CIM_ProtocolEndpoint.mof,  version: 2.15.0
//
//----------------------------------------------------------------------------
#include "CIM_ProtocolEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ProtocolEndpoint::_metadata[] = {
		{"Description", false, false, false },
		{"OperationalStatus", false, false, false },
		{"EnabledState", false, false, false },
		{"TimeOfLastStateChange", false, false, false },
		{"Name", true, false, false },
		{"NameFormat", false, false, false },
		{"ProtocolType", false, false, false },
		{"ProtocolIFType", false, false, false },
		{"OtherTypeDescription", false, false, false },
	};
	// class fields
	const string CIM_ProtocolEndpoint::NameFormat() const
	{
		return GetField("NameFormat")[0];
	}
	void CIM_ProtocolEndpoint::NameFormat(const string &value)
	{
		SetOrAddField("NameFormat", value);
	}
	bool CIM_ProtocolEndpoint::NameFormatExists() const
	{
		return ContainsField("NameFormat");
	}
	void CIM_ProtocolEndpoint::RemoveNameFormat()
	{
		RemoveField("NameFormat");
	}

	const unsigned short CIM_ProtocolEndpoint::ProtocolType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ProtocolType"), ret);
		return ret;
	}
	void CIM_ProtocolEndpoint::ProtocolType(const unsigned short value)
	{
		SetOrAddField("ProtocolType", TypeConverter::TypeToString(value));
	}
	bool CIM_ProtocolEndpoint::ProtocolTypeExists() const
	{
		return ContainsField("ProtocolType");
	}
	void CIM_ProtocolEndpoint::RemoveProtocolType()
	{
		RemoveField("ProtocolType");
	}

	const unsigned short CIM_ProtocolEndpoint::ProtocolIFType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ProtocolIFType"), ret);
		return ret;
	}
	void CIM_ProtocolEndpoint::ProtocolIFType(const unsigned short value)
	{
		SetOrAddField("ProtocolIFType", TypeConverter::TypeToString(value));
	}
	bool CIM_ProtocolEndpoint::ProtocolIFTypeExists() const
	{
		return ContainsField("ProtocolIFType");
	}
	void CIM_ProtocolEndpoint::RemoveProtocolIFType()
	{
		RemoveField("ProtocolIFType");
	}

	const string CIM_ProtocolEndpoint::OtherTypeDescription() const
	{
		return GetField("OtherTypeDescription")[0];
	}
	void CIM_ProtocolEndpoint::OtherTypeDescription(const string &value)
	{
		SetOrAddField("OtherTypeDescription", value);
	}
	bool CIM_ProtocolEndpoint::OtherTypeDescriptionExists() const
	{
		return ContainsField("OtherTypeDescription");
	}
	void CIM_ProtocolEndpoint::RemoveOtherTypeDescription()
	{
		RemoveField("OtherTypeDescription");
	}

	CimBase *CIM_ProtocolEndpoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_ProtocolEndpoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ProtocolEndpoint>(object);
		}
		else
		{
			ret = new CIM_ProtocolEndpoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ProtocolEndpoint> > CIM_ProtocolEndpoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ProtocolEndpoint>(client, keys);
	}

	void CIM_ProtocolEndpoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ProtocolEndpoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_ProtocolEndpoint::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_ProtocolEndpoint::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_ProtocolEndpoint::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_ProtocolEndpoint::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_ProtocolEndpoint::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_ProtocolEndpoint::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_ProtocolEndpoint::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_ProtocolEndpoint::CLASS_NAME = "CIM_ProtocolEndpoint";
	const string CIM_ProtocolEndpoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProtocolEndpoint";
	const string CIM_ProtocolEndpoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProtocolEndpoint";
	const string CIM_ProtocolEndpoint::CLASS_NS_PREFIX = "APr171";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ProtocolEndpoint::_classMetaData;
}
}
}
}
