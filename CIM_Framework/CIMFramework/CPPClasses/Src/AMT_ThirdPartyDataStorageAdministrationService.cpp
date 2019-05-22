//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ThirdPartyDataStorageAdministrationService.cpp
//
//  Contents:   The Storage Administration service enables administrators to reconfigure the global parameters that govern allocation and use of third-party non-volatile storage. It also enables to retrieve various management data, and perform management actions.
//
//              This file was automatically generated from AMT_ThirdPartyDataStorageAdministrationService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ThirdPartyDataStorageAdministrationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_ThirdPartyDataStorageAdministrationService::CreateFromCimObject(const CimObject &object)
	{
		AMT_ThirdPartyDataStorageAdministrationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ThirdPartyDataStorageAdministrationService>(object);
		}
		else
		{
			ret = new AMT_ThirdPartyDataStorageAdministrationService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ThirdPartyDataStorageAdministrationService> > AMT_ThirdPartyDataStorageAdministrationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ThirdPartyDataStorageAdministrationService>(client, keys);
	}

	void AMT_ThirdPartyDataStorageAdministrationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ThirdPartyDataStorageAdministrationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalStorage() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalStorage"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalStorageExists() const
	{
		return ContainsField("TotalStorage");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalAllocatedStorage() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalAllocatedStorage"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalAllocatedStorageExists() const
	{
		return ContainsField("TotalAllocatedStorage");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxPartnerStorage() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxPartnerStorage"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxPartnerStorageExists() const
	{
		return ContainsField("MaxPartnerStorage");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalPartnerAllocatedStorage() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalPartnerAllocatedStorage"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::TotalPartnerAllocatedStorageExists() const
	{
		return ContainsField("TotalPartnerAllocatedStorage");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxNonPartnerStorage() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxNonPartnerStorage"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxNonPartnerStorageExists() const
	{
		return ContainsField("MaxNonPartnerStorage");
	}
	const unsigned short AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxFpaclEntries() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxFpaclEntries"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxFpaclEntriesExists() const
	{
		return ContainsField("MaxFpaclEntries");
	}
	const unsigned short AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxAslEntries() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxAslEntries"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxAslEntriesExists() const
	{
		return ContainsField("MaxAslEntries");
	}
	const unsigned short AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxEaclEntries() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxEaclEntries"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxEaclEntriesExists() const
	{
		return ContainsField("MaxEaclEntries");
	}
	const unsigned short AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxGroupsPerBlock() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxGroupsPerBlock"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxGroupsPerBlockExists() const
	{
		return ContainsField("MaxGroupsPerBlock");
	}
	const unsigned short AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxMembersPerGroup() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxMembersPerGroup"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxMembersPerGroupExists() const
	{
		return ContainsField("MaxMembersPerGroup");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxNonPartnerTotalAllocationSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxNonPartnerTotalAllocationSize"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes_OUTPUT::MaxNonPartnerTotalAllocationSizeExists() const
	{
		return ContainsField("MaxNonPartnerTotalAllocationSize");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetGlobalStorageAttributes(GetGlobalStorageAttributes_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetGlobalStorageAttributes", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::SetGlobalStorageAttributes_INPUT::_metadata[] = {
		{"MaxPartnerStorage", false, false },
		{"MaxNonPartnerTotalAllocationSize", false, false },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::SetGlobalStorageAttributes_INPUT::MaxPartnerStorage(const unsigned int value)
	{
		SetOrAddField("MaxPartnerStorage", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageAdministrationService::SetGlobalStorageAttributes_INPUT::MaxNonPartnerTotalAllocationSize(const unsigned int value)
	{
		SetOrAddField("MaxNonPartnerTotalAllocationSize", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::SetGlobalStorageAttributes_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::SetGlobalStorageAttributes(const SetGlobalStorageAttributes_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetGlobalStorageAttributes", input, output);
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageAdministrationService::AdminGetRegisteredApplications_OUTPUT::ApplicationHandles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("ApplicationHandles"))
			TypeConverter::StringToType(GetField("ApplicationHandles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetRegisteredApplications_OUTPUT::ApplicationHandlesExists() const
	{
		return ContainsField("ApplicationHandles");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::AdminGetRegisteredApplications(AdminGetRegisteredApplications_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("AdminGetRegisteredApplications", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::AttrType() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AttrType"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::AttrTypeExists() const
	{
		return ContainsField("AttrType");
	}
	const Base64 AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::UUID() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("UUID"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::UUIDExists() const
	{
		return ContainsField("UUID");
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::VendorName() const
	{
		return GetField("VendorName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::VendorNameExists() const
	{
		return ContainsField("VendorName");
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::ApplicationName() const
	{
		return GetField("ApplicationName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::ApplicationNameExists() const
	{
		return ContainsField("ApplicationName");
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::EnterpriseName() const
	{
		return GetField("EnterpriseName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::EnterpriseNameExists() const
	{
		return ContainsField("EnterpriseName");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::CurrentAllocationSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CurrentAllocationSize"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::CurrentAllocationSizeExists() const
	{
		return ContainsField("CurrentAllocationSize");
	}
	const bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::ActiveSession() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActiveSession"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::ActiveSessionExists() const
	{
		return ContainsField("ActiveSession");
	}
	const bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::Partner() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Partner"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes_OUTPUT::PartnerExists() const
	{
		return ContainsField("Partner");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::AdminGetApplicationAttributes(const AdminGetApplicationAttributes_INPUT &input, AdminGetApplicationAttributes_OUTPUT &output)
	{
		return Invoke("AdminGetApplicationAttributes", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::AdminRemoveApplication_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::AdminRemoveApplication_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::AdminRemoveApplication_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::AdminRemoveApplication(const AdminRemoveApplication_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AdminRemoveApplication", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry_INPUT::_metadata[] = {
		{"EnterpriseName", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry_INPUT::EnterpriseName(const string &value)
	{
		SetOrAddField("EnterpriseName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry_OUTPUT::Handle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Handle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry_OUTPUT::HandleExists() const
	{
		return ContainsField("Handle");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::AddStorageEaclEntry(const AddStorageEaclEntry_INPUT &input, AddStorageEaclEntry_OUTPUT &output)
	{
		return Invoke("AddStorageEaclEntry", input, output);
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageEaclEntries_OUTPUT::Handles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("Handles"))
			TypeConverter::StringToType(GetField("Handles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageEaclEntries_OUTPUT::HandlesExists() const
	{
		return ContainsField("Handles");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageEaclEntries(EnumerateStorageEaclEntries_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("EnumerateStorageEaclEntries", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry_OUTPUT::EnterpriseName() const
	{
		return GetField("EnterpriseName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry_OUTPUT::EnterpriseNameExists() const
	{
		return ContainsField("EnterpriseName");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetStorageEaclEntry(const GetStorageEaclEntry_INPUT &input, GetStorageEaclEntry_OUTPUT &output)
	{
		return Invoke("GetStorageEaclEntry", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageEaclEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageEaclEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageEaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageEaclEntry(const RemoveStorageEaclEntry_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemoveStorageEaclEntry", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::_metadata[] = {
		{"AttrType", false, true },
		{"ApplicationName", false, true },
		{"VendorName", false, true },
		{"IsPartner", false, true },
		{"TotalAllocationSize", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::AttrType(const unsigned int value)
	{
		SetOrAddField("AttrType", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::ApplicationName(const string &value)
	{
		SetOrAddField("ApplicationName", value);
	}
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::VendorName(const string &value)
	{
		SetOrAddField("VendorName", value);
	}
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::IsPartner(const bool value)
	{
		SetOrAddField("IsPartner", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::TotalAllocationSize(const unsigned int value)
	{
		SetOrAddField("TotalAllocationSize", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_OUTPUT::Handle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Handle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry_OUTPUT::HandleExists() const
	{
		return ContainsField("Handle");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::AddStorageFpaclEntry(const AddStorageFpaclEntry_INPUT &input, AddStorageFpaclEntry_OUTPUT &output)
	{
		return Invoke("AddStorageFpaclEntry", input, output);
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageAllocEntries_OUTPUT::Handles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("Handles"))
			TypeConverter::StringToType(GetField("Handles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageAllocEntries_OUTPUT::HandlesExists() const
	{
		return ContainsField("Handles");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::EnumerateStorageAllocEntries(EnumerateStorageAllocEntries_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("EnumerateStorageAllocEntries", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::AttrType() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AttrType"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::AttrTypeExists() const
	{
		return ContainsField("AttrType");
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::ApplicationName() const
	{
		return GetField("ApplicationName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::ApplicationNameExists() const
	{
		return ContainsField("ApplicationName");
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::VendorName() const
	{
		return GetField("VendorName")[0];
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::VendorNameExists() const
	{
		return ContainsField("VendorName");
	}
	const bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::IsPartner() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsPartner"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::IsPartnerExists() const
	{
		return ContainsField("IsPartner");
	}
	const unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::TotalAllocationSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalAllocationSize"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry_OUTPUT::TotalAllocationSizeExists() const
	{
		return ContainsField("TotalAllocationSize");
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::GetStorageAllocEntry(const GetStorageAllocEntry_INPUT &input, GetStorageAllocEntry_OUTPUT &output)
	{
		return Invoke("GetStorageAllocEntry", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::UpdateStorageFpaclEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
		{"NewAllocationSize", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::UpdateStorageFpaclEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageAdministrationService::UpdateStorageFpaclEntry_INPUT::NewAllocationSize(const unsigned int value)
	{
		SetOrAddField("NewAllocationSize", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::UpdateStorageFpaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::UpdateStorageFpaclEntry(const UpdateStorageFpaclEntry_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UpdateStorageFpaclEntry", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageFpaclEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageFpaclEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageFpaclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageAdministrationService::RemoveStorageFpaclEntry(const RemoveStorageFpaclEntry_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemoveStorageFpaclEntry", input, output);
	}
	const string AMT_ThirdPartyDataStorageAdministrationService::CLASS_NAME = "AMT_ThirdPartyDataStorageAdministrationService";
	const string AMT_ThirdPartyDataStorageAdministrationService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ThirdPartyDataStorageAdministrationService";
	const string AMT_ThirdPartyDataStorageAdministrationService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ThirdPartyDataStorageAdministrationService";
	const string AMT_ThirdPartyDataStorageAdministrationService::CLASS_NS_PREFIX = "ATh836";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ThirdPartyDataStorageAdministrationService::_classMetaData;
}
}
}
}
