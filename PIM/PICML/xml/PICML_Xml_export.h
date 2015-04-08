
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -n PICML_XML
// ------------------------------
#ifndef PICML_XML_EXPORT_H
#define PICML_XML_EXPORT_H

#include "ace/config-all.h"

#if !defined (PICML_XML_HAS_DLL)
#  define PICML_XML_HAS_DLL 1
#endif /* ! PICML_XML_HAS_DLL */

#if defined (PICML_XML_HAS_DLL) && (PICML_XML_HAS_DLL == 1)
#  if defined (PICML_XML_BUILD_DLL)
#    define PICML_XML_Export ACE_Proper_Export_Flag
#    define PICML_XML_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PICML_XML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PICML_XML_BUILD_DLL */
#    define PICML_XML_Export ACE_Proper_Import_Flag
#    define PICML_XML_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PICML_XML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PICML_XML_BUILD_DLL */
#else /* PICML_XML_HAS_DLL == 1 */
#  define PICML_XML_Export
#  define PICML_XML_SINGLETON_DECLARATION(T)
#  define PICML_XML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PICML_XML_HAS_DLL == 1 */

// Set PICML_XML_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PICML_XML_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PICML_XML_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PICML_XML_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PICML_XML_NTRACE */

#if (PICML_XML_NTRACE == 1)
#  define PICML_XML_TRACE(X)
#else /* (PICML_XML_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PICML_XML_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PICML_XML_NTRACE == 1) */

#endif /* PICML_XML_EXPORT_H */

// End of auto generated file.
