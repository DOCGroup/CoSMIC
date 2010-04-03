// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GME
{
namespace XME
{
//
// Folder
//
GME_INLINE
Folder::Folder (void)
: Object (0, Object_Type::OT_FOLDER),
  counter_ (0)
{

}

//
// Folder
//
GME_INLINE
Folder::Folder (const Folder & folder)
: Object (folder),
  counter_ (folder.counter_)
{

}

//
// Folder
//
GME_INLINE
Folder::Folder (xercesc::DOMElement * folder)
: Object (folder, Object_Type::OT_FOLDER)
{
  this->initialize_counter ();
}

//
// ~Folder
//
GME_INLINE
Folder::~Folder (void)
{

}

//
// Folder
//
GME_INLINE
Folder Folder::_narrow (const Object & obj)
{
  if ((obj.type () & Object_Type::OT_FOLDER))
    return Folder (obj.ptr ());

  throw Invalid_Cast ();
}

//
// operator =
//
GME_INLINE
const Folder & Folder::operator = (const Folder & folder)
{
  this->obj_ = folder.obj_;
  this->counter_ = folder.counter_;
  return *this;
}

//
// relid_counter
//
GME_INLINE
size_t Folder::relid_counter (void) const
{
  return this->counter_;
}

//
// folders
//
GME_INLINE
size_t Folder::folders (std::vector <Folder> & folders)
{
  return Utils::get_children (this->obj_, folders);
}

//
// folders
//
GME_INLINE
size_t Folder::
folders (const std::string & metaname, std::vector <Folder> & folders)
{
  return Utils::get_children (this->obj_, metaname, folders);
}

//
// fcos
//
GME_INLINE
size_t Folder::fcos (std::vector <FCO> & folders)
{
  return Utils::get_children (this->obj_, folders);
}

//
// fcos
//
GME_INLINE
size_t Folder::
fcos (const std::string & metaname, std::vector <FCO> & folders)
{
  return Utils::get_children (this->obj_, metaname, folders);
}

//
// atoms
//
GME_INLINE
size_t Folder::atoms (std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// atoms
//
GME_INLINE
size_t Folder::
atoms (const std::string & metaname, std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// models
//
GME_INLINE
size_t Folder::models (std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// models
//
GME_INLINE
size_t Folder::
models (const std::string & metaname, std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

}
}
