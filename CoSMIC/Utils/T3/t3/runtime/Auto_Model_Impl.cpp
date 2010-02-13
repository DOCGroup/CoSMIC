#ifndef _AUTO_MODEL_T_CPP_
#define _AUTO_MODEL_T_CPP_

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
  if (this->ref_count_ == 0)
    return;

  if (-- this->ref_count_ == 0)
    delete this;
}

//
// store
//
void Auto_Model_Impl::store (const ::GME::Object & model)
{
  if (!model.is_nil ())
    model.children (this->existing_);

  this->model_ = model;

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
      for (GME::Collection_T <GME::Object>::iterator iter = this->existing_.begin (),
           iter_end = this->existing_.end (); iter != iter_end; ++ iter)
      {
        // Notify the listener.
        listener->handle_delete_object (*iter);

        // Destroy the element.
        iter->destroy ();
      }

      // Notify the handler the object is closing.
      listener->handle_close_model (this->model_);
    }
    else
    {
      // Destroy all the elements.
      std::for_each (this->existing_.begin (),
                     this->existing_.end (),
                     boost::bind (&GME::Object::destroy, _1));
    }
  }
  catch (...)
  {

  }
}

//
// handle_new_object
//
void Auto_Model_Impl::handle_new_object (const GME::Object & obj)
{
  GME::Collection_T <GME::Object>::iterator iter =
    std::find (this->existing_.begin (),
               this->existing_.end (),
               obj);

  if (iter != this->existing_.end ())
    this->existing_.items ().erase (iter);
}

}

#endif
