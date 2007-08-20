// $Id$

//
// is_connected
//
CUTS_INLINE
bool CUTS_DB_Connection::is_connected (void) const
{
  return this->connected_;
}

//
// disconnect
//
CUTS_INLINE
void CUTS_DB_Connection::disconnect (void)
{
  this->connected_ = false;
}

//
// connect
//
CUTS_INLINE
void CUTS_DB_Connection::connect (const char * username,
                                  const char * password,
                                  const char * server,
                                  int port)
{
  this->connected_ = true;

  ACE_UNUSED_ARG (username);
  ACE_UNUSED_ARG (password);
  ACE_UNUSED_ARG (server);
  ACE_UNUSED_ARG (port);
}
