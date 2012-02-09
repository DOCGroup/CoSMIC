// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaAspect.h"
#include "MetaAttribute.h"
#include "MetaPart.h"

#if !defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

#include "Collection_T.h"
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

//
// attributes
//
size_t Aspect_Impl::attributes (std::vector <Attribute> & attrs) const
{
  CComPtr <IMgaMetaAttributes> temps;
  VERIFY_HRESULT (this->impl ()->get_Attributes (&temps));

  return iter_to_collection (temps.p, attrs);
}

//
// parts
//
size_t Aspect_Impl::parts (std::vector <Part> & parts) const
{
  CComPtr <IMgaMetaParts> temps;
  VERIFY_HRESULT (this->impl ()->get_Parts (&temps));

  return iter_to_collection (temps.p, parts);
}

}
}
}
