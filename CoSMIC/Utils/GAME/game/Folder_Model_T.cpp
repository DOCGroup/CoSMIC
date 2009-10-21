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
    if (this->type_.p == this->object_.p)
      return this->type_.p;

    if (this->type_.p != 0)
      this->type_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->type_));
    return this->type_.p;
  }

  //
  // fcos
  //
  template <typename T, typename BASE>
  size_t Folder_Model_T <T, BASE>::fcos (GME::Collection_T <FCO> & children)
  {
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // get_children
  //
  template <typename T, typename BASE>
  template <typename CHILD>
  size_t Folder_Model_T <T, BASE>::
  children (const std::string & type,
            GME::Collection_T <CHILD> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }
}
