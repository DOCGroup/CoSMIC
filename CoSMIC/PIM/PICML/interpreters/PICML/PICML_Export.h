// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s PICML
// ------------------------------
#ifndef PICML_EXPORT_H
#define PICML_EXPORT_H

#if !defined (PICML_HAS_DLL)
#  define PICML_HAS_DLL 1
#endif /* ! PICML_HAS_DLL */

#if defined (PICML_HAS_DLL) && (PICML_HAS_DLL == 1)
#  if defined (PICML_BUILD_DLL)
#    define PICML_Export __declspec (dllexport)
#  else /* PICML_BUILD_DLL */
#    define PICML_Export __declspec (dllimport)
#  endif /* PICML_BUILD_DLL */
#else /* PICML_HAS_DLL == 1 */
#  define PICML_Export
#endif /* PICML_HAS_DLL == 1 */

#endif /* PICML_EXPORT_H */

// End of auto generated file.
