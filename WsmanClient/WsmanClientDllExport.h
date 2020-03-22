/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: WsmanClientDllExport.h

--*/


#ifndef _WSMAN_CLIENT_DLL_EXPORT_H
#define _WSMAN_CLIENT_DLL_EXPORT_H

#ifdef WSMAN_NO_DLL
#define WSMAN_DLL_API
#else // WSMAN_NO_DLL
#ifdef WIN32
#ifdef WSMAN_DLL_EXPORT
#define WSMAN_DLL_API __declspec(dllexport)
#else
#define WSMAN_DLL_API __declspec(dllimport)
#endif // WSMAN_DLL_EXPORT
#else // WIN32
#ifdef WSMAN_DLL_EXPORT
#define WSMAN_DLL_API __attribute__((__visibility__("default")))
#else
#define WSMAN_DLL_API
#endif // WSMAN_DLL_EXPORT
#endif // WIN32
#endif // WSMAN_NO_DLL

#endif // _WSMAN_CLIENT_DLL_EXPORT_H
