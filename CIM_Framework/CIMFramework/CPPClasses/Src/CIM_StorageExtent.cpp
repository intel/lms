//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_StorageExtent.cpp
//
//  Contents:   StorageExtent describes the capabilities and management of the various media that exist to store data and allow data retrieval. This superclass could be used to represent the various components of RAID (Hardware or Software) or as a raw logical extent on top of physical media.
//
//              This file was automatically generated from CIM_StorageExtent.mof,  version: 2.29.0
//
//----------------------------------------------------------------------------
#include "CIM_StorageExtent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_StorageExtent::_metadata[] = {
		{"DataOrganization", false, false, false },
		{"Purpose", false, false, false },
		{"Access", false, false, false },
		{"ErrorMethodology", false, false, false },
		{"BlockSize", false, false, false },
		{"NumberOfBlocks", false, false, false },
		{"ConsumableBlocks", false, false, false },
		{"IsBasedOnUnderlyingRedundancy", false, false, false },
		{"SequentialAccess", false, false, false },
		{"ExtentStatus", false, false, false },
		{"NoSinglePointOfFailure", false, false, false },
		{"DataRedundancy", false, false, false },
		{"PackageRedundancy", false, false, false },
		{"DeltaReservation", false, false, false },
		{"Primordial", false, false, false },
		{"Name", false, false, false },
		{"NameFormat", false, false, false },
		{"NameNamespace", false, false, false },
		{"OtherNameNamespace", false, false, false },
		{"OtherNameFormat", false, false, false },
	};
	// class fields
	const unsigned short CIM_StorageExtent::DataOrganization() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DataOrganization"), ret);
		return ret;
	}
	void CIM_StorageExtent::DataOrganization(const unsigned short value)
	{
		SetOrAddField("DataOrganization", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::DataOrganizationExists() const
	{
		return ContainsField("DataOrganization");
	}
	void CIM_StorageExtent::RemoveDataOrganization()
	{
		RemoveField("DataOrganization");
	}

	const string CIM_StorageExtent::Purpose() const
	{
		return GetField("Purpose")[0];
	}
	void CIM_StorageExtent::Purpose(const string &value)
	{
		SetOrAddField("Purpose", value);
	}
	bool CIM_StorageExtent::PurposeExists() const
	{
		return ContainsField("Purpose");
	}
	void CIM_StorageExtent::RemovePurpose()
	{
		RemoveField("Purpose");
	}

	const unsigned short CIM_StorageExtent::Access() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Access"), ret);
		return ret;
	}
	void CIM_StorageExtent::Access(const unsigned short value)
	{
		SetOrAddField("Access", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::AccessExists() const
	{
		return ContainsField("Access");
	}
	void CIM_StorageExtent::RemoveAccess()
	{
		RemoveField("Access");
	}

	const string CIM_StorageExtent::ErrorMethodology() const
	{
		return GetField("ErrorMethodology")[0];
	}
	void CIM_StorageExtent::ErrorMethodology(const string &value)
	{
		SetOrAddField("ErrorMethodology", value);
	}
	bool CIM_StorageExtent::ErrorMethodologyExists() const
	{
		return ContainsField("ErrorMethodology");
	}
	void CIM_StorageExtent::RemoveErrorMethodology()
	{
		RemoveField("ErrorMethodology");
	}

	const Uint64 CIM_StorageExtent::BlockSize() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("BlockSize"), ret);
		return ret;
	}
	void CIM_StorageExtent::BlockSize(const Uint64 value)
	{
		SetOrAddField("BlockSize", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::BlockSizeExists() const
	{
		return ContainsField("BlockSize");
	}
	void CIM_StorageExtent::RemoveBlockSize()
	{
		RemoveField("BlockSize");
	}

	const Uint64 CIM_StorageExtent::NumberOfBlocks() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("NumberOfBlocks"), ret);
		return ret;
	}
	void CIM_StorageExtent::NumberOfBlocks(const Uint64 value)
	{
		SetOrAddField("NumberOfBlocks", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::NumberOfBlocksExists() const
	{
		return ContainsField("NumberOfBlocks");
	}
	void CIM_StorageExtent::RemoveNumberOfBlocks()
	{
		RemoveField("NumberOfBlocks");
	}

	const Uint64 CIM_StorageExtent::ConsumableBlocks() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("ConsumableBlocks"), ret);
		return ret;
	}
	void CIM_StorageExtent::ConsumableBlocks(const Uint64 value)
	{
		SetOrAddField("ConsumableBlocks", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::ConsumableBlocksExists() const
	{
		return ContainsField("ConsumableBlocks");
	}
	void CIM_StorageExtent::RemoveConsumableBlocks()
	{
		RemoveField("ConsumableBlocks");
	}

	const bool CIM_StorageExtent::IsBasedOnUnderlyingRedundancy() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsBasedOnUnderlyingRedundancy"), ret);
		return ret;
	}
	void CIM_StorageExtent::IsBasedOnUnderlyingRedundancy(const bool value)
	{
		SetOrAddField("IsBasedOnUnderlyingRedundancy", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::IsBasedOnUnderlyingRedundancyExists() const
	{
		return ContainsField("IsBasedOnUnderlyingRedundancy");
	}
	void CIM_StorageExtent::RemoveIsBasedOnUnderlyingRedundancy()
	{
		RemoveField("IsBasedOnUnderlyingRedundancy");
	}

	const bool CIM_StorageExtent::SequentialAccess() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SequentialAccess"), ret);
		return ret;
	}
	void CIM_StorageExtent::SequentialAccess(const bool value)
	{
		SetOrAddField("SequentialAccess", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::SequentialAccessExists() const
	{
		return ContainsField("SequentialAccess");
	}
	void CIM_StorageExtent::RemoveSequentialAccess()
	{
		RemoveField("SequentialAccess");
	}

	const vector<unsigned short> CIM_StorageExtent::ExtentStatus() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ExtentStatus"), ret);
		return ret;
	}
	void CIM_StorageExtent::ExtentStatus(const vector<unsigned short> &value)
	{
		SetOrAddField("ExtentStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::ExtentStatusExists() const
	{
		return ContainsField("ExtentStatus");
	}
	void CIM_StorageExtent::RemoveExtentStatus()
	{
		RemoveField("ExtentStatus");
	}

	const bool CIM_StorageExtent::NoSinglePointOfFailure() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("NoSinglePointOfFailure"), ret);
		return ret;
	}
	void CIM_StorageExtent::NoSinglePointOfFailure(const bool value)
	{
		SetOrAddField("NoSinglePointOfFailure", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::NoSinglePointOfFailureExists() const
	{
		return ContainsField("NoSinglePointOfFailure");
	}
	void CIM_StorageExtent::RemoveNoSinglePointOfFailure()
	{
		RemoveField("NoSinglePointOfFailure");
	}

	const unsigned short CIM_StorageExtent::DataRedundancy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DataRedundancy"), ret);
		return ret;
	}
	void CIM_StorageExtent::DataRedundancy(const unsigned short value)
	{
		SetOrAddField("DataRedundancy", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::DataRedundancyExists() const
	{
		return ContainsField("DataRedundancy");
	}
	void CIM_StorageExtent::RemoveDataRedundancy()
	{
		RemoveField("DataRedundancy");
	}

	const unsigned short CIM_StorageExtent::PackageRedundancy() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PackageRedundancy"), ret);
		return ret;
	}
	void CIM_StorageExtent::PackageRedundancy(const unsigned short value)
	{
		SetOrAddField("PackageRedundancy", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::PackageRedundancyExists() const
	{
		return ContainsField("PackageRedundancy");
	}
	void CIM_StorageExtent::RemovePackageRedundancy()
	{
		RemoveField("PackageRedundancy");
	}

	const unsigned char CIM_StorageExtent::DeltaReservation() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DeltaReservation"), ret);
		return ret;
	}
	void CIM_StorageExtent::DeltaReservation(const unsigned char &value)
	{
		SetOrAddField("DeltaReservation", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::DeltaReservationExists() const
	{
		return ContainsField("DeltaReservation");
	}
	void CIM_StorageExtent::RemoveDeltaReservation()
	{
		RemoveField("DeltaReservation");
	}

	const bool CIM_StorageExtent::Primordial() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Primordial"), ret);
		return ret;
	}
	void CIM_StorageExtent::Primordial(const bool value)
	{
		SetOrAddField("Primordial", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::PrimordialExists() const
	{
		return ContainsField("Primordial");
	}
	void CIM_StorageExtent::RemovePrimordial()
	{
		RemoveField("Primordial");
	}

	const unsigned short CIM_StorageExtent::NameFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NameFormat"), ret);
		return ret;
	}
	void CIM_StorageExtent::NameFormat(const unsigned short value)
	{
		SetOrAddField("NameFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::NameFormatExists() const
	{
		return ContainsField("NameFormat");
	}
	void CIM_StorageExtent::RemoveNameFormat()
	{
		RemoveField("NameFormat");
	}

	const unsigned short CIM_StorageExtent::NameNamespace() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NameNamespace"), ret);
		return ret;
	}
	void CIM_StorageExtent::NameNamespace(const unsigned short value)
	{
		SetOrAddField("NameNamespace", TypeConverter::TypeToString(value));
	}
	bool CIM_StorageExtent::NameNamespaceExists() const
	{
		return ContainsField("NameNamespace");
	}
	void CIM_StorageExtent::RemoveNameNamespace()
	{
		RemoveField("NameNamespace");
	}

	const string CIM_StorageExtent::OtherNameNamespace() const
	{
		return GetField("OtherNameNamespace")[0];
	}
	void CIM_StorageExtent::OtherNameNamespace(const string &value)
	{
		SetOrAddField("OtherNameNamespace", value);
	}
	bool CIM_StorageExtent::OtherNameNamespaceExists() const
	{
		return ContainsField("OtherNameNamespace");
	}
	void CIM_StorageExtent::RemoveOtherNameNamespace()
	{
		RemoveField("OtherNameNamespace");
	}

	const string CIM_StorageExtent::OtherNameFormat() const
	{
		return GetField("OtherNameFormat")[0];
	}
	void CIM_StorageExtent::OtherNameFormat(const string &value)
	{
		SetOrAddField("OtherNameFormat", value);
	}
	bool CIM_StorageExtent::OtherNameFormatExists() const
	{
		return ContainsField("OtherNameFormat");
	}
	void CIM_StorageExtent::RemoveOtherNameFormat()
	{
		RemoveField("OtherNameFormat");
	}

	CimBase *CIM_StorageExtent::CreateFromCimObject(const CimObject &object)
	{
		CIM_StorageExtent *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_StorageExtent>(object);
		}
		else
		{
			ret = new CIM_StorageExtent(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_StorageExtent> > CIM_StorageExtent::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_StorageExtent>(client, keys);
	}

	void CIM_StorageExtent::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_StorageExtent::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_StorageExtent::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	unsigned int CIM_StorageExtent::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	const CimFieldAttribute CIM_StorageExtent::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_StorageExtent::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StorageExtent::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_StorageExtent::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	const CimFieldAttribute CIM_StorageExtent::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_StorageExtent::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StorageExtent::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_StorageExtent::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_StorageExtent::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_StorageExtent::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StorageExtent::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_StorageExtent::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	unsigned int CIM_StorageExtent::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_StorageExtent::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_StorageExtent::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_StorageExtent::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StorageExtent::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_StorageExtent::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	const CimFieldAttribute CIM_StorageExtent::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_StorageExtent::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_StorageExtent::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_StorageExtent::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_StorageExtent::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_StorageExtent::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_StorageExtent::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_StorageExtent::CLASS_NAME = "CIM_StorageExtent";
	const string CIM_StorageExtent::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_StorageExtent";
	const string CIM_StorageExtent::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_StorageExtent";
	const string CIM_StorageExtent::CLASS_NS_PREFIX = "ASt355";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_StorageExtent::_classMetaData;
}
}
}
}
