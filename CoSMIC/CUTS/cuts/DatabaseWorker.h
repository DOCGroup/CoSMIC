// -*- C++ -*-

//=============================================================================
/**
 * @file    DatabaseWorker.h
 *
 * $Id$
 *
 * This class contains the default database worker for CUTS
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_DATABASEWORKER_H_
#define _CUTS_DATABASEWORKER_H_

#include "cuts/Worker.h"
#include "cuts/utils/ODBC_Connection.h"
#include "cuts/utils/ODBC_Stmt.h"
#include "ace/Auto_Ptr.h"
#include <string>

//=============================================================================
/**
 * @class CUTS_DatabaseWorker
 */
//=============================================================================

class CUTS_Export CUTS_DatabaseWorker
  : public CUTS_Worker
{
public:
  CUTS_DatabaseWorker (void);

  virtual ~CUTS_DatabaseWorker (void);

  virtual void process (long reps);

  void hostname (const char * host);

  const char * hostname (void) const;

  bool create_connection (void);

  void destroy_connection (void);

private:
  std::string hostname_;

  auto_ptr <ODBC_Connection> conn_;
};

#if defined (__CUTS_INLINE__)
#include <cuts/DatabaseWorker.inl>
#endif  // defined __CUTS_INLINE__

#endif  // !defined _CUTS_DATABASEWORKER_H_
