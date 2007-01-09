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

  /**
   * Open the file for the specified implementation container.
   *
   * @retval      true      Successfully opened the file.
   * @retval      false     Failed to open file.
   */
  bool open_file (
    const PICML::ComponentImplementationContainer & container);

  void close_file (
    const PICML::ComponentImplementationContainer & container);

  void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  void write_includes (
    const CUTS_String_Set & includes);

  void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  void write_factory_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  void write_factory_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  void write_method_begin (
    const PICML::InEventPort & sink);

  void write_method_end (
    const PICML::InEventPort & sink);

  void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  void write_method_end (
    const PICML::ProvidedRequestPort & facet);

  void write_method_begin (
    const PICML::Attribute & attr);

  void write_method_end (
    const PICML::Attribute & attr);

  void write_method_begin (
    const PICML::ReadonlyAttribute & ro_attr);

  void write_method_end (
    const PICML::ReadonlyAttribute & ro_attr);

  void write_environment_begin (
    const PICML::Component & component);

  void write_environment_end (
    const PICML::Component & component);

  void write_environment_method_begin (
    const PICML::InputAction &);

  void write_environment_method_end (
    const PICML::InputAction &);

  void write_variables_begin (
    const PICML::Component & component);

  void write_variable (
    const PICML::Variable & variable);

  void write_variable (
    const PICML::WorkerType & type,
    const PICML::Worker & worker);

  void write_variable (
    const PICML::ReadonlyAttribute & readonly);

  void write_variables_end (void);

  void write_precondition (
    const std::string & precondition);

  void write_postcondition (
    const std::string & precondition);

  void write_action_property (
    const PICML::Property & property);

  void write_action_begin (
    const PICML::Worker & worker,
    const PICML::Action & action);

  void write_action_begin (
    const PICML::OutputAction & action);

  void write_action_end (void);

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
