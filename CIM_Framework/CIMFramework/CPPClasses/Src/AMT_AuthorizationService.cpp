//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuthorizationService.cpp
//
//  Contents:   Describes the Authorization Service, which is responsible for Access Control management in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_AuthorizationService.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_AuthorizationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_AuthorizationService::_metadata[] = {
		{"AllowHttpQopAuthOnly", false, false, false },
	};
	// class fields
	const unsigned int AMT_AuthorizationService::AllowHttpQopAuthOnly() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AllowHttpQopAuthOnly"), ret);
		return ret;
	}
	void AMT_AuthorizationService::AllowHttpQopAuthOnly(const unsigned int value)
	{
		SetOrAddField("AllowHttpQopAuthOnly", TypeConverter::TypeToString(value));
	}
	bool AMT_AuthorizationService::AllowHttpQopAuthOnlyExists() const
	{
		return ContainsField("AllowHttpQopAuthOnly");
	}
	void AMT_AuthorizationService::RemoveAllowHttpQopAuthOnly()
	{
		RemoveField("AllowHttpQopAuthOnly");
	}

	CimBase *AMT_AuthorizationService::CreateFromCimObject(const CimObject &object)
	{
		AMT_AuthorizationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_AuthorizationService>(object);
		}
		else
		{
			ret = new AMT_AuthorizationService(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_AuthorizationService> > AMT_AuthorizationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_AuthorizationService>(client, keys);
	}

	void AMT_AuthorizationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_AuthorizationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute AMT_AuthorizationService::AddUserAclEntryEx_INPUT::_metadata[] = {
		{"DigestUsername", false, false },
		{"DigestPassword", false, false },
		{"KerberosUserSid", false, false },
		{"AccessPermission", false, true },
		{"Realms", false, false },
	};
	void AMT_AuthorizationService::AddUserAclEntryEx_INPUT::DigestUsername(const string &value)
	{
		SetOrAddField("DigestUsername", value);
	}
	void AMT_AuthorizationService::AddUserAclEntryEx_INPUT::DigestPassword(const Base64 &value)
	{
		SetOrAddField("DigestPassword", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::AddUserAclEntryEx_INPUT::KerberosUserSid(const Base64 &value)
	{
		SetOrAddField("KerberosUserSid", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::AddUserAclEntryEx_INPUT::AccessPermission(const unsigned int value)
	{
		SetOrAddField("AccessPermission", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::AddUserAclEntryEx_INPUT::Realms(const vector<unsigned int> &value)
	{
		SetOrAddField("Realms", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::AddUserAclEntryEx_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 5);
		return ret;
	}
	const unsigned int AMT_AuthorizationService::AddUserAclEntryEx_OUTPUT::Handle() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Handle"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::AddUserAclEntryEx_OUTPUT::HandleExists() const
	{
		return ContainsField("Handle");
	}
	unsigned int AMT_AuthorizationService::AddUserAclEntryEx(const AddUserAclEntryEx_INPUT &input, AddUserAclEntryEx_OUTPUT &output)
	{
		return Invoke("AddUserAclEntryEx", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::EnumerateUserAclEntries_INPUT::_metadata[] = {
		{"StartIndex", false, true },
	};
	void AMT_AuthorizationService::EnumerateUserAclEntries_INPUT::StartIndex(const unsigned int value)
	{
		SetOrAddField("StartIndex", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::EnumerateUserAclEntries_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const unsigned int AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::TotalCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("TotalCount"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::TotalCountExists() const
	{
		return ContainsField("TotalCount");
	}
	const unsigned int AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::HandlesCount() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("HandlesCount"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::HandlesCountExists() const
	{
		return ContainsField("HandlesCount");
	}
	const vector<unsigned int> AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::Handles() const
	{
		vector<unsigned int> ret;
		if(ContainsField("Handles"))
			TypeConverter::StringToType(GetField("Handles"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::EnumerateUserAclEntries_OUTPUT::HandlesExists() const
	{
		return ContainsField("Handles");
	}
	unsigned int AMT_AuthorizationService::EnumerateUserAclEntries(const EnumerateUserAclEntries_INPUT &input, EnumerateUserAclEntries_OUTPUT &output)
	{
		return Invoke("EnumerateUserAclEntries", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::GetUserAclEntryEx_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_AuthorizationService::GetUserAclEntryEx_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::GetUserAclEntryEx_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const string AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::DigestUsername() const
	{
		return GetField("DigestUsername")[0];
	}
	bool AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::DigestUsernameExists() const
	{
		return ContainsField("DigestUsername");
	}
	const Base64 AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::DigestPassword() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("DigestPassword"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::DigestPasswordExists() const
	{
		return ContainsField("DigestPassword");
	}
	const Base64 AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::KerberosUserSid() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("KerberosUserSid"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::KerberosUserSidExists() const
	{
		return ContainsField("KerberosUserSid");
	}
	const unsigned int AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::AccessPermission() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("AccessPermission"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::AccessPermissionExists() const
	{
		return ContainsField("AccessPermission");
	}
	const vector<unsigned int> AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::Realms() const
	{
		vector<unsigned int> ret;
		if(ContainsField("Realms"))
			TypeConverter::StringToType(GetField("Realms"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetUserAclEntryEx_OUTPUT::RealmsExists() const
	{
		return ContainsField("Realms");
	}
	unsigned int AMT_AuthorizationService::GetUserAclEntryEx(const GetUserAclEntryEx_INPUT &input, GetUserAclEntryEx_OUTPUT &output)
	{
		return Invoke("GetUserAclEntryEx", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::_metadata[] = {
		{"Handle", false, true },
		{"DigestUsername", false, false },
		{"DigestPassword", false, false },
		{"KerberosUserSid", false, false },
		{"AccessPermission", false, true },
		{"Realms", false, false },
	};
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::DigestUsername(const string &value)
	{
		SetOrAddField("DigestUsername", value);
	}
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::DigestPassword(const Base64 &value)
	{
		SetOrAddField("DigestPassword", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::KerberosUserSid(const Base64 &value)
	{
		SetOrAddField("KerberosUserSid", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::AccessPermission(const unsigned int value)
	{
		SetOrAddField("AccessPermission", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::Realms(const vector<unsigned int> &value)
	{
		SetOrAddField("Realms", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::UpdateUserAclEntryEx_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 6);
		return ret;
	}
	unsigned int AMT_AuthorizationService::UpdateUserAclEntryEx(const UpdateUserAclEntryEx_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("UpdateUserAclEntryEx", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::RemoveUserAclEntry_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_AuthorizationService::RemoveUserAclEntry_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::RemoveUserAclEntry_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int AMT_AuthorizationService::RemoveUserAclEntry(const RemoveUserAclEntry_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("RemoveUserAclEntry", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::SetAdminAclEntryEx_INPUT::_metadata[] = {
		{"Username", false, true },
		{"DigestPassword", false, true },
	};
	void AMT_AuthorizationService::SetAdminAclEntryEx_INPUT::Username(const string &value)
	{
		SetOrAddField("Username", value);
	}
	void AMT_AuthorizationService::SetAdminAclEntryEx_INPUT::DigestPassword(const Base64 &value)
	{
		SetOrAddField("DigestPassword", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::SetAdminAclEntryEx_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_AuthorizationService::SetAdminAclEntryEx(const SetAdminAclEntryEx_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetAdminAclEntryEx", input, output);
	}
	const string AMT_AuthorizationService::GetAdminAclEntry_OUTPUT::Username() const
	{
		return GetField("Username")[0];
	}
	bool AMT_AuthorizationService::GetAdminAclEntry_OUTPUT::UsernameExists() const
	{
		return ContainsField("Username");
	}
	unsigned int AMT_AuthorizationService::GetAdminAclEntry(GetAdminAclEntry_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetAdminAclEntry", input, output);
	}
	const bool AMT_AuthorizationService::GetAdminAclEntryStatus_OUTPUT::IsDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsDefault"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetAdminAclEntryStatus_OUTPUT::IsDefaultExists() const
	{
		return ContainsField("IsDefault");
	}
	unsigned int AMT_AuthorizationService::GetAdminAclEntryStatus(GetAdminAclEntryStatus_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetAdminAclEntryStatus", input, output);
	}
	const bool AMT_AuthorizationService::GetAdminNetAclEntryStatus_OUTPUT::IsDefault() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IsDefault"), ret);
		return ret;
	}
	bool AMT_AuthorizationService::GetAdminNetAclEntryStatus_OUTPUT::IsDefaultExists() const
	{
		return ContainsField("IsDefault");
	}
	unsigned int AMT_AuthorizationService::GetAdminNetAclEntryStatus(GetAdminNetAclEntryStatus_OUTPUT &output)
	{
		CimEmptyParam input;
		return Invoke("GetAdminNetAclEntryStatus", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::SetAclEnabledState_INPUT::_metadata[] = {
		{"Handle", false, true },
		{"Enabled", false, true },
	};
	void AMT_AuthorizationService::SetAclEnabledState_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	void AMT_AuthorizationService::SetAclEnabledState_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::SetAclEnabledState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int AMT_AuthorizationService::SetAclEnabledState(const SetAclEnabledState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetAclEnabledState", input, output);
	}
	const CimFieldAttribute AMT_AuthorizationService::GetAclEnabledState_INPUT::_metadata[] = {
		{"Handle", false, true },
	};
	void AMT_AuthorizationService::GetAclEnabledState_INPUT::Handle(const unsigned int value)
	{
		SetOrAddField("Handle", TypeConverter::TypeToString(value));
	}
	const VectorFieldData AMT_AuthorizationService::GetAclEnabledState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	const bool AMT_AuthorizationService::GetAclEnabledState_OUTPUT::Enabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Enabled"), ret);
		return ret;
	}
	unsigned int AMT_AuthorizationService::GetAclEnabledState(const GetAclEnabledState_INPUT &input, GetAclEnabledState_OUTPUT &output)
	{
		return Invoke("GetAclEnabledState", input, output);
	}
	const string AMT_AuthorizationService::CLASS_NAME = "AMT_AuthorizationService";
	const string AMT_AuthorizationService::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuthorizationService";
	const string AMT_AuthorizationService::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_AuthorizationService";
	const string AMT_AuthorizationService::CLASS_NS_PREFIX = "AAu307";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_AuthorizationService::_classMetaData;
}
}
}
}
