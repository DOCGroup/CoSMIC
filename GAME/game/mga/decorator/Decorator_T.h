// -*- C++ -*-

//=============================================================================
/**
 * @file        Decorator_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_DECORATOR_T_H_
#define _GAME_MGA_DECORATOR_T_H_

#include <map>
#include "game/mga/FCO.h"
#include "game/mga/utils/Point.h"

namespace GAME
{
namespace Mga
{
// Forward decl.
class Decorator_Impl;

/**
 * @class ComponentEx_T
 */
template <typename T, const CLSID * pclsid = &CLSID_NULL>
class ATL_NO_VTABLE Decorator_T :
  public ATL::CComObjectRootEx <ATL::CComSingleThreadModel>,
  public ATL::CComCoClass < Decorator_T <T>, pclsid >,
  public IMgaDecorator,
  public IGMEVersionInfo
{
public:
  /// Default constructor.
  Decorator_T (void);

  /// Destructor.
  ~Decorator_T (void);

  DECLARE_PROTECT_FINAL_CONSTRUCT ()
  DECLARE_NO_REGISTRY ()

  BEGIN_COM_MAP (Decorator_T <T>)
    COM_INTERFACE_ENTRY (IMgaDecorator)
    COM_INTERFACE_ENTRY (IGMEVersionInfo)
  END_COM_MAP()

  // IMgaDecorator
  STDMETHOD (Initialize) (IMgaProject* pProject, IMgaMetaPart* pPart, IMgaFCO* pFCO);
  STDMETHOD (Destroy) (void);
  STDMETHOD (GetMnemonic)  (BSTR * bstrMnemonic );
  STDMETHOD (GetFeatures)  (feature_code* pFeatureCodes );
  STDMETHOD (SetParam) (BSTR bstrName, VARIANT vValue );
  STDMETHOD (GetParam) (BSTR bstrName, VARIANT* pvValue );
  STDMETHOD (SetActive) (VARIANT_BOOL bIsActive );
  STDMETHOD (GetPreferredSize) (LONG* plWidth, LONG* plHeight );
  STDMETHOD (SetLocation) (LONG sx, LONG sy, LONG ex, LONG ey );
  STDMETHOD (GetLocation) (LONG* sx, LONG* sy, LONG* ex, LONG* ey );
  STDMETHOD (GetLabelLocation) (LONG* sx, LONG* sy, LONG* ex, LONG* ey );
  STDMETHOD (GetPortLocation) (IMgaFCO* fco, LONG* sx, LONG* sy, LONG* ex, LONG* ey );
  STDMETHOD (GetPorts) (IMgaFCOs** portFCOs);
  STDMETHOD (Draw) (ULONG hdc);
  STDMETHOD (SaveState) (void);

  //  IMgaElementDecorator
  STDMETHOD (InitializeEx) (IMgaProject* pProject, IMgaMetaPart* pPart, IMgaFCO* pFCO, IMgaCommonDecoratorEvents* eventSink, ULONGLONG parentWnd);
  STDMETHOD (DrawEx) (ULONG hdc, ULONGLONG gdipGraphics );
  STDMETHOD (SetSelected) (VARIANT_BOOL bIsSelected );
  STDMETHOD (MouseMoved) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseLeftButtonDown) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseLeftButtonUp) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseLeftButtonDoubleClick) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseRightButtonDown) (ULONGLONG hCtxMenu, ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseRightButtonUp) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseRightButtonDoubleClick)  (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseMiddleButtonDown) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseMiddleButtonUp) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseMiddleButtonDoubleClick) (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MouseWheelTurned) (ULONG nFlags, LONG distance, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (DragEnter) (ULONG* dropEffect, ULONGLONG pCOleDataObject, ULONG keyState, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (DragOver) (ULONG* dropEffect, ULONGLONG pCOleDataObject, ULONG keyState, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (Drop) (ULONGLONG pCOleDataObject, ULONG dropEffect, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (DropFile) (ULONGLONG hDropInfo, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (MenuItemSelected) (ULONG menuItemId, ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC );
  STDMETHOD (OperationCanceled) (void);

  // IMgaVersionInfo interface
  STDMETHOD (get_version) (GMEInterfaceVersion_enum *pVal);

private:
  /// The implementation of the decorator.
  T impl_;

  /// Pointer to the implementation.
  Decorator_Impl * impl_ptr_;

  /// Initializing state for the decorator.
  bool is_init_;

  /// State that determines if the location is set.
  bool is_loc_set_;

  /// Collection of ports and their location.
  typedef std::map <GAME::Mga::FCO, GAME::Mga::Rect> port_map_t;

  port_map_t ports_;
};

}
}

#define DECLARE_DECORATOR(type, impl) \
  typedef GAME::Mga::Decorator_T <impl, &CLSID_##type> impl##_AutoImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_AutoImpl)

#if defined (__GAME_INLINE__)
#include "Decorator_T.inl"
#endif

#include "Decorator_T.cpp"

#endif  // !defined _GME_RAW_COMPONENT_I_H_
