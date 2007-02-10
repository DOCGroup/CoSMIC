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

#include <string>
#include <list>
#include <utility>

//=============================================================================
/**
 * @struct CUTS_G2P_Options
 */
//=============================================================================

struct CUTS_G2P_Options
{
  /// Default constructor.
  CUTS_G2P_Options (void);

  /**
   * Insert a new parameter into the list.
   *
   * @param[in]     param      The name=value pair.
   */
  int insert_param (char * param);

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

  /// Run the following component.
  std::string run_component_;

  /// Listing of parameters for the component.
  typedef std::list <std::pair <std::string, std::string> > Parameter_List;

  Parameter_List params_;
};

#endif  // !defined _CUTS_G2P_OPTIONS_H_
