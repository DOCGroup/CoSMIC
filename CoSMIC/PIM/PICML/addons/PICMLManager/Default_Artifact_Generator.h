// -*- C++ -*-

//=============================================================================
/**
 * @file      Default_Artifact_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
#define _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_

#include "game/Atom.h"
#include "game/Project.h"

namespace PICML
{
namespace MI
{

// Forward decl.
class Implementation_Configuration;

/**
 * @class Default_Artifact_Generator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class Default_Artifact_Generator
{
public:
  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   */
  Default_Artifact_Generator (::GAME::Project project, const std::string & folder);

  /// Destructor.
  ~Default_Artifact_Generator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const Implementation_Configuration & config,
                 const GAME::Model & type);

  const GAME::Atom & svnt_artifact (void) const;

  const GAME::Atom & exec_artifact (void) const;

private:
  std::string get_location_basename (const GAME::Model & type);

  /// The root folder for the project.
  GAME::Folder artifact_folder_;

  /// The servant's artifact.
  GAME::Atom svnt_artifact_;

  /// The implementation's artifact.
  GAME::Atom impl_artifact_;
};

}
}

#endif  // !defined _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
