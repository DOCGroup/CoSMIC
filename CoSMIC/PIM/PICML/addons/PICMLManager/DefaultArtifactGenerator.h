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
  DefaultArtifactGenerator (const GME::Folder & root);

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
  /// Helper method to generate the fully qualified typename.
  std::string fq_type (const GME::Model & component, const std::string & separator);

  /// Folder that contains the artifacts.
  GME::Folder artifacts_;

  /// The servant's artifact.
  GME::Atom svnt_artifact_;

  /// The implementation's artifact.
  GME::Atom impl_artifact_;
};

#endif  // !defined _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
