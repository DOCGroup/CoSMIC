// $Id$

#include "stdafx.h"
#include "copy.h"

#include "game/Atom.h"
#include "game/Attribute.h"
#include "game/Connection.h"
#include "game/Reference.h"
#include "game/FCO.h"

#include "game/MetaAttribute.h"
#include "game/MetaFCO.h"
#include "game/MetaModel.h"

#include <map>

#include "boost/bind.hpp"

namespace GAME
{

/**
 * @struct copy_attribute_t
 *
 * Functor for copying an attribute to an FCO.
 */
struct copy_attribute_t
{
  copy_attribute_t (FCO fco)
    : fco_ (fco)
  {

  }

  void operator () (const Attribute & src) const
  {
    // Locate the destination attribute.
    GAME::Attribute dst = this->fco_.attribute (src.meta ().name ());

    switch (dst.meta ().type ())
    {
    case ATTVAL_BOOLEAN:
      dst.bool_value (src.bool_value ());
      break;

    case ATTVAL_DOUBLE:
      dst.float_value (src.float_value ());
      break;

    case ATTVAL_ENUM:
    case ATTVAL_STRING:
      dst.string_value (src.string_value ());
      break;

    case ATTVAL_INTEGER:
      dst.int_value (src.int_value ());
      break;
    }
  }

private:
  /// Destination FCO element.
  FCO fco_;
};

//
// copy_attributes
//
FCO copy_attributes (const FCO & src, FCO dst)
{
  // Select the attributes from the source.
  std::vector <Attribute> attrs;
  src.attributes (attrs);

  std::for_each (attrs.begin (),
                 attrs.end (),
                 copy_attribute_t (dst));

  return dst;
};

/**
 * @struct copy_into_t
 *
 * Functor for copying an element's contents.
 */
struct copy_into_t
{
  typedef std::map <FCO, FCO> map_t;

  copy_into_t (const std::string & aspect, Model parent, map_t & mapping)
    : aspect_ (aspect),
      parent_ (parent),
      mapping_ (mapping)
  {

  }

  void operator () (const Atom & atom)
  {
    // Create the atom element.
    Atom new_atom = Atom::_create (this->parent_, atom.meta ().name ());
    this->mapping_[atom] = new_atom;

    // Set the name of the atom.
    new_atom.name (atom.name ());

    // Copy over its attributes and location.
    copy_attributes (atom, new_atom);
    copy_location (atom, new_atom, this->aspect_);
  }

  void operator () (const Model & model)
  {
    // Create the model element and copy the attributes.
    Model new_model = Model::_create (this->parent_, model.meta ().name ());
    this->mapping_[model] = new_model;

    new_model.name (model.name ());
    copy_attributes (model, new_model);
    copy_location (model, new_model, this->aspect_);

    // Now, copy the model elements into the new model.
    copy (model, new_model, this->aspect_);
  }

private:
  /// The source aspect.
  const std::string & aspect_;

  /// The destination model.
  Model parent_;

  std::map <FCO, FCO> & mapping_;
};

/**
 * @struct copy_simple_t
 *
 * Functor for copying over model/atom elements, which are simple
 * cases to handle.
 */
struct copy_simple_t
{
  copy_simple_t (const std::string & aspect,
                 Model dst,
                 std::map <FCO, FCO> & mapping)
    : copy_ (aspect, dst, mapping),
      mapping_ (mapping)
  {

  }

  void operator () (const FCO & fco)
  {
    switch (fco.type ())
    {
    case OBJTYPE_ATOM:
      this->copy_ (Atom::_narrow (fco));
      break;

    case OBJTYPE_MODEL:
      this->copy_ (Model::_narrow (fco));
      break;
    }
  }

private:
  copy_into_t copy_;

  std::map <FCO, FCO> & mapping_;
};

/**
 * @struct copy_connection_t
 *
 * Functor for copying a connection into the target model.
 */
struct copy_connection_t
{
  copy_connection_t (Model dst, std::map <FCO, FCO> & mapping)
    : dst_ (dst),
      mapping_ (mapping)
  {

  }

  void operator () (const FCO & fco)
  {
    if (fco.type () != OBJTYPE_CONNECTION)
      return;

    // Get the connection and its src/dst endpoints.
    Connection src_conn = Connection::_narrow (fco);
    FCO src_from = src_conn[std::string ("src")].target ();
    FCO src_to = src_conn[std::string ("dst")].target ();

    // Now, let's create the new connection.
    std::string metaname = src_conn.meta ().name ();
    Connection new_conn = Connection::_create (this->dst_,
                                               metaname,
                                               this->mapping_[src_from],
                                               this->mapping_[src_to]);

    new_conn.name (src_conn.name ());

    // Finally, copy over the attributes.
    copy_attributes (src_conn, new_conn);
  }

private:
  Model dst_;

  std::map <FCO, FCO> & mapping_;
};

/**
 * @struct copy_reference_t
 *
 * Functor for copying a reference into the target model.
 */
struct copy_reference_t
{
  copy_reference_t (const std::string & aspect,
                    const Model & dst,
                    std::map <FCO, FCO> & mapping)
    : aspect_ (aspect),
      dst_ (dst),
      mapping_ (mapping)
  {

  }

  void operator () (const FCO & fco)
  {
    if (fco.type () != OBJTYPE_REFERENCE)
      return;

    // Create a new reference based on the source.
    Reference orig = Reference::_narrow (fco);
    Reference copy = Reference::_create (this->dst_, orig.role ());

    copy.name (orig.name ());
    copy.refers_to (orig.refers_to ());

    // Finally, copy over the attributes.
    copy_attributes (orig, copy);
    copy_location (orig, copy, this->aspect_);
  }

private:
  const std::string & aspect_;

  const Model & dst_;

  std::map <FCO, FCO> & mapping_;
};

//
// copy
//
Model copy (const Model & src, Model dst, const std::string & aspect)
{
  std::map <FCO, FCO> mapping;
  std::vector <FCO> fcos;

  // Gather all the children at this level.
  if (!aspect.empty ())
    src.children (src.meta ().aspect (aspect), fcos);
  else
    src.children (fcos);

  // Copy over the basic types first.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (aspect, dst, mapping));

  // Next, copy over the connections and the references.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_connection_t (dst, mapping));

  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_reference_t (aspect, dst, mapping));

  return dst;
}

//
// copy_location_i
//
static void copy_location_i (const FCO & src, FCO dst, const Meta::Aspect & src_aspect)
{
  // Let's make sure this element is in this aspect.
  GAME::Part part = src.part (src_aspect);
  if (part.is_nil ())
    return;

  // Get the source element's location.
  long x, y;
  part.get_location (x, y);

  // Locate the parent element of the destination model.
  GAME::Model parent = dst.parent_model ();
  if (parent.is_nil ())
    return;

  const std::string name = src_aspect.name ();
  GAME::Meta::Aspect dst_aspect = parent.meta ().aspect (name);

  if (dst_aspect.is_nil ())
    return;

  // Set the destination's element's location. We still need
  // to verify that the element is part of this aspect since
  // something weird may happen on the GME end.
  part = dst.part (dst_aspect);

  if (!part.is_nil ())
    part.set_location (x, y);
}

//
// copy_location
//
void copy_location (const FCO & src, FCO dst, const std::string & aspect)
{
  // There is no need to continue if the parent is not a model
  // since a folder does not have a view.
  Model parent = src.parent_model ();

  if (parent.is_nil ())
    return;

  if (aspect.empty ())
  {
    // We are going to copy the location of every aspect. This is
    // just to be safe since no aspect was specified.
    std::vector <Meta::Aspect> aspects;
    parent.meta ().aspects (aspects);

    std::for_each (aspects.begin (),
                   aspects.end (),
                   boost::bind (&copy_location_i, src, dst, _1));
  }
  else
  {
    GAME::Meta::Model metamodel = parent.meta ();

    if (metamodel.is_nil ())
      return;

    GAME::Meta::Aspect this_aspect = metamodel.aspect (aspect);

    if (!this_aspect.is_nil ())
      copy_location_i (src, dst, this_aspect);
  }
}

}
