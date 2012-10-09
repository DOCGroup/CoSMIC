// -*- C++ -*-

//=============================================================================
/**
 * @file      Impl_Factory_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_IMPL_FACTORY_GENERATOR_H_
#define _EXTENSION_CLASSES_IMPL_FACTORY_GENERATOR_H_

#include <set>
#include <string>
#include <fstream>

#include "game/mga/GME_fwd.h"

// Forward decl.
class Object_Manager;

namespace GAME
{
namespace Mga
{
/**
 * @class Impl_Factory_Generator
 *
 * Utility class that is responsible for generating the MPC project
 * specification for the set of provided objects. It is assumed that
 * the provide objects all have source files within the specified
 * location.
 */
class Impl_Factory_Generator
{
public:
  /// Default constructor.
  Impl_Factory_Generator (void);

  /// Destructor.
  virtual ~Impl_Factory_Generator (void);

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

private:
  // Helper method for generating the source files.
  void generate_source_files (const Project &, const Object_Manager * obj_mgr);

  /// The header file for the visitor.
  std::ofstream hxx_file_;

  /// The source file for the visitor.
  std::ofstream cxx_file_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_
