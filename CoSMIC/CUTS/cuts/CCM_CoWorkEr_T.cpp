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
  this->CUTS_CCM_CoWorkEr::init ();
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
  this->context_ = _ctx_type::_narrow (ctx);

  // Verify the context was properly narrowed.
  if (this->context_ == 0)
    ACE_THROW (CORBA::INTERNAL ());

  // Store the <context_> in the <producer_>
  this->producer_.context (this->context_);
}

//
// ciao_preactivate
//
template <typename COMPONENT, typename COMPONENT_CONTEXT>
void CUTS_CCM_CoWorkEr_T <COMPONENT, COMPONENT_CONTEXT>::
ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  CUTS::Testing_Service::_var_type test_svc =
    this->context_->get_connection_cuts_testing_service ();

  // Collect registration information for the component.
  CUTS::Component_Registration reg;
  reg.name  = this->context_->_ciao_instance_id ();
  reg.agent =
    CUTS::Benchmark_Agent::_duplicate (this->benchmark_agent_->_this ());
  reg.type  = CORBA::string_dup (this->_interface_repository_id ());

  this->registration_id_ = this->register_i (test_svc.in (), reg);
  this->benchmark_agent_->parent (this->registration_id_);
  this->producer_.activate (this->registration_id_);
}

//
// ccm_passivate
//
template <typename COMPONENT, typename COMPONENT_CONTEXT>
void CUTS_CCM_CoWorkEr_T
<COMPONENT, COMPONENT_CONTEXT>::ccm_passivate (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  ::CUTS::Testing_Service_var testing_service =
    this->context_->get_connection_cuts_testing_service ();

  // Get the instance name of the component from the context.
  ::CORBA::String_var instance_id (this->context_->_ciao_instance_id ());

  if (!::CORBA::is_nil (testing_service.in ()))
  {
    try
    {
      // Initialize the <Component_Registration> data structure and
      // unregister the component.
      ::CUTS::Component_Registration creg;
      creg.name = this->context_->_ciao_instance_id ();
      creg.agent =
        ::CUTS::Benchmark_Agent::_duplicate (
        this->benchmark_agent_->_this ());

      testing_service->unregister_component (creg);
    }
    catch (const ::CUTS::ID_Not_Found &)
    {
      ACE_ERROR ((
        LM_ERROR,
        "[%M] -%T - ID not found for %s; component was not registered\n",
        instance_id.in ()));

    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] -%T - unknown exception has occurred\n"));
    }
  }
  else
  {
    ACE_DEBUG ((LM_ERROR,
                "[%M] -%T - %s not connected to Benchmark Data Collector\n",
                instance_id.in ()));
  }

  // Reset the <registration_id_>.
  this->registration_id_ = -1;
}
