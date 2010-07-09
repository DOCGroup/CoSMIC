// $Id$

#include "stdafx.h"
#include "copy.h"

#include "game/Atom.h"
#include "game/Attribute.h"
#include "game/Connection.h"
#include "game/FCO.h"

#include "game/MetaAttribute.h"
#include "game/MetaFCO.h"
#include "game/MetaModel.h"

#include <map>

namespace GAME
{
/**
 * @struct copy_attribute_t
 *
 * Functor for copying an attribute to an FCO.
 */
struct copy_attribute_t
{
  copy_attribute_t (FCO & fco)
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
  FCO & fco_;
};

//
// copy_attributes
//
FCO copy_attributes (const FCO & src, FCO & dst)
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
  copy_into_t (Model & parent, std::map <FCO, FCO> & mapping)
    : parent_ (parent), 
      mapping_ (mapping)
  {

  }

  void operator () (const Atom & atom) const
  {
    // Create the atom element and copy the attributes.
    Atom new_atom = Atom::_create (this->parent_, atom.meta ().name ());
    this->mapping_[atom] = new_atom;

    new_atom.name (atom.name ());
    copy_attributes (atom, new_atom);
  }

  void operator () (const Model & model) const
  {
    // Create the model element and copy the attributes.
    Model new_model = Model::_create (this->parent_, model.meta ().name ());
    this->mapping_[model] = new_model;

    new_model.name (model.name ());
    copy_attributes (model, new_model);

    // Now, copy the model elements into the new model.
    copy (model, new_model);
  }

private:
  /// The destination model.
  Model & parent_;

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
  copy_simple_t (Model & dst, std::map <FCO, FCO> & mapping)
    : copy_ (dst, mapping),
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
  copy_connection_t (Model & dst, std::map <FCO, FCO> & mapping)
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
  Model & dst_;

  std::map <FCO, FCO> & mapping_;
};

//
// copy
//
Model copy (const Model & src, Model & dst)
{
  std::map <FCO, FCO> mapping;

  // Gather all the children at this level.
  std::vector <FCO> fcos;
  src.children (fcos);

  // Copy over the basic types first.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, mapping));

  // Next, copy over the connections and the references.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_connection_t (dst, mapping));

  return dst;
}

}
