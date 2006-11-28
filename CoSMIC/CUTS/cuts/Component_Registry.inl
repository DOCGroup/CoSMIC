// $Id$

//
// lock
//
CUTS_INLINE
ACE_RW_Thread_Mutex & CUTS_Component_Registry::
lock (void)
{
  return this->lock_;
}

//
// is_registered
//
CUTS_INLINE
bool CUTS_Component_Registry::
is_registered (const char * uuid)
{
  return this->registry_.find (uuid) != this->registry_.end ();
}

//
// unregister_handler
//
CUTS_INLINE
int CUTS_Component_Registry::
unregister_handler (CUTS_Component_Registry_Handler * handler)
{
  return this->handlers_.remove (handler);
}

//
// is_open
//
CUTS_INLINE
int CUTS_Component_Registry::is_open (void)
{
  return this->open_;
}

//
// registry_size
//
CUTS_INLINE
size_t CUTS_Component_Registry::registry_size (void)
{
  return this->registry_.size ();
}
