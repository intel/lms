//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_FilterCollection.cpp
//
//  Contents:   A FilterCollection is a subclass of CIM_Collection which aggregates instances of CIM_IndicationFilter.
//
//              This file was automatically generated from CIM_FilterCollection.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_FilterCollection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_FilterCollection::_metadata[] = {
		{"InstanceID", true, false, false },
		{"CollectionName", false, false, false },
	};
	// class fields
	const string CIM_FilterCollection::CollectionName() const
	{
		return GetField("CollectionName")[0];
	}
	void CIM_FilterCollection::CollectionName(const string &value)
	{
		SetOrAddField("CollectionName", value);
	}
	bool CIM_FilterCollection::CollectionNameExists() const
	{
		return ContainsField("CollectionName");
	}
	void CIM_FilterCollection::RemoveCollectionName()
	{
		RemoveField("CollectionName");
	}

	CimBase *CIM_FilterCollection::CreateFromCimObject(const CimObject &object)
	{
		CIM_FilterCollection *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_FilterCollection>(object);
		}
		else
		{
			ret = new CIM_FilterCollection(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_FilterCollection> > CIM_FilterCollection::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_FilterCollection>(client, keys);
	}

	void CIM_FilterCollection::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_FilterCollection::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_FilterCollection::CLASS_NAME = "CIM_FilterCollection";
	const string CIM_FilterCollection::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollection";
	const string CIM_FilterCollection::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollection";
	const string CIM_FilterCollection::CLASS_NS_PREFIX = "AFi858";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_FilterCollection::_classMetaData;
}
}
}
}
