/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2004-2011, 2013-2018 Intel Corporation
 */
//----------------------------------------------------------------------------
//
//  File:       WMIUtils.h 
//
//----------------------------------------------------------------------------
#ifndef WMI_UTILS_LMS_H
#define WMI_UTILS_LMS_H


#include <windows.h>
#include <stdio.h>
#include <string>

typedef struct _LOCAL_AGENT_PARAMS
{ 
	std::string	OneTimePassword;
	std::string	DnsSuffix;
	bool			Verbose;
    bool            Activate;
	bool			EnableIPv6;
}LOCAL_AGENT_PARAMS;

#endif