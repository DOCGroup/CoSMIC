// -*- C++ -*-

//=============================================================================
/**
 * @file    ODBC.h
 *
 * $Id: ODBC.h 637 2006-06-16 22:48:59Z kitty $
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_ODBC_H_
#define _CUTS_ODBC_H_

#include "cuts/config.h"
#include "ODBC_DBase_Export.h"

// SQL headers
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcinst.h>

#define SQL_SUCCEED(res) ((res == SQL_SUCCESS_WITH_INFO) || (res == SQL_SUCCESS))

#define SAFE_STR(str) ((str == NULL) ? _T ("") : str)

#define SQL_VERIFY(op, ex) \
  this->return_ = op; \
  if (!SQL_SUCCEED (this->return_)) \
    throw ex

//=============================================================================
/**
 * @class ODBC_Base
 *
 * @brief Base class for all ODBC wrapper classes.
 *
 * This class is the base class for all classes that are ODBC wrappers. This
 * class contains operations that are commonly used by all ODBC wrapper class
 * such as getting the result of an operation, as well as those operations
 * that are similar but vary in implementation.
 */
//=============================================================================

class CUTS_ODBC_Export ODBC_Base
{
public:
  /// Constructor.
  ODBC_Base (void);

  /// Destructor.
  virtual ~ODBC_Base (void);

  /// Get the return value for the previous ODBC statement.
  SQLRETURN _return (void) const;

protected:
  /// Return value required for all ODBC wrapper classes.
  SQLRETURN return_;
};

#if defined (__CUTS_INLINE__)
#include <cuts/utils/ODBC.inl>
#endif  //  defined __CUTS_INLINE__

#endif  //  !define _ODBC_H_
