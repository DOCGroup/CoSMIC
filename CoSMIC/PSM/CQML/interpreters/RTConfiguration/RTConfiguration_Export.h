
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s RTConfiguration
// ------------------------------
#ifndef RTCONFIGURATION_EXPORT_H
#define RTCONFIGURATION_EXPORT_H

#if !defined (RTCONFIGURATION_HAS_DLL)
#  define RTCONFIGURATION_HAS_DLL 1
#endif /* ! RTCONFIGURATION_HAS_DLL */

#if defined (RTCONFIGURATION_HAS_DLL) && (RTCONFIGURATION_HAS_DLL == 1)
#  if defined (RTCONFIGURATION_BUILD_DLL)
#    define RTConfiguration_Export __declspec(dllexport)
#  else /* RTCONFIGURATION_BUILD_DLL */
#    define RTConfiguration_Export __declspec(dllimport)
#  endif /* RTCONFIGURATION_BUILD_DLL */
#else /* RTCONFIGURATION_BUILD_DLL == 1 */
#  define RTConfiguration_Export
#endif /* RTCONFIGURATION_BUILD_DLL == 1 */


#endif /* RTCONFIGURATION_EXPORT_H */

// End of auto generated file.
