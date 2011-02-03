
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl GAME_GRAPHICS
// ------------------------------
#ifndef GAME_GRAPHICS_EXPORT_H
#define GAME_GRAPHICS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (GAME_GRAPHICS_HAS_DLL)
#  define GAME_GRAPHICS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && GAME_GRAPHICS_HAS_DLL */

#if !defined (GAME_GRAPHICS_HAS_DLL)
#  define GAME_GRAPHICS_HAS_DLL 1
#endif /* ! GAME_GRAPHICS_HAS_DLL */

#if defined (GAME_GRAPHICS_HAS_DLL) && (GAME_GRAPHICS_HAS_DLL == 1)
#  if defined (GAME_GRAPHICS_BUILD_DLL)
#    define GAME_GRAPHICS_Export ACE_Proper_Export_Flag
#    define GAME_GRAPHICS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define GAME_GRAPHICS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* GAME_GRAPHICS_BUILD_DLL */
#    define GAME_GRAPHICS_Export ACE_Proper_Import_Flag
#    define GAME_GRAPHICS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define GAME_GRAPHICS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* GAME_GRAPHICS_BUILD_DLL */
#else /* GAME_GRAPHICS_HAS_DLL == 1 */
#  define GAME_GRAPHICS_Export
#  define GAME_GRAPHICS_SINGLETON_DECLARATION(T)
#  define GAME_GRAPHICS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* GAME_GRAPHICS_HAS_DLL == 1 */

// Set GAME_GRAPHICS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (GAME_GRAPHICS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define GAME_GRAPHICS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define GAME_GRAPHICS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !GAME_GRAPHICS_NTRACE */

#if (GAME_GRAPHICS_NTRACE == 1)
#  define GAME_GRAPHICS_TRACE(X)
#else /* (GAME_GRAPHICS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define GAME_GRAPHICS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (GAME_GRAPHICS_NTRACE == 1) */

#endif /* GAME_GRAPHICS_EXPORT_H */

// End of auto generated file.
