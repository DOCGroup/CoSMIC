// $Id$

//
// ~CUTS_CCM_Context_T
//
template <typename T>
CUTS_INLINE
CUTS_CCM_Context_T <T>::~CUTS_CCM_Context_T (void)
{

}

template <typename T>
CUTS_INLINE
::Components::Principal_ptr
CUTS_CCM_Context_T <T>::get_caller_principal (void)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->ctx_->get_caller_principal ();
}

template <typename T>
CUTS_INLINE
::Components::CCMHome_ptr
CUTS_CCM_Context_T <T>::get_CCM_home (void)
ACE_THROW_SPEC ((::CORBA::SystemException))
{
  return this->ctx_->get_CCM_home ();
}

template <typename T>
CUTS_INLINE
::CORBA::Boolean
CUTS_CCM_Context_T <T>::get_rollback_only (void)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::IllegalState))
{
  return this->ctx_->get_rollback_only ();
}

template <typename T>
CUTS_INLINE
::Components::Transaction::UserTransaction_ptr
CUTS_CCM_Context_T <T>::get_user_transaction (void)
ACE_THROW_SPEC ((::CORBA::SystemException,
                ::Components::IllegalState))
{
  return this->ctx_->get_user_transaction ();
}

template <typename T>
CUTS_INLINE
::CORBA::Boolean
CUTS_CCM_Context_T <T>::is_caller_in_role (const char * role)
ACE_THROW_SPEC ((::CORBA::SystemException))
{
  return this->ctx_->is_caller_in_role (role);
}

template <typename T>
CUTS_INLINE
void CUTS_CCM_Context_T <T>::set_rollback_only (void)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::IllegalState))
{
  this->ctx_->set_rollback_only ();
}

template <typename T>
CUTS_INLINE
::CORBA::Object_ptr
CUTS_CCM_Context_T <T>::get_CCM_object (void)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::IllegalState))
{
  return this->ctx_->get_CCM_object ();
}
