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

#include <cuts/utils/ODBC.h>

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
	:	public ODBC_Base
{
	// friend declarations
	friend class ODBC_Connection;

public:
	/// destructor
	virtual ~ODBC_Stmt (void);

	/// run a SQL query
	bool query (const char * sqlstr);

	/// get the data for the current recordset of the previous query
	bool get_data (USHORT column, void * buffer, 
		ULONG bufsize, long * datalen = 0, int type = SQL_C_DEFAULT);

	/// fetch the next record in the record set
	bool fetch (void);

	/// get the last error message for the statement
	const char * get_error_message (void) const;

private:
	/// constructor
	ODBC_Stmt (HDBC conn);

	/// handle to the ODBC statement
	HSTMT stmt_;
};

#if defined (__CUTS_INLINE__)
#include <cuts/utils/ODBC_Stmt.inl>
#endif	// defined __CUTS_INLINE__

#endif	// !defined _ODBC_STMT_H_
