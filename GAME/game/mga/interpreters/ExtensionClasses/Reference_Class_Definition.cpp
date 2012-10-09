// $Id$

#include "StdAfx.h"
#include "Reference_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Reference_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Connection_Endpoint_Visitor.h"
#include "Functors.h"
#include "Proxy_Visitor.h"
#include "Object_Manager.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"

#include "boost/bind.hpp"
#include <algorithm>

/**
 * @class RefersTo_Visitor
 */
class RefersTo_Visitor : public Proxy_Visitor
{
public:
  //
  // Containment_Visitor
  //
  RefersTo_Visitor (Reference_Class_Definition * ref)
    : ref_ (ref)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in dst)
  {
    if (this->is_false_self_reference (dst))
      return;

    // Determine what containment collection the item belongs to. This
    // will detemrine what methods containment methods we need to generate
    // for the model element.
    Object_Class_Definition * definition = OBJECT_MANAGER->get (dst);

    this->ref_->insert_refers_to (definition);
    definition->insert_dependency (this->ref_);
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    // Visit the source object.
    this->src_ = item->src ();
    item->dst ()->accept (this);
  }

private:
  bool is_false_self_reference (GAME::Mga::Atom_in dst)
  {
    GAME::Mga::FCO ref = this->ref_->get_object ();
    return dst->is_equal_to (ref) && !this->src_->is_equal_to (ref);
  }

  Reference_Class_Definition * ref_;
  GAME::Mga::FCO src_;
};

//
// build
//
void Reference_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  FCO_Class_Definition::build (fco);

  std::vector <GAME::Mga::Connection> refers_to;
  fco->in_connections ("ReferTo", refers_to);

  RefersTo_Visitor refers_to_visitor (this);
  std::for_each (GAME::Mga::make_impl_iter (refers_to.begin ()),
                 GAME::Mga::make_impl_iter (refers_to.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &refers_to_visitor));
}

//
// generate_definition
//
void Reference_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  // Pass control to the base class.
  FCO_Class_Definition::generate_definition (ctx);

  std::for_each (this->refers_to_.begin (),
                 this->refers_to_.end (),
                 boost::bind (&Reference_Class_Definition::generate_refers_to_method,
                              this,
                              boost::ref (ctx),
                              _1));
}

//
// generate_refers_to_method
//
void Reference_Class_Definition::
generate_refers_to_method (const Generation_Context & ctx, Object_Class_Definition * item)
{
  const std::string type_name = item->name ();
  const std::string test_method_name = type_name + "_is_nil";
  const std::string get_method_name = "get_" + type_name;
  const std::string set_method_name = "set_" + type_name;

  ctx.hfile_
    << std::endl
    << "/**" << std::endl
    << " * @name Refers To Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl
    << "bool " << test_method_name << " (void) const;"
    << type_name << " " << get_method_name << " (void) const;"
    << "void " << set_method_name << " (" << type_name << "_in item);"
    << "///@}" << std::endl;

  ctx.sfile_
    << function_header_t (test_method_name)
    << "bool " << this->classname_ << "::" << test_method_name << " (void) const"
    << "{"
    << "return !this->refers_to ().is_nil ();"
    << "}"
    << function_header_t (set_method_name)
    << "void " << this->classname_ << "::" << set_method_name << " (" << type_name << "_in item)"
    << "{"
    << "this->refers_to (item);"
    << "}"
    << function_header_t (get_method_name)
    << type_name << " " << this->classname_ << "::" << get_method_name << " (void) const"
    << "{"
    << "return " << type_name << "::_narrow (this->refers_to ());"
    << "}";
}
