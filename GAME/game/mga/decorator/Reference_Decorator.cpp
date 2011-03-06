// $Id$

#include "stdafx.h"
#include "Reference_Decorator.h"

#if !defined (__GAME_INLINE__)
#include "Reference_Decorator.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// initialize
//
int Reference_Decorator::
initialize (const Project & proj,
            const Meta::Part_in part,
            const FCO_in fco)
{
  return 0;
}

//
// initialize
//
int Reference_Decorator::
initialize_ex (const Project & proj,
               const Meta::Part_in part,
               const FCO_in fco,
               IMgaCommonDecoratorEvents * eventSink,
               ULONGLONG parentWnd)
{
  return 0;
}

//
// destroy
//
void Reference_Decorator::destroy (void)
{
  if (this->delegate_)
  {
    // Notify the delegate to destroy itself and release our
    // reference to the object.
    this->delegate_->Destroy ();
    this->delegate_.Release ();
  }
}

//
// set_active
//
void Reference_Decorator::set_active (bool state)
{
  if (this->delegate_)
    this->delegate_->SetActive (state ? VARIANT_TRUE : VARIANT_FALSE);

  return Decorator_Impl::set_active (state);
}

//
// set_active
//
void Reference_Decorator::set_selected (bool state)
{
  if (this->delegate_)
    this->delegate_->SetSelected (state ? VARIANT_TRUE : VARIANT_FALSE);

  Decorator_Impl::set_active (state);
}

//
// preferred_size
//
GAME_INLINE
int Reference_Decorator::get_preferred_size (long & sx, long & sy)
{
  if (this->delegate_)
    return this->delegate_->GetPreferredSize (&sx, &sy);
  else
    return Decorator_Impl::get_preferred_size (sx, sy);
}

//
// set_location
//
GAME_INLINE
void Reference_Decorator::set_location (const GAME::Mga::Rect & location)
{
  if (this->delegate_)
    VERIFY_HRESULT (this->delegate_->SetLocation (location.x_,
                                                  location.y_,
                                                  location.cx_,
                                                  location.cy_));

  Decorator_Impl::set_location (location);
}

//
// get_label_location
//
GAME_INLINE
int Reference_Decorator::
get_label_location (long & sx, long & sy, long & ex, long & ey)
{
  if (this->delegate_)
    return this->delegate_->GetLabelLocation (&sx, &sy, &ex, &ey);
  else
    return Decorator_Impl::get_label_location (sx, sy, ex, ey);
}

//
// draw
//
GAME_INLINE
int Reference_Decorator::draw (Gdiplus::Graphics * g)
{
  if (this->delegate_)
    VERIFY_HRESULT (this->delegate_->Draw (g->GetHDC ()));

  return 0;
}

//
// operation_canceled
//
GAME_INLINE
int Reference_Decorator::operation_canceled (void)
{
  if (this->delegate_)
    return this->delegate_->OperationCanceled ();
  else
    return Decorator_Impl::operation_canceled ();
}

//
// mouse_moved
//
GAME_INLINE
int Reference_Decorator::
mouse_moved (int nFlags,
             const GAME::Mga::Point & pt,
             CDC & xform)
{
  return 1;
}

//
// mouse_left_button_down
//
GAME_INLINE
int Reference_Decorator::
mouse_left_button_down (int flags,
                        const GAME::Mga::Point & pt,
                        CDC & xform)
{
  return 1;
}

//
// mouse_left_button_up
//
GAME_INLINE
int Reference_Decorator::
mouse_left_button_up (int flags,
                      const GAME::Mga::Point & pt,
                      CDC & xform)
{
  return 1;
}

//
// mouse_left_button_double_click
//
GAME_INLINE
int Reference_Decorator::
mouse_left_button_double_click (int nFlags,
                                const GAME::Mga::Point & pt,
                                CDC & xform)
{
  return 1;
}

//
// mouse_right_button_down
//
GAME_INLINE
int Reference_Decorator::
mouse_right_button_down (CMenu & ctxmenu,
                         int flags,
                         const GAME::Mga::Point & pt,
                         CDC & xform)
{
  return 1;
}

//
// mouse_right_button_up
//
GAME_INLINE
int Reference_Decorator::
mouse_right_button_up (int flags,
                       const GAME::Mga::Point & pt,
                       CDC & xform)
{
  return 1;
}

//
// mouse_right_button_double_click
//
GAME_INLINE
int Reference_Decorator::
mouse_right_button_double_click (int flags,
                                 const GAME::Mga::Point & pt,
                                 CDC & xform)
{
  return 1;
}

//
// mouse_middle_button_down
//
GAME_INLINE
int Reference_Decorator::
mouse_middle_button_down (int flags,
                          const GAME::Mga::Point & pt,
                          CDC & xform)
{
  return 1;
}

//
// mouse_middle_button_up
//
GAME_INLINE
int Reference_Decorator::
mouse_middle_button_up (int flags,
                        const GAME::Mga::Point & pt,
                        CDC & xform)
{
  return 1;
}

//
// mouse_middle_button_double_click
//
GAME_INLINE
int Reference_Decorator::
mouse_middle_button_double_click (int flags,
                                  const GAME::Mga::Point & pt,
                                  CDC & xform)
{
  return 1;
}

//
// mouse_wheel_turned
//
GAME_INLINE
int Reference_Decorator::
mouse_wheel_turned (int flags,
                    int distance,
                    const GAME::Mga::Point & pt,
                    CDC & xform)
{
  return 1;
}

//
// drag_enter
//
GAME_INLINE
int Reference_Decorator::
drag_enter (unsigned long & effect,
            COleDataObject & pCOleDataObject,
            int keyState,
            const GAME::Mga::Point & pt,
            CDC & xform)
{
  return 1;
}

//
// drag_over
//
GAME_INLINE
int Reference_Decorator::
drag_over (unsigned long & effect,
           COleDataObject & pCOleDataObject,
           int keyState,
           const GAME::Mga::Point & pt,
           CDC & xform)
{
  return 1;
}

//
// drop
//
GAME_INLINE
int Reference_Decorator::
drop (COleDataObject & pCOleDataObject,
      int effect,
      const GAME::Mga::Point & pt,
      CDC & xform)
{
  return 1;
}

//
// drop_file
//
GAME_INLINE
int Reference_Decorator::
drop_file (ULONGLONG hDropInfo,
           const GAME::Mga::Point & pt,
           CDC & xform)
{
  return 1;
}

//
// menu_item_selected
//
GAME_INLINE
int Reference_Decorator::
menu_item_selected (int item_id,
                    int nFlags,
                    const GAME::Mga::Point & pt,
                    CDC & xform)
{
  return 1;
}

}
}
