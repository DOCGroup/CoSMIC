// -*- C++ -*-

//=============================================================================
/**
 * @file        BE_ImplementationArtifactGenerator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_BE_IMPLEMENTATION_ARTIFACT_GENERATOR_H_
#define _PICML_BE_IMPLEMENTATION_ARTIFACT_GENERATOR_H_

#include "PICML/PICML.h"
#include "BE_ComponentImplementationGenerator_export.h"

namespace PICML_BE
{
/**
 * @class ImplementationArtifactGenerator
 *
 * Backend logic for generating a component's default implementation.
 */
class PICML_BE_COMPONENTIMPLEMENTATIONGENERATOR_Export ImplementationArtifactGenerator :
  public PICML::Visitor
{
public:
  /// Default constructor.
  ImplementationArtifactGenerator (PICML::ImplementationArtifacts & artifact_folder);

  /// Destructor.
  virtual ~ImplementationArtifactGenerator (void);

  virtual void Visit_Component (const PICML::Component & component);

  const PICML::ImplementationArtifact & svnt_artifact (void) const;

  const PICML::ImplementationArtifact & impl_artifact (void) const;

private:
  /// Target folder for generating artifacts.
  PICML::ImplementationArtifacts & artifact_folder_;

  /// The servant artifact.
  PICML::ImplementationArtifact svnt_artifact_;

  /// The implementation artifact.
  PICML::ImplementationArtifact impl_artifact_;
};

}

#include "BE_ImplementationArtifactGenerator.inl"

#endif  // !defined _PICML_BE_COMPONENTIMPLEMENTATIONGENERATOR_H_
