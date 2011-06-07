// $Id$

#include "stdafx.h"
#include "Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

#include "game/mga/Transaction.h"
#include "game/mga/MetaFCO.h"

#include "ace/ACE.h"
#include "ace/Auto_Ptr.h"
#include "ace/streams.h"

namespace GAME
{
namespace Mga
{

// Type definition for handling a global event.
typedef int (*GLOBAL_EVENT_METHOD) (Event_Handler_Interface *);

///////////////////////////////////////////////////////////////////////////////
// invoke functions (global events)

//
// invoke_handle_project_open
//
static inline int
invoke_handle_project_open (Event_Handler_Interface * impl)
{
  return impl->handle_project_open ();
}

//
// invoke_handle_project_close
//
static inline int
invoke_handle_project_close (Event_Handler_Interface * impl)
{
  return impl->handle_project_close ();
}

//
// invoke_handle_territory_create
//
static inline int
invoke_handle_territory_create (Event_Handler_Interface * impl)
{
  return impl->handle_territory_create ();
}


//
// invoke_handle_territory_destroy
//
static inline int
invoke_handle_territory_destroy (Event_Handler_Interface * impl)
{
  return impl->handle_territory_destroy ();
}

//
// invoke_handle_transaction_commit
//
static inline int
invoke_handle_transaction_commit (Event_Handler_Interface * impl)
{
  return impl->handle_transaction_commit ();
}

//
// invoke_handle_transaction_abort
//
static inline int
invoke_handle_transaction_abort (Event_Handler_Interface * impl)
{
  return impl->handle_transaction_abort ();
}

//
// invoke_handle_undo
//
static inline int
invoke_handle_undo (Event_Handler_Interface * impl)
{
  return impl->handle_undo ();
}

//
// invoke_handle_redo
//
static inline int
invoke_handle_redo (Event_Handler_Interface * impl)
{
  return impl->handle_redo ();
}

//
// invoke_handle_project_properties
//
static inline int
invoke_handle_project_properties (Event_Handler_Interface * impl)
{
  return impl->handle_project_properties ();
}

//
// invoke_handle_notification_ready
//
static inline int
invoke_handle_notification_ready (Event_Handler_Interface * impl)
{
  return impl->handle_notification_ready ();
}

//
// __globalevent_map__
//
static const GLOBAL_EVENT_METHOD __globalevent_map__[] = {
  &invoke_handle_project_open,
  &invoke_handle_project_close,
  &invoke_handle_territory_create,
  &invoke_handle_territory_destroy,
  &invoke_handle_transaction_commit,
  &invoke_handle_transaction_abort,
  &invoke_handle_undo,
  &invoke_handle_redo,
  &invoke_handle_project_properties,
  &invoke_handle_notification_ready
};

//
// invoke_handle_xml_import_begin
//
static inline int
invoke_handle_xml_import_begin (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_begin ();
}

//
// invoke_handle_xml_import_end
//
static inline int
invoke_handle_xml_import_end (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_end ();
}

//
// invoke_handle_xml_import_fcos_begin
//
static inline int
invoke_handle_xml_import_fcos_begin (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_fcos_begin ();
}

//
// invoke_handle_xml_import_fcos_end
//
static inline int
invoke_handle_xml_import_fcos_end (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_fcos_end ();
}

//
// invoke_handle_xml_import_special_begin
//
static inline int
invoke_handle_xml_import_special_begin (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_special_begin ();
}

//
// invoke_handle_xml_import_special_end
//
static inline int
invoke_handle_xml_import_special_end (Event_Handler_Interface * impl)
{
  return impl->handle_xml_import_special_end ();
}

//
// invoke_handle_library_attach_begin
//
static inline int
invoke_handle_library_attach_begin (Event_Handler_Interface * impl)
{
  return impl->handle_library_attach_begin ();
}

//
// invoke_handle_library_attach_end
//
static inline int
invoke_handle_library_attach_end (Event_Handler_Interface * impl)
{
  return impl->handle_library_attach_end ();
}

//
// __appevent_map__
//
static const GLOBAL_EVENT_METHOD __appevent_map__[] = {
  &invoke_handle_xml_import_begin,
  &invoke_handle_xml_import_end,
  &invoke_handle_xml_import_fcos_begin,
  &invoke_handle_xml_import_fcos_end,
  &invoke_handle_xml_import_special_begin,
  &invoke_handle_xml_import_special_end,
  &invoke_handle_library_attach_begin,
  &invoke_handle_library_attach_end
};

///////////////////////////////////////////////////////////////////////////////
// invoke functions (object events)

//
// invoke_handle_object_attribute
//
static inline int
invoke_handle_object_attribute (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_attribute (" << obj->path ("/") << ")" << std::endl;

  return impl->handle_object_attribute (obj);
}

//
// invoke_handle_object_registry
//
static inline int
invoke_handle_object_registry (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_registry ()" << std::endl;

  return impl->handle_object_registry (obj);
}

//
// invoke_handle_new_child
//
static inline int
invoke_handle_new_child (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_new_child ()" << std::endl;

  return impl->handle_new_child (obj);
}

//
// invoke_handle_object_relation
//
static inline int
invoke_handle_object_relation (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_relation ()" << std::endl;
  return impl->handle_object_relation (obj);
}

//
// invoke_handle_object_properties
//
static inline int
invoke_handle_object_properties (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_properties ()" << std::endl;
  return impl->handle_object_properties (obj);
}

//
// invoke_handle_instance_subtype
//
static inline int
invoke_handle_instance_subtype (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_instance_subtype ()" << std::endl;
  return impl->handle_instance_subtype (obj);
}

//
// invoke_handle_object_parent
//
static inline int
invoke_handle_object_parent (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_attribute ()" << std::endl;
  return impl->handle_object_parent (obj);
}

//
// invoke_handle_lost_child
//
static inline int
invoke_handle_lost_child (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_lost_child ()" << std::endl;
  return impl->handle_lost_child (obj);
}

//
// invoke_handle_referenced
//
static inline int
invoke_handle_referenced (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_referenced ()" << std::endl;
  return impl->handle_referenced (obj);
}

//
// invoke_handle_object_connected
//
static inline int
invoke_handle_object_connected (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_connected ()" << std::endl;
  return impl->handle_object_connected (obj);
}

//
// invoke_handle_set_included
//
static inline int
invoke_handle_set_included (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_set_included ()" << std::endl;
  return impl->handle_set_included (obj);
}

//
// invoke_handle_referenced_release
//
static inline int
invoke_handle_referenced_release (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_referenced_release ()" << std::endl;
  return impl->handle_referenced_release (obj);
}

//
// invoke_handle_object_disconnected
//
static inline int
invoke_handle_object_disconnected (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_disconnected ()" << std::endl;
  return impl->handle_object_disconnected (obj);
}

//
// invoke_handle_set_excluded
//
static inline int
invoke_handle_set_excluded (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_set_excluded ()" << std::endl;
  return impl->handle_set_excluded (obj);
}

//
// invoke_handle_marked_readonly
//
static inline int
invoke_handle_marked_readonly (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_marked_readonly ()" << std::endl;
  return impl->handle_marked_readonly (obj);
}

//
// invoke_handle_marked_readwrite
//
static inline int
invoke_handle_marked_readwrite (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_marked_readwrite ()" << std::endl;
  return impl->handle_marked_readwrite (obj);
}

//
// invoke_handle_model_open
//
static inline int
invoke_handle_model_open (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_model_open ()" << std::endl;
  return impl->handle_model_open (obj);
}

//
// invoke_handle_object_select
//
static inline int
invoke_handle_object_select (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_select ()" << std::endl;
  return impl->handle_object_select (obj);
}

//
// invoke_handle_object_deselect
//
static inline int
invoke_handle_object_deselect (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_deselect ()" << std::endl;
  return impl->handle_object_deselect (obj);
}

//
// invoke_handle_object_mouseover
//
static inline int
invoke_handle_object_mouseover (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_mouseover ()" << std::endl;
  return impl->handle_object_mouseover (obj);
}

//
// invoke_handle_model_close
//
static inline int
invoke_handle_model_close (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_model_close ()" << std::endl;
  return impl->handle_model_close (obj);
}

//
// invoke_handle_object_destroyed
//
static inline int
invoke_handle_object_destroyed (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);
  fout << "invoke_handle_object_destroyed ()" << std::endl;
  return impl->handle_object_destroyed (obj);
}

//
// invoke_handle_object_created
//
static inline int
invoke_handle_object_created (Event_Handler_Interface * impl, Object_in obj)
{
  std::ofstream fout;
  fout.open ("e:/temp/events.log", std::ios::app);

  fout
    << typeid (*impl).name () << "::"
    << "invoke_handle_object_created ("
    << obj->meta ()->name () << ":" << obj->path ("/")
    << ")" << std::endl;

  return impl->handle_object_created (obj);
}

///////////////////////////////////////////////////////////////////////////////
// invocation map

#define OBJECT_EVENT_COUNT 32

// Type definition for the handler method of an object event.
typedef int (*HANDLER_METHOD) (Event_Handler_Interface *, Object_in);

struct handler_entry_t
{
  unsigned long bitmask_;

  HANDLER_METHOD method_;
};

// Handle map for object events
static const handler_entry_t objectevent_handles[OBJECT_EVENT_COUNT] = {
  {0x1, &invoke_handle_object_attribute},        /* OBJEVENT_ATTR          */
  {0x2, &invoke_handle_object_registry},         /* OBJEVENT_REGISTRY      */
  {0x4, &invoke_handle_new_child},               /* OBJEVENT_NEWCHILD      */
  {0x8, &invoke_handle_object_relation},         /* OBJEVENT_RELATION      */
  {0x10, &invoke_handle_object_properties},      /* OBJEVENT_PROPERTIES    */
  {0x20, &invoke_handle_instance_subtype},       /* OBJEVENT_SUBT_INST     */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0x100, &invoke_handle_object_parent},         /* OBJEVENT_PARENT        */
  {0x200, &invoke_handle_lost_child},            /* OBJEVENT_LOSTCHILD     */
  {0x400, &invoke_handle_referenced},            /* OBJEVENT_REFERENCED    */
  {0x800, &invoke_handle_object_connected},      /* OBJEVENT_CONNECTED     */
  {0x1000, &invoke_handle_set_included},         /* OBJEVENT_SETINCLUDED   */
  {0x2000, &invoke_handle_referenced_release},   /* OBJEVENT_REFRELEASED   */
  {0x4000, &invoke_handle_object_disconnected},  /* OBJEVENT_DISCONNECTED  */
  {0x8000, &invoke_handle_set_excluded},         /* OBJEVENT_SETEXCLUDED   */
  {0x10000, &invoke_handle_marked_readonly},     /* OBJEVENT_MARKEDRO      */
  {0x20000, &invoke_handle_marked_readwrite},    /* OBJEVENT_MARKEDRW      */
  {0, 0},                                        /* (unused)               */
  {0x80000, &invoke_handle_model_open},          /* OBJEVENT_OPENMODEL     */
  {0x100000, &invoke_handle_object_select},      /* OBJEVENT_SELECT        */
  {0x200000, &invoke_handle_object_deselect},    /* OBJEVENT_DESELECT      */
  {0x400000, &invoke_handle_object_mouseover},   /* OBJEVENT_MOUSEOVER     */
  {0x800000, &invoke_handle_model_close},        /* OBJEVENT_CLOSEMODEL    */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0, 0},                                        /* (unused)               */
  {0x40000000, &invoke_handle_object_destroyed}, /* OBJEVENT_DESTROYED     */
  {0x80000000, &invoke_handle_object_created}    /* OBJEVENT_CREATED       */
};

//
// Event_Handler
//
Event_Handler::Event_Handler (Event_Handler_Interface * impl)
: impl_ (impl),
  enable_ (true)
{
  if (0 != this->impl_)
    this->impl_->set_event_handler (this);
}

//
// attach
//
void Event_Handler::attach (Event_Handler_Interface * impl)
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
int Event_Handler::initialize (Project project)
{
  // Save the project and start a new transaction.
  this->project_ = project;
  Transaction t (this->project_);

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
    return 0;

  try
  {
    if (0 != this->impl_)
    {
      // Pass control to the implementation.
      if (0 != this->impl_->handle_global_event (ev))
        return E_MGA_MUST_ABORT;

      if (0 != this->dispatch_global_event (ev, this->impl_))
        return E_MGA_MUST_ABORT;
    }

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
        if (0 != this->dispatch_global_event (ev, iter->key ()))
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
int Event_Handler::
dispatch_global_event (long global_event, Event_Handler_Interface * eh)
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
STDMETHODIMP Event_Handler::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  // There is no need to continue if we are not enabled.
  if (!this->enable_)
    return 0;

  try
  {
    Object object (obj);
    handler_set * handlers = 0;

    if (0 != this->inst_handlers_.current_size () &&
        0 == this->inst_handlers_.find (object, handlers))
    {
      // Notify the type handlers of the event. We are not going to
      // continue if there are any *errors* in the process.
      if (0 != this->dispatch_object_event (object, eventmask, *handlers))
        return E_MGA_MUST_ABORT;

      // If this is a destroy event, let's do some house keeping. ;-)
      if (0 != (eventmask & OBJEVENT_DESTROYED))
        this->unregister_all (object);
    }

    if (0 != this->type_handlers_.current_size () &&
        0 == this->type_handlers_.find (object->meta (), handlers))
    {
      // Notify the type handlers of the event. We are not going to
      // continue if there are any *errors* in the process.
      if (0 != this->dispatch_object_event (object, eventmask, *handlers))
        return E_MGA_MUST_ABORT;
    }

    if (0 != this->impl_ &&
        0 != this->dispatch_object_event (object, eventmask, this->impl_))
    {
      return E_MGA_MUST_ABORT;
    }

    return 0;
  }
  catch (const GAME::Mga::Failed_Result & ex)
  {

  }
  catch (...)
  {

  }

  return E_MGA_MUST_ABORT;
}

//
// register_global_handler
//
int Event_Handler::
register_global_handler (Event_Handler_Interface * eh)
{
  int retval = this->insert_into_global_handlers (eh);

  if (0 == retval)
    eh->initialize (this->project_);

  return retval;
}

//
// unregister_global_handler
//
int Event_Handler::unregister_global_handler (Event_Handler_Interface * eh)
{
  return this->remove_from_global_handlers (eh);
}

//
// register_handler
//
int Event_Handler::
register_handler (const std::string & metaname, Event_Handler_Interface * eh)
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
int Event_Handler::
register_handler (const Meta::Base_in meta, Event_Handler_Interface * eh)
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
  eh->set_event_handler (this);

  if (0 != eh->initialize (this->project_))
    return -1;

  handlers->insert (eh);
  return 0;
}

//
// register_handler
//
int Event_Handler::
register_handler (const Object_in obj, Event_Handler_Interface * eh)
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
  eh->set_event_handler (this);

  if (0 != eh->initialize (this->project_))
    return -1;

  handlers->insert (eh);
  return 0;
}

//
// unregister_handler
//
int Event_Handler::
unregister_handler (const Object_in obj, Event_Handler_Interface * eh)
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
int Event_Handler::unregister_all (const Object_in obj)
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
void Event_Handler::close (void)
{
  //// Delete all event handlers sets for the types.
  //typedef ACE_Hash_Map_Manager <Meta::Base,
  //                              handler_set *,
  //                              ACE_Null_Mutex> hash_map_t;

  //hash_map_t::ITERATOR iter (this->type_handlers_);

  //// Delete all the handler sets.
  //for (; !iter.done (); ++ iter)
  //  iter->item ();

  //// Clear all the container's contents.
  //this->type_handlers_.unbind_all ();
  //this->master_.reset ();
}

//
// dispatch_object_event
//
int Event_Handler::
dispatch_object_event (Object_in obj,
                       unsigned long mask,
                       const handler_set & handlers)
{
  handler_set::CONST_ITERATOR iter (handlers);

  for (; !iter.done (); ++ iter)
  {
    // Pass the event to each event hanlder.
    if (0 != Event_Handler::dispatch_object_event (obj, mask, *iter))
      return -1;
  }

  return 0;
}

//
// dispatch_object_event
//
int Event_Handler::
dispatch_object_event (const Object_in obj,
                       unsigned long mask,
                       Event_Handler_Interface * eh)
{
  // First, let's invoke the general event handler method.
  if (0 != eh->handle_object_event (obj, mask))
    return -1;

  // Get the event mask for the event handler.
  const unsigned long eh_eventmask = eh->event_mask ();
  const handler_entry_t * handler_iter = objectevent_handles;

  while (0 != (mask & 0xFFFFFFFF))
  {
    // Locate the first set bit in the current mask. We must increment
    // the handler iterator for each bit we skip.
    for (; !(0x00000001 & mask); mask >>= 1)
      ++ handler_iter;

    // Ok, we found the next set bit location. We need to check if the
    // event handler is registered for this event.
    if (0 != (handler_iter->bitmask_ & eh_eventmask) != 0 &&
        0 != (*handler_iter->method_) (eh, obj))
    {
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
int Event_Handler::
insert_into_global_handlers (Event_Handler_Interface * eh)
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
int Event_Handler::
remove_from_global_handlers (Event_Handler_Interface * eh)
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
    // Update the event handler's reference count.
    this->global_handlers_.rebind (eh, refcount);

  return 0;
}

}
}
