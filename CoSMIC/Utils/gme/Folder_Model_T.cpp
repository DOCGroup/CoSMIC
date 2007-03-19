// $Id$

#include "Set.h"
#include "Reference.h"
#include "Atom.h"
#include "Model.h"

#if !defined (__GME_INLINE__)
#include "Folder_Model_T.inl"
#endif

namespace GME
{
  //
  // impl
  //
  template <typename T, typename BASE>
  T * Folder_Model_T <T, BASE>::impl (void) const
  {
    if (this->type_.p != this->object_.p)
    {
      // We need to release the current interface since there
      // is no guarantee the QueryInterface method will release
      // the current interface in <type_>.
      if (this->type_)
        this->type_.Release ();

      this->object_.QueryInterface (&this->type_);
    }

    return this->type_.p;
  }

  //
  // get_children
  //
  template <typename T, typename BASE>
  template <typename T2>
  size_t Folder_Model_T <T, BASE>::
  get_children (const std::string & type,
                std::vector <T2> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    children.resize (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
      {
        typename T2::_type * temp = 0;
        array[i].QueryInterface (&temp);

        children[i].attach (temp);
      }

      // Delete the temp array.
      delete [] array;
    }

    return count;
  }
}
