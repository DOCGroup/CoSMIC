
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl T3_RUNTIME
// ------------------------------
#ifndef T3_RUNTIME_EXPORT_H
#define T3_RUNTIME_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (T3_RUNTIME_HAS_DLL)
#  define T3_RUNTIME_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && T3_RUNTIME_HAS_DLL */

#if !defined (T3_RUNTIME_HAS_DLL)
#  define T3_RUNTIME_HAS_DLL 1
#endif /* ! T3_RUNTIME_HAS_DLL */

#if defined (T3_RUNTIME_HAS_DLL) && (T3_RUNTIME_HAS_DLL == 1)
#  if defined (T3_RUNTIME_BUILD_DLL)
#    define T3_RUNTIME_Export ACE_Proper_Export_Flag
#    define T3_RUNTIME_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define T3_RUNTIME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* T3_RUNTIME_BUILD_DLL */
#    define T3_RUNTIME_Export ACE_Proper_Import_Flag
#    define T3_RUNTIME_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define T3_RUNTIME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* T3_RUNTIME_BUILD_DLL */
#else /* T3_RUNTIME_HAS_DLL == 1 */
#  define T3_RUNTIME_Export
#  define T3_RUNTIME_SINGLETON_DECLARATION(T)
#  define T3_RUNTIME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* T3_RUNTIME_HAS_DLL == 1 */

// Set T3_RUNTIME_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (T3_RUNTIME_NTRACE)
#  if (ACE_NTRACE == 1)
#    define T3_RUNTIME_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define T3_RUNTIME_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !T3_RUNTIME_NTRACE */

#if (T3_RUNTIME_NTRACE == 1)
#  define T3_RUNTIME_TRACE(X)
#else /* (T3_RUNTIME_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define T3_RUNTIME_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (T3_RUNTIME_NTRACE == 1) */

#endif /* T3_RUNTIME_EXPORT_H */

// End of auto generated file.
