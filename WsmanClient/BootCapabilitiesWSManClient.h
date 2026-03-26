/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: BootCapabilitiesWSManClient.h

--*/

// WS-Man client for retrieving AMT boot capability flags.

#ifndef _BOOT_CAPABILITIES_WSMAN_CLIENT_H
#define _BOOT_CAPABILITIES_WSMAN_CLIENT_H

#include "BaseWSManClient.h"

struct BootCapabilitiesWSMan
{
	bool IDER = false;
	bool SOL = false;
	bool BIOSReflash = false;
	bool BIOSSetup = false;
	bool BIOSPause = false;
	bool ForcePXEBoot = false;
	bool ForceHardDriveBoot = false;
	bool ForceDiagnosticBoot = false;
	bool ForceCDorDVDBoot = false;
	bool VerbosityScreenBlank = false;
	bool PowerButtonLock = false;
	bool ResetButtonLock = false;
	bool KeyboardLock = false;
	bool SleepButtonLock = false;
	bool UserPasswordBypass = false;
	bool ForcedProgressEvents = false;
	bool VerbosityVerbose = false;
	bool VerbosityQuiet = false;
	bool ConfigurationDataReset = false;
	bool BIOSSecureBoot = false;
	bool SecureErase = false;
	bool ForceWinREBoot = false;
	bool ForceUEFIPBABoot = false;
	bool ForceUEFIHTTPSBoot = false;
	bool AMTSecureBootControl = false;
	bool UEFIWiFiCoExistenceAndProfileShare = false;
	unsigned int PlatformErase = 0;
};

class BootCapabilitiesWSManClient : public BaseWSManClient
{
public:
	BootCapabilitiesWSManClient(unsigned int port);
	virtual ~BootCapabilitiesWSManClient();
	// Reads current AMT boot capability settings.
	bool GetBootCapabilities(BootCapabilitiesWSMan& caps);
private:
};

#endif //_BOOT_CAPABILITIES_WSMAN_CLIENT_H
