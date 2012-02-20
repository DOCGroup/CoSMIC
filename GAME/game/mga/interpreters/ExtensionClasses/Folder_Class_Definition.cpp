// $Id$

#include "StdAfx.h"
#include "Folder_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Folder_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Proxy_Visitor.h"
#include "Connection_Endpoint_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Reference.h"
#include "game/mga/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>

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

  Source_Connection_Endpoint_Visitor fcv (this->obj_, this->children_);
  std::for_each (GAME::Mga::make_impl_iter (containment.begin ()),
                 GAME::Mga::make_impl_iter (containment.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &fcv));
}

//
// generate_definition
//
void Folder_Class_Definition::
generate_definition (const Generation_Context & ctx)
{
  std::for_each (GAME::Mga::make_impl_iter (this->children_.begin ()),
                 GAME::Mga::make_impl_iter (this->children_.end ()),
                 boost::bind (&Folder_Class_Definition::generate_folder_containment,
                              this,
                              boost::ref (ctx),
                              _1));
}

//
// generate_folder_containment
//
void Folder_Class_Definition::
generate_folder_containment (const Generation_Context & ctx, GAME::Mga::Atom_in item)
{
  const std::string name = item->name ();
  const std::string method_name = "get_" + name + "s";
  const std::string accessor = item->meta ()->name () == "Folder" ? "folders" : "children";

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


//
// get_includes
//
void Folder_Class_Definition::get_includes (std::set <GAME::Mga::Atom> & includes)
{
  // Pass control to the base clas.
  Object_Class_Definition::get_includes (includes);

  // Get the includes for this definition.
  typedef std::set <GAME::Mga::Atom> atom_set;

  std::for_each (this->children_.begin (),
                 this->children_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));
}
