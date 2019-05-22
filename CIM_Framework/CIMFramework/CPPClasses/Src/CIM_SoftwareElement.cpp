//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareElement.cpp
//
//  Contents:   The CIM_SoftwareElement class is used to decompose a CIM_SoftwareFeature object into a set of individually manageable or deployable parts, for a particular platform. A SoftwareElement's platform is uniquely identified by its underlying hardware architecture and operating system (for example Sun Solaris on Sun Sparc or Windows NT on Intel platforms). As such, to understand the details of how the functionality of a particular SoftwareFeature is provided on a particular platform, the CIM_SoftwareElement objects referenced by CIM_SoftwareFeatureSoftwareElements associations are organized in disjoint sets based on the TargetOperatingSystem property. A CIM_SoftwareElement object captures the management details of a part or component in one of four states characterized by the SoftwareElementState property.
//
//              This file was automatically generated from CIM_SoftwareElement.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#include "CIM_SoftwareElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SoftwareElement::_metadata[] = {
		{"Name", true, false, false },
		{"Version", true, false, false },
		{"SoftwareElementState", true, false, false },
		{"SoftwareElementID", true, false, false },
		{"TargetOperatingSystem", true, false, false },
		{"OtherTargetOS", false, false, false },
		{"Manufacturer", false, false, false },
		{"BuildNumber", false, false, false },
		{"SerialNumber", false, false, false },
		{"CodeSet", false, false, false },
		{"IdentificationCode", false, false, false },
		{"LanguageEdition", false, false, false },
	};
	// class fields
	const string CIM_SoftwareElement::Version() const
	{
		return GetField("Version")[0];
	}
	void CIM_SoftwareElement::Version(const string &value)
	{
		SetOrAddField("Version", value);
	}

	const unsigned short CIM_SoftwareElement::SoftwareElementState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SoftwareElementState"), ret);
		return ret;
	}
	void CIM_SoftwareElement::SoftwareElementState(const unsigned short value)
	{
		SetOrAddField("SoftwareElementState", TypeConverter::TypeToString(value));
	}

	const string CIM_SoftwareElement::SoftwareElementID() const
	{
		return GetField("SoftwareElementID")[0];
	}
	void CIM_SoftwareElement::SoftwareElementID(const string &value)
	{
		SetOrAddField("SoftwareElementID", value);
	}

	const unsigned short CIM_SoftwareElement::TargetOperatingSystem() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TargetOperatingSystem"), ret);
		return ret;
	}
	void CIM_SoftwareElement::TargetOperatingSystem(const unsigned short value)
	{
		SetOrAddField("TargetOperatingSystem", TypeConverter::TypeToString(value));
	}

	const string CIM_SoftwareElement::OtherTargetOS() const
	{
		return GetField("OtherTargetOS")[0];
	}
	void CIM_SoftwareElement::OtherTargetOS(const string &value)
	{
		SetOrAddField("OtherTargetOS", value);
	}
	bool CIM_SoftwareElement::OtherTargetOSExists() const
	{
		return ContainsField("OtherTargetOS");
	}
	void CIM_SoftwareElement::RemoveOtherTargetOS()
	{
		RemoveField("OtherTargetOS");
	}

	const string CIM_SoftwareElement::Manufacturer() const
	{
		return GetField("Manufacturer")[0];
	}
	void CIM_SoftwareElement::Manufacturer(const string &value)
	{
		SetOrAddField("Manufacturer", value);
	}
	bool CIM_SoftwareElement::ManufacturerExists() const
	{
		return ContainsField("Manufacturer");
	}
	void CIM_SoftwareElement::RemoveManufacturer()
	{
		RemoveField("Manufacturer");
	}

	const string CIM_SoftwareElement::BuildNumber() const
	{
		return GetField("BuildNumber")[0];
	}
	void CIM_SoftwareElement::BuildNumber(const string &value)
	{
		SetOrAddField("BuildNumber", value);
	}
	bool CIM_SoftwareElement::BuildNumberExists() const
	{
		return ContainsField("BuildNumber");
	}
	void CIM_SoftwareElement::RemoveBuildNumber()
	{
		RemoveField("BuildNumber");
	}

	const string CIM_SoftwareElement::SerialNumber() const
	{
		return GetField("SerialNumber")[0];
	}
	void CIM_SoftwareElement::SerialNumber(const string &value)
	{
		SetOrAddField("SerialNumber", value);
	}
	bool CIM_SoftwareElement::SerialNumberExists() const
	{
		return ContainsField("SerialNumber");
	}
	void CIM_SoftwareElement::RemoveSerialNumber()
	{
		RemoveField("SerialNumber");
	}

	const string CIM_SoftwareElement::CodeSet() const
	{
		return GetField("CodeSet")[0];
	}
	void CIM_SoftwareElement::CodeSet(const string &value)
	{
		SetOrAddField("CodeSet", value);
	}
	bool CIM_SoftwareElement::CodeSetExists() const
	{
		return ContainsField("CodeSet");
	}
	void CIM_SoftwareElement::RemoveCodeSet()
	{
		RemoveField("CodeSet");
	}

	const string CIM_SoftwareElement::IdentificationCode() const
	{
		return GetField("IdentificationCode")[0];
	}
	void CIM_SoftwareElement::IdentificationCode(const string &value)
	{
		SetOrAddField("IdentificationCode", value);
	}
	bool CIM_SoftwareElement::IdentificationCodeExists() const
	{
		return ContainsField("IdentificationCode");
	}
	void CIM_SoftwareElement::RemoveIdentificationCode()
	{
		RemoveField("IdentificationCode");
	}

	const string CIM_SoftwareElement::LanguageEdition() const
	{
		return GetField("LanguageEdition")[0];
	}
	void CIM_SoftwareElement::LanguageEdition(const string &value)
	{
		SetOrAddField("LanguageEdition", value);
	}
	bool CIM_SoftwareElement::LanguageEditionExists() const
	{
		return ContainsField("LanguageEdition");
	}
	void CIM_SoftwareElement::RemoveLanguageEdition()
	{
		RemoveField("LanguageEdition");
	}

	CimBase *CIM_SoftwareElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_SoftwareElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SoftwareElement>(object);
		}
		else
		{
			ret = new CIM_SoftwareElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SoftwareElement> > CIM_SoftwareElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SoftwareElement>(client, keys);
	}

	void CIM_SoftwareElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SoftwareElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SoftwareElement::CLASS_NAME = "CIM_SoftwareElement";
	const string CIM_SoftwareElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareElement";
	const string CIM_SoftwareElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareElement";
	const string CIM_SoftwareElement::CLASS_NS_PREFIX = "ASo357";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SoftwareElement::_classMetaData;
}
}
}
}
