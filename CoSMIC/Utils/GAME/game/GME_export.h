
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl GME
// ------------------------------
#ifndef GME_EXPORT_H
#define GME_EXPORT_H

#include "game/config.h"
#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (GME_HAS_DLL)
#  define GME_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && GME_HAS_DLL */

#if !defined (GME_HAS_DLL)
#  define GME_HAS_DLL 1
#endif /* ! GME_HAS_DLL */

#if defined (GME_HAS_DLL) && (GME_HAS_DLL == 1)
#  if defined (GME_BUILD_DLL)
#    define GME_Export ACE_Proper_Export_Flag
#    define GME_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define GME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* GME_BUILD_DLL */
#    define GME_Export ACE_Proper_Import_Flag
#    define GME_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define GME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* GME_BUILD_DLL */
#else /* GME_HAS_DLL == 1 */
#  define GME_Export
#  define GME_SINGLETON_DECLARATION(T)
#  define GME_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* GME_HAS_DLL == 1 */

// Set GME_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (GME_NTRACE)
#  if (ACE_NTRACE == 1)
#    define GME_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define GME_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !GME_NTRACE */

#if (GME_NTRACE == 1)
#  define GME_TRACE(X)
#else /* (GME_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define GME_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (GME_NTRACE == 1) */

#endif /* GME_EXPORT_H */

// End of auto generated file.
