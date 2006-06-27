// $Id: ODBC_Exception.inl,v 1.1.2.1 2006/03/27 01:03:06 hillj Exp $

//
// message
//
CUTS_INLINE
const ACE_CString & ODBC_Exception::message (void) const
{
  return this->message_;
}

//
// state
//
CUTS_INLINE
const ACE_CString & ODBC_Exception::state (void) const
{
  return this->state_;
}

//
// native
//
CUTS_INLINE
long ODBC_Exception::native (void) const
{
  return this->native_;
}
