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
// metrics
//
CUTS_INLINE
CUTS_System_Metric * CUTS_BDC_Service_Manager::
metrics (void) const
{
  return this->metrics_;
}

//
// testing_service
//
CUTS_INLINE
CUTS_Testing_Service * CUTS_BDC_Service_Manager::
testing_service (void) const
{
  return this->tsvc_;
}

//
// get_uuid
//
CUTS_INLINE
const ACE_CString & CUTS_BDC_Service_Manager::get_uuid (void) const
{
  return this->uuid_;
}

//
// set_uuid
//
CUTS_INLINE
void CUTS_BDC_Service_Manager::set_uuid (const ACE_CString & uuid)
{
  this->uuid_ = uuid;
}
