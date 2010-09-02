// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GAME
{
namespace XME
{
//
// Folder
//
GAME_INLINE
Folder::Folder (void)
: Object (0, Object_Type::OT_FOLDER),
  counter_ (0)
{

}

//
// Folder
//
GAME_INLINE
Folder::Folder (const Folder & folder)
: Object (folder),
  counter_ (folder.counter_)
{

}

//
// Folder
//
GAME_INLINE
Folder::Folder (xercesc::DOMElement * folder)
: Object (folder, Object_Type::OT_FOLDER)
{
  this->initialize_counter ();
}

//
// ~Folder
//
GAME_INLINE
Folder::~Folder (void)
{

}

//
// Folder
//
GAME_INLINE
Folder Folder::_narrow (const Object & obj)
{
  if ((obj.type () & Object_Type::OT_FOLDER))
    return Folder (obj.ptr ());

  throw Invalid_Cast ();
}

//
// operator =
//
GAME_INLINE
const Folder & Folder::operator = (const Folder & folder)
{
  this->obj_ = folder.obj_;
  this->counter_ = folder.counter_;
  return *this;
}

//
// relid_counter
//
GAME_INLINE
size_t Folder::relid_counter (void) const
{
  return this->counter_;
}

//
// folders
//
GAME_INLINE
size_t Folder::children (std::vector <Folder> & folders)
{
  return Utils::get_children (this->obj_, folders);
}

//
// folders
//
GAME_INLINE
size_t Folder::
children (const GAME::Xml::String & metaname, std::vector <Folder> & folders)
{
  return Utils::get_children (this->obj_, metaname, folders);
}

//
// fcos
//
GAME_INLINE
size_t Folder::children (std::vector <FCO> & folders)
{
  return Utils::get_children (this->obj_, folders);
}

//
// fcos
//
GAME_INLINE
size_t Folder::
children (const GAME::Xml::String & metaname, std::vector <FCO> & folders)
{
  return Utils::get_children (this->obj_, metaname, folders);
}

//
// atoms
//
GAME_INLINE
size_t Folder::children (std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// atoms
//
GAME_INLINE
size_t Folder::
children (const GAME::Xml::String & metaname, std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// models
//
GAME_INLINE
size_t Folder::children (std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// models
//
GAME_INLINE
size_t Folder::
children (const GAME::Xml::String & metaname, std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

}
}
