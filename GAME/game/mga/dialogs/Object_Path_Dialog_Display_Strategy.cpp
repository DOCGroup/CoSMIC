// $Id$

#include "stdafx.h"
#include "Object_Path_Dialog_Display_Strategy.h"

#if !defined (__GAME_INLINE__)
#include "Object_Path_Dialog_Display_Strategy.inl"
#endif

#include "game/mga/Object.h"

namespace GAME
{
namespace Dialogs
{

//
// get_display_name
//
bool Object_Path_Dialog_Display_Strategy::
get_display_name (const Mga::Object_in obj, std::string & display_name)
{
  display_name = obj->path (this->separator_, this->show_leading_);
  return true;
}

}
}
