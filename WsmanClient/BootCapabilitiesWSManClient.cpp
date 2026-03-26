/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: BootCapabilitiesWSManClient.cpp

--*/

// Implements retrieval of AMT boot capability flags through WS-Man typed CIM APIs.

#include <memory>
#include <vector>
#include "BootCapabilitiesWSManClient.h"
#include "AMT_BootCapabilities.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

BootCapabilitiesWSManClient::BootCapabilitiesWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

BootCapabilitiesWSManClient::~BootCapabilitiesWSManClient()
{
}

bool BootCapabilitiesWSManClient::GetBootCapabilities(BootCapabilitiesWSMan& caps)
{
	try
	{
		// Query the singleton boot capability object and copy available properties.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_BootCapabilities>> results =
			Intel::Manageability::Cim::Typed::AMT_BootCapabilities::Enumerate(m_client.get());
		if (results.empty())
			return false;

		auto& bc = *results[0];
		if (bc.IDERExists()) caps.IDER = bc.IDER();
		if (bc.SOLExists()) caps.SOL = bc.SOL();
		if (bc.BIOSReflashExists()) caps.BIOSReflash = bc.BIOSReflash();
		if (bc.BIOSSetupExists()) caps.BIOSSetup = bc.BIOSSetup();
		if (bc.BIOSPauseExists()) caps.BIOSPause = bc.BIOSPause();
		if (bc.ForcePXEBootExists()) caps.ForcePXEBoot = bc.ForcePXEBoot();
		if (bc.ForceHardDriveBootExists()) caps.ForceHardDriveBoot = bc.ForceHardDriveBoot();
		if (bc.ForceDiagnosticBootExists()) caps.ForceDiagnosticBoot = bc.ForceDiagnosticBoot();
		if (bc.ForceCDorDVDBootExists()) caps.ForceCDorDVDBoot = bc.ForceCDorDVDBoot();
		if (bc.VerbosityScreenBlankExists()) caps.VerbosityScreenBlank = bc.VerbosityScreenBlank();
		if (bc.PowerButtonLockExists()) caps.PowerButtonLock = bc.PowerButtonLock();
		if (bc.ResetButtonLockExists()) caps.ResetButtonLock = bc.ResetButtonLock();
		if (bc.KeyboardLockExists()) caps.KeyboardLock = bc.KeyboardLock();
		if (bc.SleepButtonLockExists()) caps.SleepButtonLock = bc.SleepButtonLock();
		if (bc.UserPasswordBypassExists()) caps.UserPasswordBypass = bc.UserPasswordBypass();
		if (bc.ForcedProgressEventsExists()) caps.ForcedProgressEvents = bc.ForcedProgressEvents();
		if (bc.VerbosityVerboseExists()) caps.VerbosityVerbose = bc.VerbosityVerbose();
		if (bc.VerbosityQuietExists()) caps.VerbosityQuiet = bc.VerbosityQuiet();
		if (bc.ConfigurationDataResetExists()) caps.ConfigurationDataReset = bc.ConfigurationDataReset();
		if (bc.BIOSSecureBootExists()) caps.BIOSSecureBoot = bc.BIOSSecureBoot();
		if (bc.SecureEraseExists()) caps.SecureErase = bc.SecureErase();
		if (bc.ForceWinREBootExists()) caps.ForceWinREBoot = bc.ForceWinREBoot();
		if (bc.ForceUEFIPBABootExists()) caps.ForceUEFIPBABoot = bc.ForceUEFIPBABoot();
		if (bc.ForceUEFIHTTPSBootExists()) caps.ForceUEFIHTTPSBoot = bc.ForceUEFIHTTPSBoot();
		if (bc.AMTSecureBootControlExists()) caps.AMTSecureBootControl = bc.AMTSecureBootControl();
		if (bc.UEFIWiFiCoExistenceAndProfileShareExists()) caps.UEFIWiFiCoExistenceAndProfileShare = bc.UEFIWiFiCoExistenceAndProfileShare();
		if (bc.PlatformEraseExists()) caps.PlatformErase = bc.PlatformErase();
	}
	CATCH_exception_return("BootCapabilitiesWSManClient::GetBootCapabilities")

	return true;
}
