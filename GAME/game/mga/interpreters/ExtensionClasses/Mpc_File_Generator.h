// -*- C++ -*-

//=============================================================================
/**
 * @file      Parent_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_
#define _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_

#include <set>
#include <string>
#include "game/mga/GME_fwd.h"

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
class Mpc_File_Generator
{
public:
  /// Default constructor.
  Mpc_File_Generator (void);

  /// Destructor.
  virtual ~Mpc_File_Generator (void);

  /**
   * Generate both the workspace and project specification.
   *
   * @param[in]         location        Location of the generation
   * @param[in]         items           List of extension classes.
   */
  bool generate (const std::string & location,
                 const Project & proj,
                 const std::string & pch_basename,
                 const Object_Manager * obj_mgr);
};

}
}

#endif  // !defined _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_
