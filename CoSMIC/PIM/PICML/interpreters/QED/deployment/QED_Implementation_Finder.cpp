// $Id$

#include "QED_Implementation_Finder.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// QED_Implementation_Finder
//
QED_Implementation_Finder::QED_Implementation_Finder (void)
{

}

//
// ~QED_Implementation_Finder
//
QED_Implementation_Finder::~QED_Implementation_Finder (void)
{

}

//
// Visit_Component
//
void QED_Implementation_Finder::
Visit_Component (const PICML::Component & component)
{
  // We only work with instances.
  if (!component.isInstance ())
    return;

  // Locate the actual type for this instance.
  PICML::Component instance_type = PICML::Component (component).Archetype ();
  while (PICML::Component (instance_type.Archetype ()) != Udm::null)
    instance_type = instance_type.Archetype ();

  // Get the all the references to this component. Eventually,
  // one of the references will be for the monolithic implementation.
  // If one doesn't exist, then we haven't defined a monolithic
  // implementation for this component type.
  typedef std::set <PICML::ComponentRef> ComponentRef_Set;
  ComponentRef_Set refs = instance_type.referedbyComponentRef ();

  std::for_each (refs.begin (),
                 refs.end (),
                 boost::bind (&ComponentRef_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentRef
//
void QED_Implementation_Finder::
Visit_ComponentRef (const PICML::ComponentRef & ref)
{
  // Right now, PICML assumes there is a one-to-one mapping between
  // a component type and monolithic implementation. Therefore, if
  // we already found an implementation, we ignore the other all
  // others.

  if (this->impl_ != Udm::null)
    return;

  PICML::Implements implements = ref.srcImplements ();

  if (implements != Udm::null)
    implements.Accept (*this);
}

//
// Visit_Implements
//
void QED_Implementation_Finder::
Visit_Implements (const PICML::Implements & implements)
{
  PICML::ComponentImplementation impl = implements.srcImplements_end ();
  this->impl_ = PICML::MonolithicImplementation::Cast (impl);
}

//
// is_found
//
bool QED_Implementation_Finder::is_found (void) const
{
  return this->impl_ != Udm::null;
}

//
// implementation
//
const PICML::MonolithicImplementation &
QED_Implementation_Finder::implementation (void) const
{
  return this->impl_;
}
