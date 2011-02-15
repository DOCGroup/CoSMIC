// -*- C++ -*-

//=============================================================================
/**
 * @file      Pch_File_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_PCH_FILE_GENERATOR_H_
#define _EXTENSION_CLASSES_PCH_FILE_GENERATOR_H_

#include <set>
#include <string>
#include "game/mga/GME_fwd.h"

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
class Pch_File_Generator
{
public:
  /// Default constructor.
  Pch_File_Generator (void);

  /// Destructor.
  virtual ~Pch_File_Generator (void);

  /**
   * Generate the precompiled header file. The client is able to
   * control the name of the precompiled header file.
   *
   * @param[in]         location        Location of the generation
   * @param[in]         items           List of extension classes.
   */
  bool generate (const std::string & location,
                 const Project & proj,
                 const std::string & basename);

private:
  bool generate_pch_header (const std::string & filename);

  bool generate_pch_source (const std::string & filename,
                            const std::string & basename);
};

}
}

#endif  // !defined _EXTENSION_CLASSES_MPC_FILE_GENERATOR_H_
