// -*- C++ -*-

//=============================================================================
/**
 * @file      Header_File_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_PROXY_SOURCE_TRAITS_H_
#define _CUTS_CIAO_PROXY_SOURCE_TRAITS_H_

#include "CIAO_Source_Traits.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Source_Traits
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_CIAO_Proxy_Source_Traits :
  public CUTS_CIAO_Source_Traits
{
public:
  typedef CUTS_CIAO_Source_Traits _super;

  CUTS_CIAO_Proxy_Source_Traits (void);

  virtual ~CUTS_CIAO_Proxy_Source_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  virtual void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  virtual void write_ProvidedRequestPort_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_PeriodicEvent_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_Attribute_begin (
    const PICML::Attribute & sink);

  virtual void write_Attribute_end (
    const PICML::Attribute & sink);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & sink);

  virtual void write_environment_method_begin (
    const PICML::InputAction & action);

  virtual void write_environment_method_end (
    const PICML::InputAction & action);

  virtual void write_environment_end (
    const PICML::Component & component);

  virtual void write_precondition (
    const std::string & precondition);

  virtual void write_postcondition (
    const std::string & precondition);

  virtual void write_action_property (
    const PICML::Property & property);

  virtual void write_WorkerAction_begin (
    const PICML::Worker & worker,
    const PICML::Action & action);

  virtual void write_OutputAction_begin (
    const PICML::OutputAction & action);

  virtual void write_action_end (void);

protected:
  void write_event_handler_bind (
    const PICML::InEventPort & sink);

  void write_endpoint_register (
    const PICML::OutEventPort & source);

  void write_agent_register (
    const PICML::InEventPort & sink);

  void write_set_session_context (
    const PICML::Component & component);

  void write_register_obv_factory (
    const PICML::Event & event);

  virtual void write_method (
    const PICML::OutEventPort & source);

  virtual void write_method (
    const PICML::RequiredRequestPort & receptacle);

private:
  /// Type definition for a collection of events.
  typedef std::set <PICML::Event> EventType_Set;

  /// Collection of input event types.
  EventType_Set in_events_;
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Proxy_Source_Traits.inl"
#endif

// Singleton declaration.
CUTS_UDM_CIAO_SINGLETON_DECLARE (ACE_Singleton,
                                 CUTS_CIAO_Proxy_Source_Traits,
                                 ACE_Null_Mutex);
// Singleton definition.
#define CIAO_PROXY_SOURCE_GENERATOR() \
  ACE_Singleton <CUTS_CIAO_Proxy_Source_Traits, \
                 ACE_Null_Mutex>::instance ()

#endif  // !defined _CUTS_CIAO_PROXY_SOURCE_TRAITS_H_
