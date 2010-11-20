// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaFolder.h"

#if !defined (__GAME_INLINE__)
#include "MetaFolder.inl"
#endif

#include "Collection_T.h"

namespace GAME
{
namespace Meta
{
//
// children
//
size_t Folder::
children (std::vector <GAME::Meta::Folder> & folders) const
{
  // Get a pointer to all the legal folders.
  CComPtr <IMgaMetaFolders> metas;
  VERIFY_HRESULT (this->impl ()->get_LegalChildFolders (&metas));

  return get_children (metas, folders);
}

//
// children
//
size_t Folder::
children (std::vector <GAME::Meta::FCO> & fcos) const
{
  // Get a pointer to all the legal folders.
  CComPtr <IMgaMetaFCOs> metas;
  VERIFY_HRESULT (this->impl ()->get_LegalRootObjects (&metas));

  return get_children (metas, fcos);
}

//
// folder
//
Folder Folder::folder (const std::string & name) const
{
  CComPtr <IMgaMetaFolder> meta;
  CComBSTR bstr (name.length (), name.c_str ());

  VERIFY_HRESULT (this->impl ()->get_LegalChildFolderByName (bstr, &meta));
  return meta.p;
}

//
// child
//
FCO Folder::child (const std::string & name) const
{
  CComPtr <IMgaMetaFCO> meta;
  CComBSTR bstr (name.length (), name.c_str ());

  VERIFY_HRESULT (this->impl ()->get_LegalRootObjectByName (bstr, &meta));
  return meta.p;
}

//
// impl
//
IMgaMetaFolder * Folder::impl (void) const
{
  if (this->metabase_.p == this->metafolder_.p)
    return this->metafolder_.p;

  if (this->metafolder_)
    this->metafolder_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->metafolder_));
  return this->metafolder_.p;
}

//
// find
//
FCO Folder::find (const std::string & name, bool in_scope)
{
  // Convert the parameters values to COM.
  CComBSTR bstr (name.length (), name.c_str ());
  VARIANT_BOOL scope = in_scope ? VARIANT_TRUE : VARIANT_FALSE;

  CComPtr <IMgaMetaFCO> fco;

  // Get the defined meta FCO.
  VERIFY_HRESULT (this->impl ()->get_DefinedFCOByName (bstr, scope, &fco));

  return fco.p;
}

}
}