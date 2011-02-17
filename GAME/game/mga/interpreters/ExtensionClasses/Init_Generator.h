// -*- C++ -*-

//=============================================================================
/**
 * @file      Init_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_INIT_GENERATOR_H_
#define _EXTENSION_CLASSES_INIT_GENERATOR_H_

#include <set>
#include <string>
#include <fstream>

#include "game/mga/GME_fwd.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Init_Generator
 */
class Init_Generator
{
public:
  /// Default constructor.
  Init_Generator (void);

  /// Destructor.
  virtual ~Init_Generator (void);

  /**
   * Generate both the workspace and project specification.
   *
   * @param[in]         location        Location of the generation
   * @param[in]         items           List of extension classes.
   */
  bool generate (const std::string & location,
                 const Project & proj,
                 const std::string & pch_basename);

private:
  // Helper method for generating the source files.
  void generate_source_file (const Project & proj);

  /// The source file for the visitor.
  std::ofstream cxx_file_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_
