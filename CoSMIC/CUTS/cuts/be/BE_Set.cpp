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

//
// write_prologue
//
void CUTS_BE_Set::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_prologue,
                              _1,
                              container));
}

//
// write_epilogue
//
void CUTS_BE_Set::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_epilogue,
                              _1,
                              container));
}

//
// write_includes
//
void CUTS_BE_Set::
write_includes (const CUTS_String_Set & includes)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_includes,
                              _1,
                              includes));
}

//
// write_impl_begin
//
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

//
// write_impl_end
//
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

//
// write_object_impl_begin
//
void CUTS_BE_Set::
write_object_impl_begin (const PICML::Component & component,
                         const PICML::ProvidedRequestPort & facet)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_object_impl_begin,
                              _1,
                              component,
                              facet));
}

//
// write_object_impl_end
//
void CUTS_BE_Set::
write_object_impl_end (const PICML::Component & component,
                       const PICML::ProvidedRequestPort & facet)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_object_impl_end,
                              _1,
                              component,
                              facet));
}

//
// write_factory_impl_begin
//
void CUTS_BE_Set::
write_factory_impl_begin (const PICML::ComponentFactory & factory,
                          const PICML::MonolithicImplementation & impl,
                          const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_factory_impl_begin,
                              _1,
                              factory,
                              impl,
                              type));
}

//
// write_factory_impl_end
void CUTS_BE_Set::
write_factory_impl_end (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & impl,
                        const PICML::Component & type)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_factory_impl_end,
                              _1,
                              factory,
                              impl,
                              type));
}

//
// write_InEventPort_begin
//
void CUTS_BE_Set::
write_InEventPort_begin (const PICML::InEventPort & sink)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_InEventPort_begin,
                              _1,
                              sink));
}

//
// write_InEventPort_end
//
void CUTS_BE_Set::
write_InEventPort_end (const PICML::InEventPort & sink)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_InEventPort_end,
                              _1,
                              sink));
}

//
// write_ProvidedRequestPort_begin
//
void CUTS_BE_Set::
write_ProvidedRequestPort_begin (const PICML::ProvidedRequestPort & facet)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_ProvidedRequestPort_begin,
                              _1,
                              facet));
}

//
// write_ProvidedRequestPort_end
//
void CUTS_BE_Set::
write_ProvidedRequestPort_end (const PICML::ProvidedRequestPort & facet)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_ProvidedRequestPort_end,
                              _1,
                              facet));
}

//
// write_PeriodicEvent_begin
//
void CUTS_BE_Set::
write_PeriodicEvent_begin (const PICML::PeriodicEvent & periodic)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_PeriodicEvent_begin,
                              _1,
                              periodic));
}

//
// write_PeriodicEvent_end
//
void CUTS_BE_Set::
write_PeriodicEvent_end (const PICML::PeriodicEvent & periodic)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_PeriodicEvent_end,
                              _1,
                              periodic));
}

//
// write_Attribute_begin
//
void CUTS_BE_Set::
write_Attribute_begin (const PICML::Attribute & attr)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_Attribute_begin,
                              _1,
                              attr));
}

//
// write_Attribute_end
//
void CUTS_BE_Set::
write_Attribute_end (const PICML::Attribute & attr)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_Attribute_end,
                              _1,
                              attr));
}

//
// write_ReadonlyAttribute_begin
//
void CUTS_BE_Set::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_ReadonlyAttribute_begin,
                              _1,
                              ro_attr));
}

//
// write_ReadonlyAttribute_end
//
void CUTS_BE_Set::
write_ReadonlyAttribute_end (const PICML::ReadonlyAttribute & ro_attr)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_ReadonlyAttribute_end,
                              _1,
                              ro_attr));
}

//
// write_OnewayOperation_begin
//
void CUTS_BE_Set::
write_OnewayOperation_begin (const PICML::OnewayOperation & oneway)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_OnewayOperation_begin,
                              _1,
                              oneway));
}

//
// write_OnewayOperation_end
//
void CUTS_BE_Set::
write_OnewayOperation_end (const PICML::OnewayOperation & oneway)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_OnewayOperation_end,
                              _1,
                              oneway));
}

//
// write_TwowayOperation_begin
//
void CUTS_BE_Set::
write_TwowayOperation_begin (const PICML::TwowayOperation & twoway)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_TwowayOperation_begin,
                              _1,
                              twoway));
}

//
// write_TwowayOperation_end
//
void CUTS_BE_Set::
write_TwowayOperation_end (const PICML::TwowayOperation & twoway)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_TwowayOperation_end,
                              _1,
                              twoway));
}

//
// write_environment_begin
//
void CUTS_BE_Set::
write_environment_begin (const PICML::Component & component)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_begin,
                              _1,
                              component));
}

//
// write_environment_end
//
void CUTS_BE_Set::
write_environment_end (const PICML::Component & component)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_environment_end,
                              _1,
                              component));
}

//
// write_environment_method_begin/
//
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

//
// write_variable
//
void CUTS_BE_Set::
write_variable (const PICML::Variable & variable)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_variable,
                              _1,
                              variable));
}

//
// write_Periodic_variable
//
void CUTS_BE_Set::
write_PeriodicEvent_variable (const PICML::PeriodicEvent & variable)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_PeriodicEvent_variable,
                              _1,
                              variable));
}

//
// write_worker_variable
//
void CUTS_BE_Set::
write_worker_variable (const PICML::WorkerType & type,
                       const PICML::Worker & worker)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_worker_variable,
                              _1,
                              type,
                              worker));
}

//
// write_ReadonlyAttribute_variable
//
void CUTS_BE_Set::
write_ReadonlyAttribute_variable (const PICML::ReadonlyAttribute & readonly)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_ReadonlyAttribute_variable,
                              _1,
                              readonly));
}

//
// write_variables_end
//
void CUTS_BE_Set::
write_variables_end (void)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_variables_end,
                              _1));
}

//
// write_precondition
//
void CUTS_BE_Set::
write_precondition (const std::string & precondition)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_precondition,
                              _1,
                              precondition));
}

//
// write_postcondition
//
void CUTS_BE_Set::
write_postcondition (const std::string & postcondition)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_postcondition,
                              _1,
                              postcondition));
}

//
// write_action_property
//
void CUTS_BE_Set::
write_action_property (const PICML::Property & property)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_action_property,
                              _1,
                              property));
}

//
// write_WorkerAction_begin
//
void CUTS_BE_Set::
write_WorkerAction_begin (const PICML::Worker & worker,
                    const PICML::Action & action)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_WorkerAction_begin,
                              _1,
                              worker,
                              action));
}

//
// write_OutputAction_begin
//
void CUTS_BE_Set::
write_OutputAction_begin (const PICML::OutputAction & action)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_OutputAction_begin,
                              _1,
                              action));
}

//
// write_action_end
//
void CUTS_BE_Set::write_action_end (void)
{
  std::for_each (this->strats_.begin (),
                 this->strats_.end (),
                 boost::bind (&CUTS_BE_Traits::write_action_end,
                              _1));
}
