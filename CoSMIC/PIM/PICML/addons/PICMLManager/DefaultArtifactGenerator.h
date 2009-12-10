// -*- C++ -*-

//=============================================================================
/**
 * @file      DefaultArtifactGenerator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
#define _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_

#include "game/Folder.h"
#include "game/Atom.h"

// Forward decl.
class NewComponentConfig;

/**
 * @class DefaultArtifactGenerator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class DefaultArtifactGenerator
{
public:
  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   */
  DefaultArtifactGenerator (const GME::Folder & root,
                            const NewComponentConfig & config);

  /// Destructor.
  ~DefaultArtifactGenerator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const GME::Model & component);

  const GME::Atom & svnt_artifact (void) const;

  const GME::Atom & exec_artifact (void) const;

private:
  /// Folder that contains the artifacts.
  GME::Folder artifacts_;

  /// The servant's artifact.
  GME::Atom svnt_artifact_;

  /// The implementation's artifact.
  GME::Atom impl_artifact_;

  /// Configuration for the new component.
  const NewComponentConfig & config_;
};

#endif  // !defined _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
