// $Id$

#include "cuts/Component_Registry.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Registry.inl"
#endif

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
  CUTS_Component_Registry_Map::iterator iter;

  // Delete all the <CUTS_Component_Registry_Node> objects.
  for (iter =  this->registry_.begin ();
       iter != this->registry_.end ();
       iter ++)
  {
    delete iter->second;
  }
}


//
// register_component
//
size_t CUTS_Component_Registry::register_component (const char * uuid)
{
  // Allocate a new <CUTS_Component_Registry_Node> and store it
  // in a <ACE_Auto_Ptr>. In case anything bad happens and
  // return before we insert the allocated memory in the <registry_>
  // it will be destroyed on exit.
  CUTS_Component_Registry_Node * node = new CUTS_Component_Registry_Node;
  ACE_Auto_Ptr <CUTS_Component_Registry_Node> auto_clean (node);

  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex,
                          guard,
                          this->lock_,
                          0);

  // Insert the <node> into the <registry_> and "release" the
  // reference stored in the <auto_clean> variable.
  std::pair <CUTS_Component_Registry_Map::iterator, bool>
    result = this->registry_.insert (
    CUTS_Component_Registry_Map::value_type (uuid, node));

  if (result.second)
  {
    node->info ().inst_ = uuid;
    auto_clean.release ();
  }
  else
    node = result.first->second;

  // Set the state of the component to *active* and signal all
  // the <handlers_> that we have a new component registered.
  node->info ().state_ = 1;
  this->info_queue_.enqueue_tail (node);
  return node->info ().uid_;
}

//
// unregister_component
//
void CUTS_Component_Registry::unregister_component (const char * uuid)
{
  CUTS_Component_Registry_Map::iterator iter = this->registry_.find (uuid);

  if (iter != this->registry_.end ())
  {
    // Set the state of the component to *inactive* and notify
    // all the registered <handlers_>.

    iter->second->info ().state_ = 0;
    this->info_queue_.enqueue_tail (iter->second);
  }
}

//
// get_registration
//
size_t CUTS_Component_Registry::
get_registration (const char * uuid,
                  bool auto_register)
{
  long regid = 0;

  CUTS_Component_Registry_Map::const_iterator iter;

  do
  {
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex,
                           guard,
                           this->lock_,
                           0);

    iter = this->registry_.find (uuid);
  } while (0);

  if (iter != this->registry_.end ())
    return iter->second->info ().uid_;
  else if (auto_register)
    return this->register_component (uuid);
  else
    return 0;
}

//
// get_component_by_id
//
std::string CUTS_Component_Registry::get_component_by_id (long regid) const
{
  CUTS_Component_Registry_Map::const_iterator iter;

  for (iter = this->registry_.begin ();
       iter != this->registry_.end ();
       iter ++)
  {
    if (reinterpret_cast <long> (iter->second) == regid)
      return iter->first;
  }

  return "";
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
    ACE_reinterpret_cast (CUTS_Component_Registry *, param);

  while (reg->is_open ())
  {
    CUTS_Component_Registry_Node * node = 0;
    int retval = reg->info_queue_.dequeue_head (node);

    if (retval != -1 && node != 0)
    {
      CUTS_Handler_Set::ITERATOR iter (reg->handlers_);

      for (iter; !iter.done (); iter ++)
        (*iter)->handle_component (node->info ());
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
