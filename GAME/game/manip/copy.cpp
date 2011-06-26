// $Id$

#include "stdafx.h"
#include "copy.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaAttribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaAtom.h"

#include "game/mga/modelgen.h"
#include "game/manip/copy.h"

#include "boost/bind.hpp"

#include <map>

namespace GAME
{
namespace Mga
{
/**
 * @struct copy_attribute_t
 *
 * Functor for copying an attribute to an FCO.
 */
struct copy_attribute_t
{
  copy_attribute_t (FCO_in dst)
    : dst_ (dst)
  {

  }

  void operator () (const Attribute & src) const
  {
    // Locate the destination attribute.
    Attribute dst = this->dst_->attribute (src->meta ()->name ());

    switch (dst->meta ()->type ())
    {
    case ATTVAL_BOOLEAN:
      if (src->bool_value () != dst->bool_value ())
        dst->bool_value (src->bool_value ());
      break;

    case ATTVAL_DOUBLE:
      if (dst->double_value () != src->double_value ())
        dst->double_value (src->double_value ());
      break;

    case ATTVAL_ENUM:
    case ATTVAL_STRING:
      if (dst->string_value () != src->string_value ())
        dst->string_value (src->string_value ());
      break;

    case ATTVAL_INTEGER:
      if (dst->int_value () != src->int_value ())
        dst->int_value (src->int_value ());
      break;
    }
  }

private:
  /// Destination FCO element.
  FCO dst_;
};

//
// copy_attributes
//
FCO copy_attributes (const FCO_in src, FCO_in dst)
{
  // Select the attributes from the source.
  std::vector <Attribute> attrs;
  src->attributes (attrs);

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

  virtual void handle_atom (Atom_in atom) = 0;

  virtual void handle_model (Model_in model) = 0;

protected:
  copy_config_t & config_;
};

/**
 * @class model_copy_into_impl
 */
class model_copy_into_impl : public copy_into_impl
{
public:
  model_copy_into_impl (Model_in parent, copy_config_t & config)
    : copy_into_impl (config),
      parent_ (parent)
  {

  }

  virtual void handle_atom (Atom_in atom)
  {
    Atom new_atom;
    const std::string metaname = atom->meta ()->name ();
    const std::string name = atom->name ();

    if (this->config_.allow_duplicate_names_)
    {
      // Create the new atom element.
      new_atom = Atom_Impl::_create (this->parent_, metaname);
      new_atom->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (GAME::create_if_not <Mga_t> (this->parent_, metaname, new_atom,
          GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                  name,
                                  boost::bind (&GAME::Mga::Atom::impl_type::name,
                                               boost::bind (&GAME::Mga::Atom::get, _1))))))
      {
        new_atom->name (name);
      }
    }

    // Save the atom in the configuration map.
    this->config_.mapping_.insert (std::make_pair (atom, new_atom));

    // Set the name of the atom, and copy the attributes.
    copy_attributes (atom, new_atom.get ());

    // Copy over the location information.
    if (this->config_.location_info_)
      copy_location (atom, new_atom.get (), this->config_.aspect_);
  }

  virtual void handle_model (Model_in model)
  {
    const std::string name = model->name ();
    const std::string metaname = model->meta ()->name ();

    Model new_model;

    if (this->config_.allow_duplicate_names_)
    {
      // Create the model element.
      new_model = Model_Impl::_create (this->parent_, metaname);
      new_model->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (GAME::create_if_not <Mga_t> (this->parent_, metaname, new_model,
          GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                  name,
                                  boost::bind (&GAME::Mga::Model::impl_type::name,
                                               boost::bind (&GAME::Mga::Model::get, _1))))))
      {
        new_model->name (name);
      }
    }

    // Save the model in the configuration map.
    this->config_.mapping_.insert (std::make_pair (model, new_model));

    // Copy the attributes and the location.
    copy_attributes (model, new_model.get ());

    if (this->config_.location_info_)
      copy_location (model, new_model.get (), this->config_.aspect_);

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
  folder_copy_into_impl (Folder_in parent, copy_config_t & config)
    : copy_into_impl (config),
      parent_ (parent)
  {

  }

  virtual void handle_atom (Atom_in atom)
  {
    Atom new_atom;
    const std::string metaname = atom->meta ()->name ();
    const std::string name = atom->name ();

    if (this->config_.allow_duplicate_names_)
    {
      // Create the new atom element.
      new_atom = Atom_Impl::_create (this->parent_, metaname);
      new_atom->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (GAME::create_if_not <Mga_t> (this->parent_, metaname, new_atom,
          GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                  name,
                                  boost::bind (&GAME::Mga::Atom::impl_type::name,
                                               boost::bind (&GAME::Mga::Atom::get, _1))))))
      {
        new_atom->name (name);
      }
    }

    // Save the new atom.
    this->config_.mapping_.insert (std::make_pair (atom, new_atom));

    // Copy over the attributes.
    copy_attributes (atom, new_atom);
  }

  virtual void handle_model (Model_in model)
  {
    const std::string name = model->name ();
    const std::string metaname = model->meta ()->name ();

    Model new_model;

    if (this->config_.allow_duplicate_names_)
    {
      // Create the model element.
      new_model = Model_Impl::_create (this->parent_, metaname);
      new_model->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (GAME::create_if_not <Mga_t> (this->parent_, metaname, new_model,
          GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                  name,
                                  boost::bind (&GAME::Mga::Model::impl_type::name,
                                               boost::bind (&GAME::Mga::Model::get, _1))))))
      {
        new_model->name (name);
      }
    }

    // Save the new model.
    this->config_.mapping_.insert (std::make_pair (model, new_model));

    // Copy over the attributes.
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
  copy_into_t (Object_in parent, copy_config_t & config)
    : impl_ (0)
  {
    switch (parent->type ())
    {
    case OBJTYPE_FOLDER:
      {
        Folder folder = Folder::_narrow (parent);
        this->impl_.reset (new folder_copy_into_impl (folder, config));
      }
      break;

    case OBJTYPE_MODEL:
      {
        Model model = Model::_narrow (parent);
        this->impl_.reset (new model_copy_into_impl (model, config));
      }
      break;
    }
  }

  void operator () (Atom_in atom)
  {
    if (0 != this->impl_.get ())
      this->impl_->handle_atom (atom);
  }

  void operator () (Model_in model)
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
  copy_simple_t (Object_in dst, copy_config_t & config)
    : copy_ (dst, config)
  {

  }

  void operator () (FCO fco)
  {
    switch (fco->type ())
    {
    case OBJTYPE_ATOM:
      {
        Atom atom = Atom::_narrow (fco.get ());
        this->copy_ (atom.get ());
      }
      break;

    case OBJTYPE_MODEL:
      {
        Model model = Model::_narrow (fco.get ());
        this->copy_ (model.get ());
      }
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
  copy_connection_t (Model_in dst, copy_config_t & config)
    : dst_ (dst),
      config_ (config)
  {

  }

  void operator () (FCO_in fco)
  {
    if (fco->type () != OBJTYPE_CONNECTION)
      return;

    // Get the connection and its src/dst endpoints.
    Connection src_conn = Connection::_narrow (fco);
    FCO src_from = src_conn->src ();
    FCO src_to = src_conn->dst ();

    // Now, let's create the new connection.
    const std::string metaname = src_conn->meta ()->name ();
    const std::string name = src_conn->name ();

    Connection new_conn;

    if (this->config_.allow_duplicate_connections_)
    {
      // We can safely create a new connection without worrying about
      // dealing with duplicate connections.
      new_conn =
        Connection_Impl::_create (this->dst_,
                                  metaname,
                                  this->config_.mapping_[src_from],
                                  this->config_.mapping_[src_to]);

      // Update the connection's name.
      new_conn->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (!GAME::find <Mga_t> (this->dst_, metaname, new_conn,
            boost::bind (std::logical_and <bool> (),
              boost::bind (std::equal_to <FCO> (),
                           this->config_.mapping_[src_from],
                           boost::bind (&GAME::Mga::Connection::impl_type::src,
                                        boost::bind (&GAME::Mga::Connection::get, _1))),
              boost::bind (std::equal_to <FCO> (),
                           this->config_.mapping_[src_to],
                           boost::bind (&GAME::Mga::Connection::impl_type::dst,
                                        boost::bind (&GAME::Mga::Connection::get, _1))))))
      {
        new_conn =
          GAME::Mga::Connection_Impl::_create (this->dst_,
                                               metaname,
                                               this->config_.mapping_[src_from],
                                               this->config_.mapping_[src_to]);

        new_conn->name (name);
      }
    }

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
  copy_reference_t (Model_in dst, copy_config_t & config)
    : dst_ (dst),
      config_ (config)
  {

  }

  void operator () (FCO_in fco)
  {
    if (fco->type () != OBJTYPE_REFERENCE)
      return;

    Reference orig = Reference::_narrow (fco);
    const std::string metaname = orig->meta ()->name ();
    const std::string name = orig->name ();

    Reference new_ref;

    if (this->config_.allow_duplicate_names_)
    {
      // Create a new reference based on the source.
      new_ref = Reference_Impl::_create (this->dst_, metaname);
      new_ref->name (name);
    }
    else
    {
      using GAME::Mga_t;

      if (GAME::create_if_not <Mga_t> (this->dst_, metaname, new_ref,
          GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                  name,
                                  boost::bind (&GAME::Mga::Reference::impl_type::name,
                                               boost::bind (&GAME::Mga::Reference::get, _1))))))
      {
        new_ref->name (name);
      }
    }

    // Save the new element in the configuration mapping.
    this->config_.mapping_.insert (std::make_pair  (orig, new_ref));

    // Determine what should be the FCO that the newly created
    // reference to refer to.
    FCO refers_to = orig->refers_to ();
    FCO target = this->config_.mapping_[refers_to];

    if (target.is_nil ())
      target = refers_to;

    // Set the newly created references target object if they are not
    // the same object.
    refers_to = new_ref->refers_to ();

    if (this->config_.ignorable_fcos_.find (refers_to) != this->config_.ignorable_fcos_.end  ())
    {
      if (refers_to != target)
        new_ref->refers_to (refers_to);
    }
    else
    {
      // It should reference the original target.
      new_ref->refers_to (target);
    }

    // Finally, copy over the attributes.
    copy_attributes (orig.get (), new_ref.get ());

    if (this->config_.location_info_)
      copy_location (orig.get (), new_ref.get (), this->config_.aspect_);
  }

private:
  Model dst_;

  copy_config_t & config_;
};

//
// copy_config_t
//
copy_config_t::copy_config_t (void)
: aspect_ (""),
  location_info_ (true),
  allow_duplicate_names_ (false),
  allow_duplicate_connections_ (false)
{

}

///////////////////////////////////////////////////////////////////////////////
// copy ()

//
// copy
//
Model copy (const Model_in src, Model_in dst)
{
  return copy (src, dst, copy_config_t ());
}

//
// copy
//
Folder copy (const Folder_in src, Folder_in dst)
{
  return copy (src, dst, copy_config_t ());
}

//
// copy
//
Model copy (const Model_in src, Model_in dst, copy_config_t & config)
{
  // Gather all the children at this level.
  std::vector <FCO> fcos;

  if (!config.aspect_.empty ())
    src->children (src->meta ()->aspect (config.aspect_), fcos);
  else
    src->children (fcos);

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
Folder copy (const Folder_in src, Folder_in dst, copy_config_t & config)
{
  // Gather all the children at this level.
  std::vector <FCO> fcos;
  src->children (fcos);

  return copy_into (fcos, dst, config);
}


///////////////////////////////////////////////////////////////////////////////
// copy_location ()

//
// copy_location_i
//
static void
copy_location_i (const FCO_in src,
                 FCO_in dst,
                 const Meta::Aspect_in src_aspect)
{
  // Let's make sure this element is in this aspect.
  Part part = src->part (src_aspect);

  if (part.is_nil ())
    return;

  // Get the source element's location.
  long x, y;
  part.get_location (x, y);

  // Locate the parent element of the destination model.
  Model parent = dst->parent_model ();
  if (parent.is_nil ())
    return;

  const std::string name = src_aspect->name ();
  Meta::Aspect dst_aspect = parent->meta ()->aspect (name);

  if (dst_aspect.is_nil ())
    return;

  // Set the destination's element's location. We still need
  // to verify that the element is part of this aspect since
  // something weird may happen on the GME end.
  part = dst->part (dst_aspect);

  if (part.is_nil ())
    return;

  // Set the location for the new element iff the locations are
  // different. Otherwise, we need to update the location.
  long curr_x, curr_y;
  part.get_location (curr_x, curr_y);

  if (curr_x != x || curr_y != y)
    part.set_location (x, y);
}

//
// copy_location
//
void copy_location (const FCO_in src, FCO_in dst, const std::string & aspect)
{
  // There is no need to continue if the parent is not a model
  // since a folder does not have a view.
  Model parent = src->parent_model ();

  if (parent.is_nil ())
    return;

  if (aspect.empty ())
  {
    // We are going to copy the location of every aspect. This is
    // just to be safe since no aspect was specified.
    std::vector <Meta::Aspect> aspects;
    parent->meta ()->aspects (aspects);

    std::for_each (aspects.begin (),
                   aspects.end (),
                   boost::bind (&copy_location_i, src, dst, _1));
  }
  else
  {
    Meta::Model metamodel = parent->meta ();

    if (metamodel.is_nil ())
      return;

    Meta::Aspect this_aspect = metamodel->aspect (aspect);

    if (!this_aspect.is_nil ())
      copy_location_i (src, dst, this_aspect);
  }
}

//
// copy_into
//
Folder
copy_into (const std::vector <FCO> & fcos, Folder_in dst, copy_config_t & config)
{
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, config));

  return dst;
}

//
// copy_into
//
Model
copy_into (const std::vector <FCO> & fcos, Model_in dst, copy_config_t & config)
{
  std::for_each (fcos.begin (),
                 fcos.end (),
                 copy_simple_t (dst, config));

  return dst;
}

}
}
