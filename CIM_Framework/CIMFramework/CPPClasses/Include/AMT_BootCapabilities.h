//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_BootCapabilities.h
//
//  Contents:   Boot options that the Intel(R) AMT device supports.
//
//              This file was automatically generated from AMT_BootCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_BOOTCAPABILITIES_H
#define AMT_BOOTCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Boot options that the Intel(R) AMT device supports.
	class CIMFRAMEWORK_API AMT_BootCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_BootCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 22);
			}
		}

		//constructor which receives WSMan client
		AMT_BootCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 22);
			}
		}

		//Destructor
		virtual ~AMT_BootCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_BootCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates whether Intel(R) AMT device supports 'IDE Redirection'
		const bool IDER() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'IDE Redirection'
		void IDER(const bool value); 

		// Is true if the field IDER exists in the current object, otherwise is false.
		bool IDERExists() const;

		// Remove IDER field.
		void RemoveIDER(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Serial Over Lan'
		const bool SOL() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Serial Over Lan'
		void SOL(const bool value); 

		// Is true if the field SOL exists in the current object, otherwise is false.
		bool SOLExists() const;

		// Remove SOL field.
		void RemoveSOL(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Reflash'
		const bool BIOSReflash() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Reflash'
		void BIOSReflash(const bool value); 

		// Is true if the field BIOSReflash exists in the current object, otherwise is false.
		bool BIOSReflashExists() const;

		// Remove BIOSReflash field.
		void RemoveBIOSReflash(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Setup'
		const bool BIOSSetup() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Setup'
		void BIOSSetup(const bool value); 

		// Is true if the field BIOSSetup exists in the current object, otherwise is false.
		bool BIOSSetupExists() const;

		// Remove BIOSSetup field.
		void RemoveBIOSSetup(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Pause'
		const bool BIOSPause() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Pause'
		void BIOSPause(const bool value); 

		// Is true if the field BIOSPause exists in the current object, otherwise is false.
		bool BIOSPauseExists() const;

		// Remove BIOSPause field.
		void RemoveBIOSPause(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Force PXE Boot'
		const bool ForcePXEBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Force PXE Boot'
		void ForcePXEBoot(const bool value); 

		// Is true if the field ForcePXEBoot exists in the current object, otherwise is false.
		bool ForcePXEBootExists() const;

		// Remove ForcePXEBoot field.
		void RemoveForcePXEBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Hard Drive Boot'
		const bool ForceHardDriveBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Hard Drive Boot'
		void ForceHardDriveBoot(const bool value); 

		// Is true if the field ForceHardDriveBoot exists in the current object, otherwise is false.
		bool ForceHardDriveBootExists() const;

		// Remove ForceHardDriveBoot field.
		void RemoveForceHardDriveBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Hard Drive Safe Mode Boot'
		const bool ForceHardDriveSafeModeBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Hard Drive Safe Mode Boot'
		void ForceHardDriveSafeModeBoot(const bool value); 

		// Is true if the field ForceHardDriveSafeModeBoot exists in the current object, otherwise is false.
		bool ForceHardDriveSafeModeBootExists() const;

		// Remove ForceHardDriveSafeModeBoot field.
		void RemoveForceHardDriveSafeModeBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Diagnostic Boot'
		const bool ForceDiagnosticBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Force Diagnostic Boot'
		void ForceDiagnosticBoot(const bool value); 

		// Is true if the field ForceDiagnosticBoot exists in the current object, otherwise is false.
		bool ForceDiagnosticBootExists() const;

		// Remove ForceDiagnosticBoot field.
		void RemoveForceDiagnosticBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Force CD or DVD Boot'
		const bool ForceCDorDVDBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Force CD or DVD Boot'
		void ForceCDorDVDBoot(const bool value); 

		// Is true if the field ForceCDorDVDBoot exists in the current object, otherwise is false.
		bool ForceCDorDVDBootExists() const;

		// Remove ForceCDorDVDBoot field.
		void RemoveForceCDorDVDBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity Screen Blank'
		const bool VerbosityScreenBlank() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity Screen Blank'
		void VerbosityScreenBlank(const bool value); 

		// Is true if the field VerbosityScreenBlank exists in the current object, otherwise is false.
		bool VerbosityScreenBlankExists() const;

		// Remove VerbosityScreenBlank field.
		void RemoveVerbosityScreenBlank(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Power Button Lock'
		const bool PowerButtonLock() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Power Button Lock'
		void PowerButtonLock(const bool value); 

		// Is true if the field PowerButtonLock exists in the current object, otherwise is false.
		bool PowerButtonLockExists() const;

		// Remove PowerButtonLock field.
		void RemovePowerButtonLock(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Reset Button Lock'
		const bool ResetButtonLock() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Reset Button Lock'
		void ResetButtonLock(const bool value); 

		// Is true if the field ResetButtonLock exists in the current object, otherwise is false.
		bool ResetButtonLockExists() const;

		// Remove ResetButtonLock field.
		void RemoveResetButtonLock(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Keyboard Lock'
		const bool KeyboardLock() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Keyboard Lock'
		void KeyboardLock(const bool value); 

		// Is true if the field KeyboardLock exists in the current object, otherwise is false.
		bool KeyboardLockExists() const;

		// Remove KeyboardLock field.
		void RemoveKeyboardLock(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Sleep Button Lock'
		const bool SleepButtonLock() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Sleep Button Lock'
		void SleepButtonLock(const bool value); 

		// Is true if the field SleepButtonLock exists in the current object, otherwise is false.
		bool SleepButtonLockExists() const;

		// Remove SleepButtonLock field.
		void RemoveSleepButtonLock(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'User Password Bypass'
		const bool UserPasswordBypass() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'User Password Bypass'
		void UserPasswordBypass(const bool value); 

		// Is true if the field UserPasswordBypass exists in the current object, otherwise is false.
		bool UserPasswordBypassExists() const;

		// Remove UserPasswordBypass field.
		void RemoveUserPasswordBypass(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Forced Progress Events'
		const bool ForcedProgressEvents() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Forced Progress Events'
		void ForcedProgressEvents(const bool value); 

		// Is true if the field ForcedProgressEvents exists in the current object, otherwise is false.
		bool ForcedProgressEventsExists() const;

		// Remove ForcedProgressEvents field.
		void RemoveForcedProgressEvents(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity/Verbose'
		const bool VerbosityVerbose() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity/Verbose'
		void VerbosityVerbose(const bool value); 

		// Is true if the field VerbosityVerbose exists in the current object, otherwise is false.
		bool VerbosityVerboseExists() const;

		// Remove VerbosityVerbose field.
		void RemoveVerbosityVerbose(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity/Quiet'
		const bool VerbosityQuiet() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Verbosity/Quiet'
		void VerbosityQuiet(const bool value); 

		// Is true if the field VerbosityQuiet exists in the current object, otherwise is false.
		bool VerbosityQuietExists() const;

		// Remove VerbosityQuiet field.
		void RemoveVerbosityQuiet(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Configuration Data Reset'
		const bool ConfigurationDataReset() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Configuration Data Reset'
		void ConfigurationDataReset(const bool value); 

		// Is true if the field ConfigurationDataReset exists in the current object, otherwise is false.
		bool ConfigurationDataResetExists() const;

		// Remove ConfigurationDataReset field.
		void RemoveConfigurationDataReset(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Secure Boot'
		const bool BIOSSecureBoot() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'BIOS Secure Boot'
		void BIOSSecureBoot(const bool value); 

		// Is true if the field BIOSSecureBoot exists in the current object, otherwise is false.
		bool BIOSSecureBootExists() const;

		// Remove BIOSSecureBoot field.
		void RemoveBIOSSecureBoot(); 

		// Optional, Indicates whether Intel(R) AMT device supports 'Secure Erase'
		const bool SecureErase() const;

		// Optional, Indicates whether Intel(R) AMT device supports 'Secure Erase'
		void SecureErase(const bool value); 

		// Is true if the field SecureErase exists in the current object, otherwise is false.
		bool SecureEraseExists() const;

		// Remove SecureErase field.
		void RemoveSecureErase(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_BootCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_BootCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 22);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_BootCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 22);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 22);
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
#endif // AMT_BOOTCAPABILITIES_H
