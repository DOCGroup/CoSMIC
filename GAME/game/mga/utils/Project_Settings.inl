// $Id$

namespace GAME
{
namespace Mga
{

//
// Project_Settings
//
Project_Settings::Project_Settings (Project proj)
: project_ (proj)
{

}

//
// Project_Settings
//
GAME_INLINE
Project_Settings::
Project_Settings (Project project, const std::string & cache_loc)
: project_ (project),
  default_cache_loc_ (cache_loc)
{

}

//
// ~Project_Settings
//
GAME_INLINE
Project_Settings::~Project_Settings (void)
{

}

//
// global_default_output_directory
//
GAME_INLINE
std::string Project_Settings::
global_default_output_directory (void) const
{
  return this->default_output_directory ("");
}

//
// global_default_output_directory
//
GAME_INLINE
void Project_Settings::
global_default_output_directory (const std::string & dir)
{
  this->default_output_directory ("", dir);
}
}
}
