// -*- C++ -*-

//=============================================================================
/**
 * @file        CBML_Model_Intelligence.h
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

#include <string>
#include <set>
#include <map>

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

#include "game/FCO.h"
#include "game/be/Addon_Impl_T.h"
#include "game/be/ComponentEx_T.h"
#include "game/be/Event_Handler_Impl.h"

GAME_DEFAULT_ADDON_IMPL (CBML_Manager_ComponentEx_Impl,
                         "CBML Model Intelligence",
                         "PICML",
                         "MGA.AddOn.CBMLManager");

/**
 * @class CBML_Model_Intelligence
 *
 * Raw component interface for the add-on.
 */
class CBML_Model_Intelligence : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  CBML_Model_Intelligence (void);

  /// Destructor.
  virtual ~CBML_Model_Intelligence (void);

  virtual int initialize (GAME::Project project);

  virtual int handle_global_event (long global_event);

  virtual int handle_object_event (GAME::Object obj, unsigned long mask);

private:
  /// Event handler for OBJEVENT_CREATED.
  void handle_objevent_created (GAME::Object obj);

  /// Event handler for OBJEVENT_SELECT.
  void handle_objevent_select (GAME::Object obj);

  /// Event handler for OBJEVENT_DESTROYED.
  void handle_objevent_destroyed (GAME::Object obj);

  void handle_objevent_modelopen (GAME::Object obj);

  void handle_objevent_modelclose (GAME::Object obj);

  /**
   * Helper method that will create a state and connect it to the
   * source object with the specified connection.
   *
   * @param[in]     src         Source object in connection.
   * @param[in]     conntype    Connection type between source and state.
   */
  void create_state_and_connect (GAME::Object src, const std::string & conntype);

  /**
   * Load the active state for the current model. This will allow
   * the user to continue defining the behavior were they left
   * off.
   *
   * @param[in]     model       Parent model.
   */
  void load_active_state (GAME::Object model);

  /**
   * Save the active state. This will store in the parent model's
   * registry the relative id of the active state. This will allow
   * use to retrieve/set the active state when the user return's
   * to the model.
   */
  void save_active_state (void);

  void cache_worker_type (const GAME::Reference & worker_type);

  void resolve_worker_action (GAME::FCO action);

  void resolve_output_action (GAME::FCO action);

  typedef std::set <std::string> string_set;

  /// Type definition for mapping worker types to instances.
  typedef std::map <GAME::Model, string_set> worker_map_type;

  /// Collection of action types we are monitoring.
  static string_set actions_types_;

  ACE_Hash_Map_Manager <ACE_CString,
                        std::string,
                        ACE_Null_Mutex> state_transition_map_;

  /// The active state in the model.
  GAME::FCO active_state_;

  GAME::FCO last_action_;

  std::set <GAME::Model> worker_types_;

  /// Collection of worker types.
  worker_map_type workers_;

  /// Flag specifying if the add-on is importing.
  bool importing_;
};

#endif  // !defined RAWCOMPONENT_H
