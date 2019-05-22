//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAccessPoint.cpp
//
//  Contents:   CIM_ServiceAccessPoint represents the ability to utilize or invoke a Service. Access points represent that a Service is made available for other entities to use.
//
//              This file was automatically generated from CIM_ServiceAccessPoint.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceAccessPoint::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
	};
	// class fields
	const string CIM_ServiceAccessPoint::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_ServiceAccessPoint::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_ServiceAccessPoint::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_ServiceAccessPoint::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_ServiceAccessPoint::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_ServiceAccessPoint::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	CimBase *CIM_ServiceAccessPoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceAccessPoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceAccessPoint>(object);
		}
		else
		{
			ret = new CIM_ServiceAccessPoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceAccessPoint> > CIM_ServiceAccessPoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceAccessPoint>(client, keys);
	}

	void CIM_ServiceAccessPoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceAccessPoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_ServiceAccessPoint::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_ServiceAccessPoint::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_ServiceAccessPoint::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_ServiceAccessPoint::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_ServiceAccessPoint::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_ServiceAccessPoint::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_ServiceAccessPoint::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_ServiceAccessPoint::CLASS_NAME = "CIM_ServiceAccessPoint";
	const string CIM_ServiceAccessPoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAccessPoint";
	const string CIM_ServiceAccessPoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAccessPoint";
	const string CIM_ServiceAccessPoint::CLASS_NS_PREFIX = "ASe407";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceAccessPoint::_classMetaData;
}
}
}
}
