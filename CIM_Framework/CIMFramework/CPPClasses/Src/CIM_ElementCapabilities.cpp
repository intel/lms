//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementCapabilities.cpp
//
//  Contents:   ElementCapabilities represents the association between ManagedElements and their Capabilities. Note that the cardinality of the ManagedElement reference is Min(1). This cardinality mandates the instantiation of the ElementCapabilities association for the referenced instance of Capabilities. ElementCapabilities describes the existence requirements and context for the referenced instance of ManagedElement. Specifically, the ManagedElement MUST exist and provides the context for the Capabilities.
//
//              This file was automatically generated from CIM_ElementCapabilities.mof,  version: 2.24.0
//
//----------------------------------------------------------------------------
#include "CIM_ElementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementCapabilities::_metadata[] = {
		{"ManagedElement", true, false, true },
		{"Capabilities", true, false, true },
		{"Characteristics", false, false, false },
	};
	// class fields
	const CimReference CIM_ElementCapabilities::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_ElementCapabilities::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ElementCapabilities::Capabilities() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Capabilities"), ret);
		return ret;
	}
	void CIM_ElementCapabilities::Capabilities(const CimReference &value)
	{
		SetOrAddField("Capabilities", TypeConverter::TypeToString(value));
	}

	const vector<unsigned short> CIM_ElementCapabilities::Characteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Characteristics"), ret);
		return ret;
	}
	void CIM_ElementCapabilities::Characteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("Characteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementCapabilities::CharacteristicsExists() const
	{
		return ContainsField("Characteristics");
	}
	void CIM_ElementCapabilities::RemoveCharacteristics()
	{
		RemoveField("Characteristics");
	}

	CimBase *CIM_ElementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementCapabilities>(object);
		}
		else
		{
			ret = new CIM_ElementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementCapabilities> > CIM_ElementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementCapabilities>(client, keys);
	}

	void CIM_ElementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementCapabilities::CLASS_NAME = "CIM_ElementCapabilities";
	const string CIM_ElementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementCapabilities";
	const string CIM_ElementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementCapabilities";
	const string CIM_ElementCapabilities::CLASS_NS_PREFIX = "AEl426";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementCapabilities::_classMetaData;
}
}
}
}
