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
// handle_deactivate
//
CUTS_INLINE
int CUTS_Database_Service::handle_deactivate (void)
{
  return this->stop_current_test () ? 0 : -1;
}
