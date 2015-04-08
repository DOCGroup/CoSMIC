// -*- C++ -*-

//=============================================================================
/**
 * @file        BE_ComponentImplementationGenerator.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_
#define _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"

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
  ComponentImplementationGenerator (PICML::ComponentImplementations_in impl_folder,
                                    PICML::ImplementationArtifacts_in artifact_folder);

  /// Destructor.
  virtual ~ComponentImplementationGenerator (void);

  /// Visit a Component element.
  virtual void visit_Component (PICML::Component_in component);

private:
  /// Helper method for getting the scope of a named type.
  static std::string fq_type (PICML::NamedType_in type, const std::string & separator);

  /// Target folder for generating implementations.
  PICML::ComponentImplementations impl_folder_;

  /// The current component implementation.
  PICML::MonolithicImplementation impl_;

  /// Generator for the artifacts.
  PICML_BE::ImplementationArtifactGenerator artifact_generator_;
};

}

#endif  // !defined _PICML_BE_COMPONENT_IMPLEMENTATION_GENERATOR_H_
