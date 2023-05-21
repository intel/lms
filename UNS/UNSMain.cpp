/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2004-2006, 2009-2023 Intel Corporation
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
	UNS_DEBUG(L"Starting LMS Service\n");

#ifdef _DEBUG
	ACE::debug(true);
#endif // _DEBUG

#ifdef WIN32
	 SetDllDirectory(L"");
#endif //WIN32
	 try
	 {
		 *gmsSrv = GmsService::getService();
		 if (*gmsSrv == NULL)
			 return -1;
		 return (*gmsSrv)->activate();
	 }
	 catch (const std::exception& exc)
	 {
		 UNS_DEBUG(L"theService::instance failed with %C\n", exc.what());
		 return -1;
	 }
}

#ifndef WIN32
void sig_term(int signo)
{
	if (signo != SIGTERM)
		return;

	GMSExternalLogger::instance().ServiceStopped();
	GmsService* gmsSrv = GmsService::getService();
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
#else
#include <tchar.h>
#include "AMT_COM_Interface_exp.h"

extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
	LPTSTR lpCmdLine, int nShowCmd)
{
	if (_wcsicmp(lpCmdLine, L"") != 0)
	{
		if ((_wcsicmp(lpCmdLine, L"console") == 0))
		{
			ACEInitializer Initializer;
			GmsService* GMSsrv;
			if (RunUNSService(&GMSsrv))
				exit(EXIT_FAILURE);
			Sleep(120000);
			getchar();
			if (GMSsrv != NULL)
			{
				GMSsrv->stop();
				while (!GMSsrv->GetStopped()) {}
				GMSsrv->wait();
			}
			return 0;
		}
	}
	return RunAMT_COM_Interface(nShowCmd);
}
#endif // !WIN32
