// $Id$

//
// hostname
//
CUTS_INLINE
const char * CUTS_DatabaseWorker::hostname (void) const
{
  return this->hostname_.c_str ();
}

CUTS_INLINE
void CUTS_DatabaseWorker::hostname (const char * hostname)
{
  this->hostname_ = hostname;
}

//
// create_connection
//
CUTS_INLINE
bool CUTS_DatabaseWorker::create_connection (void)
{
  return this->conn_->connect (
    CUTS_USERNAME, 
    CUTS_PASSWORD, 
    this->hostname_.c_str (), 
    CUTS_DEFAULT_PORT);
}

//
// destroy_connection
//
CUTS_INLINE
void CUTS_DatabaseWorker::destroy_connection (void)
{
  this->conn_->disconnect ();
}
