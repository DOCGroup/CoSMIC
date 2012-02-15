// -*- C++ -*-

//=============================================================================
/**
 * @file       Export_File_Generator.h
 *
 * $Id$
 *
 * @author     James H. Hill
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_EXPORT_FILE_GENERATOR_H_
#define _EXTENSION_CLASSES_EXPORT_FILE_GENERATOR_H_

#include <set>
#include <string>
#include "game/mga/Project.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Export_File_Generator
 *
 * Utility class that is responsible for generating the top level
 * include file that includes all the header files for the objects
 * in the project.
 */
class Export_File_Generator
{
public:
  /// Default constructor.
  Export_File_Generator (void);

  /// Destructor.
  ~Export_File_Generator (void);

  /**
   * Generate both the workspace and project specification.
   *
   * @param[in]         location        Location of the generation
   * @param[in]         items           List of extension classes.
   */
  void generate (const std::string & location, const Project & proj);

};

}
}

#endif  // !defined _EXTENSION_CLASSES_TOP_LEVEL_FILE_GENERATOR_H_
