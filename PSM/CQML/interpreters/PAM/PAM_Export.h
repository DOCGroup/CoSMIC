// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s PAM
// ------------------------------
#ifndef PAM_EXPORT_H
#define PAM_EXPORT_H

#if !defined (PAM_HAS_DLL)
#  define PAM_HAS_DLL 1
#endif /* ! PAM_HAS_DLL */

#if defined (PAM_HAS_DLL) && (PAM_HAS_DLL == 1)
#  if defined (PAM_BUILD_DLL)
#    define PAM_Export __declspec(dllexport)
#  else /* PAM_BUILD_DLL */
#    define PAM_Export __declspec(dllimport)
#  endif /* PAM_BUILD_DLL */
#else /* PAM_HAS_DLL == 1 */
#  define PAM_Export
#endif /* PAM_HAS_DLL == 1 */

#endif /* PAM_EXPORT_H */

// End of auto generated file.
