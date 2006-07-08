// $Id$

#include "CUTS_Project.h"
#include "UDM_Utility_T.h"

//
// instance_
//
CUTS_Project * CUTS_Project::instance_ = 0;

//
// instance
//
CUTS_Project * CUTS_Project::instance (void)
{
  if (CUTS_Project::instance_ == 0)
    CUTS_Project::instance_ = new CUTS_Project ();
  return CUTS_Project::instance_;
}

//
// close
//
void CUTS_Project::close (void)
{
  if (CUTS_Project::instance_ != 0)
  {
    delete CUTS_Project::instance_;
    CUTS_Project::instance_ = 0;
  }
}

//
// CUTS_Project
//
CUTS_Project::CUTS_Project (void)
: valid_ (false),
  message_ ("project has not been initialized")
{

}

//
// ~CUTS_Project
//
CUTS_Project::~CUTS_Project (void)
{

}

//
// message
//
const std::string & CUTS_Project::message (void) const
{
  return this->message_;
}

//
// get_testing_service
//
const PICML::Object & CUTS_Project::get_testing_service (void) const
{
  return this->testing_service_;
}

//
// is_valid
//
bool CUTS_Project::is_valid (void) const
{
  return this->valid_;
}

//
// Visit_RootFolder
//
void CUTS_Project::Visit_RootFolder (const PICML::RootFolder & root)
{
  this->valid_ = true;

  typedef std::vector <PICML::InterfaceDefinitions> IDefs_Set;
  IDefs_Set idefs = root.InterfaceDefinitions_children ();

  IDefs_Set::iterator idef_iter =
    std::find_if (idefs.begin (),
                  idefs.end (),
                  Find_Element_By_Name <PICML::InterfaceDefinitions> (
                  "CUTS_InterfaceDefinitions"));

  if (idef_iter == idefs.end ())
  {
    this->message_ =
      "Cannot locate CUTS_InterfaceDefinitions folder. "
      "Please verify that CUTS.xme has been imported.";
    this->valid_ = false;
  }
  else
  {
    idef_iter->Accept (*this);
    if (this->valid_)
      this->message_.clear ();
  }
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Project::Visit_InterfaceDefinitions (
  const PICML::InterfaceDefinitions & idefs)
{
  if (!this->valid_)
    return;

  typedef std::vector <PICML::File> File_Set;
  File_Set files = idefs.File_children ();

  File_Set::iterator file_iter =
    std::find_if (files.begin (),
                  files.end (),
                  Find_Element_By_Name <PICML::File> (
                  "cuts/CUTS"));

  if (file_iter == files.end ())
  {
    this->message_ =
      "Cannot locate cuts/CUTS file. Please verify that "
      "CUTS.xme has been imported.";
    this->valid_ = false;
  }
  else
  {
    this->cuts_file_ = *file_iter;
    file_iter->Accept (*this);
  }
}

//
// Visit_Package
//
void CUTS_Project::Visit_File (const PICML::File & file)
{
  if (!this->valid_)
    return;

  typedef std::vector <PICML::Package> Package_Set;
  Package_Set packages = file.Package_children ();

  Package_Set::iterator package_iter =
    std::find_if (packages.begin (),
                  packages.end (),
                  Find_Element_By_Name <PICML::Package> (
                  "CUTS"));

  if (package_iter == packages.end ())
  {
    this->message_ =
      "CUTS package does not exist in cuts/CUTS. "
      "Please verify that CUTS.xme has been imported.";
    this->valid_ = false;
  }
  else
    package_iter->Accept (*this);
}

//
// Visit_Package
//
void CUTS_Project::Visit_Package (const PICML::Package & package)
{
  if (!this->valid_)
    return;

  typedef std::vector <PICML::Object> Object_Set;
  Object_Set objects = package.Object_kind_children ();

  Object_Set::iterator object_iter =
    std::find_if (objects.begin (),
                  objects.end (),
                  Find_Element_By_Name <PICML::Object> (
                  "Testing_Service"));

  if (object_iter == objects.end ())
  {
    this->message_ =
      "Cannot locate Testing_Service object in "
      "cuts/CUTS::CUTS. Please verify that CUTS.xme "
      "has been imported.";
    this->valid_ = false;
  }
  else
    this->testing_service_ = *object_iter;
}

//
// get_cuts_file
//
const PICML::File & CUTS_Project::get_cuts_file (void) const
{
  return this->cuts_file_;
}
