//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Privilege.cpp
//
//  Contents:   Privilege is the base class for all types of activities which are granted or denied by a Role or an Identity. Whether an individual Privilege is granted or denied is defined using the PrivilegeGranted boolean. Any Privileges not specifically granted are assumed to be denied. An explicit deny (Privilege Granted = FALSE) takes precedence over any granted Privileges. 
//              
//              The association of subjects (Roles and Identities) to Privileges is accomplished using policy or explicitly via the associations on a subclass. The entities that are protected (targets) can be similarly defined. 
//              
//              Note that Privileges may be inherited through hierarchical Roles, or may overlap. For example, a Privilege denying any instance Writes in a particular CIM Server Namespace would overlap with a Privilege defining specific access rights at an instance level within that Namespace. In this example, the AuthorizedSubjects are either Identities or Roles, and the AuthorizedTargets are a Namespace in the former case, and a particular instance in the latter.
//
//              This file was automatically generated from CIM_Privilege.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_Privilege.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Privilege::_metadata[] = {
		{"InstanceID", true, false, false },
		{"PrivilegeGranted", false, false, false },
		{"Activities", false, false, false },
		{"ActivityQualifiers", false, false, false },
		{"QualifierFormats", false, false, false },
		{"RepresentsAuthorizationRights", false, false, false },
	};
	// class fields
	const bool CIM_Privilege::PrivilegeGranted() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PrivilegeGranted"), ret);
		return ret;
	}
	void CIM_Privilege::PrivilegeGranted(const bool value)
	{
		SetOrAddField("PrivilegeGranted", TypeConverter::TypeToString(value));
	}
	bool CIM_Privilege::PrivilegeGrantedExists() const
	{
		return ContainsField("PrivilegeGranted");
	}
	void CIM_Privilege::RemovePrivilegeGranted()
	{
		RemoveField("PrivilegeGranted");
	}

	const vector<unsigned short> CIM_Privilege::Activities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Activities"), ret);
		return ret;
	}
	void CIM_Privilege::Activities(const vector<unsigned short> &value)
	{
		SetOrAddField("Activities", TypeConverter::TypeToString(value));
	}
	bool CIM_Privilege::ActivitiesExists() const
	{
		return ContainsField("Activities");
	}
	void CIM_Privilege::RemoveActivities()
	{
		RemoveField("Activities");
	}

	const vector<string> CIM_Privilege::ActivityQualifiers() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ActivityQualifiers"), ret);
		return ret;
	}
	void CIM_Privilege::ActivityQualifiers(const vector<string> &value)
	{
		SetOrAddField("ActivityQualifiers", TypeConverter::TypeToString(value));
	}
	bool CIM_Privilege::ActivityQualifiersExists() const
	{
		return ContainsField("ActivityQualifiers");
	}
	void CIM_Privilege::RemoveActivityQualifiers()
	{
		RemoveField("ActivityQualifiers");
	}

	const vector<unsigned short> CIM_Privilege::QualifierFormats() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("QualifierFormats"), ret);
		return ret;
	}
	void CIM_Privilege::QualifierFormats(const vector<unsigned short> &value)
	{
		SetOrAddField("QualifierFormats", TypeConverter::TypeToString(value));
	}
	bool CIM_Privilege::QualifierFormatsExists() const
	{
		return ContainsField("QualifierFormats");
	}
	void CIM_Privilege::RemoveQualifierFormats()
	{
		RemoveField("QualifierFormats");
	}

	const bool CIM_Privilege::RepresentsAuthorizationRights() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RepresentsAuthorizationRights"), ret);
		return ret;
	}
	void CIM_Privilege::RepresentsAuthorizationRights(const bool value)
	{
		SetOrAddField("RepresentsAuthorizationRights", TypeConverter::TypeToString(value));
	}
	bool CIM_Privilege::RepresentsAuthorizationRightsExists() const
	{
		return ContainsField("RepresentsAuthorizationRights");
	}
	void CIM_Privilege::RemoveRepresentsAuthorizationRights()
	{
		RemoveField("RepresentsAuthorizationRights");
	}

	CimBase *CIM_Privilege::CreateFromCimObject(const CimObject &object)
	{
		CIM_Privilege *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Privilege>(object);
		}
		else
		{
			ret = new CIM_Privilege(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Privilege> > CIM_Privilege::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Privilege>(client, keys);
	}

	void CIM_Privilege::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Privilege::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Privilege::CLASS_NAME = "CIM_Privilege";
	const string CIM_Privilege::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Privilege";
	const string CIM_Privilege::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Privilege";
	const string CIM_Privilege::CLASS_NS_PREFIX = "APr545";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Privilege::_classMetaData;
}
}
}
}
