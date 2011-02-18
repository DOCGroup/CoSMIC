
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl IDL_GENERATOR
// ------------------------------
#ifndef IDL_GENERATOR_EXPORT_H
#define IDL_GENERATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (IDL_GENERATOR_HAS_DLL)
#  define IDL_GENERATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && IDL_GENERATOR_HAS_DLL */

#if !defined (IDL_GENERATOR_HAS_DLL)
#  define IDL_GENERATOR_HAS_DLL 1
#endif /* ! IDL_GENERATOR_HAS_DLL */

#if defined (IDL_GENERATOR_HAS_DLL) && (IDL_GENERATOR_HAS_DLL == 1)
#  if defined (IDL_GENERATOR_BUILD_DLL)
#    define IDL_GENERATOR_Export ACE_Proper_Export_Flag
#    define IDL_GENERATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define IDL_GENERATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* IDL_GENERATOR_BUILD_DLL */
#    define IDL_GENERATOR_Export ACE_Proper_Import_Flag
#    define IDL_GENERATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define IDL_GENERATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* IDL_GENERATOR_BUILD_DLL */
#else /* IDL_GENERATOR_HAS_DLL == 1 */
#  define IDL_GENERATOR_Export
#  define IDL_GENERATOR_SINGLETON_DECLARATION(T)
#  define IDL_GENERATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* IDL_GENERATOR_HAS_DLL == 1 */

// Set IDL_GENERATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (IDL_GENERATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define IDL_GENERATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define IDL_GENERATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !IDL_GENERATOR_NTRACE */

#if (IDL_GENERATOR_NTRACE == 1)
#  define IDL_GENERATOR_TRACE(X)
#else /* (IDL_GENERATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define IDL_GENERATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (IDL_GENERATOR_NTRACE == 1) */

#endif /* IDL_GENERATOR_EXPORT_H */

// End of auto generated file.
