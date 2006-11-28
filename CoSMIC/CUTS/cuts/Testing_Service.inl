// $Id$

//
// host_table
//
CUTS_INLINE
const CUTS_Host_Table &
CUTS_Testing_Service::host_table (void) const
{
  return this->host_table_;
}

//
// host_table
//
CUTS_INLINE
CUTS_Host_Table &
CUTS_Testing_Service::host_table (void)
{
  return this->host_table_;
}

//
// registry
//
CUTS_INLINE
CUTS_Component_Registry *
CUTS_Testing_Service::registry (void) const
{
  return this->registry_.get ();
}
