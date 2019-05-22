//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Chip.cpp
//
//  Contents:   The Chip class represents any type of integrated circuit hardware, including ASICs, processors, memory chips, etc.
//
//              This file was automatically generated from CIM_Chip.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_Chip.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Chip::_metadata[] = {
		{"FormFactor", false, false, false },
	};
	// class fields
	const unsigned short CIM_Chip::FormFactor() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FormFactor"), ret);
		return ret;
	}
	void CIM_Chip::FormFactor(const unsigned short value)
	{
		SetOrAddField("FormFactor", TypeConverter::TypeToString(value));
	}
	bool CIM_Chip::FormFactorExists() const
	{
		return ContainsField("FormFactor");
	}
	void CIM_Chip::RemoveFormFactor()
	{
		RemoveField("FormFactor");
	}

	CimBase *CIM_Chip::CreateFromCimObject(const CimObject &object)
	{
		CIM_Chip *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Chip>(object);
		}
		else
		{
			ret = new CIM_Chip(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Chip> > CIM_Chip::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Chip>(client, keys);
	}

	void CIM_Chip::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Chip::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Chip::CLASS_NAME = "CIM_Chip";
	const string CIM_Chip::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Chip";
	const string CIM_Chip::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Chip";
	const string CIM_Chip::CLASS_NS_PREFIX = "ACh140";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Chip::_classMetaData;
}
}
}
}
