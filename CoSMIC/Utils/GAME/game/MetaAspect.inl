// -*- C++ -*
// $Id$

namespace GAME
{
namespace Meta
{
//
// Aspect
//
GAME_INLINE
Aspect::Aspect (void)
{

}

//
// Aspect
//
GAME_INLINE
Aspect::Aspect (const Aspect & aspect)
: Base (aspect)
{

}

//
// Aspect
//
GAME_INLINE
Aspect::Aspect (IMgaMetaAspect * aspect)
: Base (aspect)
{

}

//
// ~Aspect
//
GAME_INLINE
Aspect::~Aspect (void)
{

}

//
// operator =
//
GAME_INLINE
const Aspect & Aspect::operator = (const Aspect & aspect)
{
  Base::attach (aspect);
  return *this;
}

}
}
