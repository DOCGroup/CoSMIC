#ifndef RAWCOMPONENT_H
#define RAWCOMPONENT_H


// Declaration of the main RAW COM component interface class

#ifdef BUILDER_OBJECT_NETWORK
#error   This file should only be included in the RAW COM configurations
#endif

// Forward decl.
class CUdmApp;

/**
 * @class RawComponent
 */
class RawComponent
{
public:
  /// Default constructor.
  RawComponent (void);

  /// Destructor.
  ~RawComponent (void);

  STDMETHODIMP Initialize (struct IMgaProject *);
  STDMETHODIMP Invoke (IMgaProject* gme, IMgaFCOs *models, long param);
  STDMETHODIMP InvokeEx ( IMgaProject *project,  IMgaFCO *currentobj,  IMgaFCOs *selectedobjs,  long param);
  STDMETHODIMP ObjectsInvokeEx ( IMgaProject *project,  IMgaObject *currentobj,  IMgaObjects *selectedobjs,  long param);
  STDMETHODIMP get_ComponentParameter(BSTR name, VARIANT *pVal);
  STDMETHODIMP put_ComponentParameter(BSTR name, VARIANT newVal);

  bool interactive;

private:
  /// The actual UDM appliction.
  CUdmApp * app_;
};



#endif //RAWCOMPONENT_H