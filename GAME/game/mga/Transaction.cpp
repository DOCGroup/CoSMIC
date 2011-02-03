// $Id$

#include "stdafx.h"
#include "mga.h"
#include "Transaction.h"

#if !defined (__GAME_INLINE__)
#include "Transaction.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// init
//
void Transaction::init (transactiontype_enum type)
{
  this->proj_.begin_transaction (this->terr_, type);
  this->is_active_ = true;
}

//
// commit
//
void Transaction::commit (void)
{
  this->proj_.commit_transaction ();
  this->is_active_ = false;
}

//
// flush
//
void Transaction::flush (void)
{
  // Commit the current transaction if it is active.
  if (this->is_active_)
    this->commit ();

  // Start a new transaction.
  this->init (this->transaction_type_);
}

//
// abort
//
void Transaction::abort (void)
{
  this->proj_.abort_transaction ();
  this->is_active_ = false;
}

}
}
