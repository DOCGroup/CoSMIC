// $Id$

#include "BE_Manager_Factory.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Manager_Factory.inl"
#endif

//
// close
//
void CUTS_BE_Manager_Factory::close (void)
{
  delete this;
}

//
// name
//
const char * CUTS_BE_Manager_Factory::name (void) const
{
  return "No Name";
}

//
// description
//
const char * CUTS_BE_Manager_Factory::description (void) const
{
  return "No description provided";
}
