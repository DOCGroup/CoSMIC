
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl OCML_Common
// ------------------------------
#ifndef OCML_COMMON_EXPORT_H
#define OCML_COMMON_EXPORT_H

#include "ace/config-all.h"

#if !defined (OCML_COMMON_HAS_DLL)
#  define OCML_COMMON_HAS_DLL 1
#endif /* ! OCML_COMMON_HAS_DLL */

#if defined (OCML_COMMON_HAS_DLL) && (OCML_COMMON_HAS_DLL == 1)
#  if defined (OCML_COMMON_BUILD_DLL)
#    define OCML_Common_Export ACE_Proper_Export_Flag
#    define OCML_COMMON_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define OCML_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* OCML_COMMON_BUILD_DLL */
#    define OCML_Common_Export ACE_Proper_Import_Flag
#    define OCML_COMMON_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define OCML_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* OCML_COMMON_BUILD_DLL */
#else /* OCML_COMMON_HAS_DLL == 1 */
#  define OCML_Common_Export
#  define OCML_COMMON_SINGLETON_DECLARATION(T)
#  define OCML_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* OCML_COMMON_HAS_DLL == 1 */

// Set OCML_COMMON_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (OCML_COMMON_NTRACE)
#  if (ACE_NTRACE == 1)
#    define OCML_COMMON_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define OCML_COMMON_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !OCML_COMMON_NTRACE */

#if (OCML_COMMON_NTRACE == 1)
#  define OCML_COMMON_TRACE(X)
#else /* (OCML_COMMON_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define OCML_COMMON_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (OCML_COMMON_NTRACE == 1) */

#endif /* OCML_COMMON_EXPORT_H */

// End of auto generated file.
