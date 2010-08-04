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

// Type definition for handling a global event.
typedef int (Event_Handler_Impl::*GLOBAL_EVENT_METHOD) (void);

struct handler_entry_t
{
  unsigned long bitmask_;

  HANDLER_METHOD method_;
};

static const GLOBAL_EVENT_METHOD __globalevent_map__[] = {
  &Event_Handler_Impl::handle_project_open,
  &Event_Handler_Impl::handle_project_close,
  &Event_Handler_Impl::handle_territory_create,
  &Event_Handler_Impl::handle_territory_destroy,
  &Event_Handler_Impl::handle_transaction_commit,
  &Event_Handler_Impl::handle_transaction_abort,
  &Event_Handler_Impl::handle_undo,
  &Event_Handler_Impl::handle_redo,
  &Event_Handler_Impl::handle_project_properties,
  &Event_Handler_Impl::handle_notification_ready
};

static const GLOBAL_EVENT_METHOD __appevent_map__[] = {
  &Event_Handler_Impl::handle_xml_import_begin,
  &Event_Handler_Impl::handle_xml_import_end,
  &Event_Handler_Impl::handle_xml_import_fcos_begin,
  &Event_Handler_Impl::handle_xml_import_end,
  &Event_Handler_Impl::handle_xml_import_special_begin,
  &Event_Handler_Impl::handle_xml_import_special_end,
  &Event_Handler_Impl::handle_library_attach_begin,
  &Event_Handler_Impl::handle_library_attach_end
};

// Handle map for object events
static const handler_entry_t objectevent_handles[OBJECT_EVENT_COUNT] = {
  {0x1, &Event_Handler_Impl::handle_object_attribute},        /* OBJEVENT_ATTR          */
  {0x2, &Event_Handler_Impl::handle_object_registry},         /* OBJEVENT_REGISTRY      */
  {0x4, &Event_Handler_Impl::handle_new_child},               /* OBJEVENT_NEWCHILD      */
  {0x8, &Event_Handler_Impl::handle_object_relation},         /* OBJEVENT_RELATION      */
  {0x10, &Event_Handler_Impl::handle_object_properties},      /* OBJEVENT_PROPERTIES    */
  {0x20, &Event_Handler_Impl::handle_instance_subtype},       /* OBJEVENT_SUBT_INST     */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
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
  {0, 0},                                                     /* (unused)               */
  {0x80000, &Event_Handler_Impl::handle_model_open},          /* OBJEVENT_OPENMODEL     */
  {0x100000, &Event_Handler_Impl::handle_object_select},      /* OBJEVENT_SELECT        */
  {0x200000, &Event_Handler_Impl::handle_object_deselect},    /* OBJEVENT_DESELECT      */
  {0x400000, &Event_Handler_Impl::handle_object_mouseover},   /* OBJEVENT_MOUSEOVER     */
  {0x800000, &Event_Handler_Impl::handle_model_close},        /* OBJEVENT_CLOSEMODEL    */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
  {0, 0},                                                     /* (unused)               */
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
  // There is no need to continue if we are not enabled.
  if (!this->enable_)
    return S_OK;

  try
  {
    if (0 != this->impl_)
    {
      // Pass control to the implementation.
      if (0 != this->impl_->handle_global_event (ev))
        return -1;

      if (0 != this->dispatch_global_event (ev, this->impl_))
        return -1;
    }

    // Notify all handler's in the master registry. This will prevent
    // us from sending the same notification more than once to the same
    // event handler, which can be the case when a handler is registered
    // more than once.
    for (handler_set::ITERATOR iter (this->master_); !iter.done (); ++ iter)
      this->dispatch_global_event (ev, *iter);

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// dispatch_global_event
//
int Event_Handler::
dispatch_global_event (long global_event, Event_Handler_Impl * eh)
{
  GLOBAL_EVENT_METHOD method = 0;

  if (global_event >= 0 &&
      global_event <= GLOBALEVENT_NOTIFICATION_READY)
  {
    // Locate the method in the global event map.
    method = __globalevent_map__[global_event];
  }
  else if (global_event >= APPEVENT_XML_IMPORT_BEGIN &&
           global_event <= APPEVENT_LIB_ATTACH_END)
  {
    // Locate the method in the app event map.
    size_t index = global_event - APPEVENT_XML_IMPORT_BEGIN;
    method = __appevent_map__[index];
  }

  return 0 != method ? (eh->*method) () : -1;
}

//
// ObjectEvent
//
STDMETHODIMP Event_Handler::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  // There is no need to continue if we are not enabled.
  if (!this->enable_)
    return S_OK;

  try
  {
    GAME::Object object (obj);

    if (0 != this->impl_)
    {
      // First, pass control to the main implementation. We are going
      // to use the traditional method for passing the event to the
      // implementation as well as the dispatch method.
      if (0 != this->impl_->handle_object_event (object, eventmask))
        return S_FALSE;

      if (0 != this->dispatch_object_event (object, eventmask, this->impl_))
        return S_FALSE;
    }

    // Notify the instance handlers of the event
    handler_set * handlers = 0;
    if (0 == this->type_handlers_.find (object.meta ().name (), handlers) &&
        0 != this->dispatch_object_event (object, eventmask, *handlers))
    {
      return S_FALSE;
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
  // the handler.
  auto_clean.release ();

  // Save the handler to the master registery.
  if (0 != this->master_.insert (eh))
    return -1;

  // Save the handler to its handler set.
  if (0 != handlers->insert (eh))
    return -1;

  return 0;
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

  // Delete all the handler sets.
  for (; !iter.done (); ++ iter)
    delete iter->item ();

  // Clear all the container's contents.
  this->type_handlers_.unbind_all ();
  this->master_.reset ();
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
  const unsigned long eh_eventmask = static_cast <unsigned long> (eh->event_mask ());

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
    if ((handler_iter->bitmask_ & eh_eventmask) != 0 && handler_iter->method_)
      retval += (eh->*handler_iter->method_) (obj) == 0 ? 0 : 1;

    // Move to the next location.
    current_mask >>= 1;
    ++ handler_iter;
  }

  return retval;
}

}
