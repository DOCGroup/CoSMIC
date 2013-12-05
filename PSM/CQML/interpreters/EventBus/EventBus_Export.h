// -*- C++ -*-
// $Id: EventBus_Export.h,v 1.1.2.1 2006/03/29 05:37:04 sutambe Exp $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Package
// ------------------------------
#ifndef EVENTBUS_EXPORT_H
#define EVENTBUS_EXPORT_H

#if !defined (EVENTBUS_HAS_DLL)
#  define EVENTBUS_HAS_DLL 1
#endif /* ! EVENTBUS_HAS_DLL */

#if defined (EVENTBUS_HAS_DLL) && (EVENTBUS_HAS_DLL == 1)
#  if defined (EVENTBUS_BUILD_DLL)
#    define EventBus_Export __declspec(dllexport)
#  else /* EVENTBUS_BUILD_DLL */
#    define EventBus_Export __declspec(dllimport)
#  endif /* EVENTBUS_BUILD_DLL */
#else /* EVENTBUS_HAS_DLL == 1 */
#  define EventBus_Export
#endif /* EVENTBUS_HAS_DLL == 1 */

#endif /* EVENTBUS_EXPORT_H */

// End of auto generated file.
