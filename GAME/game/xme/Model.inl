// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GAME
{
namespace XME
{
//
// Model
//
GAME_INLINE
Model::Model (void)
: FCO (0, Object_Type::OT_MODEL),
  counter_ (0)
{

}

//
// Model
//
GAME_INLINE
Model::Model (const Model & model)
: FCO (model),
  counter_ (model.counter_)
{

}

//
// Model
//
Model::Model (xercesc::DOMElement * model)
: FCO (model, Object_Type::OT_MODEL),
  counter_ (0)
{
  this->initialize_counter ();
}

//
// ~Model
//
GAME_INLINE
Model::~Model (void)
{

}

//
// operator =
//
GAME_INLINE
const Model & Model::operator = (const Model & model)
{
  this->obj_ = model.obj_;
  this->counter_ = model.counter_;
  return *this;
}

//
// relid_counter
//
GAME_INLINE
size_t Model::relid_counter (void) const
{
  return this->counter_;
}

//
// children
//
GAME_INLINE
size_t Model::children (std::vector <FCO> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// children
//
GAME_INLINE
size_t Model::
children (const GAME::Xml::String & metaname, std::vector <FCO> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// children
//
GAME_INLINE
size_t Model::children (std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// children
//
GAME_INLINE
size_t Model::
children (const GAME::Xml::String & metaname, std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}


//
// children
//
GAME_INLINE
size_t Model::children (std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// children
//
GAME_INLINE
size_t Model::
children (const GAME::Xml::String & metaname, std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// children
//
GAME_INLINE
size_t Model::children (std::vector <Reference> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// children
//
GAME_INLINE
size_t Model::
children (const GAME::Xml::String & metaname, std::vector <Reference> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// children
//
GAME_INLINE
size_t Model::children (std::vector <Connection> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// children
//
GAME_INLINE
size_t Model::
children (const GAME::Xml::String & metaname, std::vector <Connection> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// _narrow
//
GAME_INLINE
Model Model::_narrow (const Object & obj)
{
  if ((Object_Type::OT_MODEL & obj.type ()))
    return Model (obj.ptr ());

  throw Invalid_Cast ();
}

}
}
