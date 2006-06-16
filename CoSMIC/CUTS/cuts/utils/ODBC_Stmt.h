// -*- C++ -*-

//=============================================================================
/**
 * @file    ODBC_Stmt.h
 *
 * $Id$
 *
 * This file contains the wrapper class for using ODBC statements.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _ODBC_STMT_H_
#define _ODBC_STMT_H_

#include "ODBC_Exception.h"

// forward declarations
class ODBC_Connection;

//=============================================================================
/**
 * @class ODBC_Stmt
 *
 * @brief Wrapper class for using ODBC statement handles.
 *
 * This class contains common operations used by CUTS for executing
 * SQL statements using ODBC. One cannot instantiate an object of this
 * class alone. Instead, it can only be created by an ODBC_Connection
 * object. This prevents the creation of dangling ODBC_Stmt objects
 * (those not associated with a connection).
 */
//=============================================================================

class CUTS_Export ODBC_Stmt
  :  public ODBC_Base
{
  // friend declarations
  friend class ODBC_Connection;

public:
  /// Destructor
  virtual ~ODBC_Stmt (void);

  /**
   * Get the data for the current recordset of the previous query.
   *
   * @param[in]     column      One-based index; bookmark is column 0.
   * @param[out]    buffer      Buffer to store data.
   * @param[in]     bufsize     Size of the buffer.
   * @param[out]    datalen     Number of bytes written.
   * @param[in]     type        SQL data type.
   * @exception     ODBC_Stmt_Exception
   *                Exception occured during database transaction.
   */
  void get_data (USHORT column,
                 void * buffer,
                 ULONG bufsize,
                 long * datalen = 0,
                 int type = SQL_C_DEFAULT)
    throw (ODBC_Stmt_Exception);

  void get_data (USHORT colunm, int & buffer)
    throw (ODBC_Stmt_Exception);

  void get_data (USHORT colunm, long & buffer)
    throw (ODBC_Stmt_Exception);

  void get_data (USHORT colunm, short & buffer)
    throw (ODBC_Stmt_Exception);

  void get_data (USHORT colunm, double & buffer)
    throw (ODBC_Stmt_Exception);

  void get_data (USHORT colunm, float & buffer)
    throw (ODBC_Stmt_Exception);

  /// fetch the next record in the record set
  void fetch (void)
    throw (ODBC_Stmt_Exception);

  /// get the last error message for the statement

  void bind_parameter (SQLUSMALLINT index,
                       SQLSMALLINT io_type,
                       SQLSMALLINT value_type,
                       SQLSMALLINT param_type,
                       SQLUINTEGER column_size,
                       SQLSMALLINT decimal_digits,
                       SQLPOINTER param_value_ptr,
                       SQLINTEGER buffer_length,
                       SQLINTEGER * strlen_indptr)
    throw (ODBC_Stmt_Exception);

  void prepare (const char * stmt)
    throw (ODBC_Stmt_Exception);

  void exec_direct (const char * stmt)
    throw (ODBC_Stmt_Exception);

  void execute (void)
    throw (ODBC_Stmt_Exception);

  /**
   * Get the last insert id. This method is only value if an
   * insert was made to a table with an \a auto_increment field.
   *
   * @return The last id inserted.
   */
  long last_insert_id (void)
    throw (ODBC_Stmt_Exception);

private:
  /// constructor
  ODBC_Stmt (HDBC conn);

  /// handle to the ODBC statement
  HSTMT stmt_;
};

#if defined (__CUTS_INLINE__)
#include "ODBC_Stmt.inl"
#endif

#endif  // !defined _ODBC_STMT_H_
