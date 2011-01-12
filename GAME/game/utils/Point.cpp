// $Id$

#include "stdafx.h"
#include "Point.h"

#if !defined (__GAME_INLINE__)
#include "Point.inl"
#endif

#include "game/FCO.h"
#include "game/Model.h"
#include "game/MetaAspect.h"
#include "game/MetaModel.h"
#include "game/Part.h"

#include "Utils/Point.h"

namespace GAME
{
namespace utils
{
//
// position
//
bool position (const std::string & aspect, const GAME::FCO_in fco, Point & pt)
{
  return get_position (aspect, fco, pt);
}

//
// get_position
//
bool get_position (const std::string & aspect, const GAME::FCO_in fco, Point & pt)
{
  // Convert the point in a position value.
  Meta::Aspect meta_aspect = fco->parent_model ()->meta ()->aspect (aspect);

  if (meta_aspect.is_nil ())
    return false;

  Part part = fco->part (meta_aspect);

  if (part.is_nil ())
    return false;

  long x, y;
  part.get_location (x, y);

  return true;
}

//
// set_position
//
bool set_position (const std::string & aspect, const Point & pt, GAME::FCO_in fco)
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

//
// position
//
bool position (const std::string & aspect, const Point & pt, GAME::FCO_in fco)
{
  return set_position (aspect, pt, fco);
}

}
}
