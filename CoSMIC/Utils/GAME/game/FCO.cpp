// $Id$

#include "stdafx.h"
#include "FCO.h"

#if !defined (__GME_INLINE__)
#include "FCO.inl"
#endif

#include "Model.h"
#include "Folder.h"
#include "Connection.h"
#include "Attribute.h"
#include "Set.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "MetaAttribute.h"
#include "Visitor.h"
#include <sstream>

namespace GME
{
  //
  // is_instance
  //
  bool FCO::is_instance (void) const
  {
    VARIANT_BOOL instance;
    VERIFY_HRESULT (this->impl ()->get_IsInstance (&instance));

    return instance == VARIANT_TRUE ? true : false;
  }

  //
  // is_primary_derived
  //
  bool FCO::is_primary_derived (void) const
  {
    VARIANT_BOOL primary;
    VERIFY_HRESULT (this->impl ()->get_IsPrimaryDerived (&primary));

    return primary == VARIANT_TRUE ? true : false;
  }

  //
  // operator =
  //
  const FCO & FCO::operator = (const FCO & fco)
  {
    if (this != &fco)
      this->object_ = fco.object_;

    return *this;
  }

  //
  // impl
  //
  IMgaFCO * FCO::impl (void) const
  {
    if (this->fco_.p == this->object_.p)
      return this->fco_.p;

    if (this->fco_.p != 0)
      this->fco_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->fco_));
    return this->fco_.p;
  }

  //
  // meta
  //
  Meta::FCO FCO::meta (void) const
  {
    CComPtr <IMgaMetaFCO> meta;
    VERIFY_HRESULT (this->impl ()->get_Meta (&meta));

    return meta.p;
  }

  //
  // meta
  //
  Meta::Role FCO::role (void) const
  {
    CComPtr <IMgaMetaRole> meta;
    VERIFY_HRESULT (this->impl ()->get_MetaRole (&meta));

    return meta.p;
  }

  //
  // archetype
  //
  FCO FCO::archetype (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_ArcheType (&fco));

    return fco.p;
  }

  //
  // basetype
  //
  FCO FCO::basetype (void) const
  {
    // This will fail if the object is not a subtype.
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_BaseType (&fco));

    return fco.p;
  }

  //
  // instance_type
  //
  FCO FCO::instance_type (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_Type (&fco));

    return fco.p;
  }

  //
  // create_subtype
  //
  FCO FCO::create_subtype (Model & parent)
  {
    // Get the metarole for this object.
    std::string metaname = this->meta ().name ();
    Meta::Role metarole = parent.meta ().role (metaname);

    // Create the subtype.
    CComPtr <IMgaFCO> child;

    VERIFY_HRESULT (
      parent.impl ()->DeriveChildObject (
      this->impl (), metarole, VARIANT_FALSE, &child));

    return child.p;
  }

  //
  // create_instance
  //
  FCO FCO::create_instance (Model & parent)
  {
    // Get the metarole for this object.
    std::string metaname = this->meta ().name ();
    Meta::Role metarole = parent.meta ().role (metaname);

    // Create the instance.
    CComPtr <IMgaFCO> child;

    VERIFY_HRESULT (
      parent.impl ()->DeriveChildObject (
      this->impl (), metarole, VARIANT_TRUE, &child));

    return child.p;
  }

  //
  // _create
  //
  FCO FCO::_create (const std::string & name, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    Meta::Role role = parent.meta ().role (name);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (role, &child));

    return child.p;
  }

  //
  // _narrow
  //
  FCO FCO::_narrow (const Object & object)
  {
    CComPtr <IMgaFCO> fco;

    VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&fco),
                             GME::Invalid_Cast ());

    return fco.p;
  }

  //
  // registry_value
  //
  std::string FCO::registry_value (const std::string & path) const
  {
    CComBSTR bstrvalue;
    CComBSTR bstrpath (path.length (), path.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RegistryValue (bstrpath, &bstrvalue));

    CW2A tempstr (bstrvalue);
    return tempstr.m_psz;
  }

  //
  // registry_value
  //
  void FCO::
  registry_value (const std::string & path, const std::string & value)
  {
    CComBSTR bstrpath (path.length (), path.c_str ());
    CComBSTR bstrvalue (value.length (), value.c_str ());

    VERIFY_HRESULT (this->impl ()->put_RegistryValue (bstrpath, bstrvalue));
  }

  //
  // attributes
  //
  size_t FCO::attributes (std::vector <Attribute> & attrs) const
  {
    CComPtr <IMgaAttributes> coll;
    VERIFY_HRESULT (this->impl ()->get_Attributes (&coll));

    return get_children (coll, attrs);
  }

  //
  // parent_model
  //
  Model FCO::parent_model (void) const
  {
    CComPtr <IMgaModel> model;
    VERIFY_HRESULT (this->impl ()->get_ParentModel (&model));

    return model.p;
  }

  //
  // parent_model
  //
  Folder FCO::parent_folder (void) const
  {
    CComPtr <IMgaFolder> folder;
    VERIFY_HRESULT (this->impl ()->get_ParentFolder (&folder));

    return folder.p;
  }

  //
  // in_connection_points
  //
  size_t FCO::in_connection_points (ConnectionPoints & points) const
  {
    CComPtr <IMgaConnPoints> temp;
    VERIFY_HRESULT (this->impl ()->get_PartOfConns (&temp));

    points.attach (temp.Detach ());
    return points.size ();
  }

  //
  // derived_from
  //
  FCO FCO::derived_from (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_DerivedFrom (&fco));

    return fco.p;
  }

  //
  // attribute
  //
  Attribute FCO::attribute (const std::string & name) const
  {
    // Get the meta attribute with the specified name.
    GME::Meta::Attribute meta_attr = this->meta ().attribute (name);

    // Get the attribute that corresponds to the meta information.
    CComPtr <IMgaAttribute> attr;
    VERIFY_HRESULT (this->impl ()->get_Attribute (meta_attr.impl (), &attr));

    return attr.p;
  }

  //
  // registry
  //
  size_t FCO::registry (std::vector <GME::RegistryNode> & nodes,
                        bool virtual_types) const
  {
    // Get all the subnodes.
    CComPtr <IMgaRegNodes> rawnodes;
    VARIANT_BOOL vtypes = !virtual_types ? VARIANT_FALSE : VARIANT_TRUE;
    VERIFY_HRESULT (this->impl ()->get_Registry (vtypes, &rawnodes));

    return get_children (rawnodes, nodes);
  }

  //
  // registry_node
  //
  RegistryNode FCO::registry_node (const std::string & path) const
  {
    CComPtr <IMgaRegNode> node;
    CComBSTR bstrval (path.size (), path.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RegistryNode (bstrval, &node));
    return node.p;
  }

  //
  // in_sets
  //
  size_t FCO::in_sets (std::vector <GME::Set> & sets) const
  {
    CComPtr <IMgaFCOs> temp;
    VERIFY_HRESULT (this->impl ()->get_MemberOfSets (&temp));

    return get_children (temp, sets);
  }

  void FCO::accept (GME::Visitor & visitor)
  {
    visitor.visit_FCO (*this);
  }
}
