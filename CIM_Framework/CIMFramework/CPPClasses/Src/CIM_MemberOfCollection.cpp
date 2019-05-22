//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MemberOfCollection.cpp
//
//  Contents:   CIM_MemberOfCollection is an aggregation used to establish membership of ManagedElements in a Collection.
//
//              This file was automatically generated from CIM_MemberOfCollection.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_MemberOfCollection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_MemberOfCollection::_metadata[] = {
		{"Collection", true, false, true },
		{"Member", true, false, true },
	};
	// class fields
	const CimReference CIM_MemberOfCollection::Collection() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Collection"), ret);
		return ret;
	}
	void CIM_MemberOfCollection::Collection(const CimReference &value)
	{
		SetOrAddField("Collection", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_MemberOfCollection::Member() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Member"), ret);
		return ret;
	}
	void CIM_MemberOfCollection::Member(const CimReference &value)
	{
		SetOrAddField("Member", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_MemberOfCollection::CreateFromCimObject(const CimObject &object)
	{
		CIM_MemberOfCollection *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_MemberOfCollection>(object);
		}
		else
		{
			ret = new CIM_MemberOfCollection(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_MemberOfCollection> > CIM_MemberOfCollection::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_MemberOfCollection>(client, keys);
	}

	void CIM_MemberOfCollection::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_MemberOfCollection::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_MemberOfCollection::CLASS_NAME = "CIM_MemberOfCollection";
	const string CIM_MemberOfCollection::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MemberOfCollection";
	const string CIM_MemberOfCollection::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MemberOfCollection";
	const string CIM_MemberOfCollection::CLASS_NS_PREFIX = "AMe575";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_MemberOfCollection::_classMetaData;
}
}
}
}
