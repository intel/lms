//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_BootSettingData.h
//
//  Contents:   The AMT_BootSettingData class represents configuration-related and operational parameters for the boot service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_BootSettingData.mof,  version: 15.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_BOOTSETTINGDATA_H
#define AMT_BOOTSETTINGDATA_H 1
#include "CIM_BootSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The AMT_BootSettingData class represents configuration-related and operational parameters for the boot service in the Intel(R) AMT.
	class CIMFRAMEWORK_API AMT_BootSettingData  : public CIM_BootSettingData
	{
	public:

		//Default constructor
		AMT_BootSettingData()
			: CIM_BootSettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_BootSettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 31);
			}
		}

		//constructor which receives WSMan client
		AMT_BootSettingData(ICimWsmanClient *client)
			: CIM_BootSettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_BootSettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 31);
			}
		}

		//Destructor
		virtual ~AMT_BootSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_BootSettingData keys
		class CimKeys : public CIM_BootSettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, When True, Serial over LAN is used on the next boot cycle.
		const bool UseSOL() const;

		// Required, When True, Serial over LAN is used on the next boot cycle.
		void UseSOL(const bool value); 

		// Is true if the field UseSOL exists in the current object, otherwise is false.
		bool UseSOLExists() const;

		// Remove UseSOL field.
		void RemoveUseSOL(); 

		// Required, When a Hard-drive boot source is chosen (using CIM_BootConfigSetting) and this property is set to True, the Intel(R) AMT firmware will boot in safe mode.
		const bool UseSafeMode() const;

		// Required, When a Hard-drive boot source is chosen (using CIM_BootConfigSetting) and this property is set to True, the Intel(R) AMT firmware will boot in safe mode.
		void UseSafeMode(const bool value); 

		// Is true if the field UseSafeMode exists in the current object, otherwise is false.
		bool UseSafeModeExists() const;

		// Remove UseSafeMode field.
		void RemoveUseSafeMode(); 

		// Required, When True, the Intel(R) AMT firmware reflashes the BIOS on the next boot cycle.
		const bool ReflashBIOS() const;

		// Required, When True, the Intel(R) AMT firmware reflashes the BIOS on the next boot cycle.
		void ReflashBIOS(const bool value); 

		// Is true if the field ReflashBIOS exists in the current object, otherwise is false.
		bool ReflashBIOSExists() const;

		// Remove ReflashBIOS field.
		void RemoveReflashBIOS(); 

		// Required, When True, the Intel(R) AMT firmware enters the CMOS Setup screen on the next boot cycle.
		const bool BIOSSetup() const;

		// Required, When True, the Intel(R) AMT firmware enters the CMOS Setup screen on the next boot cycle.
		void BIOSSetup(const bool value); 

		// Is true if the field BIOSSetup exists in the current object, otherwise is false.
		bool BIOSSetupExists() const;

		// Remove BIOSSetup field.
		void RemoveBIOSSetup(); 

		// Required, When True, the BIOS pauses for user input on the next boot cycle.
		const bool BIOSPause() const;

		// Required, When True, the BIOS pauses for user input on the next boot cycle.
		void BIOSPause(const bool value); 

		// Is true if the field BIOSPause exists in the current object, otherwise is false.
		bool BIOSPauseExists() const;

		// Remove BIOSPause field.
		void RemoveBIOSPause(); 

		// Required, When True, the Intel(R) AMT firmware disables the power button operation for the system, normally until the next boot cycle.
		const bool LockPowerButton() const;

		// Required, When True, the Intel(R) AMT firmware disables the power button operation for the system, normally until the next boot cycle.
		void LockPowerButton(const bool value); 

		// Is true if the field LockPowerButton exists in the current object, otherwise is false.
		bool LockPowerButtonExists() const;

		// Remove LockPowerButton field.
		void RemoveLockPowerButton(); 

		// Required, When True, the Intel(R) AMT firmware disables the reset button operation for the system, normally until the next boot cycle.
		const bool LockResetButton() const;

		// Required, When True, the Intel(R) AMT firmware disables the reset button operation for the system, normally until the next boot cycle.
		void LockResetButton(const bool value); 

		// Is true if the field LockResetButton exists in the current object, otherwise is false.
		bool LockResetButtonExists() const;

		// Remove LockResetButton field.
		void RemoveLockResetButton(); 

		// Required, When True, the Intel(R) AMT firmware disallows keyboard activity during its boot process.
		const bool LockKeyboard() const;

		// Required, When True, the Intel(R) AMT firmware disallows keyboard activity during its boot process.
		void LockKeyboard(const bool value); 

		// Is true if the field LockKeyboard exists in the current object, otherwise is false.
		bool LockKeyboardExists() const;

		// Remove LockKeyboard field.
		void RemoveLockKeyboard(); 

		// Required, When True, the Intel(R) AMT firmware disables the sleep button operation for the system, normally until the next boot cycle.
		const bool LockSleepButton() const;

		// Required, When True, the Intel(R) AMT firmware disables the sleep button operation for the system, normally until the next boot cycle.
		void LockSleepButton(const bool value); 

		// Is true if the field LockSleepButton exists in the current object, otherwise is false.
		bool LockSleepButtonExists() const;

		// Remove LockSleepButton field.
		void RemoveLockSleepButton(); 

		// Required, When True, the Intel(R) AMT firmware boots the system and bypasses any user or boot password that might be set in the system.
		const bool UserPasswordBypass() const;

		// Required, When True, the Intel(R) AMT firmware boots the system and bypasses any user or boot password that might be set in the system.
		void UserPasswordBypass(const bool value); 

		// Is true if the field UserPasswordBypass exists in the current object, otherwise is false.
		bool UserPasswordBypassExists() const;

		// Remove UserPasswordBypass field.
		void RemoveUserPasswordBypass(); 

		// Required, When True, the Intel(R) AMT firmware transmits all progress PET events to the alert-sending device.
		const bool ForcedProgressEvents() const;

		// Required, When True, the Intel(R) AMT firmware transmits all progress PET events to the alert-sending device.
		void ForcedProgressEvents(const bool value); 

		// Is true if the field ForcedProgressEvents exists in the current object, otherwise is false.
		bool ForcedProgressEventsExists() const;

		// Remove ForcedProgressEvents field.
		void RemoveForcedProgressEvents(); 

		// Required, When set to a non-zero value, controls the amount of information the managed system writes to its local display.
		const unsigned char FirmwareVerbosity() const;

		// Required, When set to a non-zero value, controls the amount of information the managed system writes to its local display.
		void FirmwareVerbosity(const unsigned char &value); 

		// Is true if the field FirmwareVerbosity exists in the current object, otherwise is false.
		bool FirmwareVerbosityExists() const;

		// Remove FirmwareVerbosity field.
		void RemoveFirmwareVerbosity(); 

		// Required, When True, the Intel(R) AMT firmware resets its non-volatile configuration data to the managed system's Setup defaults prior to booting the system.
		const bool ConfigurationDataReset() const;

		// Required, When True, the Intel(R) AMT firmware resets its non-volatile configuration data to the managed system's Setup defaults prior to booting the system.
		void ConfigurationDataReset(const bool value); 

		// Is true if the field ConfigurationDataReset exists in the current object, otherwise is false.
		bool ConfigurationDataResetExists() const;

		// Remove ConfigurationDataReset field.
		void RemoveConfigurationDataReset(); 

		// Required, Specifies the device to use when UseIder is set. 0 - Floppy Boot, 1- CD Boot.
		const unsigned char IDERBootDevice() const;

		// Required, Specifies the device to use when UseIder is set. 0 - Floppy Boot, 1- CD Boot.
		void IDERBootDevice(const unsigned char &value); 

		// Is true if the field IDERBootDevice exists in the current object, otherwise is false.
		bool IDERBootDeviceExists() const;

		// Remove IDERBootDevice field.
		void RemoveIDERBootDevice(); 

		// Required, When True, IDER is used on the next boot cycle.
		const bool UseIDER() const;

		// Required, When True, IDER is used on the next boot cycle.
		void UseIDER(const bool value); 

		// Is true if the field UseIDER exists in the current object, otherwise is false.
		bool UseIDERExists() const;

		// Remove UseIDER field.
		void RemoveUseIDER(); 

		// Optional, When True, Secure boot over IDER is enforced on the next boot cycle, if IDER boot is used.
		const bool EnforceSecureBoot() const;

		// Optional, When True, Secure boot over IDER is enforced on the next boot cycle, if IDER boot is used.
		void EnforceSecureBoot(const bool value); 

		// Is true if the field EnforceSecureBoot exists in the current object, otherwise is false.
		bool EnforceSecureBootExists() const;

		// Remove EnforceSecureBoot field.
		void RemoveEnforceSecureBoot(); 

		// Required, This property identifies the boot-media index for the managed client (when a boot source is set using the CIM_BootConfigSetting.ChangeBootOrder method). For Hard-Drive or CD/DVD boot - when the parameter value is 0, the default boot-media is booted. When the parameter value is 1, the primary boot-media is booted; when the value is 2, the secondary boot-media is booted; and so on. For PXE or diagnostics boot this property must be 0.
		const unsigned short BootMediaIndex() const;

		// Required, This property identifies the boot-media index for the managed client (when a boot source is set using the CIM_BootConfigSetting.ChangeBootOrder method). For Hard-Drive or CD/DVD boot - when the parameter value is 0, the default boot-media is booted. When the parameter value is 1, the primary boot-media is booted; when the value is 2, the secondary boot-media is booted; and so on. For PXE or diagnostics boot this property must be 0.
		void BootMediaIndex(const unsigned short value); 

		// Is true if the field BootMediaIndex exists in the current object, otherwise is false.
		bool BootMediaIndexExists() const;

		// Remove BootMediaIndex field.
		void RemoveBootMediaIndex(); 

		// Required, When True, the BIOS performs secure erase operation.
		const bool SecureErase() const;

		// Required, When True, the BIOS performs secure erase operation.
		void SecureErase(const bool value); 

		// Is true if the field SecureErase exists in the current object, otherwise is false.
		bool SecureEraseExists() const;

		// Remove SecureErase field.
		void RemoveSecureErase(); 

		// Optional, When True, Remote Platform Erase will be performed by BIOS on the next boot cycle.
		const bool PlatformErase() const;

		// Optional, When True, Remote Platform Erase will be performed by BIOS on the next boot cycle.
		void PlatformErase(const bool value); 

		// Is true if the field PlatformErase exists in the current object, otherwise is false.
		bool PlatformEraseExists() const;

		// Remove PlatformErase field.
		void RemovePlatformErase(); 

		// Optional, SSD password for Remote Secure Erase operation. This is a write-only field, an empty string is returned when instance is read. When writing, an empty string or lack of field will be ignored. The password length is limited to 32 ASCII charachters. 
		const string RSEPassword() const;

		// Optional, SSD password for Remote Secure Erase operation. This is a write-only field, an empty string is returned when instance is read. When writing, an empty string or lack of field will be ignored. The password length is limited to 32 ASCII charachters. 
		void RSEPassword(const string &value); 

		// Is true if the field RSEPassword exists in the current object, otherwise is false.
		bool RSEPasswordExists() const;

		// Remove RSEPassword field.
		void RemoveRSEPassword(); 

		// Optional, Indicates whether the boot options have been cleared by BIOS or not. This property is read only.
		const bool OptionsCleared() const;

		// Optional, Indicates whether the boot options have been cleared by BIOS or not. This property is read only.
		void OptionsCleared(const bool value); 

		// Is true if the field OptionsCleared exists in the current object, otherwise is false.
		bool OptionsClearedExists() const;

		// Remove OptionsCleared field.
		void RemoveOptionsCleared(); 

		// Optional, Last boot status reported by BIOS. 1st word (16 bit) contains general BIOS status (0 - Success, 1 - In Progress, 2 - Not Updated, 0xFFFF - Failed). 2nd word contains detailed error status (0 - Success/In Progress, 1 - General Drive Failure, 2 - Drive Password/Authentication Failure, 3 - Feature is not supported). This property is read only.
		const vector<unsigned short> BIOSLastStatus() const;

		// Optional, Last boot status reported by BIOS. 1st word (16 bit) contains general BIOS status (0 - Success, 1 - In Progress, 2 - Not Updated, 0xFFFF - Failed). 2nd word contains detailed error status (0 - Success/In Progress, 1 - General Drive Failure, 2 - Drive Password/Authentication Failure, 3 - Feature is not supported). This property is read only.
		void BIOSLastStatus(const vector<unsigned short> &value); 

		// Is true if the field BIOSLastStatus exists in the current object, otherwise is false.
		bool BIOSLastStatusExists() const;

		// Remove BIOSLastStatus field.
		void RemoveBIOSLastStatus(); 

		// Optional, Reflects the enabled state of boot to OCR WinRE recovery boot option in the BIOS options
		const bool WinREBootEnabled() const;

		// Optional, Reflects the enabled state of boot to OCR WinRE recovery boot option in the BIOS options
		void WinREBootEnabled(const bool value); 

		// Is true if the field WinREBootEnabled exists in the current object, otherwise is false.
		bool WinREBootEnabledExists() const;

		// Remove WinREBootEnabled field.
		void RemoveWinREBootEnabled(); 

		// Optional, Reflects the enabled state of boot to OCR local Pre-Boot Application (PBA) recovery boot option in the BIOS options
		const bool UEFILocalPBABootEnabled() const;

		// Optional, Reflects the enabled state of boot to OCR local Pre-Boot Application (PBA) recovery boot option in the BIOS options
		void UEFILocalPBABootEnabled(const bool value); 

		// Is true if the field UEFILocalPBABootEnabled exists in the current object, otherwise is false.
		bool UEFILocalPBABootEnabledExists() const;

		// Remove UEFILocalPBABootEnabled field.
		void RemoveUEFILocalPBABootEnabled(); 

		// Optional, Reflects the enabled state of boot to OCR HTTPS server recovery boot option in the BIOS options
		const bool UEFIHTTPSBootEnabled() const;

		// Optional, Reflects the enabled state of boot to OCR HTTPS server recovery boot option in the BIOS options
		void UEFIHTTPSBootEnabled(const bool value); 

		// Is true if the field UEFIHTTPSBootEnabled exists in the current object, otherwise is false.
		bool UEFIHTTPSBootEnabledExists() const;

		// Remove UEFIHTTPSBootEnabled field.
		void RemoveUEFIHTTPSBootEnabled(); 

		// Optional, Reflects the enabled state of allowing Intel(R) AMT firmware to disable UEFI secure boot for OCR boot options
		const bool SecureBootControlEnabled() const;

		// Optional, Reflects the enabled state of allowing Intel(R) AMT firmware to disable UEFI secure boot for OCR boot options
		void SecureBootControlEnabled(const bool value); 

		// Is true if the field SecureBootControlEnabled exists in the current object, otherwise is false.
		bool SecureBootControlEnabledExists() const;

		// Remove SecureBootControlEnabled field.
		void RemoveSecureBootControlEnabled(); 

		// Optional, Reflects the enabled state of Remote Platform Erase from BIOS control POV, the WSMAN enabled state is in CIM_BootService WSMAN class
		const bool RPEEnabled() const;

		// Optional, Reflects the enabled state of Remote Platform Erase from BIOS control POV, the WSMAN enabled state is in CIM_BootService WSMAN class
		void RPEEnabled(const bool value); 

		// Is true if the field RPEEnabled exists in the current object, otherwise is false.
		bool RPEEnabledExists() const;

		// Remove RPEEnabled field.
		void RemoveRPEEnabled(); 

		// Optional, Bitmap that describes the status of Intel(R) Boot Guard (if for some reason AMT fails to get the Boot Guard status AMT shall return 0xffffffff)
		const unsigned int BootguardStatus() const;

		// Optional, Bitmap that describes the status of Intel(R) Boot Guard (if for some reason AMT fails to get the Boot Guard status AMT shall return 0xffffffff)
		void BootguardStatus(const unsigned int value); 

		// Is true if the field BootguardStatus exists in the current object, otherwise is false.
		bool BootguardStatusExists() const;

		// Remove BootguardStatus field.
		void RemoveBootguardStatus(); 

		// Optional, Reflects the number of parameters in the UefiBootParametersArray parameter array
		const unsigned int UefiBootNumberOfParams() const;

		// Optional, Reflects the number of parameters in the UefiBootParametersArray parameter array
		void UefiBootNumberOfParams(const unsigned int value); 

		// Is true if the field UefiBootNumberOfParams exists in the current object, otherwise is false.
		bool UefiBootNumberOfParamsExists() const;

		// Remove UefiBootNumberOfParams field.
		void RemoveUefiBootNumberOfParams(); 

		// Optional, The UEFI boot option parameters blob in Base64 encoding format, max size of data after Base64 decoding is 1024 bytes(Base64 encoding increases the size of the data by a factor of 1.333, hence the size of UefiBootParametersArray should be at least 1365 bytes)
		const Base64 UefiBootParametersArray() const;

		// Optional, The UEFI boot option parameters blob in Base64 encoding format, max size of data after Base64 decoding is 1024 bytes(Base64 encoding increases the size of the data by a factor of 1.333, hence the size of UefiBootParametersArray should be at least 1365 bytes)
		void UefiBootParametersArray(const Base64 &value); 

		// Is true if the field UefiBootParametersArray exists in the current object, otherwise is false.
		bool UefiBootParametersArrayExists() const;

		// Remove UefiBootParametersArray field.
		void RemoveUefiBootParametersArray(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_BootSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_BootSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_BootSettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_BootSettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 31);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_BootSettingData(const CimObject &object)
			: CIM_BootSettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_BootSettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 31);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_BootSettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 31);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
		static const CimFieldAttribute _metadata[];
		static const string CLASS_NAME;
		static const string CLASS_URI;
		static const string CLASS_NS;
		static const string CLASS_NS_PREFIX;
		static vector<CimFieldAttribute> _classMetaData;
	};

} // close namespace Typed
} // close namespace Cim
} // close namespace Manageability
} // close namespace Intel
#endif // AMT_BOOTSETTINGDATA_H
