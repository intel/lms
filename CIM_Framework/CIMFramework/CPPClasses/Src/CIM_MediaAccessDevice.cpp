//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MediaAccessDevice.cpp
//
//  Contents:   A MediaAccessDevice represents the ability to access one or more media and use this media to store and retrieve data.
//
//              This file was automatically generated from CIM_MediaAccessDevice.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_MediaAccessDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_MediaAccessDevice::_metadata[] = {
		{"Capabilities", false, false, false },
		{"CapabilityDescriptions", false, false, false },
		{"ErrorMethodology", false, false, false },
		{"CompressionMethod", false, false, false },
		{"NumberOfMediaSupported", false, false, false },
		{"MaxMediaSize", false, false, false },
		{"DefaultBlockSize", false, false, false },
		{"MaxBlockSize", false, false, false },
		{"MinBlockSize", false, false, false },
		{"NeedsCleaning", false, false, false },
		{"MediaIsLocked", false, false, false },
		{"Security", false, false, false },
		{"LastCleaned", false, false, false },
		{"MaxAccessTime", false, false, false },
		{"UncompressedDataRate", false, false, false },
		{"LoadTime", false, false, false },
		{"UnloadTime", false, false, false },
		{"MountCount", false, false, false },
		{"TimeOfLastMount", false, false, false },
		{"TotalMountTime", false, false, false },
		{"UnitsDescription", false, false, false },
		{"MaxUnitsBeforeCleaning", false, false, false },
		{"UnitsUsed", false, false, false },
	};
	// class fields
	const vector<unsigned short> CIM_MediaAccessDevice::Capabilities() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("Capabilities"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::Capabilities(const vector<unsigned short> &value)
	{
		SetOrAddField("Capabilities", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::CapabilitiesExists() const
	{
		return ContainsField("Capabilities");
	}
	void CIM_MediaAccessDevice::RemoveCapabilities()
	{
		RemoveField("Capabilities");
	}

	const vector<string> CIM_MediaAccessDevice::CapabilityDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CapabilityDescriptions"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::CapabilityDescriptions(const vector<string> &value)
	{
		SetOrAddField("CapabilityDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::CapabilityDescriptionsExists() const
	{
		return ContainsField("CapabilityDescriptions");
	}
	void CIM_MediaAccessDevice::RemoveCapabilityDescriptions()
	{
		RemoveField("CapabilityDescriptions");
	}

	const string CIM_MediaAccessDevice::ErrorMethodology() const
	{
		return GetField("ErrorMethodology")[0];
	}
	void CIM_MediaAccessDevice::ErrorMethodology(const string &value)
	{
		SetOrAddField("ErrorMethodology", value);
	}
	bool CIM_MediaAccessDevice::ErrorMethodologyExists() const
	{
		return ContainsField("ErrorMethodology");
	}
	void CIM_MediaAccessDevice::RemoveErrorMethodology()
	{
		RemoveField("ErrorMethodology");
	}

	const string CIM_MediaAccessDevice::CompressionMethod() const
	{
		return GetField("CompressionMethod")[0];
	}
	void CIM_MediaAccessDevice::CompressionMethod(const string &value)
	{
		SetOrAddField("CompressionMethod", value);
	}
	bool CIM_MediaAccessDevice::CompressionMethodExists() const
	{
		return ContainsField("CompressionMethod");
	}
	void CIM_MediaAccessDevice::RemoveCompressionMethod()
	{
		RemoveField("CompressionMethod");
	}

	const unsigned int CIM_MediaAccessDevice::NumberOfMediaSupported() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("NumberOfMediaSupported"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::NumberOfMediaSupported(const unsigned int value)
	{
		SetOrAddField("NumberOfMediaSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::NumberOfMediaSupportedExists() const
	{
		return ContainsField("NumberOfMediaSupported");
	}
	void CIM_MediaAccessDevice::RemoveNumberOfMediaSupported()
	{
		RemoveField("NumberOfMediaSupported");
	}

	const Uint64 CIM_MediaAccessDevice::MaxMediaSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxMediaSize"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MaxMediaSize(const Uint64 value)
	{
		SetOrAddField("MaxMediaSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MaxMediaSizeExists() const
	{
		return ContainsField("MaxMediaSize");
	}
	void CIM_MediaAccessDevice::RemoveMaxMediaSize()
	{
		RemoveField("MaxMediaSize");
	}

	const Uint64 CIM_MediaAccessDevice::DefaultBlockSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("DefaultBlockSize"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::DefaultBlockSize(const Uint64 value)
	{
		SetOrAddField("DefaultBlockSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::DefaultBlockSizeExists() const
	{
		return ContainsField("DefaultBlockSize");
	}
	void CIM_MediaAccessDevice::RemoveDefaultBlockSize()
	{
		RemoveField("DefaultBlockSize");
	}

	const Uint64 CIM_MediaAccessDevice::MaxBlockSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxBlockSize"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MaxBlockSize(const Uint64 value)
	{
		SetOrAddField("MaxBlockSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MaxBlockSizeExists() const
	{
		return ContainsField("MaxBlockSize");
	}
	void CIM_MediaAccessDevice::RemoveMaxBlockSize()
	{
		RemoveField("MaxBlockSize");
	}

	const Uint64 CIM_MediaAccessDevice::MinBlockSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MinBlockSize"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MinBlockSize(const Uint64 value)
	{
		SetOrAddField("MinBlockSize", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MinBlockSizeExists() const
	{
		return ContainsField("MinBlockSize");
	}
	void CIM_MediaAccessDevice::RemoveMinBlockSize()
	{
		RemoveField("MinBlockSize");
	}

	const bool CIM_MediaAccessDevice::NeedsCleaning() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("NeedsCleaning"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::NeedsCleaning(const bool value)
	{
		SetOrAddField("NeedsCleaning", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::NeedsCleaningExists() const
	{
		return ContainsField("NeedsCleaning");
	}
	void CIM_MediaAccessDevice::RemoveNeedsCleaning()
	{
		RemoveField("NeedsCleaning");
	}

	const bool CIM_MediaAccessDevice::MediaIsLocked() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("MediaIsLocked"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MediaIsLocked(const bool value)
	{
		SetOrAddField("MediaIsLocked", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MediaIsLockedExists() const
	{
		return ContainsField("MediaIsLocked");
	}
	void CIM_MediaAccessDevice::RemoveMediaIsLocked()
	{
		RemoveField("MediaIsLocked");
	}

	const unsigned short CIM_MediaAccessDevice::Security() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Security"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::Security(const unsigned short value)
	{
		SetOrAddField("Security", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::SecurityExists() const
	{
		return ContainsField("Security");
	}
	void CIM_MediaAccessDevice::RemoveSecurity()
	{
		RemoveField("Security");
	}

	const CimDateTime CIM_MediaAccessDevice::LastCleaned() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("LastCleaned"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::LastCleaned(const CimDateTime &value)
	{
		SetOrAddField("LastCleaned", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::LastCleanedExists() const
	{
		return ContainsField("LastCleaned");
	}
	void CIM_MediaAccessDevice::RemoveLastCleaned()
	{
		RemoveField("LastCleaned");
	}

	const Uint64 CIM_MediaAccessDevice::MaxAccessTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxAccessTime"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MaxAccessTime(const Uint64 value)
	{
		SetOrAddField("MaxAccessTime", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MaxAccessTimeExists() const
	{
		return ContainsField("MaxAccessTime");
	}
	void CIM_MediaAccessDevice::RemoveMaxAccessTime()
	{
		RemoveField("MaxAccessTime");
	}

	const unsigned int CIM_MediaAccessDevice::UncompressedDataRate() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("UncompressedDataRate"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::UncompressedDataRate(const unsigned int value)
	{
		SetOrAddField("UncompressedDataRate", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::UncompressedDataRateExists() const
	{
		return ContainsField("UncompressedDataRate");
	}
	void CIM_MediaAccessDevice::RemoveUncompressedDataRate()
	{
		RemoveField("UncompressedDataRate");
	}

	const Uint64 CIM_MediaAccessDevice::LoadTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("LoadTime"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::LoadTime(const Uint64 value)
	{
		SetOrAddField("LoadTime", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::LoadTimeExists() const
	{
		return ContainsField("LoadTime");
	}
	void CIM_MediaAccessDevice::RemoveLoadTime()
	{
		RemoveField("LoadTime");
	}

	const Uint64 CIM_MediaAccessDevice::UnloadTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("UnloadTime"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::UnloadTime(const Uint64 value)
	{
		SetOrAddField("UnloadTime", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::UnloadTimeExists() const
	{
		return ContainsField("UnloadTime");
	}
	void CIM_MediaAccessDevice::RemoveUnloadTime()
	{
		RemoveField("UnloadTime");
	}

	const Uint64 CIM_MediaAccessDevice::MountCount() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MountCount"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MountCount(const Uint64 value)
	{
		SetOrAddField("MountCount", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MountCountExists() const
	{
		return ContainsField("MountCount");
	}
	void CIM_MediaAccessDevice::RemoveMountCount()
	{
		RemoveField("MountCount");
	}

	const CimDateTime CIM_MediaAccessDevice::TimeOfLastMount() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastMount"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::TimeOfLastMount(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastMount", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::TimeOfLastMountExists() const
	{
		return ContainsField("TimeOfLastMount");
	}
	void CIM_MediaAccessDevice::RemoveTimeOfLastMount()
	{
		RemoveField("TimeOfLastMount");
	}

	const Uint64 CIM_MediaAccessDevice::TotalMountTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("TotalMountTime"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::TotalMountTime(const Uint64 value)
	{
		SetOrAddField("TotalMountTime", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::TotalMountTimeExists() const
	{
		return ContainsField("TotalMountTime");
	}
	void CIM_MediaAccessDevice::RemoveTotalMountTime()
	{
		RemoveField("TotalMountTime");
	}

	const string CIM_MediaAccessDevice::UnitsDescription() const
	{
		return GetField("UnitsDescription")[0];
	}
	void CIM_MediaAccessDevice::UnitsDescription(const string &value)
	{
		SetOrAddField("UnitsDescription", value);
	}
	bool CIM_MediaAccessDevice::UnitsDescriptionExists() const
	{
		return ContainsField("UnitsDescription");
	}
	void CIM_MediaAccessDevice::RemoveUnitsDescription()
	{
		RemoveField("UnitsDescription");
	}

	const Uint64 CIM_MediaAccessDevice::MaxUnitsBeforeCleaning() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxUnitsBeforeCleaning"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::MaxUnitsBeforeCleaning(const Uint64 value)
	{
		SetOrAddField("MaxUnitsBeforeCleaning", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::MaxUnitsBeforeCleaningExists() const
	{
		return ContainsField("MaxUnitsBeforeCleaning");
	}
	void CIM_MediaAccessDevice::RemoveMaxUnitsBeforeCleaning()
	{
		RemoveField("MaxUnitsBeforeCleaning");
	}

	const Uint64 CIM_MediaAccessDevice::UnitsUsed() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("UnitsUsed"), ret);
		return ret;
	}
	void CIM_MediaAccessDevice::UnitsUsed(const Uint64 value)
	{
		SetOrAddField("UnitsUsed", TypeConverter::TypeToString(value));
	}
	bool CIM_MediaAccessDevice::UnitsUsedExists() const
	{
		return ContainsField("UnitsUsed");
	}
	void CIM_MediaAccessDevice::RemoveUnitsUsed()
	{
		RemoveField("UnitsUsed");
	}

	CimBase *CIM_MediaAccessDevice::CreateFromCimObject(const CimObject &object)
	{
		CIM_MediaAccessDevice *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_MediaAccessDevice>(object);
		}
		else
		{
			ret = new CIM_MediaAccessDevice(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_MediaAccessDevice> > CIM_MediaAccessDevice::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_MediaAccessDevice>(client, keys);
	}

	void CIM_MediaAccessDevice::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_MediaAccessDevice::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_MediaAccessDevice::CLASS_NAME = "CIM_MediaAccessDevice";
	const string CIM_MediaAccessDevice::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MediaAccessDevice";
	const string CIM_MediaAccessDevice::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_MediaAccessDevice";
	const string CIM_MediaAccessDevice::CLASS_NS_PREFIX = "AMe602";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_MediaAccessDevice::_classMetaData;
}
}
}
}
