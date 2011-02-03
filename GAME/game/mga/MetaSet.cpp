// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "MetaSet.h"

#if !defined (__GAME_INLINE__)
#include "MetaSet.inl"
#endif

#include "Exception.h"
#include "MetaProject.h"
#include "MetaFolder.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// impl
//
IMgaMetaSet * Set_Impl::impl (void) const
{
  if (this->set_.p == this->metabase_.p)
    return this->set_.p;

  if (this->set_.p != 0)
    this->set_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->set_));
  return this->set_.p;
}

//
// members
//
size_t Set_Impl::members (std::vector <FCO> & fcos)
{
  CComPtr <IMgaMetaPointerSpec> spec;
  VERIFY_HRESULT (this->impl ()->get_MemberSpec (&spec));

  // Get each of the items in the specification.
  CComPtr <IMgaMetaPointerItems> items;
  VERIFY_HRESULT (spec->get_Items (&items));

  // Get the root folder for this project.
  Folder root_folder = this->project ().root_folder ();

  // Locate each item in the project and store it.
  long count = 0;
  items->get_Count (&count);

  for (long i = 0; i < count; ++ i)
  {
    CComBSTR name;
    CComPtr <IMgaMetaPointerItem> item;

    // Get the next item in the collection.
    VERIFY_HRESULT (items->get_Item (count, &item));
    VERIFY_HRESULT (item->get_Desc (&name));

    // Locate the FCO with the specified name.
    CComPtr <IMgaMetaFCO> fco;
    VERIFY_HRESULT (root_folder->impl ()->get_DefinedFCOByName (name, VARIANT_TRUE, &fco));

    if (0 != fco.p)
      fcos.push_back (fco.p);
  }

  return 0;
}

}
}
}
