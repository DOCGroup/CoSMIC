// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "MetaAtom.h"

#if !defined (__GAME_INLINE__)
#include "MetaAtom.inl"
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
IMgaMetaAtom * Atom_Impl::impl (void) const
{
  // Optimize for the quick path.
  if (this->atom_.p == this->metabase_.p)
    return this->atom_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->atom_)
    this->atom_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->atom_));
  return this->atom_;
}

}
}
}
