// $Id$

#include "CUTS_Project.h"
#include "UDM_Utility_T.h"

// Static decl.
static const std::string CUTS_INTERFACE_DEFS ("CUTS_InterfaceDefinitions");

static const std::string CUTS_PREDEFINED_TYPES ("CUTS_PredefinedTypes");

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
// get_testing_service
//
const PICML::String & CUTS_Project::get_string_type (void) const
{
  return this->string_;
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

  // Get the <CUTS_InterfaceDefinitions> folder. If we cannot
  // locate it, then we will create a new one.
  PICML::InterfaceDefinitions cuts_idefs;
  if (create_element_if_not_exist (idefs,
                                   Find_Element_By_Name <
                                   PICML::InterfaceDefinitions> (
                                   CUTS_INTERFACE_DEFS),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   cuts_idefs))
  {
    cuts_idefs.name () = CUTS_INTERFACE_DEFS;
  }

  cuts_idefs.Accept (*this);

  typedef std::vector <PICML::PredefinedTypes> PredefinedTypes_Set;
  PredefinedTypes_Set type_set = root.PredefinedTypes_children ();

  // Get the <CUTS_PredefinedTypes> folder. If we cannot
  // locate it, then we will create a new one.
  PICML::PredefinedTypes predefined_types;
  if (create_element_if_not_exist (type_set,
                                   Find_Element_By_Name <
                                   PICML::PredefinedTypes> (
                                   CUTS_PREDEFINED_TYPES),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   predefined_types))
  {
    predefined_types.name () = CUTS_PREDEFINED_TYPES;
  }

  predefined_types.Accept (*this);
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Project::Visit_InterfaceDefinitions (
  const PICML::InterfaceDefinitions & idefs)
{
  typedef std::vector <PICML::File> File_Set;
  File_Set files = idefs.File_children ();

  if (create_element_if_not_exist (files,
                                   Find_Element_By_Name <PICML::File> (
                                   "cuts/CUTS"),
                                   idefs,
                                   Udm::NULLCHILDROLE,
                                   this->cuts_file_))
  {
    this->cuts_file_.name () = "cuts/CUTS";
  }

  this->cuts_file_.Accept (*this);
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Project::Visit_PredefinedTypes (
  const PICML::PredefinedTypes & predefined_types)
{
  typedef std::vector <PICML::String> String_Set;
  String_Set strings = predefined_types.String_kind_children ();

  if (strings.empty ())
  {
    this->string_ = PICML::String::Create (predefined_types, Udm::NULLCHILDROLE);
    this->string_.name () = "string";
  }
  else
  {
    this->string_ = strings[0];
  }
}

//
// Visit_Package
//
void CUTS_Project::Visit_File (const PICML::File & file)
{
  typedef std::vector <PICML::Package> Package_Set;
  Package_Set packages = file.Package_children ();

  PICML::Package package;
  if (create_element_if_not_exist (packages,
                                   Find_Element_By_Name <PICML::Package> (
                                   "CUTS"),
                                   file,
                                   Udm::NULLCHILDROLE,
                                   package))
  {
    package.name () = "CUTS";
  }

  package.Accept (*this);
}

//
// Visit_Package
//
void CUTS_Project::Visit_Package (const PICML::Package & package)
{
  typedef std::vector <PICML::Object> Object_Set;
  Object_Set objects = package.Object_kind_children ();

  if (create_element_if_not_exist (objects,
                                   Find_Element_By_Name <PICML::Object> (
                                   "Testing_Service"),
                                   package,
                                   Udm::NULLCHILDROLE,
                                   this->testing_service_))
  {
    this->testing_service_.name () = "Testing_Service";
  }
}

//
// get_cuts_file
//
const PICML::File & CUTS_Project::get_cuts_file (void) const
{
  return this->cuts_file_;
}
