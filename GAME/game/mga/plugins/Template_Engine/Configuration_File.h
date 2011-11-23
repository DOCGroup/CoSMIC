// -*- C++ -*-

//=============================================================================
/**
 * @file        Configuration_File.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_CONFIGURATION_FILE_H_
#define _TEMPLATE_ENGINE_CONFIGURATION_FILE_H_

#include "parser/Property_Configuration.hpp"
#include "Template_Engine_export.h"

/**
 * @class Configuration_File
 *
 * Utility class for parsing the contents of a configuration file.
 */
class GAME_TEMPLATE_ENGINE_Export Configuration_File
{
public:
  /**
   * Read the contents of the configuration file. This will
   * append all new configurations to the property configuration
   * map object. It the configuration already exists, then it
   * will replace it the existing one with the one.
   */
  static bool read (const std::string & file, Property_Configuration_Map & pcm);
};

#endif  // !defined _TEMPLATE_ENGINE_CONFIGURATION_FILE_H_
