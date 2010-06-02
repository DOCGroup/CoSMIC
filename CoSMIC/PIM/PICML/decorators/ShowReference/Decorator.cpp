// $Id$

#include "stdafx.h"
#include "Decorator.h"

#include "game/FCO.h"
#include "game/Reference.h"
#include "game/Project.h"
#include "game/MetaRole.h"
#include "game/MetaFCO.h"
#include "game/utils/Parser.hpp"
#include <fstream>

#define VERIFY_INIT   { if (!m_isInitialized) return E_DECORATOR_UNINITIALIZED; }
#define VERIFY_LOCSET { if (!m_isLocSet) return E_DECORATOR_LOCISNOTSET; }

CDecoratorUtil d_util;

//
// registrar_
//
GAME::utils::Registrar CDecorator::registrar_;

//
// CDecorator
//
CDecorator::CDecorator (void)
{

}

//
// ~CDecorator
//
CDecorator::~CDecorator (void)
{

}

//
// Initialize
//
STDMETHODIMP CDecorator::
Initialize (IMgaProject *p, IMgaMetaPart *metaPart, IMgaFCO *obj)
{
  if (!this->m_bInitCallFromEx)
    return E_DECORATOR_USING_DEPRECATED_FUNCTION;

  // Set the parser configuration.
  GAME::Project project (p);
  GAME::utils::PathParserConfig config (project);

  // Initialize the parser.
  std::vector <std::string> paths;
  GAME::utils::PathParser <std::string::const_iterator> grammar (config, paths);

  // Extract paths from registrar and tokenize the string.
  std::string path = this->registrar_.icon_path (GAME::utils::Registrar::ACCESS_BOTH);
  
  using boost::phoenix::ref;
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  bool result = qi::phrase_parse (path.begin (), 
                                  path.end (), 
                                  grammar, 
                                  ascii::space);

  std::string icon_filename;

  if (obj == 0)
  {
    // Get the icon for the element in the parts browser.
    CComPtr <IMgaMetaFCO> mf;
    if (!this->GetMetaFCO (metaPart, mf))
      return E_DECORATOR_INIT_WITH_NULL;   

    GAME::Meta::FCO metafco (mf.Detach ());
    icon_filename = metafco.registry_value ("icon");
    this->label_ = metafco.display_name ().c_str ();
  }
  else
  {
    GAME::FCO fco (obj);

    // Get the icon filename for the referenced element. If no 
    // element is referenced, then display the reference's icon.
    GAME::Reference ref = GAME::Reference::_narrow (fco);
    fco = ref.refers_to ();


    if (!fco.is_nil ())
      icon_filename = fco.registry_value ("icon");
    else
      icon_filename = ref.registry_value ("icon");

    // Determine if we need to show the label for the element.
    std::string show_name = ref.registry_value ("isNameEnabled");

    if (show_name.empty () || show_name == "true")
      this->label_ = ref.name ().c_str ();
  }

  // Determine the exact location of the filename based on the
  // paths retrieved from the registrar.
  std::string filename;
  std::vector <std::string>::const_iterator 
    iter = paths.begin (), iter_end = paths.end ();

  CFile bitmap_file;
  for (; iter != iter_end; ++ iter)
  {
    filename = *iter + "\\" + icon_filename;

    if (bitmap_file.Open (filename.c_str (), CFile::modeRead | CFile::shareDenyWrite))
      break;
  }

  // If we are not able to locate the bitmap, we should just load
  // the default bitmap for the reference.

  // Now, let's load the bitmap into memory.
  this->bitmap_.Read (bitmap_file);
  bitmap_file.Close ();

  m_isInitialized = true;
  return S_OK;
}

//
// Destroy
//
STDMETHODIMP CDecorator::Destroy (void)
{
  return S_OK;
}

//
// GetMnemonic
//
STDMETHODIMP CDecorator::GetMnemonic (BSTR *mnemonic)
{
  *mnemonic = CComBSTR (L"MGA.Decorator.ShowReference").Detach ();
  return S_OK;
}

//
// GetFeatures
//
STDMETHODIMP CDecorator::GetFeatures (feature_code *features )
{
  *features = 0;
  return S_OK;
}

//
// SetParam
//
STDMETHODIMP CDecorator::SetParam (BSTR name, VARIANT value)
{
  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// GetParam
//
STDMETHODIMP CDecorator::GetParam (BSTR name, VARIANT* value)
{
  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// SetActive
//
STDMETHODIMP CDecorator::SetActive (VARIANT_BOOL isActive)
{
  return S_OK;
}

//
// GetPreferredSize
//
STDMETHODIMP CDecorator::GetPreferredSize (long* sizex, long* sizey)
{
  *sizex = this->bitmap_.Width ();
  *sizey = this->bitmap_.Height ();

  return S_OK;
}

//
// SetLocation
//
STDMETHODIMP CDecorator::
SetLocation (long sx, long sy, long ex, long ey)
{
  this->location_.left = sx;
  this->location_.top = sy;
  this->location_.right = ex;
  this->location_.bottom = ey;

  return S_OK;
}

//
// GetLocation
//
STDMETHODIMP CDecorator::
GetLocation (long *sx, long *sy, long *ex, long *ey)
{
  *sx = this->location_.left;
  *sy = this->location_.top;
  *ex = this->location_.right;
  *ey = this->location_.bottom;

  return S_OK;
}

//
// GetLabelLocation
//
STDMETHODIMP CDecorator::
GetLabelLocation (long *sx, long *sy, long *ex, long *ey)
{
  return S_OK;
}

//
// GetPortLocation
//
STDMETHODIMP CDecorator::
GetPortLocation (IMgaFCO *pFCO, long *sx, long *sy, long *ex, long *ey)
{
  return S_FALSE;
}

//
// GetPorts
//
STDMETHODIMP CDecorator::GetPorts (IMgaFCOs **portFCOs)
{
  return S_FALSE;
}

//
// Draw
//
STDMETHODIMP CDecorator::Draw (HDC hdc)
{
  CDC context;
  context.Attach (hdc);

  this->bitmap_.Draw (&context, this->location_);
 
  CPoint name_location (this->location_.left + this->bitmap_.Width () / 2,
                        this->location_.bottom + 20);

  COLORREF name_color (RGB (0x00, 0x00, 0x00));

  d_util.DrawText (&context,
                   this->label_,
                   name_location,
                   d_util.GetFont (GME_NAME_FONT),
                   name_color,
                   TA_BOTTOM | TA_CENTER);

  context.Detach ();

  return S_OK;
}

STDMETHODIMP CDecorator::SaveState (void)
{
  return S_OK;
}

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
	m_bInitCallFromEx = true;
	this->Initialize (pProject, pPart, pFCO);

	return S_OK;
}

//
// DrawEx
//
STDMETHODIMP CDecorator::DrawEx (HDC hdc, ULONGLONG gdipGraphics)
{
  this->Draw (hdc);
  return S_OK;
}

//
// SetSelected
//
STDMETHODIMP CDecorator::SetSelected(VARIANT_BOOL vbIsSelected)
{
	m_bSelected = (vbIsSelected == VARIANT_TRUE);
	return S_OK;
}

//
// MouseMoved
//
STDMETHODIMP CDecorator::
MouseMoved (ULONG nFlags, LONG pointx, LONG pointy, ULONGLONG transformHDC)
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

//
// GetMetaFCO
//
bool CDecorator::
GetMetaFCO (const CComPtr<IMgaMetaPart> &metaPart, CComPtr<IMgaMetaFCO> &metaFco)
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
