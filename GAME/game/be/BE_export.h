
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl GAME_BE
// ------------------------------
#ifndef GAME_BE_EXPORT_H
#define GAME_BE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (GAME_BE_HAS_DLL)
#  define GAME_BE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && GAME_BE_HAS_DLL */

#if !defined (GAME_BE_HAS_DLL)
#  define GAME_BE_HAS_DLL 1
#endif /* ! GAME_BE_HAS_DLL */

#if defined (GAME_BE_HAS_DLL) && (GAME_BE_HAS_DLL == 1)
#  if defined (GAME_BE_BUILD_DLL)
#    define GAME_BE_Export ACE_Proper_Export_Flag
#    define GAME_BE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define GAME_BE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* GAME_BE_BUILD_DLL */
#    define GAME_BE_Export ACE_Proper_Import_Flag
#    define GAME_BE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define GAME_BE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* GAME_BE_BUILD_DLL */
#else /* GAME_BE_HAS_DLL == 1 */
#  define GAME_BE_Export
#  define GAME_BE_SINGLETON_DECLARATION(T)
#  define GAME_BE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* GAME_BE_HAS_DLL == 1 */

// Set GAME_BE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (GAME_BE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define GAME_BE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define GAME_BE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !GAME_BE_NTRACE */

#if (GAME_BE_NTRACE == 1)
#  define GAME_BE_TRACE(X)
#else /* (GAME_BE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define GAME_BE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (GAME_BE_NTRACE == 1) */

#endif /* GAME_BE_EXPORT_H */

// End of auto generated file.
