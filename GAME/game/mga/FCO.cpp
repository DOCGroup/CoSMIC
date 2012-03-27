// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "FCO.h"

#if !defined (__GAME_INLINE__)
#include "FCO.inl"
#endif

#include "Exception.h"
#include "Collection_T.h"

#include "Model.h"
#include "Folder.h"
#include "Connection.h"
#include "Reference.h"
#include "Set.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "Visitor.h"
#include "boost/bind.hpp"
#include <sstream>

namespace GAME
{
namespace Mga
{

//
// is_instance
//
bool FCO_Impl::is_instance (void) const
{
  VARIANT_BOOL instance;
  VERIFY_HRESULT (this->impl ()->get_IsInstance (&instance));

  return instance == VARIANT_TRUE ? true : false;
}

//
// is_primary_derived
//
bool FCO_Impl::is_primary_derived (void) const
{
  VARIANT_BOOL primary;
  VERIFY_HRESULT (this->impl ()->get_IsPrimaryDerived (&primary));

  return primary == VARIANT_TRUE ? true : false;
}

//
// impl
//
IMgaFCO * FCO_Impl::impl (void) const
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
Meta::FCO FCO_Impl::meta (void) const
{
  CComPtr <IMgaMetaFCO> meta;
  VERIFY_HRESULT (this->impl ()->get_Meta (&meta));

  return meta.p;
}

//
// meta
//
Meta::Role FCO_Impl::role (void) const
{
  CComPtr <IMgaMetaRole> meta;
  VERIFY_HRESULT (this->impl ()->get_MetaRole (&meta));

  return meta.p;
}

//
// archetype
//
FCO FCO_Impl::archetype (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_ArcheType (&fco));

  return fco.p;
}

//
// basetype
//
FCO FCO_Impl::basetype (void) const
{
  // This will fail if the object is not a subtype.
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_BaseType (&fco));

  return fco.p;
}

//
// instance_type
//
FCO FCO_Impl::instance_type (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_Type (&fco));

  return fco.p;
}

//
// create_subtype
//
FCO FCO_Impl::create_subtype (const Model_in parent)
{
  // Get the metarole for this object.
  std::string metaname = this->meta ()->name ();
  Meta::Role metarole = parent->meta ()->role (metaname);

  // Create the subtype.
  CComPtr <IMgaFCO> child;

  VERIFY_HRESULT (parent->impl ()->DeriveChildObject (
                  this->impl (),
                  metarole->impl (),
                  VARIANT_FALSE,
                  &child));

  return child.p;
}

//
// create_instance
//
FCO FCO_Impl::create_instance (const Model_in parent)
{
  // Get the metarole for this object.
  std::string metaname = this->meta ()->name ();
  Meta::Role metarole = parent->meta ()->role (metaname);

  // Create the instance.
  CComPtr <IMgaFCO> child;

  VERIFY_HRESULT (parent->impl ()->DeriveChildObject (
                  this->impl (),
                  metarole->impl (),
                  VARIANT_TRUE,
                  &child));

  return child.p;
}

//
// registry_value
//
std::string FCO_Impl::registry_value (const std::string & path) const
{
  CComBSTR bstrvalue;
  CComBSTR bstrpath (path.length (), path.c_str ());

  VERIFY_HRESULT (this->impl ()->get_RegistryValue (bstrpath, &bstrvalue));
  if (!bstrvalue)
    return "";

  CW2A tempstr (bstrvalue);
  return tempstr.m_psz;
}

//
// registry_value
//
void FCO_Impl::
registry_value (const std::string & path, const std::string & value)
{
  CComBSTR bstrpath (path.length (), path.c_str ());
  CComBSTR bstrvalue (value.length (), value.c_str ());

  VERIFY_HRESULT (this->impl ()->put_RegistryValue (bstrpath, bstrvalue));
}

//
// attributes
//
size_t FCO_Impl::attributes (std::vector <Attribute> & attrs) const
{
  CComPtr <IMgaAttributes> coll;
  VERIFY_HRESULT (this->impl ()->get_Attributes (&coll));

  return iter_to_collection (coll.p, attrs);
}

//
// parent_model
//
Model FCO_Impl::parent_model (void) const
{
  CComPtr <IMgaModel> model;
  VERIFY_HRESULT (this->impl ()->get_ParentModel (&model));

  return model.p;
}

//
// parent_model
//
Folder FCO_Impl::parent_folder (void) const
{
  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (this->impl ()->get_ParentFolder (&folder));

  return folder.p;
}

//
// in_connection_points
//
size_t FCO_Impl::in_connection_points (ConnectionPoints & points) const
{
  CComPtr <IMgaConnPoints> temp;
  VERIFY_HRESULT (this->impl ()->get_PartOfConns (&temp));

  points.attach (temp.Detach ());
  return points.size ();
}

//
// derived_from
//
FCO FCO_Impl::derived_from (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_DerivedFrom (&fco));

  return fco.p;
}

//
// attribute
//
Attribute FCO_Impl::attribute (const Meta::Attribute_in meta) const
{
  // Get the attribute that corresponds to the meta information.
  CComPtr <IMgaAttribute> attr;
  VERIFY_HRESULT (this->impl ()->get_Attribute (meta->impl (), &attr));

  return attr.p;
}

//
// registry
//
size_t FCO_Impl::
registry (std::vector <RegistryNode> & nodes,
          bool virtual_types) const
{
  // Get all the subnodes.
  CComPtr <IMgaRegNodes> rawnodes;
  VARIANT_BOOL vtypes = !virtual_types ? VARIANT_FALSE : VARIANT_TRUE;
  VERIFY_HRESULT (this->impl ()->get_Registry (vtypes, &rawnodes));

  return iter_to_collection (rawnodes.p, nodes);
}

//
// registry_node
//
RegistryNode FCO_Impl::registry_node (const std::string & path) const
{
  CComPtr <IMgaRegNode> node;
  CComBSTR bstrval (path.size (), path.c_str ());

  VERIFY_HRESULT (this->impl ()->get_RegistryNode (bstrval, &node));
  return node.p;
}

//
// in_sets
//
size_t FCO_Impl::in_sets (std::vector <Set> & sets) const
{
  CComPtr <IMgaFCOs> temp;
  VERIFY_HRESULT (this->impl ()->get_MemberOfSets (&temp));

  return iter_to_collection (temp.p, sets);
}

//
// in_sets
//
Iterator <Set> FCO_Impl::in_sets (void) const
{
  CComPtr <IMgaFCOs> temp;
  VERIFY_HRESULT (this->impl ()->get_MemberOfSets (&temp));

  return Iterator <Set> (temp.p);
}

//
// part
//
Part FCO_Impl::part (const Meta::Aspect_in aspect) const
{
  CComPtr <IMgaPart> part;
  VERIFY_HRESULT (this->impl ()->get_Part (aspect->impl (), &part));

  return Part (part);
}

//
// in_connections
//
size_t FCO_Impl::
in_connections (std::vector <Connection> & conns) const
{
  CComPtr <IMgaConnPoints> temp;
  VERIFY_HRESULT (this->impl ()->get_PartOfConns (&temp));

  std::vector <ConnectionPoint> points;

  if (iter_to_collection (temp.p, points) > 0)
    std::for_each (points.begin (),
                   points.end (),
                   boost::bind (&std::vector <Connection>::push_back,
                                boost::ref (conns),
                                boost::bind (&ConnectionPoint::impl_type::owner,
                                             boost::bind (&ConnectionPoint::get, _1))));

  return conns.size ();
}

//
// in_connections
//
size_t FCO_Impl::
in_connections (const std::string & type, std::vector <Connection> & conns) const
{
  CComPtr <IMgaConnPoints> temp;
  VERIFY_HRESULT (this->impl ()->get_PartOfConns (&temp));

  std::vector <ConnectionPoint> points;

  if (0 == iter_to_collection (temp.p, points))
    return 0;

  Connection conn;
  std::vector <ConnectionPoint>::const_iterator
    iter = points.begin (), iter_end = points.end ();

  for (; iter != iter_end; ++ iter)
  {
    // Get the connection that own this point.
    conn = (*iter)->owner ();

    if (conn->meta ()->name () == type)
      conns.push_back (conn);
  }

  return conns.size ();
}

//
// referenced_by
//
size_t FCO_Impl::referenced_by (std::vector <Reference> & refs) const
{
  CComPtr <IMgaFCOs> temp;
  VERIFY_HRESULT (this->impl ()->get_ReferencedBy (&temp));

  return iter_to_collection (temp.p, refs);
}

//
// referenced_by
//
Iterator <Reference> FCO_Impl::referenced_by (void) const
{
  CComPtr <IMgaFCOs> temp;
  VERIFY_HRESULT (this->impl ()->get_ReferencedBy (&temp));

  return Iterator <Reference> (temp.p);
}

}
}
