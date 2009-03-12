// -*- C++ -*-

//=============================================================================
/**
 * @file        RawComponent.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef RAWCOMPONENT_H
#define RAWCOMPONENT_H

#ifdef BUILDER_OBJECT_NETWORK
# error This file should only be included in the RAW COM configurations
#endif

#include "game/FCO.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"
#include <string>
#include <set>
#include <map>

/**
 * @class RawComponent
 *
 * Raw component interface for the add-on.
 */
class RawComponent
{
public:
  /// Default constructor.
  RawComponent (void);

  /// Destructor.
  ~RawComponent (void);

#if defined (GME_ADDON)
  /// Pointer to the project for the add-on.
  CComPtr <IMgaProject> project;

  /// Pointer to the add-on for this project.
  CComPtr <IMgaAddOn> addon;
#endif

  /// Interactive flag for the component.
  bool interactive;

  STDMETHODIMP Initialize (struct IMgaProject *);

  STDMETHODIMP Invoke (IMgaProject* gme,
                       IMgaFCOs *models,
                       long param);

  STDMETHODIMP InvokeEx (IMgaProject *project,
                         IMgaFCO *currentobj,
                         IMgaFCOs *selectedobjs,
                         long param);

  STDMETHODIMP ObjectsInvokeEx (IMgaProject *project,
                                IMgaObject *currentobj,
                                IMgaObjects *selectedobjs,
                                long param);

  STDMETHODIMP get_ComponentParameter (BSTR name,
                                       VARIANT *pVal);

  STDMETHODIMP put_ComponentParameter (BSTR name,
                                       VARIANT newVal);

#if defined (GME_ADDON)
  STDMETHODIMP GlobalEvent (globalevent_enum event);

  STDMETHODIMP ObjectEvent (IMgaObject * obj,
                            unsigned long eventmask,
                            VARIANT v);
#endif

private:
  /// Event handler for OBJEVENT_CREATED.
  void handle_objevent_created (GME::Object & obj);

  /// Event handler for OBJEVENT_SELECT.
  void handle_objevent_select (GME::Object & obj);

  /// Event handler for OBJEVENT_DESTROYED.
  void handle_objevent_destroyed (GME::Object & obj);

  void handle_objevent_modelopen (GME::Object & obj);

  void handle_objevent_modelclose (GME::Object & obj);

  /**
   * Helper method that will create a state and connect it to the
   * source object with the specified connection.
   *
   * @param[in]     src         Source object in connection.
   * @param[in]     conntype    Connection type between source and state.
   */
  void create_state_and_connect (GME::Object & src,
                                 const std::string & conntype);

  /**
   * Load the active state for the current model. This will allow
   * the user to continue defining the behavior were they left
   * off.
   *
   * @param[in]     model       Parent model.
   */
  void load_active_state (GME::Object & model);

  /**
   * Save the active state. This will store in the parent model's
   * registry the relative id of the active state. This will allow
   * use to retrieve/set the active state when the user return's
   * to the model.
   */
  void save_active_state (void);

  void cache_worker_type (const GME::Reference & worker_type);

  void resolve_worker_action (GME::FCO & action);

  void resolve_output_action (GME::FCO & action);

  typedef std::set <std::string> string_set;

  /// Type definition for mapping worker types to instances.
  typedef std::map <GME::Model, string_set> worker_map_type;

  /// Collection of action types we are monitoring.
  static string_set actions_types_;

  ACE_Hash_Map_Manager <ACE_CString,
                        std::string,
                        ACE_Null_Mutex> state_transition_map_;

  /// The active state in the model.
  GME::FCO active_state_;

  GME::FCO last_action_;

  std::set <GME::Model> worker_types_;

  /// Collection of worker types.
  worker_map_type workers_;

  /// Flag specifying if the add-on is importing.
  bool importing_;
};

#endif  // !defined RAWCOMPONENT_H
