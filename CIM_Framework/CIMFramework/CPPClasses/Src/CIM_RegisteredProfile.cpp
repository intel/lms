//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RegisteredProfile.cpp
//
//  Contents:   A RegisteredProfile describes a set of CIM Schema classes with required properties and/or methods, necessary to manage a real-world entity or to support a usage scenario, in an interoperable fashion. RegisteredProfiles can be defined by the DMTF or other standards organizations. Note that this class should not be confused with CIM_Profile, which collects SettingData instances, to be applied as a 'configuration profile' for an element. 
//              A RegisteredProfile is a named 'standard' for CIM-based management of a particular System, subsystem, Service or other entity, for a specified set of uses. It is a complete, standalone definition, as opposed to the subclass RegisteredSubProfile, which requires a scoping profile for context. 
//              The uses for a RegisteredProfile or SubProfile MUST be specified in the document that defines the profile. Examples of Profiles are to manage various aspects of an Operating System, Storage Array, or Database. The name of the profile is defined and scoped by its authoring organization.
//
//              This file was automatically generated from CIM_RegisteredProfile.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_RegisteredProfile.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RegisteredProfile::_metadata[] = {
		{"InstanceID", true, false, false },
		{"RegisteredOrganization", false, true, false },
		{"OtherRegisteredOrganization", false, false, false },
		{"RegisteredName", false, true, false },
		{"RegisteredVersion", false, true, false },
		{"AdvertiseTypes", false, true, false },
		{"AdvertiseTypeDescriptions", false, false, false },
		{"ImplementedFeatures", false, false, false },
	};
	// class fields
	const unsigned short CIM_RegisteredProfile::RegisteredOrganization() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RegisteredOrganization"), ret);
		return ret;
	}
	void CIM_RegisteredProfile::RegisteredOrganization(const unsigned short value)
	{
		SetOrAddField("RegisteredOrganization", TypeConverter::TypeToString(value));
	}
	bool CIM_RegisteredProfile::RegisteredOrganizationExists() const
	{
		return ContainsField("RegisteredOrganization");
	}
	void CIM_RegisteredProfile::RemoveRegisteredOrganization()
	{
		RemoveField("RegisteredOrganization");
	}

	const string CIM_RegisteredProfile::OtherRegisteredOrganization() const
	{
		return GetField("OtherRegisteredOrganization")[0];
	}
	void CIM_RegisteredProfile::OtherRegisteredOrganization(const string &value)
	{
		SetOrAddField("OtherRegisteredOrganization", value);
	}
	bool CIM_RegisteredProfile::OtherRegisteredOrganizationExists() const
	{
		return ContainsField("OtherRegisteredOrganization");
	}
	void CIM_RegisteredProfile::RemoveOtherRegisteredOrganization()
	{
		RemoveField("OtherRegisteredOrganization");
	}

	const string CIM_RegisteredProfile::RegisteredName() const
	{
		return GetField("RegisteredName")[0];
	}
	void CIM_RegisteredProfile::RegisteredName(const string &value)
	{
		SetOrAddField("RegisteredName", value);
	}
	bool CIM_RegisteredProfile::RegisteredNameExists() const
	{
		return ContainsField("RegisteredName");
	}
	void CIM_RegisteredProfile::RemoveRegisteredName()
	{
		RemoveField("RegisteredName");
	}

	const string CIM_RegisteredProfile::RegisteredVersion() const
	{
		return GetField("RegisteredVersion")[0];
	}
	void CIM_RegisteredProfile::RegisteredVersion(const string &value)
	{
		SetOrAddField("RegisteredVersion", value);
	}
	bool CIM_RegisteredProfile::RegisteredVersionExists() const
	{
		return ContainsField("RegisteredVersion");
	}
	void CIM_RegisteredProfile::RemoveRegisteredVersion()
	{
		RemoveField("RegisteredVersion");
	}

	const vector<unsigned short> CIM_RegisteredProfile::AdvertiseTypes() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("AdvertiseTypes"), ret);
		return ret;
	}
	void CIM_RegisteredProfile::AdvertiseTypes(const vector<unsigned short> &value)
	{
		SetOrAddField("AdvertiseTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_RegisteredProfile::AdvertiseTypesExists() const
	{
		return ContainsField("AdvertiseTypes");
	}
	void CIM_RegisteredProfile::RemoveAdvertiseTypes()
	{
		RemoveField("AdvertiseTypes");
	}

	const vector<string> CIM_RegisteredProfile::AdvertiseTypeDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("AdvertiseTypeDescriptions"), ret);
		return ret;
	}
	void CIM_RegisteredProfile::AdvertiseTypeDescriptions(const vector<string> &value)
	{
		SetOrAddField("AdvertiseTypeDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_RegisteredProfile::AdvertiseTypeDescriptionsExists() const
	{
		return ContainsField("AdvertiseTypeDescriptions");
	}
	void CIM_RegisteredProfile::RemoveAdvertiseTypeDescriptions()
	{
		RemoveField("AdvertiseTypeDescriptions");
	}

	const vector<string> CIM_RegisteredProfile::ImplementedFeatures() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ImplementedFeatures"), ret);
		return ret;
	}
	void CIM_RegisteredProfile::ImplementedFeatures(const vector<string> &value)
	{
		SetOrAddField("ImplementedFeatures", TypeConverter::TypeToString(value));
	}
	bool CIM_RegisteredProfile::ImplementedFeaturesExists() const
	{
		return ContainsField("ImplementedFeatures");
	}
	void CIM_RegisteredProfile::RemoveImplementedFeatures()
	{
		RemoveField("ImplementedFeatures");
	}

	CimBase *CIM_RegisteredProfile::CreateFromCimObject(const CimObject &object)
	{
		CIM_RegisteredProfile *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RegisteredProfile>(object);
		}
		else
		{
			ret = new CIM_RegisteredProfile(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RegisteredProfile> > CIM_RegisteredProfile::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RegisteredProfile>(client, keys);
	}

	void CIM_RegisteredProfile::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RegisteredProfile::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RegisteredProfile::CLASS_NAME = "CIM_RegisteredProfile";
	const string CIM_RegisteredProfile::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RegisteredProfile";
	const string CIM_RegisteredProfile::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RegisteredProfile";
	const string CIM_RegisteredProfile::CLASS_NS_PREFIX = "ARe31";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RegisteredProfile::_classMetaData;
}
}
}
}
