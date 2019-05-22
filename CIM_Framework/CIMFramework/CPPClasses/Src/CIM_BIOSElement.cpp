//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSElement.cpp
//
//  Contents:   BIOSElement represents the low-level software that is loaded into non-volatile storage and used to bring up and configure a ComputerSystem.
//
//              This file was automatically generated from CIM_BIOSElement.mof,  version: 2.17.0
//
//----------------------------------------------------------------------------
#include "CIM_BIOSElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_BIOSElement::_metadata[] = {
		{"Version", true, false, false },
		{"Manufacturer", false, false, false },
		{"PrimaryBIOS", false, false, false },
		{"ListOfLanguages", false, false, false },
		{"CurrentLanguage", false, false, false },
		{"LoadedStartingAddress", false, false, false },
		{"LoadedEndingAddress", false, false, false },
		{"LoadUtilityInformation", false, false, false },
		{"ReleaseDate", false, false, false },
		{"RegistryURIs", false, false, false },
	};
	// class fields
	const bool CIM_BIOSElement::PrimaryBIOS() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PrimaryBIOS"), ret);
		return ret;
	}
	void CIM_BIOSElement::PrimaryBIOS(const bool value)
	{
		SetOrAddField("PrimaryBIOS", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::PrimaryBIOSExists() const
	{
		return ContainsField("PrimaryBIOS");
	}
	void CIM_BIOSElement::RemovePrimaryBIOS()
	{
		RemoveField("PrimaryBIOS");
	}

	const vector<string> CIM_BIOSElement::ListOfLanguages() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("ListOfLanguages"), ret);
		return ret;
	}
	void CIM_BIOSElement::ListOfLanguages(const vector<string> &value)
	{
		SetOrAddField("ListOfLanguages", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::ListOfLanguagesExists() const
	{
		return ContainsField("ListOfLanguages");
	}
	void CIM_BIOSElement::RemoveListOfLanguages()
	{
		RemoveField("ListOfLanguages");
	}

	const string CIM_BIOSElement::CurrentLanguage() const
	{
		return GetField("CurrentLanguage")[0];
	}
	void CIM_BIOSElement::CurrentLanguage(const string &value)
	{
		SetOrAddField("CurrentLanguage", value);
	}
	bool CIM_BIOSElement::CurrentLanguageExists() const
	{
		return ContainsField("CurrentLanguage");
	}
	void CIM_BIOSElement::RemoveCurrentLanguage()
	{
		RemoveField("CurrentLanguage");
	}

	const Uint64 CIM_BIOSElement::LoadedStartingAddress() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("LoadedStartingAddress"), ret);
		return ret;
	}
	void CIM_BIOSElement::LoadedStartingAddress(const Uint64 value)
	{
		SetOrAddField("LoadedStartingAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::LoadedStartingAddressExists() const
	{
		return ContainsField("LoadedStartingAddress");
	}
	void CIM_BIOSElement::RemoveLoadedStartingAddress()
	{
		RemoveField("LoadedStartingAddress");
	}

	const Uint64 CIM_BIOSElement::LoadedEndingAddress() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("LoadedEndingAddress"), ret);
		return ret;
	}
	void CIM_BIOSElement::LoadedEndingAddress(const Uint64 value)
	{
		SetOrAddField("LoadedEndingAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::LoadedEndingAddressExists() const
	{
		return ContainsField("LoadedEndingAddress");
	}
	void CIM_BIOSElement::RemoveLoadedEndingAddress()
	{
		RemoveField("LoadedEndingAddress");
	}

	const string CIM_BIOSElement::LoadUtilityInformation() const
	{
		return GetField("LoadUtilityInformation")[0];
	}
	void CIM_BIOSElement::LoadUtilityInformation(const string &value)
	{
		SetOrAddField("LoadUtilityInformation", value);
	}
	bool CIM_BIOSElement::LoadUtilityInformationExists() const
	{
		return ContainsField("LoadUtilityInformation");
	}
	void CIM_BIOSElement::RemoveLoadUtilityInformation()
	{
		RemoveField("LoadUtilityInformation");
	}

	const CimDateTime CIM_BIOSElement::ReleaseDate() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ReleaseDate"), ret);
		return ret;
	}
	void CIM_BIOSElement::ReleaseDate(const CimDateTime &value)
	{
		SetOrAddField("ReleaseDate", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::ReleaseDateExists() const
	{
		return ContainsField("ReleaseDate");
	}
	void CIM_BIOSElement::RemoveReleaseDate()
	{
		RemoveField("ReleaseDate");
	}

	const vector<string> CIM_BIOSElement::RegistryURIs() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("RegistryURIs"), ret);
		return ret;
	}
	void CIM_BIOSElement::RegistryURIs(const vector<string> &value)
	{
		SetOrAddField("RegistryURIs", TypeConverter::TypeToString(value));
	}
	bool CIM_BIOSElement::RegistryURIsExists() const
	{
		return ContainsField("RegistryURIs");
	}
	void CIM_BIOSElement::RemoveRegistryURIs()
	{
		RemoveField("RegistryURIs");
	}

	CimBase *CIM_BIOSElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_BIOSElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_BIOSElement>(object);
		}
		else
		{
			ret = new CIM_BIOSElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_BIOSElement> > CIM_BIOSElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_BIOSElement>(client, keys);
	}

	void CIM_BIOSElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_BIOSElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_BIOSElement::CLASS_NAME = "CIM_BIOSElement";
	const string CIM_BIOSElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSElement";
	const string CIM_BIOSElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_BIOSElement";
	const string CIM_BIOSElement::CLASS_NS_PREFIX = "ABI625";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_BIOSElement::_classMetaData;
}
}
}
}
