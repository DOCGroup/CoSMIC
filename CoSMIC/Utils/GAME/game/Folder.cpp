// $Id$

#include "stdafx.h"
#include "Folder.h"

#if !defined (__GME_INLINE__)
#include "Folder.inl"
#endif

#include "MetaFolder.h"
#include "Visitor.h"
#include "Atom.h"
#include "Set.h"
#include "Reference.h"
#include "Model.h"
#include <algorithm>

namespace GME
{
  //
  // children
  //
  size_t Folder::children (std::vector <GME::Folder> & folders) const
  {
    CComPtr <IMgaFolders> tempptr;
    VERIFY_HRESULT (this->impl ()->get_ChildFolders (&tempptr));

    return get_children (tempptr, folders);
  }

  /**
   * @struct filter_t
   *
   * Functor for filtering folders by their metaname.
   */
  struct filter_t
  {
    filter_t (const std::string & type, std::vector <GME::Folder> & coll)
      : type_ (type),
        coll_ (coll)
    {

    }

    void operator () (const GME::Folder & folder) const
    {
      if (folder.meta ().name () == this->type_)
        this->coll_.push_back (folder);
    }

  private:
    const std::string & type_;

    std::vector <GME::Folder> & coll_;
  };

  //
  // children
  //
  size_t Folder::
  children (const std::string & type, std::vector <GME::Folder> & folders) const
  {
    // Clear the folders in the collection.
    folders.clear ();

    // Get all the child folders in this folder.
    std::vector <GME::Folder> temp_set;

    if (this->children (temp_set) > 0)
      std::for_each (temp_set.begin (),
                     temp_set.end (),
                     filter_t (type, folders));

    return folders.size ();
  }

  //
  // children
  //
  size_t Folder::children (std::vector <FCO> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

    return get_children (fcos, children);
  }

  //
  // children
  //
  size_t Folder::
  children (const std::string & type, std::vector <GME::Atom> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    return get_children (fcos, children);
  }

  //
  // children
  //
  size_t Folder::
  children (const std::string & type, std::vector <GME::Model> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    return get_children (fcos, children);
  }

  //
  // children
  //
  size_t Folder::
  children (const std::string & type, std::vector <GME::Reference> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    return get_children (fcos, children);
  }

  //
  // children
  //
  size_t Folder::
  children (const std::string & type, std::vector <GME::Set> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    return get_children (fcos, children);
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
  // _create
  //
  Folder Folder::_create (Folder & parent, const std::string & type)
  {
    Meta::Folder meta = parent.meta ().folder (type);
    return Folder::_create (parent, meta);
  }

  //
  // _create
  //
  Folder Folder::_create (Folder & parent, const Meta::Folder & meta)
  {
    CComPtr <IMgaFolder> folder;
    VERIFY_HRESULT (parent.impl ()->CreateFolder (meta, &folder));
    return folder.p;
  }

  //
  // _narrow
  //
  Folder Folder::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaFolder> folder;

    VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&folder),
                             GME::Invalid_Cast ());

    return folder.p;
  }

  //
  // parent
  //
  Folder Folder::parent(void) const
  {
    CComPtr <IMgaFolder> folder;
    VERIFY_HRESULT (this->impl ()->get_ParentFolder (&folder));

    return folder.p;
  }

  //
  // meta
  //
  Meta::Folder Folder::meta (void) const
  {
    CComPtr <IMgaMetaFolder> meta;
    VERIFY_HRESULT (this->impl ()->get_MetaFolder (&meta));

    return meta.p;
  }

  //
  // registry_value
  //
  std::string Folder::registry_value (const std::string & path) const
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
  void Folder::
  registry_value (const std::string & path, const std::string & value)
  {
    CComBSTR bstrpath (path.length (), path.c_str ());
    CComBSTR bstrvalue (value.length (), value.c_str ());

    VERIFY_HRESULT (this->impl ()->put_RegistryValue (bstrpath, bstrvalue));
  }

  //
  // registry_node
  //
  RegistryNode Folder::registry_node (const std::string & path) const
  {
    CComPtr <IMgaRegNode> node;
    CComBSTR bstrval (path.size (), path.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RegistryNode (bstrval, &node));
    return node.p;
  }

  //
  // registry
  //
  size_t Folder::registry (std::vector <GME::RegistryNode> & nodes,
                           bool virtualinterface_types) const
  {
    // Get all the subnodes.
    CComPtr <IMgaRegNodes> rawnodes;
    VARIANT_BOOL vtypes = !virtualinterface_types ? VARIANT_FALSE : VARIANT_TRUE;
    VERIFY_HRESULT (this->impl ()->get_Registry (vtypes, &rawnodes));

    return get_children (rawnodes, nodes);
  }

  //
  // accept
  //
  void Folder::accept (GME::Visitor & visitor)
  {
    visitor.visit_Folder (*this);
  }

  //
  // impl
  //
  IMgaFolder * Folder::impl (void) const
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
  void Folder::attach (IMgaFolder * folder)
  {
    VERIFY_HRESULT (folder->QueryInterface (&this->object_));
  }
}
