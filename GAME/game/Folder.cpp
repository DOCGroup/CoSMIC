// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Folder.h"

#if !defined (__GAME_INLINE__)
#include "Folder.inl"
#endif

#include "Exception.h"
#include "Collection_T.h"
#include "Atom.h"
#include "Set.h"
#include "Reference.h"
#include "Model.h"
#include "Visitor.h"

#include <algorithm>

namespace GAME
{

//
// _create
//
Folder Folder_Impl::
_create (const Folder_in parent, const std::string & type)
{
  Meta::Folder meta = parent->meta ()->folder (type);
  return Folder_Impl::_create (parent, meta.get ());
}

//
// _create
//
Folder Folder_Impl::
_create (const Folder_in parent, const Meta::Folder_in meta)
{
  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (parent->impl ()->CreateFolder (meta->impl (), &folder));

  // Use factory to create concrete implementation type.
  return folder.p;
}

//
// children
//
size_t Folder_Impl::children (std::vector <GAME::Folder> & folders) const
{
  CComPtr <IMgaFolders> tempptr;
  VERIFY_HRESULT (this->impl ()->get_ChildFolders (&tempptr));

  return get_children (tempptr.p, folders);
}

/**
 * @struct filter_t
 *
 * Functor for filtering folders by their metaname.
 */
struct filter_t
{
  filter_t (const std::string & type, std::vector <GAME::Folder> & coll)
    : type_ (type),
      coll_ (coll)
  {

  }

  void operator () (const GAME::Folder & folder) const
  {
    if (folder->meta ()->name () == this->type_)
      this->coll_.push_back (folder);
  }

private:
  const std::string & type_;

  std::vector <GAME::Folder> & coll_;
};

//
// children
//
size_t Folder_Impl::
children (const std::string & type, std::vector <GAME::Folder> & folders) const
{
  // Clear the folders in the collection.
  folders.clear ();

  // Get all the child folders in this folder.
  std::vector <GAME::Folder> temp_set;

  if (this->children (temp_set) > 0)
    std::for_each (temp_set.begin (),
                   temp_set.end (),
                   filter_t (type, folders));

  return folders.size ();
}

//
// children
//
size_t Folder_Impl::children (std::vector <FCO> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos.p, children);
}

//
// children
//
size_t Folder_Impl::
children (const std::string & type, std::vector <GAME::Atom> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos.p, children);
}

//
// children
//
size_t Folder_Impl::
children (const std::string & type, std::vector <GAME::Model> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos.p, children);
}

//
// children
//
size_t Folder_Impl::
children (const std::string & type, std::vector <GAME::Reference> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos.p, children);
}

//
// children
//
size_t Folder_Impl::
children (const std::string & type, std::vector <GAME::Set> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos.p, children);
}

//
// parent
//
Folder Folder_Impl::parent(void) const
{
  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (this->impl ()->get_ParentFolder (&folder));

  return new Folder_Impl (folder);
}

//
// meta
//
GAME::Meta::Folder Folder_Impl::meta (void) const
{
  CComPtr <IMgaMetaFolder> meta;
  VERIFY_HRESULT (this->impl ()->get_MetaFolder (&meta));

  return meta.p;
}

//
// registry_value
//
std::string Folder_Impl::registry_value (const std::string & path) const
{
  CComBSTR bstrvalue;
  CComBSTR bstrpath (path.length (), path.c_str ());

  VERIFY_HRESULT (this->impl ()->get_RegistryValue (bstrpath, &bstrvalue));

  CW2A tempstr (bstrvalue);
  return tempstr.m_psz ? tempstr.m_psz : "";
}

//
// registry_value
//
void Folder_Impl::
registry_value (const std::string & path, const std::string & value)
{
  CComBSTR bstrpath (path.length (), path.c_str ());
  CComBSTR bstrvalue (value.length (), value.c_str ());

  VERIFY_HRESULT (this->impl ()->put_RegistryValue (bstrpath, bstrvalue));
}

//
// registry_node
//
RegistryNode Folder_Impl::registry_node (const std::string & path) const
{
  CComPtr <IMgaRegNode> node;
  CComBSTR bstrval (path.size (), path.c_str ());

  VERIFY_HRESULT (this->impl ()->get_RegistryNode (bstrval, &node));
  return node.p;
}

//
// registry
//
size_t Folder_Impl::registry (std::vector <GAME::RegistryNode> & nodes,
                         bool virtualinterface_types) const
{
  // Get all the subnodes.
  CComPtr <IMgaRegNodes> rawnodes;
  VARIANT_BOOL vtypes = !virtualinterface_types ? VARIANT_FALSE : VARIANT_TRUE;
  VERIFY_HRESULT (this->impl ()->get_Registry (vtypes, &rawnodes));

  return get_children (rawnodes.p, nodes);
}

//
// accept
//
void Folder_Impl::accept (Visitor * v)
{
  v->visit_Folder (this);
}

//
// impl
//
IMgaFolder * Folder_Impl::impl (void) const
{
  if (this->folder_.p == this->object_.p)
    return this->folder_.p;

  if (this->folder_.p != 0)
    this->folder_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->folder_));
  return this->folder_.p;
}

//
// attach
//
void Folder_Impl::attach (IMgaFolder * folder)
{
  VERIFY_HRESULT (folder->QueryInterface (&this->object_));
}

}
