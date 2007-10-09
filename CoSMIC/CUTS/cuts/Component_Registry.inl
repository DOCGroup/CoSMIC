// $Id$

//
// is_registered
//
CUTS_INLINE
bool CUTS_Component_Registry::
is_registered (const char * inst)
{
  return this->registry_.find (inst) == 0;
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
size_t CUTS_Component_Registry::registry_size (void) const
{
  return this->registry_.current_size ();
}

//
// hosts
//
CUTS_INLINE
const CUTS_Host_Table & CUTS_Component_Registry::hosts (void) const
{
  return this->hosts_;
}

//
// hosts
//
CUTS_INLINE
CUTS_Host_Table & CUTS_Component_Registry::hosts (void)
{
  return this->hosts_;
}

//
// entries
//
CUTS_INLINE
const CUTS_Component_Registry_Map &
CUTS_Component_Registry::entries (void) const
{
  return this->registry_;
}

//
// component_types
//
CUTS_INLINE
const CUTS_Component_Type_Map &
CUTS_Component_Registry::component_types (void) const
{
  return this->component_types_;
}

//
// component_types
//
CUTS_INLINE
CUTS_Component_Type_Map &
CUTS_Component_Registry::component_types (void)
{
  return this->component_types_;
}
