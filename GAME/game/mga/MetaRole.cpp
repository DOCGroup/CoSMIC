// $Id$

#include "stdafx.h"

#include <cstring>
#include <iostream>
#include "Mga.h"
#include "MetaRole.h"
#include "MetaPart.h"
#include "MetaModel.h"

#if !defined (__GAME_INLINE__)
#include "MetaRole.inl"
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
IMgaMetaRole * Role_Impl::impl (void) const
{
  // Optimize for the short path.
  if (this->metarole_.p == this->metabase_.p)
    return this->metarole_;

  // Ok, so we have to actually get the implementation first.
  if (this->metarole_.p)
    this->metarole_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->metarole_));
  return this->metarole_;
}

//
// parts
//
size_t Role_Impl::parts (std::vector <Part> & parts) const
{
  CComPtr <IMgaMetaParts> temps;
  VERIFY_HRESULT (this->impl ()->get_Parts (&temps));

  return iter_to_collection (temps.p, parts);
}

//
// partscount
//
long Role_Impl::partscount (void) const
{
  CComPtr <IMgaMetaParts> temps;
  VERIFY_HRESULT (this->impl ()->get_Parts (&temps));

  long count;
  VERIFY_HRESULT (temps->get_Count (&count));

  return count;
}

//
// kind
//
FCO Role_Impl::kind (void) const
{
  CComPtr <IMgaMetaFCO> metafco;
  VERIFY_HRESULT (this->impl ()->get_Kind (&metafco));

  return metafco.p;
}

//
// parent
//
Model Role_Impl::parent (void) const
{
  CComPtr <IMgaMetaModel> model;
  VERIFY_HRESULT (this->impl ()->get_ParentModel (&model));

  return model.p;
}

}
}
}
