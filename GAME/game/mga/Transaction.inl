// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Transaction
//
GAME_INLINE
Transaction::
Transaction (const Project & proj,
             transactiontype_enum type)
: proj_ (proj),
  terr_ (proj_.create_territory ()),
  is_active_ (false),
  transaction_type_ (type)
{
  this->init (this->transaction_type_);
}

//
// Transaction
//
GAME_INLINE
Transaction::
Transaction (const Project & proj,
             const Territory & terr,
             transactiontype_enum type)
: proj_ (proj),
  terr_ (terr),
  is_active_ (false),
  transaction_type_ (type)
{
  this->init (this->transaction_type_);
}

//
// ~Transaction
//
GAME_INLINE
Transaction::~Transaction (void)
{
  if (this->is_active_)
    this->abort ();
}

//
// Readonly_Transaction
//
GAME_INLINE
Readonly_Transaction::Readonly_Transaction (const Project & proj)
: Transaction (proj, TRANSACTION_READ_ONLY)
{
  this->is_active_ = false;
}

//
// ~Readonly_Transaction
//
GAME_INLINE
Readonly_Transaction::~Readonly_Transaction (void)
{
  // Force committing of the transaction.
  this->commit ();
}

}
}
