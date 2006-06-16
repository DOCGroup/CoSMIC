// -*- C++ -*-

//=============================================================================
/**
 * @file      ODBC_Exception.h
 *
 * $Id: ODBC_Exception.h,v 1.1.2.1.2.1 2006/06/02 05:13:45 hillj Exp $
 *
 * @brief     Defines exceptions used by ODBC operations
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ODBC_EXCEPTION_H_
#define _CUTS_ODBC_EXCEPTION_H_

#include "cuts/config.h"
#include "cuts/CUTS_export.h"
#include "ace/SStringfwd.h"
#include "ace/String_Base.h"
#include "ODBC.h"

//=============================================================================
/**
 * @class ODBC_Exception
 *
 * @brief Base class for all ODBC exception classes.
 */
//=============================================================================

class CUTS_Export ODBC_Exception
{
public:
  /// Default constructor.
  ODBC_Exception (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     message     Message to store in the exception.
   */
  ODBC_Exception (const char * message);

  /// Default destructor.
  virtual ~ODBC_Exception (void);

  /**
   * Get the exception message.
   *
   * @return      The exception message; NULL-terminated.
   */
  const char * message (void) const;

protected:
  /// The exception message.
  ACE_CString message_;
};

//=============================================================================
/**
 * @class ODBC_Connection_Exception
 *
 * @brief Exception thrown when a ODBC connection operation fails.
 */
//=============================================================================

class CUTS_Export ODBC_Connection_Exception :
  public ODBC_Exception
{
public:
  /**
   * Constructor.
   *
   * @param[in]     handle      Connection handle causing exception.
   */
  ODBC_Connection_Exception (HDBC handle);

  /// Destructor.
  virtual ~ODBC_Connection_Exception (void);
};

//=============================================================================
/**
 * @class ODBC_Stmt_Exception
 *
 * @brief Exception thrown when a ODBC statement operation fails.
 */
//=============================================================================

class CUTS_Export ODBC_Stmt_Exception :
  public ODBC_Exception
{
public:
  /**
   * Constructor.
   *
   * @param[in]     handle      Statement handle causing exception.
   */
  ODBC_Stmt_Exception (HSTMT handle);

  /// Destructor.
  virtual ~ODBC_Stmt_Exception (void);
};

#if defined (__CUTS_INLINE__)
#include "ODBC_Exception.inl"
#endif

#endif  // !defined _CUTS_ODBC_EXCEPTION_H_
