// -*- C++ -*-
// $Id$

//
// ~CUTS_CCM_Context_T
//
template <typename T>
CUTS_INLINE
CUTS_CCM_Context_T <T>::~CUTS_CCM_Context_T (void)
{

}

//
// get_caller_principal
//
template <typename T>
CUTS_INLINE
::Components::Principal_ptr
CUTS_CCM_Context_T <T>::get_caller_principal (void)
{
  return this->ctx_->get_caller_principal ();
}

//
// get_CCM_home
//
template <typename T>
CUTS_INLINE
::Components::CCMHome_ptr
CUTS_CCM_Context_T <T>::get_CCM_home (void)
{
  return this->ctx_->get_CCM_home ();
}

//
// get_rollback_only
//
template <typename T>
CUTS_INLINE
::CORBA::Boolean
CUTS_CCM_Context_T <T>::get_rollback_only (void)
{
  return this->ctx_->get_rollback_only ();
}

//
// get_user_transaction
//
template <typename T>
CUTS_INLINE
::Components::Transaction::UserTransaction_ptr
CUTS_CCM_Context_T <T>::get_user_transaction (void)
{
  return this->ctx_->get_user_transaction ();
}

//
// is_caller_in_role
//
template <typename T>
CUTS_INLINE
::CORBA::Boolean
CUTS_CCM_Context_T <T>::is_caller_in_role (const char * role)
{
  return this->ctx_->is_caller_in_role (role);
}

//
// set_rollback_only
//
template <typename T>
CUTS_INLINE
void CUTS_CCM_Context_T <T>::set_rollback_only (void)
{
  this->ctx_->set_rollback_only ();
}

//
// get_CCM_object
//
template <typename T>
CUTS_INLINE
::CORBA::Object_ptr
CUTS_CCM_Context_T <T>::get_CCM_object (void)
{
  return this->ctx_->get_CCM_object ();
}

//
// resolve_service_reference
//
template <typename T>
CUTS_INLINE
::CORBA::Object_ptr
CUTS_CCM_Context_T <T>::resolve_service_reference (const char * service_id)
{
  return this->ctx_->resolve_service_reference (service_id);
}
