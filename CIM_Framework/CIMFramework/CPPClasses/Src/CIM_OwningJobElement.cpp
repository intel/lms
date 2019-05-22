//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OwningJobElement.cpp
//
//  Contents:   OwningJobElement represents an association between a Job and the ManagedElement responsible for the creation of the Job. This association may not be possible, given that the execution of jobs can move between systems and that the lifecycle of the creating entity may not persist for the total duration of the job. However, this can be very useful information when available. This association defines a more specific 'owner' than is provided by the CIM_Job.Owner string.
//
//              This file was automatically generated from CIM_OwningJobElement.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_OwningJobElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_OwningJobElement::_metadata[] = {
		{"OwningElement", true, false, true },
		{"OwnedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_OwningJobElement::OwningElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("OwningElement"), ret);
		return ret;
	}
	void CIM_OwningJobElement::OwningElement(const CimReference &value)
	{
		SetOrAddField("OwningElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_OwningJobElement::OwnedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("OwnedElement"), ret);
		return ret;
	}
	void CIM_OwningJobElement::OwnedElement(const CimReference &value)
	{
		SetOrAddField("OwnedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_OwningJobElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_OwningJobElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_OwningJobElement>(object);
		}
		else
		{
			ret = new CIM_OwningJobElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_OwningJobElement> > CIM_OwningJobElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_OwningJobElement>(client, keys);
	}

	void CIM_OwningJobElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_OwningJobElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_OwningJobElement::CLASS_NAME = "CIM_OwningJobElement";
	const string CIM_OwningJobElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OwningJobElement";
	const string CIM_OwningJobElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OwningJobElement";
	const string CIM_OwningJobElement::CLASS_NS_PREFIX = "AOw555";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_OwningJobElement::_classMetaData;
}
}
}
}
