// $Id$

#include "StdAfx.h"
#include "Model_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Model_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Proxy_Visitor.h"
#include "Object_Manager.h"

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
  Containment_Visitor (Model_Class_Definition * parent)
    : model_ (parent)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in item)
  {
    if (this->is_false_self_containment (item))
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

    // Determine what containment collection the item belongs to. This
    // will detemrine what methods containment methods we need to generate
    // for the model element.
    Object_Class_Definition * definition = OBJECT_MANAGER->get (item);
    bool stop = this->model_->name () == "ComponentAssembly" && definition->name () == "Requirement";

    if (min_cardinality == 0 && max_cardinality == 1)
      this->model_->insert_optional_definition (definition);
    else if (min_cardinality == 1 && max_cardinality == 1)
      this->model_->insert_optional_definition (definition);
    else
      this->model_->insert_multiple_definition (definition);
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    this->cardinality_ = item->attribute ("Cardinality")->string_value ();

    // Visit the source object.
    this->dst_ = item->dst ();
    item->src ()->accept (this);
  }

private:
  bool is_false_self_containment (GAME::Mga::Atom_in src)
  {
    GAME::Mga::FCO model = this->model_->get_object ();
    return src->is_equal_to (model) && !this->dst_->is_equal_to (model);
  }

  Model_Class_Definition * model_;
  std::string cardinality_;
  GAME::Mga::FCO dst_;
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

  Containment_Visitor cv (this);
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

  std::for_each (this->single_.begin (),
                 this->single_.end (),
                 boost::bind (&Model_Class_Definition::generate_single_definition,
                              this,
                              boost::ref (ctx),
                              _1));

  std::for_each (this->optional_.begin (),
                 this->optional_.end (),
                 boost::bind (&Model_Class_Definition::generate_optional_definition,
                              this,
                              boost::ref (ctx),
                              _1));

  std::for_each (this->multiple_.begin (),
                 this->multiple_.end (),
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
generate_optional_definition (const Generation_Context & ctx, Object_Class_Definition * item)
{
  if (!item->is_abstract ())
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

  if (!item->derived_classes ().empty ())
  {
    // Make sure we generate getter methods for each of the derived classes.
    std::for_each (item->derived_classes ().begin (),
                   item->derived_classes ().end (),
                   boost::bind (&Model_Class_Definition::generate_optional_definition,
                                this,
                                boost::ref (ctx),
                                _1));
  }
}

//
// generate_single_definition
//
void Model_Class_Definition::
generate_single_definition (const Generation_Context & ctx, Object_Class_Definition * item)
{
  if (!item->is_abstract ())
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
      << "GAME::Mga::Iterator <" << name << "> iter = this->children <" << name << "> ();"
      << "return !iter.is_done () ? *iter : 0;"
      << "}";
  }

  if (!item->derived_classes ().empty ())
  {
    // Make sure we generate getter methods for each of the derived classes.
    std::for_each (item->derived_classes ().begin (),
                   item->derived_classes ().end (),
                   boost::bind (&Model_Class_Definition::generate_single_definition,
                                this,
                                boost::ref (ctx),
                                _1));
  }
}

//
// generate_multiple_definition
//
void Model_Class_Definition::
generate_multiple_definition (const Generation_Context & ctx, Object_Class_Definition * item)
{
  if (!item->is_abstract ())
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

  if (!item->derived_classes ().empty ())
  {
    // Make sure we generate getter methods for each of the derived classes.
    std::for_each (item->derived_classes ().begin (),
                   item->derived_classes ().end (),
                   boost::bind (&Model_Class_Definition::generate_multiple_definition,
                                this,
                                boost::ref (ctx),
                                _1));
  }
}

/**
 * @struct insert_include
 *
 * Functor object that is responsible for intelligently adding the items
 * to the include list.
 */
struct insert_include
{
public:
  insert_include (std::set <Object_Class_Definition *> & includes)
    : includes_ (includes)
  {

  }

  void operator () (std::set <Object_Class_Definition *>::value_type item)
  {
    if (item->derived_classes ().empty ())
    {
      // Since this object does not have any derived classes, we need to
      // go ahead and include this object in the include list.
      this->includes_.insert (item);
    }
    else
    {
      // Since the object does have derived classes, we need to include all
      // the objects derived types. We do not need to include the object itself
      // since the subclasses will include this object.
      std::for_each (item->derived_classes ().begin (),
                     item->derived_classes ().end (),
                     insert_include (this->includes_));
    }
  }

private:
  std::set <Object_Class_Definition *> & includes_;
};
