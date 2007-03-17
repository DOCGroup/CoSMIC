// $Id$

//
// CUTS_BE_Impl_Generator_T
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
CUTS_BE_Impl_Generator_T (void)
{

}

//
// ~CUTS_BE_Impl_Generator_T
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
~CUTS_BE_Impl_Generator_T (void)
{

}

//
// generate
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
generate (const PICML::RootFolder & root)
{
  root.Accept (*this);
}

//
// Visit_Include
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Include (const std::string & include)
{
  CUTS_BE::generate <IMPL_STRATEGY::Include> (include);
}

//
// Visit_PeriodicEvent_Variable
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_PeriodicEvent_Variable (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE::generate <IMPL_STRATEGY::PeriodicEvent_Variable> (periodic);
}

//
// Visit_Include
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_ReadonlyAttribute_Variable (const PICML::ReadonlyAttribute & attr)
{
  CUTS_BE::generate <IMPL_STRATEGY::Attribute_Variable> (attr);
}

//
// Visit_Variable
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
Visit_Variable (const PICML::Variable & variable)
{
  CUTS_BE::generate <IMPL_STRATEGY::Variable> (variable);
}

