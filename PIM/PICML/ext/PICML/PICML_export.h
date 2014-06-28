// -*- C++ -*-

#ifndef _PICML_EXPORT_H_
#define _PICML_EXPORT_H_

#include "ace/config.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (PICML_HAS_DLL)
#  define PICML_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && PICML_HAS_DLL */

#if !defined (PICML_HAS_DLL)
#  define PICML_HAS_DLL 1
#endif /* ! PICML_HAS_DLL */

#if defined (PICML_HAS_DLL) && (PICML_HAS_DLL == 1)
#  if defined (PICML_BUILD_DLL)
#    define PICML_Export ACE_Proper_Export_Flag
#    define PICML_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PICML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PICML_BUILD_DLL */
#    define PICML_Export ACE_Proper_Import_Flag
#    define PICML_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PICML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PICML_BUILD_DLL */
#else /* PICML_HAS_DLL == 1 */
#  define PICML_Export
#  define PICML_SINGLETON_DECLARATION(T)
#  define PICML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PICML_HAS_DLL == 1 */

// Set PICML_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PICML_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PICML_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PICML_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PICML_NTRACE */

#if (PICML_NTRACE == 1)
#  define PICML_TRACE(X)
#else /* (PICML_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PICML_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PICML_NTRACE == 1) */
#endif  // !defined _PICML_EXPORT_H_
