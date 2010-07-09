// $Id$

#include "stdafx.h"
#include "Project_Settings.h"

#if !defined (__GAME_INLINE__)
#include "Project_Settings.inl"
#endif

#include "game/Exception.h"
#include "game/Project.h"

#include <algorithm>
#include <sstream>

namespace GAME
{
namespace utils
{
//
// default_output_directory
//
std::string Project_Settings::
default_output_directory (const std::string & uid) const
{
  // Get the root folder for the project.
  GAME::Folder root = this->project_.root_folder ();

  // Construct the registry path for the directory.
  std::string path (this->default_cache_loc_);
  path.append (uid);

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  return root.registry_value (path);
}

//
// default_output_directory
//
void Project_Settings::
default_output_directory (const std::string & uid, const std::string & dir)
{
  // Get the root folder for the project.
  GAME::Folder root = this->project_.root_folder ();

  // Construct the registry path for the directory.
  std::string path (this->default_cache_loc_);
  path.append (uid);

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  root.registry_value (path, dir);
}
}
}
