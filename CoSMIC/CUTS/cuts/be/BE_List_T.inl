// $Id$

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
bool CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
open_file (const PICML::ComponentImplementationContainer & container)
{
  return
    this->traits_.open_file (container) &
    this->next_.open_file (container);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
close_file (const PICML::ComponentImplementationContainer & container)
{
  this->traits_.close_file (container);
  this->next_.close_file (container);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  this->traits_.write_prologue (container);
  this->next_.write_prologue (container);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{
  this->traits_.write_epilogue (container);
  this->next_.write_epilogue (container);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_includes (const CUTS_String_Set & includes)
{
  this->traits_.write_includes (includes);
  this->next_.write_includes (includes);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & type)
{
  this->traits_.write_impl_begin (monoimpl, type);
  this->next_.write_impl_begin (monoimpl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_impl_end (const PICML::MonolithicImplementation & impl,
                const PICML::Component & type)
{
  this->traits_.write_impl_end (impl, type);
  this->next_.write_impl_end (impl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_factory_begin (const PICML::ComponentFactory & factory,
                     const PICML::MonolithicImplementation & impl,
                     const PICML::Component & type)
{
  this->traits_.write_factory_begin (factory, impl, type);
  this->next_.write_factory_begin (factory, impl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_factory_end (const PICML::ComponentFactory & factory,
                   const PICML::MonolithicImplementation & impl,
                   const PICML::Component & type)
{
  this->traits_.write_factory_end (factory, impl, type);
  this->next_.write_factory_end (factory, impl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_begin (const PICML::InEventPort & sink)
{
  this->traits_.write_method_begin (sink);
  this->next_.write_method_begin (sink);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_end (const PICML::InEventPort & sink)
{
  this->traits_.write_method_end (sink);
  this->next_.write_method_end (sink);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_method_begin (facet);
  this->next_.write_method_begin (facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_method_end (facet);
  this->next_.write_method_end (facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_begin (const PICML::Attribute & attr)
{
  this->traits_.write_method_begin (attr);
  this->next_.write_method_begin (attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_end (const PICML::Attribute & attr)
{
  this->traits_.write_method_end (attr);
  this->next_.write_method_end (attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_method_begin (periodic);
  this->next_.write_method_begin (periodic);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_end (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_method_end (periodic);
  this->next_.write_method_end (periodic);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  this->traits_.write_method_begin (ro_attr);
  this->next_.write_method_begin (ro_attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_method_end (const PICML::ReadonlyAttribute & ro_attr)
{
  this->traits_.write_method_end (ro_attr);
  this->next_.write_method_end (ro_attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_environment_begin (const PICML::Component & component)
{
  this->traits_.write_environment_begin (component);
  this->next_.write_environment_begin (component);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_environment_end (const PICML::Component & component)
{
  this->traits_.write_environment_end (component);
  this->next_.write_environment_end (component);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_environment_method_begin (const PICML::InputAction & action)
{
  this->traits_.write_environment_method_begin (action);
  this->next_.write_environment_method_begin (action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_environment_method_end (const PICML::InputAction & action)
{
  this->traits_.write_environment_method_end (action);
  this->next_.write_environment_method_end (action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variables_begin (const PICML::Component & component)
{
  this->traits_.write_variables_begin (component);
  this->next_.write_variables_begin (component);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variable (const PICML::Variable & variable)
{
  this->traits_.write_variable (variable);
  this->next_.write_variable (variable);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variable (const PICML::WorkerType & type,
                const PICML::Worker & worker)
{
  this->traits_.write_variable (type, worker);
  this->next_.write_variable (type, worker);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variable (const PICML::ReadonlyAttribute & readonly)
{
  this->traits_.write_variable (readonly);
  this->next_.write_variable (readonly);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variable (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_variable (periodic);
  this->next_.write_variable (periodic);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_variables_end (void)
{
  this->traits_.write_variables_end ();
  this->next_.write_variables_end ();
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_precondition (const std::string & precondition)
{
  this->traits_.write_precondition (precondition);
  this->next_.write_precondition (precondition);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_postcondition (const std::string & postcondition)
{
  this->traits_.write_postcondition (postcondition);
  this->next_.write_postcondition (postcondition);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_action_property (const PICML::Property & property)
{
  this->traits_.write_action_property (property);
  this->next_.write_action_property (property);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_action_begin (const PICML::Worker & worker,
                    const PICML::Action & action)
{
  this->traits_.write_action_begin (worker, action);
  this->next_.write_action_begin (worker, action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_action_begin (const PICML::OutputAction & action)
{
  this->traits_.write_action_begin (action);
  this->next_.write_action_begin (action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_action_end (void)
{
  this->traits_.write_action_end ();
  this->next_.write_action_end ();
}
