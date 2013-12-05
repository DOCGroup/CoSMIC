// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Package
// ------------------------------
#ifndef QED_DEPLOYMENT_EXPORT_H
#define QED_DEPLOYMENT_EXPORT_H

#if !defined (QED_DEPLOYMENT_HAS_DLL)
#  define QED_DEPLOYMENT_HAS_DLL 1
#endif /* ! QED_DEPLOYMENT_HAS_DLL */

#if defined (QED_DEPLOYMENT_HAS_DLL) && (QED_DEPLOYMENT_HAS_DLL == 1)
#  if defined (QED_DEPLOYMENT_BUILD_DLL)
#    define QED_Deployment_Export __declspec(dllexport)
#  else /* QED_DEPLOYMENT_BUILD_DLL */
#    define QED_Deployment_Export __declspec(dllimport)
#  endif /* QED_DEPLOYMENT_BUILD_DLL */
#else /* QED_DEPLOYMENT_HAS_DLL == 1 */
#  define QED_Deployment_Export
#endif /* QED_DEPLOYMENT_HAS_DLL == 1 */

#endif /* QED_DEPLOYMENT_EXPORT_H */

// End of auto generated file.
