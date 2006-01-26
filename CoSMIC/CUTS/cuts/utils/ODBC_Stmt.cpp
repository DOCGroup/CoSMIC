// $Id$

#include "ODBC_Stmt.h"

#if !defined (__CUTS_INLINE__)
#include "ODBC_Stmt.inl"
#endif	// !defined __CUTS_INLINE__

//
// ODBC_Stmt
//
ODBC_Stmt::ODBC_Stmt (HDBC hDBCLink)
: stmt_ (SQL_NULL_HSTMT)
{
	// allocate a new statement handle
	this->return_ = ::SQLAllocHandle (SQL_HANDLE_STMT, hDBCLink, &this->stmt_);

	if (!SQL_SUCCEED (this->return_))
		return;

	// set the attributes for the statement
	this->return_ = ::SQLSetStmtAttr (this->stmt_, SQL_ATTR_CONCURRENCY, 
		(SQLPOINTER) SQL_CONCUR_ROWVER, 0);
	this->return_ = ::SQLSetStmtAttr (this->stmt_, SQL_ATTR_CURSOR_TYPE, 
		(SQLPOINTER) SQL_CURSOR_KEYSET_DRIVEN, 0);
}

//
// ~ODBC_Stmt
//
ODBC_Stmt::~ODBC_Stmt (void)
{
	if (this->stmt_ != SQL_NULL_HSTMT)
		::SQLFreeHandle (SQL_HANDLE_STMT, this->stmt_);
}

//
// get_error_message
//
const char * ODBC_Stmt::get_error_message (void) const
{
	static char errmsg [256];
	SQLCHAR sql_state[6];
	SQLINTEGER native;
	SQLSMALLINT actual;

	::SQLGetDiagRec (SQL_HANDLE_STMT, this->stmt_, 1, sql_state, &native, (SQLCHAR *)errmsg, 
		sizeof (errmsg), &actual);
	return errmsg;
}
