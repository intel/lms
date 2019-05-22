//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementStatisticalData.cpp
//
//  Contents:   CIM_ElementStatisticalData is an association that relates a ManagedElement to its StatisticalData. Note that the cardinality of the ManagedElement reference is Min(1), Max(1). This cardinality mandates the instantiation of the ElementStatisticalData association for the referenced instance of CIM_StatisticalData. ElementStatisticalData describes the existence requirements and context for the CIM_StatisticalData, relative to a specific ManagedElement.
//
//              This file was automatically generated from CIM_ElementStatisticalData.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_ElementStatisticalData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementStatisticalData::_metadata[] = {
		{"ManagedElement", true, false, true },
		{"Stats", true, false, true },
	};
	// class fields
	const CimReference CIM_ElementStatisticalData::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_ElementStatisticalData::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ElementStatisticalData::Stats() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Stats"), ret);
		return ret;
	}
	void CIM_ElementStatisticalData::Stats(const CimReference &value)
	{
		SetOrAddField("Stats", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_ElementStatisticalData::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementStatisticalData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementStatisticalData>(object);
		}
		else
		{
			ret = new CIM_ElementStatisticalData(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementStatisticalData> > CIM_ElementStatisticalData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementStatisticalData>(client, keys);
	}

	void CIM_ElementStatisticalData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementStatisticalData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementStatisticalData::CLASS_NAME = "CIM_ElementStatisticalData";
	const string CIM_ElementStatisticalData::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementStatisticalData";
	const string CIM_ElementStatisticalData::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementStatisticalData";
	const string CIM_ElementStatisticalData::CLASS_NS_PREFIX = "AEl735";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementStatisticalData::_classMetaData;
}
}
}
}
