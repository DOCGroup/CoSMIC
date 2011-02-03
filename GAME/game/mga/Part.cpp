// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "Part.h"

#if !defined (__GAME_INLINE__)
#include "Part.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Mga
{

//
// meta
//
Meta::Part Part::meta (void) const
{
  CComPtr <IMgaMetaPart> meta;
  VERIFY_HRESULT (this->part_->get_Meta (&meta));

  return Meta::Part (meta);
}

//
// get_location
//
void Part::get_location (long & x, long & y)
{
  VERIFY_HRESULT (this->part_->GetGmeAttrs (0, &x, &y));
}

//
// set_location
//
void Part::set_location (long x, long y)
{
  VERIFY_HRESULT (this->part_->SetGmeAttrs (0, x, y));
}

}
}
