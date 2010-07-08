// -*- C++ -*-
// $Id$

namespace GAME
{

//
// Transaction
//
GAME_INLINE
Transaction::
Transaction (GAME::Project & proj, transactiontype_enum type)
: proj_ (proj),
  terr_ (proj_.create_territory ()),
  is_active_ (false)
{
  this->init (type);
}

//
// Transaction
//
GAME_INLINE
Transaction::
Transaction (Project & proj, const Territory & terr, transactiontype_enum type)
: proj_ (proj),
  terr_ (terr),
  is_active_ (false)
{
  this->init (type);
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

}
