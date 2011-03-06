// -*- C++ -*-

//=============================================================================
/**
 * @file        Reference_Decorator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_REFERENCE_DECORATOR_H_
#define _GAME_MGA_REFERENCE_DECORATOR_H_

#include "Decorator_Impl.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Reference_Decorator
 *
 * Base class for all reference decorators. This class provides required
 * functionality that allows reference decorators to behave correctly.
 * Clients to can extend this class to add more domain-specific behavior
 * to the decorator.
 */
class GAME_MGA_DECORATOR_Export Reference_Decorator : public Decorator_Impl
{
public:
  /// Default constructor.
  Reference_Decorator (void);

  /// Destructor.
  virtual ~Reference_Decorator (void);

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

  void set_active (bool state);

  void set_selected (bool state);

  void set_location (const GAME::Mga::Rect & location);

  int get_preferred_size (long & sx, long & sy);

  int get_label_location (long & sx, long & sy, long & ex, long & ey);

  int draw (Gdiplus::Graphics * g);

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
  /// The delegate decorator for this referenced object.
  CComPtr <IMgaElementDecorator> delegate_;
};


}
}

#if defined (__GAME_INLINE__)
#include "Reference_Decorator.inl"
#endif

#endif  // !defined _GAME_MGA_BE_REFERENCE_DECORATOR_H_
