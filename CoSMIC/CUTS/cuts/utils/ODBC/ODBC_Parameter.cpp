// $Id$

#include "ODBC_Parameter.h"
#include "ODBC_Types.h"

//
// ODBC_Parameter
//
ODBC_Parameter::ODBC_Parameter (HSTMT handle, int index)
: handle_ (handle),
  intptr_ (SQL_NULL_DATA)
{
  this->index_ = index;
}

//
// ~ODBC_Parameter
//
ODBC_Parameter::~ODBC_Parameter (void)
{

}

//
// bind
//
void ODBC_Parameter::bind (char * buffer, size_t bufsize)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_CHAR,
                SQL_CHAR,
                0,
                0,
                buffer,
                bufsize);

  if (bufsize == 0)
    this->intptr_ = SQL_NTS;

  CUTS_DB_Parameter::bind (buffer, bufsize);
}

//
// bind
//
void ODBC_Parameter::bind (short * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_SSHORT,
                SQL_SMALLINT,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (u_short * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_USHORT,
                SQL_SMALLINT,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (long * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_SLONG,
                SQL_INTEGER,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (u_long * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_ULONG,
                SQL_INTEGER,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (float * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_FLOAT,
                SQL_REAL,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (double * buffer)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_DOUBLE,
                SQL_DOUBLE,
                0,
                0,
                buffer,
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (buffer);
}

//
// bind
//
void ODBC_Parameter::bind (CUTS_DB_Date_Time_Impl * datetime)
{
  this->bind_i (SQL_PARAM_INPUT,
                SQL_C_TYPE_TIMESTAMP,
                SQL_TYPE_TIMESTAMP,
                0,
                0,
                datetime->value_i (),
                0);

  this->intptr_ = 0;
  CUTS_DB_Parameter::bind (datetime);
}

//
// bind
//
void ODBC_Parameter::null (void)
{
  this->intptr_ = SQL_NULL_DATA;

  CUTS_DB_Parameter::null ();
}

//
//
// bind_i
//
void ODBC_Parameter::bind_i (SQLSMALLINT iotype,
                             SQLSMALLINT valuetype,
                             SQLSMALLINT paramtype,
                             SQLUINTEGER columnsize,
                             SQLSMALLINT decimals,
                             SQLPOINTER  valueptr,
                             SQLINTEGER  buffer_length)
{
  SQL_VERIFY (::SQLBindParameter (this->handle_,
                                  this->index_,
                                  iotype,
                                  valuetype,
                                  paramtype,
                                  columnsize,
                                  decimals,
                                  valueptr,
                                  buffer_length,
                                  &this->intptr_),
              ODBC_Stmt_Exception (this->handle_));
}

//
// length
//
void ODBC_Parameter::length (long len)
{
  this->intptr_ =
    this->type () == CUTS_DB_Parameter::PT_CHAR && len == 0 ? SQL_NTS : len;
}

//
// length
//
long ODBC_Parameter::length (void)
{
  return this->intptr_;
}
