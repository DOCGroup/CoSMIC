// -*- C++ -*-

//=============================================================================
/**
 * @file      Header_Exec_Source_Traits.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_EXEC_SOURCE_TRAITS_H_
#define _CUTS_CIAO_EXEC_SOURCE_TRAITS_H_

#include "CIAO_Source_Traits.h"
#include "Port_Manager_T.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include <stack>

//=============================================================================
/**
 * @class CUTS_CIAO_Exec_Source_Traits
 */
//=============================================================================

class CUTS_CIAO_Exec_Source_Traits :
  public CUTS_CIAO_Source_Traits
{
public:
  typedef CUTS_CIAO_Source_Traits _super;

  CUTS_CIAO_Exec_Source_Traits (void);

  virtual ~CUTS_CIAO_Exec_Source_Traits (void);

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

  virtual void write_ProvidedRequestPort_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_InEventPort_end (
    const PICML::InEventPort & sink);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_PeriodicEvent_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_environment_begin (
    const PICML::Component & component);

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

  virtual void write_OuputAction_Property (
    const PICML::OutputAction & action,
    const PICML::Property & property);

  virtual void write_OutputAction_end (
    const PICML::OutputAction & action);

  virtual void write_action_end (void);

  void write_branches_begin (size_t branches);

  void write_branch_condition_begin (void);

  void write_branch_condition_end (void);

  void write_branch_begin (void);

  void write_branch_end (void);

  void write_branches_end (void);

  void write_equal_to (void);

  void write_not_equal_to (void);

  void write_less_than (void);

  void write_less_than_equal_to (void);

  void write_greater_than (void);

  void write_greater_than_equal_to (void);

  void write_identifier (const std::string & ident);

  void write_text (const std::string & text);

  void write_char (char ch);

  void write_and_symbol (void);

  void write_or_symbol (void);

protected:
  virtual void write_set_session_context (
    const PICML::Component & component);

  virtual void write_ciao_preactivate (
    const PICML::Component & component);

  virtual void write_ccm_activate (
    const PICML::Component & component);

  virtual void write_ciao_postactivate (
    const PICML::Component & component);

  virtual void write_ccm_passivate (
    const PICML::Component & component);

  virtual void write_ccm_remove (
    const PICML::Component & component);

private:
  /// Type definition for pointer-to-methods to environment methods.
  typedef void (CUTS_CIAO_Exec_Source_Traits::
    *Environment_Method) (const PICML::Component &);

  /// Type definition for environment jump table.
  typedef std::map <std::string,
                    Environment_Method> Environment_Table;

  /// Global jump table for the environment writers.
  static Environment_Table env_table_;

  /// Flag for determining if current action is skipped.
  bool skip_action_;

  /// Flag that determines calling method for environment.
  bool auto_env_;

  /// Manager for mapping port types to their scoped name.
  CUTS_UDM_Port_Manager_T <const PICML::OutEventPort> outevent_mgr_;

  std::stack <size_t> branches_;
};

// Singleton definition.
#define CIAO_EXEC_SOURCE_GENERATOR() \
  ACE_Singleton <CUTS_CIAO_Exec_Source_Traits, \
                 ACE_Null_Mutex>::instance ()

#endif  // !defined _CUTS_CIAO_EXEC_SOURCE_TRAITS_H_
