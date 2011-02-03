// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaAspect.h"

#if !defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{
//
// impl
//
IMgaMetaAspect * Aspect_Impl::impl (void) const
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
}
