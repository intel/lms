//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Memory.cpp
//
//  Contents:   Capabilities and management of Memory-related LogicalDevices.
//
//              This file was automatically generated from CIM_Memory.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#include "CIM_Memory.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Memory::_metadata[] = {
		{"Volatile", false, false, false },
		{"ErrorMethodology", false, false, false },
		{"StartingAddress", false, false, false },
		{"EndingAddress", false, false, false },
		{"ErrorInfo", false, false, false },
		{"OtherErrorDescription", false, false, false },
		{"CorrectableError", false, false, false },
		{"ErrorTime", false, false, false },
		{"ErrorAccess", false, false, false },
		{"ErrorTransferSize", false, false, false },
		{"ErrorData", false, false, false },
		{"ErrorDataOrder", false, false, false },
		{"ErrorAddress", false, false, false },
		{"SystemLevelAddress", false, false, false },
		{"ErrorResolution", false, false, false },
		{"AdditionalErrorData", false, false, false },
	};
	// class fields
	const bool CIM_Memory::Volatile() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Volatile"), ret);
		return ret;
	}
	void CIM_Memory::Volatile(const bool value)
	{
		SetOrAddField("Volatile", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::VolatileExists() const
	{
		return ContainsField("Volatile");
	}
	void CIM_Memory::RemoveVolatile()
	{
		RemoveField("Volatile");
	}

	const Uint64 CIM_Memory::StartingAddress() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("StartingAddress"), ret);
		return ret;
	}
	void CIM_Memory::StartingAddress(const Uint64 value)
	{
		SetOrAddField("StartingAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::StartingAddressExists() const
	{
		return ContainsField("StartingAddress");
	}
	void CIM_Memory::RemoveStartingAddress()
	{
		RemoveField("StartingAddress");
	}

	const Uint64 CIM_Memory::EndingAddress() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("EndingAddress"), ret);
		return ret;
	}
	void CIM_Memory::EndingAddress(const Uint64 value)
	{
		SetOrAddField("EndingAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::EndingAddressExists() const
	{
		return ContainsField("EndingAddress");
	}
	void CIM_Memory::RemoveEndingAddress()
	{
		RemoveField("EndingAddress");
	}

	const unsigned short CIM_Memory::ErrorInfo() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorInfo"), ret);
		return ret;
	}
	void CIM_Memory::ErrorInfo(const unsigned short value)
	{
		SetOrAddField("ErrorInfo", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorInfoExists() const
	{
		return ContainsField("ErrorInfo");
	}
	void CIM_Memory::RemoveErrorInfo()
	{
		RemoveField("ErrorInfo");
	}

	const string CIM_Memory::OtherErrorDescription() const
	{
		return GetField("OtherErrorDescription")[0];
	}
	void CIM_Memory::OtherErrorDescription(const string &value)
	{
		SetOrAddField("OtherErrorDescription", value);
	}
	bool CIM_Memory::OtherErrorDescriptionExists() const
	{
		return ContainsField("OtherErrorDescription");
	}
	void CIM_Memory::RemoveOtherErrorDescription()
	{
		RemoveField("OtherErrorDescription");
	}

	const bool CIM_Memory::CorrectableError() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("CorrectableError"), ret);
		return ret;
	}
	void CIM_Memory::CorrectableError(const bool value)
	{
		SetOrAddField("CorrectableError", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::CorrectableErrorExists() const
	{
		return ContainsField("CorrectableError");
	}
	void CIM_Memory::RemoveCorrectableError()
	{
		RemoveField("CorrectableError");
	}

	const CimDateTime CIM_Memory::ErrorTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("ErrorTime"), ret);
		return ret;
	}
	void CIM_Memory::ErrorTime(const CimDateTime &value)
	{
		SetOrAddField("ErrorTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorTimeExists() const
	{
		return ContainsField("ErrorTime");
	}
	void CIM_Memory::RemoveErrorTime()
	{
		RemoveField("ErrorTime");
	}

	const unsigned short CIM_Memory::ErrorAccess() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorAccess"), ret);
		return ret;
	}
	void CIM_Memory::ErrorAccess(const unsigned short value)
	{
		SetOrAddField("ErrorAccess", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorAccessExists() const
	{
		return ContainsField("ErrorAccess");
	}
	void CIM_Memory::RemoveErrorAccess()
	{
		RemoveField("ErrorAccess");
	}

	const unsigned int CIM_Memory::ErrorTransferSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("ErrorTransferSize"), ret);
		return ret;
	}
	void CIM_Memory::ErrorTransferSize(const unsigned int value)
	{
		SetOrAddField("ErrorTransferSize", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorTransferSizeExists() const
	{
		return ContainsField("ErrorTransferSize");
	}
	void CIM_Memory::RemoveErrorTransferSize()
	{
		RemoveField("ErrorTransferSize");
	}

	const Base64 CIM_Memory::ErrorData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("ErrorData"), ret);
		return ret;
	}
	void CIM_Memory::ErrorData(const Base64 &value)
	{
		SetOrAddField("ErrorData", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorDataExists() const
	{
		return ContainsField("ErrorData");
	}
	void CIM_Memory::RemoveErrorData()
	{
		RemoveField("ErrorData");
	}

	const unsigned short CIM_Memory::ErrorDataOrder() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorDataOrder"), ret);
		return ret;
	}
	void CIM_Memory::ErrorDataOrder(const unsigned short value)
	{
		SetOrAddField("ErrorDataOrder", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorDataOrderExists() const
	{
		return ContainsField("ErrorDataOrder");
	}
	void CIM_Memory::RemoveErrorDataOrder()
	{
		RemoveField("ErrorDataOrder");
	}

	const Uint64 CIM_Memory::ErrorAddress() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("ErrorAddress"), ret);
		return ret;
	}
	void CIM_Memory::ErrorAddress(const Uint64 value)
	{
		SetOrAddField("ErrorAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorAddressExists() const
	{
		return ContainsField("ErrorAddress");
	}
	void CIM_Memory::RemoveErrorAddress()
	{
		RemoveField("ErrorAddress");
	}

	const bool CIM_Memory::SystemLevelAddress() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SystemLevelAddress"), ret);
		return ret;
	}
	void CIM_Memory::SystemLevelAddress(const bool value)
	{
		SetOrAddField("SystemLevelAddress", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::SystemLevelAddressExists() const
	{
		return ContainsField("SystemLevelAddress");
	}
	void CIM_Memory::RemoveSystemLevelAddress()
	{
		RemoveField("SystemLevelAddress");
	}

	const Uint64 CIM_Memory::ErrorResolution() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("ErrorResolution"), ret);
		return ret;
	}
	void CIM_Memory::ErrorResolution(const Uint64 value)
	{
		SetOrAddField("ErrorResolution", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::ErrorResolutionExists() const
	{
		return ContainsField("ErrorResolution");
	}
	void CIM_Memory::RemoveErrorResolution()
	{
		RemoveField("ErrorResolution");
	}

	const Base64 CIM_Memory::AdditionalErrorData() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("AdditionalErrorData"), ret);
		return ret;
	}
	void CIM_Memory::AdditionalErrorData(const Base64 &value)
	{
		SetOrAddField("AdditionalErrorData", TypeConverter::TypeToString(value));
	}
	bool CIM_Memory::AdditionalErrorDataExists() const
	{
		return ContainsField("AdditionalErrorData");
	}
	void CIM_Memory::RemoveAdditionalErrorData()
	{
		RemoveField("AdditionalErrorData");
	}

	CimBase *CIM_Memory::CreateFromCimObject(const CimObject &object)
	{
		CIM_Memory *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Memory>(object);
		}
		else
		{
			ret = new CIM_Memory(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Memory> > CIM_Memory::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Memory>(client, keys);
	}

	void CIM_Memory::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Memory::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Memory::CLASS_NAME = "CIM_Memory";
	const string CIM_Memory::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Memory";
	const string CIM_Memory::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Memory";
	const string CIM_Memory::CLASS_NS_PREFIX = "AMe679";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Memory::_classMetaData;
}
}
}
}
