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

#ifndef _CUTS_CONFIG_H_
#define _CUTS_CONFIG_H_

#if defined (__CUTS_INLINE__)
# define CUTS_INLINE inline
#else
# define CUTS_INLINE
#endif

#define CUTS_USERNAME                     "cuts"

#define CUTS_PASSWORD                     "cuts"

#define CUTS_DEFAULT_HOSTNAME             "localhost"

#define CUTS_DEFAULT_PORT                 3306

#define CUTS_DEFAULT_EVENT_COUNT          20

#define CUTS_EVENT_HANDLER_THREAD_COUNT   1

#define CUTS_UNKNOWN_TYPE                 1

#define CUTS_UNKNOWN_IMPL                 1

#define CUTS_DEFAULT_LOG_SIZE             50

#define CUTS_UNKNOWN_HOSTNAME             "unknown"
#define CUTS_UNKNOWN_IPADDR               "0.0.0.0"

#if defined (CUTS_HAS_DOXYGEN)
#include "config-doxygen.h"
#endif

#endif  // !defined _CUTS_CONFIG_H_
