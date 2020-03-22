/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
//----------------------------------------------------------------------------
//
//  File:       GMSCommonDllExport.h
//
//  Contents:   File which define declspec for cross-platform portability.
//
//----------------------------------------------------------------------------

#ifndef GMS_COMMONDLLEXPORT_H
#define GMS_COMMONDLLEXPORT_H 1

#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

#ifdef GMS_COMMON_NO_DLL
  #define GMS_COMMON_EXPORT
#else // GMS_COMMON_NO_DLL
#if defined (_WIN32) || defined (_WIN64)
  #ifdef GMS_COMMON_DLL_EXPORTS
    #define GMS_COMMON_EXPORT __declspec(dllexport)
  #else
    #define GMS_COMMON_EXPORT __declspec(dllimport)
  #endif
#else
  #ifdef GMS_COMMON_DLL_EXPORTS
    #define GMS_COMMON_EXPORT __attribute__((__visibility__("default")))
  #else
    #define GMS_COMMON_EXPORT
  #endif
#endif
#endif // GMS_COMMON_NO_DLL

#endif // GMS_COMMONDLLEXPORT_H
