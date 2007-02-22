// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Trait.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_TRAITS_H_
#define _CUTS_BE_TRAITS_H_

#include "BE_export.h"
#include "String_Set.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_Traits
 *
 * Base class for all backend generators. This class defines the traits
 * that must be defined by all generators. If the generator opts not
 * to define a trait, then a default trait will be assigned.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Traits
{
public:
  /// Default constructor.
  CUTS_BE_Traits (void);

  /// Destructor.
  virtual ~CUTS_BE_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void close_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_includes (
    const CUTS_String_Set & includes);

  // @@ begin component implementation

  virtual void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_InEventPort_end (
    const PICML::InEventPort & sink);

  virtual void write_ProvidedRequestPort_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_ProvidedRequestPort_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_Attribute_end (
    const PICML::Attribute & attr);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & ro_attr);

  virtual void write_ReadonlyAttribute_end (
    const PICML::ReadonlyAttribute & ro_attr);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_PeriodicEvent_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_environment_method_begin (
    const PICML::InputAction &);

  virtual void write_environment_method_end (
    const PICML::InputAction &);

  virtual void write_environment_end (
    const PICML::Component & component);

  virtual void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  // @@ end component implementation

  // @@ begin facet implementation

  virtual void write_object_impl_begin (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  virtual void write_OnewayOperation_begin (
    const PICML::OnewayOperation & oneway);

  virtual void write_OnewayOperation_end (
    const PICML::OnewayOperation & oneway);

  virtual void write_TwowayOperation_begin (
    const PICML::TwowayOperation & twoway);

  virtual void write_TwowayOperation_end (
    const PICML::TwowayOperation & twoway);

  virtual void write_object_impl_end (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  // @@ end facet implementation

  // @@ begin home implementation

  virtual void write_factory_impl_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_FactoryOperation_begin (
    const PICML::FactoryOperation & factory);

  virtual void write_FactoryOperation_end (
    const PICML::FactoryOperation & factory);

  virtual void write_factory_impl_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  // @@ end home implementation

  virtual void write_variables_begin (
    const PICML::Component & component);

  virtual void write_variable (
    const PICML::Variable & variable);

  virtual void write_worker_variable (
    const PICML::WorkerType & type,
    const PICML::Worker & worker);

  virtual void write_ReadonlyAttribute_variable (
    const PICML::ReadonlyAttribute & readonly);

  virtual void write_PeriodicEvent_variable (
    const PICML::PeriodicEvent & periodic);

  virtual void write_variables_end (void);

  virtual void write_precondition (
    const std::string & precondition);

  virtual void write_postcondition (
    const std::string & precondition);

  virtual void write_WorkerAction_begin (
    const PICML::Worker & worker,
    const PICML::Action & action);

  virtual void write_OutputAction_begin (
    const PICML::OutputAction & action);

  virtual void write_action_property (
    const PICML::Property & property);

  virtual void write_action_end (void);

private:
  // prevent the following operations
  CUTS_BE_Traits (const CUTS_BE_Traits &);
  const CUTS_BE_Traits & operator = (const CUTS_BE_Traits &);
};

#if defined (__CUTS_INLINE__)
#include "BE_Traits.inl"
#endif

#endif  // !defined _CUTS_BE_TRAITS_H_
