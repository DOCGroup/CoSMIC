// -*- C++ -*-

//=============================================================================
/**
 * @file      ODBC_Parameter.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _ODBC_PARAMETER_H_
#define _ODBC_PARAMETER_H_

#include "ODBC_Base.h"
#include "ODBC_Exception.h"
#include "cuts/utils/DB_Parameter.h"

//=============================================================================
/**
 * @class ODBC_Parameter
 *
 * ODBC implementation of the CUTS_DB_Parameter abstract type.
 */
//=============================================================================

class CUTS_ODBC_Export ODBC_Parameter :
  public CUTS_DB_Parameter,
  public ODBC_Base
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     handle      Handle to the ODBC statement.
   */
  ODBC_Parameter (HSTMT handle, int index);

  /// Destructor.
  virtual ~ODBC_Parameter (void);

  virtual void null (void);

  virtual void bind (char * buffer, size_t bufsize);

  virtual void bind (short * buffer);

  virtual void bind (u_short * buffer);

  virtual void bind (long * buffer);

  virtual void bind (u_long * buffer);

  virtual void bind (float * buffer);

  virtual void bind (double * buffer);

  virtual void bind (CUTS_DB_Date_Time_Impl * datetime);

  /**
   * Set the length of the parameter. This is necessary of the
   * parameter is already bound to a buffer, and the length of the
   * input buffer has changed.
   *
   * @param[in]       len         Length of the buffer.
   */
  virtual void length (long len);

  /**
   * Get the current length/size of the parameter.
   *
   * @return          The length/size of the parameter.
   */
  virtual long length (void);

private:
  /// Helper method for binding SQL parameters.
  void bind_i (SQLSMALLINT iotype,
               SQLSMALLINT valuetype,
               SQLSMALLINT paramtype,
               SQLUINTEGER columnsize,
               SQLSMALLINT decimals,
               SQLPOINTER  valueptr,
               SQLINTEGER  buffer_length);

  /// Handle to the ODBC statement.
  HSTMT handle_;

  /// Size of the parameter buffer.
  SQLINTEGER intptr_;
};

#endif  // !defined _ODBC_PARAMETER_H_
