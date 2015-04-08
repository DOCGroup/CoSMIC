// -*- C++ -*-

//=============================================================================
/**
 * @file      Default_Artifact_Generator.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
#define _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_

#include "game/mga/Atom.h"
#include "game/mga/Project.h"

#include "PIM/PICML/ext/PICML/PICML.h"

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
  bool generate (const Implementation_Configuration & config, Component_in type);

  ImplementationArtifact svnt_artifact (void);

  ImplementationArtifact exec_artifact (void);

private:
  GAME::Mga::Model get_file (const GAME::Mga::Model_in type);

  /// The root folder for the project.
  ImplementationArtifacts artifact_folder_;

  /// The servant's artifact.
  ImplementationArtifact svnt_artifact_;

  /// The implementation's artifact.
  ImplementationArtifact impl_artifact_;
};

}
}

#endif  // !defined _PICML_MANAGER_DEFAULT_ARTIFACT_GENERATOR_H_
