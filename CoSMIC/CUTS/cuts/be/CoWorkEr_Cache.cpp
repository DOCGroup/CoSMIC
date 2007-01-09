// $Id$

#include "CoWorkEr_Cache.h"
#include "PICML/PICML.h"
#include "UDM_Utility_T.h"

/// expected CUTS CoWorkEr receptacle
static const char * CUTS_TESTING_SERVICE = "cuts_testing_service";

/// expected CUTS CoWorkEr attribute
static const char * CUTS_PROXY_IMPL = "cuts_proxy_impl";

//
// instance_
//
CUTS_CoWorkEr_Cache * CUTS_CoWorkEr_Cache::instance_ = 0;

//
// CUTS_CoWorkEr_Cache
//
CUTS_CoWorkEr_Cache::CUTS_CoWorkEr_Cache (void)
{

}

//
// ~CUTS_CoWorkEr_Cache
//
CUTS_CoWorkEr_Cache::~CUTS_CoWorkEr_Cache (void)
{

}

//
// close
//
void CUTS_CoWorkEr_Cache::close (void)
{
  if (this == CUTS_CoWorkEr_Cache::instance_)
    CUTS_CoWorkEr_Cache::instance_ = 0;

  delete this;
}

//
// instance
//
CUTS_CoWorkEr_Cache * CUTS_CoWorkEr_Cache::instance (void)
{
  if (CUTS_CoWorkEr_Cache::instance_ == 0)
    CUTS_CoWorkEr_Cache::instance_ = new CUTS_CoWorkEr_Cache ();

  return CUTS_CoWorkEr_Cache::instance_;
}

//
// is_coworker
//
bool CUTS_CoWorkEr_Cache::is_coworker (const PICML::Component & component)
{
  // We need to search for the receptacle "cuts_proxy_impl"
  typedef std::set <PICML::RequiredRequestPort> Receptacle_Set;
  Receptacle_Set receptacles = component.RequiredRequestPort_kind_children ();

  if (std::find_if (
      receptacles.begin (),
      receptacles.end (),
      Find_Element_By_Name <Receptacle_Set::value_type> (
      CUTS_TESTING_SERVICE)) == receptacles.end ())
  {
    return false;
  }

  // We need to search for the attribute "cuts_proxy_impl"
  typedef std::set <PICML::Attribute> Attribute_Set;
  Attribute_Set attrs = component.Attribute_kind_children ();

  if (std::find_if (
      attrs.begin (),
      attrs.end (),
      Find_Element_By_Name <Attribute_Set::value_type> (
      CUTS_PROXY_IMPL)) == attrs.end ())
  {
    return false;
  }

  return true;
}
