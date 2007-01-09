// $Id$

CUTS_INLINE
bool CUTS_BE_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  return true;
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
write_factory_begin (const PICML::ComponentFactory & factory,
                     const PICML::MonolithicImplementation & impl,
                     const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_begin (const PICML::InEventPort & sink)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_end (const PICML::InEventPort & sink)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_begin (const PICML::Attribute & attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_end (const PICML::Attribute & attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_begin (const PICML::ReadonlyAttribute & ro_attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_end (const PICML::ReadonlyAttribute & ro_attr)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
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
write_variable (const PICML::WorkerType & type,
                const PICML::Worker & worker)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_variable (const PICML::ReadonlyAttribute & type)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_variable (const PICML::PeriodicEvent & periodic)
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
write_action_begin (const PICML::Worker & worker,
                    const PICML::Action & action)
{

}

CUTS_INLINE
void CUTS_BE_Traits::
write_action_begin (const PICML::OutputAction & action)
{

}

CUTS_INLINE
void CUTS_BE_Traits::write_action_end (void)
{

}
