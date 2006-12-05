// $Id$

//
// ~CUTS_BDC_Service
//
CUTS_INLINE
CUTS_BDC_Service::~CUTS_BDC_Service (void)
{

}

//
// init
//
CUTS_INLINE
int CUTS_BDC_Service::init (int argc, char * argv [])
{
  return 0;
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);
}

//
// handle_activate
//
CUTS_INLINE
int CUTS_BDC_Service::handle_activate (void)
{
  return 0;
}

//
// handle_deactivate
//
CUTS_INLINE
int CUTS_BDC_Service::handle_deactivate (void)
{
  return 0;
}

//
// handle_component
//
CUTS_INLINE
int CUTS_BDC_Service::
handle_component (const CUTS_Component_Info & info)
{
  return 0;
}

//
// handle_metrics
//
CUTS_INLINE
int CUTS_BDC_Service::handle_metrics (void)
{
  return 0;
}

//
// get_remote_object
//
CUTS_INLINE
CUTS::BDC_Service_ptr CUTS_BDC_Service::
get_remote_object (void) const
{
  return CUTS::BDC_Service::_nil ();
}

//
// is_active
//
CUTS_INLINE
bool CUTS_BDC_Service::is_active (void) const
{
  return this->active_;
}

//
// svc_mgr
//
CUTS_INLINE
CUTS_BDC_Service_Manager * CUTS_BDC_Service::svc_mgr (void)
{
  return this->svc_mgr_;
}

//
// fini
//
CUTS_INLINE
int CUTS_BDC_Service::fini (void)
{
  return 0;
}

