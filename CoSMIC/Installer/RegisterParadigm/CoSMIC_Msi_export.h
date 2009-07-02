
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl COSMIC_MSI
// ------------------------------
#ifndef COSMIC_MSI_EXPORT_H
#define COSMIC_MSI_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (COSMIC_MSI_HAS_DLL)
#  define COSMIC_MSI_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && COSMIC_MSI_HAS_DLL */

#if !defined (COSMIC_MSI_HAS_DLL)
#  define COSMIC_MSI_HAS_DLL 1
#endif /* ! COSMIC_MSI_HAS_DLL */

#if defined (COSMIC_MSI_HAS_DLL) && (COSMIC_MSI_HAS_DLL == 1)
#  if defined (COSMIC_MSI_BUILD_DLL)
#    define COSMIC_MSI_Export ACE_Proper_Export_Flag
#    define COSMIC_MSI_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define COSMIC_MSI_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* COSMIC_MSI_BUILD_DLL */
#    define COSMIC_MSI_Export ACE_Proper_Import_Flag
#    define COSMIC_MSI_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define COSMIC_MSI_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* COSMIC_MSI_BUILD_DLL */
#else /* COSMIC_MSI_HAS_DLL == 1 */
#  define COSMIC_MSI_Export
#  define COSMIC_MSI_SINGLETON_DECLARATION(T)
#  define COSMIC_MSI_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* COSMIC_MSI_HAS_DLL == 1 */

// Set COSMIC_MSI_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (COSMIC_MSI_NTRACE)
#  if (ACE_NTRACE == 1)
#    define COSMIC_MSI_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define COSMIC_MSI_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !COSMIC_MSI_NTRACE */

#if (COSMIC_MSI_NTRACE == 1)
#  define COSMIC_MSI_TRACE(X)
#else /* (COSMIC_MSI_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define COSMIC_MSI_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (COSMIC_MSI_NTRACE == 1) */

#endif /* COSMIC_MSI_EXPORT_H */

// End of auto generated file.
