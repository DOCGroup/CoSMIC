// $Id$

//
// current_test
//
CUTS_INLINE
long CUTS_Database_Service::current_test (void) const
{
  return this->test_number_;
}

//
// handle_activate
//
CUTS_INLINE
int CUTS_Database_Service::handle_activate (void)
{
  return this->create_new_test () ? 0 : -1;
}

//
// handle_deactivate
//
CUTS_INLINE
int CUTS_Database_Service::handle_deactivate (void)
{
  return this->stop_current_test () ? 0 : -1;
}
