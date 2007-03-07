
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s BIRSpecification
// ------------------------------
#ifndef BIRSPECIFICATION_EXPORT_H
#define BIRSPECIFICATION_EXPORT_H

#if !defined (BIRSPECIFICATION_HAS_DLL)
#  define BIRSPECIFICATION_HAS_DLL 1
#endif /* ! BIRSPECIFICATION_HAS_DLL */

#if defined (BIRSPECIFICATION_HAS_DLL) && (BIRSPECIFICATION_HAS_DLL == 1)
#  if defined (BIRSPECIFICATION_BUILD_DLL)
#    define BIRSpecification_Export __declspec(dllexport)
#  else /* BIRSPECIFICATION_BUILD_DLL */
#    define BIRSpecification_Export __declspec(dllimport)
#  endif /* BIRSPECIFICATION_BUILD_DLL */
#else /* BIRSPECIFICATION_HAS_DLL == 1 */
#  define BIRSpecification_Export
#endif /* BIRSPECIFICATION_HAS_DLL == 1 */


#endif /* BIRSPECIFICATION_EXPORT_H */

// End of auto generated file.
