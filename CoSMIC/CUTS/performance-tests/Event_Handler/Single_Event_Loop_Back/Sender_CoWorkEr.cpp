// This file was generated by
// $Id: Sender_CoWorkEr.cpp,v 1.1.2.8 2006/04/19 09:29:00 hillj Exp $

#include "Sender_CoWorkEr.h"
#include "cuts/ActivationRecord.h"

namespace CIDL_Sender_Impl 
{
  Sender_CoWorkEr::Sender_CoWorkEr (void) 
  {
    Sender_CoWorkEr::init ();
  }

  Sender_CoWorkEr::~Sender_CoWorkEr (void) 
  {
    Sender_CoWorkEr::fini ();
  }

  //
  // Event Sink: input
  //
  void Sender_CoWorkEr::push_input (
    Dummy_Event * ev
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  	ACE_THROW_SPEC ((::CORBA::SystemException))
  {
    this->push_input_event_handler_.handle_event (
      ev->sender (),
      ev->dispatch_time ());
  }

  void Sender_CoWorkEr::push_input_event_handler (
    CUTS_Activation_Record * record)
  {
    record->record_exit_point (
      "output",
      Event_Producer::Push_Data_Event <
      OBV_Dummy_Event, Dummy_Event> (
        this->event_producer_, 1, &Event_Producer::Context::push_output));
  }

  //
  // Environment: activate
  //
  void Sender_CoWorkEr::cuts_activate (void)
  {
    CUTS_Activation_Record dummy_record;
    CUTS_Activation_Record * record = &dummy_record;

    record->record_exit_point (
      "output",
      Event_Producer::Push_Data_Event <
      OBV_Dummy_Event, Dummy_Event> (
        this->event_producer_, 1, &Event_Producer::Context::push_output));
  }

  //
  // SessionComponent: set_session_context
  //
  void Sender_CoWorkEr::set_session_context (
    ::Components::SessionContext_ptr ctx
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
    ACE_DEBUG ((LM_TRACE,
                "entered Sender_CoWorkEr set_session_context\n"));

    CoWorkEr_Type::set_session_context (ctx);

    CIAO_REGISTER_OBV_FACTORY (Dummy_Event_init,
                               Dummy_Event);

    // Set the context for the <event_producer_>.
    this->event_producer_.context (this->context_);
  }

  //
  // SessionComponent: ciao_preactivate
  //
  void Sender_CoWorkEr::ciao_preactivate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
    ACE_DEBUG ((LM_TRACE,
                "entered Sender_CoWorkEr ciao_preactivate\n"));

    // Pass control to the base class.
    CoWorkEr_Type::ciao_preactivate ();

    // Activate the event producer.
    this->event_producer_.activate (this->registration_id_);

    // Activate the port agents.
    this->push_input_port_agent_.activate ();

    // Activate the event handlers.
    this->push_input_event_handler_.activate ();
  }

  //
  // SessionComponent: ccm_activate
  //
  void Sender_CoWorkEr::ccm_activate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
    this->cuts_activate ();
  }

  //
  // SessionComponent: ciao_postactivate
  //
  void Sender_CoWorkEr::ciao_postactivate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
  }

  //
  // SessionComponent: ccm_passivate
  //
  void Sender_CoWorkEr::ccm_passivate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
    // Pass control to the base class.
    CoWorkEr_Type::ccm_passivate ();

    // Deactivate the event producer.
    this->event_producer_.deactivate ();

    // Activate the port agents.
    this->push_input_port_agent_.deactivate ();

    // Activate the event handlers.
    this->push_input_event_handler_.deactivate ();
  }

  //
  // SessionComponent: ccm_remove
  //
  void Sender_CoWorkEr::ccm_remove (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException))
  {
    CoWorkEr_Type::ccm_remove ();
  }

  //
  // init
  //
  void Sender_CoWorkEr::init (void) 
  {
    ACE_DEBUG ((LM_TRACE,
                "entered Sender_CoWorkEr::init\n"));

    // Configuring <input> event port
    this->push_input_port_agent_.name ("input");
    this->push_input_event_handler_.bind (
      this, &this->push_input_port_agent_, &Sender_CoWorkEr::push_input_event_handler);
    this->benchmark_agent_->register_port_agent (&this->push_input_port_agent_);
  }

  //
  // fini
  //
  void Sender_CoWorkEr::fini (void) 
  {
    this->benchmark_agent_->unregister_port_agent (&this->push_input_port_agent_);
  }

  Sender_Factory_CoWorkEr_Factory::Sender_Factory_CoWorkEr_Factory (void) 
  {
     
  }

  Sender_Factory_CoWorkEr_Factory::~Sender_Factory_CoWorkEr_Factory (void) 
  {
     
  }

  ::Components::EnterpriseComponent_ptr
  Sender_Factory_CoWorkEr_Factory::create (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException)) 
  {
    ::Components::EnterpriseComponent_ptr retval =
    	::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (retval, 
                      Sender_CoWorkEr,
                      CORBA::NO_MEMORY ());

    ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

    return retval;
  }

  extern "C" CUTS_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Sender_Factory_CoWorkEr_Factory_Impl (void) 
  {
    ::Components::HomeExecutorBase_ptr retval =
    	::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (retval, 
                    Sender_Factory_CoWorkEr_Factory,
                    ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}


