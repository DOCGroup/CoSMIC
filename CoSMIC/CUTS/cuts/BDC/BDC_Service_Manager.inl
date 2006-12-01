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
