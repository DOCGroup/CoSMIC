// $Id: ODBC_Exception.inl,v 1.1.2.1 2006/03/27 01:03:06 hillj Exp $

//=============================================================================
//
// ODBC_Exception
//
//=============================================================================

CUTS_INLINE
const char * ODBC_Exception::message (void) const
{
  return this->message_.c_str ();
}
