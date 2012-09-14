// $Id$

#include "Collection_T.h"
#include "game/mga/Static_Assert.h"

namespace GAME
{
namespace Mga
{

namespace assertion
{

/**
 * @struct element_containable_in_folder
 */
template <typename T>
struct element_containable_in_folder
{
  static const bool result_type = true;
};

template < >
struct element_containable_in_folder <reference_tag_t>
{
  static const bool result_type = false;
};

template < >
struct element_containable_in_folder <set_tag_t>
{
  static const bool result_type = false;
};

/**
 * @struct element_is_not_folder
 */
template <typename T>
struct element_is_not_folder
{
  static const bool result_type = true;
};

template < >
struct element_is_not_folder <folder_tag_t>
{
  static const bool result_type = false;
};

/**
 * @struct element_is_not_folder
 */
template <typename T>
struct element_is_folder
{
  static const bool result_type = false;
};

template < >
struct element_is_folder <folder_tag_t>
{
  static const bool result_type = true;
};

}

//
// children
//
template <typename T>
size_t Folder_Impl::children (std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
template <typename T>
Iterator <T> Folder_Impl::children (void) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (impl_type::metaname.length (), impl_type::metaname.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return Iterator <T> (fcos.p);
}

//
// children
//
template <typename T>
Iterator <T> Folder_Impl::children (const std::string & type) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return Iterator <T> (fcos.p);
}

//
// children
//
template <typename T>
size_t Folder_Impl::
children (const std::string & type, std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert < assertion::element_containable_in_folder <impl_type::type_tag>::result_type >::result_type;
  GAME::static_assert < assertion::element_is_not_folder <impl_type::type_tag>::result_type >::result_type;

  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// folders
//
template <typename T>
size_t Folder_Impl::folders (std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert <
    GAME::negate <assertion::element_is_not_folder <impl_type::type_tag>::result_type>::result_type >::
    result_type;

  CComPtr <IMgaFolders> folders;
  VERIFY_HRESULT (this->impl ()->get_ChildFolders (&folders));

  for (Iterator <Folder> iter (folders.p); !iter.is_done (); ++ iter)
  {
    if ((*iter)->meta ()->name () == T::impl_type::metaname)
      children.push_back (*iter);
  }

  return children.size ();
}

//
// folders
//
template <typename T>
size_t Folder_Impl::
folders (const std::string & type, std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  GAME::static_assert <
    GAME::negate <assertion::element_is_not_folder <impl_type::type_tag>::result_type>::result_type >::
    result_type;

  CComPtr <IMgaFolders> folders;
  VERIFY_HRESULT (this->impl ()->get_ChildFolders (&folders));

  for (Iterator <Folder> iter (folders.p); !iter.is_done (); ++ iter)
  {
    try
    {
      children.push_back (T::_narrow (*iter));
    }
    catch (GAME::Mga::Invalid_Cast &)
    {
    }
  }

  return children.size ();
}

}
}
