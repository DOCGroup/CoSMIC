// $Id$

#include "Transaction.h"

#if !defined (__GAME_INLINE__)
#include "Transaction.inl"
#endif  

namespace GAME
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
// abort
//
void Transaction::abort (void)
{
  this->proj_.abort_transaction ();
  this->is_active_ = false;
}

}
