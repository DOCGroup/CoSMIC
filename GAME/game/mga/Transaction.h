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

#ifndef _GAME_MGA_TRANSACTION_H_
#define _GAME_MGA_TRANSACTION_H_

#include "Project.h"
#include "Mga_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Transaction
 *
 * Guard class for managing transactions.
 */
class GAME_MGA_Export Transaction
{
public:
  /**
   * Initializing constructor
   *
   * @param[in]     proj        Target project
   */
  Transaction (const Project & proj,
               transactiontype_enum type = TRANSACTION_GENERAL);

  Transaction (const Project & proj,
               const Territory & terr,
               transactiontype_enum type = TRANSACTION_GENERAL);

  /// Destructor.
  virtual ~Transaction (void);

  /// Commit the current transaction.
  void commit (void);

  /// Commit the current transaction and start another one. This
  /// make it a lot easier to reuse a transaction, instead of creating
  /// may different ones within the same scope.
  void flush (void);

  /// Abort the transaction.
  void abort (void);

protected:
  /// The active state of the transaction
  bool is_active_;

private:
  // Initialize the transaction.
  void init (transactiontype_enum type);

  /// Target project for the transaction.
  Project proj_;

  /// Territory for the transaction.
  Territory terr_;

  /// The type of transaction.
  transactiontype_enum transaction_type_;

  // Prevent the following operations.
  Transaction (const Transaction &);
  const Transaction & operator = (const Transaction &);
};

/**
 * @class Readonly_Transaction
 */
class GAME_MGA_Export Readonly_Transaction : public Transaction
{
public:
  Readonly_Transaction (const Project & proj);
  virtual ~Readonly_Transaction (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Transaction.inl"
#endif

#endif  // !defined _GAME_TRANSACTION_H_
