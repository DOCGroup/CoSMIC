// $Id: ODBC_Exception.cpp,v 1.1.2.1.2.1 2006/06/02 05:13:45 hillj Exp $

#include "ODBC_Exception.h"

#if !defined (__CUTS_INLINE__)
#include "ODBC_Exception.inl"
#endif

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
  char message[256];
  SQLCHAR sql_state[6];
  SQLINTEGER native;
  SQLSMALLINT actual;

  ::SQLGetDiagRec (SQL_HANDLE_DBC,
                   handle,
                   1,
                   sql_state,
                   &native,
                   (SQLCHAR *)message,
                   sizeof (message),
                   &actual);

  this->message_.set (message, actual, 1);
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
  char message[256];
  SQLCHAR sql_state[6];
  SQLINTEGER native;
  SQLSMALLINT actual;

  ::SQLGetDiagRec (SQL_HANDLE_STMT,
                   handle,
                   1,
                   sql_state,
                   &native,
                   (SQLCHAR *)message,
                   sizeof (message),
                   &actual);

  this->message_.set (message, actual, 1);
}

//
// ~ODBC_Connection_Exception
//
ODBC_Stmt_Exception::~ODBC_Stmt_Exception (void)
{

}

