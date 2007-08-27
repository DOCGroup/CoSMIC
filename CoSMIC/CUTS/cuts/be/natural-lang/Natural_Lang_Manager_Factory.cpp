// $Id$

#include "Natural_Lang_Manager_Factory.h"
#include "Natural_Lang_Manager.h"

static const char * __description__ =
  "Generate text (.txt) files\r\n"
  "that contain human readable\r\n"
  "description of each\r\n"
  "component's implementation.";

//
// CUTS_BE_Natural_Lang_Manager_Factory
//
CUTS_BE_Natural_Lang_Manager_Factory::
CUTS_BE_Natural_Lang_Manager_Factory (void)
{

}

//
// ~CUTS_BE_Natural_Lang_Manager_Factory
//
CUTS_BE_Natural_Lang_Manager_Factory::
~CUTS_BE_Natural_Lang_Manager_Factory (void)
{

}

//
// create_manager
//
CUTS_BE_Manager *
CUTS_BE_Natural_Lang_Manager_Factory::create_manager (void)
{
  return new CUTS_BE_Natural_Lang_Manager ();
}

//
// name
//
const char *
CUTS_BE_Natural_Lang_Manager_Factory::name (void) const
{
  return "Natural Language (English)";
}

//
// description
//
const char *
CUTS_BE_Natural_Lang_Manager_Factory::description (void) const
{
  return __description__;
}

CUTS_BE_CREATE_MANAGER_FACTORY_IMPLEMENT (CUTS_BE_Natural_Lang_Manager_Factory);
