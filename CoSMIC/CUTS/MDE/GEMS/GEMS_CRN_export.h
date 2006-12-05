
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl GEMS_CRN
// ------------------------------
#ifndef GEMS_CRN_EXPORT_H
#define GEMS_CRN_EXPORT_H

#include "ace/config-all.h"
#include "cuts/config.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (GEMS_CRN_HAS_DLL)
#  define GEMS_CRN_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && GEMS_CRN_HAS_DLL */

#if !defined (GEMS_CRN_HAS_DLL)
#  define GEMS_CRN_HAS_DLL 1
#endif /* ! GEMS_CRN_HAS_DLL */

#if defined (GEMS_CRN_HAS_DLL) && (GEMS_CRN_HAS_DLL == 1)
#  if defined (GEMS_CRN_BUILD_DLL)
#    define GEMS_CRN_Export ACE_Proper_Export_Flag
#    define GEMS_CRN_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define GEMS_CRN_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* GEMS_CRN_BUILD_DLL */
#    define GEMS_CRN_Export ACE_Proper_Import_Flag
#    define GEMS_CRN_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define GEMS_CRN_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* GEMS_CRN_BUILD_DLL */
#else /* GEMS_CRN_HAS_DLL == 1 */
#  define GEMS_CRN_Export
#  define GEMS_CRN_SINGLETON_DECLARATION(T)
#  define GEMS_CRN_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* GEMS_CRN_HAS_DLL == 1 */

// Set GEMS_CRN_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (GEMS_CRN_NTRACE)
#  if (ACE_NTRACE == 1)
#    define GEMS_CRN_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define GEMS_CRN_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !GEMS_CRN_NTRACE */

#if (GEMS_CRN_NTRACE == 1)
#  define GEMS_CRN_TRACE(X)
#else /* (GEMS_CRN_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define GEMS_CRN_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (GEMS_CRN_NTRACE == 1) */

#endif /* GEMS_CRN_EXPORT_H */

// End of auto generated file.
