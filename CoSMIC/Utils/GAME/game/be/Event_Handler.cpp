// $Id$

#include "stdafx.h"
#include "Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#include "ace/ACE.h"
#include "ace/Auto_Ptr.h"
#include <bitset>

namespace GAME
{

#define OBJECT_EVENT_COUNT 32

// Type definition for the handler method of an object event.
typedef int (Event_Handler_Impl::*HANDLER_METHOD) (Object);

struct handler_entry_t
{
  unsigned long bitmask_;

  HANDLER_METHOD method_;
};

// Handle map for object events
static const handler_entry_t objectevent_handles[OBJECT_EVENT_COUNT] = {
  {0x1, &Event_Handler_Impl::handle_object_attribute},        /* OBJEVENT_ATTR          */
  {0x2, &Event_Handler_Impl::handle_object_registry},         /* OBJEVENT_REGISTRY      */
  {0x3, &Event_Handler_Impl::handle_new_child},               /* OBJEVENT_NEWCHILD      */
  {0x4, &Event_Handler_Impl::handle_object_relation},         /* OBJEVENT_RELATION      */
  {0x10, &Event_Handler_Impl::handle_object_properties},      /* OBJEVENT_PROPERTIES    */
  {0x20, &Event_Handler_Impl::handle_instance_subtype},       /* OBJEVENT_SUBT_INST     */
  {0x40, 0},                                                  /* (unused)               */
  {0x80, 0},                                                  /* (unused)               */
  {0x100, &Event_Handler_Impl::handle_object_parent},         /* OBJEVENT_PARENT        */
  {0x200, &Event_Handler_Impl::handle_lost_child},            /* OBJEVENT_LOSTCHILD     */
  {0x400, &Event_Handler_Impl::handle_referenced},            /* OBJEVENT_REFERENCED    */
  {0x800, &Event_Handler_Impl::handle_object_connected},      /* OBJEVENT_CONNECTED     */
  {0x1000, &Event_Handler_Impl::handle_set_included},         /* OBJEVENT_SETINCLUDED   */
  {0x2000, &Event_Handler_Impl::handle_referenced_release},   /* OBJEVENT_REFRELEASED   */
  {0x4000, &Event_Handler_Impl::handle_object_disconnected},  /* OBJEVENT_DISCONNECTED  */
  {0x8000, &Event_Handler_Impl::handle_set_excluded},         /* OBJEVENT_SETEXCLUDED   */
  {0x10000, &Event_Handler_Impl::handle_marked_readonly},     /* OBJEVENT_MARKEDRO      */
  {0x20000, &Event_Handler_Impl::handle_marked_readwrite},    /* OBJEVENT_MARKEDRW      */
  {0x40000, 0},                                               /* (unused)               */
  {0x80000, &Event_Handler_Impl::handle_model_open},          /* OBJEVENT_OPENMODEL     */
  {0x100000, &Event_Handler_Impl::handle_object_select},      /* OBJEVENT_SELECT        */
  {0x200000, &Event_Handler_Impl::handle_object_deselect},    /* OBJEVENT_DESELECT      */
  {0x400000, &Event_Handler_Impl::handle_object_mouseover},   /* OBJEVENT_MOUSEOVER     */
  {0x800000, &Event_Handler_Impl::handle_model_close},        /* OBJEVENT_CLOSEMODEL    */
  {0x1000000, 0},                                             /* (unused)               */
  {0x2000000, 0},                                             /* (unused)               */
  {0x4000000, 0},                                             /* (unused)               */
  {0x8000000, 0},                                             /* (unused)               */
  {0x10000000, 0},                                            /* (unused)               */
  {0x20000000, 0},                                            /* (unused)               */
  {0x40000000, &Event_Handler_Impl::handle_object_destroyed}, /* OBJEVENT_DESTROYED     */
  {0x80000000, &Event_Handler_Impl::handle_object_created}    /* OBJEVENT_CREATED       */
};

//
// attach
//
void Event_Handler::attach (Event_Handler_Impl * impl)
{
  if (this->impl_ == impl)
    return;

  // Unset event handler for current implementation
  if (0 != this->impl_)
    this->impl_->set_event_handler (0);

  // Save the implementation.
  this->impl_ = impl;

  // Set event handler for current implementation
  if (0 != this->impl_)
    this->impl_->set_event_handler (this);
}

//
// initialize
//
int Event_Handler::initialize (GAME::Project & project)
{
  if (0 != this->impl_)
    return this->impl_->initialize (project);

  return 0;
}

//
// GlobalEvent
//
STDMETHODIMP Event_Handler::GlobalEvent (globalevent_enum ev)
{
  try
  {
    if (0 != this->impl_ && this->enable_)
      return this->impl_->handle_global_event (ev);

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// ObjectEvent
//
STDMETHODIMP Event_Handler::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  try
  {
    GAME::Object object (obj);

    // First, pass control to the main implementation.
    if (0 != this->impl_ && this->enable_)
    {
      if (this->impl_->handle_object_event (object, eventmask) != 0)
        return -1;
    }

    // Notify the instance handlers of the event
    handler_set * handlers = 0;
    if (0 == this->type_handlers_.find (object.meta ().name (), handlers) &&
        0 != this->dispatch_object_event (object, eventmask, *handlers))
    {
      return -1;
    }

    // Notify the type handlers of the event.

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// register_event_handler
//
int Event_Handler::
register_handler (const std::string & metaname, Event_Handler_Impl * eh)
{
  // Locate the event handler set for this type.
  handler_set * handlers = 0;

  if (0 == this->type_handlers_.find (metaname, handlers))
    return handlers->insert (eh);

  // Create a new event handler set.
  ACE_NEW_RETURN (handlers, handler_set (), -1);
  ACE_Auto_Ptr <handler_set> auto_clean (handlers);

  if (0 != this->type_handlers_.bind (metaname, handlers))
    return -1;

  // Release the auto clean pointer since the hash map now owns
  // the handler. Also, insert the event handler into the set.
  auto_clean.release ();
  return handlers->insert (eh);
}

//
// close
//
void Event_Handler::close (void)
{
  // Delete all event handlers sets for the types.
  ACE_Hash_Map_Manager <std::string,
                        handler_set *,
                        ACE_Null_Mutex>::ITERATOR iter (this->type_handlers_);

  // Delete all the
  for (; !iter.done (); ++ iter)
    delete iter->item ();
}

//
// dispatch_object_event
//
int Event_Handler::
dispatch_object_event (GAME::Object obj,
                       unsigned long mask,
                       const handler_set & handlers)
{
  int retval = 0;

  // Pass the event to each event hanlder.
  handler_set::CONST_ITERATOR iter (handlers);

  for (; !iter.done (); ++ iter)
    retval += this->dispatch_object_event (obj, mask, *iter);

  return retval;
}

//
// dispatch_object_event
//
int Event_Handler::
dispatch_object_event (Object obj,
                       unsigned long eventmask,
                       Event_Handler_Impl * const eh)
{
  // Get the event mask for the event handler.
  std::bitset <OBJECT_EVENT_COUNT> current_mask (eventmask);
  unsigned long eh_eventmask = static_cast <unsigned long> (eh->event_mask ());

  int retval = 0;
  const handler_entry_t * handler_iter = objectevent_handles;

  for (size_t count = current_mask.count (); count > 0; -- count)
  {
    // Locate the first set bit in the current mask. We must increment
    // the handler iterator for each bit we skip.
    while (!current_mask.test (0))
    {
      current_mask >>= 1;
      ++ handler_iter;
    }

    // Ok, we found the next set bit location. We need to check if the
    // event handler is registered for this event.
    if ((handler_iter->bitmask_ & eh_eventmask) != 0)
      retval += (eh->*handler_iter->method_) (obj) == 0 ? 0 : 1;

    // Move to the next location.
    ++ handler_iter;
  }

  return retval;
}

}
