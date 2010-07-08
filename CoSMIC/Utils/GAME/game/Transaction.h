// -*- C++ -*-

//=============================================================================
/**
 *  @file       Transaction.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_TRANSACTION_H_
#define _GAME_TRANSACTION_H_

#include "Project.h"
#include "GAME_export.h"

namespace GAME
{
// Forward decl.
class Project;

/**
 * @class Transaction
 *
 * Guard class for managing transactions.
 */
class GAME_Export Transaction
{
public:
  /**
   * Initializing constructor
   *
   * @param[in]     proj        Target project
   */
  Transaction (Project & proj, 
               transactiontype_enum type = TRANSACTION_GENERAL);

  Transaction (Project & proj,
               const Territory & terr,
               transactiontype_enum type = TRANSACTION_GENERAL);

  /// Destructor.
  virtual ~Transaction (void);

  /// Abort the transaction.
  void abort (void);

  /// Commit the current transaction.
  void commit (void);

private:
  // Initialize the transaction.
  void init (transactiontype_enum type);

  /// Target project for the transaction.
  Project & proj_;

  /// Territory for the transaction.
  Territory terr_;

  /// The active state of the transaction
  bool is_active_;  
};

}

#if defined (__GAME_INLINE__)
#include "Transaction.inl"
#endif  

#endif  // !defined _GAME_TRANSACTION_H_
