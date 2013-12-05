// $Id$

#include "stdafx.h"
#include "Auto_Model.h"
#include "Auto_Model_Impl.h"
#include "Event_Listener.h"

namespace T3
{
//
// Auto_Model
//
Auto_Model::Auto_Model (const Auto_Model & copy)
: impl_ (copy.impl_)
{
  if (0 != this->impl_)
    this->impl_->inc_refcount ();
}

//
// ~Auto_Model
//
Auto_Model::~Auto_Model (void)
{
  if (0 != this->impl_)
    this->impl_->dec_refcount ();
}

//
// operator =
//
const Auto_Model  & Auto_Model::operator = (const Auto_Model & rhs)
{
  if (this == &rhs)
    return *this;

  // Increment their refcount before incrementing ours.
  if (0 != rhs.impl_)
    rhs.impl_->inc_refcount ();

  if (0 != this->impl_)
    this->impl_->dec_refcount ();

  // It is now save to copy things over.
  this->impl_ = rhs.impl_;

  return *this;
}

//
// operator =
//
void Auto_Model::attach (const GAME::Mga::Object_in obj)
{
  if (0 == this->impl_ || this->impl_->model () != obj)
  {
    // We need to create a new wrapper.
    std::auto_ptr <Auto_Model_Impl> auto_clean (new Auto_Model_Impl (obj));

    // Release our current reference.
    if (0 != this->impl_)
      this->impl_->dec_refcount ();

    // Take ownership of the new object.
    this->impl_ = auto_clean.release ();
  }
}

//
// create_element
//
GAME::Mga::Object Auto_Model::
create_element (const std::string & type)
{
  GAME::Mga::Object object =
    T3_RUNTIME_ENGINE->create_element (this->impl_->model (), type);

  this->impl_->handle_new_object (object);

  return object;
}

//
// create_unique_reference
//
bool Auto_Model::
create_unique_reference (const std::string & symbol, const std::string & type)
{
  GAME::Mga::FCO ref_element;

  bool result =
    T3_RUNTIME_ENGINE->create_unique_reference (this->impl_->model (),
                                                symbol,
                                                type,
                                                ref_element);

  if (result)
    this->impl_->handle_new_object (ref_element);

  return result;
}

}
