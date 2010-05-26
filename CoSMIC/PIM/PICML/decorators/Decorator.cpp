// $Id$

#include "stdafx.h"
#include "Decorator.h"
#include "IDMLDecorators.h"

#include "game/FCO.h"
#include "game/MetaRole.h"
#include "game/MetaFCO.h"

#define VERIFY_INIT   { if (!m_isInitialized) return E_DECORATOR_UNINITIALIZED; }
#define VERIFY_LOCSET { if (!m_isLocSet) return E_DECORATOR_LOCISNOTSET; }

/////////////////////////////////////////////////////////////////////////////
// CDecorator

STDMETHODIMP CDecorator::
Initialize (IMgaProject *project, IMgaMetaPart *metaPart, IMgaFCO *obj )
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
	  //
	  // TODO: read all important data from MGA and cache them for later use
	  //
#if GME_VERSION_MAJOR >= 10
    if (!this->m_bInitCallFromEx)
      return E_DECORATOR_USING_DEPRECATED_FUNCTION;
#endif

    CComPtr <IMgaMetaFCO> mf;
    if (!GetMetaFCO (metaPart, mf ))
      return E_DECORATOR_INIT_WITH_NULL;

    GME::Meta::FCO meta_fco (mf.Detach ());

    if (project && metaPart) 
    {
      // Get the object's type information.
      objtype_enum eType;

      if (obj)
      {
        GME::Object object (obj);
        eType = object.type ();
      }
      else
      {
        IMgaMetaRole * r = 0;
        COMTHROW (metaPart->get_Role( &r));
        
        GME::Meta::Role role (r);
        eType = role.kind ().type ();    
      }

      // Determine what kind of decorator to create. In the future, we 
      // should use COM correctly and create a seperate decorator for 
      // each case. Then, we can register each decorator under its own 
      // program id. Right now, we are manually doing what COM and the 
      // windows architecture will do automatically. Moreover, it should 
      // improve the decorator's performance.
      switch (eType)
      {
      case OBJTYPE_MODEL :
        m_pDecorator = new ComponentDecorator (metaPart);
        break;

      case OBJTYPE_REFERENCE :
        {
          std::string name = meta_fco.name ();

          if (NamespaceEquals (name, PICML_COMPONENTREF_NAME) || 
              NamespaceEquals (name, PICML_COMPONENTASMREF_NAME))
          {
            // ComponentDecorator draws ComponentRefs too.
            m_pDecorator = new ComponentDecorator (metaPart);
          }
          else if (NamespaceEquals (name, PICML_INHERITS_NAME))
          {
            m_pDecorator = new InheritsDecorator;
          }
          else
          {
            m_pDecorator = new MemberDecorator;
          }
        }

        break;
      }

      if (m_pDecorator)
        m_pDecorator->initialize (obj, meta_fco);

      m_isInitialized = true;
      return S_OK;
    }
  }
  catch (...)
  {

  }

  return E_DECORATOR_INIT_WITH_NULL;
}

STDMETHODIMP CDecorator::Destroy()
{
  //
  // TODO: At least free all references to MGA objects
  //
  VERIFY_INIT;
  m_isInitialized = false;
  m_isLocSet = false;
  m_pDecorator->destroy();
  return S_OK;
}

STDMETHODIMP CDecorator::GetMnemonic( BSTR *mnemonic )
{
  //
  // TODO: Return the logical name of the decorator (currently not used by GME)
  //
  *mnemonic = CComBSTR(DECORATOR_NAME).Detach();
  return S_OK;
}

STDMETHODIMP CDecorator::GetFeatures( feature_code *features )
{
  //
  // TODO: Return supported features (combine multiple features with bitwise-OR)
  // Available feature codes are found in MgaDecorator.idl
  // (curently not used by GME)
  *features = 0;
  return S_OK;
}

STDMETHODIMP CDecorator::SetParam( BSTR name, VARIANT value )
{
  //
  // TODO:  Parse and set all supported parameters, otherwise return error
  // (currently all values are BSTR type)
  //
  VERIFY_INIT;
  return E_DECORATOR_UNKNOWN_PARAMETER;
}

STDMETHODIMP CDecorator::GetParam( BSTR name, VARIANT* value )
{
  //
  // TODO: Return values of supported and previously set parameters, otherwise return error
  // (currently GME does not use this method)
  //
  VERIFY_INIT;
  return E_DECORATOR_UNKNOWN_PARAMETER;
}

STDMETHODIMP CDecorator::SetActive( VARIANT_BOOL isActive )
{
  VERIFY_INIT;
  m_pDecorator->setActive( isActive == VARIANT_TRUE );

  return S_OK;
}

STDMETHODIMP CDecorator::GetPreferredSize( long* sizex, long* sizey )
{
  VERIFY_INIT;

  CSize cSize = m_pDecorator->getPreferredSize();
  *sizex = cSize.cx;
  *sizey = cSize.cy;

  return S_OK;
}


STDMETHODIMP CDecorator::SetLocation( long sx,
                                      long sy,
                                      long ex,
                                      long ey )
{
  VERIFY_INIT;
  m_pDecorator->setLocation (CRect (sx, sy, ex, ey ) );
  m_isLocSet = true;

  return S_OK;
}

STDMETHODIMP CDecorator::GetLocation( long *sx,
                                      long *sy,
                                      long *ex,
                                      long *ey )
{
  VERIFY_INIT;
  VERIFY_LOCSET;
  CRect cRect = m_pDecorator->getLocation();
  *sx = cRect.left;
  *sy = cRect.top;
  *ex = cRect.right;
  *ey = cRect.bottom;

  return S_OK;
}

STDMETHODIMP CDecorator::GetLabelLocation( long *sx,
                                           long *sy,
                                           long *ex,
                                           long *ey )
{
  //
  // TODO: Return the location of the text box of your label if you support labels.
  // (currently GME does not call this)
  //
  VERIFY_INIT;
  VERIFY_LOCSET;
  return S_OK;
}

STDMETHODIMP CDecorator::GetPortLocation( IMgaFCO *pFCO,
                                          long *sx,
                                          long *sy,
                                          long *ex,
                                          long *ey )
{
  VERIFY_INIT;
  VERIFY_LOCSET;

  PortDecorator* pPort = m_pDecorator->getPort( pFCO );

  if ( pPort ) {
    CRect cRect = pPort->getBoxLocation();
    *sx = cRect.left;
    *sy = cRect.top;
    *ex = cRect.right;
    *ey = cRect.bottom;
    return S_OK;
  }

  return E_DECORATOR_PORTNOTFOUND;
}

STDMETHODIMP CDecorator::GetPorts (IMgaFCOs **portFCOs)
{
  try
  {
    VERIFY_INIT;
    CComPtr<IMgaFCOs> spFCOs;
    COMTHROW (spFCOs.CoCreateInstance (OLESTR("Mga.MgaFCOs")));

    vector <PortDecorator*> vecPorts = m_pDecorator->getPorts ();

    for ( unsigned int i = 0 ; i < vecPorts.size() ; i++ )
      COMTHROW (spFCOs->Append (vecPorts[ i ]->getFCO().impl ()));

    *portFCOs = spFCOs.Detach();
    return S_OK;
  }
  catch (...)
  {
    
  }

  return S_FALSE;
}


STDMETHODIMP CDecorator::Draw ( HDC hdc )
{
  VERIFY_INIT;
  VERIFY_LOCSET;

  CDC dc;
  dc.Attach( hdc );
  m_pDecorator->draw( &dc );
  dc.Detach();
  return S_OK;
}

STDMETHODIMP CDecorator::SaveState()
{
  //
  // TODO: The only method where we are in read-write transaction.
  // Store all permanent information
  // (currently GME does not support this)
  //
  VERIFY_INIT;
  return S_OK;
}

#if GME_VERSION_MAJOR >= 10
//
// InitializeEx
//
STDMETHODIMP CDecorator::
InitializeEx (IMgaProject* pProject,
              IMgaMetaPart* pPart, 
              IMgaFCO* pFCO,
              IMgaCommonDecoratorEvents* eventSink, 
              ULONGLONG parentWnd)
{
	//
	// TODO: handle extra parameters, call Initialize with the rest
	//
	m_bInitCallFromEx = true;

	// If this wouldn't be a simple decorator, we would initialize the Decorator utilities facility framework
	//DecoratorSDK::getFacilities().loadPathes(pProject, true);

	this->Initialize (pProject, pPart, pFCO);
	m_eventSink = eventSink;
	m_parentWnd = (HWND)parentWnd;

	return S_OK;
}

STDMETHODIMP CDecorator::DrawEx (HDC hdc, ULONGLONG gdipGraphics)
{
  //
	// TODO: gdipGraphics is a Gdiplus::Graphics* variable, it is advisable to use this for drawing and don't use the HDC
	//
  return this->Draw (hdc);

  //VERIFY_INIT;
  //VERIFY_LOCSET;

  //Gdiplus::Graphics * g = reinterpret_cast <Gdiplus::Graphics *> (gdipGraphics);
  //m_pDecorator->draw (*g);

  //return S_OK;
}

STDMETHODIMP CDecorator::SetSelected(VARIANT_BOOL vbIsSelected)
{
	//
	// TODO: memorize selected state, it might be needed for some operations later
	//
	//VERIFY_INITIALIZATION

	m_bSelected = (vbIsSelected == VARIANT_TRUE);

	return S_OK;
}

STDMETHODIMP CDecorator::MouseMoved(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, for example change the mouse cursor, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseLeftButtonDown(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseLeftButtonUp(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseLeftButtonDoubleClick(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//

	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseRightButtonDown(ULONGLONG hCtxMenu, ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// hCtxMenu is a HMENU type variable, you can add menu items to it which will be displayed in the context menu
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//

	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseRightButtonUp(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseRightButtonDoubleClick(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseMiddleButtonDown(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseMiddleButtonUp(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseMiddleButtonDoubleClick(ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MouseWheelTurned(ULONG nFlags, LONG distance, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// nFlags shows additional button states (see WM_MOUSEMOVE MSDN page for example, see MK_CONTROL, MK_SHIFT, etc constants)
	// you can use transformHDC HDC to transform point coordinates to screen coordinates (GMEView can be zoomed and scrolled)
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::DragEnter(ULONG* dropEffect, ULONGLONG pCOleDataObject, ULONG keyState, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// If you are interested only file drag-drops you should only hook up to DropFile event and inhibit DragEnter, DragOver, Drop
	// If you want more complicated things though, you should handle the three mentioned event in Windows fashion.
	// See OnDragEnter, OnDragOver, OnDrop MFC notifications in MSDN or GME source
	// pCOleDataObject is a COleDataObject pointer
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::DragOver(ULONG* dropEffect, ULONGLONG pCOleDataObject, ULONG keyState, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// If you are interested only file drag-drops you should only hook up to DropFile event and inhibit DragEnter, DragOver, Drop
	// If you want more complicated things though, you should handle the three mentioned event in Windows fashion.
	// See OnDragEnter, OnDragOver, OnDrop MFC notifications in MSDN or GME source
	// pCOleDataObject is a COleDataObject pointer
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::Drop(ULONGLONG pCOleDataObject, ULONG dropEffect, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// If you are interested only file drag-drops you should only hook up to DropFile event and inhibit DragEnter, DragOver, Drop
	// If you want more complicated things though, you should handle the three mentioned event in Windows fashion.
	// See OnDragEnter, OnDragOver, OnDrop MFC notifications in MSDN or GME source
	// pCOleDataObject is a COleDataObject pointer
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::DropFile(ULONGLONG hDropInfo, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// hDropInfo is a HDROP type variable, you should use this to extract the needed data
	//
  return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::MenuItemSelected(ULONG menuItemId, ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
{
	//
	// TODO: if you respond to the message, you should return
	// S_DECORATOR_EVENT_HANDLED, else you should return S_DECORATOR_EVENT_NOT_HANDLED
	// In menuItemId you should get back one of the menu IDs you previously added to the context menu
	//

	return S_DECORATOR_EVENT_NOT_HANDLED;
}

STDMETHODIMP CDecorator::OperationCanceled()
{
	//
	// TODO: if you handle the message, you should return S_DECORATOR_EVENT_HANDLED,
	// else you should return S_DECORATOR_EVENT_NOT_HANDLED
	//
	return S_DECORATOR_EVENT_NOT_HANDLED;
}
#endif

//////////// Decorator private functions

CDecorator::CDecorator (void)
: m_isInitialized( false),
  m_isLocSet( false ),
  m_pDecorator( 0 )
{
}

CDecorator::~CDecorator()
{
  delete m_pDecorator;
}

bool
CDecorator::GetMetaFCO( const CComPtr<IMgaMetaPart> &metaPart,
                        CComPtr<IMgaMetaFCO> &metaFco )
{
  if ( !metaPart ) {
    return false;
  }

  metaFco = NULL;
  CComPtr<IMgaMetaRole> metaRole;
  try {
    COMTHROW( metaPart->get_Role( &metaRole ) );
    COMTHROW( metaRole->get_Kind( &metaFco ) );
  }
  catch ( hresult_exception & ) {
    metaFco = NULL;
  }
  return ( metaFco != NULL );
}
