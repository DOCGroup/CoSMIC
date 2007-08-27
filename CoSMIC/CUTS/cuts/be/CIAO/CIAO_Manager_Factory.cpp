// $Id$

#include "CIAO_Manager_Factory.h"
#include "CIAO_Manager.h"

static const char * __description__ =
  "Generate project and source\r\n"
  "files for the Component\r\n"
  "Integrated ACE ORB (CIAO)\r\n"
  "framework - a C++\r\n"
  "implementation of the CORBA\r\n"
  "Component Model (CCM).";

//
// CUTS_BE_CIAO_Manager_Factory
//
CUTS_BE_CIAO_Manager_Factory::CUTS_BE_CIAO_Manager_Factory (void)
{

}

//
// ~CUTS_BE_CIAO_Manager_Factory
//
CUTS_BE_CIAO_Manager_Factory::~CUTS_BE_CIAO_Manager_Factory (void)
{

}

//
// create_manager
//
CUTS_BE_Manager * CUTS_BE_CIAO_Manager_Factory::create_manager (void)
{
  return new CIAO_BE_Manager ();
}

//
// name
//
const char * CUTS_BE_CIAO_Manager_Factory::name (void) const
{
  return "Component Integrated ACE ORB (CIAO)";
}

//
// description
//
const char * CUTS_BE_CIAO_Manager_Factory::description (void) const
{
  return __description__;
}

CUTS_BE_CREATE_MANAGER_FACTORY_IMPLEMENT (CUTS_BE_CIAO_Manager_Factory);
