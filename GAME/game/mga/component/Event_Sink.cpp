// $Id$

#include "stdafx.h"
#include "Event_Sink.h"

#if !defined (__GAME_INLINE__)
#include "Event_Sink.inl"
#endif

#include "Console_Service.h"
#include "Object_Event_Handler.h"

#include "game/mga/Transaction.h"
#include "game/mga/MetaFCO.h"

#include "ace/ACE.h"
#include "ace/Auto_Ptr.h"
#include "ace/streams.h"

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// invoke functions (global events)

// Type definition for handling a global event.
typedef int (*GLOBAL_EVENT_METHOD) (Global_Event_Handler *);

//
// invoke_handle_project_open
//
static inline int
invoke_handle_project_open (Global_Event_Handler * impl)
{
  return impl->handle_project_open ();
}

//
// invoke_handle_project_close
//
static inline int
invoke_handle_project_close (Global_Event_Handler * impl)
{
  return impl->handle_project_close ();
}

//
// invoke_handle_territory_create
//
static inline int
invoke_handle_territory_create (Global_Event_Handler * impl)
{
  return impl->handle_territory_create ();
}

//
// invoke_handle_save_project
//
static inline int
invoke_handle_save_project (Global_Event_Handler * impl)
{
  return impl->handle_save_project ();
}

//
// invoke_handle_territory_destroy
//
static inline int
invoke_handle_territory_destroy (Global_Event_Handler * impl)
{
  return impl->handle_territory_destroy ();
}

//
// invoke_handle_transaction_commit
//
static inline int
invoke_handle_transaction_commit (Global_Event_Handler * impl)
{
  return impl->handle_transaction_commit ();
}

//
// invoke_handle_transaction_abort
//
static inline int
invoke_handle_transaction_abort (Global_Event_Handler * impl)
{
  return impl->handle_transaction_abort ();
}

//
// invoke_handle_undo
//
static inline int
invoke_handle_undo (Global_Event_Handler * impl)
{
  return impl->handle_undo ();
}

//
// invoke_handle_redo
//
static inline int
invoke_handle_redo (Global_Event_Handler * impl)
{
  return impl->handle_redo ();
}

//
// invoke_handle_project_properties
//
static inline int
invoke_handle_project_properties (Global_Event_Handler * impl)
{
  return impl->handle_project_properties ();
}

//
// invoke_handle_notification_ready
//
static inline int
invoke_handle_notification_ready (Global_Event_Handler * impl)
{
  return impl->handle_notification_ready ();
}

//
// invoke_handle_project_open_finished
//
static inline int
invoke_handle_project_open_finished (Global_Event_Handler * impl)
{
  return impl->handle_project_open_finished ();
}

//
// __globalevent_map__
//
static const GLOBAL_EVENT_METHOD __globalevent_map__[] = {
  &invoke_handle_project_open,            /* GLOBALEVENT_OPEN_PROJECT           */
  &invoke_handle_project_close,           /* GLOBALEVENT_CLOSE_PROJECT          */
  &invoke_handle_save_project,            /* GLOBALEVENT_SAVE_PROJECT           */
  &invoke_handle_territory_create,        /* GLOBALEVENT_NEW_TERRITORY          */
  &invoke_handle_territory_destroy,       /* GLOBALEVENT_DESTROY_TERRITORY      */
  &invoke_handle_transaction_commit,      /* GLOBALEVENT_COMMIT_TRANSACTION     */
  &invoke_handle_transaction_abort,       /* GLOBALEVENT_ABORT_TRANSACTION      */
  &invoke_handle_undo,                    /* GLOBALEVENT_UNDO                   */
  &invoke_handle_redo,                    /* GLOBALEVENT_REDO                   */
  &invoke_handle_project_properties,      /* GLOBALEVENT_PROJECT_PROPERTIES     */
  &invoke_handle_notification_ready,      /* GLOBALEVENT_NOTIFICATION_READY     */
  &invoke_handle_project_open_finished,   /* GLOBALEVENT_OPEN_PROJECT_FINISHED  */
};

//
// invoke_handle_xml_import_begin
//
static inline int
invoke_handle_xml_import_begin (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_begin ();
}

//
// invoke_handle_xml_import_end
//
static inline int
invoke_handle_xml_import_end (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_end ();
}

//
// invoke_handle_xml_import_fcos_begin
//
static inline int
invoke_handle_xml_import_fcos_begin (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_fcos_begin ();
}

//
// invoke_handle_xml_import_fcos_end
//
static inline int
invoke_handle_xml_import_fcos_end (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_fcos_end ();
}

//
// invoke_handle_xml_import_special_begin
//
static inline int
invoke_handle_xml_import_special_begin (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_special_begin ();
}

//
// invoke_handle_xml_import_special_end
//
static inline int
invoke_handle_xml_import_special_end (Global_Event_Handler * impl)
{
  return impl->handle_xml_import_special_end ();
}

//
// invoke_handle_library_attach_begin
//
static inline int
invoke_handle_library_attach_begin (Global_Event_Handler * impl)
{
  return impl->handle_library_attach_begin ();
}

//
// invoke_handle_library_attach_end
//
static inline int
invoke_handle_library_attach_end (Global_Event_Handler * impl)
{
  return impl->handle_library_attach_end ();
}

//
// __appevent_map__
//
static const GLOBAL_EVENT_METHOD __appevent_map__[] = {
  &invoke_handle_xml_import_begin,                    /* APPEVENT_XML_IMPORT_BEGIN */
  &invoke_handle_xml_import_end,                      /* APPEVENT_XML_IMPORT_END */
  &invoke_handle_xml_import_fcos_begin,               /* APPEVENT_XML_IMPORT_FCOS_BEGIN */
  &invoke_handle_xml_import_fcos_end,                 /* APPEVENT_XML_IMPORT_FCOS_END */
  &invoke_handle_xml_import_special_begin,            /* APPEVENT_XML_IMPORT_SPECIAL_BEGIN */
  &invoke_handle_xml_import_special_end,              /* APPEVENT_XML_IMPORT_SPECIAL_END */
  &invoke_handle_library_attach_begin,                /* APPEVENT_LIB_ATTACH_BEGIN */
  &invoke_handle_library_attach_end                   /* APPEVENT_LIB_ATTACH_END */
};

///////////////////////////////////////////////////////////////////////////////
// invoke functions (object events)

//
// invoke_handle_object_attribute
//
static inline int
invoke_handle_object_attribute (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_attribute (obj);
}

//
// invoke_handle_object_registry
//
static inline int
invoke_handle_object_registry (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_registry (obj);
}

//
// invoke_handle_new_child
//
static inline int
invoke_handle_new_child (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_new_child (obj);
}

//
// invoke_handle_object_relation
//
static inline int
invoke_handle_object_relation (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_relation (obj);
}

//
// invoke_handle_object_properties
//
static inline int
invoke_handle_object_properties (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_properties (obj);
}

//
// invoke_handle_instance_subtype
//
static inline int
invoke_handle_instance_subtype (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_instance_subtype (obj);
}

//
// invoke_handle_object_parent
//
static inline int
invoke_handle_object_parent (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_parent (obj);
}

//
// invoke_handle_lost_child
//
static inline int
invoke_handle_lost_child (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_lost_child (obj);
}

//
// invoke_handle_referenced
//
static inline int
invoke_handle_referenced (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_referenced (obj);
}

//
// invoke_handle_object_connected
//
static inline int
invoke_handle_object_connected (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_connected (obj);
}

//
// invoke_handle_set_included
//
static inline int
invoke_handle_set_included (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_set_included (obj);
}

//
// invoke_handle_referenced_release
//
static inline int
invoke_handle_referenced_release (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_referenced_release (obj);
}

//
// invoke_handle_object_disconnected
//
static inline int
invoke_handle_object_disconnected (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_disconnected (obj);
}

//
// invoke_handle_set_excluded
//
static inline int
invoke_handle_set_excluded (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_set_excluded (obj);
}

//
// invoke_handle_marked_readonly
//
static inline int
invoke_handle_marked_readonly (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_marked_readonly (obj);
}

//
// invoke_handle_marked_readwrite
//
static inline int
invoke_handle_marked_readwrite (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_marked_readwrite (obj);
}

//
// invoke_handle_model_open
//
static inline int
invoke_handle_model_open (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_model_open (obj);
}

//
// invoke_handle_object_select
//
static inline int
invoke_handle_object_select (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_select (obj);
}

//
// invoke_handle_object_deselect
//
static inline int
invoke_handle_object_deselect (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_deselect (obj);
}

//
// invoke_handle_object_mouseover
//
static inline int
invoke_handle_object_mouseover (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_mouseover (obj);
}

//
// invoke_handle_model_close
//
static inline int
invoke_handle_model_close (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_model_close (obj);
}

//
// invoke_handle_object_predestroyed
//
static inline int
invoke_handle_object_predestroyed (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_predestroyed (obj);
}

//
// invoke_handle_object_copied
//
static inline int
invoke_handle_object_copied (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_copied (obj);
}

//
// invoke_handle_object_destroyed
//
static inline int
invoke_handle_object_destroyed (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_destroyed (obj);
}

//
// invoke_handle_object_created
//
static inline int
invoke_handle_object_created (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_created (obj);
}

//
// invoke_handle_object_prestatus
//
static inline int
invoke_handle_object_prestatus (Object_Event_Handler * impl, Object_in obj)
{
  return impl->handle_object_prestatus (obj);
}

///////////////////////////////////////////////////////////////////////////////
// invocation map

#define OBJECT_EVENT_COUNT 32

// Type definition for the handler method of an object event.
typedef int (*HANDLER_METHOD) (Object_Event_Handler *, Object_in);

struct handler_entry_t
{
  unsigned long bitmask_;

  HANDLER_METHOD method_;
};

// Handle map for object events
static const handler_entry_t objectevent_handles[OBJECT_EVENT_COUNT] = {
  {0x1, &invoke_handle_object_attribute},           /* OBJEVENT_ATTR          */
  {0x2, &invoke_handle_object_registry},            /* OBJEVENT_REGISTRY      */
  {0x4, &invoke_handle_new_child},                  /* OBJEVENT_NEWCHILD      */
  {0x8, &invoke_handle_object_relation},            /* OBJEVENT_RELATION      */
  {0x10, &invoke_handle_object_properties},         /* OBJEVENT_PROPERTIES    */
  {0x20, &invoke_handle_instance_subtype},          /* OBJEVENT_SUBT_INST     */
  {0, 0},                                           /* (unused)               */
  {0, 0},                                           /* (unused)               */
  {0x100, &invoke_handle_object_parent},            /* OBJEVENT_PARENT        */
  {0x200, &invoke_handle_lost_child},               /* OBJEVENT_LOSTCHILD     */
  {0x400, &invoke_handle_referenced},               /* OBJEVENT_REFERENCED    */
  {0x800, &invoke_handle_object_connected},         /* OBJEVENT_CONNECTED     */
  {0x1000, &invoke_handle_set_included},            /* OBJEVENT_SETINCLUDED   */
  {0x2000, &invoke_handle_referenced_release},      /* OBJEVENT_REFRELEASED   */
  {0x4000, &invoke_handle_object_disconnected},     /* OBJEVENT_DISCONNECTED  */
  {0x8000, &invoke_handle_set_excluded},            /* OBJEVENT_SETEXCLUDED   */
  {0x10000, &invoke_handle_marked_readonly},        /* OBJEVENT_MARKEDRO      */
  {0x20000, &invoke_handle_marked_readwrite},       /* OBJEVENT_MARKEDRW      */
  {0, 0},                                           /* (unused)               */
  {0x80000, &invoke_handle_model_open},             /* OBJEVENT_OPENMODEL     */
  {0x100000, &invoke_handle_object_select},         /* OBJEVENT_SELECT        */
  {0x200000, &invoke_handle_object_deselect},       /* OBJEVENT_DESELECT      */
  {0x400000, &invoke_handle_object_mouseover},      /* OBJEVENT_MOUSEOVER     */
  {0x800000, &invoke_handle_model_close},           /* OBJEVENT_CLOSEMODEL    */
  {0, 0},                                           /* (unused)               */
  {0, 0},                                           /* (unused)               */
  {0, 0},                                           /* (unused)               */
  {0x8000000, &invoke_handle_object_copied},        /* OBJEVENT_COPIED        */
  {0x10000000, &invoke_handle_object_prestatus},    /* OBJEVENT_PRE_STATUS    */
  {0x20000000, &invoke_handle_object_predestroyed}, /* OBJEVENT_PRE_DESTROYED */
  {0x40000000, &invoke_handle_object_destroyed},    /* OBJEVENT_DESTROYED     */
  {0x80000000, &invoke_handle_object_created}       /* OBJEVENT_CREATED       */
};

//
// Event_Sink
//
Event_Sink::Event_Sink (void)
: impl_ (0),
  enable_ (true),
  meta_handlers_ (OBJTYPE_FOLDER + 1)
{

}

//
// set_event_handler
//
void Event_Sink::set_event_handler (Top_Level_Event_Handler * impl)
{
  if (this->impl_ != impl)
  {
    // Unset event handler for current implementation
    if (0 != this->impl_)
      this->impl_->set_event_sink (0);

    // Save the implementation.
    this->impl_ = impl;

    // Set event handler for current implementation
    if (0 != this->impl_)
      this->impl_->set_event_sink (this);
  }
}

//
// initialize
//
int Event_Sink::initialize (Project project)
{
  this->project_ = project;
  int retval = 0;

  if (0 != this->impl_)
  {
    // Start a new transaction and initialize the implementation.
    Transaction t (this->project_);
    retval = this->impl_->initialize (project);

    if (0 == retval)
      t.commit ();
  }

  return retval;
}

//
// GlobalEvent
//
STDMETHODIMP Event_Sink::GlobalEvent (globalevent_enum ev)
{
  // There is no need to continue if we are not enabled.
  if (!this->enable_)
    return 0;

  try
  {
    // Notify all handler's in the master registry. This will prevent
    // us from sending the same notification more than once to the same
    // event handler, which can be the case when a handler is registered
    // more than once.
    if (0 != this->global_handlers_.current_size ())
    {
      for (global_handler_map_t::ITERATOR iter (this->global_handlers_);
           !iter.done ();
           ++ iter)
      {
        if (0 != Event_Sink::dispatch_global_event (ev, iter->key ()))
          return E_MGA_MUST_ABORT;
      }
    }

    return 0;
  }
  catch (...)
  {

  }

  return E_MGA_MUST_ABORT;
}

//
// dispatch_global_event
//
int Event_Sink::
dispatch_global_event (long global_event, Global_Event_Handler * eh)
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


  return 0 != method ? (*method) (eh) : -1;
}

//
// ObjectEvent
//
STDMETHODIMP Event_Sink::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  // There is no need to continue if we are not enabled.
  if (!this->enable_)
    return 0;

  try
  {
    Object object (obj);
    handler_set * handlers = 0;

    if (0 != this->inst_handlers_.current_size ())
    {
      if (0 == this->inst_handlers_.find (object, handlers))
      {
        // Notify the type handlers of the event. We are not going to
        // continue if there are any *errors* in the process.
        if (0 != this->dispatch_object_event (object, eventmask, *handlers))
          return E_MGA_MUST_ABORT;

        // If this is a destroy event, let's do some house keeping. ;-)
        if (0 != (eventmask & OBJEVENT_DESTROYED))
          this->unregister_all (object);
      }
    }

    if (0 != this->type_handlers_.current_size ())
    {
      if (0 == this->type_handlers_.find (object->meta (), handlers))
      {
        // Notify the type handlers of the event. We are not going to
        // continue if there are any *errors* in the process.
        if (0 != this->dispatch_object_event (object, eventmask, *handlers))
          return E_MGA_MUST_ABORT;
      }
    }

    // Notify the meta type handlers of the event. We are not going to
    // continue if there are any *errors* in the process.
    int type = object->type ();
    handler_set & meta_handlers = this->meta_handlers_[type];

    if (0 != meta_handlers.size ())
    {
      if (0 != this->dispatch_object_event (object, eventmask, meta_handlers))
        return E_MGA_MUST_ABORT;
    }

    return 0;
  }
  catch (const GAME::Mga::Exception & ex)
  {
    Console_Service * console = GME_CONSOLE_SERVICE;

    if (!console->is_initialized ())
      console->initialize (this->project_);

    console->error (ex.message ());
  }
  catch (...)
  {

  }

  return E_MGA_MUST_ABORT;
}

//
// register_handler
//
int Event_Sink::register_handler (Global_Event_Handler * eh)
{
  int retval = this->insert_into_global_handlers (eh);

  if (0 == retval)
    eh->initialize (this->project_);

  return retval;
}

//
// unregister_handler
//
int Event_Sink::unregister_handler (Global_Event_Handler * eh)
{
  return this->remove_from_global_handlers (eh);
}


//
// register_handler
//
int Event_Sink::
register_handler (size_t metatype, Object_Event_Handler * eh)
{
  // Make sure the meta type is valid.
  if (metatype + 1 >= this->meta_handlers_.size ())
    return -1;

  // Insert the event handler into the global handler set.
  if (0 != this->insert_into_global_handlers (eh))
    return -1;

  // Initialize the event handler.
  eh->set_event_sink (this);
  if (0 != eh->initialize (this->project_))
    return -1;

  // Lastly, store the event handler.
  this->meta_handlers_[metatype].insert (eh);

  return 0;
}

//
// register_handler
//
int Event_Sink::
register_handler (const std::string & metaname, Object_Event_Handler * eh)
{
  Folder root = this->project_.root_folder ();
  Meta::Folder metafolder = root->meta ();

  try
  {
    Meta::FCO metafco = metafolder->find (metaname);

    if (!metafco.is_nil ())
      return this->register_handler (metafco.get (), eh);
  }
  catch (const GAME::Mga::Failed_Result & ex)
  {
    // We only care about the E_NOTFOUND exception. All other exception
    // we are just going to re-throw...
    if (ex.value () != 0x80731007)
      throw;

    // Maybe the type is a folder.
    Meta::Folder folder = metafolder->find_folder (metaname);

    if (!folder.is_nil ())
      return this->register_handler (folder.get (), eh);
  }

  return -1;
}

//
// register_handler
//
int Event_Sink::
register_handler (const Meta::Base_in meta, Object_Event_Handler * eh)
{
  if (0 != this->insert_into_global_handlers (eh))
    return -1;

  // Locate the event handler set for this type.
  handler_set * handlers = 0;

  if (0 != this->type_handlers_.find (meta, handlers))
  {
    // Create a new event handler set.
    ACE_NEW_RETURN (handlers, handler_set (), -1);
    ACE_Auto_Ptr <handler_set> auto_clean (handlers);

    if (0 != this->type_handlers_.bind (meta, handlers))
      return -1;

    auto_clean.release ();
  }

  // Initialize the event handler.
  eh->set_event_sink (this);
  if (0 != eh->initialize (this->project_))
    return -1;

  handlers->insert (eh);
  return 0;
}

//
// register_handler
//
int Event_Sink::
register_handler (const Object_in obj, Object_Event_Handler * eh)
{
  if (0 != this->insert_into_global_handlers (eh))
    return -1;

  // Locate the event handler set for this type.
  handler_set * handlers = 0;

  if (0 != this->inst_handlers_.find (obj, handlers))
  {
    // Create a new event handler set.
    ACE_NEW_RETURN (handlers, handler_set (), -1);
    ACE_Auto_Ptr <handler_set> auto_clean (handlers);

    if (0 != this->inst_handlers_.bind (obj, handlers))
      return -1;

    auto_clean.release ();
  }

  // Initialize the event handler.
  eh->set_event_sink (this);
  if (0 != eh->initialize (this->project_))
    return -1;

  handlers->insert (eh);
  return 0;
}

//
// unregister_handler
//
int Event_Sink::
unregister_handler (const Object_in obj, Object_Event_Handler * eh)
{
  handler_set * handlers = 0;

  if (0 != this->inst_handlers_.find (obj, handlers))
    return -1;

  if (0 == handlers->remove (eh))
    this->remove_from_global_handlers (eh);

  return 0;
}

//
// unregister_all
//
int Event_Sink::unregister_all (const Object_in obj)
{
  handler_set * handlers = 0;

  // Locate the handler set.
  if (0 != this->inst_handlers_.find (obj, handlers))
    return -1;

  // Close all the handlers in the handler set.
  for (handler_set::ITERATOR iter (*handlers); !iter.done (); ++ iter)
    this->remove_from_global_handlers (*iter);

  // Reset the handler set.
  handlers->reset ();
  return 0;
}

//
// close
//
void Event_Sink::close (void)
{
  // Close all the event handlers.
  global_handler_map_t::ITERATOR iter (this->global_handlers_);

  for (; !iter.done (); ++ iter)
  {
    iter->key ()->handle_close ();
    iter->key ()->close ();
  }
}

//
// dispatch_object_event
//
int Event_Sink::
dispatch_object_event (Object_in obj, unsigned long mask, const handler_set & handlers)
{
  // Check the size before continuing. This will improve performance
  // a little.
  if (0 == handlers.size ())
    return 0;

  handler_set::CONST_ITERATOR iter (handlers);

  for (; !iter.done (); ++ iter)
  {
    // Pass the event to each event handler.
    if (0 != Event_Sink::dispatch_object_event (obj, mask, *iter))
      return -1;
  }

  return 0;
}

//
// dispatch_object_event
//
int Event_Sink::
dispatch_object_event (const Object_in obj,
                       unsigned long mask,
                       Object_Event_Handler * eh)
{
  // Get the event mask for the event handler.
  const unsigned long eh_eventmask = eh->event_mask ();
  const handler_entry_t * handler_iter = objectevent_handles;

  while (0 != (mask & 0xFFFFFFFF))
  {
    // Locate the first set bit in the current mask. We must increment
    // the handler iterator for each bit we skip. We could use division
    // and modulus to locate the next value, but those operations are
    // to expensive.
    for (; !(0x00000001 & mask); mask >>= 1)
      ++ handler_iter;

    // Ok, we found the next set bit location. We need to check if the
    // event handler is registered for this event.
    if (0 != (handler_iter->bitmask_ & eh_eventmask))
    {
      if (0 != (*handler_iter->method_) (eh, obj))
        return -1;
    }

    // Move to the next location.
    mask >>= 1;
    ++ handler_iter;
  }

  return 0;
}

//
// insert_into_global_handlers
//
int Event_Sink::
insert_into_global_handlers (Global_Event_Handler * eh)
{
  // Get the current reference count.
  size_t refcount = 0;
  this->global_handlers_.find (eh, refcount);

  // Update the reference count.
  return this->global_handlers_.rebind (eh, refcount + 1) == -1 ? -1 : 0;
}

//
// remove_from_global_handlers
//
int Event_Sink::
remove_from_global_handlers (Global_Event_Handler * eh)
{
  // Get the current reference count.
  size_t refcount = 0;

  if (0 != this->global_handlers_.find (eh, refcount))
    return 0;

  // Decrement the reference count.
  -- refcount;

  if (refcount == 0)
  {
    // Remove the event handler.
    this->global_handlers_.unbind (eh);

    // Close the event handler.
    eh->close ();
  }
  else
  {
    // Update the event handler's reference count.
    this->global_handlers_.rebind (eh, refcount);
  }

  return 0;
}

}
}
