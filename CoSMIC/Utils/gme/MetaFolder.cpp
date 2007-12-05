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
  // subfolder
  //
  Folder Folder::folder (const std::string & type) const
  {
    CComPtr <IMgaMetaFolder> folder;
    CComBSTR name (type.length (), type.c_str ());

    VERIFY_HRESULT (
      this->impl ()->get_LegalChildFolderByName (name, &folder));

    return folder.p;
  }

  //
  // subfolders
  //
  size_t Folder::folders (std::vector <Folder> & folders) const
  {
    // Get a pointer to all the legal folders.
    CComPtr <IMgaMetaFolders> metas;
    VERIFY_HRESULT (this->impl ()->get_LegalChildFolders (&metas));

    // Update the size of <folders>.
    long count;
    VERIFY_HRESULT (metas->get_Count (&count));
    folders.resize (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaMetaFolder> * array = new CComPtr <IMgaMetaFolder> [count];
      VERIFY_HRESULT (metas->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
        folders[i].attach (array[i]);

      // Delete the temp array.
      delete [] array;
    }

    return count;
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
}
}
