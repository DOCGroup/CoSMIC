// -*- C++ -*-

//=============================================================================
/**
 * @file      Client_Options.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BDC_CLIENT_OPTIONS_H_
#define _CUTS_BDC_CLIENT_OPTIONS_H_

struct CUTS_BDC_Client_Options
{
  /// Flag for listing the services currently loaded
  /// into the service manager.
  bool list_svcs_;

  /// Verbose flag for the application
  bool verbose_;
};

#endif  // !defined _CUTS_BDC_CLIENT_OPTIONS_H_
