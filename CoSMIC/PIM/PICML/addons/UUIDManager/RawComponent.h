#ifndef RAWCOMPONENT_H
#define RAWCOMPONENT_H


// Declaration of the main RAW COM component interface class


#ifdef BUILDER_OBJECT_NETWORK
#error   This file should only be included in the RAW COM configurations
#endif

#include "Component_Listener.h"

class RawComponent
{
public:
  RawComponent (void);

  virtual ~RawComponent (void);

  CComPtr <IMgaAddOn> addon;      // this is set before Initialize() is called

  bool interactive;

  STDMETHODIMP Initialize (struct IMgaProject *);

  STDMETHODIMP Invoke (IMgaProject* gme, IMgaFCOs *models, long param);

  STDMETHODIMP InvokeEx (
    IMgaProject *project,
    IMgaFCO *currentobj,
    IMgaFCOs *selectedobjs,
    long param);

  STDMETHODIMP ObjectsInvokeEx (
    IMgaProject *project,
    IMgaObject *currentobj,
    IMgaObjects *selectedobjs,
    long param);

  STDMETHODIMP get_ComponentParameter (BSTR name, VARIANT *pVal);
  STDMETHODIMP put_ComponentParameter (BSTR name, VARIANT newVal);

  STDMETHODIMP GlobalEvent (globalevent_enum event);

  STDMETHODIMP ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v);

private:
  CComPtr <IMgaProject> project_;

  CComObjectNoLock <Component_Listener> component_listener_;
};


#endif //RAWCOMPONENT_H