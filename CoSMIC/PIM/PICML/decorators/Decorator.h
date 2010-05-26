// Decorator.h : Declaration of the CDecorator

#ifndef __DECORATOR_H_
#define __DECORATOR_H_

#include "DecoratorStd.h"
#include "DecoratorConfig.h"
#include "Resource.h"       // main symbols
#include "DecoratorLib.h"
#include "DecoratorUtil.h"
#include "MaskedBitmap.h"

class DecoratorBase;

/////////////////////////////////////////////////////////////////////////////
// CDecorator
class ATL_NO_VTABLE CDecorator : 
	public CComObjectRootEx <CComSingleThreadModel>,
	public IMgaElementDecorator,
	public CComCoClass <CDecorator, &CLSID_Decorator>
{
public:
  /// Default constructor
	CDecorator (void);

  /// Destructor.
	~CDecorator (void);

  DECLARE_REGISTRY_RESOURCEID (IDR_DECORATOR)

  DECLARE_PROTECT_FINAL_CONSTRUCT()

  BEGIN_COM_MAP(CDecorator)
	  COM_INTERFACE_ENTRY(IMgaElementDecorator)
  END_COM_MAP()

// IMgaDecorator
public:
	// =============== inherited from IMgaDecorator
	STDMETHOD( Initialize )						( /*[in]*/ IMgaProject* pProject, /*[in]*/ IMgaMetaPart* pPart, /*[in]*/ IMgaFCO* pFCO );
	STDMETHOD( Destroy )						( void );
	STDMETHOD( GetMnemonic )					( /*[out]*/ BSTR* bstrMnemonic );
	STDMETHOD( GetFeatures )					( /*[out]*/ feature_code* pFeatureCodes );
	STDMETHOD( SetParam )						( /*[in]*/ BSTR bstrName, /*[in]*/ VARIANT vValue );
	STDMETHOD( GetParam )						( /*[in]*/ BSTR bstrName, /*[out]*/ VARIANT* pvValue );
	STDMETHOD( SetActive )						( /*[in]*/ VARIANT_BOOL bIsActive );
	STDMETHOD( GetPreferredSize )				( /*[out]*/ LONG* plWidth, /*[out]*/ LONG* plHeight );
	STDMETHOD( SetLocation )					( /*[in]*/ LONG sx, /*[in]*/ LONG sy, /*[in]*/ LONG ex, /*[in]*/ LONG ey );
	STDMETHOD( GetLocation )					( /*[out]*/ LONG* sx, /*[out]*/ LONG* sy, /*[out]*/ LONG* ex, /*[out]*/ LONG* ey );
	STDMETHOD( GetLabelLocation )				( /*[out]*/ LONG* sx, /*[out]*/ LONG* sy, /*[out]*/ LONG* ex, /*[out]*/ LONG* ey );
	STDMETHOD( GetPortLocation )				( /*[in]*/ IMgaFCO* fco, /*[out]*/ LONG* sx, /*[out]*/ LONG* sy, /*[out]*/ LONG* ex, /*[out]*/ LONG* ey );
	STDMETHOD( GetPorts )						( /*[out, retval]*/ IMgaFCOs** portFCOs );
	STDMETHOD( Draw )							( /*[in]*/ HDC hdc );
	STDMETHOD( SaveState )						( void );

#if GME_VERSION_MAJOR >= 10
	// =============== IMgaElementDecorator
	STDMETHOD( InitializeEx )					( /*[in]*/ IMgaProject* pProject, /*[in]*/ IMgaMetaPart* pPart, /*[in]*/ IMgaFCO* pFCO, /*[in]*/ IMgaCommonDecoratorEvents* eventSink, /*[in]*/ ULONGLONG parentWnd );
	STDMETHOD( DrawEx )							( /*[in]*/ HDC hdc, /*[in]*/ ULONGLONG gdipGraphics );
	STDMETHOD( SetSelected )					( /*[in]*/ VARIANT_BOOL bIsSelected );
	STDMETHOD( MouseMoved )						( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseLeftButtonDown )			( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseLeftButtonUp )				( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseLeftButtonDoubleClick )		( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseRightButtonDown )			( /*[in]*/ ULONGLONG hCtxMenu, /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseRightButtonUp )				( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseRightButtonDoubleClick )	( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseMiddleButtonDown )			( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseMiddleButtonUp )			( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseMiddleButtonDoubleClick )	( /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MouseWheelTurned )				( /*[in]*/ ULONG nFlags, /*[in]*/ LONG distance, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( DragEnter )						( /*[out]*/ ULONG* dropEffect, /*[in]*/ ULONGLONG pCOleDataObject, /*[in]*/ ULONG keyState, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( DragOver )						( /*[out]*/ ULONG* dropEffect, /*[in]*/ ULONGLONG pCOleDataObject, /*[in]*/ ULONG keyState, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( Drop )							( /*[in]*/ ULONGLONG pCOleDataObject, /*[in]*/ ULONG dropEffect, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( DropFile )						( /*[in]*/ ULONGLONG hDropInfo, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( MenuItemSelected )				( /*[in]*/ ULONG menuItemId, /*[in]*/ ULONG nFlags, /*[in]*/ LONG pointx, /*[in]*/ LONG pointy, /*[in]*/ ULONGLONG transformHDC );
	STDMETHOD( OperationCanceled )				( void );
#endif

private:
	bool m_isInitialized;
	bool m_isLocSet;
 	bool m_isActive;
  DecoratorBase*	m_pDecorator;

#if GME_VERSION_MAJOR >= 10
  // add for the new decorator
  bool m_bInitCallFromEx;
  CComPtr<IMgaCommonDecoratorEvents>	m_eventSink;
	HWND								m_parentWnd;
	bool								m_bSelected;
#endif

private:
	bool GetMetaFCO(const CComPtr<IMgaMetaPart> &metaPart, CComPtr<IMgaMetaFCO> &metaFco);
};


#endif //__DECORATOR_H_
