// -*- C++ -*-
// $Id$

//
// ccm_activate
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
ccm_activate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  if (!::CORBA::is_nil (this->sc_.in ()))     
    this->sc_->ccm_activate ();
}

//
// ciao_postactivate
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  if (!::CORBA::is_nil (this->sc_.in ()))
    this->sc_->ciao_postactivate ();
}
