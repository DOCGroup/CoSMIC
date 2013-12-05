// $Id$

#include "stdafx.h"
#include "Auto_Model_Impl.h"
#include "Runtime_Engine.h"
#include "Event_Listener.h"
#include "boost/bind.hpp"
#include <algorithm>

namespace T3
{
//
// dec_refcount
//
void Auto_Model_Impl::dec_refcount (void)
{
  // Make sure we do not cause the reference count to wrap
  // around. Otherwise, we will mismanage this object.
  if (this->ref_count_ == 0)
    return;

  // Decrement the reference count, then delete this object
  // if our reference count has reached 0.
  if (-- this->ref_count_ == 0)
    delete this;
}

//
// store
//
void Auto_Model_Impl::store (const GAME::Mga::Object_in model)
{
  // Check the type of the element. We do not need to store the
  // children if the element cannot have any children. ;-)
  int type = model->meta ()->type ();

  if (0 != model && (type == OBJTYPE_FOLDER || type == OBJTYPE_MODEL))
    model->children (this->existing_);

  // Store the model.
  this->model_ = model;

  // Notify the listener that we are entering a new model.
  T3_Event_Listener * listener = T3_RUNTIME_ENGINE->event_listener ();

  if (listener != 0)
    listener->handle_open_model (this->model_);
}

//
// cleanup
//
void Auto_Model_Impl::cleanup (void)
{
  if (this->model_.is_nil ())
    return;

  try
  {
    T3_Event_Listener * listener = T3_RUNTIME_ENGINE->event_listener ();

    if (listener)
    {
      typedef std::vector <GAME::Mga::Object>::iterator iterator;

      for (iterator iter = this->existing_.begin (),
           iter_end = this->existing_.end (); iter != iter_end; ++ iter)
      {
        // Notify the listener.
        listener->handle_delete_object (*iter);

        // Destroy the element.
        (*iter)->destroy ();
      }

      // Notify the handler the object is closing.
      listener->handle_close_model (this->model_);
    }
    else
    {
      // Destroy all the elements.
      std::for_each (this->existing_.begin (),
                     this->existing_.end (),
                     boost::bind (&GAME::Mga::Object_Impl::destroy,
                                  boost::bind (&GAME::Mga::Object::get, _1)));
    }
  }
  catch (...)
  {

  }
}

//
// handle_new_object
//
void Auto_Model_Impl::handle_new_object (const GAME::Mga::Object_in obj)
{
  std::vector <GAME::Mga::Object>::iterator iter =
    std::find (this->existing_.begin (),
               this->existing_.end (),
               obj);

  if (iter != this->existing_.end ())
    this->existing_.erase (iter);
}

}
