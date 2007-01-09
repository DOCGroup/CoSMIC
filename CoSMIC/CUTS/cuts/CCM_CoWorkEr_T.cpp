// $Id$

#if !defined (__CUTS_INLINE__)
# include "cuts/CCM_CoWorkEr_T.inl"
#endif

#include "ciao/Container_Base.h"
#include "ace/Log_Msg.h"
#include "ace/SString.h"

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

}
