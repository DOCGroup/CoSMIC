// -*- C++ -*-

///=============================================================================
/**
 * @file      DefaultImplementationGenerator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
#define _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_

#include "game/Folder.h"
#include "DefaultArtifactGenerator.h"

/**
 * @class DefaultImplementationGenerator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class DefaultImplementationGenerator
{
public:
  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   */
  DefaultImplementationGenerator (const GME::Folder & root);

  /// Destructor.
  ~DefaultImplementationGenerator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const GME::Model & component);

private:
  std::string fq_type (const GME::Model & component,
                       const std::string & separator);

  /// Folder that contains the implementations.
  GME::Folder impls_;

  /// Default artifact generator.
  DefaultArtifactGenerator artifact_gen_;
};

#endif  // !defined _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
