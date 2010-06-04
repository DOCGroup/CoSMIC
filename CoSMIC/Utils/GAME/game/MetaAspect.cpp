// $Id$

#include "stdafx.h"
#include "MetaAspect.h"

#if !defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

namespace GAME
{
namespace Meta
{
//
// impl
//
IMgaMetaAspect * Aspect::impl (void) const
{
  // Optimize for the quick path.
  if (this->aspect_.p == this->metabase_.p)
    return this->aspect_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->aspect_)
    this->aspect_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->aspect_));
  return this->aspect_;
}

}
}
