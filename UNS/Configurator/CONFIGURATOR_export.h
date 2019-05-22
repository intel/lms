/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CONFIGURATOR
// ------------------------------
#ifndef CONFIGURATOR_EXPORT_H
#define CONFIGURATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CONFIGURATOR_HAS_DLL)
#  define CONFIGURATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CONFIGURATOR_HAS_DLL */

#if !defined (CONFIGURATOR_HAS_DLL)
#  define CONFIGURATOR_HAS_DLL 1
#endif /* ! CONFIGURATOR_HAS_DLL */

#if defined (CONFIGURATOR_HAS_DLL) && (CONFIGURATOR_HAS_DLL == 1)
#  if defined (CONFIGURATOR_BUILD_DLL)
#    define CONFIGURATOR_Export ACE_Proper_Export_Flag
#    define CONFIGURATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CONFIGURATOR_BUILD_DLL */
#    define CONFIGURATOR_Export ACE_Proper_Import_Flag
#    define CONFIGURATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CONFIGURATOR_BUILD_DLL */
#else /* CONFIGURATOR_HAS_DLL == 1 */
#  define CONFIGURATOR_Export
#  define CONFIGURATOR_SINGLETON_DECLARATION(T)
#  define CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CONFIGURATOR_HAS_DLL == 1 */

// Set CONFIGURATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CONFIGURATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CONFIGURATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CONFIGURATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CONFIGURATOR_NTRACE */

#if (CONFIGURATOR_NTRACE == 1)
#  define CONFIGURATOR_TRACE(X)
#else /* (CONFIGURATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CONFIGURATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CONFIGURATOR_NTRACE == 1) */

#endif /* CONFIGURATOR_EXPORT_H */

// End of auto generated file.
