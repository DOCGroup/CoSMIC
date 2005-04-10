// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Package
// ------------------------------
#ifndef PLAN_EXPORT_H
#define PLAN_EXPORT_H

#if !defined (PLAN_HAS_DLL)
#  define PLAN_HAS_DLL 1
#endif /* ! PLAN_HAS_DLL */

#if defined (PLAN_HAS_DLL) && (PLAN_HAS_DLL == 1)
#  if defined (PLAN_BUILD_DLL)
#    define Plan_Export __declspec(dllexport)
#  else /* PLAN_BUILD_DLL */
#    define Plan_Export __declspec(dllimport)
#  endif /* PLAN_BUILD_DLL */
#else /* PLAN_HAS_DLL == 1 */
#  define Plan_Export
#endif /* PLAN_HAS_DLL == 1 */

#endif /* PLAN_EXPORT_H */

// End of auto generated file.
