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

#include "game/mga/Atom.h"
#include "game/mga/Project.h"

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
  Default_Artifact_Generator (::GAME::Mga::Project project, const std::string & folder);

  /// Destructor.
  ~Default_Artifact_Generator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const Implementation_Configuration & config,
                 const GAME::Mga::Model_in type);

  GAME::Mga::Atom svnt_artifact (void);

  GAME::Mga::Atom exec_artifact (void);

private:
  std::string get_location_basename (const GAME::Mga::Model_in type);

  GAME::Mga::Model get_file (const GAME::Mga::Model_in type);

  /// The root folder for the project.
  GAME::Mga::Folder artifact_folder_;

  /// The servant's artifact.
  GAME::Mga::Atom svnt_artifact_;

  /// The implementation's artifact.
  GAME::Mga::Atom impl_artifact_;
};

}
}

#endif  // !defined _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_