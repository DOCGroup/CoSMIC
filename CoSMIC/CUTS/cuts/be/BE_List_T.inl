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
write_object_impl_begin (const PICML::Component & component,
                         const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_object_impl_begin (component, facet);
  this->next_.write_object_impl_begin (component, facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_object_impl_end (const PICML::Component & component,
                       const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_object_impl_end (component, facet);
  this->next_.write_object_impl_end (component, facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_factory_impl_begin (const PICML::ComponentFactory & factory,
                          const PICML::MonolithicImplementation & impl,
                          const PICML::Component & type)
{
  this->traits_.write_factory_impl_begin (factory, impl, type);
  this->next_.write_factory_impl_begin (factory, impl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_factory_impl_end (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & impl,
                        const PICML::Component & type)
{
  this->traits_.write_factory_impl_end (factory, impl, type);
  this->next_.write_factory_impl_end (factory, impl, type);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_InEventPort_begin (const PICML::InEventPort & sink)
{
  this->traits_.write_InEventPort_begin (sink);
  this->next_.write_InEventPort_begin (sink);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_InEventPort_end (const PICML::InEventPort & sink)
{
  this->traits_.write_InEventPort_end (sink);
  this->next_.write_InEventPort_end (sink);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_ProvidedRequestPort_begin (const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_ProvidedRequestPort_begin (facet);
  this->next_.write_ProvidedRequestPort_begin (facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_ProvidedRequestPort_end (const PICML::ProvidedRequestPort & facet)
{
  this->traits_.write_ProvidedRequestPort_end (facet);
  this->next_.write_ProvidedRequestPort_end (facet);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_Attribute_begin (const PICML::Attribute & attr)
{
  this->traits_.write_Attribute_begin (attr);
  this->next_.write_Attribute_begin (attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_Attribute_end (const PICML::Attribute & attr)
{
  this->traits_.write_Attribute_end (attr);
  this->next_.write_Attribute_end (attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_PeriodicEvent_begin (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_PeriodicEvent_begin (periodic);
  this->next_.write_PeriodicEvent_begin (periodic);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_PeriodicEvent_end (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_PeriodicEvent_end (periodic);
  this->next_.write_PeriodicEvent_end (periodic);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  this->traits_.write_ReadonlyAttribute_begin (ro_attr);
  this->next_.write_ReadonlyAttribute_begin (ro_attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_ReadonlyAttribute_end (const PICML::ReadonlyAttribute & ro_attr)
{
  this->traits_.write_ReadonlyAttribute_end (ro_attr);
  this->next_.write_ReadonlyAttribute_end (ro_attr);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_OnewayOperation_begin (const PICML::OnewayOperation & oneway)
{
  this->traits_.write_OnewayOperation_begin (oneway);
  this->next_.write_OnewayOperation_begin (oneway);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_OnewayOperation_end (const PICML::OnewayOperation & oneway)
{
  this->traits_.write_OnewayOperation_end (oneway);
  this->next_.write_OnewayOperation_end (oneway);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_TwowayOperation_begin (const PICML::TwowayOperation & twoway)
{
  this->traits_.write_TwowayOperation_begin (twoway);
  this->next_.write_TwowayOperation_begin (twoway);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_TwowayOperation_end (const PICML::TwowayOperation & twoway)
{
  this->traits_.write_TwowayOperation_end (twoway);
  this->next_.write_TwowayOperation_end (twoway);
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
write_environment_end (const PICML::Component & component)
{
  this->traits_.write_environment_end (component);
  this->next_.write_environment_end (component);
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
write_worker_variable (const PICML::WorkerType & type,
                const PICML::Worker & worker)
{
  this->traits_.write_worker_variable (type, worker);
  this->next_.write_worker_variable (type, worker);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_ReadonlyAttribute_variable (const PICML::ReadonlyAttribute & readonly)
{
  this->traits_.write_ReadonlyAttribute_variable (readonly);
  this->next_.write_ReadonlyAttribute_variable (readonly);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_PeriodicEvent_variable (const PICML::PeriodicEvent & periodic)
{
  this->traits_.write_PeriodicEvent_variable (periodic);
  this->next_.write_PeriodicEvent_variable (periodic);
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
write_WorkerAction_begin (const PICML::Worker & worker,
                          const PICML::Action & action)
{
  this->traits_.write_WorkerAction_begin (worker, action);
  this->next_.write_WorkerAction_begin (worker, action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_OutputAction_begin (const PICML::OutputAction & action)
{
  this->traits_.write_OutputAction_begin (action);
  this->next_.write_OutputAction_begin (action);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_action_end (void)
{
  this->traits_.write_action_end ();
  this->next_.write_action_end ();
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_FactoryOperation_begin (const PICML::FactoryOperation & factory_op)
{
  this->traits_.write_FactoryOperation_begin (factory_op);
  this->next_.write_FactoryOperation_begin (factory_op);
}

template <typename BE_STRATEGY, typename BE_NEXT>
CUTS_INLINE
void CUTS_BE_List_T <BE_STRATEGY, BE_NEXT>::
write_FactoryOperation_end (const PICML::FactoryOperation & factory_op)
{
  this->traits_.write_FactoryOperation_end (factory_op);
  this->next_.write_FactoryOperation_end (factory_op);
}
