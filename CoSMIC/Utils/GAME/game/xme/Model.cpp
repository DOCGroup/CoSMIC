// $Id$

#include "Model.h"

#if !defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#include "Folder.h"
#include "GME_ID_Generator.h"
#include <sstream>

namespace GAME
{
namespace XME
{
const ::Utils::XStr Model::TAGNAME ("model");
const ::Utils::XStr Model::ATTR_CHILDRELIDCNTR ("childrelidcntr");
const ::Utils::XStr Model::NO_CHILDREN ("0x0");

//
// _create_impl
//
template <typename T>
Model Model::create_impl (T & parent, const ::Utils::XStr & kind)
{
  // Generate the relative id for the new folder.
  size_t counter = parent.relid_counter ();
  parent.relid_counter (counter + 1);

  // Generate a unique id for the new folder.
  return Model (parent.ptr (), kind, counter);
}

//
// Model
//
Model::
Model (xercesc::DOMElement * model, bool validate)
: FCO (model, false),
  counter_ (0)
{
  if (validate && !(this->type_ & Object_Type::OT_MODEL))
    throw Invalid_Cast ();

  this->initialize_counter ();
}

//
// Model
//
GAME_INLINE
Model::
Model (xercesc::DOMElement * parent,
       const ::Utils::XStr & kind,
       size_t relid)
: FCO (parent,
       TAGNAME,
       GME_XME_ID_GENERATOR (Model)->generate_id (),
       kind,
       kind,
       relid),
  counter_ (0)
{
  this->obj_->setAttribute (ATTR_CHILDRELIDCNTR, NO_CHILDREN);
}

//
// _create
//
Model Model::_create (Model & parent, const ::Utils::XStr & kind)
{
  return Model::create_impl (parent, kind);
}

//
// _create
//
Model Model::_create (Folder & parent, const ::Utils::XStr & kind)
{
  return Model::create_impl (parent, kind);
}

//
// attach
//
void Model::attach (xercesc::DOMElement * obj, bool validate)
{
  // Pass control to the base class.
  FCO::attach (obj, false);

  if (validate && !(this->type_ & Object_Type::OT_MODEL))
    throw Invalid_Cast ();

  // Initialize the counter.
  this->initialize_counter ();
}

//
// relid_counter
//
void Model::relid_counter (size_t value)
{
  if (value <= this->counter_)
    return;

  // Write the counter to hexadecimal format.
  std::ostringstream xstr;
  xstr << "0x" << std::hex << value;
  this->obj_->setAttribute (ATTR_CHILDRELIDCNTR, ::Utils::XStr (xstr.str ()));

  // Save the counter's value.
  this->counter_ = value;
}

//
// initialize_counter
//
void Model::initialize_counter (void)
{
  // Get the child relative id counter value.
  const XMLCh * ch = this->obj_->getAttribute (ATTR_CHILDRELIDCNTR);
  const ::Utils::XStr value (ch, false);

  std::istringstream istr (value.to_string ());
  istr >> std::hex >> this->counter_;
}

}
}
