// -*- C++ -*-

//=============================================================================
/**
 * @file      Extension_Classes_Build_Files_Generator.h
 *
 * $Id: Extension_Classes_Build_Files_Generator.h 2220 2010-06-07 17:27:27Z alhad $
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_BUILD_FILES_GENERATOR_H_
#define _EXTENSION_CLASSES_BUILD_FILES_GENERATOR_H_

#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Object.h"
#include "Folder.h"

namespace GAME
{
/**
 * @class Extension_Classes_Build_Files_Generator
 */
class Extension_Classes_Build_Files_Generator
{
public:
  Extension_Classes_Build_Files_Generator (const GAME::Folder &,
                                           std::set <GAME::Object>,
                                           std::string,
                                           std::string,
                                           std::string);
  
  ~Extension_Classes_Build_Files_Generator (void);
  
  void generate_mwc_file (void);
  
  void generate_mpc_file (void);

  void generate_stdafx_files (void);

  void generate_stdafx_header_preamble (void);
  
private:
  GAME::Folder root_;

  std::set <GAME::Object> objects_;
  
  std::string output_;

  std::string uc_paradigm_name_;

  std::string filename_;

  std::ofstream out_;
};

}

#endif
