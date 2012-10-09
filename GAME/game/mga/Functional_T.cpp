// $Id$

#include "MetaFCO.h"
#include "Impl_Factory.h"

namespace GAME
{
namespace Mga
{
//
// create_root_folder
//
template <typename T, typename P>
T create_root_folder (P parent, const std::string & meta)
{
  // Select the MetaFCO for the type.
  Meta::Folder role = parent->meta ()->folder (meta);
  return create_root_folder <T> (parent, role);
}

//
// create_root_folder
//
template <typename T, typename P>
T create_root_folder (P parent, const Meta::Folder_in meta)
{
  // Create a new root object.
  CComPtr <IMgaFolder> child;
  VERIFY_HRESULT (parent->impl ()->CreateFolder (meta->impl (), &child));

  // Locate the correct interface.
  typedef typename T::interface_type interface_type;
  CComPtr <interface_type> mga_type;
  VERIFY_HRESULT (child.QueryInterface (&mga_type));

  return mga_type.p;
}

//
// create_root_object
//
template <typename T, typename P>
T create_root_object (P parent, const std::string & metaname)
{
  // Select the MetaFCO for the type.
  Meta::FCO role = parent->meta ()->child (metaname);
  return create_root_object <T> (parent, role);
}

//
// create_root_object
//
template <typename T, typename P>
T create_root_object (P parent, const Meta::FCO_in metafco)
{
  // Create a new root object.
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateRootObject (metafco->impl (), &child));

  // Locate the correct interface.
  typedef typename T::interface_type interface_type;
  CComPtr <interface_type> mga_type;
  VERIFY_HRESULT (child.QueryInterface (&mga_type));

  return mga_type.p;
}

//
// create_object
//
template <typename T, typename P>
T create_object (P parent, const std::string & metaname)
{
  Meta::Role role = parent->meta ()->role (metaname);
  return create_object <T> (parent, role);
}

//
// create_object
//
template <typename T, typename P>
T create_object (P parent, const Meta::Role_in role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateChildObject (role->impl (), &child));

  typedef typename T::interface_type interface_type;
  CComPtr <interface_type> mga_type;
  VERIFY_HRESULT (child.QueryInterface (&mga_type));

  return mga_type.p;
}

//
// create_folder
//
template <typename T, typename P>
T create_folder (P parent, const std::string & metaname)
{
  Meta::Folder meta = parent->meta ()->folder (metaname);
  return create_folder <T> (parent, meta.get ());
}

//
// create_folder
//
template <typename T, typename P>
T create_folder (P parent, const Meta::Folder_in meta)
{
  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (parent->impl ()->CreateFolder (meta->impl (), &folder));

  return folder.p;
}

//
// get_parent
//
template <typename T>
T get_parent (IMgaObject * obj)
{
  // Locate the parent.
  CComPtr <IMgaObject> parent;
  VERIFY_HRESULT (obj->GetParent (&parent, 0));

  Object_Impl * impl = GLOBAL_IMPL_FACTORY::instance ()->allocate (parent.p);
  return T::_narrow_nocheck (impl);
}

//
// get_refers_to
//
template <typename T, typename R>
T get_refers_to (R ref)
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (ref->impl ()->get_Referred (&fco));

  Object_Impl * impl = GLOBAL_IMPL_FACTORY::instance ()->allocate (fco.p);
  return T::_narrow_nocheck (impl);
}

//
// allocate_impl
//
template <typename T>
Object_Impl * allocate_impl (IMgaObject * ptr)
{
  CComPtr <typename T::interface_type> temp;
  VERIFY_HRESULT (ptr->QueryInterface (&temp));

  return new T (temp);
}

}
}
