//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AssociatedPrivilege.cpp
//
//  Contents:   CIM_AssociatedPrivilege is an association that models the privileges that a Subject element has to access or authorize other elements to access a Target element.
//
//              This file was automatically generated from CIM_AssociatedPrivilege.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_AssociatedPrivilege.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AssociatedPrivilege::_metadata[] = {
		{"Subject", true, false, true },
		{"Target", true, false, true },
		{"UseKey", true, false, false },
		{"PrivilegeGranted", false, false, false },
		{"Activities", false, false, false },
		{"ActivityQualifiers", false, false, false },
		{"QualifierFormats", false, false, false },
		{"RepresentsAuthorizationRights", false, false, false },
	};
	// class fields
	const CimReference CIM_AssociatedPrivilege::Subject() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Subject"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::Subject(const CimReference &value)
	{
		SetOrAddField("Subject", TypeConverter::TypeToString(value));
	}

	const CimReference CIM_AssociatedPrivilege::Target() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Target"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::Target(const CimReference &value)
	{
		SetOrAddField("Target", TypeConverter::TypeToString(value));
	}

	const string CIM_AssociatedPrivilege::UseKey() const
	{
		return GetField("UseKey")[0];
	}
	void CIM_AssociatedPrivilege::UseKey(const string &value)
	{
		SetOrAddField("UseKey", value);
	}

	const bool CIM_AssociatedPrivilege::PrivilegeGranted() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PrivilegeGranted"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::PrivilegeGranted(const bool value)
	{
		SetOrAddField("PrivilegeGranted", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPrivilege::PrivilegeGrantedExists() const
	{
		return ContainsField("PrivilegeGranted");
	}
	void CIM_AssociatedPrivilege::RemovePrivilegeGranted()
	{
		RemoveField("PrivilegeGranted");
	}

	const vector<unsigned short> CIM_AssociatedPrivilege::Activities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Activities"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::Activities(const vector<unsigned short> &value)
	{
		SetOrAddField("Activities", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPrivilege::ActivitiesExists() const
	{
		return ContainsField("Activities");
	}
	void CIM_AssociatedPrivilege::RemoveActivities()
	{
		RemoveField("Activities");
	}

	const vector<string> CIM_AssociatedPrivilege::ActivityQualifiers() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ActivityQualifiers"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::ActivityQualifiers(const vector<string> &value)
	{
		SetOrAddField("ActivityQualifiers", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPrivilege::ActivityQualifiersExists() const
	{
		return ContainsField("ActivityQualifiers");
	}
	void CIM_AssociatedPrivilege::RemoveActivityQualifiers()
	{
		RemoveField("ActivityQualifiers");
	}

	const vector<unsigned short> CIM_AssociatedPrivilege::QualifierFormats() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("QualifierFormats"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::QualifierFormats(const vector<unsigned short> &value)
	{
		SetOrAddField("QualifierFormats", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPrivilege::QualifierFormatsExists() const
	{
		return ContainsField("QualifierFormats");
	}
	void CIM_AssociatedPrivilege::RemoveQualifierFormats()
	{
		RemoveField("QualifierFormats");
	}

	const bool CIM_AssociatedPrivilege::RepresentsAuthorizationRights() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RepresentsAuthorizationRights"), ret);
		return ret;
	}
	void CIM_AssociatedPrivilege::RepresentsAuthorizationRights(const bool value)
	{
		SetOrAddField("RepresentsAuthorizationRights", TypeConverter::TypeToString(value));
	}
	bool CIM_AssociatedPrivilege::RepresentsAuthorizationRightsExists() const
	{
		return ContainsField("RepresentsAuthorizationRights");
	}
	void CIM_AssociatedPrivilege::RemoveRepresentsAuthorizationRights()
	{
		RemoveField("RepresentsAuthorizationRights");
	}

	CimBase *CIM_AssociatedPrivilege::CreateFromCimObject(const CimObject &object)
	{
		CIM_AssociatedPrivilege *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AssociatedPrivilege>(object);
		}
		else
		{
			ret = new CIM_AssociatedPrivilege(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AssociatedPrivilege> > CIM_AssociatedPrivilege::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AssociatedPrivilege>(client, keys);
	}

	void CIM_AssociatedPrivilege::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AssociatedPrivilege::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AssociatedPrivilege::CLASS_NAME = "CIM_AssociatedPrivilege";
	const string CIM_AssociatedPrivilege::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssociatedPrivilege";
	const string CIM_AssociatedPrivilege::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AssociatedPrivilege";
	const string CIM_AssociatedPrivilege::CLASS_NS_PREFIX = "AAs669";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AssociatedPrivilege::_classMetaData;
}
}
}
}
