// $Id$

//
// Project_Settings
//
GME_INLINE
GME::Utils::Project_Settings::
Project_Settings (const GME::Project & proj)
: project_ (proj),
  default_cache_loc_ ("__OutputDir__/")
{

}

//
// ~Project_Settings
//
GME_INLINE
GME::Utils::Project_Settings::~Project_Settings (void)
{

}

//
// global_default_output_directory
//
GME_INLINE
std::string GME::Utils::Project_Settings::
global_default_output_directory (void) const
{
  return this->default_output_directory ("");
}

//
// global_default_output_directory
//
GME_INLINE
void GME::Utils::Project_Settings::
global_default_output_directory (const std::string & dir)
{
  this->default_output_directory ("", dir);
}
