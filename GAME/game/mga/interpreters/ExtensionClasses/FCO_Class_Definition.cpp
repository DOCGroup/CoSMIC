// $Id$

#include "StdAfx.h"
#include "FCO_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "FCO_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include <assert.h>

#include "Connection_Endpoint_Visitor.h"
#include "Functors.h"
#include "Object_Manager.h"
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>


/**
 * @class Attribute_Visitor
 *
 * Utility class that gathers the unique source endpoints of a
 * connection.
 */
class Attribute_Visitor : public Proxy_Visitor
{
public:
  Attribute_Visitor (GAME::Mga::FCO_in dst, std::set <GAME::Mga::Atom> & items)
    : dst_ (dst),
      items_ (items)
  {

  }

  virtual void visit_Connection (GAME::Mga::Connection_in item)
  {
    item->src ()->accept (this);
  }

  virtual void visit_Atom (GAME::Mga::Atom_in item)
  {
    this->items_.insert (item);
  }

private:
  GAME::Mga::FCO dst_;
  std::set <GAME::Mga::Atom> & items_;
};

/**
 * @class Connection_Point_Visitor
 */
class Connection_Point_Visitor : public Proxy_Visitor
{
public:
  //
  // SourceToConnector_Visitor
  //
  Connection_Point_Visitor (std::set < std::pair <std::string, FCO_Class_Definition *> > & points,
                            Unique_Object_Class_Definitions & includes)
    : points_ (points),
      includes_ (includes)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in item)
  {
    std::vector <GAME::Mga::Connection> association_class;
    item->in_connections ("AssociationClass", association_class);

    std::for_each (GAME::Mga::make_impl_iter (association_class.begin ()),
                   GAME::Mga::make_impl_iter (association_class.end ()),
                   boost::bind (&Connection_Point_Visitor::visit_Connection, this, _1));
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    const std::string metaname = item->meta ()->name ();

    if (metaname == "SourceToConnector")
    {
      // Store the role name, then visit the connector.
      this->role_name_ = item->attribute ("srcRolename")->string_value ();
      item->dst ()->accept (this);
    }
    else if (metaname == "ConnectorToDestination")
    {
      // Store the role name, then visit the connector.
      this->role_name_ = item->attribute ("dstRolename")->string_value ();
      item->src ()->accept (this);
    }
    else if (metaname == "AssociationClass")
    {
      GAME::Mga::FCO src = item->src ();
      while (src->type () == OBJTYPE_REFERENCE)
        src = GAME::Mga::Reference::_narrow (src)->refers_to ();

      const std::string src_metaname = src->meta ()->name ();

      if (src_metaname == "Connector")
      {
        GAME::Mga::FCO dst = item->dst ();

        while (dst->type () == OBJTYPE_REFERENCE)
          dst = GAME::Mga::Reference::_narrow (dst)->refers_to ();

        Object_Class_Definition * definition =
          OBJECT_MANAGER->get (GAME::Mga::Atom::_narrow (dst));

        FCO_Class_Definition  * fco_definition =
          dynamic_cast <FCO_Class_Definition *> (definition);

        assert (0 != fco_definition);
        this->points_.insert (std::make_pair (this->role_name_, fco_definition));

        this->includes_.insert (fco_definition);
      }
      else
      {
        Object_Class_Definition * definition =
          OBJECT_MANAGER->get (GAME::Mga::Atom::_narrow (src));

        FCO_Class_Definition  * fco_definition =
          dynamic_cast <FCO_Class_Definition *> (definition);

        assert (0 != fco_definition);
        this->points_.insert (std::make_pair (this->role_name_, fco_definition));

        this->includes_.insert (fco_definition);
      }
    }
  }

private:
  std::set < std::pair <std::string, FCO_Class_Definition *> > & points_;
  Unique_Object_Class_Definitions & includes_;

  std::string role_name_;
};

//
// build
//
void FCO_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  Object_Class_Definition::build (fco);

  // Get the FCO's attributes.
  std::vector <GAME::Mga::Connection> has_attributes;
  fco->in_connections ("HasAttribute", has_attributes);

  Attribute_Visitor has_attrs (this->obj_, this->attributes_);
  std::for_each (GAME::Mga::make_impl_iter (has_attributes.begin ()),
                 GAME::Mga::make_impl_iter (has_attributes.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &has_attrs));

  // Gather all our connection points.
  std::vector <GAME::Mga::Connection> src_to_connector;
  fco->in_connections ("SourceToConnector", src_to_connector);

  Connection_Point_Visitor cpv_src (this->src_connpoints_, this->source_includes_);
  std::for_each (GAME::Mga::make_impl_iter (src_to_connector.begin ()),
                 GAME::Mga::make_impl_iter (src_to_connector.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &cpv_src));

  std::vector <GAME::Mga::Connection> dst_to_connector;
  fco->in_connections ("ConnectorToDestination", dst_to_connector);

  Connection_Point_Visitor cpv_dst (this->dst_connpoints_, this->source_includes_);
  std::for_each (GAME::Mga::make_impl_iter (dst_to_connector.begin ()),
                 GAME::Mga::make_impl_iter (dst_to_connector.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &cpv_dst));
}

//
// generate_definition
//
void FCO_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  if (!this->attributes_.empty ())
  {
    // Write the attributes for this model element.
    ctx.hfile_
      << std::endl
      << "/**" << std::endl
      << " * @name Attribute Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    std::for_each (GAME::Mga::make_impl_iter (this->attributes_.begin ()),
                   GAME::Mga::make_impl_iter (this->attributes_.end ()),
                   boost::bind (&FCO_Class_Definition::generate_attribute,
                                this,
                                boost::ref (ctx),
                                _1));

    ctx.hfile_
      << "///@}"
      << std::endl;
  }

  if (!this->src_connpoints_.empty ())
  {
    // Write the source connection points for this element.
    ctx.hfile_
      << std::endl
      << "/**" << std::endl
      << " * @name Source Connection Point Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    std::for_each (this->src_connpoints_.begin (),
                   this->src_connpoints_.end (),
                   boost::bind (&FCO_Class_Definition::generate_connection_point,
                                this,
                                boost::ref (ctx),
                                _1));

    ctx.hfile_
      << "///@}"
      << std::endl;
  }

  if (!this->dst_connpoints_.empty ())
  {
    // Write the destination connection points for this element.
    ctx.hfile_
      << std::endl
      << "/**" << std::endl
      << " * @name Destination Connection Point Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    std::for_each (this->dst_connpoints_.begin (),
                   this->dst_connpoints_.end (),
                   boost::bind (&FCO_Class_Definition::generate_connection_point,
                                this,
                                boost::ref (ctx),
                                _1));

    ctx.hfile_
      << "///@}"
      << std::endl;
  }
}

//
// generate_attribute
//
void FCO_Class_Definition::
generate_attribute (const Generation_Context & ctx, GAME::Mga::Atom_in item)
{
  const std::string attr_type = item->meta ()->name ();

  std::string getter_type;
  std::string setter_type;
  std::string function_name;

  if (attr_type == "BooleanAttribute")
  {
    // Set the setter/getter for the boolean type.
    setter_type = "bool";
    getter_type = "bool";
    function_name = "bool_value";
  }
  else if (attr_type == "EnumAttribute")
  {
    // Set the setter/getter for the enum type.
    setter_type = "const std::string &";
    getter_type = "std::string";
    function_name = "string_value";
  }
  else if (attr_type == "FieldAttribute")
  {
    // Determine the setter/getter values for the field attribute.
    static const std::string attr_DataType ("DataType");
    const std::string datatype = item->attribute (attr_DataType)->string_value ();

    if (datatype == "integer")
    {
      setter_type = "long";
      getter_type = "long";
      function_name = "int_value";
    }
    else if (datatype == "string")
    {
      setter_type = "const std::string &";
      getter_type = "std::string";
      function_name = "string_value";
    }
    else if (datatype == "double")
    {
      setter_type = "double";
      getter_type = "double";
      function_name = "double_value";
    }
  }
  else // Unknown attribute type.
  {
    return;
  }

  // Write the setter and getter methods in the header and source file.
  const std::string attr_name = item->name ();

  ctx.hfile_
    << std::endl
    << "/// Set the value of " << attr_name << std::endl
    << "void " << attr_name << " (" << setter_type << " val);"
    << std::endl
    << "/// Get the value of " << attr_name << std::endl
    << getter_type << " " << attr_name << " (void) const;";

  ctx.ifile_
    << function_header_t (attr_name)
    << ctx.inline_ << " "
    << "void " << this->classname_ << "::" << attr_name << " (" << setter_type << " val)"
    << "{"
    << "static const std::string attr_name (\"" << attr_name << "\");"
    << "this->attribute (attr_name)->" << function_name << " (val);"
    << "}"
    << function_header_t (attr_name)
    << ctx.inline_ << " "
    << getter_type << " " << this->classname_ << "::" << attr_name << " (void) const"
    << "{"
    << "static const std::string attr_name (\"" << attr_name << "\");"
    << "return this->attribute (attr_name)->" << function_name << " ();"
    << "}";
}

//
// generate_connection_point
//
void FCO_Class_Definition::
generate_connection_point (const Generation_Context & ctx,
                           std::pair < std::string, FCO_Class_Definition * > & item)
{
  const std::string role_name = item.first;
  const std::string type_name = item.second->name ();
  const std::string func_name = item.first + "_" + type_name;

  // Write the connection point method.
  ctx.hfile_
    << std::endl
    << "/// Get the " << role_name << " " << type_name << " connection." << std::endl
    << "size_t " << func_name << " (std::vector <" << type_name << "> & items) const;";

  ctx.sfile_
    << function_header_t (func_name)
    << "size_t " << this->classname_ << "::"
    << func_name << " (std::vector <" << type_name << "> & items) const"
    << "{"
    << "return this->in_connections <" << type_name << "> (items);"
    << "}";
}
