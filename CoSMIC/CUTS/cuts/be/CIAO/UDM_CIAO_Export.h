// -*- C++ -*-

//=============================================================================
/**
 * @file        UDM_CIAO_Export.h
 *
 * $Id: UDM_CIAO_Export.h,v 1.1.2.1.2.1 2006/06/07 03:41:20 hillj Exp $
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_UDM_CIAO_EXPORT_H_
#define _CUTS_UDM_CIAO_EXPORT_H_

#if defined (PICML_HAS_DLL) && (PICML_HAS_DLL == 1)
#  if defined (CUTS_UDM_CIAO_BUILD_DLL)
#    define CUTS_UDM_CIAO_Export __declspec (dllexport)
#  else /* CUTS_UDM_CIAO_BUILD_DLL */
#    define CUTS_UDM_CIAO_Export __declspec (dllimport)
#  endif /* CUTS_UDM_CIAO_BUILD_DLL */
#else /* CUTS_UDM_CIAO_HAS_DLL == 1 */
#  define CUTS_UDM_CIAO_Export
#endif /* CUTS_UDM_CIAO_HAS_DLL == 1 */

#endif /* CUTS_UDM_CIAO_EXPORT_H */
