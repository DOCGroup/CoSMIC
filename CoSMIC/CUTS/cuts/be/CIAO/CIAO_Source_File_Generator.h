// $Id$

//=============================================================================
/**
 * @file      Source_File_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_SOURCE_FILE_GENERATOR_H_
#define _CUTS_BE_CIAO_SOURCE_FILE_GENERATOR_H_

#include "UDM_CIAO_Export.h"
#include "CIAO_File_Generator_Base.h"
#include "Port_Manager_T.h"
#include "cuts/be/String_Set.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Source_File_Generator
 *
 * CIAO source file generator for the CUTS-PICML backend that
 * uses UDM for modeling.
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_CIAO_Source_File_Generator :
  public CUTS_CIAO_File_Generator_Base
{
public:
  /// Type definition of the super class.
  typedef CUTS_CIAO_File_Generator_Base _super;

  /// Default constructor.
  CUTS_CIAO_Source_File_Generator (void);

  /// Destructor.
  virtual ~CUTS_CIAO_Source_File_Generator (void);

protected:
  /**
   * Open the basename for writing. The basename does not contain
   * the file extension, or any naming decoration. It's the
   * responsibility of this object to create the correct name.
   *
   * @param[in]     basename        Basename of the file.
   */
  virtual void open (const std::string & basename);

  /**
   * Write the preamble for the file.
   *
   * @param[in]     container       Top-most container of implementation.
   */
  virtual void write_preamble (
    const PICML::ComponentImplementationContainer & container);

  /**
   * Begin writing the code for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_component_begin (
    const PICML::Component & component);

  /// End writing the code for a component.
  virtual void write_component_end (
    const PICML::Component & component);

  /**
   * Begin writing the method for an event sink.
   *
   * @param[in]       sink          Source event sink.
   */
  virtual void write_method_begin (
    const PICML::InEventPort & sink);

  /**
   * Begin writing the method for a request port (facet).
   *
   * @param[in]       facet          Source request port.
   */
  virtual void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  /**
   * Begin writing the method for a periodic action.
   *
   * @param[in]       periodic       Source periodic action.
   */
  virtual void write_method_begin (
    const PICML::PeriodicAction & periodic);

  /// End writing the current method.
  virtual void write_method_end (void);

  /**
   * Begin writing a component factory.
   *
   * @param[in]   factory       Source factory.
   * @param[in]   component     Component created by factory.
   */
  virtual void write_component_factory_begin (
    const PICML::ComponentFactory & factory,
    const PICML::Component & component);

  /**
   * Begin writing a action.
   *
   * @param[in]       parent      Parent worker of the action.
   * @param[in]       action      Current action.
   */
  virtual void write_action_begin (
    const PICML::Worker & parent,
    const PICML::Action & action);

  /**
   * Begin writing an output action.
   *
   * @param[in]       action      Source action.
   */
  virtual void write_action_begin (
    const PICML::OutputAction & action);

  /// End writing an action.
  virtual void write_action_end (void);

  /**
   * Write the property of an action.
   *
   * @param[in]     property      Source property.
   */
  virtual void write_action_property (
    const PICML::Property & property);

  /**
   * Write the method that will register the OBV factory
   * with the ORB. This is done usually in the set_session_context
   * method.
   *
   * @param[in]     component       Source component.
   */
  void write_register_obv_factory (
    const std::string & event);

  /**
   * Write the set_session_context () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_set_session_context (
    const PICML::Component & component);

  /**
   * Write the ciao_preactivate () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_ciao_preactivate (
    const PICML::Component & component);

  /**
   * Write the ccm_activate () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_ccm_activate (
    const PICML::Component & component);

  /**
   * Write the ciao_postactivate () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_ciao_postactivate (
    const PICML::Component & component);

  /**
   * Write the ccm_passivate () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_ccm_passivate (
    const PICML::Component & component);

  /**
   * Write the ccm_remove () method for a component.
   *
   * @param[in]     component       Source component.
   */
  virtual void write_ccm_remove (
    const PICML::Component & component);

  /// End writing an environment method.
  virtual void write_environment_end (void);

private:
  /**
   * Initialize the port manager for output events. This
   * is a temporary method that will eventually be forced
   * down into the framework.
   *
   * @param[in]       component       Source component.
   */
  void init_outevent_mgr (
    const PICML::Component & component);

  /// Write the dummy activate record in a method.
  void write_dummy_record (void);

  /// Collection of events for this component.
  CUTS_String_Set events_;

  /// Collection of the event sink names.
  CUTS_String_Set event_sinks_;

  /// Flag for determining if the current action is being
  /// skipped.
  bool skip_action_;

  /// Flag for determining if environment methd should
  /// be ignored.
  bool ignore_env_;

  /// Manager for mapping port types to their scoped name.
  CUTS_UDM_Port_Manager_T <const PICML::OutEventPort> outevent_mgr_;
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Source_File_Generator.inl"
#endif

#endif  // !defined _CUTS_BE_CIAO_SOURCE_FILE_GENERATOR_H_
