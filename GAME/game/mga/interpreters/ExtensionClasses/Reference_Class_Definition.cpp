// $Id$

#include "StdAfx.h"
#include "Reference_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Reference_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Connection_Endpoint_Visitor.h"
#include "Functors.h"
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// build
//
void Reference_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  FCO_Class_Definition::build (fco);

  std::vector <GAME::Mga::Connection> refers_to;
  fco->in_connections ("ReferTo", refers_to);

  Destination_Connection_Endpoint_Visitor dst_visitor (this->obj_, this->refers_to_);
  std::for_each (GAME::Mga::make_impl_iter (refers_to.begin ()),
                 GAME::Mga::make_impl_iter (refers_to.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &dst_visitor));
}

//
// get_includes
//
void Reference_Class_Definition::get_includes (std::set <GAME::Mga::Atom> & includes)
{
  // Pass control to the base clas.
  FCO_Class_Definition::get_includes (includes);

  // Get the includes for this definition.
  typedef std::set <GAME::Mga::Atom> atom_set;

  std::for_each (this->refers_to_.begin (),
                 this->refers_to_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));
}

//
// generate_definition
//
void Reference_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  // Pass control to the base class.
  FCO_Class_Definition::generate_definition (ctx);

  std::for_each (GAME::Mga::make_impl_iter (this->refers_to_.begin ()),
                 GAME::Mga::make_impl_iter (this->refers_to_.end ()),
                 boost::bind (&Reference_Class_Definition::generate_refers_to_method,
                              this,
                              boost::ref (ctx),
                              _1));
}

//
// generate_refers_to_method
//
void Reference_Class_Definition::
generate_refers_to_method (const Generation_Context & ctx, GAME::Mga::Atom_in item)
{
  const std::string type_name = item->name ();
  const std::string test_method_name = type_name + "_is_nil";
  const std::string get_method_name = "get_" + type_name;

  ctx.hfile_
    << std::endl
    << "/**" << std::endl
    << " * @name Refers To Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl
    << "bool " << test_method_name << " (void) const;"
    << type_name << " " << get_method_name << " (void) const;"
    << "///@}" << std::endl;

  ctx.sfile_
    << function_header_t (test_method_name)
    << "bool " << this->classname_ << "::" << test_method_name << " (void) const"
    << "{"
    << "return !this->refers_to ().is_nil ();"
    << "}"
    << function_header_t (get_method_name)
    << type_name << " " << this->classname_ << "::" << get_method_name << " (void) const"
    << "{"
    << "return " << type_name << "::_narrow (this->refers_to ());"
    << "}";
}
