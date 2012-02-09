// $Id$

#include "ace/ACE.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// Constraint_Impl
//
GAME_INLINE
Constraint_Impl::Constraint_Impl (void)
{

}

//
// Constraint_Impl
//
GAME_INLINE
Constraint_Impl::Constraint_Impl (IMgaConstraint * meta)
: metaconst_ (meta)
{

}

//
// ~Constraint_Impl
//
GAME_INLINE
Constraint_Impl::~Constraint_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void Constraint_Impl::attach (IMgaConstraint * metaconst)
{
  this->metaconst_.Attach (metaconst);
}

//
// impl
//
GAME_INLINE
IMgaConstraint * Constraint_Impl::impl (void) const
{
  return this->metaconst_;
}

//
// release
//
GAME_INLINE
void Constraint_Impl::release (void)
{
  this->metaconst_.Release ();
}

}
}
}
