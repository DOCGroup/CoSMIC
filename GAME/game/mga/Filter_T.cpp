// $Id$

#include "Assert.h"

namespace GAME
{
namespace Mga
{

//
// apply
//
template <typename T>
size_t Filter::apply (std::vector <T> & result) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->project_.impl ()->AllFCOs (this->filter_, &fcos));

  return iter_to_collection (fcos.p, result);
}

//
// apply
//
template <typename T>
Iterator <T> Filter::apply (void) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->project_.impl ()->AllFCOs (this->filter_, &fcos));

  return Iterator <T> (fcos.p);
}

//
// apply
//
template <typename T>
size_t Filter::apply (const Model_in & model, std::vector <T> & result) const
{
  typedef typename T::impl_type impl_type;
  assertion::element_not_containable_in_model <impl_type::type_tag>::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (model->impl ()->GetDescendantFCOs (this->filter_, &fcos));

  return iter_to_collection (fcos.p, result);
}

//
// apply
//
template <typename T>
Iterator <T> Filter::apply (const Model_in & model) const
{
  typedef typename T::impl_type impl_type;
  assertion::element_not_containable_in_model <impl_type::type_tag>::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (folder->impl ()->GetDescendantFCOs (this->filter_, &fcos));

  return Iterator <T> (fcos.p);
}

//
// apply
//
template <typename T>
size_t Filter::apply (const Folder_in & folder, std::vector <T> & result) const
{
  // Make sure the element type is either a folder, or containable
  // in a folder.
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (folder->impl ()->GetDescendantFCOs (this->filter_, &fcos));

  return iter_to_collection (fcos.p, result);
}

//
// apply
//
template <typename T>
Iterator <T> Filter::apply (const Folder_in & folder) const
{
  // Make sure the element type is either a folder, or containable
  // in a folder.
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (folder->impl ()->GetDescendantFCOs (this->filter_, &fcos));

  return Iterator <T> (fcos.p);
}

}
}
