// $Id$

#include "Collection_T.h"

namespace GAME
{
namespace Mga
{

namespace assert
{
/**
 * @struct element_not_containable_in_model
 *
 * Assertion that determines if an implementation is containable in
 * a model. This will prevent clients from requesting children of type
 * Folder from a model.
 */
template <typename T>
struct element_not_containable_in_model;

template < >
struct element_not_containable_in_model <fco_tag_t>
{
  static const bool result_type = true;
};

template < >
struct element_not_containable_in_model <atom_tag_t>
{
  static const bool result_type = true;
};

template < >
struct element_not_containable_in_model <model_tag_t>
{
  static const bool result_type = true;
};

template < >
struct element_not_containable_in_model <reference_tag_t>
{
  static const bool result_type = true;
};

template < >
struct element_not_containable_in_model <set_tag_t>
{
  static const bool result_type = true;
};

template < >
struct element_not_containable_in_model <connection_tag_t>
{
  static const bool result_type = true;
};

}

//
// children
//
template <typename T>
size_t Model_Impl::children (std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  assert::element_not_containable_in_model <impl_type::type_tag>::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
template <typename T>
size_t Model_Impl::
children (const std::string & type, std::vector <T> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
template <typename T>
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <T> & children) const
{
  // Let's get the list of children.
  std::vector <T> temp;
  this->children (temp);

  std::vector <T>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

}
}