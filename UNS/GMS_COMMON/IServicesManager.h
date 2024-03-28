/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: IServicesManager.h

--*/

#ifndef _I_SERVICES_NANAGER_H_
#define _I_SERVICES_NANAGER_H_

/*
	this is an interface for a class that should manage ace services
*/

#include "ace/Stream.h"

class IServicesManager
{
public:
	virtual ~IServicesManager(){} 

	virtual bool StartAceService(const ACE_TString &serviceName) = 0;
	virtual bool StopAceService(const ACE_TString &serviceName) = 0;
	virtual bool SuspendAceService(const ACE_TString &serviceName) = 0;
	virtual bool ResumeAceService(const ACE_TString &serviceName) = 0;
};

#endif // _I_SERVICES_NANAGER_H_
