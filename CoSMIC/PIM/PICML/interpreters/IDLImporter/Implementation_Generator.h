// -*- C++ -*-

///=============================================================================
/**
 * @file      Implementation_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_IMPLEMENTATION_GENERATOR_H_
#define _IDL_TO_PICML_IMPLEMENTATION_GENERATOR_H_

#include "game/xme/Folder.h"
#include "Artifact_Generator.h"

/**
 * @class Implementation_Generator
 *
 * Helper class that generates the default monolithic implementation
 * elments for a component.
 */
class Implementation_Generator
{
public:
  /**
   * Initializing constuctor
   *
   * @param[in]       root        Root folder for the project
   * @param[in]       config      Configuration for the new component.
   */
  Implementation_Generator (GAME::XME::Folder & root);

  /// Destructor.
  ~Implementation_Generator (void);

  /**
   * Generate the implementration for the specified component.
   *
   * @param[in]       component         Compent
   */
  bool generate (const GAME::XME::Model & component);

private:
  void generate_impl (GAME::XME::Model & container,
                      const GAME::XME::FCO & impl,
                      const ::Utils::XStr & fq_type);

  void generate_servant (GAME::XME::Model & container,
                         const GAME::XME::FCO & impl,
                         const ::Utils::XStr & fq_type);

  /// Folder that contains the implementations.
  GAME::XME::Folder impls_;

  /// Default artifact generator.
  Artifact_Generator artifact_gen_;
};

#endif  // !defined _PICML_MANAGER_DEFAULT_IMPLEMENTATION_GENERATOR_H_
