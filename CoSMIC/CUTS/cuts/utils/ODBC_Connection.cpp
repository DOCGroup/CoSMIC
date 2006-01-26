// $Id$

#include "ODBC_Connection.h"
#include "ODBC_Stmt.h"

#if !defined (__CUTS_INLINE__)
#include "ODBC_Connection.inl"
#endif	// !defined __CUTS_INLINE__

//
// ODBC_Connection
//
ODBC_Connection::ODBC_Connection (void)
:	conn_ (SQL_NULL_HDBC), 
	env_ (SQL_NULL_HENV),
  connected_ (false)
{

}

//
// ~ODBC_Connection
//
ODBC_Connection::~ODBC_Connection (void)
{
	// reset database connection handle
	if (is_connected ())
		disconnect ();

  // release the resource for the connection
  if (this->conn_ != SQL_NULL_HDBC)
	  ::SQLFreeHandle (SQL_HANDLE_DBC, this->conn_);

	// free the environment variable
	if (this->env_ != SQL_NULL_HENV)
    ::SQLFreeHandle (SQL_HANDLE_ENV, this->env_);
}

//
// connect
//
bool ODBC_Connection::connect (const string & connstr)
{
	// allocate environment handle and register version
	if (this->env_ == SQL_NULL_HENV)
		this->return_ = ::SQLAllocHandle (SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->env_);

	if (!SQL_SUCCEED (this->return_))
		return false;

	this->return_ = ::SQLSetEnvAttr (this->env_, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0 );
	if (!SQL_SUCCEED (this->return_))
		return false;

	// allocate connection handle and set timeout
	if (conn_ == SQL_NULL_HDBC)
		this->return_ = ::SQLAllocHandle (SQL_HANDLE_DBC, this->env_, &this->conn_);
	
	if (!SQL_SUCCEED (this->return_))
		return false;

	::SQLSetConnectOption (this->conn_, SQL_LOGIN_TIMEOUT, 30);                

	// establish a connection
	short result = 0;
	SQLTCHAR tempstr[256];

	this->return_ = ::SQLDriverConnect (this->conn_, NULL, (SQLCHAR *)connstr.c_str (),
		connstr.length (), tempstr, sizeof (tempstr),	&result, SQL_DRIVER_NOPROMPT);
  
  if (SQL_SUCCEED (this->return_))
    this->connected_ = true;
  
  return this->connected_;
}

//
// disconnect 
//
void ODBC_Connection::disconnect (void)
{
  // verify handle is valid
	if (this->conn_ != SQL_NULL_HDBC)
  {
	  // close the current connection
	  this->return_ = ::SQLDisconnect (this->conn_);
    this->connected_ = false;
  }
}

//
// get_error_message
//
const char * ODBC_Connection::get_error_message (void) const
{
	static char errmsg[256];
	SQLCHAR sql_state[6];
	SQLINTEGER native;
	SQLSMALLINT actual;

	SQLGetDiagRec (SQL_HANDLE_DBC, this->conn_, 1, sql_state, &native, (SQLCHAR *)errmsg, 
		sizeof (errmsg), &actual);
	return errmsg;
}

//
// create_statement
//
ODBC_Stmt * ODBC_Connection::create_statement (void) const
{
	return new ODBC_Stmt (this->conn_);
}
