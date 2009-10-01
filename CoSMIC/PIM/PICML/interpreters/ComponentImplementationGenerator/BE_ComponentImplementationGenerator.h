// -*- C++ -*-

//=============================================================================
/**
 * @file        BE_ComponentImplementationGenerator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_
#define _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_

#include "PICML/PICML.h"
#include "BE_ImplementationArtifactGenerator.h"

namespace PICML_BE
{
/**
 * @class PICML_BE_ComponentImplementationGenerator
 *
 * Backend logic for generating a component's default implementation.
 */
class PICML_BE_COMPONENTIMPLEMENTATIONGENERATOR_Export ComponentImplementationGenerator :
  public PICML::Visitor
{
public:
  /// Default constructor.
  ComponentImplementationGenerator (PICML::ComponentImplementations & impl_folder,
                                    PICML::ImplementationArtifacts & artifact_folder);

  /// Destructor.
  virtual ~ComponentImplementationGenerator (void);

  /// Visit a Component element.
  virtual void Visit_Component (const PICML::Component & component);

private:
  /// Target folder for generating implementations.
  PICML::ComponentImplementations & impl_folder_;

  /// The current component implementation.
  PICML::MonolithicImplementation impl_;

  /// Generator for the artifacts.
  PICML_BE::ImplementationArtifactGenerator artifact_generator_;
};

}

#endif  // !defined _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_
