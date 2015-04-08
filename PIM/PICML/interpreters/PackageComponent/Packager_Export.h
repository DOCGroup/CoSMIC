// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Packager
// ------------------------------
#ifndef PACKAGER_EXPORT_H
#define PACKAGER_EXPORT_H

#if !defined (PACKAGER_HAS_DLL)
#  define PACKAGER_HAS_DLL 1
#endif /* ! PACKAGER_HAS_DLL */

#if defined (PACKAGER_HAS_DLL) && (PACKAGER_HAS_DLL == 1)
#  if defined (PACKAGER_BUILD_DLL)
#    define Packager_Export __declspec(dllexport)
#  else /* PACKAGER_BUILD_DLL */
#    define Packager_Export __declspec(dllimport)
#  endif /* PACKAGER_BUILD_DLL */
#else /* PACKAGER_HAS_DLL == 1 */
#  define Packager_Export
#endif /* PACKAGER_HAS_DLL == 1 */

#endif /* PACKAGER_EXPORT_H */

// End of auto generated file.
