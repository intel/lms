//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalElement.cpp
//
//  Contents:   CIM_LogicalElement is a base class for all the components of a System that represent abstract system components, such as Files, Processes, or LogicalDevices.
//
//              This file was automatically generated from CIM_LogicalElement.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_LogicalElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogicalElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogicalElement>(object);
		}
		else
		{
			ret = new CIM_LogicalElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogicalElement> > CIM_LogicalElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogicalElement>(client, keys);
	}

	void CIM_LogicalElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogicalElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_LogicalElement::CLASS_NAME = "CIM_LogicalElement";
	const string CIM_LogicalElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalElement";
	const string CIM_LogicalElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogicalElement";
	const string CIM_LogicalElement::CLASS_NS_PREFIX = "ALo909";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogicalElement::_classMetaData;
}
}
}
}
