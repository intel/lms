//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PrivilegeManagementCapabilities.cpp
//
//  Contents:   A subclass of Capabilities that defines the capabilities of the Privilege Management Service.
//
//              This file was automatically generated from CIM_PrivilegeManagementCapabilities.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#include "CIM_PrivilegeManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PrivilegeManagementCapabilities::_metadata[] = {
		{"SharedPrivilegeSupported", false, false, false },
		{"ActivitiesSupported", false, false, false },
		{"ActivityQualifiersSupported", false, false, false },
		{"QualifierFormatsSupported", false, false, false },
		{"SupportedMethods", false, false, false },
	};
	// class fields
	const bool CIM_PrivilegeManagementCapabilities::SharedPrivilegeSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SharedPrivilegeSupported"), ret);
		return ret;
	}
	void CIM_PrivilegeManagementCapabilities::SharedPrivilegeSupported(const bool value)
	{
		SetOrAddField("SharedPrivilegeSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PrivilegeManagementCapabilities::SharedPrivilegeSupportedExists() const
	{
		return ContainsField("SharedPrivilegeSupported");
	}
	void CIM_PrivilegeManagementCapabilities::RemoveSharedPrivilegeSupported()
	{
		RemoveField("SharedPrivilegeSupported");
	}

	const vector<unsigned short> CIM_PrivilegeManagementCapabilities::ActivitiesSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ActivitiesSupported"), ret);
		return ret;
	}
	void CIM_PrivilegeManagementCapabilities::ActivitiesSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("ActivitiesSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PrivilegeManagementCapabilities::ActivitiesSupportedExists() const
	{
		return ContainsField("ActivitiesSupported");
	}
	void CIM_PrivilegeManagementCapabilities::RemoveActivitiesSupported()
	{
		RemoveField("ActivitiesSupported");
	}

	const vector<string> CIM_PrivilegeManagementCapabilities::ActivityQualifiersSupported() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ActivityQualifiersSupported"), ret);
		return ret;
	}
	void CIM_PrivilegeManagementCapabilities::ActivityQualifiersSupported(const vector<string> &value)
	{
		SetOrAddField("ActivityQualifiersSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PrivilegeManagementCapabilities::ActivityQualifiersSupportedExists() const
	{
		return ContainsField("ActivityQualifiersSupported");
	}
	void CIM_PrivilegeManagementCapabilities::RemoveActivityQualifiersSupported()
	{
		RemoveField("ActivityQualifiersSupported");
	}

	const vector<unsigned short> CIM_PrivilegeManagementCapabilities::QualifierFormatsSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("QualifierFormatsSupported"), ret);
		return ret;
	}
	void CIM_PrivilegeManagementCapabilities::QualifierFormatsSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("QualifierFormatsSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_PrivilegeManagementCapabilities::QualifierFormatsSupportedExists() const
	{
		return ContainsField("QualifierFormatsSupported");
	}
	void CIM_PrivilegeManagementCapabilities::RemoveQualifierFormatsSupported()
	{
		RemoveField("QualifierFormatsSupported");
	}

	const vector<unsigned short> CIM_PrivilegeManagementCapabilities::SupportedMethods() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("SupportedMethods"), ret);
		return ret;
	}
	void CIM_PrivilegeManagementCapabilities::SupportedMethods(const vector<unsigned short> &value)
	{
		SetOrAddField("SupportedMethods", TypeConverter::TypeToString(value));
	}
	bool CIM_PrivilegeManagementCapabilities::SupportedMethodsExists() const
	{
		return ContainsField("SupportedMethods");
	}
	void CIM_PrivilegeManagementCapabilities::RemoveSupportedMethods()
	{
		RemoveField("SupportedMethods");
	}

	CimBase *CIM_PrivilegeManagementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_PrivilegeManagementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PrivilegeManagementCapabilities>(object);
		}
		else
		{
			ret = new CIM_PrivilegeManagementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PrivilegeManagementCapabilities> > CIM_PrivilegeManagementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PrivilegeManagementCapabilities>(client, keys);
	}

	void CIM_PrivilegeManagementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PrivilegeManagementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PrivilegeManagementCapabilities::CLASS_NAME = "CIM_PrivilegeManagementCapabilities";
	const string CIM_PrivilegeManagementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PrivilegeManagementCapabilities";
	const string CIM_PrivilegeManagementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PrivilegeManagementCapabilities";
	const string CIM_PrivilegeManagementCapabilities::CLASS_NS_PREFIX = "APr990";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PrivilegeManagementCapabilities::_classMetaData;
}
}
}
}
