// -*- C++ -*-

//=============================================================================
/**
 * @file    ODBC_Connection.h
 *
 * $Id$
 *
 * This file contains the wrapper class for ODBC connections.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _ODBC_CONNECTION_H_
#define _ODBC_CONNECTION_H_

#include <cuts/utils/ODBC.h>

// STL headers
#include <string>
using namespace std;

// forward declarations
class ODBC_Stmt;

//=============================================================================
/**
 * @class ODBC_Connection
 *
 * @brief Wrapper class for handling ODBC connection objects.
 *
 * This class provides a minimal set of operations used in CUTS for
 * creating connection to a database using the ODBC protocol. Futhermore,
 * this class is the only way to create an ODBC_Stmt object for performing
 * SQL queries using the ODBC protocol.
 */
//=============================================================================

class CUTS_Export ODBC_Connection
	:	public ODBC_Base
{
public: 
	/// default constructor
	ODBC_Connection (void);

	/// destructor
	virtual ~ODBC_Connection (void);

	ODBC_Stmt * create_statement (void) const;

	/**
	 * Establish an new ODBC connection. The information for
	 * the establishing the connection is specified in the 
	 * parameter from the client.
	 *
	 * @param[in]			svSource			source connection string
	 * @retval				true					successfully established connection
	 * @retval				false					failed to establish a connection
	 */
	virtual bool connect (const char * username,
	                      const char * password,
												const char * host,
												int port) = 0;

	/// close the existing connection
	void disconnect (void);

	/**
	 * Determine if a connnection exist.
	 *
	 * @retval			true			there is a connection
	 * @retval			false			there is not a connection
	 */
	bool is_connected (void) const;

	/// get the last error message for the connection
	const char * get_error_message (void) const;

protected:
	/// helper method to establish a connection
	bool connect (const string & connstr);

private:
	/// handle to the database connection
	HDBC conn_;

	/// handle to the environment
	HENV env_;

  /// Flag holding the connection state.
  bool connected_;
};

/**
 *
 */
class CUTS_Export MyODBC_Connection 
	: public ODBC_Connection
{
public:
	MyODBC_Connection (void);

	virtual ~MyODBC_Connection (void);

	bool connect (const char * username,
		            const char * password,
								const char * server,
								int port);
};

#if	defined (__CUTS_INLINE__)
#include <cuts/utils/ODBC_Connection.inl>
#endif	// defined __CUTS_INLINE__

#endif	// !defined _ODBC_CONNECTION_H_
