// $Id$

#include "MetaFCO.h"

namespace GAME
{
namespace Mga
{
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

  typedef typename T::impl_type impl_type;
  return new impl_type (mga_type.p);
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

  typedef typename T::impl_type impl_type;
  return new impl_type (mga_type.p);
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

  typedef typename T::impl_type impl_type;
  return new impl_type (folder.p);
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

  // Get the correct interface type.
  typedef typename T::interface_type interface_type;
  CComPtr <interface_type> mga_type;
  VERIFY_HRESULT (parent.QueryInterface (&mga_type));

  // Allocate a new implementation.
  typedef typename T::impl_type impl_type;
  return new impl_type (mga_type.p);
}

}
}
