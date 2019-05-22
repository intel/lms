//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_InstalledSoftwareIdentity.cpp
//
//  Contents:   The InstalledSoftwareIdentity association identifies the System on which a SoftwareIdentity is installed. This class is a corollary to InstalledSoftwareElement, but deals with the asset aspects of software (as indicated by SoftwareIdentity), versus the deployment aspects (as indicated by SoftwareElement).
//
//              This file was automatically generated from CIM_InstalledSoftwareIdentity.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_InstalledSoftwareIdentity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_InstalledSoftwareIdentity::_metadata[] = {
		{"System", true, false, true },
		{"InstalledSoftware", true, false, true },
	};
	// class fields
	const CimReference CIM_InstalledSoftwareIdentity::System() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("System"), ret);
		return ret;
	}
	void CIM_InstalledSoftwareIdentity::System(const CimReference &value)
	{
		SetOrAddField("System", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_InstalledSoftwareIdentity::InstalledSoftware() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("InstalledSoftware"), ret);
		return ret;
	}
	void CIM_InstalledSoftwareIdentity::InstalledSoftware(const CimReference &value)
	{
		SetOrAddField("InstalledSoftware", TypeConverter::TypeToString(value));
	}

	CimBase *CIM_InstalledSoftwareIdentity::CreateFromCimObject(const CimObject &object)
	{
		CIM_InstalledSoftwareIdentity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_InstalledSoftwareIdentity>(object);
		}
		else
		{
			ret = new CIM_InstalledSoftwareIdentity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_InstalledSoftwareIdentity> > CIM_InstalledSoftwareIdentity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_InstalledSoftwareIdentity>(client, keys);
	}

	void CIM_InstalledSoftwareIdentity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_InstalledSoftwareIdentity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_InstalledSoftwareIdentity::CLASS_NAME = "CIM_InstalledSoftwareIdentity";
	const string CIM_InstalledSoftwareIdentity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_InstalledSoftwareIdentity";
	const string CIM_InstalledSoftwareIdentity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_InstalledSoftwareIdentity";
	const string CIM_InstalledSoftwareIdentity::CLASS_NS_PREFIX = "AIn583";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_InstalledSoftwareIdentity::_classMetaData;
}
}
}
}
