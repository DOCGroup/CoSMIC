// $Id$

#include "Folder.h"

namespace GME
{
  //
  // Folder
  //
  Folder::Folder (void)
  {

  }

  //
  // Folder
  //
  Folder::Folder (IMgaFolder * folder)
    : _base_type (folder)
  {

  }

  //
  // Folder
  //
  Folder::Folder (const Folder & folder)
    : _base_type (folder)
  {

  }

  //
  // Folder
  //
  Folder::~Folder (void)
  {

  }

  //
  // folders
  //
  size_t Folder::folders (std::vector <Folder>  & folders) const
  {
    CComPtr <IMgaFolders> tempptr;
    VERIFY_HRESULT (this->impl ()->get_ChildFolders (&tempptr));

    // Determine how many folders there are.
    long count;
    VERIFY_HRESULT (tempptr->get_Count (&count));
    folders.resize (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaFolder> * array = new CComPtr <IMgaFolder> [count];
      VERIFY_HRESULT (tempptr->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
        folders[i].attach (array[i]);

      // Delete the temp array.
      delete [] array;
    }

    return count;
  }

  //
  // operator =
  //
  const Folder & Folder::operator = (const Folder & folder)
  {
    if (this != &folder)
      this->object_ = folder.object_;

    return *this;
  }

  //
  // _create
  //
  Folder Folder::_create (const std::string & type, Folder & parent)
  {
    CComPtr <IMgaFolder> folder;
    MetaFolder meta = parent.meta ().folder (type);

    if (meta)
    {
      VERIFY_HRESULT (parent.impl ()->CreateFolder (meta, &folder));
    }

    return folder.p;
  }

  //
  // parent
  //
  Folder Folder::parent(void) const
  {
    CComPtr <IMgaFolder> folder;
    VERIFY_HRESULT (this->impl ()->get_ParentFolder (&folder));

    return folder.p;
  }

  //
  // meta
  //
  MetaFolder Folder::meta (void) const
  {
    CComPtr <IMgaMetaFolder> meta;
    VERIFY_HRESULT (this->impl ()->get_MetaFolder (&meta));

    return meta.p;
  }
}
