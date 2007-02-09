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

#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include <string>

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
      use_naming_service_  (false),
      target_folder_ ("GUTS_DeploymentPlans"),
      target_model_ ("GUTS_DeploymentPlan"),
      create_ (false)
  {
  }

  /// Verbose flag.
  bool verbose_;

  /// Flag determining if GEMS is in the naming service
  bool use_naming_service_;

  /// Location of the GME model.
  std::string gme_connstr_;

  /// The target folder for the converted model.
  std::string target_folder_;

  /// The target model for the converted model.
  std::string target_model_;

  /// Create the target folder and model it does not exist.
  bool create_;
};

#endif  // !defined _CUTS_G2P_OPTIONS_H_
