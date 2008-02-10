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

#include "gme/GME_fwd.h"

// Forward decl.
class PICML_DT_Control;

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

private:
  /**
   * Get the data type of a property element.
   *
   * @param[in]     object        The source property.
   * @param[in]     datatype      The data type of the property.
   * @retval        true          Successfully retrieved the data type.
   * @retval        false         Failed to retrieve the data type.
   */
  bool get_datatype (const GME::FCO & property, GME::FCO & datatype);
};

#endif  // !defined RAWCOMPONENT_H
