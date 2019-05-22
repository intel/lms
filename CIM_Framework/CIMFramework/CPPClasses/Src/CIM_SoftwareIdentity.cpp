//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareIdentity.cpp
//
//  Contents:   SoftwareIdentity provides descriptive information about a software component for asset tracking and/or installation dependency management. When the IsEntity property has the value TRUE, the instance of SoftwareIdentity represents an individually identifiable entity similar to Physical Element. SoftwareIdentity does NOT indicate whether the software is installed, executing, etc. This extra information may be provided through specialized associations to Software Identity. For instance, both InstalledSoftwareIdentity and ElementSoftwareIdentity may be used to indicate that the software identified by this class is installed. SoftwareIdentity is used when managing the software components of a ManagedElement that is the management focus. Since software may be acquired, SoftwareIdentity can be associated with a Product using the ProductSoftwareComponent relationship. The Application Model manages the deployment and installation of software via the classes, SoftwareFeatures and SoftwareElements. SoftwareFeature and SoftwareElement are used when the software component is the management focus. The deployment/installation concepts are related to the asset/identity one. In fact, a SoftwareIdentity may correspond to a Product, or to one or more SoftwareFeatures or SoftwareElements - depending on the granularity of these classes and the deployment model. The correspondence of Software Identity to Product, SoftwareFeature or SoftwareElement is indicated using the ConcreteIdentity association. Note that there may not be sufficient detail or instrumentation to instantiate ConcreteIdentity. And, if the association is instantiated, some duplication of information may result. For example, the Vendor described in the instances of Product and SoftwareIdentity MAY be the same. However, this is not necessarily true, and it is why vendor and similar information are duplicated in this class. 
//              Note that ConcreteIdentity can also be used to describe the relationship of the software to any LogicalFiles that result from installing it. As above, there may not be sufficient detail or instrumentation to instantiate this association.
//
//              This file was automatically generated from CIM_SoftwareIdentity.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#include "CIM_SoftwareIdentity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SoftwareIdentity::_metadata[] = {
		{"InstanceID", true, false, false },
		{"MajorVersion", false, false, false },
		{"MinorVersion", false, false, false },
		{"RevisionNumber", false, false, false },
		{"BuildNumber", false, false, false },
		{"LargeBuildNumber", false, false, false },
		{"IsLargeBuildNumber", false, false, false },
		{"VersionString", false, false, false },
		{"TargetOperatingSystems", false, false, false },
		{"Manufacturer", false, false, false },
		{"Languages", false, false, false },
		{"Classifications", false, false, false },
		{"ClassificationDescriptions", false, false, false },
		{"SerialNumber", false, false, false },
		{"TargetTypes", false, false, false },
		{"IdentityInfoValue", false, false, false },
		{"IdentityInfoType", false, false, false },
		{"ReleaseDate", false, false, false },
		{"IsEntity", false, false, false },
		{"ExtendedResourceType", false, false, false },
		{"OtherExtendedResourceTypeDescription", false, false, false },
		{"MinExtendedResourceTypeMajorVersion", false, false, false },
		{"MinExtendedResourceTypeMinorVersion", false, false, false },
		{"MinExtendedResourceTypeRevisionNumber", false, false, false },
		{"MinExtendedResourceTypeBuildNumber", false, false, false },
		{"TargetOSTypes", false, false, false },
	};
	// class fields
	const unsigned short CIM_SoftwareIdentity::MajorVersion() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MajorVersion"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MajorVersion(const unsigned short value)
	{
		SetOrAddField("MajorVersion", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MajorVersionExists() const
	{
		return ContainsField("MajorVersion");
	}
	void CIM_SoftwareIdentity::RemoveMajorVersion()
	{
		RemoveField("MajorVersion");
	}

	const unsigned short CIM_SoftwareIdentity::MinorVersion() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MinorVersion"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MinorVersion(const unsigned short value)
	{
		SetOrAddField("MinorVersion", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MinorVersionExists() const
	{
		return ContainsField("MinorVersion");
	}
	void CIM_SoftwareIdentity::RemoveMinorVersion()
	{
		RemoveField("MinorVersion");
	}

	const unsigned short CIM_SoftwareIdentity::RevisionNumber() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RevisionNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::RevisionNumber(const unsigned short value)
	{
		SetOrAddField("RevisionNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::RevisionNumberExists() const
	{
		return ContainsField("RevisionNumber");
	}
	void CIM_SoftwareIdentity::RemoveRevisionNumber()
	{
		RemoveField("RevisionNumber");
	}

	const unsigned short CIM_SoftwareIdentity::BuildNumber() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BuildNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::BuildNumber(const unsigned short value)
	{
		SetOrAddField("BuildNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::BuildNumberExists() const
	{
		return ContainsField("BuildNumber");
	}
	void CIM_SoftwareIdentity::RemoveBuildNumber()
	{
		RemoveField("BuildNumber");
	}

	const Uint64 CIM_SoftwareIdentity::LargeBuildNumber() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("LargeBuildNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::LargeBuildNumber(const Uint64 value)
	{
		SetOrAddField("LargeBuildNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::LargeBuildNumberExists() const
	{
		return ContainsField("LargeBuildNumber");
	}
	void CIM_SoftwareIdentity::RemoveLargeBuildNumber()
	{
		RemoveField("LargeBuildNumber");
	}

	const bool CIM_SoftwareIdentity::IsLargeBuildNumber() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsLargeBuildNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::IsLargeBuildNumber(const bool value)
	{
		SetOrAddField("IsLargeBuildNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::IsLargeBuildNumberExists() const
	{
		return ContainsField("IsLargeBuildNumber");
	}
	void CIM_SoftwareIdentity::RemoveIsLargeBuildNumber()
	{
		RemoveField("IsLargeBuildNumber");
	}

	const string CIM_SoftwareIdentity::VersionString() const
	{
		return GetField("VersionString")[0];
	}
	void CIM_SoftwareIdentity::VersionString(const string &value)
	{
		SetOrAddField("VersionString", value);
	}
	bool CIM_SoftwareIdentity::VersionStringExists() const
	{
		return ContainsField("VersionString");
	}
	void CIM_SoftwareIdentity::RemoveVersionString()
	{
		RemoveField("VersionString");
	}

	const vector<string> CIM_SoftwareIdentity::TargetOperatingSystems() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("TargetOperatingSystems"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::TargetOperatingSystems(const vector<string> &value)
	{
		SetOrAddField("TargetOperatingSystems", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::TargetOperatingSystemsExists() const
	{
		return ContainsField("TargetOperatingSystems");
	}
	void CIM_SoftwareIdentity::RemoveTargetOperatingSystems()
	{
		RemoveField("TargetOperatingSystems");
	}

	const string CIM_SoftwareIdentity::Manufacturer() const
	{
		return GetField("Manufacturer")[0];
	}
	void CIM_SoftwareIdentity::Manufacturer(const string &value)
	{
		SetOrAddField("Manufacturer", value);
	}
	bool CIM_SoftwareIdentity::ManufacturerExists() const
	{
		return ContainsField("Manufacturer");
	}
	void CIM_SoftwareIdentity::RemoveManufacturer()
	{
		RemoveField("Manufacturer");
	}

	const vector<string> CIM_SoftwareIdentity::Languages() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("Languages"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::Languages(const vector<string> &value)
	{
		SetOrAddField("Languages", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::LanguagesExists() const
	{
		return ContainsField("Languages");
	}
	void CIM_SoftwareIdentity::RemoveLanguages()
	{
		RemoveField("Languages");
	}

	const vector<unsigned short> CIM_SoftwareIdentity::Classifications() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Classifications"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::Classifications(const vector<unsigned short> &value)
	{
		SetOrAddField("Classifications", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::ClassificationsExists() const
	{
		return ContainsField("Classifications");
	}
	void CIM_SoftwareIdentity::RemoveClassifications()
	{
		RemoveField("Classifications");
	}

	const vector<string> CIM_SoftwareIdentity::ClassificationDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ClassificationDescriptions"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::ClassificationDescriptions(const vector<string> &value)
	{
		SetOrAddField("ClassificationDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::ClassificationDescriptionsExists() const
	{
		return ContainsField("ClassificationDescriptions");
	}
	void CIM_SoftwareIdentity::RemoveClassificationDescriptions()
	{
		RemoveField("ClassificationDescriptions");
	}

	const string CIM_SoftwareIdentity::SerialNumber() const
	{
		return GetField("SerialNumber")[0];
	}
	void CIM_SoftwareIdentity::SerialNumber(const string &value)
	{
		SetOrAddField("SerialNumber", value);
	}
	bool CIM_SoftwareIdentity::SerialNumberExists() const
	{
		return ContainsField("SerialNumber");
	}
	void CIM_SoftwareIdentity::RemoveSerialNumber()
	{
		RemoveField("SerialNumber");
	}

	const vector<string> CIM_SoftwareIdentity::TargetTypes() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("TargetTypes"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::TargetTypes(const vector<string> &value)
	{
		SetOrAddField("TargetTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::TargetTypesExists() const
	{
		return ContainsField("TargetTypes");
	}
	void CIM_SoftwareIdentity::RemoveTargetTypes()
	{
		RemoveField("TargetTypes");
	}

	const vector<string> CIM_SoftwareIdentity::IdentityInfoValue() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("IdentityInfoValue"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::IdentityInfoValue(const vector<string> &value)
	{
		SetOrAddField("IdentityInfoValue", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::IdentityInfoValueExists() const
	{
		return ContainsField("IdentityInfoValue");
	}
	void CIM_SoftwareIdentity::RemoveIdentityInfoValue()
	{
		RemoveField("IdentityInfoValue");
	}

	const vector<string> CIM_SoftwareIdentity::IdentityInfoType() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("IdentityInfoType"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::IdentityInfoType(const vector<string> &value)
	{
		SetOrAddField("IdentityInfoType", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::IdentityInfoTypeExists() const
	{
		return ContainsField("IdentityInfoType");
	}
	void CIM_SoftwareIdentity::RemoveIdentityInfoType()
	{
		RemoveField("IdentityInfoType");
	}

	const CimDateTime CIM_SoftwareIdentity::ReleaseDate() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ReleaseDate"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::ReleaseDate(const CimDateTime &value)
	{
		SetOrAddField("ReleaseDate", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::ReleaseDateExists() const
	{
		return ContainsField("ReleaseDate");
	}
	void CIM_SoftwareIdentity::RemoveReleaseDate()
	{
		RemoveField("ReleaseDate");
	}

	const bool CIM_SoftwareIdentity::IsEntity() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsEntity"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::IsEntity(const bool value)
	{
		SetOrAddField("IsEntity", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::IsEntityExists() const
	{
		return ContainsField("IsEntity");
	}
	void CIM_SoftwareIdentity::RemoveIsEntity()
	{
		RemoveField("IsEntity");
	}

	const unsigned short CIM_SoftwareIdentity::ExtendedResourceType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ExtendedResourceType"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::ExtendedResourceType(const unsigned short value)
	{
		SetOrAddField("ExtendedResourceType", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::ExtendedResourceTypeExists() const
	{
		return ContainsField("ExtendedResourceType");
	}
	void CIM_SoftwareIdentity::RemoveExtendedResourceType()
	{
		RemoveField("ExtendedResourceType");
	}

	const string CIM_SoftwareIdentity::OtherExtendedResourceTypeDescription() const
	{
		return GetField("OtherExtendedResourceTypeDescription")[0];
	}
	void CIM_SoftwareIdentity::OtherExtendedResourceTypeDescription(const string &value)
	{
		SetOrAddField("OtherExtendedResourceTypeDescription", value);
	}
	bool CIM_SoftwareIdentity::OtherExtendedResourceTypeDescriptionExists() const
	{
		return ContainsField("OtherExtendedResourceTypeDescription");
	}
	void CIM_SoftwareIdentity::RemoveOtherExtendedResourceTypeDescription()
	{
		RemoveField("OtherExtendedResourceTypeDescription");
	}

	const unsigned short CIM_SoftwareIdentity::MinExtendedResourceTypeMajorVersion() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MinExtendedResourceTypeMajorVersion"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MinExtendedResourceTypeMajorVersion(const unsigned short value)
	{
		SetOrAddField("MinExtendedResourceTypeMajorVersion", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MinExtendedResourceTypeMajorVersionExists() const
	{
		return ContainsField("MinExtendedResourceTypeMajorVersion");
	}
	void CIM_SoftwareIdentity::RemoveMinExtendedResourceTypeMajorVersion()
	{
		RemoveField("MinExtendedResourceTypeMajorVersion");
	}

	const unsigned short CIM_SoftwareIdentity::MinExtendedResourceTypeMinorVersion() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MinExtendedResourceTypeMinorVersion"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MinExtendedResourceTypeMinorVersion(const unsigned short value)
	{
		SetOrAddField("MinExtendedResourceTypeMinorVersion", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MinExtendedResourceTypeMinorVersionExists() const
	{
		return ContainsField("MinExtendedResourceTypeMinorVersion");
	}
	void CIM_SoftwareIdentity::RemoveMinExtendedResourceTypeMinorVersion()
	{
		RemoveField("MinExtendedResourceTypeMinorVersion");
	}

	const unsigned short CIM_SoftwareIdentity::MinExtendedResourceTypeRevisionNumber() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MinExtendedResourceTypeRevisionNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MinExtendedResourceTypeRevisionNumber(const unsigned short value)
	{
		SetOrAddField("MinExtendedResourceTypeRevisionNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MinExtendedResourceTypeRevisionNumberExists() const
	{
		return ContainsField("MinExtendedResourceTypeRevisionNumber");
	}
	void CIM_SoftwareIdentity::RemoveMinExtendedResourceTypeRevisionNumber()
	{
		RemoveField("MinExtendedResourceTypeRevisionNumber");
	}

	const unsigned short CIM_SoftwareIdentity::MinExtendedResourceTypeBuildNumber() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MinExtendedResourceTypeBuildNumber"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::MinExtendedResourceTypeBuildNumber(const unsigned short value)
	{
		SetOrAddField("MinExtendedResourceTypeBuildNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::MinExtendedResourceTypeBuildNumberExists() const
	{
		return ContainsField("MinExtendedResourceTypeBuildNumber");
	}
	void CIM_SoftwareIdentity::RemoveMinExtendedResourceTypeBuildNumber()
	{
		RemoveField("MinExtendedResourceTypeBuildNumber");
	}

	const vector<unsigned short> CIM_SoftwareIdentity::TargetOSTypes() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("TargetOSTypes"), ret);
		return ret;
	}
	void CIM_SoftwareIdentity::TargetOSTypes(const vector<unsigned short> &value)
	{
		SetOrAddField("TargetOSTypes", TypeConverter::TypeToString(value));
	}
	bool CIM_SoftwareIdentity::TargetOSTypesExists() const
	{
		return ContainsField("TargetOSTypes");
	}
	void CIM_SoftwareIdentity::RemoveTargetOSTypes()
	{
		RemoveField("TargetOSTypes");
	}

	CimBase *CIM_SoftwareIdentity::CreateFromCimObject(const CimObject &object)
	{
		CIM_SoftwareIdentity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SoftwareIdentity>(object);
		}
		else
		{
			ret = new CIM_SoftwareIdentity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SoftwareIdentity> > CIM_SoftwareIdentity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SoftwareIdentity>(client, keys);
	}

	void CIM_SoftwareIdentity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SoftwareIdentity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SoftwareIdentity::CLASS_NAME = "CIM_SoftwareIdentity";
	const string CIM_SoftwareIdentity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareIdentity";
	const string CIM_SoftwareIdentity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareIdentity";
	const string CIM_SoftwareIdentity::CLASS_NS_PREFIX = "ASo411";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SoftwareIdentity::_classMetaData;
}
}
}
}
