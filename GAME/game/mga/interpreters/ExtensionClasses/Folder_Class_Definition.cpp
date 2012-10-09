// $Id$

#include "StdAfx.h"
#include "Folder_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Folder_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Object_Manager.h"
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>

/**
 * @class Containment_Visitor
 */
class Folder_Containment_Visitor : public Proxy_Visitor
{
public:
  //
  // Containment_Visitor
  //
  Folder_Containment_Visitor (Folder_Class_Definition * parent)
    : parent_ (parent)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in src)
  {
    if (this->is_false_self_containment (src))
      return;

    // Determine what containment collection the item belongs to. This
    // will detemrine what methods containment methods we need to generate
    // for the model element.
    Object_Class_Definition * definition = OBJECT_MANAGER->get (src);

    this->parent_->insert_child (definition);
    definition->insert_parent (this->parent_);
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    this->dst_ = item->dst ();
    item->src ()->accept (this);
  }

private:
  bool is_false_self_containment (GAME::Mga::Atom_in src)
  {
    return
      src->is_equal_to (this->parent_->get_object ()) &&
      !this->dst_->is_equal_to (this->parent_->get_object ());
  }

  Folder_Class_Definition * parent_;
  std::string cardinality_;
  GAME::Mga::FCO dst_;
};
//
// build
//
void Folder_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // Pass control to the base class.
  Object_Class_Definition::build (fco);

  // Gather all the contained elements.
  std::vector <GAME::Mga::Connection> containment;
  fco->in_connections ("FolderContainment", containment);

  Folder_Containment_Visitor cv (this);
  std::for_each (GAME::Mga::make_impl_iter (containment.begin ()),
                 GAME::Mga::make_impl_iter (containment.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &cv));
}

//
// generate_definition
//
void Folder_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  std::for_each (this->children_.begin (),
                 this->children_.end (),
                 boost::bind (&Folder_Class_Definition::generate_folder_containment,
                              this,
                              boost::ref (ctx),
                              _1));
}

//
// generate_folder_containment
//
void Folder_Class_Definition::
generate_folder_containment (const Generation_Context & ctx, Object_Class_Definition * item)
{
  const std::string name = item->name ();
  const std::string method_name = "get_" + name + "s";
  const std::string accessor = item->metaname () == "Folder" ? "folders" : "children";

  // Declare the function.
  ctx.hfile_
    << std::endl
    << "size_t " << method_name << " (std::vector <" << name << "> & items) const;";

  // Implement the function.
  ctx.sfile_
    << function_header_t (method_name)
    << "size_t " << this->classname_ << "::"
    << method_name << " (std::vector <" << name << "> & items) const"
    << "{"
    << "return this->" << accessor << " (items);"
    << "}";
}
