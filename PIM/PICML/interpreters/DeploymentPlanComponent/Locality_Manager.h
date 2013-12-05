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

/**
 * @class Locality_Manager
 *
 * Helper class that is responsible for generating locality manager
 * tags to the deployment plan.
 */
class Locality_Manager
{
public:
  static void generate_default_artifacts (xercesc::DOMElement * parent);

  static void generate_default_implementation (xercesc::DOMElement * parent);

  static void generate_default_instance_configs (xercesc::DOMElement * parent,
                                                 const PICML::CollocationGroup & group);

  static const GAME::Xml::String DEFAULT_ARTIFACT_ID;
  static const GAME::Xml::String DEFAULT_ARTIFACT_NAME;

  static const GAME::Xml::String DEFAULT_IMPLEMENTATION_ID;
  static const GAME::Xml::String DEFAULT_IMPLEMENTATION_NAME;
};

#endif  // !defined _PICML_DEPLOYMENT_LOCALITY_MANAGER_H_
