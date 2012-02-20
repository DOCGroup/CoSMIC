// $Id$

#include "StdAfx.h"
#include "Connection_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Connection_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Proxy_Visitor.h"

#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// build
//
void Connection_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  FCO_Class_Definition::build (fco);

  std::vector <GAME::Mga::Connection> association_class;

  if (fco->in_connections ("AssociationClass", association_class))
  {
    // Get the Connector element from the association class. It can be
    // either the source or the destination of the connection.
    GAME::Mga::Connection ac = association_class.front ();
    GAME::Mga::FCO connector;

    if (ac->src ()->is_equal_to (fco))
      connector = ac->dst ();
    else
      connector = ac->src ();

    // Get the source model element for the connection.
    std::vector <GAME::Mga::Connection> src_to_connector;
    if (0 == connector->in_connections ("SourceToConnector", src_to_connector))
      return;

    GAME::Mga::FCO src = src_to_connector.front ()->src ();

    while (src->type () == OBJTYPE_REFERENCE)
      src = GAME::Mga::Reference::_narrow (src)->refers_to ();

    this->src_ = ::GAME::Mga::Atom::_narrow (src);

    // Get the destination model element for the connection.
    std::vector <GAME::Mga::Connection> connector_to_dst;
    if (0 == connector->in_connections ("ConnectorToDestination", connector_to_dst))
      return;

    GAME::Mga::FCO dst = connector_to_dst.front ()->dst ();
    while (dst->type () == OBJTYPE_REFERENCE)
      dst = GAME::Mga::Reference::_narrow (dst)->refers_to ();

    this->dst_ = GAME::Mga::Atom::_narrow (dst);
  }
}

//
// generate_definition
//
void Connection_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  // Pass control to the base class.
  FCO_Class_Definition::generate_definition (ctx);

  // Generate our methods related to the connection points.
  const std::string src_type_name = this->src_->name ();
  const std::string dst_type_name = this->dst_->name ();

  const std::string src_method = "src_" + src_type_name;
  const std::string dst_method = "dst_" + dst_type_name;

  ctx.hfile_
    << std::endl
    << src_type_name << " " << src_method << " (void) const;"
    << dst_type_name << " " << dst_method << " (void) const;";

  ctx.sfile_
    << function_header_t (src_type_name)
    << src_type_name << " " << this->classname_ << "::" << src_method << " (void) const"
    << "{"
    << "return " << src_type_name << "::_narrow (this->src ());"
    << "}"
    << function_header_t (dst_type_name)
    << dst_type_name << " " << this->classname_ << "::" << dst_method << " (void) const"
    << "{"
    << "return " << dst_type_name << "::_narrow (this->dst ());"
    << "}";
}

//
// get_includes
//
void Connection_Class_Definition::
get_includes (std::set <GAME::Mga::Atom> & includes)
{
  FCO_Class_Definition::get_includes (includes);

  includes.insert (this->src_);
  includes.insert (this->dst_);
}
