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
                GME::Collection_T <T2> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }
}
