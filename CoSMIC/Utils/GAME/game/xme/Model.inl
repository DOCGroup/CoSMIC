// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GME
{
namespace XME
{
//
// Model
//
GME_INLINE
Model::Model (void)
: FCO (0, Object_Type::OT_MODEL),
  counter_ (0)
{

}

//
// Model
//
GME_INLINE
Model::Model (const Model & model)
: FCO (model),
  counter_ (model.counter_)
{

}

//
// Model
//
Model::Model (xercesc::DOMElement * folder)
: FCO (folder, Object_Type::OT_MODEL),
  counter_ (0)
{
  this->initialize_counter ();
}

//
// ~Model
//
GME_INLINE
Model::~Model (void)
{

}

//
// operator =
//
GME_INLINE
const Model & Model::operator = (const Model & model)
{
  this->obj_ = model.obj_;
  this->counter_ = model.counter_;
  return *this;
}

//
// relid_counter
//
GME_INLINE
size_t Model::relid_counter (void) const
{
  return this->counter_;
}

//
// fcos
//
GME_INLINE
size_t Model::fcos (std::vector <FCO> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// fcos
//
GME_INLINE
size_t Model::
fcos (const std::string & metaname, std::vector <FCO> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

//
// atoms
//
GME_INLINE
size_t Model::atoms (std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// atoms
//
GME_INLINE
size_t Model::
atoms (const std::string & metaname, std::vector <Atom> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}


//
// atoms
//
GME_INLINE
size_t Model::models (std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, coll);
}

//
// atoms
//
GME_INLINE
size_t Model::
models (const std::string & metaname, std::vector <Model> & coll)
{
  return Utils::get_children (this->obj_, metaname, coll);
}

}
}
