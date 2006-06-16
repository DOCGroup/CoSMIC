// $Id$

#include "ODBC_Stmt.h"

#if !defined (__CUTS_INLINE__)
#include "ODBC_Stmt.inl"
#endif

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
    ::SQLFreeStmt (this->stmt_, SQL_RESET_PARAMS);
}

//
// last_insert_id
//
long ODBC_Stmt::last_insert_id (void)
  throw (ODBC_Stmt_Exception)
{
  long last_id = 0;

  // Execute the statement and move to the first and only
  // row in the result set.
  this->exec_direct ("SELECT LAST_INSERT_ID()");

  // Get the data returned from the statement.
  this->fetch ();
  this->get_data (1, last_id);

  return last_id;
}

//
// exec_direct
//
void ODBC_Stmt::exec_direct (const char * sqlstr)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = ::SQLExecDirect (this->stmt_, (SQLCHAR *)sqlstr, SQL_NTS);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}

//
// exec_direct
//
void ODBC_Stmt::execute (void)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = ::SQLExecute (this->stmt_);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}

//
// fetch
//
void ODBC_Stmt::fetch (void)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = ::SQLFetch (this->stmt_);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}

//
// get_data
//
void ODBC_Stmt::get_data (USHORT column,
                          void * buffer,
                          ULONG bufsize,
                          long * datalen,
                          int type)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = SQLGetData (this->stmt_, column, type, buffer, bufsize, 0);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}

//
// bind_parameter
//
void ODBC_Stmt::bind_parameter (SQLUSMALLINT index,
                                SQLSMALLINT io_type,
                                SQLSMALLINT value_type,
                                SQLSMALLINT param_type,
                                SQLUINTEGER column_size,
                                SQLSMALLINT decimal_digits,
                                SQLPOINTER param_value_ptr,
                                SQLINTEGER buffer_length,
                                SQLINTEGER * strlen_indptr)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = SQLBindParameter (this->stmt_,
                                    index,
                                    io_type,
                                    value_type,
                                    param_type,
                                    column_size,
                                    decimal_digits,
                                    param_value_ptr,
                                    buffer_length,
                                    strlen_indptr);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}

//
// prepare
//
void ODBC_Stmt::prepare (const char * stmt)
  throw (ODBC_Stmt_Exception)
{
  this->return_ = SQLPrepare (this->stmt_,
                              (SQLCHAR *) stmt,
                              SQL_NTS);

  if (!SQL_SUCCEED (this->return_))
  {
    throw ODBC_Stmt_Exception (this->stmt_);
  }
}
