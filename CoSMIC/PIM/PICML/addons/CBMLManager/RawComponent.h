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

#include <string>
#include <set>
#include <map>
#include "GME/FCO.h"
#include "GME/Object.h"

/**
 * @struct point_t
 *
 * Structure that contains an x-coordinate and y-coordinate.
 */
struct point_t
{
  /// Default constructor.
  point_t (void)
    : x_ (0), y_ (0) { }

  /**
   * Shift the point.
   *
   * @param[in]     x       X-coordinate shift value.
   * @param[in]     y       Y-coordinate shift value.
   */
  void shift (long x, long y)
  {
    this->x_ += x;
    this->y_ += y;
  }

  /// X-coordinate
  long x_;

  /// Y-coordinate
  long y_;
};

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
   * Helper method to get the position of an FCO.
   *
   * @param[in]     fco         Target FCO.
   * @param[out]    pt          Buffer to receive the position.
   */
  bool get_position (GME::FCO & fco, point_t & pt);

  /**
   * Helper method to set the position of an FCO.
   *
   * @param[in]     fco         Target FCO.
   * @param[in]     pt          New position of the FCO.
   */
  bool set_position (GME::FCO & fco, const point_t & pt);

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

  typedef std::set <std::string> string_set;

  /// Type definition for mapping worker types to instances.
  typedef std::map <GME::Model, string_set> worker_map_type;

  /// Collection of action types we are monitoring.
  static string_set actions_types_;

  /// The active state in the model.
  GME::FCO active_state_;

  GME::FCO last_action_;

  std::set <GME::Model> worker_types_;

  /// Collection of worker types.
  worker_map_type workers_;

  /// List of output ports in current model.
  string_set outputs_;

  /// Flag specifying if the add-on is importing.
  bool importing_;
};

#endif  // !defined RAWCOMPONENT_H
