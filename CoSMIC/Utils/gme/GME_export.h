// -*- C++ -*-
// $Id$

#ifndef GME_EXPORT_H
#define GME_EXPORT_H

#if !defined (GME_HAS_DLL)
#  define GME_HAS_DLL 1
#endif /* ! GME_HAS_DLL */

#if defined (GME_HAS_DLL) && (GME_HAS_DLL == 1)
#  if defined (GME_BUILD_DLL)
#    define GME_Export __declspec (dllexport)
#  else /* GME_BUILD_DLL */
#    define GME_Export __declspec (dllimport)
#  endif /* GME_BUILD_DLL */
#else /* GME_HAS_DLL == 1 */
#  define GME_Export
#endif /* GME_HAS_DLL == 1 */

#if defined (__GME_INLINE__)
#define GME_INLINE inline
#else
#define GME_INLINE
#endif

#endif /* GME_EXPORT_H */
