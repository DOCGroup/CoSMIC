// $Id$

#include "CoWorkEr_Cache.h"
#include "PICML/PICML.h"
#include "modelgen.h"
#include "boost/bind.hpp"

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
  PICML::RequiredRequestPort receptacle;

  if (!contains (boost::bind (std::equal_to <std::string> (),
      CUTS_TESTING_SERVICE,
      boost::bind (&PICML::RequiredRequestPort::name, _1)))
      (component, receptacle))
  {
    return false;
  }

  // We need to search for the attribute "cuts_proxy_impl"
  typedef std::set <PICML::Attribute> Attribute_Set;
  Attribute_Set attrs = component.Attribute_kind_children ();

  PICML::Attribute attribute;

  if (!contains (boost::bind (std::equal_to <std::string> (),
      CUTS_PROXY_IMPL,
      boost::bind (&PICML::Attribute::name, _1)))
      (component, attribute))
  {
    return false;
  }

  return true;
}
