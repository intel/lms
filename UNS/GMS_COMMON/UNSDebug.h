/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: UNSDebug.h

--*/

#ifndef __UNSDEBUG_H
#define __UNSDEBUG_H

#ifndef UNSDEBUG_NO_DLL
#include "GMSCommonDllExport.h"
#else
#define GMS_COMMON_EXPORT
#endif

#ifdef __cplusplus
extern "C" 
{
#endif

#ifdef _DEBUGPRINT
	void GMS_COMMON_EXPORT DbgPrint(const char *format, ...);
	void GMS_COMMON_EXPORT DbgPrintW(const wchar_t *format, ...);
#else
#define DbgPrint(...){}
#define DbgPrintW(...){}
#endif // _DEBUGPRINT

#ifdef __cplusplus
}
#endif

#endif // __UNSDEBUG_H