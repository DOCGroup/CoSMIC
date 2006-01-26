// $Id$

//
// server_name
//
CUTS_INLINE
void
CUTS_CCM_CoWorkEr::server_name (const char * server_name)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->server_name_ = server_name;
}
