//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Role.cpp
//
//  Contents:   The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope, and MAY be filled by a person or persons (or non-human entities represented by ManagedSystemElement subclasses) - i.e., the 'role occupants'. The latter MAY be explicitly associated to a Role, by associating Identities using MemberOfCollection. The 'position or set of responsibilities' of a Role are represented as a set of rights defined by instances of the Privilege class, and are also associated to the Role via MemberOfCollection. If Identities are not explicitly associated, instances of AuthorizationRule MUST be associated with a Role using AuthorizationRuleAppliesToRole. The rule defines how subject entities are authorized for a Role and to which target entities the Role applies. 
//              
//              The Role class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. This class's properties are a subset of a related class, OtherRoleInformation, which defines all the group properties and uses arrays for directory compatibility.
//
//              This file was automatically generated from CIM_Role.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_Role.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Role::_metadata[] = {
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"BusinessCategory", false, false, false },
		{"CommonName", false, true, false },
		{"RoleCharacteristics", false, false, false },
	};
	// class fields
	const string CIM_Role::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_Role::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_Role::Name() const
	{
		return GetField("Name")[0];
	}
	void CIM_Role::Name(const string &value)
	{
		SetOrAddField("Name", value);
	}

	const string CIM_Role::BusinessCategory() const
	{
		return GetField("BusinessCategory")[0];
	}
	void CIM_Role::BusinessCategory(const string &value)
	{
		SetOrAddField("BusinessCategory", value);
	}
	bool CIM_Role::BusinessCategoryExists() const
	{
		return ContainsField("BusinessCategory");
	}
	void CIM_Role::RemoveBusinessCategory()
	{
		RemoveField("BusinessCategory");
	}

	const string CIM_Role::CommonName() const
	{
		return GetField("CommonName")[0];
	}
	void CIM_Role::CommonName(const string &value)
	{
		SetOrAddField("CommonName", value);
	}
	bool CIM_Role::CommonNameExists() const
	{
		return ContainsField("CommonName");
	}
	void CIM_Role::RemoveCommonName()
	{
		RemoveField("CommonName");
	}

	const vector<unsigned short> CIM_Role::RoleCharacteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("RoleCharacteristics"), ret);
		return ret;
	}
	void CIM_Role::RoleCharacteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("RoleCharacteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_Role::RoleCharacteristicsExists() const
	{
		return ContainsField("RoleCharacteristics");
	}
	void CIM_Role::RemoveRoleCharacteristics()
	{
		RemoveField("RoleCharacteristics");
	}

	CimBase *CIM_Role::CreateFromCimObject(const CimObject &object)
	{
		CIM_Role *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Role>(object);
		}
		else
		{
			ret = new CIM_Role(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Role> > CIM_Role::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Role>(client, keys);
	}

	void CIM_Role::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Role::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Role::CLASS_NAME = "CIM_Role";
	const string CIM_Role::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Role";
	const string CIM_Role::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Role";
	const string CIM_Role::CLASS_NS_PREFIX = "ARo466";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Role::_classMetaData;
}
}
}
}
