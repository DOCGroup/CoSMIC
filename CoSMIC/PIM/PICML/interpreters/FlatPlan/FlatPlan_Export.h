// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Package
// ------------------------------
#ifndef FLATPLAN_EXPORT_H
#define FLATPLAN_EXPORT_H

#if !defined (FLATPLAN_HAS_DLL)
#  define FLATPLAN_HAS_DLL 1
#endif /* ! FLATPLAN_HAS_DLL */

#if defined (FLATPLAN_HAS_DLL) && (FLATPLAN_HAS_DLL == 1)
#  if defined (FLATPLAN_BUILD_DLL)
#    define FlatPlan_Export __declspec(dllexport)
#  else /* FLATPLAN_BUILD_DLL */
#    define FlatPlan_Export __declspec(dllimport)
#  endif /* FLATPLAN_BUILD_DLL */
#else /* FLATPLAN_HAS_DLL == 1 */
#  define FlatPlan_Export
#endif /* FLATPLAN_HAS_DLL == 1 */

#endif /* FLATPLAN_EXPORT_H */

// End of auto generated file.
