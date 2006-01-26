// -*- C++ -*-

//=============================================================================
/**
 * @file    CUTS.h
 *
 * $Id$
 *
 * This files contains macro definitions that are global to the CUTS
 * module, such as exporting and importing objects
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_H_
#define _CUTS_H_

#include "cuts/CUTS_Export.h"

#if defined (__CUTS_INLINE__)
# define CUTS_INLINE inline
#else
# define CUTS_INLINE
#endif

#define CUTS_USERNAME           "wlg"
#define CUTS_PASSWORD           "mdc"
#define CUTS_DEFAULT_HOSTNAME   "localhost"
#define CUTS_DEFAULT_PORT       3306

#endif  // !defined _CUTS_H_
