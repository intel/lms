//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OwningCollectionElement.cpp
//
//  Contents:   OwningCollectionElement represents an association between a Collection and the ManagedElement responsible for the control or ownership of the Collection.
//
//              This file was automatically generated from CIM_OwningCollectionElement.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_OwningCollectionElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_OwningCollectionElement::_metadata[] = {
		{"OwningElement", true, false, true },
		{"OwnedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_OwningCollectionElement::OwningElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("OwningElement"), ret);
		return ret;
	}
	void CIM_OwningCollectionElement::OwningElement(const CimReference &value)
	{
		SetOrAddField("OwningElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_OwningCollectionElement::OwnedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("OwnedElement"), ret);
		return ret;
	}
	void CIM_OwningCollectionElement::OwnedElement(const CimReference &value)
	{
		SetOrAddField("OwnedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_OwningCollectionElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_OwningCollectionElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_OwningCollectionElement>(object);
		}
		else
		{
			ret = new CIM_OwningCollectionElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_OwningCollectionElement> > CIM_OwningCollectionElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_OwningCollectionElement>(client, keys);
	}

	void CIM_OwningCollectionElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_OwningCollectionElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_OwningCollectionElement::CLASS_NAME = "CIM_OwningCollectionElement";
	const string CIM_OwningCollectionElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OwningCollectionElement";
	const string CIM_OwningCollectionElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_OwningCollectionElement";
	const string CIM_OwningCollectionElement::CLASS_NS_PREFIX = "AOw814";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_OwningCollectionElement::_classMetaData;
}
}
}
}
