//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Service.cpp
//
//  Contents:   A Service is a LogicalElement that represents the availability of functionality that can be managed. This functionality may be provided by a seperately modeled entity such as a LogicalDevice or a SoftwareFeature, or both. The modeled Service typically provides only functionality required for management of itself or the elements it affects.
//
//              This file was automatically generated from CIM_Service.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Service::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"PrimaryOwnerName", false, false, false },
		{"PrimaryOwnerContact", false, false, false },
		{"StartMode", false, false, false },
		{"Started", false, false, false },
	};
	// class fields
	const string CIM_Service::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_Service::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_Service::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_Service::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_Service::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_Service::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_Service::PrimaryOwnerName() const
	{
		return GetField("PrimaryOwnerName")[0];
	}
	void CIM_Service::PrimaryOwnerName(const string &value)
	{
		SetOrAddField("PrimaryOwnerName", value);
	}
	bool CIM_Service::PrimaryOwnerNameExists() const
	{
		return ContainsField("PrimaryOwnerName");
	}
	void CIM_Service::RemovePrimaryOwnerName()
	{
		RemoveField("PrimaryOwnerName");
	}

	const string CIM_Service::PrimaryOwnerContact() const
	{
		return GetField("PrimaryOwnerContact")[0];
	}
	void CIM_Service::PrimaryOwnerContact(const string &value)
	{
		SetOrAddField("PrimaryOwnerContact", value);
	}
	bool CIM_Service::PrimaryOwnerContactExists() const
	{
		return ContainsField("PrimaryOwnerContact");
	}
	void CIM_Service::RemovePrimaryOwnerContact()
	{
		RemoveField("PrimaryOwnerContact");
	}

	const string CIM_Service::StartMode() const
	{
		return GetField("StartMode")[0];
	}
	void CIM_Service::StartMode(const string &value)
	{
		SetOrAddField("StartMode", value);
	}
	bool CIM_Service::StartModeExists() const
	{
		return ContainsField("StartMode");
	}
	void CIM_Service::RemoveStartMode()
	{
		RemoveField("StartMode");
	}

	const bool CIM_Service::Started() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Started"), ret);
		return ret;
	}
	void CIM_Service::Started(const bool value)
	{
		SetOrAddField("Started", TypeConverter::TypeToString(value));
	}
	bool CIM_Service::StartedExists() const
	{
		return ContainsField("Started");
	}
	void CIM_Service::RemoveStarted()
	{
		RemoveField("Started");
	}

	CimBase *CIM_Service::CreateFromCimObject(const CimObject &object)
	{
		CIM_Service *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Service>(object);
		}
		else
		{
			ret = new CIM_Service(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Service> > CIM_Service::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Service>(client, keys);
	}

	void CIM_Service::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Service::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_Service::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_Service::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_Service::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Service::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_Service::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_Service::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_Service::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	unsigned int CIM_Service::StartService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartService", input, output);
	}
	unsigned int CIM_Service::StopService()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StopService", input, output);
	}
	const string CIM_Service::CLASS_NAME = "CIM_Service";
	const string CIM_Service::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Service";
	const string CIM_Service::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Service";
	const string CIM_Service::CLASS_NS_PREFIX = "ASe91";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Service::_classMetaData;
}
}
}
}
