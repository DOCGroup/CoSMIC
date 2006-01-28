// $Id$

#if !defined (__CUTS_INLINE__)
# include "cuts/CCM_CoWorkEr_T.inl"
#endif

//
// CUTS_CCM_CoWorkEr_T
//
template <typename COMPONENT, typename COMPONENT_CONTEXT>
CUTS_CCM_CoWorkEr_T
<COMPONENT, COMPONENT_CONTEXT>::CUTS_CCM_CoWorkEr_T (void)
{

}

//
// ~CUTS_CCM_CoWorkEr_T
//
template <typename COMPONENT, typename COMPONENT_CONTEXT>
CUTS_CCM_CoWorkEr_T
<COMPONENT, COMPONENT_CONTEXT>::~CUTS_CCM_CoWorkEr_T (void)
{

}

//
// set_session_context
//
template <typename COMPONENT, typename COMPONENT_CONTEXT>
void CUTS_CCM_CoWorkEr_T
<COMPONENT, COMPONENT_CONTEXT>::set_session_context (
  ::Components::SessionContext_ptr ctx
  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException,
                   ::Components::CCMException))
{
  // Narrow the context to the one for this component type.
  this->context_ =
    Component_Context::_narrow (ctx ACE_ENV_ARG_PARAMETER);

  // Check the environment variable.
  ACE_CHECK;

  // Verify the context was properly narrowed.
  if (this->context_ == 0)
  {
    ACE_THROW (CORBA::INTERNAL ());
  }
}
