//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSFeature.cpp
//
//  Contents:   BIOSFeature represents the capabilities of the low-level software that is used to bring up and configure a Computer System.
//
//              This file was automatically generated from CIM_BIOSFeature.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_BIOSFeature.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BIOSFeature::_metadata[] = {
		{"Characteristics", false, false, false },
		{"CharacteristicDescriptions", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_BIOSFeature::Characteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Characteristics"), ret);
		return ret;
	}
	void CIM_BIOSFeature::Characteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("Characteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSFeature::CharacteristicsExists() const
	{
		return ContainsField("Characteristics");
	}
	void CIM_BIOSFeature::RemoveCharacteristics()
	{
		RemoveField("Characteristics");
	}

	const vector<string> CIM_BIOSFeature::CharacteristicDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CharacteristicDescriptions"), ret);
		return ret;
	}
	void CIM_BIOSFeature::CharacteristicDescriptions(const vector<string> &value)
	{
		SetOrAddField("CharacteristicDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSFeature::CharacteristicDescriptionsExists() const
	{
		return ContainsField("CharacteristicDescriptions");
	}
	void CIM_BIOSFeature::RemoveCharacteristicDescriptions()
	{
		RemoveField("CharacteristicDescriptions");
	}

	CimBase *CIM_BIOSFeature::CreateFromCimObject(const CimObject &object)
	{
		CIM_BIOSFeature *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BIOSFeature>(object);
		}
		else
		{
			ret = new CIM_BIOSFeature(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BIOSFeature> > CIM_BIOSFeature::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BIOSFeature>(client, keys);
	}

	void CIM_BIOSFeature::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BIOSFeature::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_BIOSFeature::CLASS_NAME = "CIM_BIOSFeature";
	const string CIM_BIOSFeature::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSFeature";
	const string CIM_BIOSFeature::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSFeature";
	const string CIM_BIOSFeature::CLASS_NS_PREFIX = "ABI187";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BIOSFeature::_classMetaData;
}
}
}
}
