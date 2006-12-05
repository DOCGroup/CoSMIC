// $Id$

//
// service_count
//
CUTS_INLINE
size_t CUTS_BDC_Service_Manager::
get_service_count (void) const
{
  return ACE_Service_Gestalt::repo_->current_size ();
}

//
// get_orb
//
CUTS_INLINE
::CORBA::ORB_ptr CUTS_BDC_Service_Manager::
get_orb (void) const
{
  return ::CORBA::ORB::_duplicate (this->orb_.in ());
}

//
// metrics
//
CUTS_INLINE
CUTS_System_Metric * CUTS_BDC_Service_Manager::
metrics (void)
{
  return this->metrics_;
}
