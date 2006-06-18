// $Id: ODBC_Exception.cpp,v 1.1.2.1.2.1 2006/06/02 05:13:45 hillj Exp $

#include "ODBC_Exception.h"

#if !defined (__CUTS_INLINE__)
#include "ODBC_Exception.inl"
#endif

#include "ODBC.h"

//=============================================================================
//
// ODBC_Exception
//
//=============================================================================

//
// ODBC_Exception
//
ODBC_Exception::ODBC_Exception (void)
: message_ ("ODBC exception has occurred")
{

}

//
// ODBC_Exception
//
ODBC_Exception::ODBC_Exception (const char * message)
: message_ (message)
{

}

//
// ~ODBC_Exception
//
ODBC_Exception::~ODBC_Exception (void)
{

}

//
// get_message_i
//
void ODBC_Exception::get_message_i (SQLHANDLE handle, SQLSMALLINT type)
{
  static char message[256];
  SQLSMALLINT actual;
  char state[6];

  ::SQLGetDiagRec (type,
                   handle,
                   1,
                   (SQLCHAR *)state,
                   &this->native_,
                   (SQLCHAR *)message,
                   sizeof (message),
                   &actual);

  // We need to make sure the code is NULL-terminated before
  // continuing.
  state[5] = 0;

  this->message_.set (message, actual);
  this->state_.set (state, sizeof (state) - 1);
}

//=============================================================================
//
// ODBC_Connection_Exception
//
//=============================================================================

//
// ODBC_Connection_Exception
//
ODBC_Connection_Exception::ODBC_Connection_Exception (HDBC handle)
{
  this->get_message_i (handle, SQL_HANDLE_DBC);
}

//
// ~ODBC_Connection_Exception
//
ODBC_Connection_Exception::~ODBC_Connection_Exception (void)
{

}

//=============================================================================
//
// ODBC_Stmt_Exception
//
//=============================================================================

//
// ODBC_Connection_Exception
//
ODBC_Stmt_Exception::ODBC_Stmt_Exception (HSTMT handle)
{
  this->get_message_i (handle, SQL_HANDLE_STMT);
}

//
// ~ODBC_Connection_Exception
//
ODBC_Stmt_Exception::~ODBC_Stmt_Exception (void)
{

}

