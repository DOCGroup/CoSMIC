// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Proxy_Header_Traits.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_PROXY_HEADER_TRAITS_H_
#define _CUTS_CIAO_PROXY_HEADER_TRAITS_H_

#include "CIAO_Header_Traits.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Header_Traits
 *
 * CIAO header file generator for the CUTS-PICML backend.
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_CIAO_Proxy_Header_Traits :
  public CUTS_CIAO_Header_Traits
{
public:
  /// Type definition of the super class.
  typedef CUTS_CIAO_Header_Traits _super;

  CUTS_CIAO_Proxy_Header_Traits (void);

  virtual ~CUTS_CIAO_Proxy_Header_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_includes (
    const CUTS_String_Set & includes);

  void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  void write_method_end (
    const PICML::ProvidedRequestPort & facet);

  void write_method_begin (
    const PICML::PeriodicEvent & periodic);

  void write_method_end (
    const PICML::PeriodicEvent & periodic);

  void write_method_begin (
    const PICML::InEventPort & sink);

  void write_method_end (
    const PICML::InEventPort & sink);

  void write_method_begin (
    const PICML::ReadonlyAttribute & readonly);

  void write_method_end (
    const PICML::ReadonlyAttribute & readonly);

  void write_method_begin (
    const PICML::Attribute & readonly);

  void write_method_end (
    const PICML::Attribute & readonly);

  void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  virtual void write_factory_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_factory_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_variables_begin (
    const PICML::Component & component);

  virtual void write_variable (
    const PICML::Variable & variable);

  virtual void write_variable (
    const PICML::WorkerType & type,
    const PICML::Worker & worker);

  virtual void write_variable (
    const PICML::ReadonlyAttribute & readonly);

  virtual void write_variable (
    const PICML::PeriodicEvent & periodic);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_environment_method_begin (
    const PICML::InputAction &);

  virtual void write_environment_method_end (
    const PICML::InputAction &);

  virtual void write_environment_end (
    const PICML::Component & component);

protected:
  void write_method (
    const PICML::OutEventPort & source);

  void write_method (
    const PICML::RequiredRequestPort & receptacle);

private:
  bool get_component_factory (
    const PICML::Component & component,
    PICML::ComponentFactory & factory);

  void write_eventsink_variable (
    const PICML::InEventPort & sink);

  virtual void write_id_variable (
    const PICML::OutEventPort & source);
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Proxy_Header_Traits.inl"
#endif

#endif  // !defined _CUTS_CIAO_PROXY_HEADER_TRAITS_H_
