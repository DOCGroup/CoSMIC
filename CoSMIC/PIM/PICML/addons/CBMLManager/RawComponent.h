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

//=============================================================================
/**
 * @struct point_t
 *
 * Structure that contains an x-coordinate and y-coordinate.
 */
//=============================================================================

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

//=============================================================================
/**
 * @class RawComponent
 *
 * Raw component interface for the add-on.
 */
//=============================================================================

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
  void handle_objevent_created (IMgaObject * object);

  /// Event handler for OBJEVENT_SELECT.
  void handle_objevent_select (IMgaObject * object);

  /// Event handler for OBJEVENT_DESTROYED.
  void handle_objevent_destroyed (IMgaObject * object);

  /**
   * Helper method for creating a state element programmtically.
   *
   * @param[in]       parent        Pointer to the parent model.
   * @param[in]       state         Pointer to the newly created state.
   * @return          Result of the creation operation.
   */
  HRESULT create_model (const std::wstring & type,
                        IMgaModel * parent,
                        IMgaFCO ** state);

  /**
   * Helper method for creating a connection.
   *
   * @param[in]       type      Type of connection.
   * @param[in]       parent    Parent model of the connection.
   * @param[in]       src       Source FCO in connection.
   * @param[in]       dst       Destination FCO in connection.
   * @param[out]      conn      Pointer to new connection.
   */
  HRESULT create_connection (const std::wstring & type,
                             IMgaModel * parent,
                             IMgaFCO * src,
                             IMgaFCO * dst,
                             IMgaFCO ** conn);

  /**
   * Helper method that will create a state and connect it to the
   * source object with the specified connection.
   *
   * @param[in]     src         Source object in connection.
   * @param[in]     conntype    Connection type between source and state.
   */
  HRESULT create_state_and_connect (IMgaObject * src,
                                    const std::wstring & conntype);

  /**
   * Helper method for getting the role of a child element from a
   * model.
   *
   * @param[in]     model         Target model.
   * @param[in]     rolename      Name of the role.
   * @param[out]    role          Pointer to the role.
   */
  HRESULT get_role (IMgaModel * model,
                    const std::wstring & rolename,
                    IMgaMetaRole ** role);

  /**
   * Helper method to get the position of an FCO.
   *
   * @param[in]     fco         Target FCO.
   * @param[out]    pt          Buffer to receive the position.
   */
  HRESULT get_position (IMgaFCO * fco, point_t & pt);

  /**
   * Helper method to set the position of an FCO.
   *
   * @param[in]     fco         Target FCO.
   * @param[in]     pt          New position of the FCO.
   */
  HRESULT set_position (IMgaFCO * fco, const point_t & pt);

  /**
   * Load the active state for the current model. This will allow
   * the user to continue defining the behavior were they left
   * off.
   *
   * @param[in]     model       Parent model.
   */
  HRESULT load_active_state (IMgaObject * model);

  /**
   * Save the active state. This will store in the parent model's
   * registry the relative id of the active state. This will allow
   * use to retrieve/set the active state when the user return's
   * to the model.
   */
  HRESULT save_active_state (void);

  /// Type definition for a collection of strings.
  typedef std::set <std::wstring> wstring_set;

  /// Collection of action types we are monitoring.
  static wstring_set actions_types_;

  /// Type definition for a mapping role names to role objects.
  typedef std::map <std::wstring, CComPtr <IMgaMetaRole> > MgaMetaRole_Map;

  /// Mapping of role names to role objects.
  MgaMetaRole_Map role_map_;

  /// The active state in the model.
  CComPtr <IMgaFCO> active_state_;

  CComPtr <IMgaFCO> last_action_;

  /// Flag specifying if the add-on is importing.
  bool importing_;
};

#endif  // !defined RAWCOMPONENT_H
