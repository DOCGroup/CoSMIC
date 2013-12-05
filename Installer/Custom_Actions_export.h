
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CUSTOM_ACTIONS
// ------------------------------
#ifndef CUSTOM_ACTIONS_EXPORT_H
#define CUSTOM_ACTIONS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CUSTOM_ACTIONS_HAS_DLL)
#  define CUSTOM_ACTIONS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CUSTOM_ACTIONS_HAS_DLL */

#if !defined (CUSTOM_ACTIONS_HAS_DLL)
#  define CUSTOM_ACTIONS_HAS_DLL 1
#endif /* ! CUSTOM_ACTIONS_HAS_DLL */

#if defined (CUSTOM_ACTIONS_HAS_DLL) && (CUSTOM_ACTIONS_HAS_DLL == 1)
#  if defined (CUSTOM_ACTIONS_BUILD_DLL)
#    define CUSTOM_ACTIONS_Export ACE_Proper_Export_Flag
#    define CUSTOM_ACTIONS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CUSTOM_ACTIONS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CUSTOM_ACTIONS_BUILD_DLL */
#    define CUSTOM_ACTIONS_Export ACE_Proper_Import_Flag
#    define CUSTOM_ACTIONS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CUSTOM_ACTIONS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CUSTOM_ACTIONS_BUILD_DLL */
#else /* CUSTOM_ACTIONS_HAS_DLL == 1 */
#  define CUSTOM_ACTIONS_Export
#  define CUSTOM_ACTIONS_SINGLETON_DECLARATION(T)
#  define CUSTOM_ACTIONS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CUSTOM_ACTIONS_HAS_DLL == 1 */

// Set CUSTOM_ACTIONS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CUSTOM_ACTIONS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CUSTOM_ACTIONS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CUSTOM_ACTIONS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CUSTOM_ACTIONS_NTRACE */

#if (CUSTOM_ACTIONS_NTRACE == 1)
#  define CUSTOM_ACTIONS_TRACE(X)
#else /* (CUSTOM_ACTIONS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CUSTOM_ACTIONS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CUSTOM_ACTIONS_NTRACE == 1) */

#endif /* CUSTOM_ACTIONS_EXPORT_H */

// End of auto generated file.
