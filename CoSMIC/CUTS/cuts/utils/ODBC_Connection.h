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

#include "ODBC_Exception.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/SStringfwd.h"

// Forward decl.
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

class CUTS_Export ODBC_Connection :
  public ODBC_Base
{
public:
  /// Constructor
  ODBC_Connection (void);

  /// Destructor
  virtual ~ODBC_Connection (void);

  /**
   * Create an ODBC statement associated with this connection.
   * The statement is valid as long as the connection is valid.
   * Using a statement for an invalid connection can cause
   * unpredictable side-effects.
   *
   * @return  Pointer to the ODBC statement.
   *
   * @todo
   * Determine how to handle invalid using statements that have
   * an invalid connection handle. This may result in the connection
   * class tracking all statements created.
   */
  ODBC_Stmt * create_statement (void) const;

  /**
   * Execute a cached statement.
   *
   * @param[in]     name      Name of the statement.
   */
  void execute_statement (const char * name)
    throw (ODBC_Exception, ODBC_Stmt_Exception);

  /**
   * Establish an new ODBC connection. The information for
   * the establishing the connection is specified in the
   * parameter from the client.
   *
   * @param[in]     username      username for the connection
   * @param[in]     password      password for the @a username
   * @param[in]     host          location of the database
   * @param[in]     port          port of connection
   * @retval        true          successfully established connection
   * @retval        false         failed to establish a connection
   */
  virtual void connect (const char * username,
                        const char * password,
                        const char * host,
                        int port) = 0;

  /// Close the existing connection
  void disconnect (void);

  /**
   * Determine if a connnection exist.
   *
   * @retval      true      there is a connection
   * @retval      false     there is not a connection
   */
  bool is_connected (void) const;

protected:
  /// Helper method to establish a connection
  void connect_i (const char * connstr);

  /// Handle to the database connection
  HDBC conn_;

  /// Handle to the environment
  HENV env_;

  /// Flag holding the connection state.
  bool connected_;

private:
  /// Type definition for statement mappings.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                ODBC_Stmt *,
                                ACE_Null_Mutex> Statement_Map;

  /// Collection of statements mapped to names.
  Statement_Map stmts_;
};

/**
 * @brief MyOBDC connection object class.
 *
 * This is a specialized version of the ODBC_Connection class
 * from which it inherits. It provides the same functionality
 * as the ODBC_Connection class, but if formats the connection
 * string for use with MyODBC.
 */
class CUTS_Export MyODBC_Connection :
  public ODBC_Connection
{
public:
  /// Constructor.
  MyODBC_Connection (void);

  /// Destructor.
  virtual ~MyODBC_Connection (void);

  /**
   * Connect to the specified @a server using the specified
   * @a username and @a password. This connect method is
   * taylored for establishing MyODBC connections.
   *
   * @param[in]     username      username for the connection
   * @param[in]     password      password for the @a username
   * @param[in]     host          location of the database
   * @param[in]     port          port of connection
   *
   * @exception     ODBC_Connection_Exception
   * Failed to create the connection to the database.
   */
  virtual void connect (const char * username,
                        const char * password,
                        const char * server,
                        int port)
    throw (ODBC_Connection_Exception);
};

#if defined (__CUTS_INLINE__)
#include "cuts/utils/ODBC_Connection.inl"
#endif

#endif  // !defined _ODBC_CONNECTION_H_
