// -*- C++ -*-

//=============================================================================
/**
 * @file      Locality_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENT_LOCALITY_MANAGER_H_
#define _PICML_DEPLOYMENT_LOCALITY_MANAGER_H_

#include "game/xml/Fragment.h"
#include "PICML/PICML.h"

namespace PICML
{
namespace Deployment
{

/**
 * @class Locality_Manager
 *
 * Helper class that is responsible for generating locality manager
 * tags to the deployment plan.
 */
class Locality_Manager
{
public:
  static void generate_default_artifacts (GAME::Xml::Fragment parent);
  static void generate_default_implementation (GAME::Xml::Fragment parent);
  static void generate_default_instance_configs (GAME::Xml::Fragment parent, PICML::CollocationGroup_in group);

  static const std::string DEFAULT_ARTIFACT_ID;
  static const std::string DEFAULT_ARTIFACT_NAME;

  static const std::string DEFAULT_IMPLEMENTATION_ID;
  static const std::string DEFAULT_IMPLEMENTATION_NAME;
};

}
}

#endif  // !defined _PICML_DEPLOYMENT_LOCALITY_MANAGER_H_
