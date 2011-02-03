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

#ifndef _GAME_DECORATOR_IMPL_H_
#define _GAME_DECORATOR_IMPL_H_

#include <vector>
#include "game/mga/GME_fwd.h"
#include "game/mga/utils/Point.h"
#include "BE_export.h"

// Forward decl.
class CDC;

// Forward decl.
class CMenu;

// Forward decl.
class COleDataObject;

// Forward decl.
struct IMgaCommonDecoratorEvents;

namespace Gdiplus
{
// Forward decl.
class Graphics;
}

namespace GAME
{
namespace Mga
{
// Forward decl.
class Point;

/**
 * @class Decorator_Impl
 */
class GAME_BE_Export Decorator_Impl
{
protected:
  /// Default constructor.
  Decorator_Impl (void);

public:
  /// Destructor.
  ~Decorator_Impl (void);

  /**
   * Initailize the decorator.
   */
  int initialize (const Project & proj,
                  const Meta::Part_in part,
                  const FCO_in fco);

  int initialize_ex (const Project & proj,
                     const Meta::Part_in part,
                     const FCO_in fco,
                     IMgaCommonDecoratorEvents * eventSink,
                     ULONGLONG parentWnd);

  /// Destroy the decorator.
  void destroy (void);

  /// Get the decorator's features.
  long features (void);

  int set_param (const std::string & name,
                 const std::string & value);

  int get_param (const std::string & name,
                 std::string & value);

  void set_active (bool state);

  void set_selected (bool state);

  void set_location (const GAME::Mga::Rect & location);

  const GAME::Mga::Rect & get_location (void) const;

  int get_preferred_size (long & sx, long & sy);

  int get_label_location (long & sx, long & sy, long & ex, long & ey);

  int get_port_location (const FCO_in fco,
                         long & sx,
                         long & sy,
                         long & ex,
                         long & ey);

  int get_ports (std::vector <FCO> & v);

  int draw (Gdiplus::Graphics * g);

  int save_state (void);

  int mouse_moved (int nFlags,
                   const GAME::Mga::Point & pt,
                   CDC & xform);

  int mouse_left_button_down (int flags,
                              const GAME::Mga::Point & pt,
                              CDC & xform);

  int mouse_left_button_up (int flags,
                            const GAME::Mga::Point & pt,
                            CDC & xform);

  int mouse_left_button_double_click (int nFlags,
                                      const GAME::Mga::Point & pt,
                                      CDC & xform);

  int mouse_right_button_down (CMenu & ctxmenu,
                               int flags,
                               const GAME::Mga::Point & pt,
                               CDC & xform);

  int mouse_right_button_up (int flags,
                             const GAME::Mga::Point & pt,
                             CDC & xform);

  int mouse_right_button_double_click (int flags,
                                       const GAME::Mga::Point & pt,
                                       CDC & xform);

  int mouse_middle_button_down (int flags,
                                const GAME::Mga::Point & pt,
                                CDC & xform);

  int mouse_middle_button_up (int flags,
                              const GAME::Mga::Point & pt,
                              CDC & xform);

  int mouse_middle_button_double_click (int flags,
                                        const GAME::Mga::Point & pt,
                                        CDC & xform);

  int mouse_wheel_turned (int flags,
                          int distance,
                          const GAME::Mga::Point & pt,
                          CDC & xform);

  int drag_enter (unsigned long & effect,
                  COleDataObject & pCOleDataObject,
                  int keyState,
                  const GAME::Mga::Point & pt,
                  CDC & xform);

  int drag_over (unsigned long & effect,
                 COleDataObject & pCOleDataObject,
                 int keyState,
                 const GAME::Mga::Point & pt,
                 CDC & xform);

  int drop (COleDataObject & pCOleDataObject,
            int effect,
            const GAME::Mga::Point & pt,
            CDC & xform);

  int drop_file (ULONGLONG hDropInfo,
                 const GAME::Mga::Point & pt,
                 CDC & xform);

  int menu_item_selected (int item_id,
                          int nFlags,
                          const GAME::Mga::Point & pt,
                          CDC & xform);

  /// The current operation is canceled.
  int operation_canceled (void);

protected:
  /// The active state of the decorator.
  bool is_active_;

  /// The selected state for the decorator.
  bool is_selected_;

  GAME::Mga::Rect location_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Decorator_Impl.inl"
#endif

#endif  // !defined _GAME_DECORATOR_IMPL_H_
