// -*- C++ -*-

#ifndef _GME_INTERPRETER_T_H_
#define _GME_INTERPRETER_T_H_

#include "ComponentEx_T.h"

namespace GAME
{
/**
 * @class Interpreter_T
 */
template <typename T, const CLSID * pclsid = &CLSID_NULL>
class Interpreter_T :
  public GAME::ComponentEx_T < Interpreter_T < T >, pclsid>
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

protected:
  /// The actual implementation of the interpreter
  T impl_;
};
}

#define DECLARE_GAME_INTERPRETER(type, impl) \
  typedef GAME::Interpreter_T <impl, &CLSID_##type> impl##_AutoImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_AutoImpl)

#if defined (__GAME_INLINE__)
#include "Interpreter_T.inl"
#endif

#include "Interpreter_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
