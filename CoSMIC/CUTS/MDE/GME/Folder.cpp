// $Id$

#include "Folder.h"
#include "FCO.h"
#include "Model.h"
#include "Atom.h"
#include "Set.h"

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
    : Object (folder)
  {

  }

  //
  // Folder
  //
  Folder::Folder (const Folder & folder)
    : Object (folder)
  {

  }

  //
  // Folder
  //
  Folder::~Folder (void)
  {

  }

  //
  // get_children
  //
  template <typename T>
  std::vector <T> Folder::get_children (const std::string & type) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    std::vector <T> children (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
      {
        typename T::_type * temp = 0;
        VERIFY_HRESULT (array[i].QueryInterface (&temp));

        children[i].attach (temp);
      }

      // Delete the temp array.
      delete [] array;
    }

    return children;
  }

  //
  // fcos
  //
  std::vector <FCO> Folder::fcos (void) const
  {
    // Get the child FCOs for the folder.
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

    // Determine how many there are.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    std::vector <FCO> children (count);

    if (count > 0)
    {
      // Store all the FCOs in the vector.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
        children[i].attach (array[i]);

      // Delete the temp array.
      delete [] array;
    }

    return children;
  }

  //
  // folders
  //
  std::vector <Folder> Folder::folders (void) const
  {
    CComPtr <IMgaFolders> folders;
    VERIFY_HRESULT (this->impl ()->get_ChildFolders (&folders));

    // Determine how many folders there are.
    long count;
    VERIFY_HRESULT (folders->get_Count (&count));
    std::vector <Folder> children (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaFolder> * array = new CComPtr <IMgaFolder> [count];
      VERIFY_HRESULT (folders->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
        children[i].attach (array[i]);

      // Delete the temp array.
      delete [] array;
    }

    return children;
  }

  //
  // models
  //
  std::vector <Model> Folder::models (const std::string & type) const
  {
    return this->get_children <Model> (type);
  }

  //
  // atoms
  //
  std::vector <Atom> Folder::atoms (const std::string & type) const
  {
    return this->get_children <Atom> (type);
  }

  //
  // fcos
  //
  std::vector <FCO> Folder::fcos (const std::string & type) const
  {
    return this->get_children <FCO> (type);
  }

  //
  // sets
  //
  std::vector <Set> Folder::sets (const std::string & type) const
  {
    return this->get_children <Set> (type);
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
  // attach
  //
  void Folder::attach (IMgaFolder * folder)
  {
    VERIFY_HRESULT (folder->QueryInterface (&this->object_));
  }

  //
  // impl
  //
  IMgaFolder * Folder::impl (void) const
  {
    if (this->folder_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->folder_));

    return this->folder_.p;
  }
}
