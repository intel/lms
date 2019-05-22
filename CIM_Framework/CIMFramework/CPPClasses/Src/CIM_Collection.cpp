//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Collection.cpp
//
//  Contents:   Collection is an abstract class that provides a common superclass for data elements that represent collections of ManagedElements and its subclasses.
//
//              This file was automatically generated from CIM_Collection.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_Collection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_Collection::CreateFromCimObject(const CimObject &object)
	{
		CIM_Collection *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Collection>(object);
		}
		else
		{
			ret = new CIM_Collection(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Collection> > CIM_Collection::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Collection>(client, keys);
	}

	void CIM_Collection::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Collection::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Collection::CLASS_NAME = "CIM_Collection";
	const string CIM_Collection::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Collection";
	const string CIM_Collection::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Collection";
	const string CIM_Collection::CLASS_NS_PREFIX = "ACo818";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Collection::_classMetaData;
}
}
}
}
