// $Id$

#include "stdafx.h"

#include "Common.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "PICML/Utils.h"
#include <string>

class COM_Exception
{
public:
  COM_Exception (void) { }
  ~COM_Exception (void) { }
};

#define VERIFY_RESULT(x) \
  if (FAILED (x)) \
    throw COM_Exception ();

//
// RawComponent
//
RawComponent::RawComponent (void)
{

}

RawComponent::~RawComponent (void)
{

}

//
// Initaialize
//
STDMETHODIMP RawComponent::Initialize (struct IMgaProject *)
{
  try
  {
    unsigned long mask =
      OBJEVENT_CREATED | OBJEVENT_DESTROYED | OBJEVENT_ATTR;

    VERIFY_RESULT (this->addon->put_EventMask (mask));
  }
  catch (COM_Exception &)
  {

  }
  return S_OK;
}

//
// Invoke [obsolete]
//
STDMETHODIMP RawComponent::Invoke (IMgaProject* gme,
                                   IMgaFCOs *models,
                                   long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// InvokeEx
//
STDMETHODIMP RawComponent::InvokeEx (IMgaProject *project,
                                     IMgaFCO *currentobj,
                                     IMgaFCOs *selectedobjs,
                                     long param)
{
  return E_MGA_NOT_SUPPORTED;
}


//
// ObjectsInvokeEx [not implemented]
//
STDMETHODIMP RawComponent::ObjectsInvokeEx (IMgaProject *project,
                                            IMgaObject *currentobj,
                                            IMgaObjects *selectedobjs,
                                            long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// get_ComponentParameter
//
STDMETHODIMP RawComponent::get_ComponentParameter(BSTR name, VARIANT *pVal)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// put_ComponentParameter
//
STDMETHODIMP RawComponent::put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// GlobalEvent
//
STDMETHODIMP RawComponent::GlobalEvent (globalevent_enum event)
{
  try
  {
    if (event == GLOBALEVENT_OPEN_PROJECT)
    {
      VERIFY_RESULT (this->addon->get_Project (&this->project_));

      IMgaTerritory * territory = 0;
      VERIFY_RESULT (
        this->project_->CreateTerritory (
        0, &territory, &this->component_listener_));

      this->component_listener_.territory (territory);

      // Get all the component (component assembly) objects.
      CComPtr <IMgaFilter> filter;
      this->project_->CreateFilter (&filter);

      filter->put_Kind (L"Component ComponentAssembly");
      filter->put_Level (L"0-");
      filter->put_ObjType (L"OBJTYPE_MODEL");

      CComPtr <IMgaFCOs> mga_fcos;
      VERIFY_RESULT (this->project_->AllFCOs (filter, &mga_fcos));

      long count;
      mga_fcos->get_Count (&count);

      for (long i = 1; i <= count; i ++)
      {
        CComPtr <IMgaFCO> mga_fco;
        mga_fcos->get_Item (i, &mga_fco);

        VARIANT_BOOL lib_object;
        mga_fco->get_IsLibObject (&lib_object);

        if (lib_object == VARIANT_FALSE)
        {
          this->component_listener_.listen_to_object (mga_fco);
        }
      }
    }
    else if (event == GLOBALEVENT_CLOSE_PROJECT)
    {
      CComPtr <IMgaTerritory> territory =
        this->component_listener_.territory (0);
    }
  }
  catch (COM_Exception &)
  {

  }
  catch (...)
  {

  }

  return S_OK;
}

//
// ObjectEvent
//
STDMETHODIMP RawComponent::ObjectEvent (IMgaObject * obj,
                                        unsigned long eventmask,
                                        VARIANT v)
{
  // We do not handle the <OBJEVENT_DESTROYED> event at this
  // level of the add-on.
  if ((eventmask & OBJEVENT_DESTROYED))
    return S_OK;


  CComPtr <IMgaObject> object (obj);

  // Determine if the object is a library object before
  // continuing.
  try
  {
    VARIANT_BOOL lib_object;
    VERIFY_RESULT (object->get_IsLibObject (&lib_object));

    if (lib_object == VARIANT_FALSE)
    {
      CComPtr <IMgaFCO> fco_object;
      VERIFY_RESULT (object.QueryInterface (&fco_object));

      // Get the meta information for the object.
      CComPtr <IMgaMetaFCO> meta_info;
      VERIFY_RESULT (fco_object->get_Meta (&meta_info));

      // Get the "type" of the object.
      CComBSTR bstr;
      VERIFY_RESULT (meta_info->get_Name (&bstr));

      if (bstr == L"Component" || bstr == L"ComponentAssembly")
      {
        if ((eventmask & OBJEVENT_CREATED) != 0)
        {
          this->component_listener_.listen_to_object (object);
        }
      }
    }
  }
  catch (COM_Exception &)
  {

  }

  return S_OK;
}
