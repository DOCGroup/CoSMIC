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

#ifndef _PICML_DEPLOYMENT_PLAN_CONFIGURATION_H_
#define _PICML_DEPLOYMENT_PLAN_CONFIGURATION_H_

#include "DeploymentPlan_Export.h"
#include <string>

/**
 * @class Configuration
 *
 * Configuration values for the deployment plan generator.
 */
class DeploymentPlan_Export Configuration
{
public:
  /// Default constructor.
  Configuration (void);

  /// The output location for the deployment plan.
  std::string output_;

  /// Disable optimizations.
  bool disable_optimize_;

  /// Generate constructs for the locality manager.
  bool has_locality_manager_;
};

#endif  // !defined _CONFIGURATION_H_
