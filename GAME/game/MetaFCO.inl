// -*- C++ -*
// $Id$

namespace GAME
{
namespace Meta
{
//
// FCO
//
GAME_INLINE
FCO::FCO (void)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (const FCO & meta)
: Base (meta)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (IMgaMetaFCO * meta)
: Base (meta)
{

}

//
// ~FCO
//
GAME_INLINE
FCO::~FCO (void)
{

}

//
// operator =
//
GAME_INLINE
const FCO & FCO::operator = (const FCO & meta)
{
  if (this == &meta)
    return *this;

  Base::attach (meta.impl ());
  return *this;
}
}

}
