//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ThirdPartyDataStorageService.cpp
//
//  Contents:   The ISV storage (ISVS) feature provides limited non-volatile storage services to third-party software applications running either on the local computer system host processor or on a remote system.
//
//              This file was automatically generated from AMT_ThirdPartyDataStorageService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#include "AMT_ThirdPartyDataStorageService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *AMT_ThirdPartyDataStorageService::CreateFromCimObject(const CimObject &object)
	{
		AMT_ThirdPartyDataStorageService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_ThirdPartyDataStorageService>(object);
		}
		else
		{
			ret = new AMT_ThirdPartyDataStorageService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_ThirdPartyDataStorageService> > AMT_ThirdPartyDataStorageService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_ThirdPartyDataStorageService>(client, keys);
	}

	void AMT_ThirdPartyDataStorageService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_ThirdPartyDataStorageService::GetMetaData() const
	{
		return _classMetaData;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetMTU_OUTPUT::Mtu() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Mtu"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetMTU_OUTPUT::MtuExists() const
	{
		return ContainsField("Mtu");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetMTU(GetMTU_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetMTU", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::_metadata[] = {
		{"CallerUUID", false, true },
		{"VendorName", false, true },
		{"ApplicationName", false, true },
		{"EnterpriseName", false, true },
	};
	void AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::CallerUUID(const HexBinary &value)
	{
		SetOrAddField("CallerUUID", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::VendorName(const string &value)
	{
		SetOrAddField("VendorName", value);
	}
	void AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::ApplicationName(const string &value)
	{
		SetOrAddField("ApplicationName", value);
	}
	void AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::EnterpriseName(const string &value)
	{
		SetOrAddField("EnterpriseName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::RegisterApplication_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const HexBinary AMT_ThirdPartyDataStorageService::RegisterApplication_OUTPUT::SessionHandle() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("SessionHandle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::RegisterApplication_OUTPUT::SessionHandleExists() const
	{
		return ContainsField("SessionHandle");
	}
	unsigned int AMT_ThirdPartyDataStorageService::RegisterApplication(const RegisterApplication_INPUT &input, RegisterApplication_OUTPUT &output)
	{
		return Invoke("RegisterApplication", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::UnregisterApplication_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::UnregisterApplication_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::UnregisterApplication_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::UnregisterApplication(const UnregisterApplication_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UnregisterApplication", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetRegisteredApplications_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetRegisteredApplications_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetRegisteredApplications_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageService::GetRegisteredApplications_OUTPUT::AppHandles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("AppHandles"))
			TypeConverter::StringToType(GetField("AppHandles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetRegisteredApplications_OUTPUT::AppHandlesExists() const
	{
		return ContainsField("AppHandles");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetRegisteredApplications(const GetRegisteredApplications_INPUT &input, GetRegisteredApplications_OUTPUT &output)
	{
		return Invoke("GetRegisteredApplications", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle_OUTPUT::ApplicationHandle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ApplicationHandle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle_OUTPUT::ApplicationHandleExists() const
	{
		return ContainsField("ApplicationHandle");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetCurrentApplicationHandle(const GetCurrentApplicationHandle_INPUT &input, GetCurrentApplicationHandle_OUTPUT &output)
	{
		return Invoke("GetCurrentApplicationHandle", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetApplicationAttributes_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"ApplicationBeingRequested", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetApplicationAttributes_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetApplicationAttributes_INPUT::ApplicationBeingRequested(const unsigned int value)
	{
		SetOrAddField("ApplicationBeingRequested", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetApplicationAttributes_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const string AMT_ThirdPartyDataStorageService::GetApplicationAttributes_OUTPUT::VendorName() const
	{
		return GetField("VendorName")[0];
	}
	bool AMT_ThirdPartyDataStorageService::GetApplicationAttributes_OUTPUT::VendorNameExists() const
	{
		return ContainsField("VendorName");
	}
	const string AMT_ThirdPartyDataStorageService::GetApplicationAttributes_OUTPUT::ApplicationName() const
	{
		return GetField("ApplicationName")[0];
	}
	bool AMT_ThirdPartyDataStorageService::GetApplicationAttributes_OUTPUT::ApplicationNameExists() const
	{
		return ContainsField("ApplicationName");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetApplicationAttributes(const GetApplicationAttributes_INPUT &input, GetApplicationAttributes_OUTPUT &output)
	{
		return Invoke("GetApplicationAttributes", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::RemoveApplication_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::RemoveApplication_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::RemoveApplication_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::RemoveApplication(const RemoveApplication_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemoveApplication", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetBytesAvailable_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetBytesAvailable_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetBytesAvailable_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetBytesAvailable_OUTPUT::BytesAvailable() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("BytesAvailable"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetBytesAvailable_OUTPUT::BytesAvailableExists() const
	{
		return ContainsField("BytesAvailable");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetBytesAvailable(const GetBytesAvailable_INPUT &input, GetBytesAvailable_OUTPUT &output)
	{
		return Invoke("GetBytesAvailable", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BytesRequested", false, true },
		{"BlockHidden", false, true },
		{"BlockName", false, false },
	};
	void AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::BytesRequested(const unsigned int value)
	{
		SetOrAddField("BytesRequested", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::BlockHidden(const bool value)
	{
		SetOrAddField("BlockHidden", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::BlockName(const string &value)
	{
		SetOrAddField("BlockName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::AllocateBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::AllocateBlock_OUTPUT::BlockHandle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("BlockHandle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::AllocateBlock_OUTPUT::BlockHandleExists() const
	{
		return ContainsField("BlockHandle");
	}
	unsigned int AMT_ThirdPartyDataStorageService::AllocateBlock(const AllocateBlock_INPUT &input, AllocateBlock_OUTPUT &output)
	{
		return Invoke("AllocateBlock", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::DeallocateBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::DeallocateBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::DeallocateBlock_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::DeallocateBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::DeallocateBlock(const DeallocateBlock_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("DeallocateBlock", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::RemovePermissionsGroup_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroup_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroup_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroup_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::RemovePermissionsGroup_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::RemovePermissionsGroup(const RemovePermissionsGroup_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemovePermissionsGroup", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_OUTPUT::MemberHandles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("MemberHandles"))
			TypeConverter::StringToType(GetField("MemberHandles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers_OUTPUT::MemberHandlesExists() const
	{
		return ContainsField("MemberHandles");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetPermissionsGroupMembers(const GetPermissionsGroupMembers_INPUT &input, GetPermissionsGroupMembers_OUTPUT &output)
	{
		return Invoke("GetPermissionsGroupMembers", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockOwnerApplication", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_INPUT::BlockOwnerApplication(const unsigned int value)
	{
		SetOrAddField("BlockOwnerApplication", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_OUTPUT::BlockHandles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("BlockHandles"))
			TypeConverter::StringToType(GetField("BlockHandles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetAllocatedBlocks_OUTPUT::BlockHandlesExists() const
	{
		return ContainsField("BlockHandles");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetAllocatedBlocks(const GetAllocatedBlocks_INPUT &input, GetAllocatedBlocks_OUTPUT &output)
	{
		return Invoke("GetAllocatedBlocks", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
		{"MemberHandles", false, true },
	};
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::MemberHandles(const vector<unsigned int> &value)
	{
		SetOrAddField("MemberHandles", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::RemovePermissionsGroupMembers(const RemovePermissionsGroupMembers_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemovePermissionsGroupMembers", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetBlockAttributes_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetBlockAttributes_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetBlockAttributes_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetBlockAttributes_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("BlockSize"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockSizeExists() const
	{
		return ContainsField("BlockSize");
	}
	const bool AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockHidden() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BlockHidden"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockHiddenExists() const
	{
		return ContainsField("BlockHidden");
	}
	const string AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockName() const
	{
		return GetField("BlockName")[0];
	}
	bool AMT_ThirdPartyDataStorageService::GetBlockAttributes_OUTPUT::BlockNameExists() const
	{
		return ContainsField("BlockName");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetBlockAttributes(const GetBlockAttributes_INPUT &input, GetBlockAttributes_OUTPUT &output)
	{
		return Invoke("GetBlockAttributes", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
		{"MemberHandles", false, true },
	};
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::MemberHandles(const vector<unsigned int> &value)
	{
		SetOrAddField("MemberHandles", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::AddPermissionsGroupMembers(const AddPermissionsGroupMembers_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("AddPermissionsGroupMembers", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::UnlockBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::UnlockBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::UnlockBlock_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::UnlockBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::UnlockBlock(const UnlockBlock_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UnlockBlock", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
		{"GroupName", false, true },
	};
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::GroupName(const string &value)
	{
		SetOrAddField("GroupName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::SetPermissionsGroupName_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::SetPermissionsGroupName(const SetPermissionsGroupName_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPermissionsGroupName", input, output);
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetTimeoutValues_OUTPUT::RegistrationTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("RegistrationTimeout"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetTimeoutValues_OUTPUT::RegistrationTimeoutExists() const
	{
		return ContainsField("RegistrationTimeout");
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetTimeoutValues_OUTPUT::LockTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("LockTimeout"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetTimeoutValues_OUTPUT::LockTimeoutExists() const
	{
		return ContainsField("LockTimeout");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetTimeoutValues(GetTimeoutValues_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetTimeoutValues", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"ByteOffset", false, true },
		{"ByteCount", false, true },
	};
	void AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::ByteOffset(const unsigned int value)
	{
		SetOrAddField("ByteOffset", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::ByteCount(const unsigned int value)
	{
		SetOrAddField("ByteCount", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::ReadBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const Base64 AMT_ThirdPartyDataStorageService::ReadBlock_OUTPUT::Data() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("Data"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::ReadBlock_OUTPUT::DataExists() const
	{
		return ContainsField("Data");
	}
	unsigned int AMT_ThirdPartyDataStorageService::ReadBlock(const ReadBlock_INPUT &input, ReadBlock_OUTPUT &output)
	{
		return Invoke("ReadBlock", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"ByteOffset", false, true },
		{"Data", false, true },
	};
	void AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::ByteOffset(const unsigned int value)
	{
		SetOrAddField("ByteOffset", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::Data(const Base64 &value)
	{
		SetOrAddField("Data", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::WriteBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::WriteBlock_OUTPUT::BytesWritten() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("BytesWritten"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::WriteBlock_OUTPUT::BytesWrittenExists() const
	{
		return ContainsField("BytesWritten");
	}
	unsigned int AMT_ThirdPartyDataStorageService::WriteBlock(const WriteBlock_INPUT &input, WriteBlock_OUTPUT &output)
	{
		return Invoke("WriteBlock", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
		{"Permissions", false, true },
	};
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::Permissions(const unsigned int value)
	{
		SetOrAddField("Permissions", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::SetPermissionsGroupPermissions(const SetPermissionsGroupPermissions_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPermissionsGroupPermissions", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::SetBlockVisibility_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"BlockHidden", false, true },
	};
	void AMT_ThirdPartyDataStorageService::SetBlockVisibility_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetBlockVisibility_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetBlockVisibility_INPUT::BlockHidden(const bool value)
	{
		SetOrAddField("BlockHidden", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::SetBlockVisibility_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::SetBlockVisibility(const SetBlockVisibility_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetBlockVisibility", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_INPUT::GroupHandle(const unsigned int value)
	{
		SetOrAddField("GroupHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	const string AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_OUTPUT::Name() const
	{
		return GetField("Name")[0];
	}
	bool AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_OUTPUT::NameExists() const
	{
		return ContainsField("Name");
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_OUTPUT::Permissions() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Permissions"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes_OUTPUT::PermissionsExists() const
	{
		return ContainsField("Permissions");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetPermissionsGroupAttributes(const GetPermissionsGroupAttributes_INPUT &input, GetPermissionsGroupAttributes_OUTPUT &output)
	{
		return Invoke("GetPermissionsGroupAttributes", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::GetPermissionsGroups_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroups_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::GetPermissionsGroups_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::GetPermissionsGroups_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const vector<unsigned int> AMT_ThirdPartyDataStorageService::GetPermissionsGroups_OUTPUT::GroupHandles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("GroupHandles"))
			TypeConverter::StringToType(GetField("GroupHandles"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetPermissionsGroups_OUTPUT::GroupHandlesExists() const
	{
		return ContainsField("GroupHandles");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetPermissionsGroups(const GetPermissionsGroups_INPUT &input, GetPermissionsGroups_OUTPUT &output)
	{
		return Invoke("GetPermissionsGroups", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::SetBlockName_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"BlockName", false, true },
	};
	void AMT_ThirdPartyDataStorageService::SetBlockName_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetBlockName_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::SetBlockName_INPUT::BlockName(const string &value)
	{
		SetOrAddField("BlockName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::SetBlockName_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 3);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::SetBlockName(const SetBlockName_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetBlockName", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
		{"GroupPermissions", false, true },
		{"GroupName", false, false },
	};
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::GroupPermissions(const unsigned int value)
	{
		SetOrAddField("GroupPermissions", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::GroupName(const string &value)
	{
		SetOrAddField("GroupName", value);
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::AddPermissionsGroup_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 4);
		return ret;
	}
	const unsigned int AMT_ThirdPartyDataStorageService::AddPermissionsGroup_OUTPUT::GroupHandle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("GroupHandle"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::AddPermissionsGroup_OUTPUT::GroupHandleExists() const
	{
		return ContainsField("GroupHandle");
	}
	unsigned int AMT_ThirdPartyDataStorageService::AddPermissionsGroup(const AddPermissionsGroup_INPUT &input, AddPermissionsGroup_OUTPUT &output)
	{
		return Invoke("AddPermissionsGroup", input, output);
	}
	const CimFieldAttribute AMT_ThirdPartyDataStorageService::LockBlock_INPUT::_metadata[] = {
		{"SessionHandle", false, true },
		{"BlockHandle", false, true },
	};
	void AMT_ThirdPartyDataStorageService::LockBlock_INPUT::SessionHandle(const HexBinary &value)
	{
		SetOrAddField("SessionHandle", TypeConverter::TypeToString(value));
	}
	void AMT_ThirdPartyDataStorageService::LockBlock_INPUT::BlockHandle(const unsigned int value)
	{
		SetOrAddField("BlockHandle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_ThirdPartyDataStorageService::LockBlock_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_ThirdPartyDataStorageService::LockBlock(const LockBlock_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("LockBlock", input, output);
	}
	const unsigned int AMT_ThirdPartyDataStorageService::GetWriteEraseLimit_OUTPUT::WriteEraseLimit() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("WriteEraseLimit"), ret);
		return ret;
	}
	bool AMT_ThirdPartyDataStorageService::GetWriteEraseLimit_OUTPUT::WriteEraseLimitExists() const
	{
		return ContainsField("WriteEraseLimit");
	}
	unsigned int AMT_ThirdPartyDataStorageService::GetWriteEraseLimit(GetWriteEraseLimit_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetWriteEraseLimit", input, output);
	}
	const string AMT_ThirdPartyDataStorageService::CLASS_NAME = "AMT_ThirdPartyDataStorageService";
	const string AMT_ThirdPartyDataStorageService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ThirdPartyDataStorageService";
	const string AMT_ThirdPartyDataStorageService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_ThirdPartyDataStorageService";
	const string AMT_ThirdPartyDataStorageService::CLASS_NS_PREFIX = "ATh46";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_ThirdPartyDataStorageService::_classMetaData;
}
}
}
}
