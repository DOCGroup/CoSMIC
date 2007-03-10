// -*- C++ -*-

//=============================================================================
/**
 * @file        Natural_Lang_Generator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_NATURAL_LANG_GENERATOR_H_
#define _CUTS_BE_NATURAL_LANG_GENERATOR_H_

#include "Natural_Lang_export.h"
#include "cuts/be/BE_Traits.h"
#include <fstream>

namespace CUTS_BE
{
//=============================================================================
/**
 * @class Natural_Lang_Generator
 *
 * Natural language generator for the CUTS backend. This generator
 * write .txt files that contains a description of each implementation
 * and it's behavior.
 */
//=============================================================================

class CUTS_BE_NATURAL_LANG_Export Natural_Lang_Generator :
  public CUTS_BE_Traits
{
public:
  /// Default contructor.
  Natural_Lang_Generator (void);

  /// Destructor.
  virtual ~Natural_Lang_Generator (void);

  // Open the output file.
  bool open_file (
    const PICML::ComponentImplementationContainer & container);

  // Close the output file.
  void close_file (
    const PICML::ComponentImplementationContainer & container);

  // Write the beginning of the implemenation.
  void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  // Write the InEventPort description.
  void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  // End of the InEventPort description.
  void write_InEventPort_end (
    const PICML::InEventPort & sink);

  // Write the PeriodicEvent description.
  void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & event);

  // End of the PeriodicEvent description.
  void write_PeriodicEvent_end (
    const PICML::PeriodicEvent & event);

  // Write the WorkerAction description
  void write_WorkerAction_begin (
    const PICML::Worker & worker,
    const PICML::Action & action);

  // Write the OutputAction description
  void write_OutputAction_begin (
    const PICML::OutputAction & action);

  // Write the property for an action.
  void write_action_property (
    const PICML::Property & property);

  // End the WorkerAction description
  void write_action_end (void);

  // Write the beginning of environment action description.
  void write_environment_method_begin (
    const PICML::InputAction & action);

  // Write the end of environment action description.
  void write_environment_method_end (
    const PICML::InputAction & action);

  // Write the beginning of the variables.
  void write_variables_begin (
    const PICML::Component & component);

  // Write the variable.
  void write_variable (const PICML::Variable & variable);

  void write_worker_variable (
    const PICML::WorkerType & type,
    const PICML::Worker & worker);

private:
  /// The output file stream for the generator.
  std::ofstream outfile_;

  /// The indentation count.
  size_t indent_;
};

}

#if defined (__CUTS_INLINE__)
#include "Natural_Lang_Generator.inl"
#endif

#endif  // !defined _CUTS_BE_NATURAL_LANG_GENERATOR_H_
