//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_BootSettingData.cpp
//
//  Contents:   The AMT_BootSettingData class represents configuration-related and operational parameters for the boot service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_BootSettingData.mof,  version: 15.0.0
//
//----------------------------------------------------------------------------
#include "AMT_BootSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_BootSettingData::_metadata[] = {
		{"OwningEntity", false, false, false },
		{"UseSOL", false, true, false },
		{"UseSafeMode", false, true, false },
		{"ReflashBIOS", false, true, false },
		{"BIOSSetup", false, true, false },
		{"BIOSPause", false, true, false },
		{"LockPowerButton", false, true, false },
		{"LockResetButton", false, true, false },
		{"LockKeyboard", false, true, false },
		{"LockSleepButton", false, true, false },
		{"UserPasswordBypass", false, true, false },
		{"ForcedProgressEvents", false, true, false },
		{"FirmwareVerbosity", false, true, false },
		{"ConfigurationDataReset", false, true, false },
		{"IDERBootDevice", false, true, false },
		{"UseIDER", false, true, false },
		{"EnforceSecureBoot", false, false, false },
		{"BootMediaIndex", false, true, false },
		{"SecureErase", false, true, false },
		{"PlatformErase", false, false, false },
		{"RSEPassword", false, false, false },
		{"OptionsCleared", false, false, false },
		{"BIOSLastStatus", false, false, false },
		{"WinREBootEnabled", false, false, false },
		{"UEFILocalPBABootEnabled", false, false, false },
		{"UEFIHTTPSBootEnabled", false, false, false },
		{"SecureBootControlEnabled", false, false, false },
		{"RPEEnabled", false, false, false },
		{"BootguardStatus", false, false, false },
		{"UefiBootNumberOfParams", false, false, false },
		{"UefiBootParametersArray", false, false, false },
	};
	// class fields
	const bool AMT_BootSettingData::UseSOL() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UseSOL"), ret);
		return ret;
	}
	void AMT_BootSettingData::UseSOL(const bool value)
	{
		SetOrAddField("UseSOL", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UseSOLExists() const
	{
		return ContainsField("UseSOL");
	}
	void AMT_BootSettingData::RemoveUseSOL()
	{
		RemoveField("UseSOL");
	}

	const bool AMT_BootSettingData::UseSafeMode() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UseSafeMode"), ret);
		return ret;
	}
	void AMT_BootSettingData::UseSafeMode(const bool value)
	{
		SetOrAddField("UseSafeMode", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UseSafeModeExists() const
	{
		return ContainsField("UseSafeMode");
	}
	void AMT_BootSettingData::RemoveUseSafeMode()
	{
		RemoveField("UseSafeMode");
	}

	const bool AMT_BootSettingData::ReflashBIOS() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ReflashBIOS"), ret);
		return ret;
	}
	void AMT_BootSettingData::ReflashBIOS(const bool value)
	{
		SetOrAddField("ReflashBIOS", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::ReflashBIOSExists() const
	{
		return ContainsField("ReflashBIOS");
	}
	void AMT_BootSettingData::RemoveReflashBIOS()
	{
		RemoveField("ReflashBIOS");
	}

	const bool AMT_BootSettingData::BIOSSetup() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSSetup"), ret);
		return ret;
	}
	void AMT_BootSettingData::BIOSSetup(const bool value)
	{
		SetOrAddField("BIOSSetup", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::BIOSSetupExists() const
	{
		return ContainsField("BIOSSetup");
	}
	void AMT_BootSettingData::RemoveBIOSSetup()
	{
		RemoveField("BIOSSetup");
	}

	const bool AMT_BootSettingData::BIOSPause() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BIOSPause"), ret);
		return ret;
	}
	void AMT_BootSettingData::BIOSPause(const bool value)
	{
		SetOrAddField("BIOSPause", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::BIOSPauseExists() const
	{
		return ContainsField("BIOSPause");
	}
	void AMT_BootSettingData::RemoveBIOSPause()
	{
		RemoveField("BIOSPause");
	}

	const bool AMT_BootSettingData::LockPowerButton() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LockPowerButton"), ret);
		return ret;
	}
	void AMT_BootSettingData::LockPowerButton(const bool value)
	{
		SetOrAddField("LockPowerButton", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::LockPowerButtonExists() const
	{
		return ContainsField("LockPowerButton");
	}
	void AMT_BootSettingData::RemoveLockPowerButton()
	{
		RemoveField("LockPowerButton");
	}

	const bool AMT_BootSettingData::LockResetButton() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LockResetButton"), ret);
		return ret;
	}
	void AMT_BootSettingData::LockResetButton(const bool value)
	{
		SetOrAddField("LockResetButton", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::LockResetButtonExists() const
	{
		return ContainsField("LockResetButton");
	}
	void AMT_BootSettingData::RemoveLockResetButton()
	{
		RemoveField("LockResetButton");
	}

	const bool AMT_BootSettingData::LockKeyboard() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LockKeyboard"), ret);
		return ret;
	}
	void AMT_BootSettingData::LockKeyboard(const bool value)
	{
		SetOrAddField("LockKeyboard", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::LockKeyboardExists() const
	{
		return ContainsField("LockKeyboard");
	}
	void AMT_BootSettingData::RemoveLockKeyboard()
	{
		RemoveField("LockKeyboard");
	}

	const bool AMT_BootSettingData::LockSleepButton() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("LockSleepButton"), ret);
		return ret;
	}
	void AMT_BootSettingData::LockSleepButton(const bool value)
	{
		SetOrAddField("LockSleepButton", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::LockSleepButtonExists() const
	{
		return ContainsField("LockSleepButton");
	}
	void AMT_BootSettingData::RemoveLockSleepButton()
	{
		RemoveField("LockSleepButton");
	}

	const bool AMT_BootSettingData::UserPasswordBypass() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UserPasswordBypass"), ret);
		return ret;
	}
	void AMT_BootSettingData::UserPasswordBypass(const bool value)
	{
		SetOrAddField("UserPasswordBypass", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UserPasswordBypassExists() const
	{
		return ContainsField("UserPasswordBypass");
	}
	void AMT_BootSettingData::RemoveUserPasswordBypass()
	{
		RemoveField("UserPasswordBypass");
	}

	const bool AMT_BootSettingData::ForcedProgressEvents() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ForcedProgressEvents"), ret);
		return ret;
	}
	void AMT_BootSettingData::ForcedProgressEvents(const bool value)
	{
		SetOrAddField("ForcedProgressEvents", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::ForcedProgressEventsExists() const
	{
		return ContainsField("ForcedProgressEvents");
	}
	void AMT_BootSettingData::RemoveForcedProgressEvents()
	{
		RemoveField("ForcedProgressEvents");
	}

	const unsigned char AMT_BootSettingData::FirmwareVerbosity() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("FirmwareVerbosity"), ret);
		return ret;
	}
	void AMT_BootSettingData::FirmwareVerbosity(const unsigned char &value)
	{
		SetOrAddField("FirmwareVerbosity", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::FirmwareVerbosityExists() const
	{
		return ContainsField("FirmwareVerbosity");
	}
	void AMT_BootSettingData::RemoveFirmwareVerbosity()
	{
		RemoveField("FirmwareVerbosity");
	}

	const bool AMT_BootSettingData::ConfigurationDataReset() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ConfigurationDataReset"), ret);
		return ret;
	}
	void AMT_BootSettingData::ConfigurationDataReset(const bool value)
	{
		SetOrAddField("ConfigurationDataReset", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::ConfigurationDataResetExists() const
	{
		return ContainsField("ConfigurationDataReset");
	}
	void AMT_BootSettingData::RemoveConfigurationDataReset()
	{
		RemoveField("ConfigurationDataReset");
	}

	const unsigned char AMT_BootSettingData::IDERBootDevice() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("IDERBootDevice"), ret);
		return ret;
	}
	void AMT_BootSettingData::IDERBootDevice(const unsigned char &value)
	{
		SetOrAddField("IDERBootDevice", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::IDERBootDeviceExists() const
	{
		return ContainsField("IDERBootDevice");
	}
	void AMT_BootSettingData::RemoveIDERBootDevice()
	{
		RemoveField("IDERBootDevice");
	}

	const bool AMT_BootSettingData::UseIDER() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UseIDER"), ret);
		return ret;
	}
	void AMT_BootSettingData::UseIDER(const bool value)
	{
		SetOrAddField("UseIDER", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UseIDERExists() const
	{
		return ContainsField("UseIDER");
	}
	void AMT_BootSettingData::RemoveUseIDER()
	{
		RemoveField("UseIDER");
	}

	const bool AMT_BootSettingData::EnforceSecureBoot() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("EnforceSecureBoot"), ret);
		return ret;
	}
	void AMT_BootSettingData::EnforceSecureBoot(const bool value)
	{
		SetOrAddField("EnforceSecureBoot", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::EnforceSecureBootExists() const
	{
		return ContainsField("EnforceSecureBoot");
	}
	void AMT_BootSettingData::RemoveEnforceSecureBoot()
	{
		RemoveField("EnforceSecureBoot");
	}

	const unsigned short AMT_BootSettingData::BootMediaIndex() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("BootMediaIndex"), ret);
		return ret;
	}
	void AMT_BootSettingData::BootMediaIndex(const unsigned short value)
	{
		SetOrAddField("BootMediaIndex", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::BootMediaIndexExists() const
	{
		return ContainsField("BootMediaIndex");
	}
	void AMT_BootSettingData::RemoveBootMediaIndex()
	{
		RemoveField("BootMediaIndex");
	}

	const bool AMT_BootSettingData::SecureErase() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SecureErase"), ret);
		return ret;
	}
	void AMT_BootSettingData::SecureErase(const bool value)
	{
		SetOrAddField("SecureErase", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::SecureEraseExists() const
	{
		return ContainsField("SecureErase");
	}
	void AMT_BootSettingData::RemoveSecureErase()
	{
		RemoveField("SecureErase");
	}

	const bool AMT_BootSettingData::PlatformErase() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("PlatformErase"), ret);
		return ret;
	}
	void AMT_BootSettingData::PlatformErase(const bool value)
	{
		SetOrAddField("PlatformErase", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::PlatformEraseExists() const
	{
		return ContainsField("PlatformErase");
	}
	void AMT_BootSettingData::RemovePlatformErase()
	{
		RemoveField("PlatformErase");
	}

	const string AMT_BootSettingData::RSEPassword() const
	{
		return GetField("RSEPassword")[0];
	}
	void AMT_BootSettingData::RSEPassword(const string &value)
	{
		SetOrAddField("RSEPassword", value);
	}
	bool AMT_BootSettingData::RSEPasswordExists() const
	{
		return ContainsField("RSEPassword");
	}
	void AMT_BootSettingData::RemoveRSEPassword()
	{
		RemoveField("RSEPassword");
	}

	const bool AMT_BootSettingData::OptionsCleared() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("OptionsCleared"), ret);
		return ret;
	}
	void AMT_BootSettingData::OptionsCleared(const bool value)
	{
		SetOrAddField("OptionsCleared", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::OptionsClearedExists() const
	{
		return ContainsField("OptionsCleared");
	}
	void AMT_BootSettingData::RemoveOptionsCleared()
	{
		RemoveField("OptionsCleared");
	}

	const vector<unsigned short> AMT_BootSettingData::BIOSLastStatus() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("BIOSLastStatus"), ret);
		return ret;
	}
	void AMT_BootSettingData::BIOSLastStatus(const vector<unsigned short> &value)
	{
		SetOrAddField("BIOSLastStatus", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::BIOSLastStatusExists() const
	{
		return ContainsField("BIOSLastStatus");
	}
	void AMT_BootSettingData::RemoveBIOSLastStatus()
	{
		RemoveField("BIOSLastStatus");
	}

	const bool AMT_BootSettingData::WinREBootEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("WinREBootEnabled"), ret);
		return ret;
	}
	void AMT_BootSettingData::WinREBootEnabled(const bool value)
	{
		SetOrAddField("WinREBootEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::WinREBootEnabledExists() const
	{
		return ContainsField("WinREBootEnabled");
	}
	void AMT_BootSettingData::RemoveWinREBootEnabled()
	{
		RemoveField("WinREBootEnabled");
	}

	const bool AMT_BootSettingData::UEFILocalPBABootEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UEFILocalPBABootEnabled"), ret);
		return ret;
	}
	void AMT_BootSettingData::UEFILocalPBABootEnabled(const bool value)
	{
		SetOrAddField("UEFILocalPBABootEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UEFILocalPBABootEnabledExists() const
	{
		return ContainsField("UEFILocalPBABootEnabled");
	}
	void AMT_BootSettingData::RemoveUEFILocalPBABootEnabled()
	{
		RemoveField("UEFILocalPBABootEnabled");
	}

	const bool AMT_BootSettingData::UEFIHTTPSBootEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("UEFIHTTPSBootEnabled"), ret);
		return ret;
	}
	void AMT_BootSettingData::UEFIHTTPSBootEnabled(const bool value)
	{
		SetOrAddField("UEFIHTTPSBootEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UEFIHTTPSBootEnabledExists() const
	{
		return ContainsField("UEFIHTTPSBootEnabled");
	}
	void AMT_BootSettingData::RemoveUEFIHTTPSBootEnabled()
	{
		RemoveField("UEFIHTTPSBootEnabled");
	}

	const bool AMT_BootSettingData::SecureBootControlEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SecureBootControlEnabled"), ret);
		return ret;
	}
	void AMT_BootSettingData::SecureBootControlEnabled(const bool value)
	{
		SetOrAddField("SecureBootControlEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::SecureBootControlEnabledExists() const
	{
		return ContainsField("SecureBootControlEnabled");
	}
	void AMT_BootSettingData::RemoveSecureBootControlEnabled()
	{
		RemoveField("SecureBootControlEnabled");
	}

	const bool AMT_BootSettingData::RPEEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("RPEEnabled"), ret);
		return ret;
	}
	void AMT_BootSettingData::RPEEnabled(const bool value)
	{
		SetOrAddField("RPEEnabled", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::RPEEnabledExists() const
	{
		return ContainsField("RPEEnabled");
	}
	void AMT_BootSettingData::RemoveRPEEnabled()
	{
		RemoveField("RPEEnabled");
	}

	const unsigned int AMT_BootSettingData::BootguardStatus() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("BootguardStatus"), ret);
		return ret;
	}
	void AMT_BootSettingData::BootguardStatus(const unsigned int value)
	{
		SetOrAddField("BootguardStatus", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::BootguardStatusExists() const
	{
		return ContainsField("BootguardStatus");
	}
	void AMT_BootSettingData::RemoveBootguardStatus()
	{
		RemoveField("BootguardStatus");
	}

	const unsigned int AMT_BootSettingData::UefiBootNumberOfParams() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("UefiBootNumberOfParams"), ret);
		return ret;
	}
	void AMT_BootSettingData::UefiBootNumberOfParams(const unsigned int value)
	{
		SetOrAddField("UefiBootNumberOfParams", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UefiBootNumberOfParamsExists() const
	{
		return ContainsField("UefiBootNumberOfParams");
	}
	void AMT_BootSettingData::RemoveUefiBootNumberOfParams()
	{
		RemoveField("UefiBootNumberOfParams");
	}

	const Base64 AMT_BootSettingData::UefiBootParametersArray() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("UefiBootParametersArray"), ret);
		return ret;
	}
	void AMT_BootSettingData::UefiBootParametersArray(const Base64 &value)
	{
		SetOrAddField("UefiBootParametersArray", TypeConverter::TypeToString(value));
	}
	bool AMT_BootSettingData::UefiBootParametersArrayExists() const
	{
		return ContainsField("UefiBootParametersArray");
	}
	void AMT_BootSettingData::RemoveUefiBootParametersArray()
	{
		RemoveField("UefiBootParametersArray");
	}

	CimBase *AMT_BootSettingData::CreateFromCimObject(const CimObject &object)
	{
		AMT_BootSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_BootSettingData>(object);
		}
		else
		{
			ret = new AMT_BootSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_BootSettingData> > AMT_BootSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_BootSettingData>(client, keys);
	}

	void AMT_BootSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_BootSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_BootSettingData::CLASS_NAME = "AMT_BootSettingData";
	const string AMT_BootSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_BootSettingData";
	const string AMT_BootSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_BootSettingData";
	const string AMT_BootSettingData::CLASS_NS_PREFIX = "ABo303";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_BootSettingData::_classMetaData;
}
}
}
}
