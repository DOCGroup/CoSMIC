// $Id$

#include "cuts/Component_Registry.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Registry.inl"
#endif

#include "cuts/Component_Registry_Node.h"
#include "cuts/Component_Registry_Handler.h"
#include "ace/Guard_T.h"
#include "ace/Thread_Manager.h"

//
// CUTS_Component_Registry
//
CUTS_Component_Registry::CUTS_Component_Registry (void)
: open_ (0),
  grp_id_ (-1)
{

}

//
// ~CUTS_Component_Registry
//
CUTS_Component_Registry::~CUTS_Component_Registry (void)
{
  Component_Registry_Map::iterator iter (this->registry_);

  for (iter; !iter.done (); iter.advance ())
    delete iter->int_id_;
}

//
// register_component
//
int CUTS_Component_Registry::
register_component (CUTS_Component_Registry_Node * info)
{
  int retval = this->registry_.bind (info->info_.inst_, info);

  if (retval == 0)
  {
    // Set the state of the component to *active* and signal all
    // the <handlers_> that we have a new component registered.
    info->info_.state_ = 1;
    this->info_queue_.enqueue_tail (info);
  }

  return retval;
}

//
// unregister_component
//
void CUTS_Component_Registry::
unregister_component (const ACE_CString & instance)
{
  // Remove the component from the registry.
  CUTS_Component_Registry_Node * node = 0;
  int retval = this->registry_.unbind (instance, node);

  // Delete the node.
  if (retval == 0 && node != 0)
    delete node;
}

//
// register_handler
//
int CUTS_Component_Registry::
register_handler (CUTS_Component_Registry_Handler * handler)
{
  if (this->handlers_.find (handler) == 0)
    return 1;

  return this->handlers_.insert (handler);
}

//
// thr_svc
//
ACE_THR_FUNC_RETURN CUTS_Component_Registry::thr_svc (void * param)
{
  CUTS_Component_Registry * reg =
    reinterpret_cast <CUTS_Component_Registry *> (param);

  while (reg->is_open ())
  {
    // Get the next registry node from the <info_queue_>.
    CUTS_Component_Registry_Node * node = 0;
    int retval = reg->info_queue_.dequeue_head (node);

    if (retval != -1 && node != 0)
    {
      // Notify all loaded services to handle the component.
      CUTS_Handler_Set::ITERATOR iter (reg->handlers_);

      for (iter; !iter.done (); iter ++)
        (*iter)->handle_component (node->info_);
    }
  }

  return 0;
}

//
// open
//
int CUTS_Component_Registry::open (void)
{
  // We only all one thread open.
  if (this->is_open ())
    return 1;

  // We need to setup all workings for service thread.
  this->open_ = 1;
  this->info_queue_.activate ();

  // Spawn the service thread for the registry.
  this->grp_id_ =
    ACE_Thread_Manager::instance ()->spawn (
    &CUTS_Component_Registry::thr_svc,
    this);

  // Verify everything was created properly.
  if (this->grp_id_ == -1)
    this->open_ = 0;

  return this->open_ ? 0 : -1;
}

//
// close
//
int CUTS_Component_Registry::close (void)
{
  if (!this->is_open ())
    return 0;

  this->open_ = 0;
  this->info_queue_.deactivate ();

  ACE_Thread_Manager::instance ()->wait_grp (this->grp_id_);

  return 0;
}
