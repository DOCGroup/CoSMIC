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

// Forward decl.
class DefaultArtifactGenerator;

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
   * @param[in]       config      Configuration for the new component.
   */
  DefaultImplementationGenerator (const DefaultArtifactGenerator & artifact_gen, 
                                  GAME::Folder & folder);

  /// Destructor.
  ~DefaultImplementationGenerator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const GAME::Model & component);

private:
  /// Default artifact generator.
  const DefaultArtifactGenerator & artifact_gen_;

  GAME::Folder & folder_;
};

#endif  // !defined _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
