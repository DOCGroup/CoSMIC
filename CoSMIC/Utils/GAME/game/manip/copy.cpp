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
 * @class copy_into_impl
 */
class copy_into_impl
{
public:
  copy_into_impl (copy_config_t & config)
    : config_ (config)
  {

  }

  virtual void handle_atom (const Atom & atom) = 0;
  virtual void handle_model (const Model & model) = 0;

protected:
  copy_config_t & config_;
};

/**
 * @class model_copy_into_impl
 */
class model_copy_into_impl : public copy_into_impl
{
public:
  model_copy_into_impl (Model parent, copy_config_t & config)
    : copy_into_impl (config),
      parent_ (parent)
  {

  }

  virtual void handle_atom (const Atom & atom)
  {
    // Create the atom element.
    const std::string metaname = atom.meta ().name ();
    Atom new_atom = Atom::_create (this->parent_, metaname);
    this->config_.mapping_[atom] = new_atom;

    // Set the name of the atom.
    new_atom.name (atom.name ());

    // Copy over its attributes and location.
    copy_attributes (atom, new_atom);

    if (this->config_.location_info_)
      copy_location (atom, new_atom, this->config_.aspect_);
  }

  virtual void handle_model (const Model & model)
  {
    // Create the model element and copy the attributes.
    const std::string metaname = model.meta ().name ();
    Model new_model = Model::_create (this->parent_, model.meta ().name ());
    this->config_.mapping_[model] = new_model;

    new_model.name (model.name ());
    copy_attributes (model, new_model);

    if (this->config_.location_info_)
      copy_location (model, new_model, this->config_.aspect_);

    // Now, copy the model elements into the new model.
    copy (model, new_model, this->config_);
  }

private:
  Model parent_;
};

/**
 * @class folder_copy_into_impl
 */
class folder_copy_into_impl : public copy_into_impl
{
public:
  folder_copy_into_impl (Folder parent, copy_config_t & config)
    : copy_into_impl (config),
      parent_ (parent)
  {

  }

  virtual void handle_atom (const Atom & atom)
  {
    // Create the atom element.
    const std::string metaname = atom.meta ().name ();
    Atom new_atom = Atom::_create (this->parent_, metaname);
    this->config_.mapping_[atom] = new_atom;

    // Set the name of the atom.
    new_atom.name (atom.name ());
    copy_attributes (atom, new_atom);
  }

  virtual void handle_model (const Model & model)
  {
    // Create the model element and copy the attributes.
    const std::string metaname = model.meta ().name ();
    Model new_model = Model::_create (this->parent_, model.meta ().name ());
    this->config_.mapping_[model] = new_model;

    new_model.name (model.name ());
    copy_attributes (model, new_model);

    // Now, copy the model elements into the new model.
    copy (model, new_model, this->config_);
  }

private:
  Folder parent_;
};

/**
 * @struct copy_into_t
 *
 * Functor for copying an element's contents.
 */
struct copy_into_t
{
  copy_into_t (Object parent, copy_config_t & config)
    : impl_ (0)
  {
    switch (parent.type ())
    {
    case OBJTYPE_FOLDER:
      this->impl_.reset (new folder_copy_into_impl (Folder::_narrow (parent), config));
      break;

    case OBJTYPE_MODEL:
      this->impl_.reset (new model_copy_into_impl (Model::_narrow (parent), config));
      break;
    }
  }

  void operator () (const Atom & atom)
  {
    if (0 != this->impl_.get ())
      this->impl_->handle_atom (atom);
  }

  void operator () (const Model & model)
  {
    if (0 != this->impl_.get ())
      this->impl_->handle_model (model);
  }

private:
  std::auto_ptr <copy_into_impl> impl_;
};

/**
 * @struct copy_simple_t
 *
 * Functor for copying over model/atom elements, which are simple
 * cases to handle.
 */
struct copy_simple_t
{
  copy_simple_t (Object dst, copy_config_t & config)
    : copy_ (dst, config)
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
};

/**
 * @struct copy_connection_t
 *
 * Functor for copying a connection into the target model.
 */
struct copy_connection_t
{
  copy_connection_t (Model dst, copy_config_t & config)
    : dst_ (dst),
      config_ (config)
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
                                               this->config_.mapping_[src_from],
                                               this->config_.mapping_[src_to]);

    new_conn.name (src_conn.name ());

    // Finally, copy over the attributes.
    copy_attributes (src_conn, new_conn);
  }

private:
  Model dst_;

  copy_config_t & config_;
};

/**
 * @struct copy_reference_t
 *
 * Functor for copying a reference into the target model.
 */
struct copy_reference_t
{
  copy_reference_t (const Model & dst,
                    copy_config_t & config)
    : dst_ (dst),
      config_ (config)
  {

  }

  void operator () (const FCO & fco)
  {
    if (fco.type () != OBJTYPE_REFERENCE)
      return;

    // Create a new reference based on the source.
    Reference orig = Reference::_narrow (fco);
    const std::string metaname = orig.meta ().name ();

    Reference new_ref = Reference::_create (this->dst_, metaname);
    this->config_.mapping_[orig] = new_ref;

    new_ref.name (orig.name ());

    // Set the reference element.
    FCO target = this->config_.mapping_[orig.refers_to ()];
    new_ref.refers_to (target);

    // Finally, copy over the attributes.
    copy_attributes (orig, new_ref);

    if (this->config_.location_info_)
      copy_location (orig, new_ref, this->config_.aspect_);
  }

private:
  const Model & dst_;

  copy_config_t & config_;
};

//
// copy_config_t
//
copy_config_t::copy_config_t (void)
: aspect_ (""),
  location_info_ (true)
{

}

///////////////////////////////////////////////////////////////////////////////
// copy ()

//
// copy
//
Model copy (const Model & src, Model dst)
{
  return copy (src, dst, copy_config_t ());
}

//
// copy
//
Folder copy (const Folder & src, Folder dst)
{
  return copy (src, dst, copy_config_t ());
}

//
// copy
//
Model copy (const Model & src, Model dst, copy_config_t & config)
{
  // Gather all the children at this level.
  std::vector <FCO> fcos;

  if (!config.aspect_.empty ())
    src.children (src.meta ().aspect (config.aspect_), fcos);
  else
    src.children (fcos);

  // Copy over the basic types first.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, config));

  // Next, copy over the connections and the references.
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_connection_t (dst, config));

  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_reference_t (dst, config));

  return dst;
}

//
// copy
//
Folder copy (const Folder & src, Folder dst, copy_config_t & config)
{
  // Gather all the children at this level.
  std::vector <FCO> fcos;
  src.children (fcos);

  return copy_into (fcos, dst, config);
}


///////////////////////////////////////////////////////////////////////////////
// copy_location ()

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

//
// copy_into
//
Folder copy_into (const std::vector <FCO> & fcos,
                  Folder dst,
                  copy_config_t & config)
{
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, config));

  return dst;
}

//
// copy_into
//
Model copy_into (const std::vector <FCO> & fcos,
                 Model dst,
                 copy_config_t & config)
{
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, config));

  return dst;
}

}
