// -*- C++ -*-

#ifndef _DQML_EXPORT_H_
#define _DQML_EXPORT_H_

#include "ace/config.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DQML_HAS_DLL)
#  define DQML_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DQML_HAS_DLL */

#if !defined (DQML_HAS_DLL)
#  define DQML_HAS_DLL 1
#endif /* ! DQML_HAS_DLL */

#if defined (DQML_HAS_DLL) && (DQML_HAS_DLL == 1)
#  if defined (DQML_BUILD_DLL)
#    define DQML_Export ACE_Proper_Export_Flag
#    define DQML_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DQML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DQML_BUILD_DLL */
#    define DQML_Export ACE_Proper_Import_Flag
#    define DQML_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DQML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DQML_BUILD_DLL */
#else /* DQML_HAS_DLL == 1 */
#  define DQML_Export
#  define DQML_SINGLETON_DECLARATION(T)
#  define DQML_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DQML_HAS_DLL == 1 */

// Set DQML_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DQML_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DQML_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DQML_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DQML_NTRACE */

#if (DQML_NTRACE == 1)
#  define DQML_TRACE(X)
#else /* (DQML_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DQML_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DQML_NTRACE == 1) */
#endif  // !defined _DQML_EXPORT_H_
