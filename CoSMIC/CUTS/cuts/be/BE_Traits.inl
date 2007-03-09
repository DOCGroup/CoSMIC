// -*- C++ -*-
// $Id$

//
// CUTS_BE_Traits
//
CUTS_INLINE
CUTS_BE_Traits::CUTS_BE_Traits (void)
{

}

//
// ~CUTS_BE_Traits
//
CUTS_INLINE
CUTS_BE_Traits::~CUTS_BE_Traits (void)
{

}

CUTS_INLINE
bool CUTS_BE_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  return false;
}

CUTS_INLINE
void CUTS_BE_Traits::
close_file (const PICML::ComponentImplementationContainer & container)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_prologue (const PICML::ComponentImplementationContainer & container)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_includes (const CUTS_String_Set & includes)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_impl_end (const PICML::MonolithicImplementation &,
                const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_object_impl_begin (const PICML::Component & component,
                         const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_object_impl_end (const PICML::Component & component,
                       const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_factory_impl_begin (const PICML::ComponentFactory & factory,
                          const PICML::MonolithicImplementation & impl,
                          const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_factory_impl_end (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & impl,
                        const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_ProvidedRequestPort_begin (const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_ProvidedRequestPort_end (const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_InEventPort_begin (const PICML::InEventPort & sink)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_InEventPort_end (const PICML::InEventPort & sink)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_Attribute_begin (const PICML::Attribute & attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_Attribute_end (const PICML::Attribute & attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & ro_attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_ReadonlyAttribute_end (const PICML::ReadonlyAttribute & ro_attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_PeriodicEvent_begin (const PICML::PeriodicEvent & periodic)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_PeriodicEvent_end (const PICML::PeriodicEvent & periodic)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_OnewayOperation_begin (const PICML::OnewayOperation & oneway)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_OnewayOperation_end (const PICML::OnewayOperation & oneway)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_TwowayOperation_begin (const PICML::TwowayOperation & twoway)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_TwowayOperation_end (const PICML::TwowayOperation & twoway)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_environment_begin (const PICML::Component & component)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_environment_end (const PICML::Component & component)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_environment_method_begin (const PICML::InputAction & action)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_environment_method_end (const PICML::InputAction &)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_variables_begin (const PICML::Component & component)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_variable (const PICML::Variable & variable)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_worker_variable (const PICML::WorkerType & type,
                       const PICML::Worker & worker)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_ReadonlyAttribute_variable (const PICML::ReadonlyAttribute & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_PeriodicEvent_variable (const PICML::PeriodicEvent & periodic)
{

}

CUTS_INLINE
void CUTS_BE_Traits::write_variables_end (void)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_precondition (const std::string & precondition)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_postcondition (const std::string & postcondition)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_action_property (const PICML::Property & property)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_WorkerAction_begin (const PICML::Worker & worker,
                          const PICML::Action & action)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_OutputAction_begin (const PICML::OutputAction & action)
{

}

CUTS_INLINE
void CUTS_BE_Traits::write_action_end (void)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_FactoryOperation_begin (const PICML::FactoryOperation & factory)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_FactoryOperation_end (const PICML::FactoryOperation & factory)
{

}
