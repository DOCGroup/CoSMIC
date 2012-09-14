// $Id$

#include "stdafx.h"
#include "Project_Settings.h"

#if !defined (__GAME_INLINE__)
#include "Project_Settings.inl"
#endif

#include "game/mga/Exception.h"
#include "game/mga/Project.h"

#include <algorithm>
#include <sstream>

namespace GAME
{
namespace Mga
{

//
// default_output_directory
//
std::string Project_Settings::
default_output_directory (const std::string & uid) const
{
  // Get the root folder for the project.
  Folder root = this->project_.root_folder ();
  std::string path = this->default_cache_loc_ + "/" + uid;

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  return root->registry_value (path);
}

//
// default_output_directory
//
void Project_Settings::
default_output_directory (const std::string & uid, const std::string & dir)
{
  // Get the root folder for the project.
  Folder root = this->project_.root_folder ();
  std::string path = this->default_cache_loc_ + "/" + uid;

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  root->registry_value (path, dir);
}

//
// set_boolean_value
//
bool Project_Settings::
set_value (const std::string & path, bool value)
{
  const std::string str_value = value ? "true" : "false";
  return this->set_value (path, str_value);
}

//
// get_boolean_value
//
bool Project_Settings::
get_value (const std::string & path, bool & value)
{
  std::string str_value;
  if (!this->get_value (path, str_value))
    return false;

  value = (str_value == "true" || str_value == "1") ? true : false;
  return true;
}

//
// set_string_value
//
bool Project_Settings::
set_value (const std::string & path, const std::string & value)
{
  // Get the root folder for the project.
  Folder root = this->project_.root_folder ();

  // Construct the registry value path and set its value.
  std::string fullpath = this->default_cache_loc_ + "/" + path;
  root->registry_value (fullpath, value);

  return true;
}

//
// get_string_value
//
bool Project_Settings::
get_value (const std::string & path, std::string & value)
{
  // Get the root folder for the project.
  Folder root = this->project_.root_folder ();

  // Construct the registry value path and set its value.
  std::string fullpath = this->default_cache_loc_ + "/" + path;
  value = root->registry_value (fullpath);

  return true;
}

}
}
