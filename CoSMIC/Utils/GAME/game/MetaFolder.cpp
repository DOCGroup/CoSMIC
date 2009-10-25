// $Id$

#include "stdafx.h"
#include "MetaFolder.h"

#if !defined (__GME_INLINE__)
#include "MetaFolder.inl"
#endif

namespace GME
{
namespace Meta
{
  //
  // children
  //
  size_t Folder::
  children (GME::Collection_T <GME::Meta::Folder> & folders) const
  {
    // Get a pointer to all the legal folders.
    CComPtr <IMgaMetaFolders> metas;
    VERIFY_HRESULT (this->impl ()->get_LegalChildFolders (&metas));

    folders.attach (metas.Detach ());
    return folders.size ();
  }

  //
  // children
  //
  size_t Folder::
  children (GME::Collection_T <GME::Meta::FCO> & fcos) const
  {
    // Get a pointer to all the legal folders.
    CComPtr <IMgaMetaFCOs> metas;
    VERIFY_HRESULT (this->impl ()->get_LegalRootObjects (&metas));

    fcos.attach (metas.Detach ());
    return fcos.size ();
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
  // fco
  //
  GME::Meta::FCO Folder::fco (const std::string & name, bool in_scope)
  {
    // Convert the parameters values to COM.
    CComBSTR bstr (name.length (), name.c_str ());
    VARIANT_BOOL scope = in_scope ? VARIANT_TRUE : VARIANT_FALSE;

    CComPtr <IMgaMetaFCO> fco;

    // Get the defined meta FCO.
    VERIFY_HRESULT (
      this->impl ()->get_DefinedFCOByName (bstr, scope, &fco));

    return fco.p;
  }
}
}
