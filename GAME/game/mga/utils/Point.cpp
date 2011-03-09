// $Id$

#include "stdafx.h"
#include "Point.h"

#if !defined (__GAME_INLINE__)
#include "Point.inl"
#endif

#include "game/mga/FCO.h"
#include "game/mga/Model.h"
#include "game/mga/MetaAspect.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Part.h"

#include "Utils/Point.h"

namespace GAME
{
namespace Mga
{

//
// get_position
//
bool get_position (const std::string & aspect, const FCO_in fco, Point & pt)
{
  // Convert the point in a position value.
  Meta::Aspect meta_aspect = fco->parent_model ()->meta ()->aspect (aspect);

  if (meta_aspect.is_nil ())
    return false;

  Part part = fco->part (meta_aspect);

  if (part.is_nil ())
    return false;

  // Get the position from the part.
  long x, y;
  part.get_location (x, y);

  // Update the position value.
  pt.set (x, y);

  return true;
}

//
// set_position
//
bool set_position (const std::string & aspect, const Point & pt, FCO_in fco)
{
  // Convert the point in a position value.
  Meta::Aspect meta_aspect = fco->parent_model ()->meta ()->aspect (aspect);

  if (meta_aspect.is_nil ())
    return false;

  Part part = fco->part (meta_aspect);

  if (part.is_nil ())
    return false;

  part.set_location (pt.x_value (), pt.y_value ());
  return true;
}

}
}
