// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Impl_Generator_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_IMPL_GENERATOR_T_H_
#define _CUTS_BE_IMPL_GENERATOR_T_H_

#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_Impl_Generator_T
 *
 * Implementation generator for CUTS. This class is parameterized
 * by a backend trait that determines what is generated. This class
 * only contains the parsing logic for generating the inplementation.
 * The backend traits that are used when generating the implemenation
 * can be found in CUTS_BE_Traits.
 */
//=============================================================================

template <typename IMPL_STRATEGY>
class CUTS_BE_Impl_Generator_T : public PICML::Visitor
{
public:
  /// Default constructor.
  CUTS_BE_Impl_Generator_T (void);

  /// Destructor.
  virtual ~CUTS_BE_Impl_Generator_T (void);

  void generate (const PICML::RootFolder & root);

protected:
  /// Visit a RootFolder element.
  void Visit_RootFolder (
    const PICML::RootFolder & root);

  /// Visit a ComponentImplementations folder.
  void Visit_ComponentImplementations (
    const PICML::ComponentImplementations & impls);

  /// Visit a ComponentImplementationContainer element.
  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer & container);

  /// Visit a MonolithicImplementation element.
  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation & monoimpl);

  /// Visit a Component element.
  void Visit_Component (
    const PICML::Component & component);

  /// Visit a InEventPort element.
  void Visit_InEventPort (
    const PICML::InEventPort & sink);

  /// Visit a ProvidedRequestPort element.
  void Visit_ProvidedRequestPort (
    const PICML::ProvidedRequestPort & facet);

  /// Visit a ProvidedRequestPort element.
  void Visit_PeriodicEvent (
    const PICML::PeriodicEvent & periodic);

  /// Visit a ReadonlyAttribute element.
  void Visit_ReadonlyAttribute (
    const PICML::ReadonlyAttribute  & ro_attr);

  /// Visit an Attribute element.
  void Visit_Attribute (
    const PICML::Attribute & attr);

  /// Visit a Variable element.
  void Visit_Variable (
    const PICML::Variable & variable);

  /// Visit a WorkerType element.
  void Visit_WorkerType (
    const PICML::WorkerType & type);

private:
  bool get_component_factory (const PICML::Component & component,
                              PICML::ComponentFactory & factory);

  /// The traits for the generators.
  IMPL_STRATEGY traits_;

  // prevent the following operations
  CUTS_BE_Impl_Generator_T (const CUTS_BE_Impl_Generator_T &);
  const CUTS_BE_Impl_Generator_T & operator = (const CUTS_BE_Impl_Generator_T &);
};

#if defined (__CUTS_INLINE__)
#include "BE_Impl_Generator_T.inl"
#endif

#include "BE_Impl_Generator_T.cpp"

#endif  // !defined _CUTS_BE_IMPL_GENERATOR_T_H_