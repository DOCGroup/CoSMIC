// -*- C++ -*-

//=============================================================================
/**
 * @file      Artifact_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_ARTIFACT_GENERATOR_H_
#define _IDL_TO_PICML_ARTIFACT_GENERATOR_H_

#include "game/xme/Folder.h"

/**
 * @class Artifact_Generator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class Artifact_Generator
{
public:
  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   */
  Artifact_Generator (GAME::XME::Folder & root);

  /// Destructor.
  ~Artifact_Generator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const GAME::XME::Model & component);

  const GAME::XME::Atom & svnt_artifact (void) const;

  const GAME::XME::Atom & exec_artifact (void) const;

private:
  /// Folder that contains the artifacts.
  GAME::XME::Folder artifacts_;

  /// The servant's artifact.
  GAME::XME::Atom svnt_artifact_;

  /// The implementation's artifact.
  GAME::XME::Atom impl_artifact_;
};

#include "Artifact_Generator.inl"

#endif  // !defined _IDL_TO_PICML_ARTIFACT_GENERATOR_H_
