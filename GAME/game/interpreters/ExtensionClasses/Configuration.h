// -*- C++ -*-

//=============================================================================
/**
 * @file        Configuration.h
 *
 * $Id: Configuration.h 2505 2010-09-11 16:33:15Z hillj $
 *
 * @author      Alhad Mokashi
 */
//=============================================================================

#ifndef _GAME_EXTENSION_CLASSES_CONFIGURATION_H_
#define _GAME_EXTENSION_CLASSES_CONFIGURATION_H_

#include "ExtensionClasses_export.h"
#include <string>

/**
 * @class Configuration
 *
 * Configuration values for the deployment plan generator.
 */
class Configuration
{
public:
  /// Default constructor.
  Configuration (void): disable_optimize_ (false){}

  /// The output location for the deployment plan.
  std::string output_;

  /// Disable optimizations.
  bool disable_optimize_;

};

#endif  // !defined _CONFIGURATION_H_
