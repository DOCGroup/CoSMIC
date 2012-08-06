// -*- C++  -*-

//=============================================================================
/**
 *  @file     Dialog_Display_Strategy.h
 *
 *  $Id$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _GAME_DIALOG_DISPLAY_STRATEGY_H_
#define _GAME_DIALOG_DISPLAY_STRATEGY_H_

#include <string>
#include "game/config.h"
#include "game/mga/GME_fwd.h"

#include "Dialogs_export.h"

namespace GAME
{

namespace Dialogs
{
/**
 * @class Dialog_Display_Strategy
 *
 * Strategy class for determining the display name for each element. Clients
 * can implement domain-specific display strategies by subclassing from this
 * class. This will enalbe the client to customize the text shown for each
 * element in a dialog without having to (re-)implement the dialog themselves.
 */
class GAME_DIALOGS_Export Dialog_Display_Strategy
{
public:
  /// Default constructor.
  Dialog_Display_Strategy (void);

  /// Destructor.
  virtual ~Dialog_Display_Strategy (void);

  /**
   * Callback method for getting the display name of a element. The
   * value of the \a name parameter is what the dialog shows for the
   * specified element.
   *
   * @param[in]        obj                Target object
   * @param[out]       display_name       Display name of the object.
   */
  virtual bool get_display_name (const Mga::Object_in obj,
                                 std::string & display_name) = 0;
};

}
}

#if defined (__GAME_INLINE__)
#include "Dialog_Display_Strategy.inl"
#endif

#endif  // !defined _GAME_DIALOG_DISPLAY_STRATEGY_H_
