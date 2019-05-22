//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteAccessAvailableToElement.cpp
//
//  Contents:   Describes an element's knowledge regarding accessing other (i.e., remote) Servers and Systems.
//
//              This file was automatically generated from CIM_RemoteAccessAvailableToElement.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_RemoteAccessAvailableToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RemoteAccessAvailableToElement::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"IsDefault", false, false, false },
		{"OrderOfAccess", false, false, false },
	};
	// class fields
	const bool CIM_RemoteAccessAvailableToElement::IsDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsDefault"), ret);
		return ret;
	}
	void CIM_RemoteAccessAvailableToElement::IsDefault(const bool value)
	{
		SetOrAddField("IsDefault", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteAccessAvailableToElement::IsDefaultExists() const
	{
		return ContainsField("IsDefault");
	}
	void CIM_RemoteAccessAvailableToElement::RemoveIsDefault()
	{
		RemoveField("IsDefault");
	}

	const unsigned short CIM_RemoteAccessAvailableToElement::OrderOfAccess() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OrderOfAccess"), ret);
		return ret;
	}
	void CIM_RemoteAccessAvailableToElement::OrderOfAccess(const unsigned short value)
	{
		SetOrAddField("OrderOfAccess", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteAccessAvailableToElement::OrderOfAccessExists() const
	{
		return ContainsField("OrderOfAccess");
	}
	void CIM_RemoteAccessAvailableToElement::RemoveOrderOfAccess()
	{
		RemoveField("OrderOfAccess");
	}

	CimBase *CIM_RemoteAccessAvailableToElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_RemoteAccessAvailableToElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RemoteAccessAvailableToElement>(object);
		}
		else
		{
			ret = new CIM_RemoteAccessAvailableToElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RemoteAccessAvailableToElement> > CIM_RemoteAccessAvailableToElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RemoteAccessAvailableToElement>(client, keys);
	}

	void CIM_RemoteAccessAvailableToElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RemoteAccessAvailableToElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RemoteAccessAvailableToElement::CLASS_NAME = "CIM_RemoteAccessAvailableToElement";
	const string CIM_RemoteAccessAvailableToElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteAccessAvailableToElement";
	const string CIM_RemoteAccessAvailableToElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteAccessAvailableToElement";
	const string CIM_RemoteAccessAvailableToElement::CLASS_NS_PREFIX = "ARe598";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RemoteAccessAvailableToElement::_classMetaData;
}
}
}
}
