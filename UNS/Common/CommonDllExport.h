/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
//----------------------------------------------------------------------------
//
//  File:       CommonDllExport.h
//
//  Contents:   File which define declspec for cross-platform portability.
//
//----------------------------------------------------------------------------

#ifndef COMMONDLLEXPORT_H
#define COMMONDLLEXPORT_H 1

#pragma warning(disable: 4251)

#if defined (_WIN32) || defined (_WIN64)
#ifdef COMMON_DLL_EXPORTS
#define COMMON_EXPORT __declspec(dllexport)
#else
#define COMMON_EXPORT __declspec(dllimport)
#endif
#else
#define COMMON_EXPORT
#endif

#endif // COMMONDLLEXPORT_H