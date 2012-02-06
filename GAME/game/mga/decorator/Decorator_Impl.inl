// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Decorator_Impl
//
GAME_INLINE
Decorator_Impl::Decorator_Impl (void)
{

}

//
// ~Decorator_Impl
//
GAME_INLINE
Decorator_Impl::~Decorator_Impl (void)
{

}

//
// initialize
//
GAME_INLINE
int Decorator_Impl::
initialize (const Project & proj,
            const Meta::Part_in part,
            IMgaCommonDecoratorEvents * eventSink,
            ULONGLONG parentWnd)
{
  return 0;
}

//
// initialize
//
GAME_INLINE
int Decorator_Impl::
initialize (const Project & proj,
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
GAME_INLINE
void Decorator_Impl::destroy (void)
{

}

//
// features
//
GAME_INLINE
long Decorator_Impl::features (void)
{
  return 0;
}

//
// set_param
//
GAME_INLINE
int Decorator_Impl::
set_param (const std::string & name, const std::string & value)
{
  return 0;
}


//
// get_param
//
GAME_INLINE
int Decorator_Impl::
get_param (const std::string & name, std::string & value)
{
  return 0;
}

//
// set_active
//
GAME_INLINE
void Decorator_Impl::set_active (bool state)
{
  this->is_active_ = state;
}

//
// set_active
//
GAME_INLINE
void Decorator_Impl::set_selected (bool state)
{
  this->is_selected_ = state;
}

//
// preferred_size
//
GAME_INLINE
int Decorator_Impl::get_preferred_size (long & sx, long & sy)
{
  return -1;
}

//
// set_location
//
GAME_INLINE
void Decorator_Impl::set_location (const GAME::Mga::Rect & location)
{
  this->location_ = location;
}

//
// get_location
//
GAME_INLINE
const GAME::Mga::Rect & Decorator_Impl::get_location (void) const
{
  return this->location_;
}

//
// get_label_location
//
GAME_INLINE
int Decorator_Impl::
get_label_location (long & sx, long & sy, long & ex, long & ey)
{
  return -1;
}

//
// get_port_location
//
GAME_INLINE
int Decorator_Impl::
get_port_location (const FCO_in fco, long & sx, long & sy, long & ex, long & ey)
{
  return -1;
}

//
// ports
//
GAME_INLINE
int Decorator_Impl::get_ports (std::vector <FCO> & v)
{
  return 0;
}

//
// draw
//
GAME_INLINE
int Decorator_Impl::draw (Gdiplus::Graphics * g)
{
  return 0;
}

//
// save_state
//
GAME_INLINE
int Decorator_Impl::save_state (void)
{
  return 0;
}

//
// operation_canceled
//
GAME_INLINE
int Decorator_Impl::operation_canceled (void)
{
  return 1;
}

//
// mouse_moved
//
GAME_INLINE
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
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
int Decorator_Impl::
menu_item_selected (int item_id,
                    int nFlags,
                    const GAME::Mga::Point & pt,
                    CDC & xform)
{
  return 1;
}

}
}
