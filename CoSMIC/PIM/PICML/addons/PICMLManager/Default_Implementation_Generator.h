// -*- C++ -*-

///=============================================================================
/**
 * @file      Default_Implementation_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
#define _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_

#include "game/Folder.h"
#include "Default_Artifact_Generator.h"

namespace PICML
{
namespace MI
{

/**
 * @class Default_Implementation_Generator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class Default_Implementation_Generator
{
public:
  struct meta_info_t
  {
    std::string impl_folder_;

    std::string impl_folder_name_;

    std::string artifact_folder_;

    /// The container type for the implementation.
    std::string container_type_;

    std::string impl_type_;

    std::string type_ref_;

    std::string implements_type_;
  };

  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   * @param[in]       config      Configuration for the new component.
   */
  Default_Implementation_Generator (::GAME::Project project,
                                    const meta_info_t & info);

  /// Destructor.
  ~Default_Implementation_Generator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const Implementation_Configuration & config,
                 const GAME::Model_in type);

private:
  /// Target implementation folder.
  GAME::Folder impl_folder_;

  const meta_info_t & info_;

  /// Default artifact generator.
  Default_Artifact_Generator artifact_gen_;
};

}
}

#endif  // !defined _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
