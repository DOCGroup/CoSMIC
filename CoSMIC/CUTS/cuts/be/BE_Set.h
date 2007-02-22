// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Set_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_LIST_T_H_
#define _CUTS_BE_LIST_T_H_

#include "BE_Traits.h"
#include <set>

//=============================================================================
/**
 * @class CUTS_BE_List_T
 *
 * Static list of backend traits. This list uses generator programming
 * techniques to create the most optimal (in terms of speed) generator
 * for a particular backend.
 *
 * This list object is used by parameterizing the first parameter with
 * backend trait that derives from CUTS_BE_Traits. The second parameter
 * is a CUTS_BE_List_T with that is parameterized with another class
 * that derives from CUTS_BE_Traits. This process continues until all
 * traits included. To end the list specification, the second parameter
 * of the last node is left blank.
 *
 * @todo Create a specialization of this class for the last trait in
 *       the list. Right now we are depending on _traits_nil, which is
 *       a type definition for CUTS_BE_Traits. During iteration an extra
 *       node is parsed, i.e., CUTS_BE_Traits, everytime even when this
 *       is really not necessary. It does help that CUTS_BE_Traits has
 *       everything inlined, but this issue still needs to be addressed.
 */
//=============================================================================

class CUTS_BE_Set : public CUTS_BE_Traits
{
public:
  /// Default constructor.
  CUTS_BE_Set (void);

  /// Destructor.
  virtual ~CUTS_BE_Set (void);

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
  /// Type definition for the collection of strategies.
  typedef std::set <CUTS_BE_Traits *> Strategy_Set;

  /// Collection of strategy generators.
  Strategy_Set strats_;
};

#if defined (__CUTS_INLINE__)
#include "BE_Set.inl"
#endif

#endif  // !defined _CUTS_BE_LIST_T_H_
