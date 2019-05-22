/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2004-2006, 2009-2018 Intel Corporation
 */
/*++

@file: UNSMain.cpp

--*/

//----------------------------------------------------------------------------
//
//  Contents:   Defines the entry point for the Local Management Service.
//
//----------------------------------------------------------------------------

#include <stdlib.h>
#include "global.h"
#include "GmsService.h"
#include "GMSExternalLogger.h"

int RunUNSService(GmsService** gmsSrv)
{
	UNS_DEBUG(L"Starting LMS Service",L"\n");

#ifdef WIN32
	 SetDllDirectory(L"");
#endif //WIN32

	*gmsSrv = theService::instance();
	if (*gmsSrv == NULL)
		return -1;
	return (*gmsSrv)->activate();
}

#ifndef WIN32
void sig_term(int signo)
{
	if (signo != SIGTERM)
		return;

	GMSExternalLogger::instance().ServiceStopped();
	GmsService* gmsSrv = theService::instance();
	if (gmsSrv)
		gmsSrv->stop();
}

int main(void)
{
	ACEInitializer Initializer;
	GmsService* GMSsrv = NULL;

	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGPIPE, &sa, 0) == -1)
		exit(EXIT_FAILURE);
	sa.sa_handler = sig_term;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGTERM, &sa, 0) == -1)
		exit(EXIT_FAILURE);
	if (RunUNSService(&GMSsrv))
		exit(EXIT_FAILURE);
	if (GMSsrv)
		GMSsrv->wait();
	exit(EXIT_SUCCESS);
}
#endif // !WIN32
