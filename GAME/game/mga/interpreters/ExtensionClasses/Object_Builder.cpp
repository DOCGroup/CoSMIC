// $Id: generate_cpp_class.py 3679 2012-04-30 02:25:20Z hillj $

#include "stdafx.h"
#include "Object_Builder.h"

#if !defined (__GAME_INLINE__)
#include "Object_Builder.inl"
#endif  // !defined __GAME_INLINE__

#include "Object_Manager.h"

#include "game/mga/Model.h"
#include "game/mga/RootFolder.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// visit_RootFolder
//
void Object_Builder::
visit_RootFolder (GAME::Mga::RootFolder_in folder)
{
  this->visit_Folder_i (folder);
}

//
// visit_Folder
//
void Object_Builder::
visit_Folder (GAME::Mga::Folder_in folder)
{
  this->visit_Folder_i (folder);
}

//
// visit_Atom
//
void Object_Builder::visit_Atom (GAME::Mga::Atom_in atom)
{
  OBJECT_MANAGER->build (atom);
}

//
// visit_Model
//
void Object_Builder::visit_Model (GAME::Mga::Model_in model)
{
  // Visit all the children in this model (or paradigm sheet).
  std::vector <GAME::Mga::FCO> children;
  model->children (children);

  std::for_each (make_impl_iter (children.begin ()),
                 make_impl_iter (children.end ()),
                 boost::bind (&GAME::Mga::FCO::impl_type::accept, _1, this));
}

//
// visit_Folder_i
//
void Object_Builder::visit_Folder_i (GAME::Mga::Folder_in folder)
{
  using namespace GAME::Mga;

  // Visit all the SheetFolder elements in the model.
  Iterator <GAME::Mga::Folder> folders = folder->folders ();
  std::for_each (make_impl_iter (folders),
                 make_impl_iter (folders.make_end ()),
                 boost::bind (&GAME::Mga::Folder::impl_type::accept, _1, this));

  // Visit all the paradigm sheets.
  std::vector <Model> sheets;
  folder->children (sheets);

  std::for_each (make_impl_iter (sheets.begin ()),
                 make_impl_iter (sheets.end ()),
                 boost::bind (&Model::impl_type::accept, _1, this));
}
