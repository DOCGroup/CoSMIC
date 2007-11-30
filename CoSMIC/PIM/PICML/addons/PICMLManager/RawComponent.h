/* -*- C++ -*- */

//=============================================================================
/**
 * @file      RawComponent.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef RAWCOMPONENT_H
#define RAWCOMPONENT_H

#ifdef BUILDER_OBJECT_NETWORK
#error   This file should only be included in the RAW COM configurations
#endif

#include <set>
#include "Utils/gme/GME.h"

//=============================================================================
/**
 * @class RawComponent
 *
 * Raw COM implementation of the PICML manager add-on.
 */
//=============================================================================

class RawComponent
{
public:
  /// Constructor.
  RawComponent (void);

  /// Destructor.
  virtual ~RawComponent (void);

  /* GME specific members */
  CComPtr <IMgaAddOn> addon;
  bool interactive;

  /* RawComponent specific methods */
  STDMETHODIMP Initialize (struct IMgaProject *);
  STDMETHODIMP Invoke (IMgaProject*, IMgaFCOs *, long );
  STDMETHODIMP InvokeEx (IMgaProject *, IMgaFCO *, IMgaFCOs *, long);
  STDMETHODIMP ObjectsInvokeEx (IMgaProject *, IMgaObject *, IMgaObjects *, long);
  STDMETHODIMP get_ComponentParameter (BSTR, VARIANT *);
  STDMETHODIMP put_ComponentParameter (BSTR, VARIANT);
  STDMETHODIMP GlobalEvent (globalevent_enum);
  STDMETHODIMP ObjectEvent (IMgaObject *, unsigned long, VARIANT);

private:
  /**
   * Create a UUID for the FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void create_uuid (const GME::FCO & fco);

  /**
   * Verify the UUID of an FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void verify_uuid (const GME::FCO & fco);

  /// This verifies all UUID's in the project.
  void verify_all_uuids (void);

  void handle_pending (void);

  /**
   * Get the UUID from a FCO object.
   *
   * @param[in]     fco       Source FCO
   * @param[out]    attr      Pointer to the UUID attribute.
   * @retval        true      The attribute was found.
   * @retval        false     The attribute was not found.
   */
  bool get_uuid_i (const GME::FCO & fco,
                   GME::Attribute & attr);

  void set_property_datatype (GME::Model & property,
                              const GME::FCO & type);

  void verify_property_datatype (GME::ConnectionPoint & attr,
                                 const GME::FCO & attr_type);

  /// The project is in import mode.
  int importing_;

  /// Collection of pending FCO's to validate.
  std::vector <GME::FCO> pending_;

  /// Interface pointer to the hosting project.
  GME::Project project_;

  /// PICML types with a UUID attribute.
  std::set <std::string> uuid_types_;
};


#endif /* RAWCOMPONENT_H */
