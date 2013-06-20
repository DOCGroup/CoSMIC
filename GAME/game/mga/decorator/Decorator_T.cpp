// $Id$

#if !defined (__GAME_INLINE__)
#include "Decorator_T.inl"
#endif

#include "game/mga/Exception.h"
#include "game/mga/Transaction.h"
#include "game/mga/component/Console_Service.h"

#include <gdiplus.h>
#include <sstream>

namespace GAME
{
namespace Mga
{

//
// Initialize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
Initialize (IMgaProject *project, IMgaMetaPart *part, IMgaFCO * fco)
{
  return this->InitializeEx (project, part, fco, 0, 0);
}

//
// InitializeEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
InitializeEx (IMgaProject* project,
              IMgaMetaPart* pPart,
              IMgaFCO* pFCO,
              IMgaCommonDecoratorEvents* sink,
              ULONGLONG window)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    // Reset the state variables.
    this->is_loc_set_ = false;
    this->is_init_ = false;

    int retval;
    GAME::Mga::Project proj (project);
    GAME::Mga::Meta::Part part (pPart);

    // Initialize the GME console service.
    GME_CONSOLE_SERVICE->initialize (proj);


    if (0 != pFCO)
    {
      // Initialize the decorator for the model view.
      GAME::Mga::FCO fco (pFCO);
      retval = this->impl_ptr_->initialize (proj, part, fco, sink, window);
    }
    else
    {
      // Initialize the decorator for the browser view.
      retval = this->impl_ptr_->initialize (proj, part, sink, window);
    }

    if (0 == retval)
      this->is_init_ = true;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_OK;
}

//
// Destroy
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::Destroy (void)
{
  try
  {
    if (!this->is_init_)
      return E_DECORATOR_UNINITIALIZED;

    this->is_init_ = false;
    this->is_loc_set_ = false;

    this->impl_.destroy ();
    return S_OK;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

//
// Draw
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::Draw (ULONG hdc)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    // Allocate a graphics objects and then pass control to the extended
    // version of the draw method.
    std::auto_ptr <Gdiplus::Graphics> g (Gdiplus::Graphics::FromHDC ((HDC)hdc));
    return this->impl_.draw (g.get ());
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

//
// DrawEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::DrawEx (ULONG hdc, ULONGLONG graphics)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    Gdiplus::Graphics * g = reinterpret_cast <Gdiplus::Graphics *> (graphics);
    return this->impl_.draw (g);
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

//
// GetPreferredSize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetPreferredSize (long* sx, long* sy)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    return 0 == this->impl_.get_preferred_size (*sx, *sy) ? S_OK : S_FALSE;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}


//
// SetLocation
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::SetLocation (long sx, long sy, long ex, long ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    GAME::Mga::Rect location (sx, sy, ex, ey);
    this->impl_.set_location (location);
    this->is_loc_set_ = true;

    return S_OK;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

//
// SetParam
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::SetParam (BSTR name, VARIANT value)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// GetParam
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetParam (BSTR name, VARIANT* value)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// GetLocation
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
GetLocation (long *sx, long *sy, long *ex, long *ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    const GAME::Mga::Rect & location = this->impl_.get_location ();
    *sx = location.x_;
    *sy = location.y_;
    *ex = location.cx_;
    *ey = location.cy_;

    return S_OK;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

/**
 * @struct is_equal_to
 */
struct is_equal_to
{
public:
  is_equal_to (IMgaFCO * fco)
    : fco_ (fco)
  {

  }

  bool operator () (const std::map <GAME::Mga::FCO, GAME::Mga::Rect>::value_type & entry) const
  {
    VARIANT_BOOL result;
    VERIFY_HRESULT (entry.first->impl ()->get_IsEqual (this->fco_, &result));
    return result == VARIANT_TRUE ? true : false;
  }

private:
  /// Pointer to FCO under test.
  IMgaFCO * fco_;
};

//
// GetPortLocation
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
GetPortLocation (IMgaFCO * fco, long *sx, long *sy, long *ex, long *ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    // Attempt to locate the port in our cache.
    port_map_t::iterator iter =
      std::find_if (this->ports_.begin (),
                    this->ports_.end (),
                    is_equal_to (fco));

    if (iter == this->ports_.end ())
      return E_DECORATOR_PORTNOTFOUND;

    if (!(iter->second.height () == 0 && iter->second.width () == 0))
    {
      // Copy over the port's relative location.
      *sx = iter->second.x_;
      *sy = iter->second.y_;
      *ex = iter->second.cx_;
      *ey = iter->second.cy_;
    }
    else
    {
      // Since the current location of this port is undefined, we are
      // going to ask the implementation get this port's location.
      int retval = this->impl_.get_port_location (iter->first, *sx, *sy, *ex, *ey);

      if (0 != retval)
        return E_DECORATOR_PORTNOTFOUND;

      // Get the object's current location and convert the port's
      // absolute location to a relative location.
      const GAME::Mga::Rect & loc = this->impl_.get_location ();

      *sx -= loc.x_;
      *sy -= loc.y_;
      *ex -= loc.x_;
      *ey -= loc.y_;

      // Save the port's relative location for later.
      iter->second.set (*sx, *sy, *ex, *ey);
    }

    return S_OK;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return E_DECORATOR_PORTNOTFOUND;
}

//
// GetPorts
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetPorts (IMgaFCOs **portFCOs)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    // First, let's get the ports for the FCO
    ATL::CComPtr <IMgaFCOs> temp;
    VERIFY_HRESULT (temp.CoCreateInstance (L"Mga.MgaFCOs"));

    std::vector <FCO> ports;
    if (0 != this->impl_.get_ports (ports))
      return S_FALSE;

    // Clear the map that contains the port locations.
    if (!this->ports_.empty ())
      this->ports_.clear ();

    std::vector <FCO>::const_iterator
      iter = ports.begin (), iter_end = ports.end ();

    for (; iter != iter_end; ++ iter)
    {
      // Append the FCO to the listing, then insert an empty rectangle
      // into the port mapping.
      VERIFY_HRESULT (temp->Append ((*iter)->impl ()));
      this->ports_.insert (std::make_pair (*iter, Rect ()));
    }

    // Return the collection to the client.
    *portFCOs = temp.Detach ();

    return S_OK;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    GME_CONSOLE_SERVICE->error (ex.message ());
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());
  }

  return S_FALSE;
}

//
// MouseMoved
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMoved (ULONG flags,
            LONG px,
            LONG py,
            ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  CDC context;

  try
  {
    HDC hdc = reinterpret_cast <HDC> (transformHDC);
    context.Attach (hdc);

    int retval = this->impl_.mouse_moved (flags, GAME::Mga::Point (px, py), context);

    // Make sure we release the context.
    context.Detach ();
    return retval;
  }
  catch (...)
  {
    std::ostringstream ostr;
    ostr << "(" << __FILE__ << ":" << __LINE__ << "): caught unknown exception";
    GME_CONSOLE_SERVICE->error (ostr.str ());

    context.Detach ();
  }

  return S_FALSE;
}

//
// MouseLeftButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonDown (ULONG flags,
                     LONG px,
                     LONG py,
                     ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_down (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseLeftButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonUp (ULONG flags,
                   LONG px,
                   LONG py,
                   ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseLeftButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonDoubleClick (ULONG flags,
                            LONG px,
                            LONG py,
                            ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_double_click (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseRightButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonDown (ULONGLONG hCtxMenu,
                      ULONG flags,
                      LONG px,
                      LONG py,
                      ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HMENU menu = reinterpret_cast <HMENU> (hCtxMenu);
  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  CMenu context_menu;

  context.Attach (hdc);
  context_menu.Attach (menu);

  int retval = this->impl_.mouse_right_button_down (context_menu,
                                                    flags,
                                                    GAME::Mga::Point (px, py),
                                                    context);

  // Make sure we release the context.
  context.Detach ();
  context_menu.Detach ();

  return retval;
}

//
// MouseRightButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonUp (ULONG flags,
                    LONG px,
                    LONG py,
                    ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_right_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseRightButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonDoubleClick (ULONG flags,
                             LONG px,
                             LONG py,
                             ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_right_button_double_click (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonDown (ULONG flags,
                       LONG px,
                       LONG py,
                       ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_down (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonUp (ULONG flags,
                     LONG px,
                     LONG py,
                     ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonDoubleClick (ULONG flags,
                              LONG px,
                              LONG py,
                              ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_double_click (flags,
                                                             GAME::Mga::Point (px, py),
                                                             context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseWheelTurned
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseWheelTurned (ULONG flags,
                  LONG distance,
                  LONG px,
                  LONG py,
                  ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_wheel_turned (flags,
                                               distance,
                                               GAME::Mga::Point (px, py),
                                               context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// DragEnter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DragEnter (ULONG* effect,
           ULONGLONG pCOleDataObject,
           ULONG keystate,
           LONG px,
           LONG py,
           ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drag_enter (*effect,
                                       *data_object,
                                       keystate,
                                       GAME::Mga::Point (px, py),
                                       context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// DragOver
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DragOver (ULONG* effect,
          ULONGLONG pCOleDataObject,
          ULONG keystate,
          LONG px,
          LONG py,
          ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drag_over (*effect,
                                      *data_object,
                                      keystate,
                                      GAME::Mga::Point (px, py),
                                      context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// Drop
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
Drop (ULONGLONG pCOleDataObject,
      ULONG drop_effect,
      LONG px,
      LONG py,
      ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drop (*data_object,
                                 drop_effect,
                                 GAME::Mga::Point (px, py),
                                 context);

  context.Detach ();

  return retval;
}

//
// DropFile
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DropFile (ULONGLONG drop_info,
          LONG px,
          LONG py,
          ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drop_file (drop_info,
                                      GAME::Mga::Point (px, py),
                                      context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MenuItemSelected
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MenuItemSelected (ULONG menuItemId,
                  ULONG flags,
                  LONG px,
                  LONG py,
                  ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.menu_item_selected (menuItemId,
                                               flags,
                                               GAME::Mga::Point (px, py),
                                               context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// get_version
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
get_version (GMEInterfaceVersion_enum *pVal)
{
  if (pVal == 0)
    return E_POINTER;

  *pVal = GMEInterfaceVersion_Current;
  return S_OK;
}

}
}
