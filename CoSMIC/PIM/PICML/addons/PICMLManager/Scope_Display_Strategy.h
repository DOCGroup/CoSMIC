// -*- C++ -*-

//=============================================================================
/**
 *  @file       Scope_Display_Strategy.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#include "game/dialogs/Dialog_Display_Strategy.h"

#ifndef _PICML_MI_SCOPE_DISPLAY_STRATEGY_H_
#define _PICML_MI_SCOPE_DISPLAY_STRATEGY_H_

namespace PICML
{
namespace MI
{
/**
 * @class Scope_Display_Strategy
 *
 * Dialog display strategy that displays the scope of an element. This
 * display strategy should be used for elements that appear within the
 * scope of a File element. The display names of the elements will be the
 * element's path using '::' as the separator up to the File element.
 */
class Scope_Display_Strategy :
  public GAME::Dialogs::Dialog_Display_Strategy
{
public:
  /// Default constructor.
  Scope_Display_Strategy (void);

  /// Destructor.
  virtual ~Scope_Display_Strategy (void);

  // Get the display name for the object.
  bool get_display_name (const GAME::Object_in, std::string &);
};

}
}

#if defined (__GAME_INLINE__)
#include "Scope_Display_Strategy.inl"
#endif

#endif
