//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementConformsToProfile.cpp
//
//  Contents:   The CIM_ElementConformsToProfile association defines the RegisteredProfiles to which the referenced ManagedElement is conformant. Note: This association may apply to any Managed Element. Typical usage will apply it to a higher level instance, such as a System, NameSpace, or Service. When applied to a higher level instance, all constituent parts MUST behave appropriately in support of the ManagedElement's conformance to the named RegisteredProfile.
//
//              This file was automatically generated from CIM_ElementConformsToProfile.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_ElementConformsToProfile.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementConformsToProfile::_metadata[] = {
		{"ConformantStandard", true, false, true },
		{"ManagedElement", true, false, true },
	};
	// class fields
	const CimReference CIM_ElementConformsToProfile::ConformantStandard() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ConformantStandard"), ret);
		return ret;
	}
	void CIM_ElementConformsToProfile::ConformantStandard(const CimReference &value)
	{
		SetOrAddField("ConformantStandard", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_ElementConformsToProfile::ManagedElement() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("ManagedElement"), ret);
		return ret;
	}
	void CIM_ElementConformsToProfile::ManagedElement(const CimReference &value)
	{
		SetOrAddField("ManagedElement", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_ElementConformsToProfile::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementConformsToProfile *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementConformsToProfile>(object);
		}
		else
		{
			ret = new CIM_ElementConformsToProfile(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementConformsToProfile> > CIM_ElementConformsToProfile::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementConformsToProfile>(client, keys);
	}

	void CIM_ElementConformsToProfile::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementConformsToProfile::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementConformsToProfile::CLASS_NAME = "CIM_ElementConformsToProfile";
	const string CIM_ElementConformsToProfile::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementConformsToProfile";
	const string CIM_ElementConformsToProfile::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementConformsToProfile";
	const string CIM_ElementConformsToProfile::CLASS_NS_PREFIX = "AEl43";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementConformsToProfile::_classMetaData;
}
}
}
}
