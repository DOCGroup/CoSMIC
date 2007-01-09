// $Id$

#include "BE_Set.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Set.inl"
#endif

#include "boost/bind.hpp"
#include <algorithm>

CUTS_BE_Set::CUTS_BE_Set (void)
{

}

CUTS_BE_Set::~CUTS_BE_Set (void)
{

}

bool CUTS_BE_Set::
open_file (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::open_file,
                              _1,
                              container));

  // ALWAYS return 'true' for now.
  return true;
}


void CUTS_BE_Set::
close_file (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::close_file,
                              _1,
                              container));
}

void CUTS_BE_Set::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_prologue,
                              _1,
                              container));
}

void CUTS_BE_Set::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_epilogue,
                              _1,
                              container));
}

void CUTS_BE_Set::
write_includes (const CUTS_String_Set & includes)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_includes,
                              _1,
                              includes));
}

void CUTS_BE_Set::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_impl_begin,
                              _1,
                              monoimpl,
                              type));
}

void CUTS_BE_Set::
write_impl_end (const PICML::MonolithicImplementation & impl,
                const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_impl_end,
                              _1,
                              impl,
                              type));
}

void CUTS_BE_Set::
write_factory_begin (const PICML::ComponentFactory & factory,
                     const PICML::MonolithicImplementation & impl,
                     const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_factory_begin,
                              _1,
                              factory,
                              impl,
                              type));
}

void CUTS_BE_Set::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_factory_end,
                              _1,
                              factory,
                              impl,
                              type));
}

void CUTS_BE_Set::
write_method_begin (const PICML::InEventPort & sink)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::InEventPort &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_begin),
                              _1,
                              sink));
}

void CUTS_BE_Set::
write_method_end (const PICML::InEventPort & sink)
{
  typedef void (CUTS_BE_Traits::*method_ptr) (const PICML::InEventPort &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_end),
                              _1,
                              sink));
}

void CUTS_BE_Set::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::ProvidedRequestPort &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_begin),
                              _1,
                              facet));
}

void CUTS_BE_Set::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::ProvidedRequestPort &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_end),
                              _1,
                              facet));
}

void CUTS_BE_Set::
write_method_begin (const PICML::Attribute & attr)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::Attribute &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_begin),
                              _1,
                              attr));
}

void CUTS_BE_Set::
write_method_end (const PICML::Attribute & attr)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::Attribute &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_end),
                              _1,
                              attr));
}

void CUTS_BE_Set::
write_method_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::ReadonlyAttribute &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_begin),
                              _1,
                              ro_attr));
}

void CUTS_BE_Set::
write_method_end (const PICML::ReadonlyAttribute & ro_attr)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::ReadonlyAttribute &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_method_end),
                              _1,
                              ro_attr));
}

void CUTS_BE_Set::
write_environment_begin (const PICML::Component & component)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_begin,
                              _1,
                              component));
}

void CUTS_BE_Set::
write_environment_end (const PICML::Component & component)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_end,
                              _1,
                              component));
}

void CUTS_BE_Set::
write_environment_method_begin (const PICML::InputAction & action)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_method_begin,
                              _1,
                              action));
}

void CUTS_BE_Set::
write_environment_method_end (const PICML::InputAction & action)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_method_end,
                              _1,
                              action));
}

void CUTS_BE_Set::
write_variables_begin (const PICML::Component & component)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_variables_begin,
                              _1,
                              component));
}

void CUTS_BE_Set::
write_variable (const PICML::Variable & variable)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr) (const PICML::Variable &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_variable),
                              _1,
                              variable));
}

void CUTS_BE_Set::
write_variable (const PICML::WorkerType & type,
                const PICML::Worker & worker)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::WorkerType &, const PICML::Worker &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_variable),
                              _1,
                              type,
                              worker));
}

void CUTS_BE_Set::
write_variable (const PICML::ReadonlyAttribute & readonly)
{
  typedef
    void (CUTS_BE_Traits::*method_ptr)
    (const PICML::ReadonlyAttribute &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_variable),
                              _1,
                              readonly));
}

void CUTS_BE_Set::
write_variables_end (void)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_variables_end,
                              _1));
}

void CUTS_BE_Set::
write_precondition (const std::string & precondition)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_precondition,
                              _1,
                              precondition));
}

void CUTS_BE_Set::
write_postcondition (const std::string & postcondition)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_postcondition,
                              _1,
                              postcondition));
}

void CUTS_BE_Set::
write_action_property (const PICML::Property & property)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_action_property,
                              _1,
                              property));
}

void CUTS_BE_Set::
write_action_begin (const PICML::Worker & worker,
                    const PICML::Action & action)
{
  typedef void (CUTS_BE_Traits::*method_ptr)
    (const PICML::Worker &, const PICML::Action &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_action_begin),
                              _1,
                              worker,
                              action));
}

void CUTS_BE_Set::
write_action_begin (const PICML::OutputAction & action)
{
  typedef void (CUTS_BE_Traits::*method_ptr) (const PICML::OutputAction &);

  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (reinterpret_cast <method_ptr> (
                              &CUTS_BE_Traits::write_action_begin),
                              _1,
                              action));
}

void CUTS_BE_Set::write_action_end (void)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_action_end, _1));
}
