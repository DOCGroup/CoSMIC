// -*- C++ -*-

//=============================================================================
/**
 * @file      G2P_Options.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_G2P_OPTIONS_H_
#define _CUTS_G2P_OPTIONS_H_

#include "ace/SString.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"

//=============================================================================
/**
 * @struct CUTS_G2P_Options
 */
//=============================================================================

struct CUTS_G2P_Options
{
  /// Default constructor.
  CUTS_G2P_Options (void)
    : verbose_ (false),
      use_naming_service_  (false)
  {
  }

  /// Verbose flag.
  bool verbose_;

  /// Flag determining if GEMS is in the naming service
  bool use_naming_service_;

  /// Location of the GME model.
  ACE_CString gme_connstr_;
};

#endif  // !defined _CUTS_G2P_OPTIONS_H_
