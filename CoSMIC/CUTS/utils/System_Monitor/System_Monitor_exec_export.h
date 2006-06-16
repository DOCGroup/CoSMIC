
// -*- C++ -*-
// $Id: System_Monitor_exec_export.h,v 1.1.4.1 2006/03/12 01:48:06 hillj Exp $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl SYSTEM_MONITOR_EXEC
// ------------------------------
#ifndef SYSTEM_MONITOR_EXEC_EXPORT_H
#define SYSTEM_MONITOR_EXEC_EXPORT_H

#include "ace/config-all.h"

#if !defined (SYSTEM_MONITOR_EXEC_HAS_DLL)
#  define SYSTEM_MONITOR_EXEC_HAS_DLL 1
#endif /* ! SYSTEM_MONITOR_EXEC_HAS_DLL */

#if defined (SYSTEM_MONITOR_EXEC_HAS_DLL) && (SYSTEM_MONITOR_EXEC_HAS_DLL == 1)
#  if defined (SYSTEM_MONITOR_EXEC_BUILD_DLL)
#    define SYSTEM_MONITOR_EXEC_Export ACE_Proper_Export_Flag
#    define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* SYSTEM_MONITOR_EXEC_BUILD_DLL */
#    define SYSTEM_MONITOR_EXEC_Export ACE_Proper_Import_Flag
#    define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* SYSTEM_MONITOR_EXEC_BUILD_DLL */
#else /* SYSTEM_MONITOR_EXEC_HAS_DLL == 1 */
#  define SYSTEM_MONITOR_EXEC_Export
#  define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARATION(T)
#  define SYSTEM_MONITOR_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* SYSTEM_MONITOR_EXEC_HAS_DLL == 1 */

// Set SYSTEM_MONITOR_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (SYSTEM_MONITOR_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define SYSTEM_MONITOR_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define SYSTEM_MONITOR_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !SYSTEM_MONITOR_EXEC_NTRACE */

#if (SYSTEM_MONITOR_EXEC_NTRACE == 1)
#  define SYSTEM_MONITOR_EXEC_TRACE(X)
#else /* (SYSTEM_MONITOR_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define SYSTEM_MONITOR_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (SYSTEM_MONITOR_EXEC_NTRACE == 1) */

#endif /* SYSTEM_MONITOR_EXEC_EXPORT_H */

// End of auto generated file.
