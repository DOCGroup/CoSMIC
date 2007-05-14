// $Id$

#include "CUTS_Project.h"
#include "modelgen.h"
#include "boost/bind.hpp"
#include <functional>

// Static decl.
static const char * CUTS_INTERFACE_DEFS = "CUTS_InterfaceDefinitions";

// Static decl.
static const char * CUTS_PREDEFINED_TYPES = "CUTS_PredefinedTypes";

// Static decl.
static const char * CUTS_IDL_FILENAME = "cuts/CUTS";

// Static decl.
static const char * CUTS_PACKAGE_NAME = "CUTS";

// Static decl.
static const char * CUTS_TESTING_SERVICE_OBJECT = "Testing_Service";

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
void CUTS_Project::
Visit_RootFolder (const PICML::RootFolder & root)
{
  this->valid_ = true;

  // Get the <CUTS_InterfaceDefinitions> folder. If we cannot
  // locate it, then we will create a new one.
  PICML::InterfaceDefinitions cutsidefs;

  if (Udm::create_if_not (root, cutsidefs,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                                  CUTS_INTERFACE_DEFS,
                                  boost::bind (&PICML::InterfaceDefinitions::name, _1)))))
  {
    cutsidefs.SetStrValue ("name", CUTS_INTERFACE_DEFS);
  }

  cutsidefs.Accept (*this);

  // Get the CUTS_PredefinedTypes folder. If we cannot locate it, then we
  // will create a new one.
  PICML::PredefinedTypes ptypes;

  if (Udm::create_if_not (root, ptypes,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                                  CUTS_PREDEFINED_TYPES,
                                  boost::bind (&PICML::PredefinedTypes::name, _1)))))
  {
    ptypes.SetStrValue ("name", CUTS_PREDEFINED_TYPES);
  }

  ptypes.Accept (*this);
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Project::
Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & idefs)
{
  // Locate the CUTS IDL file. If we are not able to find it then we
  // need to create a new one.
  if (Udm::create_if_not (idefs, this->cuts_file_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                                  CUTS_IDL_FILENAME,
                                  boost::bind (&PICML::File::name, _1)))))
  {
    this->cuts_file_.SetStrValue ("name", CUTS_IDL_FILENAME);
  }

  this->cuts_file_.Accept (*this);
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Project::
Visit_PredefinedTypes (const PICML::PredefinedTypes & ptypes)
{
  // Get a listing of all the strings in the predefined types.
  typedef std::vector <PICML::String> String_Set;
  String_Set strings = ptypes.String_kind_children ();

  if (strings.empty ())
  {
    // Since we did not find a single string type, we need to create
    // one. It will be referenced by all auto generated elements.
    this->string_ = PICML::String::Create (ptypes);
    this->string_.SetStrValue ("name", "String");
  }
  else
  {
    // So we found a string. We need to save it and delete the
    // all the other string types.
    this->string_ = strings[0];

    std::for_each (strings.begin  () + 1, strings.end (),
                   boost::bind (&PICML::String::DeleteObject, _1));
  }
}

//
// Visit_File
//
void CUTS_Project::Visit_File (const PICML::File & file)
{
  PICML::Package package;

  if (Udm::create_if_not (file, package,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                                  CUTS_PACKAGE_NAME,
                                  boost::bind (&PICML::Package::name, _1)))))
  {
    package.SetStrValue ("name", CUTS_PACKAGE_NAME);
  }

  package.Accept (*this);
}

//
// Visit_Package
//
void CUTS_Project::Visit_Package (const PICML::Package & package)
{
  if (Udm::create_if_not (package, this->testing_service_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                                  CUTS_TESTING_SERVICE_OBJECT,
                                  boost::bind (&PICML::Object::name, _1)))))
  {
    this->testing_service_.SetStrValue ("name", CUTS_TESTING_SERVICE_OBJECT);
  }
}

//
// get_cuts_file
//
const PICML::File & CUTS_Project::get_cuts_file (void) const
{
  return this->cuts_file_;
}
