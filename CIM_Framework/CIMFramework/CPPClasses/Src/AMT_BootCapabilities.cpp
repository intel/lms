//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_BootCapabilities.cpp
//
//  Contents:   Boot options that the Intel(R) AMT device supports.
//
//              This file was automatically generated from AMT_BootCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_BootCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_BootCapabilities::_metadata[] = {
		{"IDER", false, false, false },
		{"SOL", false, false, false },
		{"BIOSReflash", false, false, false },
		{"BIOSSetup", false, false, false },
		{"BIOSPause", false, false, false },
		{"ForcePXEBoot", false, false, false },
		{"ForceHardDriveBoot", false, false, false },
		{"ForceHardDriveSafeModeBoot", false, false, false },
		{"ForceDiagnosticBoot", false, false, false },
		{"ForceCDorDVDBoot", false, false, false },
		{"VerbosityScreenBlank", false, false, false },
		{"PowerButtonLock", false, false, false },
		{"ResetButtonLock", false, false, false },
		{"KeyboardLock", false, false, false },
		{"SleepButtonLock", false, false, false },
		{"UserPasswordBypass", false, false, false },
		{"ForcedProgressEvents", false, false, false },
		{"VerbosityVerbose", false, false, false },
		{"VerbosityQuiet", false, false, false },
		{"ConfigurationDataReset", false, false, false },
		{"BIOSSecureBoot", false, false, false },
		{"SecureErase", false, false, false },
	};
	// class fields
	const bool AMT_BootCapabilities::IDER() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("IDER"), ret);
		return ret;
	}
	void AMT_BootCapabilities::IDER(const bool value)
	{
		SetOrAddField("IDER", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::IDERExists() const
	{
		return ContainsField("IDER");
	}
	void AMT_BootCapabilities::RemoveIDER()
	{
		RemoveField("IDER");
	}

	const bool AMT_BootCapabilities::SOL() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SOL"), ret);
		return ret;
	}
	void AMT_BootCapabilities::SOL(const bool value)
	{
		SetOrAddField("SOL", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::SOLExists() const
	{
		return ContainsField("SOL");
	}
	void AMT_BootCapabilities::RemoveSOL()
	{
		RemoveField("SOL");
	}

	const bool AMT_BootCapabilities::BIOSReflash() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSReflash"), ret);
		return ret;
	}
	void AMT_BootCapabilities::BIOSReflash(const bool value)
	{
		SetOrAddField("BIOSReflash", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::BIOSReflashExists() const
	{
		return ContainsField("BIOSReflash");
	}
	void AMT_BootCapabilities::RemoveBIOSReflash()
	{
		RemoveField("BIOSReflash");
	}

	const bool AMT_BootCapabilities::BIOSSetup() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSSetup"), ret);
		return ret;
	}
	void AMT_BootCapabilities::BIOSSetup(const bool value)
	{
		SetOrAddField("BIOSSetup", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::BIOSSetupExists() const
	{
		return ContainsField("BIOSSetup");
	}
	void AMT_BootCapabilities::RemoveBIOSSetup()
	{
		RemoveField("BIOSSetup");
	}

	const bool AMT_BootCapabilities::BIOSPause() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSPause"), ret);
		return ret;
	}
	void AMT_BootCapabilities::BIOSPause(const bool value)
	{
		SetOrAddField("BIOSPause", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::BIOSPauseExists() const
	{
		return ContainsField("BIOSPause");
	}
	void AMT_BootCapabilities::RemoveBIOSPause()
	{
		RemoveField("BIOSPause");
	}

	const bool AMT_BootCapabilities::ForcePXEBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForcePXEBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForcePXEBoot(const bool value)
	{
		SetOrAddField("ForcePXEBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForcePXEBootExists() const
	{
		return ContainsField("ForcePXEBoot");
	}
	void AMT_BootCapabilities::RemoveForcePXEBoot()
	{
		RemoveField("ForcePXEBoot");
	}

	const bool AMT_BootCapabilities::ForceHardDriveBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForceHardDriveBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForceHardDriveBoot(const bool value)
	{
		SetOrAddField("ForceHardDriveBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForceHardDriveBootExists() const
	{
		return ContainsField("ForceHardDriveBoot");
	}
	void AMT_BootCapabilities::RemoveForceHardDriveBoot()
	{
		RemoveField("ForceHardDriveBoot");
	}

	const bool AMT_BootCapabilities::ForceHardDriveSafeModeBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForceHardDriveSafeModeBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForceHardDriveSafeModeBoot(const bool value)
	{
		SetOrAddField("ForceHardDriveSafeModeBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForceHardDriveSafeModeBootExists() const
	{
		return ContainsField("ForceHardDriveSafeModeBoot");
	}
	void AMT_BootCapabilities::RemoveForceHardDriveSafeModeBoot()
	{
		RemoveField("ForceHardDriveSafeModeBoot");
	}

	const bool AMT_BootCapabilities::ForceDiagnosticBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForceDiagnosticBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForceDiagnosticBoot(const bool value)
	{
		SetOrAddField("ForceDiagnosticBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForceDiagnosticBootExists() const
	{
		return ContainsField("ForceDiagnosticBoot");
	}
	void AMT_BootCapabilities::RemoveForceDiagnosticBoot()
	{
		RemoveField("ForceDiagnosticBoot");
	}

	const bool AMT_BootCapabilities::ForceCDorDVDBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForceCDorDVDBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForceCDorDVDBoot(const bool value)
	{
		SetOrAddField("ForceCDorDVDBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForceCDorDVDBootExists() const
	{
		return ContainsField("ForceCDorDVDBoot");
	}
	void AMT_BootCapabilities::RemoveForceCDorDVDBoot()
	{
		RemoveField("ForceCDorDVDBoot");
	}

	const bool AMT_BootCapabilities::VerbosityScreenBlank() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("VerbosityScreenBlank"), ret);
		return ret;
	}
	void AMT_BootCapabilities::VerbosityScreenBlank(const bool value)
	{
		SetOrAddField("VerbosityScreenBlank", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::VerbosityScreenBlankExists() const
	{
		return ContainsField("VerbosityScreenBlank");
	}
	void AMT_BootCapabilities::RemoveVerbosityScreenBlank()
	{
		RemoveField("VerbosityScreenBlank");
	}

	const bool AMT_BootCapabilities::PowerButtonLock() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PowerButtonLock"), ret);
		return ret;
	}
	void AMT_BootCapabilities::PowerButtonLock(const bool value)
	{
		SetOrAddField("PowerButtonLock", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::PowerButtonLockExists() const
	{
		return ContainsField("PowerButtonLock");
	}
	void AMT_BootCapabilities::RemovePowerButtonLock()
	{
		RemoveField("PowerButtonLock");
	}

	const bool AMT_BootCapabilities::ResetButtonLock() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ResetButtonLock"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ResetButtonLock(const bool value)
	{
		SetOrAddField("ResetButtonLock", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ResetButtonLockExists() const
	{
		return ContainsField("ResetButtonLock");
	}
	void AMT_BootCapabilities::RemoveResetButtonLock()
	{
		RemoveField("ResetButtonLock");
	}

	const bool AMT_BootCapabilities::KeyboardLock() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("KeyboardLock"), ret);
		return ret;
	}
	void AMT_BootCapabilities::KeyboardLock(const bool value)
	{
		SetOrAddField("KeyboardLock", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::KeyboardLockExists() const
	{
		return ContainsField("KeyboardLock");
	}
	void AMT_BootCapabilities::RemoveKeyboardLock()
	{
		RemoveField("KeyboardLock");
	}

	const bool AMT_BootCapabilities::SleepButtonLock() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SleepButtonLock"), ret);
		return ret;
	}
	void AMT_BootCapabilities::SleepButtonLock(const bool value)
	{
		SetOrAddField("SleepButtonLock", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::SleepButtonLockExists() const
	{
		return ContainsField("SleepButtonLock");
	}
	void AMT_BootCapabilities::RemoveSleepButtonLock()
	{
		RemoveField("SleepButtonLock");
	}

	const bool AMT_BootCapabilities::UserPasswordBypass() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UserPasswordBypass"), ret);
		return ret;
	}
	void AMT_BootCapabilities::UserPasswordBypass(const bool value)
	{
		SetOrAddField("UserPasswordBypass", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::UserPasswordBypassExists() const
	{
		return ContainsField("UserPasswordBypass");
	}
	void AMT_BootCapabilities::RemoveUserPasswordBypass()
	{
		RemoveField("UserPasswordBypass");
	}

	const bool AMT_BootCapabilities::ForcedProgressEvents() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForcedProgressEvents"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ForcedProgressEvents(const bool value)
	{
		SetOrAddField("ForcedProgressEvents", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ForcedProgressEventsExists() const
	{
		return ContainsField("ForcedProgressEvents");
	}
	void AMT_BootCapabilities::RemoveForcedProgressEvents()
	{
		RemoveField("ForcedProgressEvents");
	}

	const bool AMT_BootCapabilities::VerbosityVerbose() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("VerbosityVerbose"), ret);
		return ret;
	}
	void AMT_BootCapabilities::VerbosityVerbose(const bool value)
	{
		SetOrAddField("VerbosityVerbose", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::VerbosityVerboseExists() const
	{
		return ContainsField("VerbosityVerbose");
	}
	void AMT_BootCapabilities::RemoveVerbosityVerbose()
	{
		RemoveField("VerbosityVerbose");
	}

	const bool AMT_BootCapabilities::VerbosityQuiet() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("VerbosityQuiet"), ret);
		return ret;
	}
	void AMT_BootCapabilities::VerbosityQuiet(const bool value)
	{
		SetOrAddField("VerbosityQuiet", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::VerbosityQuietExists() const
	{
		return ContainsField("VerbosityQuiet");
	}
	void AMT_BootCapabilities::RemoveVerbosityQuiet()
	{
		RemoveField("VerbosityQuiet");
	}

	const bool AMT_BootCapabilities::ConfigurationDataReset() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ConfigurationDataReset"), ret);
		return ret;
	}
	void AMT_BootCapabilities::ConfigurationDataReset(const bool value)
	{
		SetOrAddField("ConfigurationDataReset", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::ConfigurationDataResetExists() const
	{
		return ContainsField("ConfigurationDataReset");
	}
	void AMT_BootCapabilities::RemoveConfigurationDataReset()
	{
		RemoveField("ConfigurationDataReset");
	}

	const bool AMT_BootCapabilities::BIOSSecureBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSSecureBoot"), ret);
		return ret;
	}
	void AMT_BootCapabilities::BIOSSecureBoot(const bool value)
	{
		SetOrAddField("BIOSSecureBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::BIOSSecureBootExists() const
	{
		return ContainsField("BIOSSecureBoot");
	}
	void AMT_BootCapabilities::RemoveBIOSSecureBoot()
	{
		RemoveField("BIOSSecureBoot");
	}

	const bool AMT_BootCapabilities::SecureErase() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SecureErase"), ret);
		return ret;
	}
	void AMT_BootCapabilities::SecureErase(const bool value)
	{
		SetOrAddField("SecureErase", TypeConverter::TypeToString(value));
	}
	bool AMT_BootCapabilities::SecureEraseExists() const
	{
		return ContainsField("SecureErase");
	}
	void AMT_BootCapabilities::RemoveSecureErase()
	{
		RemoveField("SecureErase");
	}

	CimBase *AMT_BootCapabilities::CreateFromCimObject(const CimObject &object)
	{
		AMT_BootCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_BootCapabilities>(object);
		}
		else
		{
			ret = new AMT_BootCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_BootCapabilities> > AMT_BootCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_BootCapabilities>(client, keys);
	}

	void AMT_BootCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_BootCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_BootCapabilities::CLASS_NAME = "AMT_BootCapabilities";
	const string AMT_BootCapabilities::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_BootCapabilities";
	const string AMT_BootCapabilities::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_BootCapabilities";
	const string AMT_BootCapabilities::CLASS_NS_PREFIX = "ABo257";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_BootCapabilities::_classMetaData;
}
}
}
}
