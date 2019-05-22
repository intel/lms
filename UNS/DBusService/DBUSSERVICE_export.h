/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2018 Intel Corporation
 */
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl DBUSSERVICE
// ------------------------------
#ifndef DBUSSERVICE_EXPORT_H
#define DBUSSERVICE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DBUSSERVICE_HAS_DLL)
#  define DBUSSERVICE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DBUSSERVICE_HAS_DLL */

#if !defined (DBUSSERVICE_HAS_DLL)
#  define DBUSSERVICE_HAS_DLL 1
#endif /* ! DBUSSERVICE_HAS_DLL */

#if defined (DBUSSERVICE_HAS_DLL) && (DBUSSERVICE_HAS_DLL == 1)
#  if defined (DBUSSERVICE_BUILD_DLL)
#    define DBUSSERVICE_Export ACE_Proper_Export_Flag
#    define DBUSSERVICE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DBUSSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DBUSSERVICE_BUILD_DLL */
#    define DBUSSERVICE_Export ACE_Proper_Import_Flag
#    define DBUSSERVICE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DBUSSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DBUSSERVICE_BUILD_DLL */
#else /* DBUSSERVICE_HAS_DLL == 1 */
#  define DBUSSERVICE_Export
#  define DBUSSERVICE_SINGLETON_DECLARATION(T)
#  define DBUSSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DBUSSERVICE_HAS_DLL == 1 */

// Set DBUSSERVICE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DBUSSERVICE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DBUSSERVICE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DBUSSERVICE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DBUSSERVICE_NTRACE */

#if (DBUSSERVICE_NTRACE == 1)
#  define DBUSSERVICE_TRACE(X)
#else /* (DBUSSERVICE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DBUSSERVICE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DBUSSERVICE_NTRACE == 1) */

#endif /* DBUSSERVICE_EXPORT_H */

// End of auto generated file.
