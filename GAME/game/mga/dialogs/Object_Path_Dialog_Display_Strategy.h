// -*- C++  -*-

//=============================================================================
/**
 *  @file     Object_Path_Dialog_Display_Strategy.h
 *
 *  $Id$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _GAME_OBJECT_PATH_DIALOG_DISPLAY_STRATEGY_H_
#define _GAME_OBJECT_PATH_DIALOG_DISPLAY_STRATEGY_H_

#include "Dialog_Display_Strategy.h"
#include "game/mga/GME_fwd.h"

namespace GAME
{

namespace Dialogs
{
/**
 * @class Object_Path_Dialog_Display_Strategy
 *
 * Strategy class for determining the display name for each element. Clients
 * can implement domain-specific display strategies by subclassing from this
 * class. This will enalbe the client to customize the text shown for each
 * element in a dialog without having to (re-)implement the dialog themselves.
 */
class GAME_DIALOGS_Export Object_Path_Dialog_Display_Strategy :
  public Dialog_Display_Strategy
{
public:
  /// Default constructor.
  Object_Path_Dialog_Display_Strategy (void);

  Object_Path_Dialog_Display_Strategy (const std::string & separator,
                                       bool show_leading = false);

  /// Destructor.
  virtual ~Object_Path_Dialog_Display_Strategy (void);

  /**
   * Callback method for getting the display name of a element. The
   * value of the \a name parameter is what the dialog shows for the
   * specified element.
   *
   * @param[in]        obj                Target object
   * @param[out]       display_name       Display name of the object.
   */
  virtual bool
    get_display_name (const Mga::Object_in obj, std::string & display_name);

private:
  /// Separator value to use in path construction.
  std::string separator_;

  /// Show the leading separator.
  bool show_leading_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Object_Path_Dialog_Display_Strategy.inl"
#endif

#endif  // !defined _GAME_DIALOG_DISPLAY_STRATEGY_H_
