/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl EVENTMANAGER
// ------------------------------
#ifndef EVENTMANAGER_EXPORT_H
#define EVENTMANAGER_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (EVENTMANAGER_HAS_DLL)
#  define EVENTMANAGER_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && EVENTMANAGER_HAS_DLL */

#if !defined (EVENTMANAGER_HAS_DLL)
#  define EVENTMANAGER_HAS_DLL 1
#endif /* ! EVENTMANAGER_HAS_DLL */

#if defined (EVENTMANAGER_HAS_DLL) && (EVENTMANAGER_HAS_DLL == 1)
#  if defined (EVENTMANAGER_BUILD_DLL)
#    define EVENTMANAGER_Export ACE_Proper_Export_Flag
#    define EVENTMANAGER_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define EVENTMANAGER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* EVENTMANAGER_BUILD_DLL */
#    define EVENTMANAGER_Export ACE_Proper_Import_Flag
#    define EVENTMANAGER_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define EVENTMANAGER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* EVENTMANAGER_BUILD_DLL */
#else /* EVENTMANAGER_HAS_DLL == 1 */
#  define EVENTMANAGER_Export
#  define EVENTMANAGER_SINGLETON_DECLARATION(T)
#  define EVENTMANAGER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* EVENTMANAGER_HAS_DLL == 1 */

// Set EVENTMANAGER_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (EVENTMANAGER_NTRACE)
#  if (ACE_NTRACE == 1)
#    define EVENTMANAGER_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define EVENTMANAGER_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !EVENTMANAGER_NTRACE */

#if (EVENTMANAGER_NTRACE == 1)
#  define EVENTMANAGER_TRACE(X)
#else /* (EVENTMANAGER_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define EVENTMANAGER_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (EVENTMANAGER_NTRACE == 1) */

#endif /* EVENTMANAGER_EXPORT_H */

// End of auto generated file.
