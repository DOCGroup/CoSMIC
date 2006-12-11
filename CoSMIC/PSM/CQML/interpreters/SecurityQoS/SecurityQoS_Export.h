// -*- C++ -*-
// $Id: SecurityQoS_Export.h 587 2005-12-14 21:39:34Z sutambe $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s SecurityQoS
// ------------------------------
#ifndef SECURITYQOS_EXPORT_H
#define SECURITYQOS_EXPORT_H

#if !defined (SECURITYQOS_HAS_DLL)
#  define SECURITYQOS_HAS_DLL 1
#endif /* ! SECURITYQOS_HAS_DLL */

#if defined (SECURITYQOS_HAS_DLL) && (SECURITYQOS_HAS_DLL == 1)
#  if defined (SECURITYQOS_BUILD_DLL)
#    define SecurityQoS_Export __declspec(dllexport)
#  else /* SECURITYQOS_BUILD_DLL */
#    define SecurityQoS_Export __declspec(dllimport)
#  endif /* SECURITYQOS_BUILD_DLL */
#else /* SECURITYQOS_HAS_DLL == 1 */
#  define SecurityQoS_Export
#endif /* SECURITYQOS_HAS_DLL == 1 */

#endif /* SECURITYQOS_EXPORT_H */


// End of auto generated file.

