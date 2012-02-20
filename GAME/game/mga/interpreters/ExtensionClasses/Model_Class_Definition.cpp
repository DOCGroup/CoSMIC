// $Id$

#include "StdAfx.h"
#include "Model_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Model_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>
#include <sstream>

/**
 * @class Containment_Visitor
 */
class Containment_Visitor : public Proxy_Visitor
{
public:
  //
  // Containment_Visitor
  //
  Containment_Visitor (GAME::Mga::FCO_in parent,
                       std::set <GAME::Mga::Atom> & optional,
                       std::set <GAME::Mga::Atom> & single,
                       std::set <GAME::Mga::Atom> & multiple)
    : parent_ (parent),
      optional_ (optional),
      single_ (single),
      multiple_ (multiple)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in item)
  {
    if (this->parent_->is_equal_to (item))
      return;

    // Extract the concrete values for the cardinality.
    std::istringstream istr (this->cardinality_);
    int min_cardinality = 0, max_cardinality = -1;

    istr >> min_cardinality;

    if (!istr.eof ())
    {
      istr.ignore (2);
      istr >> max_cardinality;
    }
    else
    {
      max_cardinality = min_cardinality;
    }

    const std::string path = item->path ("/");
    const std::string metaname = item->meta ()->name ();

    const std::string parent_path = this->parent_->path ("/");
    const std::string parent_metaname = this->parent_->meta ()->name ();

    // Determine what containment collection the item belongs to. This
    // will detemrine what methods containment methods we need to generate
    // for the model element.
    if (min_cardinality == 0 && max_cardinality == 1)
      this->optional_.insert (item);
    else if (min_cardinality == 1 && max_cardinality == 1)
      this->single_.insert (item);
    else
      this->multiple_.insert (item);
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    this->cardinality_ = item->attribute ("Cardinality")->string_value ();
    item->src ()->accept (this);
  }

private:
  GAME::Mga::FCO_in parent_;

  std::set <GAME::Mga::Atom> & optional_;

  std::set <GAME::Mga::Atom> & single_;

  std::set <GAME::Mga::Atom> & multiple_;

  std::string cardinality_;
};

//
// build
//
void Model_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  FCO_Class_Definition::build (fco);

  // Gather all the contained elements.
  std::vector <GAME::Mga::Connection> containment;
  fco->in_connections ("Containment", containment);

  Containment_Visitor cv (this->obj_, this->optional_, this->single_, this->multiple_);
  std::for_each (GAME::Mga::make_impl_iter (containment.begin ()),
                 GAME::Mga::make_impl_iter (containment.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &cv));
}

//
// generate_definition
//
void Model_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  // Pass control to the base class.
  FCO_Class_Definition::generate_definition (ctx);

  if (this->single_.empty () && this->multiple_.empty () && this->optional_.empty ())
    return;

  ctx.hfile_
    << std::endl
    << "/**" << std::endl
    << " * @name Containment Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl;

  std::for_each (GAME::Mga::make_impl_iter (this->single_.begin ()),
                 GAME::Mga::make_impl_iter (this->single_.end ()),
                 boost::bind (&Model_Class_Definition::generate_single_definition,
                              this,
                              boost::ref (ctx),
                              _1));

  std::for_each (GAME::Mga::make_impl_iter (this->optional_.begin ()),
                 GAME::Mga::make_impl_iter (this->optional_.end ()),
                 boost::bind (&Model_Class_Definition::generate_optional_definition,
                              this,
                              boost::ref (ctx),
                              _1));

  std::for_each (GAME::Mga::make_impl_iter (this->multiple_.begin ()),
                 GAME::Mga::make_impl_iter (this->multiple_.end ()),
                 boost::bind (&Model_Class_Definition::generate_multiple_definition,
                              this,
                              boost::ref (ctx),
                              _1));


  ctx.hfile_
    << "///@}"
    << std::endl;
}

//
// generate_optional_definition
//
void Model_Class_Definition::
generate_optional_definition (const Generation_Context & ctx,
                              GAME::Mga::Atom_in item)
{
  // Write the method for testing if the model has this element. Since
  // it is an optional element, then there is chance this does not appear
  // in the model. This is OK per the metamodel definition.
  const std::string name = item->name ();
  const std::string has_method_name = "has_" + name;
  const std::string get_method_name = "get_" + name;

  ctx.hfile_
    << std::endl
    << "bool " << has_method_name << " (void) const;"
    << name << " " << get_method_name << " (void) const;";

  ctx.sfile_
    << function_header_t (has_method_name)
    << "bool " << this->classname_ << "::" << has_method_name << " (void) const"
    << "{"
    << "return this->children <" << name << "> ().count () == 1;"
    << "}"
    << function_header_t (get_method_name)
    << name << " " << this->classname_ << "::" << get_method_name << " (void) const"
    << "{"
    << "return this->children <" << name << "> ().item ();"
    << "}";
}

//
// generate_single_definition
//
void Model_Class_Definition::
generate_single_definition (const Generation_Context & ctx,
                            GAME::Mga::Atom_in item)
{
  const std::string name = item->name ();
  const std::string get_method_name = "get_" + name;

  // Declare the function.
  ctx.hfile_
    << name << " " << get_method_name << " (void) const;"
    << std::endl;

  // Implement the function.
  ctx.sfile_
    << function_header_t (get_method_name)
    << name << " " << this->classname_ << "::" << get_method_name << " (void) const"
    << "{"
    << "this->children <" << name << "> ().item ();"
    << "}";
}

//
// generate_multiple_definition
//
void Model_Class_Definition::
generate_multiple_definition (const Generation_Context & ctx,
                              GAME::Mga::Atom_in item)
{
  const std::string name = item->name ();
  const std::string get_method_name = "get_" + name + "s";

  // Declare the function.
  ctx.hfile_
    << "size_t " << get_method_name << " (std::vector <" << name << "> & items) const;"
    << "::GAME::Mga::Iterator <" << name << "> " << get_method_name << " (void) const;"
    << std::endl;

  // Implement the function.
  ctx.sfile_
    << function_header_t (get_method_name)
    << "size_t " << this->classname_ << "::"
    << get_method_name << " (std::vector <" << name << "> & items) const"
    << "{"
    << "return this->children (items);"
    << "}"
    << function_header_t (get_method_name)
    << "::GAME::Mga::Iterator <" << name << "> " << this->classname_ << "::"
    << get_method_name << " (void) const"
    << "{"
    << "return this->children <" << name << "> ();"
    << "}";
}

//
// get_includes
//
void Model_Class_Definition::get_includes (std::set <GAME::Mga::Atom> & includes)
{
  // Pass control to the base clas.
  FCO_Class_Definition::get_includes (includes);

  // Get the includes for this definition.
  typedef std::set <GAME::Mga::Atom> atom_set;

  std::for_each (this->optional_.begin (),
                 this->optional_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));

  std::for_each (this->single_.begin (),
                 this->single_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));

  std::for_each (this->multiple_.begin (),
                 this->multiple_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));
}
