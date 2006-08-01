// -*- C++ -*-

//=============================================================================
/**
 * @file      ODBC.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ODBC_H_
#define _CUTS_ODBC_H_

#include "cuts/config.h"
#include "ace/config.h"

#if defined (CUTS_HAS_ODBC)

// SQL headers
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcinst.h>

#include "ODBC_DBase_Export.h"

#else

#error ODBC databases are not supported

#endif

#endif  // !defined _CUTS_ODBC_H_
