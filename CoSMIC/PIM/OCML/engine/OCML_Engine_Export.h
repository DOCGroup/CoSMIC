
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl OCML_Engine
// ------------------------------
#ifndef OCML_ENGINE_EXPORT_H
#define OCML_ENGINE_EXPORT_H

#include "ace/config-all.h"

#if !defined (OCML_ENGINE_HAS_DLL)
#  define OCML_ENGINE_HAS_DLL 1
#endif /* ! OCML_ENGINE_HAS_DLL */

#if defined (OCML_ENGINE_HAS_DLL) && (OCML_ENGINE_HAS_DLL == 1)
#  if defined (OCML_ENGINE_BUILD_DLL)
#    define OCML_Engine_Export ACE_Proper_Export_Flag
#    define OCML_ENGINE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define OCML_ENGINE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* OCML_ENGINE_BUILD_DLL */
#    define OCML_Engine_Export ACE_Proper_Import_Flag
#    define OCML_ENGINE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define OCML_ENGINE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* OCML_ENGINE_BUILD_DLL */
#else /* OCML_ENGINE_HAS_DLL == 1 */
#  define OCML_Engine_Export
#  define OCML_ENGINE_SINGLETON_DECLARATION(T)
#  define OCML_ENGINE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* OCML_ENGINE_HAS_DLL == 1 */

// Set OCML_ENGINE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (OCML_ENGINE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define OCML_ENGINE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define OCML_ENGINE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !OCML_ENGINE_NTRACE */

#if (OCML_ENGINE_NTRACE == 1)
#  define OCML_ENGINE_TRACE(X)
#else /* (OCML_ENGINE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define OCML_ENGINE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (OCML_ENGINE_NTRACE == 1) */

#endif /* OCML_ENGINE_EXPORT_H */

// End of auto generated file.
