// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Package
// ------------------------------
#ifndef CIAO_EVENTS_EXPORT_H
#define CIAO_EVENTS_EXPORT_H

#if !defined (CIAO_EVENTS_HAS_DLL)
#  define CIAO_EVENTS_HAS_DLL 1
#endif /* ! CIAO_EVENTS_HAS_DLL */

#if defined (CIAO_EVENTS_HAS_DLL) && (CIAO_EVENTS_HAS_DLL == 1)
#  if defined (CIAO_EVENTS_BUILD_DLL)
#    define CIAOEvents_Export __declspec(dllexport)
#  else /* CIAO_EVENTS_BUILD_DLL */
#    define CIAOEvents_Export __declspec(dllimport)
#  endif /* CIAO_EVENTS_BUILD_DLL */
#else /* CIAO_EVENTS_HAS_DLL == 1 */
#  define CIAOEvents_Export
#endif /* CIAO_EVENTS_HAS_DLL == 1 */

#endif /* CIAO_EVENTS_EXPORT_H */

// End of auto generated file.