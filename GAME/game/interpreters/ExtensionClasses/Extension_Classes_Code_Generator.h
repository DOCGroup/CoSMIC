// -*- C++ -*-

//=============================================================================
/**
 * @file      Extension_Classes_Code_Generator.h
 *
 * $Id: Extension_Classes_Code_Generator.h 2220 2010-06-07 17:27:27Z alhad $
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_CODE_GENERATOR_H_
#define _EXTENSION_CLASSES_CODE_GENERATOR_H_

#include <algorithm>
#include <cstdio>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "boost/bind.hpp"

#include "Attribute.h"
#include "MetaFCO.h"

namespace GAME
{
/**
 * @class Extension_Classes_Code_Generator
 */
class Extension_Classes_Code_Generator
{
public:
  Extension_Classes_Code_Generator (std::string fname,
                                    std::string mname,
                                    std::string fpath,
                                    std::string uc_paradigm_name,
                                    std::string inner_location);

  ~Extension_Classes_Code_Generator (void);

  void generate_default_functions (std::string prefix_symbol,
                                   std::string params,
                                   std::string parent_cons);

  void generate_narrow (void);

  void generate_create (void);

  void add_includes (std::string name);

  void add_inherited_class (std::string name);

  void generate_connector_connections (std::string name);

  void generate_connection_end (std::string role_name,
                                std::string name);

  void generate_h_file (void);

  void generate_cpp_file (void);

  void generate_attribute_list (GAME::FCO fco);

  std::string generate_function_comments_header (std::string name);

  void set_inheritance_flag (void);

private:
  std::ofstream out_;

  std::string uc_paradigm_name_;

  std::string inner_location_;

  std::stringstream member_variables_;

  std::stringstream default_member_functions_h_;

  std::stringstream default_member_functions_cpp_;

  std::stringstream member_functions_h_;

  std::stringstream member_functions_cpp_;

  std::stringstream inherited_classes_;

  std::stringstream classes_includes_;

  std::stringstream cpp_includes_;

  std::stringstream forward_declerations_;

  std::string indentation_h_;

  std::string indentation_cpp_;

  std::string class_name_;

  std::string meta_name_;

  std::string path_;

  bool done_inheriting_;

  bool has_attribute_;

  bool is_in_connections_;
};

}

#endif
