// -*- C++ -*-

//=============================================================================
/**
 * @file      Fwd_Decl_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_FWD_DECL_GENERATOR_H_
#define _EXTENSION_CLASSES_FWD_DECL_GENERATOR_H_

#include <set>
#include <string>
#include "game/mga/GME_fwd.h"

// Forward decl.
class Object_Manager;

namespace GAME
{
namespace Mga
{
/**
 * @class Mpc_File_Generator
 *
 * Utility class that is responsible for generating the MPC project
 * specification for the set of provided objects. It is assumed that
 * the provide objects all have source files within the specified
 * location.
 */
class Fwd_Decl_Generator
{
public:
  /// Default constructor.
  Fwd_Decl_Generator (void);

  /// Destructor.
  virtual ~Fwd_Decl_Generator (void);

  /**
   * Generate both the workspace and project specification.
   *
   * @param[in]         location        Location of the generation
   * @param[in]         items           List of extension classes.
   */
  bool generate (const std::string & location,
                 const Project & proj,
                 const Object_Manager * obj_mgr);
};

}
}

#endif
