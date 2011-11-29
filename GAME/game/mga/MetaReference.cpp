// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "MetaReference.h"

#if !defined (__GAME_INLINE__)
#include "MetaReference.inl"
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
IMgaMetaReference * Reference_Impl::impl (void) const
{
  if (this->ref_.p == this->metabase_.p)
    return this->ref_.p;

  if (this->ref_.p != 0)
    this->ref_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->ref_));
  return this->ref_.p;
}

//
// targets
//
size_t Reference_Impl::targets (std::vector <FCO> & fcos)
{
  // Get the reference pointer specification.
  CComPtr <IMgaMetaPointerSpec> spec;
  VERIFY_HRESULT (this->impl ()->get_RefSpec (&spec));

  // Get each of the items in the specification.
  CComPtr <IMgaMetaPointerItems> items;
  VERIFY_HRESULT (spec->get_Items (&items));

  // Get the root folder for this project.
  Folder root_folder = this->project ().root_folder ();

  // Locate each item in the project and store it.
  long count = 0;
  items->get_Count (&count);

  for (long i = 1; i <= count; ++ i)
  {
    CComBSTR name;
    CComPtr <IMgaMetaPointerItem> item;

    // Get the next item in the collection.
    VERIFY_HRESULT (items->get_Item (i, &item));
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
