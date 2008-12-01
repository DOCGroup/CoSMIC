// -*- C++ -*-

#ifndef _GME_INTERPRETER_T_H_
#define _GME_INTERPRETER_T_H_

#include "ComponentEx_T.h"

namespace GME
{
  /**
   * @class Interpreter_T
   */
  template <typename T, typename IMPL>
  class Interpreter_T : public GME::ComponentEx_T <T, &CLSID_MgaComponent>
  {
  public:
    /// Default constructor
    Interpreter_T (void);

    /// Destructor
    virtual ~Interpreter_T (void);

    STDMETHOD (Initialize) (IMgaProject * proj);
    STDMETHOD (Invoke) (IMgaProject * proj, IMgaFCOs * selected, long flags);
    STDMETHOD (Enable) (VARIANT_BOOL enable);
    STDMETHOD (get_InteractiveMode) (VARIANT_BOOL * mode);
    STDMETHOD (put_InteractiveMode) (VARIANT_BOOL mode);
    STDMETHOD (get_ComponentName) (BSTR * name);
    STDMETHOD (get_ComponentType) (componenttype_enum * type);
    STDMETHOD (get_Paradigm) (BSTR * paradigm);

    STDMETHOD (InvokeEx) (IMgaProject * proj, IMgaFCO * current, IMgaFCOs * selected, long flags);
    STDMETHOD (ObjectsInvokeEx) (IMgaProject *, IMgaObject *, IMgaObjects *, long);
    STDMETHOD (get_ComponentProgID) (BSTR *pVal);
    STDMETHOD (put_ComponentParameter) (BSTR name, VARIANT newVal);
    STDMETHOD (get_ComponentParameter) (BSTR name, VARIANT *pVal);

  private:
    /// The actual implementation of the interpreter
    IMPL impl_;
  };
}

#if defined (__GME_INLINE__)
#include "Interpreter_T.inl"
#endif

#include "Interpreter_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
