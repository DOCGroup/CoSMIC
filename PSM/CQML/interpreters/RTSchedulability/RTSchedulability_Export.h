// -*- C++ -*-
// $Id:$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s RTSchedulability
// ------------------------------
#ifndef RTSCHEDULABILITY_EXPORT_H
#define RTSCHEDULABILITY_EXPORT_H

#if !defined (RTSCHEDULABILITY_HAS_DLL)
#  define RTSCHEDULABILITY_HAS_DLL 1
#endif /* ! RTSCHEDULABILITY_HAS_DLL */

#if defined (RTSCHEDULABILITY_HAS_DLL) && (RTSCHEDULABILITY_HAS_DLL == 1)
#  if defined (RTSCHEDULABILITY_BUILD_DLL)
#    define RTSchedulability_Export __declspec(dllexport)
#  else /* RTSCHEDULABILITY_BUILD_DLL */
#    define RTSchedulability_Export __declspec(dllimport)
#  endif /* RTSCHEDULABILITY_BUILD_DLL */
#else /* RTSCHEDULABILITY_HAS_DLL == 1 */
#  define RTSchedulability_Export
#endif /* RTSCHEDULABILITY_HAS_DLL == 1 */

#endif /* RTSCHEDULABILITY_EXPORT_H */


// End of auto generated file.
