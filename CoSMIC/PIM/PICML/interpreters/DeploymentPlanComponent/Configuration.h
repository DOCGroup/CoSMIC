// -*- C++ -*-

//=============================================================================
/**
 * @file        Configuration.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

/**
 * @struct Configuration
 *
 * Configuration values for the deployment plan generator.
 */
struct Configuration
{
  /// Default constructor.
  Configuration (void)
    : disable_optimize_ (0)
  {

  }

  CString output_path_;

  int disable_optimize_;
};

#endif  // !defined _CONFIGURATION_H_
